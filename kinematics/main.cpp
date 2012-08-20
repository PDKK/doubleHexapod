#include "kinematics.h"
#include <stdio.h>

// main program to solicit the desired Cartesian position, calculate the Leg lengths and
// display the results

int testMain (int argc, char *argv)
{
	int i;
	fbReverse r;
	char inLn[127+1];

	fprintf(stdout,"Enter Position:  ");
	fflush(stdout);

	while ( fgets(inLn,127,stdin)!=NULL ) {

		if ( inLn[0]=='\0' || inLn[0]=='\n' ) break;

		fprintf(stdout,"\nInput = %s",inLn);

		r.X = r.Y = r.Z = r.Roll = r.Pitch = r.Yaw = 0.0;

		sscanf(inLn,"%lf %lf %lf %lf %lf %lf",
			   &r.X, &r.Y, &r.Z, &r.Roll, &r.Pitch, &r.Yaw);

		fprintf(stdout,"\nConsider %0.4lf %0.4lf %0.4lf %0.4lf %0.4lf %0.4lf\n",
				r.X, r.Y, r.Z, r.Roll, r.Pitch, r.Yaw);

		r.Calculate();

		fprintf(stdout,"\nLengths %0.4lf %0.4lf %0.4lf %0.4lf %0.4lf %0.4lf\n",
				r.l[0], r.l[1], r.l[2], r.l[3], r.l[4], r.l[5]);

		// display any errors (below min or above max)
		bool errorFlag = false;
		for ( i=0; i<6; i++ ) {
			if ( r.calI.minLegLength[i]<r.calI.maxLegLength[i] ) {
				if ( r.l[i]<r.calI.minLegLength[i] || r.l[i]>r.calI.maxLegLength[i] ) {
					if ( !errorFlag ) {
						fprintf(stdout,"\nErrors: ");
						errorFlag = true;
					}
					fprintf(stdout," %d%c",i,r.l[i]<r.calI.minLegLength[i]?'<':'>');
				}
			}
		}
		if ( errorFlag ) fprintf(stdout,"\n");

		fprintf(stdout,"\n\nEnter Position:  ");
		fflush(stdout);
	}
}
