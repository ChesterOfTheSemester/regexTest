#include <stdio.h>
#include <string.h>
#include <regex.h>

char **regexTest(char *pattern, char *subject)
{
  unsigned int i,j,k,c;
  regex_t regex; char *rtn[(size_t)0xFFF];
  regmatch_t regex_matches[(size_t)0xFFF];

  if (regcomp(&regex, pattern, REG_EXTENDED)) return 0;

  for (i=0; i<0xFFF; i++)
  {
    if (regexec(&regex, subject, (size_t)0xFFF, regex_matches, 0)) break;

    for (j=0; j<0xFFF; j++)
    {
      if (regex_matches[j].rm_so == (size_t)-1) break;
      if (!j) k = regex_matches[j].rm_eo;

      char ch[strlen(subject) + 1];
      strcpy(ch, subject); ch[regex_matches[j].rm_eo] = 0;
      strcpy(rtn[c++]=calloc(1,(size_t)strlen(ch+regex_matches[j].rm_so)), (ch+regex_matches[j].rm_so));
    }

    subject += k;
  }

  regfree(&regex);
  return c?rtn:0;
}
