#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

int main(int arg_count, char *arg_values[])
{
	FILE *file_pointer ;
	char file_line[1255],*line,*ref;
    char jwell_details[5][1255];
	file_pointer = fopen("./cartier_catalog.txt", "r") ;
	if ( file_pointer == NULL )
	{
		printf("cartier_catalog.txt file failed to open." ) ;
        exit;
	}	
	else
	{
		fgets ( file_line, 255, file_pointer );
		while( fgets ( file_line, 1255, file_pointer )!= NULL )
		{
			char *str = strtok(file_line, "\t");
			int c=0;
            ref = arg_values[1];
			if (strcmp(str, ref)==0){
    			while (str != NULL)
    			{
        			strcpy(jwell_details[c],str);
        			str = strtok(NULL, "\t");
					c=c+1;
    			}
				fclose(file_pointer);
			}
		}
	}
    printf ("Jwell Details are :\n"  ) ;
	printf ("Ref : %s\n" , jwell_details[0] ) ;
	printf ("Category : %s\n" , jwell_details[1] ) ;
	printf ("Title : %s\n" , jwell_details[2] ) ;
	printf ("Tags : %s\n" , jwell_details[3] ) ; 
	printf ("Price : %s\n" , jwell_details[6] ) ; 
	
}

