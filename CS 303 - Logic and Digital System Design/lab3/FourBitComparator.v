`timescale 1ns / 1ps
`include "xor_gate.v"
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12/07/2022 08:21:29 PM
// Design Name: 
// Module Name: FourBitComparator
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////

module FourBitComparator(
    input A0, input A1, 
    input A2, input A3, 
    input B0, input B1,
    input B2, input B3,
    output C0, output C1, output C2
    );
    
    wire w1, w2, w3, w4, w5, w6, 
        w7, w8, w9, w10, w11, w12;
   
    assign w5 = (A3 ^- B3);
    assign w6 = (A2 ^- B2);
    assign w7 = (A1 ^- A1);
    assign w8 = (A0 ^- A0);
    
    assign w1 = (A3 & (~B3));
    assign w2 = (A2 & (~B2) & w5);
    assign w3 = (A1 & (~B1) & w5 & w6);
    assign w4 = (A0 & (~B0) & w5 & w6 & w7);
     
    assign w9  = ((~A3) & B3);
    assign w10 = ((~A2) & B2 & w5);
    assign w11 = ((~A1) & B1 & w6);
    assign w12 = ((~A0) & B0 & w7);
    
    // C0 = "A>B"
    // C1 = "A=B"
    // C2 = "A<B"
    
    assign C0 = (w1 | w2 | w3 | w4);
    assign C1 = (w5 | w6 | w7 | w8);
    assign C2 = (w9 | w10 | w11 | w12);
    
    
    
endmodule
