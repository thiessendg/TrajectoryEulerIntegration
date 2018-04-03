//
// Created by David on 02-Apr-2018.
//

#include <stdio.h>
#include <math.h>
int main() {
    /* Declare variables */
    double x;	    //position in x
    double y;	    //position in y
    double x_o;	    //Initial position in x
    double y_o;	    //Initial position in y
    double v;	    //velocity
    double v_x;	    //velocity in x
    double v_y;	    //velocity in y
    double v_x_o;	//Initial velocity in x
    double v_y_o;	//Initial velocity in y
    double p;	    //Air density
    double p_o;	    //Initial air density
    double m;	    //projectile mass
    double g;	    //gravity constant
    double theta;	//Initial launch angle
    double C;	    //Drag constant
    double A;	    //projectile area
    double dt, tmax, t; // Time step, Maximum time, Current time
    /* Set initial values for variables */
    v = 700.0;	//set initial velocity
    theta = M_PI/6.0;	//set initial angle to 30 degrees
    v_x = v_x_o;	//set initial speed variable in x
    v_x_o = v*cos(theta);	//set initial speed constant in x
    v_y = v_y_o;	//set initial speed variable in y
    v_y_o = v*sin(theta);	//set initial speed constant in y
    x = 0.0;	//initial position
    y = 0.0;	//initial position
    y_o = 10000.0;	//initial sea height
    m = 1.0;	//set ball mass
    p = 1.4;	//density of air
    g = 9.8;	//gravity constant
    C = 1.0;	//set drag constant
    A = 0.01;	//set ball area
    t = 0.0;	//set initial time
    dt = 0.5;	//set time steps
    tmax = 50.0;	//maximum time
    /* Now go through the steps until tmax is exceeded */
    printf("time\t\tx pos\t\ty pos\n");
    while (t < tmax ) {
        //no exact solution
        printf("%lf\t%lf\t%lf\n", t, x, y);	//print statement
        v = sqrt(v_x*v_x + v_y*v_y);	//total speed
        v_x = v_x - exp(-y/y_o)*(1.0/(2.0*m))*C*p*A*fabs(v_x)*v_x*dt;	//Euler's solution in x
        v_y	= v_y - g*dt - exp(-y/y_o)*(1.0/(2.0*m))*C*p*A*fabs(v_y)*v_y*dt;	//Euler's solution in y
        x = x + v_x*dt;	//Position in x as function of speed
        y = y + v_y*dt;	//Position in y as function of speed
        t = t + dt;	//time steps
    }
}
