/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package wave2d;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.Arrays;

/**
 *
 * @author kevinsanft
 */
public class State {
    //left,bottom endpoint is (0,0), top,right endpoint is (1,1)
    private final int N;
    private double[][] u;
    
    //constructor (set state to 0)
    public State(int N) {
        this.N = N;
        u = new double[N][N];
        //fill with 0
        for (int row=0; row<N; ++row) {
            for (int col=0; col<N; ++col) {
                u[row][col] = 0.0;
            }
        }
    }
    
    double[][] getU() {
        return u;
    }
    
    //set state u to standard initial condition (small bump)
    //which is bivariate normal, rescaled to max=1
    //use 
    void setInitialCondition() {
        //double sigma=0.1;//standard deviation in both directions
        double sigma=0.01;//tighter initial point
        double mu=0.5;//center
        for (int row=0; row<N; ++row) {
            for (int col=0; col<N; ++col) {
                double x = 1.0/(N-1)*row;
                double y = 1.0/(N-1)*col;
                u[row][col] = (1.0/(2.0*Math.PI*sigma*sigma))*Math.exp(-0.5*( ((x-mu)/sigma)*((x-mu)/sigma) +  ((y-mu)/sigma)*((y-mu)/sigma)   ));
            }
        }
    }
    
    //print entire matrix
    void printState() {
        for (int row=0; row<N; ++row) {
            for (int col=0; col<N; ++col) {
                if (col!=0) {
                    System.out.print(" ");
                }
                System.out.print(u[row][col]);
            }
            System.out.print("\n");
        }        
    }
    

    //write u data block to file
    //from rowStart to rowEnd (inclusive) and colStart to colEnd (inclusive)
    //rescale to max of all data (for pgm file)
    void writePGMData(int rowStart, int rowEnd, int colStart, int colEnd, int printEveryNPoints, String filename, boolean append) {
        Path file = Paths.get(filename);
        double maxVal = getMaxAbs();
        //try (BufferedWriter writer = Files.newBufferedWriter(file)) {
        try (BufferedWriter writer = Files.newBufferedWriter(file,StandardCharsets.UTF_8, append ? StandardOpenOption.APPEND : StandardOpenOption.WRITE))
        {
            //writer.write(s, 0, s.length());
            for (int row=rowStart; row<=rowEnd; row+=printEveryNPoints) {
                for (int col=colStart; col<=colEnd; col+=printEveryNPoints) {
                    writer.write(Long.toString(Math.round( (u[row][col]/maxVal)*127 + 127 ))+" ");
                }
                writer.newLine();
            }
        } catch (IOException e) {
            System.err.format("IOException: %s%n", e);
        }
    }
    
    static void writePGMHeader(int rows, int cols, String filename) {//, int max) {
        String headerString = "P2\n"+rows+" "+cols+"\n255\n";
        try {
            Files.write(Paths.get(filename), headerString.getBytes(), StandardOpenOption.CREATE);
        }catch (IOException e) {
            System.err.format("IOException: %s%n", e);
        }
    }
    
    double getMax() {
        double maxVal = u[0][0];
        for (int row=0; row<N; ++row) {
            for (int col=0; col<N; ++col) {
                if (u[row][col]>maxVal) {
                    maxVal = u[row][col];
                }
            }
        }
        return maxVal;
    }
    
    double getMaxAbs() {
        double maxVal = Math.abs(u[0][0]);
        for (int row=0; row<N; ++row) {
            for (int col=0; col<N; ++col) {
                if (Math.abs(u[row][col])>maxVal) {
                    maxVal = Math.abs(u[row][col]);
                }
            }
        }
		//System.out.printf("%f\n",maxVal);
        return maxVal;
    }

    //compute this State (t_(i+1)) from t_i and t_(i-1)
    static void step(double k, double h,State tip1, State ti, State tim1) {
        //tip1 is t_(i+1), ti is t_i, tim1 is t_(i-1)
        //should verify that all are same size...not implemented
        
        for (int row=1; row<(tip1.N-1); ++row) {
            for (int col=1; col<(tip1.N-1); ++col) {
                //uk[cindex]=k^2/h^2*(ukminus1[cup]-4*ukminus1[cindex]+ukminus1[cdown]+ukminus1[cleft]+ukminus1[cright])+2*ukminus1[cindex]-ukminus2[cindex]
                tip1.getU()[row][col] = k*k/(h*h)*(ti.getU()[row-1][col]-4*ti.getU()[row][col]+ti.getU()[row+1][col]+ti.getU()[row][col-1]+ti.getU()[row][col+1])+2*ti.getU()[row][col]-tim1.getU()[row][col];
            }
        }
    }
}
