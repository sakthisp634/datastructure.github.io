#include <stdio.h>

int main () {

	static int ma[10][10],mb[10][10];

	int i,j,k,a,m,n;
         clrscr();
	printf ("Enter the order of the matrix \n");

	scanf ("%d %d", &m,&n);

	printf ("Enter co-efficients of the matrix \n");

	for (i=0;i<m;++i) {

		for (j=0;j<n;++j) {

			scanf ("%d",&ma[i][j]);

			mb[i][j] = ma[i][j];

		}

	}

	printf ("The given matrix is \n");

	for (i=0;i<m;++i) {

		for (j=0;j<n;++j) {

			printf (" %d",ma[i][j]);

		}

		printf ("\n");

	}

	printf ("After arranging rows in ascending order\n");

	for (i=0;i<m;++i) {

		for (j=0;j<n;++j) {

			for (k=(j+1);k<n;++k) {

				if (ma[i][j] > ma[i][k]) {

					a = ma[i][j];

					ma[i][j] = ma[i][k];

					ma[i][k] = a;

				}

			}

		}

	}

	/* End of outer for loop*/

	for (i=0;i<m;++i) {

		for (j=0;j<n;++j) {

			printf (" %d",ma[i][j]);

		}

		printf ("\n");

	}

	printf ("After arranging the columns in descending order \n");

	for (j=0;j<n;++j) {
		for (i=0;i<m;++i) {

			for (k=i+1;k<m;++k) {

				if (mb[i][j] < mb[k][j]) {

					a = mb[i][j];

					mb[i][j] = mb[k][j];

					mb[k][j] = a;

				}

                      }

		}

	}

	/* End of outer for loop*/

	for (i=0;i<m;++i) {

		for (j=0;j<n;++j) {

			printf (" %d",mb[i][j]);

		}

		printf ("\n");

	}

        printf("Output for m=5,n=6\n");
        fillOX(5,6);
        printf("Output for m=4,n=4\n");
        fillOX(4,4);
        printf("output for m=6,n=7\n");
        fillOX(6,7);
        getch();
        return 0;

}

int fillOX(int m, int n)
{
    /*  k - starting row index
        m - ending row index
        l - starting column index
        n - ending column index
        i - iterator            */

            int i, k = 0,j, l = 0;

    // Store given number of rows and columns for later use
    int r = m, c = n;

    // A 2D array to store the output to be printed
    char a[20][20];
    char x = 'X'; // Initialize the character to be stored in a[][]

    // Fill characters in a[][] in spiral form. Every iteration fills
    // one rectangle of either Xs or Os
    while (k < m && l < n)
    {
        // Fill the first row from the remaining rows
        for (i = l; i < n; ++i)
            a[k][i] = x;
        k++;

       // Fill the last column from the remaining columns
               for (i = k; i < m; ++i)
            a[i][n-1] = x;
        n--;

        // Fill the last row from the remaining rows
        if (k < m)
        {
            for (i = n-1; i >= l; --i)
                a[m-1][i] = x;
            m--;
        }

     // Print the first column from the remaining columns
        if (l < n)
        {
            for (i = m-1; i >= k; --i)
                a[i][l] = x;
            l++;
        }

        // Flip character for next iteration
        x = (x == '0')? 'X': '0';
    }

    // Print the filled matrix
    for (i = 0; i < r; i++)
    {
        for ( j = 0; j < c; j++)
            printf("%c ", a[i][j]);
        printf("\n");
    }
}


