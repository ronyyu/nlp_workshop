#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define MAX_LENGTH 1024
#define TRUE 1
#define FALSE 0



int contains(const char *str1, const char *str2)
{
  char *sub_str = strstr(str1, str2);

  if(sub_str)
    return TRUE;
  return FALSE;
}

char *getAnswer(const char *input)
{
  if (contains(input, "france") == TRUE)
    return "C'est Emmanuel macron\n";
  return "Je n'ai pas de reponse a cette requete\n";
}

int strcmp(const char *s1, const char *s2)
{
  int ret = 0;

  while (!(ret = *(unsigned char *) s1 - *(unsigned char *) s2) && *s2) ++s1, ++s2;

  if (ret < 0)

    ret = -1;
  else if (ret > 0)

    ret = 1 ;

  return ret;
}

int main(int argc, char *argv[]) {
  char line[MAX_LENGTH];

  while (42) {
    printf("you: ");
    if (!fgets(line, MAX_LENGTH, stdin)) break;

    if (strcmp("(exit)\n", line) == 0)
      break;

    char *answer = getAnswer(line);
    
    printf("%s%s", "bot: ", answer);
  }

  return 0;
}
