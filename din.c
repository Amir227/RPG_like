int sizex = 0;
while (1) {
        if ((scanx = fscanf(IN1, "%lf", &a)) == 1) {
            sizex+=1;
           // printf ("sizex=%d 5\n", sizex);
            if (sizex == 1) {
                A = malloc(2 * sizex * sizeof(double));
            } else {
                A = realloc(A, (sizex+1) * sizeof(double));
            }
            A[i] = a;
            i+=1;
        } else {
            break;
        }
    }