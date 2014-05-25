#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
  struct stat s;
  if (argc < 2)
    exit(EXIT_FAILURE);
  if( stat(argv[1],&s) == 0 )
    {
      if( s.st_mode & S_IFDIR )
	{
	  //directory
	  printf("directory\n");
	}
      else if( s.st_mode & S_IFREG )
	{
	  //it's a file
	  printf("file\n");
	}
      else if( s.st_mode & S_IFBLK )
	{
	  printf("block special file\n");
	}
      else if( s.st_mode & S_IFCHR )
	{
	  printf("character special\n");
	}
      else if( s.st_mode & S_IFIFO )
	{
	  printf("FIFO special\n");
	}
      else if( s.st_mode & S_IFLNK )
	{
	  printf("symbolic link\n");
	}
      else
	{
	  printf("something else\n");
	  //something else
	}
    }
  else
    {
      //error
      printf("error\n");
    }
}
