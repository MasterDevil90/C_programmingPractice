#include "cards.h"
#include <stdio.h>
int main(void) {
  card_t tem;

  tem = card_from_letters('9' , 's');
  print_card(tem);
  return 0;  
}
