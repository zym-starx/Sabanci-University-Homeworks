`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Description: This module drives the seven segment displays. It // has got 8 different inputs
//						for the 8 digits on the board. // It's inputs are not directly the binary numbers.
//						 
//	a[0],b[0],c[0],d[0],e[0],f[0],g[0],p[0] belongs to digit0, rigth 
// most digit on the board.
//	a[1],b[1],c[1],d[1],e[1],f[1],g[1],p[1] belongs to digit1, 2.
// from the rigth most digit on the board.
//	a[2],b[2],c[2],d[2],e[2],f[2],g[2],p[2] belongs to digit2, 3. 
// from the rigth most digit on the board.
//	a[3],b[3],c[3],d[3],e[3],f[3],g[3],p[3] belongs to digit3, 3. 
// from the rigth most digit on the board.
//	a[4],b[4],c[4],d[4],e[4],f[4],g[4],p[4] belongs to digit4, 4. 
// from the rigth most digit on the board.
//	a[5],b[5],c[5],d[5],e[5],f[5],g[5],p[5] belongs to digit5, 5. 
// from the rigth most digit on the board.
//
//	a[6],b[6],c[6],d[6],e[6],f[6],g[6],p[6]belongs to digit6, 6. 
// from the rigth most digit on the board.
//
//	a[7],b[7],c[7],d[7],e[7],f[7],g[7],p[7] belongs to digit7, 
// left most digit on the board.
//						
// The values that you connect to these inputs will appear on the 
// display digits.
// Thus, you just need to make the appropriate connections.
//
//
//////////////////////////////////////////////////////////////////////////////////

module ssd(clk,reset,a,b,c,d,e,f,g,p,
		a_out,b_out,c_out,d_out,e_out,f_out,g_out,p_out,
		an
          );

input clk, reset;// set clock and reset as input(1 bit)
input [7:0] a,b,c,d,e,f,g,p;

output reg a_out,b_out,c_out,d_out,e_out,f_out,g_out,p_out;
output reg [7:0] an;

reg [3:0] state;//holds state number (3 bit)
reg [19:0] counter;//counter to slow the input clock

// in this always block the speed of the clock reduced by 100000
// times so that display works properly

always @ (posedge clk) begin //state counter

	if(reset) begin	//synchronus reset
		state <= 0; //if reset set state and counter to zero
		counter <= 0;
	end 

	else begin //else the counter untill 100000

		if(counter == 20'h186A0) begin	 //if equal to 100000
			if (state == 4'b1000) 
				state <= 1;
			else
				state <= state + 1;
			
			counter <= 0;
		end

		else
			counter <= counter + 1; //if not 100000 add 1
	end
end

//in this always block we give the inputs to the leds by choosing 
//different display segment in each time

always@(posedge clk)
begin
	if(reset)// if reset initilize the outputs
	begin
		an[7:0] <= 8'b11111111;
		a_out <= 1;
		b_out  <= 1;
		c_out  <= 1;
		d_out  <= 1;
		e_out  <= 1;
		f_out  <= 1;
		g_out  <= 1;
		p_out  <= 1;
	end
	else if(state == 4'b0001) 
//state 1 gives the led outputs to the AN0	
	begin
		an[7:0] <= 8'b11111110;
		a_out  <= a[0];
		b_out  <= b[0];
		c_out  <= c[0];
		d_out  <= d[0];
		e_out  <= e[0];
		f_out  <= f[0];
		g_out  <= g[0];
		p_out  <= p[0];
	end
	else if(state == 4'b0010) 
//state 2 gives the led outputs to the AN1		
	begin
		an[7:0] <= 8'b11111101;
		a_out  <= a[1];
		b_out  <= b[1];
		c_out  <= c[1];
		d_out  <= d[1];
		e_out  <= e[1];
		f_out  <= f[1];
		g_out  <= g[1];
		p_out  <= p[1];

	end
	else if(state == 4'b0011) 
//state 3 gives the led outputs to the AN2		
	begin
		an[7:0] <= 8'b11111011;
		a_out  <= a[2];
		b_out  <= b[2];
		c_out  <= c[2];
		d_out  <= d[2];
		e_out  <= e[2];
		f_out  <= f[2];
		g_out  <= g[2];
		p_out  <= p[2];

	end
	else if(state == 4'b0100)	
//state 4 gives the led outputs to the AN3	
	begin
		an[7:0] <= 8'b11110111;
		a_out  <= a[3];
		b_out  <= b[3];
		c_out  <= c[3];
		d_out  <= d[3];
		e_out  <= e[3];
		f_out  <= f[3];
		g_out  <= g[3];
		p_out  <= p[3];

	end
	else if(state == 4'b0101)	
//state 4 gives the led outputs to the AN4	
	begin
		an[7:0] <= 8'b11101111;
		a_out  <= a[4];
		b_out  <= b[4];
		c_out  <= c[4];
		d_out  <= d[4];
		e_out  <= e[4];
		f_out  <= f[4];
		g_out  <= g[4];
		p_out  <= p[4];

	end

	else if(state == 4'b0110)	
//state 4 gives the led outputs to the AN5	
	begin
		an[7:0] <= 8'b11011111;
		a_out  <= a[5];
		b_out  <= b[5];
		c_out  <= c[5];
		d_out  <= d[5];
		e_out  <= e[5];
		f_out  <= f[5];
		g_out  <= g[5];
		p_out  <= p[5];

	end

	else if(state == 4'b0111)	
//state 4 gives the led outputs to the AN6	
	begin
		an[7:0] <= 8'b10111111;
		a_out  <= a[6];
		b_out  <= b[6];
		c_out  <= c[6];
		d_out  <= d[6];
		e_out  <= e[6];
		f_out  <= f[6];
		g_out  <= g[6];
		p_out  <= p[6];

	end

	else if(state == 4'b1000)	
//state 4 gives the led outputs to the AN7	
	begin
		an[7:0] <= 8'b01111111;
		a_out  <= a[7];
		b_out  <= b[7];
		c_out  <= c[7];
		d_out  <= d[7];
		e_out  <= e[7];
		f_out  <= f[7];
		g_out  <= g[7];
		p_out  <= p[7];

	end

	else //For other states default inputs and outputs
	begin
		an[7:0] <= 8'b11111111;
		a_out  <= 1;
		b_out  <= 1;
		c_out  <= 1;
		d_out  <= 1;
		e_out  <= 1;
		f_out  <= 1;
		g_out  <= 1;
		p_out  <= 1;
	end
end

endmodule
