`timescale 1ns / 1ps

module elevator(

input clk_50hz, rst,
    
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
    
    output reg led_inside_0,
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
    
    reg [7:0] a,b,c,d,e,f,g,p
    );
    
    //***********Your code goes here**************//
    
    
    //there are floors 0,1,2,3,4 -> total 5 floors 00001, 00010, 00100, 01000, 10000 respectively
    //status: Idle, Up, Down -> 001, 010, 100 respectively
    //might use bit shifting
    
    parameter IDLE = 2'b00, UP = 2'b01, DOWN = 2'b10;
    parameter F0 = 5'b00001, F1 = 5'b00010, F2 = 5'b00100, F3 = 5'b01000, F4 = 5'b10000;
    
    // counter thingies
    parameter counterIDLE = 1'b0, COUNT = 1'b1, LIMIT = 8'b101;
    reg counter_state; reg start; reg timeup;
    
    // Variables
    //initialization
    reg [4:0] current_floor = F0; //floor 0
    reg [4:0] destination; // farest destination floor requested by user
    reg [1:0] state = IDLE;  //state: Idle
    reg [1:0] direction = IDLE;
    reg [4:0] requestlist = 5'b00000; //to keep track of requests
    // if a request is accepted then the elevator will stop at
    // corresponding index's floor 
    
    reg [7:0] counter = 0;
    
    
    // getting requests
    always @(posedge clk_50hz or posedge rst) begin
        if (rst) begin
            destination <= F0;
            direction <= 0;
            requestlist <= 5'b00000; 
            led_outside_0 <= 0; led_outside_1 <= 0; led_outside_2 <= 0;
            led_outside_3 <= 0; led_outside_4 <= 0; led_inside_0 <= 0;
            led_inside_1 <= 0; led_inside_2 <= 0; led_inside_3 <= 0; led_inside_4 <= 0;
        end else begin
        
            // check for outside requests
            if (floor_0_p) begin
                direction <= DOWN;
                
                case (state)
                    IDLE: begin
                        if (current_floor == F0) begin
                            direction <= IDLE;
                        end else begin
                            destination <= F0;
                            requestlist[0] <= 1;
                            led_outside_0 <= 1;
                        end       
                    end
                    
                    DOWN: begin               
                        if (direction == DOWN) begin
                            if (destination <= F0 && F0 <= current_floor) begin
                                requestlist[0] <= 1;
                                led_outside_0 <= 1;
                            end else begin
                                requestlist <= requestlist;
                            end
                        end //else we ignore the request
                        else begin
                            requestlist <= requestlist;
                        end
                    end
                    
                    UP: begin
                        if (direction == UP) begin
                            if (destination >= F0 && F0 >= current_floor) begin
                                requestlist[0] <= 1;
                                led_outside_0 <= 1;
                            end else begin
                                requestlist <= requestlist;
                            end
                        end //else we ignore the request
                        else begin
                            requestlist <= requestlist;
                        end
                    end
                    
                    default:
                        direction <= IDLE;
                    
                endcase            
            end
            
            else if (floor_1_p) begin
                case (state)
                    IDLE: begin
                        if (direction_1)
                            direction <= UP;
                        else
                            direction <= DOWN;
                        if (current_floor == F1) begin
                            direction <= IDLE;
                        end else begin
                            destination <= F1;
                            requestlist[1] <= 1;
                            led_outside_1 <= 1;
                        end       
                    end
                    
                    DOWN: begin                             
                        if (!direction_1) begin
                            if (destination <= F1 && F1 <= current_floor) begin
                                requestlist[1] <= 1;
                                led_outside_1 <= 1;
                            end else begin
                                requestlist <= requestlist;
                            end
                        end //else we ignore the request
                        else begin
                            requestlist <= requestlist;
                        end
                    end
                    
                    UP: begin
                        if (direction_1) begin
                            if (destination >= F1 && F1 >= current_floor) begin
                                requestlist[1] <= 1;
                                led_outside_1 <= 1;
                            end else begin
                                requestlist <= requestlist;
                            end
                        end //else we ignore the request
                        else begin
                            requestlist <= requestlist;
                        end
                    end
                    
                    default:
                        direction <= IDLE;
                    
                endcase            
            end
        
            else if (floor_2_p) begin
                case (state)
                    IDLE: begin
                        if (current_floor == F2) begin
                            direction <= IDLE;
                        end else begin
                            destination <= F2;
                            requestlist[2] <= 1;
                            led_outside_2 <= 1;
                        end       
                    end
                    
                    DOWN: begin                             
                        if (!direction_2) begin
                            if (destination <= F2 && F2 <= current_floor) begin
                                requestlist[2] <= 1;
                                led_outside_2 <= 1;
                            end else begin
                                requestlist <= requestlist;
                            end
                        end //else we ignore the request
                        else begin
                            requestlist <= requestlist;
                        end
                    end
                    
                    UP: begin                            
                        if (direction_2) begin
                            if (destination >= F2 && F2 >= current_floor) begin
                                requestlist[2] <= 1;
                                led_outside_2 <= 1;
                            end else begin
                                requestlist <= requestlist;
                            end
                        end //else we ignore the request
                        else begin
                            requestlist <= requestlist;
                        end
                    end
                    
                    default:
                        direction <= IDLE;
                    
                endcase            
            end
            
            else if (floor_3_p) begin
                case (state)
                    IDLE: begin
                        if (current_floor == F3) begin
                            direction <= IDLE;
                        end else begin
                            destination <= F3;
                            requestlist[3] <= 1;
                            led_outside_3 <= 1;
                        end       
                    end
                    
                    DOWN: begin 
                        if (!direction_3) begin
                            if (destination <= F3 && F3 <= current_floor) begin
                                requestlist[3] <= 1;
                                led_outside_3 <= 1;
                            end else begin
                                requestlist <= requestlist;
                            end
                        end //else we ignore the request
                        else begin
                            requestlist <= requestlist;
                        end
                    end
                    
                    UP: begin
                        if (direction_3) begin
                            if (destination >= F3 && F3 >= current_floor) begin
                                requestlist[3] <= 1;
                                led_outside_3 <= 1;
                            end else begin
                                requestlist <= requestlist;
                            end
                        end //else we ignore the request
                        else begin
                            requestlist <= requestlist;
                        end
                    end
                    
                    default:
                        direction <= IDLE;
                    
                endcase            
            end
            
            else if (floor_4_p) begin
                direction <= UP;
                                        
                case (state)
                    IDLE: begin
                        if (current_floor == F4) begin
                            direction <= IDLE;
                        end else begin
                            destination <= F4;
                            requestlist[4] <= 1;
                            led_outside_4 <= 1;
                        end       
                    end
                    
                    DOWN: begin               
                        if (direction == DOWN) begin
                            if (destination <= F4 && F4 <= current_floor) begin
                                requestlist[4] <= 1;
                                led_outside_4 <= 1;
                            end else begin
                                requestlist <= requestlist;
                            end
                        end //else we ignore the request
                        else begin
                            requestlist <= requestlist;
                        end
                        
                    end
                    
                    UP: begin
                        if (direction == UP) begin
                            if (destination >= F4 && F4 >= current_floor) begin
                                requestlist[4] <= 1;
                                led_outside_4 <= 1;
                            end else begin
                                requestlist <= requestlist;
                            end
                        end //else we ignore the request
                        else begin
                            requestlist <= requestlist;
                        end
                    end
                    
                    default:
                        direction <= IDLE;
                    
                endcase            
            end
        
            // check for inside requests
            
            else if (floor_0_d) begin
                direction <= DOWN;
                case (state)
                    IDLE: begin                            
                        if (current_floor == F0) begin
                            direction <= IDLE;
                        end else begin
                            destination <= F0;
                            requestlist[0] <= 1;
                            led_inside_0 <= 1;
                        end       
                    end
                    
                    DOWN: begin
                        if (current_floor == F0)
                            direction <= IDLE;
                            
                        if (direction == DOWN) begin
                            if (destination <= F0 && F0 <= current_floor) begin
                                requestlist[0] <= 1;
                                led_inside_0 <= 1;
                            end else begin
                                requestlist <= requestlist;
                            end
                        end //else we ignore the request
                        else begin
                            requestlist <= requestlist;
                        end
                    end
                    
                    UP: begin                            
                        if (direction == UP) begin
                            if (destination >= F0 && F0 >= current_floor) begin
                                requestlist[0] <= 1;
                                led_inside_0 <= 1;
                            end else begin
                                requestlist <= requestlist;
                            end
                        end //else we ignore the request
                        else begin
                            requestlist <= requestlist;
                        end
                    end
                    
                    default:
                        direction <= IDLE;
                    
                endcase            
            end
            
            else if (floor_1_d) begin
                if (current_floor < F1)
                    direction <= UP;
                else if (current_floor > F1)
                    direction <= DOWN;
                else if (current_floor == F1)
                    direction <= IDLE;
                
                case (state)
                    IDLE: begin
                        destination <= F1;
                        requestlist[1] <= 1;
                        led_inside_1 <= 1;     
                    end
                    
                    DOWN: begin
                        if (direction == DOWN) begin
                            if (destination <= F1 && F1 <= current_floor) begin
                                requestlist[1] <= 1;
                                led_inside_1 <= 1;  
                            end else begin
                                requestlist <= requestlist;
                            end
                        end //else we ignore the request
                        else begin
                            requestlist <= requestlist;
                        end
                    end
                    
                    UP: begin
                        if (direction == UP) begin
                            if (destination >= F1 && F1 >= current_floor) begin
                                requestlist[1] <= 1;
                                led_inside_1 <= 1;  
                            end else begin
                                requestlist <= requestlist;
                            end
                        end //else we ignore the request
                        else begin
                            requestlist <= requestlist;
                        end
                    end
                    
                    default:
                        direction <= IDLE;
                    
                endcase            
            end
            
            else if (floor_2_d) begin
                if (current_floor < F2)
                    direction <= UP;
                else if (current_floor > F2)
                    direction <= DOWN;
                else if (current_floor == F2)
                    direction <= IDLE;
                    
                case (state)
                    IDLE: begin
                        destination <= F2;
                        requestlist[2] <= 1;  
                        led_inside_2 <= 1;       
                    end
                    
                    DOWN: begin
                        if (direction == DOWN) begin
                            if (destination <= F2 && F2 <= current_floor) begin
                                requestlist[2] <= 1;
                                led_inside_2 <= 1;
                            end else begin
                                requestlist <= requestlist;
                            end
                        end //else we ignore the request
                        else begin
                            requestlist <= requestlist;
                        end
                    end
                    
                    UP: begin
                        if (direction == UP) begin
                            if (destination >= F2 && F2 >= current_floor) begin
                                requestlist[2] <= 1;
                                led_inside_2 <= 1;
                            end else begin
                                requestlist <= requestlist;
                            end
                        end //else we ignore the request
                        else begin
                            requestlist <= requestlist;
                        end
                    end
                    
                    default:
                        direction <= IDLE;
                    
                endcase            
            end

            else if (floor_3_d) begin
                if (current_floor < F3)
                    direction <= UP;
                else if (current_floor > F3)
                    direction <= DOWN;
                else if (current_floor == F3)
                    direction <= IDLE;
            
                case (state)
                    IDLE: begin
                        destination <= F3;
                        requestlist[3] <= 1;
                        led_inside_3 <= 1;        
                    end
                    
                    DOWN: begin
                        if (direction == DOWN) begin
                            if (destination <= F3 && F3 <= current_floor) begin
                                requestlist[3] <= 1;
                                led_inside_3 <= 1; 
                            end else begin
                                requestlist <= requestlist;
                            end
                        end //else we ignore the request
                        else begin
                            requestlist <= requestlist;
                        end
                    end
                    
                    UP: begin
                        if (direction == UP) begin
                            if (destination >= F3 && F3 >= current_floor) begin
                                requestlist[3] <= 1;
                                led_inside_3 <= 1; 
                            end else begin
                                requestlist <= requestlist;
                            end
                        end //else we ignore the request
                        else begin
                            requestlist <= requestlist;
                        end
                    end
                    
                    default:
                        direction <= IDLE;
                    
                endcase            
            end
            
            else if (floor_4_d) begin
                if (current_floor < F4)
                    direction <= UP;
                else if (current_floor > F4)
                    direction <= DOWN;
                else if (current_floor == F4)
                    direction <= IDLE;
            
                case (state)
                    IDLE: begin
                        destination <= F4;
                        requestlist[4] <= 1;
                        led_inside_4 <= 1;           
                    end
                    
                    DOWN: begin
                        if (direction == DOWN) begin
                            if (destination <= F4 && F4 <= current_floor) begin
                                requestlist[4] <= 1;
                                led_inside_4 <= 1;   
                            end else begin
                                requestlist <= requestlist;
                            end
                        end //else we ignore the request
                        else begin
                            requestlist <= requestlist;
                        end
                    end
                    
                    UP: begin   
                        if (direction == UP) begin
                            if (destination >= F4 && F4 >= current_floor) begin
                                requestlist[4] <= 1;
                                led_inside_4 <= 1;   
                            end else begin
                                requestlist <= requestlist;
                            end
                        end //else we ignore the request
                        else begin
                            requestlist <= requestlist;
                        end
                    end
                    
                    default:
                        direction <= IDLE;
                    
                endcase            
            end
            
            
            case (current_floor)
                F0: begin
                    if (requestlist[0] == 1) begin
                        requestlist[0] <= 0;
                        led_inside_0 <= 0;
                        led_outside_0 <= 0;
                    end
                end
                
                F1: begin
                    if (requestlist[1] == 1) begin
                        requestlist[1] <= 0;
                        led_inside_1 <= 0;
                        led_outside_1 <= 0;
                    end 
                end
                
                F2: begin
                    if (requestlist[2] == 1) begin
                        requestlist[2] <= 0;
                        led_inside_2 <= 0;
                        led_outside_2 <= 0;
                    end
                end
                
                F3: begin
                    if (requestlist[3] == 1) begin
                        requestlist[3] <= 0;
                        led_inside_3 <= 0;
                        led_outside_3 <= 0;
                    end
                end
                
                F4: begin
                    if (requestlist[4] == 1) begin
                        requestlist[4] <= 0;
                        led_inside_4 <= 0;
                        led_outside_4 <= 0;
                    end
                end
                
                default: begin
                    requestlist <= requestlist;
                    led_inside_0 <= led_inside_0;
                    led_outside_0 <= led_outside_0;
                    led_inside_1 <= led_inside_1;
                    led_outside_1 <= led_outside_1;
                    led_inside_2 <= led_inside_2;
                    led_outside_2 <= led_outside_2;
                    led_inside_3 <= led_inside_3;
                    led_outside_3 <= led_outside_3;
                    led_inside_4 <= led_inside_4;
                    led_outside_4 <= led_outside_4;
                end
            endcase

                        
        end
    end
    
    always @(posedge clk_50hz or posedge rst) begin
        if (rst) begin
            current_floor <= F0;
            state <= IDLE;
            start <= 0;
            led_busy <= 0;
        end else begin
        
            //next_state = state;
            if (current_floor == destination) begin
                state <= IDLE;
                led_busy <= 0;
            end else if (current_floor < destination)
                state <= UP;
            else if (current_floor > destination)
                state <= DOWN;
            else 
                state <= state;
            
            case (current_floor)
                F0: begin
                
                    if (current_floor != destination) begin
                        if (state == UP)begin
                            if (timeup) begin
                                current_floor <= current_floor << 1;
                                led_busy <= 0;
                            end else begin
                                if (requestlist[0] == 1)
                                    led_busy <= 1;
                                else
                                    led_busy <= led_busy;
                                current_floor <= current_floor;
                            end 
                        end else if (state == DOWN)begin
                            if (timeup) begin
                                current_floor <= current_floor >> 1;
                                led_busy <= 0;
                            end else begin
                                if (requestlist[0] == 1)
                                    led_busy <= 1;
                                else
                                    led_busy <= led_busy;
                                current_floor <= current_floor;
                            end
                        end else begin
                            current_floor <= current_floor;
                        end
                        
                        if (state != IDLE)
                            start = 1;
                        else 
                            start = 0;
                        
                    end else begin
                        led_busy <= 1;
                    end
                end  
                F1: begin
                        
                    if (current_floor != destination) begin
                        if (state == UP)begin
                            if (timeup) begin
                                current_floor <= current_floor << 1;
                                led_busy <= 0;
                            end else begin
                                if (requestlist[1] == 1)
                                    led_busy <= 1;
                                else
                                    led_busy <= led_busy;
                                current_floor <= current_floor;
                            end    
                        end else if (state == DOWN)begin
                            if (timeup) begin
                                current_floor <= current_floor >> 1;
                                led_busy <= 0;
                            end else begin
                                if (requestlist[1] == 1)
                                    led_busy <= 1;
                                else
                                    led_busy <= led_busy;
                                current_floor <= current_floor;
                            end
                        end else begin
                            current_floor <= current_floor;
                        end
                        
                        if (state != IDLE)
                            start = 1;
                        else 
                            start = 0;
                    end else begin
                        led_busy <= 1;
                    end
                end
                F2: begin
                         
                    if (current_floor != destination) begin
                        if (state == UP)begin
                            if (timeup) begin
                                current_floor <= current_floor << 1;
                                led_busy <= 0;
                            end else begin
                                if (requestlist[2] == 1)
                                    led_busy <= 1;
                                else
                                    led_busy <= led_busy;
                                current_floor <= current_floor;
                            end
                        end else if (state == DOWN)begin
                            if (timeup) begin
                                current_floor <= current_floor >> 1;
                                led_busy <= 0;
                            end else begin
                                current_floor <= current_floor;
                                if (requestlist[2] == 1)
                                    led_busy <= 1;
                                else
                                    led_busy <= led_busy;
                            end
                        end else begin
                            current_floor <= current_floor;
                        end
                        
                        if (state != IDLE)
                            start = 1;
                        else
                            start = 0; 
                    end else begin
                        led_busy <= 1;
                    end
                end
                F3: begin
                
                    if (current_floor != destination) begin
                        if (state == UP)begin
                            if (timeup) begin
                                current_floor <= current_floor << 1;
                                led_busy <= 0;
                            end else begin
                                current_floor <= current_floor;
                                if (requestlist[3] == 1)
                                    led_busy <= 1;
                                else
                                    led_busy <= led_busy;
                            end    
                        end else if (state == DOWN)begin
                            if (timeup) begin
                                current_floor <= current_floor >> 1;
                                led_busy <= 0;
                            end else begin
                                current_floor <= current_floor;
                                if (requestlist[3] == 1)
                                    led_busy <= 1;
                                else
                                    led_busy <= led_busy;
                            end
                        end else begin
                            current_floor <= current_floor;
                        end
                        
                        if (state != IDLE)
                            start = 1;
                        else 
                            start = 0;   
                        
                    end else begin
                        led_busy <= 1;
                    end
                end
                F4: begin
                                    
                    if (current_floor != destination) begin
                        if (state == UP)begin
                            if (timeup) begin
                                current_floor <= current_floor << 1;
                                led_busy <= 0;
                            end else begin
                                current_floor <= current_floor;
                                if (requestlist[4] == 1)
                                    led_busy <= 1;
                                else
                                    led_busy <= led_busy;
                            end  
                        end else if (state == DOWN)begin
                            if (timeup) begin
                                current_floor <= current_floor >> 1;
                                led_busy <= 0;
                            end else begin
                                current_floor <= current_floor;
                                if (requestlist[4] == 1)
                                    led_busy <= 1;
                                else
                                    led_busy <= led_busy;
                            end
                        end else begin
                            current_floor <= current_floor;
                        end
                        
                        if (state != IDLE)
                            start = 1;
                        else 
                            start = 0;
                        
                    end else begin
                        led_busy <= 1;
                    end
                end
                default: begin
                    state <= IDLE;
                    current_floor <= F0;
                    start <= 0;
                    led_busy <= 0;
                end
            endcase
            
            
            if(state == IDLE)
                led_busy <= 0;
            
        end
        
    end
    
    always @(*) begin
        if(rst)
            timeup = 0;
        else begin
            case (counter_state)
                COUNT: begin
                    if (counter == 249)
                        timeup = 1;
                    else 
                        timeup = 0;
                end
                default:
                    timeup = 0;
            endcase
        end
    end
    
    always @ (posedge clk_50hz, posedge rst) begin
        if(rst) begin
            counter <= 0;
            counter_state <= 0;
        end else if(start) begin
            if(counter == 249) begin
                counter <= LIMIT;
                counter <= 0;
                counter_state <= counterIDLE;
            end else begin
                counter <= counter +1;
                counter_state <= COUNT;
            end
       end else
            counter <= 0;
           
    end
            
    always @(state or current_floor or rst) begin
        if (rst) begin
            a = 0; b = 0; c = 0;
            d = 0; e = 0; f = 0;
            g = 0; p = 0;
        end else begin
            case(state) 
                IDLE:begin
                    case(current_floor)
                        F0:begin
                            a[7:0]=8'b11110110;
                            b[7:0]=8'b11001110;
                            c[7:0]=8'b11001110;
                            d[7:0]=8'b11101010;
                            e[7:0]=8'b11100010;
                            f[7:0]=8'b11110010;
                            g[7:0]=8'b11100111;
                            p[7:0]=8'b11111110;            
                            //state: IDLE Floor: F0
                        end
                        
                        F1:begin
                            a[7:0]=8'b11110111;
                            b[7:0]=8'b11001110;
                            c[7:0]=8'b11001110;
                            d[7:0]=8'b11101011;
                            e[7:0]=8'b11100011;
                            f[7:0]=8'b11110011;
                            g[7:0]=8'b11100111;
                            p[7:0]=8'b11111111;            
                            //state: IDLE Floor: F1   
                        end
                        
                        F2:begin
                            a[7:0]=8'b11110110;
                            b[7:0]=8'b11001110;
                            c[7:0]=8'b11001111;
                            d[7:0]=8'b11101010;
                            e[7:0]=8'b11100010;
                            f[7:0]=8'b11110011;
                            g[7:0]=8'b11100110;
                            p[7:0]=8'b11111111;            
                            //state: IDLE Floor: F2
                        end
                    
                        F3:begin
                            a[7:0]=8'b11110110;
                            b[7:0]=8'b11001110;
                            c[7:0]=8'b11001110;
                            d[7:0]=8'b11101010;
                            e[7:0]=8'b11100011;
                            f[7:0]=8'b11110011;
                            g[7:0]=8'b11100110;
                            p[7:0]=8'b11111110;            
                            //state: IDLE Floor: F3   
                        end
                        
                        F4:begin
                            a[7:0]=8'b11110111;
                            b[7:0]=8'b11001110;
                            c[7:0]=8'b11001110;
                            d[7:0]=8'b11101011;
                            e[7:0]=8'b11100011;
                            f[7:0]=8'b11110010;
                            g[7:0]=8'b11100110;
                            p[7:0]=8'b11111110;            
                            //state: IDLE Floor: F4       
                        end
                        
                    endcase
                end
                
                UP: begin
                    case(current_floor)
                        F0:begin
                            a[7:0]=8'b11100110;
                            b[7:0]=8'b11001110;
                            c[7:0]=8'b11011110;
                            d[7:0]=8'b11011010;
                            e[7:0]=8'b11000010;
                            f[7:0]=8'b11000010;
                            g[7:0]=8'b11100111;
                            p[7:0]=8'b11111110;            
                            //state: IDLE Floor: F0
                        end
                        
                        F1:begin
                            a[7:0]=8'b11100111;
                            b[7:0]=8'b11001110;
                            c[7:0]=8'b11011110;
                            d[7:0]=8'b11011011;
                            e[7:0]=8'b11000011;
                            f[7:0]=8'b11000011;
                            g[7:0]=8'b11100111;
                            p[7:0]=8'b11111111;            
                            //state: IDLE Floor: F1   
                        end
                        
                        F2:begin
                            a[7:0]=8'b11100110;
                            b[7:0]=8'b11001110;
                            c[7:0]=8'b11011111;
                            d[7:0]=8'b11011010;
                            e[7:0]=8'b11000010;
                            f[7:0]=8'b11000011;
                            g[7:0]=8'b11100110;
                            p[7:0]=8'b11111111;            
                            //state: IDLE Floor: F2
                        end
                    
                        F3:begin
                            a[7:0]=8'b11100110;
                            b[7:0]=8'b11001110;
                            c[7:0]=8'b11011110;
                            d[7:0]=8'b11011010;
                            e[7:0]=8'b11000011;
                            f[7:0]=8'b11000011;
                            g[7:0]=8'b11100110;
                            p[7:0]=8'b11111110;            
                            //state: IDLE Floor: F3   
                        end
                        
                        F4:begin
                            a[7:0]=8'b11100111;
                            b[7:0]=8'b11001110;
                            c[7:0]=8'b11011110;
                            d[7:0]=8'b11011011;
                            e[7:0]=8'b11000011;
                            f[7:0]=8'b11000010;
                            g[7:0]=8'b11100110;
                            p[7:0]=8'b11111110;            
                            //state: IDLE Floor: F4       
                        end
                        
                    endcase
                end
                
                DOWN: begin
                    case(current_floor)
                        F0:begin
                            a[7:0]=8'b11100110;
                            b[7:0]=8'b11001110;
                            c[7:0]=8'b11001110;
                            d[7:0]=8'b11001010;
                            e[7:0]=8'b11000010;
                            f[7:0]=8'b11100010;
                            g[7:0]=8'b11010111;
                            p[7:0]=8'b11111110;            
                            //state: IDLE Floor: F0
                        end
                        
                        F1:begin
                            a[7:0]=8'b11100111;
                            b[7:0]=8'b11001110;
                            c[7:0]=8'b11001110;
                            d[7:0]=8'b11001011;
                            e[7:0]=8'b11000011;
                            f[7:0]=8'b11100011;
                            g[7:0]=8'b11010111;
                            p[7:0]=8'b11111111;            
                            //state: IDLE Floor: F1   
                        end
                        
                        F2:begin
                            a[7:0]=8'b11100110;
                            b[7:0]=8'b11001110;
                            c[7:0]=8'b11001111;
                            d[7:0]=8'b11001010;
                            e[7:0]=8'b11000010;
                            f[7:0]=8'b11100011;
                            g[7:0]=8'b11010110;
                            p[7:0]=8'b11111111;            
                            //state: IDLE Floor: F2
                        end
                    
                        F3:begin
                            a[7:0]=8'b11100110;
                            b[7:0]=8'b11001110;
                            c[7:0]=8'b11001110;
                            d[7:0]=8'b11001010;
                            e[7:0]=8'b11000011;
                            f[7:0]=8'b11100011;
                            g[7:0]=8'b11010110;
                            p[7:0]=8'b11111110;            
                            //state: IDLE Floor: F3   
                        end
                        
                        F4:begin
                            a[7:0]=8'b11100111;
                            b[7:0]=8'b11001110;
                            c[7:0]=8'b11001110;
                            d[7:0]=8'b11001011;
                            e[7:0]=8'b11000011;
                            f[7:0]=8'b11100010;
                            g[7:0]=8'b11010110;
                            p[7:0]=8'b11111110;            
                            //state: IDLE Floor: F4       
                        end
                        
                    endcase
                
                end
                
            endcase
        end
            
        
        
    end
    
    //***********Your code goes here**************//
    
endmodule
