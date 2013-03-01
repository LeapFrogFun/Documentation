#include <math.h>

int main (){

	double BodyAngles [3];

	double BodyRates [3];

	double CPU_Time [1];

	double Quat [4];

	double NextQuat [4];

	double NextQuatDot [4];

	double NextBodyAngles [4];

	double NextBodyRates [4];


	double theta_mag, theta1, theta2, theta3;

	double L1, L2, L3;

	double q1, q2, q3, q4;

	double w, w1, w2, w3;

	double T;

	double trig_term, cos_term, sin_term;

	double q11, q12, q13, q14;

	double q21, q22, q23, q24;

	double L11, L12, L13;

	double L21, L22, L23;

	double theta_mag1, theta_mag2;



	BodyAngles[0] = 1.2;

	BodyAngles[0] = 2.3;

	BodyAngles[0] = -1.5;

	BodyRates[0] = 0.3;

	BodyRates[0] = -0.4;

	BodyRates[0] = -0.8;

	T = 0.5;



	theta1 = BodyAngles[0];

	theta2 = BodyAngles[1];

	theta3 = BodyAngles[2];



	theta_mag = sqrt(theta1*theta1 + theta2*theta2 + theta3*theta3);

	L1 = theta1/theta_mag;

	L2 = theta2/theta_mag;

	L3 = theta3/theta_mag;



	q1 = L1*sin(theta_mag/2.0);

	q2 = L2*sin(theta_mag/2.0);

	q3 = L3*sin(theta_mag/2.0);

	q4 = cos(theta_mag/2.0);



	Quat[0] = q1;

	Quat[1] = q2;

	Quat[2] = q3;

	Quat[3] = q4;













	w1 = BodyRates[0];

	w2 = BodyRates[1];

	w3 = BodyRates[2];

	T = CPU_Time[0];



	w = sqrt(w1*w1 + w2*w2 + w3*w3);

	trig_term = w*T/2.0;

	cos_term = cos(trig_term);

	sin_term = (1/w)*sin(trig_term);



	NextQuat[0] = cos_term*q1 + sin_term*(w3*q2 - w2*q3 + w1*q4);

	NextQuat[1] = cos_term*q2 + sin_term*(-w3*q1 + w1*q3 + w2*q4);

	NextQuat[2] = cos_term*q3 + sin_term*(w2*q1 - w1*q2 + w3*q4);

	NextQuat[3] = cos_term*q4 + sin_term*(-w1*q1 - w2*q2 - w3*q3);









	NextQuatDot[0] = 0.5*(w3*q2 - w2*q3 + w1*q4);

	NextQuatDot[1] = 0.5*(-w3*q1 + w1*q3 + w2*q4);

	NextQuatDot[2] = 0.5*(w2*q1 - w1*q2 + w3*q4);

	NextQuatDot[3] = 0.5*(-w1*q1 - w2*q2 - w3*q3);









	q11 = NextQuat[0];

	q12 = NextQuat[1];

	q13 = NextQuat[2];

	q14 = NextQuat[3];



	theta_mag1 = 2*acos(q14);

	L11 = q11/sin(theta_mag1/2.0);

	L12 = q12/sin(theta_mag1/2.0);

	L13 = q13/sin(theta_mag1/2.0);



	NextBodyAngles[0] = L11*theta_mag1;

	NextBodyAngles[1] = L12*theta_mag1;

	NextBodyAngles[2] = L13*theta_mag1;









	q21 = NextQuatDot[0];

	q22 = NextQuatDot[1];

	q23 = NextQuatDot[2];

	q24 = NextQuatDot[3];



	theta_mag2 = 2*acos(q24);

	L21 = q21/sin(theta_mag2/2.0);

	L22 = q22/sin(theta_mag2/2.0);

	L23 = q23/sin(theta_mag2/2.0);



	NextBodyRates[0] = L21*theta_mag2;

	NextBodyRates[1] = L22*theta_mag2;

	NextBodyRates[2] = L23*theta_mag2;
}
