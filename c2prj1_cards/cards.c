#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"
#include <ctype.h>

void assert_card_valid(card_t c) {
  assert(c.value >=2 && c.value <= VALUE_ACE );
  assert(c.suit >= SPADES && c.suit <= CLUBS);
}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r){
  case STRAIGHT_FLUSH:
    return "Straigt Flush";
    break;
  case FOUR_OF_A_KIND:
    return "Four of a kind";
    break;
  case FULL_HOUSE:
    return "Full House";
    break;
  case FLUSH:
    return "Flush";
    break;
  case STRAIGHT:
    return "Straight";
    break;
  case THREE_OF_A_KIND:
    return "Three of a kind";
    break;
  case TWO_PAIR:
    return "Two Pair";
    break;
  case PAIR:
    return "Pair";
    break;
  case NOTHING:
    return "Nothing";
    break;
  default:
    return "nothing";
  }
  
  return "";
}

char value_letter(card_t c) {
  //char str[3];
  if(c.value >='2' && c.value <='9'){
    //return sprintf(str,"%d", c.value +'1'  ) +'1' ;
    return c.value + 2;
  }
  else if (c.value == 10){
    return '0';
  }
  else if (c.value>10)
    {
      switch (c.value){
      case VALUE_JACK:
	return 'J';
	break;
      case VALUE_QUEEN:
	return 'Q';
	break;
      case VALUE_KING:
	return 'K';
	break;
      case VALUE_ACE:
	return 'A';
	break;
      default:
	return 'o';
      }
    }
  return 'x';
    

}
char suit_letter(card_t c) {

  switch (c.suit)
    {
    case SPADES:
      return 's';
    case HEARTS:
      return 'h';
    case DIAMONDS:
      return 'd';
    case CLUBS:
      return 'c';

    default:
      return 'n';
    }
  return 'x';
  
}

void print_card(card_t c) {
  printf("%c%c", value_letter(c)  , suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  switch (suit_let)
    {
    case  's':
      temp.suit = SPADES;
      break;
    case 'h':
      temp.suit =  HEARTS;
      break;
    case 'd':
      temp.suit = DIAMONDS;
      break;
    case 'c':
      temp.suit = CLUBS;
      break;

    default:
      temp.suit = CLUBS;
    }


  if (isdigit(value_let) != 0)
    {
      if (value_let == '0')
	{
	  temp.value = 10;
	}
      else
	{
	  temp.value = value_let  ;
	}
    }
  else
    {
      switch (value_let){
      
      case 'J':
	temp.value = VALUE_JACK;
	break;
      
      case 'Q':
	temp.value = VALUE_QUEEN;
        break;
      
      case 'K':
	temp.value = VALUE_KING;
        break;
      
      case 'A':
	temp.value = VALUE_ACE;
        break;
	
      default:
        temp.value = '?';
      }
    }
  
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  assert(c >= 0 && c <= 51);
  int i = 0;
  temp.value = 1;
  for(; i<=c; i++) {


    /// estimating the suit
    if(i<=12) 
      temp.suit = CLUBS;
    else if (i<=25)
      temp.suit = DIAMONDS;
    else if (i<=38)
      temp.suit = HEARTS;
    else if (i<=51)
      temp.suit = SPADES;

    // estimating TEMP VALUE
    temp.value +=1 ;
    temp.value = temp.value % 15;
    if (temp.value == 0 ) temp.value += 2;
      }
  return temp;
}
