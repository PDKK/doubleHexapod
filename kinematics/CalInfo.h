#ifndef _INC_CalInfo
#define _INC_CalInfo

// This information defines the geometry/hardware of the robot
// Essentially, it identifies the Platform and Node locations and Leg/Actuator limits

#define N_AXES (6)

#include "vector64.h"

enum tAxesOrder {
	AxesOrderUndefined = (-1),
	RollPitchYaw = 0,
	RollYawPitch,
	PitchRollYaw,
	PitchYawRoll,
	YawRollPitch,
	YawPitchRoll,
	AxesOrderLast
};

class fbCalInfo;
class fbCalInfo
{

public:
	vector64 Ball[N_AXES];		// Platform Nodes
	vector64 MidSphere[N_AXES];		// Middle platform
	vector64 MidBall[N_AXES];		// Middle Platform - Platform Nodes
	vector64 Sphere[N_AXES];	// Base Nodes

	vector64 i,j,k;				// Original Platform orientation

	double legLength[N_AXES];		// Home Leg Lengths (not used)
	double minLegLength[N_AXES];	// Min Leg Lengths
	double maxLegLength[N_AXES];	// Max Leg Lengths

	tAxesOrder RotOrder;		// determines order of multiplication of Rotational Matrices

	int n_Axes;					// number of Axes (6)

public:
	fbCalInfo()
	{
		// Platform "original" orientation
		i = vector64(1.0,0.0,0.0);
		j = vector64(0.0,1.0,0.0);
		k = vector64(0.0,0.0,1.0);

		// Order is Roll - Pitch - Yaw
		RotOrder = RollPitchYaw;

		n_Axes = N_AXES;

		// Platform Node locations (from a recently measured P-2000)
		Ball[0] = vector64( 136.49950, -128.60920, -71.92080 );
		Ball[1] = vector64( 179.45550, -53.92250, -72.05260 );
		Ball[2] = vector64( 43.07670, 182.60150, -72.56360 );
		Ball[3] = vector64( -43.02370, 182.38900, -72.51090 );
		Ball[4] = vector64( -179.57560, -53.92250, -72.08120 );
		Ball[5] = vector64( -136.43240, -128.53620, -71.95920 );

		// Base Node locations (from a recently measured P-2000)
		Sphere[0] = vector64( 80.25060, -439.51770, -1430.32127 );
		Sphere[1] = vector64( 420.78770, 150.48500, -1430.32107 );
		Sphere[2] = vector64( 340.31940, 289.22580, -1430.32327 );
		Sphere[3] = vector64( -340.61570, 289.12130, -1430.06687 );
		Sphere[4] = vector64( -420.69520, 150.48500, -1429.65787 );
		Sphere[5] = vector64( -80.04690, -439.79940, -1431.13167 );

		// Leg lengths
		for ( int ii=0; ii<n_Axes; ii++ ) {
			legLength[ii] = 1125.0;							// Home
			minLegLength[ii] = legLength[ii];				// Min
			maxLegLength[ii] = minLegLength[ii] + 625.0;	// MaX
		}
	}
};

#endif

