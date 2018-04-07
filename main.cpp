//
// Created by David on 02-Apr-2018.
//

#include <cstdio>
#include <cmath>
int main() {
    /* Declare variables */
    double xt=0.0;	    //position x at time t
    double yt=0.0;	    //position y at time t

    double x_0=0.0;	    //Initial position x at time 0
    double y_0=0.0;	    //Initial position y at time 0

    double theta = M_PI/6.0;	//set initial angle to 30 degrees
    double v=15.0;	    //velocity
    double v_x_0=v*cos(theta);	//Initial velocity in x at time 0
    double v_y_0=v*sin(theta);	//Initial velocity in y at time 0

    double v_x=v_x_0;	    //velocity in x
    double v_y=v_y_0;	    //velocity in y


    //double p;	    //Air density
    //double p_0;	    //Initial air density

    //double m;	    //projectile mass

    double g=-9.81;	    //gravity constant

    //double C;	    //Drag constant

    //double A;	    //projectile area

    double dt, tmax, t; // Time step, Maximum time, Current time

    /* Set initial values for variables */

    //xt = 0.0;	//initial position
    //yt = 0.0;	//initial position
    //x_0 = 0.0;  //initial x
    //y_0 = 0.0;	//initial height y

    //m = 1.0;	//set ball mass
    //p = 1.4;	//density of air
    //C = 1.0;	//set drag constant
    //A = 0.01;	//set ball area
    t = 0.0;	//set initial time
    dt = 0.1;	//set time steps
    tmax = 50.0;	//maximum time

    /* Now go through the steps until tmax is exceeded */
    printf("time\t\tx(t)\t\ty(t)\n");
    while (t < tmax && yt >= 0.0) {
        //no exact solution
        printf("%lf\t%lf\t%lf\n", t, xt, yt);	//print statement

        v_x = v_x;// - exp(-yt/y_0)*(1.0/(2.0*m))*C*p*A*fabs(v_x)*v_x*dt;	//Euler's solution in xt
        v_y	= v_y + g*dt;// - exp(-yt/y_0)*(1.0/(2.0*m))*C*p*A*fabs(v_y)*v_y*dt;	//Euler's solution in yt

        v = sqrt(v_x*v_x + v_y*v_y);	//total speed

        xt = xt + v_x*dt;	//Position in xt as function of speed
        yt = yt + v_y*dt;	//Position in yt as function of speed

        t = t + dt;	//time steps
    }

    return 0;
}
