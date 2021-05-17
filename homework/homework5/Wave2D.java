/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package wave2d;

import java.util.Arrays;

/**
 *
 * @author kevinsanft
 */
public class Wave2D {

    /**
     * @param args h (space step), k (time step), steps (end time)
     */
    public static void main(String[] args) {
        System.out.println("args="+Arrays.toString(args));
        //0.01 0.002 1.0 1 1
        double h = Double.parseDouble(args[0]);//0.01;//space step size
        double k = Double.parseDouble(args[1]);//0.002;//time step size
        double endTime = Double.parseDouble(args[2]);//
        int printEveryNSteps = Integer.parseInt(args[3]);//1=print every time step, 2=print every other, etc
        int printEveryNPoints = Integer.parseInt(args[4]);//1=print every grid point
        
        String filenamePrefix = "";
        if (args.length>5) {
            filenamePrefix = args[5];
        }
        
        //in homogeneous case with constant "c" = 1, require k<h
        if (k>=h) {
            System.out.println("error, cfl condition violated");
            return;//exit
        }
        
        int N = (int)(1.0/h) + 1;
        System.out.println("N="+N);
        
        //set up array of 3 State objects
        //we only need 3 (the state of the two previous times and the state we're computing)
        State[] states = new State[3];
        states[0] = new State(N);
        states[0].setInitialCondition();
        states[1] = new State(N);
        states[1].setInitialCondition();
        states[2] = new State(N);
        
        //output initial condition to pgm file
        //append the output file number and .pgm extension
        //output file number must include leading 0s (for constructing animation later)
        //assume we won't have more than 
        String filename = filenamePrefix+String.format("%06d",0)+".pgm";
        System.out.println(filename);
        //System.exit(1);//bug here and later when printEveryNPoint>1, pgm header has incorrect dimensions
        State.writePGMHeader((int)Math.ceil((float)N/printEveryNPoints),(int)Math.ceil((float)N/printEveryNPoints),filename);
        states[1].writePGMData(0, N-1, 0, N-1, printEveryNPoints, filename, true);
        //System.exit(1);
        
        
        //iterate
        int steps = 1;
        double t = 0.0;
        while (t<=endTime) {
            //for simplicity, reindex states
            State uk = states[(steps+1)%3];//step we're computing
            State ukm1 = states[steps%3];//previous time
            State ukm2 = states[(steps-1)%3];//time before previous
            
            State.step(k,h,uk,ukm1,ukm2);
            
            //output
            if (steps%printEveryNSteps == 0) {
                filename = filenamePrefix+String.format("%06d",steps/printEveryNSteps)+".pgm";
                System.out.println(filename+", t="+t);
                State.writePGMHeader((int)Math.ceil((float)N/printEveryNPoints),(int)Math.ceil((float)N/printEveryNPoints),filename);
                uk.writePGMData(0, N-1, 0, N-1, printEveryNPoints, filename, true);
            }
            
            //increment
            ++steps;
            t=k*steps;
        }
        
    }
    
}
