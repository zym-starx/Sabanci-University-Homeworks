`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 01/05/2023 05:35:09 PM
// Design Name: 
// Module Name: top_module
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


module top_module(

    input clk,
    rst,
    
    floor_0_p,
    floor_1_p,
    floor_2_p,
    floor_3_p,
    floor_4_p,
    
    direction_1,
    direction_2,
    direction_3,
    
    floor_0_d,
    floor_1_d,
    floor_2_d,
    floor_3_d,
    floor_4_d,
    
    output led_inside_0,
    led_inside_1,
    led_inside_2,
    led_inside_3,
    led_inside_4,
    
    led_outside_0,
    led_outside_1,
    led_outside_2,
    led_outside_3,
    led_outside_4,

    led_busy,
    
    a_out,b_out,c_out,d_out,e_out,f_out,g_out,p_out,
    [7:0]an
);
    
    wire [7:0] a,b,c,d,e,f,g,p;
    
    assign reset = ~rst;
    
    clk_divider divider(.clk_in(clk), .rst(reset), .divided_clk(clk50hz));

    debouncer pb0(.clk(clk50hz), .rst(reset), .noisy_in(floor_0_p), .clean_out(floor_0_p_clean));
    debouncer pb1(.clk(clk50hz), .rst(reset), .noisy_in(floor_1_p), .clean_out(floor_1_p_clean));
    debouncer pb2(.clk(clk50hz), .rst(reset), .noisy_in(floor_2_p), .clean_out(floor_2_p_clean));
    debouncer pb3(.clk(clk50hz), .rst(reset), .noisy_in(floor_3_p), .clean_out(floor_3_p_clean));
    debouncer pb4(.clk(clk50hz), .rst(reset), .noisy_in(floor_4_p), .clean_out(floor_4_p_clean));
    
    ssd seven_segment_display(clk,reset,a,b,c,d,e,f,g,p,
		a_out,b_out,c_out,d_out,e_out,f_out,g_out,p_out,
		an);
		
	elevator elev(
	clk50hz,reset,
	floor_0_p_clean,floor_1_p_clean,floor_2_p_clean,floor_3_p_clean,floor_4_p_clean,
	direction_1,direction_2,direction_3,
	floor_0_d,floor_1_d,floor_2_d,floor_3_d,floor_4_d,
	led_inside_0,led_inside_1,led_inside_2,led_inside_3,led_inside_4,
	led_outside_0,led_outside_1,led_outside_2,led_outside_3,led_outside_4, led_busy,
	a,b,c,d,e,f,g,p);
endmodule
