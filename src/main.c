#include "matio.h"

int main(int argc, char **argv)
{
    matvar_t *matvar;
    
    mat_t    *matfp = Mat_Open("friction_of_roller_and_frame.mat", MAT_ACC_RDONLY);
    if ( NULL == matfp ) {
        fprintf(stderr, "Error opening MAT file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    matvar = Mat_VarRead(matfp, "friction_of_roller_and_frame");
    if ( NULL != matvar ) {
        Mat_VarPrint(matvar, 1);
        Mat_VarFree(matvar);
    }

    Mat_Close(matfp);
    return EXIT_SUCCESS;
}