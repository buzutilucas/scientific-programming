/*----------------------------------------------------------------------
+----------------------------------------------------------------------+
| @file montecarlo.h                                                   |
| @author Lucas Fontes Buzuti                                          |
| @version V0.0.1                                                      |
| @created 08/28/2019                                                  |
| @modified 08/28/2019                                                 |
| @e-mail lucas.buzuti@outlook.com                                     |
+----------------------------------------------------------------------+
          Calculating the volume integral of a specific object
----------------------------------------------------------------------*/

#include <iostream>
#include <cmath>
#include <mpi.h>

using namespace std;

#define DARTS 5E6   //number of throws at dartboard
#define MASTER 0    //task ID of master task
#define LOW 0
#define HIGH 4

double dboard(int darts);

int main(int argc, char *argv[]) {
  double startime,     //start timer
         stoptime;     //stop timer
  double homeinteg,    //value of integrate calculated by current task
         integsum,     //sum of tasks' integrate values
         result;       //result of integrate
  int taskid,          //task ID - also used as seed number
   	  numtasks,        //number of tasks
   	  rs;              //return code sum integration
  srand((unsigned)time(NULL));   //start the generator random
  char hostname[MPI_MAX_PROCESSOR_NAME]; //hostname of each process

  MPI_Init(&argc,&argv);

  /*Obtain number of tasks and task ID*/
  MPI_Comm_size(MPI_COMM_WORLD,&numtasks);
  MPI_Comm_rank(MPI_COMM_WORLD,&taskid);

  srandom (taskid); //set seed for random number generator equal to task ID

  startime = MPI_Wtime();
  /*
  Calculate volume of object
  */
  homeinteg = dboard(DARTS);
  rs = MPI_Reduce(&homeinteg, &integsum, 1, MPI_DOUBLE,
                  MPI_SUM, MASTER, MPI_COMM_WORLD);

  if(rs != MPI_SUCCESS)
    std::cout << taskid << " failure on MPI_Reduce" << std::endl;

  if(taskid == MASTER)
  {
    result = integsum/numtasks; //the average of integration to all processor
    std::cout << "volume of object: " << result << std::endl;
  }
  stoptime = MPI_Wtime();
  std::cout << "Time of processor "<< taskid << ": " << stoptime - startime << std::endl;

  MPI_Finalize();

  return 0;
}

double dboard(int darts)
{
  double xCoord,     //coordinate x
         yCoord,     //coordinate y
         zCoord,     //coordinate z
         r,          //random numbers
         torus,      //torus equation
         score;      //score
  for(int i=0; i<darts; i++)
  {
    r = LOW + (double)(rand()) /((double)(RAND_MAX/(HIGH - LOW)));
    xCoord = (2.*r)-1.;
    r = LOW + (double)(rand()) /((double)(RAND_MAX/(HIGH - LOW)));
    yCoord = (2.*r)-1.;
    r = LOW + (double)(rand()) /((double)(RAND_MAX/(HIGH - LOW)));
    zCoord = (2.*r)-1.;

    /*if drat lands in object, increment score*/
    torus = pow(zCoord,2)+pow(sqrt(pow(xCoord,2)+pow(yCoord,2))-3,2);
    if((torus <= 1.) && (xCoord > 1.) && (yCoord >= -3.))
        score++;
  }

  /*calculate volume object*/
  return score/(double)darts;
}
