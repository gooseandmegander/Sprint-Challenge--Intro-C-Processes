#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  int i;
  DIR *dirPtr;
  struct dirent *direntPtr;

  printf("There are %d command line argument(s):\n\n", argc);

  if (!argv[1])
  {
    dirPtr = opendir(".");

    while ((direntPtr = readdir(dirPtr)) != NULL)
    {
      printf("%s\n", direntPtr->d_name);
    }

    int isClosed = closedir(dirPtr);
    if (isClosed != 0)
    {
      printf("CLOSEDIR unsuccessful");
    }
    exit(0);
  }

  for (i = 1; i < argc; i++)
  {
    printf("   %s\n", argv[i]);
    dirPtr = opendir(argv[i]);
    printf("dirPtr: %p\n", dirPtr);

    if ((dirPtr = opendir(argv[i])) == NULL)
    {
      printf("OPENDIR unsuccessful");
      exit(1);
    }

    while ((direntPtr = readdir(dirPtr)) != NULL)
    {
      printf("%s\n", direntPtr->d_name);
    }

    // Repeatly read and print entries

    // Close directory
    int isClosed = closedir(dirPtr);
    if (isClosed != 0)
    {
      printf("CLOSEDIR unsuccessful");
    }
  }

  return 0;
}