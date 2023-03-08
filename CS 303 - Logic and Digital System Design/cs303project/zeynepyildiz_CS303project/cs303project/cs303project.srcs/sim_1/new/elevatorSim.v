`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 01/20/2023 01:36:24 PM
// Design Name: 
// Module Name: elevatorSim
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


module elevatorSim(
    );
    
    reg clk_in, rst, clk_50hz;
    reg floor_0_p, floor_1_p, floor_2_p, floor_3_p, floor_4_p;
    reg direction_1, direction_2, direction_3;
    reg floor_0_d, floor_1_d, floor_2_d, floor_3_d, floor_4_d; 
    wire led_inside_0, led_inside_1, led_inside_2, led_inside_3, led_inside_4;
    wire led_outside_0, led_outside_1, led_outside_2, led_outside_3, led_outside_4;
    wire led_busy;
    wire [7:0] a, b, c, d, e, f, g, p;
    
        
    elevator uut (
        .clk_50hz(clk_in),
        .rst(rst),
        .floor_0_p(floor_0_p),
        .floor_1_p(floor_1_p),
        .floor_2_p(floor_2_p),
        .floor_3_p(floor_3_p),
        .floor_4_p(floor_4_p),
        .direction_1(direction_1),
        .direction_2(direction_2),
        .direction_3(direction_3),
        .floor_0_d(floor_0_d),
        .floor_1_d(floor_1_d),
        .floor_2_d(floor_2_d),
        .floor_3_d(floor_3_d),
        .floor_4_d(floor_4_d),
        .led_inside_0(led_inside_0),
        .led_inside_1(led_inside_1),
        .led_inside_2(led_inside_2),
        .led_inside_3(led_inside_3),
        .led_inside_4(led_inside_4),
        .led_outside_0(led_outside_0),
        .led_outside_1(led_outside_1),
        .led_outside_2(led_outside_2),
        .led_outside_3(led_outside_3),
        .led_outside_4(led_outside_4),
        .led_busy(led_busy),
        .a(a), .b(b), .c(c),
        .d(d), .e(e), .f(f),
        .g(g), .p(p)
    );
    
    always #25 clk_in = !clk_in;
    
    initial begin
        clk_in = 1'b0;

        
        rst = 1'b1;
        
        #25;
        
        rst = 1'b0;
        
        //call from inside the elevator to floor 3
        rst = 0;
        
        floor_0_p = 0; floor_1_p = 0; floor_2_p = 0; floor_3_p = 0; floor_4_p = 0;
        direction_1 = 0; direction_2 = 0; direction_3 = 0;
        floor_0_d = 0; floor_1_d = 0; floor_2_d = 0; floor_3_d = 0; floor_4_d = 0; 
        
        #50;
        floor_3_d = 1'b1;
        #15;
        floor_3_d = 1'b0;
        
        #25;
        direction_2 = 1'b1;
        #10;
        floor_2_p = 1'b1;
        #10;
        direction_2 = 1'b0;
        floor_2_p = 1'b0;
        
        #25;
        direction_1 = 1'b0;
        #10;
        floor_1_p = 1'b1;
        #10;
        direction_1 = 1'b0;
        floor_1_p = 1'b0;
        
        #25;
        
        
        
        #50;
        floor_4_p = 1'b1;
        #10;
        floor_4_p = 1'b0;
        
    end
    
    
    
    
endmodule
