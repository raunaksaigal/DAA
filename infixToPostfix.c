#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int  prec(char c){
  if(c=='^')
    return 3;
  else if(c=="*" || c=="/")
    return 2;
  else if(c=='+' || c=='-')
      return 1;
  else
    return -1;
}
char associativity(char c) {
    if (c == '^')
        return 'R';
    return 'L'; // Default to left-associative
}

void ip(char s[]){
  char result[100];
  char stack[100];
  int stackindex=-1;
  int resindex = 0;
  int l = strlen(s);
  
  for(int i=0; i<l; i++){
    char c=s[i];
    if(c>='a' && c<='z'){
      result[resindex++] = c;
    }
    else if(c=="(")
        stack[++stackindex] = c;
    else if(c==")"){
      while(stackindex>=0, stack[stackindex]!="("){
        result[resindex++] = stack[stackindex--];
      }
      stackindex--;
    }
    else{
      while(stackindex>=0 && (prec(c)<=prec(stack[stackindex])) && associativity(c) == "L"){
        result[resindex++]  = stack[stackindex--];
      }
      stack[++stackindex]=c;
    }
  }

  while(stackindex>=0){
    result[resindex++] = stack[stackindex--];
  }
  
  result[resindex] = '\0';
  printf("%s\n",result);
 
}

int main() {
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
 
    // Function call
    ip(exp);
 
    return 0;
}
