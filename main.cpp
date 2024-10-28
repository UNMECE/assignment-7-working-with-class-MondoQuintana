#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;

class Electric_Field    
{
private:
    double *E;
public:
    Electric_Field(){
        E = (double*)malloc(3*sizeof(double));
        this->E[0]=0;
        this->E[1]=0;
        this->E[2]=0;
        cout<<"Default Electric Field set to 0"<<endl;
    };
    Electric_Field(double x, double y, double z){
        E = (double*)malloc(3*sizeof(double));
        this->E[0]=x;
        this->E[1]=y;
        this->E[2]=z;
    };
    double getElectric_Fieldx(){
        return E[0];
    }
    double getElectric_Fieldy(){
        return E[1];
    }
    double getElectric_Fieldz(){
        return E[2];
    }
    double calculateInnerProductEF(){
        return pow(E[0],2)+pow(E[1],2)+pow(E[2],2);
    }
    void setElectric_Field(double x, double y, double z){
        this->E[0] = x;
        this->E[1] = y;
        this->E[2] = z;
    }
    ~Electric_Field(){
        free(E);
        cout<<"Memory Free"<<endl;
    };
};

class Magnetic_Field    
{
private:
    double *M;
public:
    Magnetic_Field(){
        M = (double*)malloc(3*sizeof(double));
        this->M[0]=0;
        this->M[1]=0;
        this->M[2]=0;
        cout<<"Default Magnetic Field set to 0."<<endl;
    };
    Magnetic_Field(double x, double y, double z){
        M = (double*)malloc(3*sizeof(double));
        this->M[0]=x;
        this->M[1]=y;
        this->M[2]=z;
    };
    double getMagnetic_Fieldx(){
        return M[0];
    }
    double getMagnetic_Fieldy(){
        return M[1];
    }
    double getMagnetic_Fieldz(){
        return M[2];
    }
    void calculateUnitVectorMF(){
        double denom = sqrt(pow(M[0],2)+pow(M[1],2)+pow(M[2],2));
        double x = M[0]/denom;
        double y = M[1]/denom;
        double z = M[2]/denom;
        cout<<"Unit Vector for Magnetic Field is: "<<x<<" , "<<y<<" , "<<z<<endl;
    }
    void setMagnetic_Field(double x, double y, double z){
        this->M[0] = x;
        this->M[1] = y;
        this->M[2] = z;
    }
    ~Magnetic_Field(){
        free(M);
        cout<<"Memory Free"<<endl;
    };
};

int main()
{
    Electric_Field Electric_Field1; //create first EF with default
    cout<<"EF1 has x = "<<Electric_Field1.getElectric_Fieldx()<<" y = "<<Electric_Field1.getElectric_Fieldy()<< " and z = "<<Electric_Field1.getElectric_Fieldz()<<endl;
    cout<<"Innter Product is "<<Electric_Field1.calculateInnerProductEF()<<endl;
    Electric_Field Electric_Field2(4, 5, 6); //create second with overload
    cout<<"EF2 has x = "<<Electric_Field2.getElectric_Fieldx()<<" y = "<<Electric_Field2.getElectric_Fieldy()<< " and z = "<<Electric_Field2.getElectric_Fieldz()<<endl;
    cout<<"Inner Product is "<<Electric_Field2.calculateInnerProductEF()<<endl;
    Electric_Field1.setElectric_Field(4,5,6); //set first to different values
    cout<<"EF1 has x = "<<Electric_Field1.getElectric_Fieldx()<<" y = "<<Electric_Field1.getElectric_Fieldy()<< " and z = "<<Electric_Field1.getElectric_Fieldz()<<endl;
    cout<<"Innter Product is "<<Electric_Field1.calculateInnerProductEF()<<endl;
    Magnetic_Field Magnetic_Field1; //create first EF with default
    cout<<"MF1 has x = "<<Magnetic_Field1.getMagnetic_Fieldx()<<" y = "<<Magnetic_Field1.getMagnetic_Fieldy()<< " and z = "<<Magnetic_Field1.getMagnetic_Fieldz()<<endl;
    Magnetic_Field1.calculateUnitVectorMF();
    Magnetic_Field Magnetic_Field2(4, 5, 6); //create second with overload
    cout<<"MF2 has x = "<<Magnetic_Field2.getMagnetic_Fieldx()<<" y = "<<Magnetic_Field2.getMagnetic_Fieldy()<< " and z = "<<Magnetic_Field2.getMagnetic_Fieldz()<<endl;
    Magnetic_Field2.calculateUnitVectorMF();    

    return 0;
}