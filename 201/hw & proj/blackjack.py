"""
File: blackjack.py
Author: Wilfried Dim
Date: 3/18/2023
Section: 33
E-mail: wtendjo1@umbc.edu
Description: This program is a text-based version of Blackjack
"""

# imports random library and initializes deck and other constants
import random

DECK_OF_CARDS = ["2\u2663", "3\u2663", "4\u2663", "5\u2663", "6\u2663",
"7\u2663", "8\u2663", "9\u2663", "10\u2663", "J\u2663", "Q\u2663", "K\u2663",
"A\u2663", "2\u2660", "3\u2660", "4\u2660", "5\u2660", "6\u2660", "7\u2660",
"8\u2660", "9\u2660", "10\u2660", "J\u2660", "Q\u2660", "K\u2660", "A\u2660",
"2\u2661", "3\u2661", "4\u2661", "5\u2661", "6\u2661", "7\u2661", "8\u2661",
"9\u2661", "10\u2661", "J\u2661", "Q\u2661", "K\u2661", "A\u2661", "2\u2662",
"3\u2662", "4\u2662", "5\u2662", "6\u2662", "7\u2662", "8\u2662", "9\u2662",
"10\u2662", "J\u2662", "Q\u2662", "K\u2662", "A\u2662"]

HAND_VALUE_MAX = 21
MAX_DEALER_DRAW_VALUE = 17


def initial_card_deal(deck):
    # draws two cards for the player and the dealer
    hand = [deck[0], deck[1]]
    deck.append(deck[0])
    deck.append(deck[1])
    deck.pop(0)
    deck.pop(0)
    return hand


def hit_card_deal(hand, deck):
    # gives the user a new card after hitting
    new_hand = hand
    new_hand.append(deck[0])
    deck.append(deck[0])
    deck.pop(0)
    return new_hand


def hand_value_calculator(hand):
    # calculates the value of any given hand
    hand_value = 0
    for i in range(len(hand)):
        if len(hand[i]) == 2:
            card_value_list = hand[i]
            card_value = card_value_list[0]
            # retriever cards automatically makes hand worth 21
            if card_value == "R":
                return 21
            if card_value == "J" or card_value == "Q" or card_value == "K":
                hand_value += 10
            elif card_value == "A":
                if ace_status[0] == "<":
                    hand_value += 11
                else:
                    hand_value += 1
            else:
                hand_value += int(card_value[0])
        else:
            hand_value += 10
    return hand_value


def game_loop(num_of_decks, num_of_retriever_cards):
    # shuffles the deck and initializes ace_status
    live_deck = []
    ace_status = ["<"]
    for i in range(num_of_decks):
        for j in range(len(DECK_OF_CARDS)):
            live_deck.append(DECK_OF_CARDS[j])
    if num_of_retriever_cards > 0:
        for i in range(num_of_retriever_cards):
            live_deck.append("R*")
    random.shuffle(live_deck)

    # initializes starting number of quatloos
    quatloos = 100
    flag = True
    while flag:
        result = ""
        # asks for bet amount
        bet = int(input("You have" + " " + str(quatloos) + " " +
                        "quatloos, how many would you like to bet? "))
        # gets the initial hands for the player and dealer
        dealer_hand = initial_card_deal(live_deck)
        user_hand = initial_card_deal(live_deck)
        initial_dealer_hand_value = hand_value_calculator(dealer_hand)
        initial_user_hand_value = hand_value_calculator(user_hand)
        if initial_user_hand_value <= 10:
            ace_status = ["<"]
        else:
            ace_status = [">"]
        if initial_dealer_hand_value <= 10:
            ace_status = ["<"]
        else:
            ace_status = [">"]
        print("The dealer's hand is:", "\u2588\u2588", dealer_hand[1])
        print("Your hand is: ", user_hand[0], user_hand[1],
              "and has a value of", initial_user_hand_value)
        flag_2 = True
        while flag_2:
            # asks the user to play or hit
            play = input("What would you like to do? [hit or stay] ")
            if play == "hit":
                new_user_hand = hit_card_deal(user_hand, live_deck)
                new_user_hand_value = hand_value_calculator(new_user_hand)
                new_dealer_hand_value = initial_dealer_hand_value
                if initial_user_hand_value <= 10:
                    ace_status = ["<"]
                else:
                    ace_status = [">"]
                new_dealer_hand = dealer_hand
                print("Your hand is:", new_user_hand, "and has a value of",
                      new_user_hand_value)
                # user busts if hand value goes over 21
                if new_user_hand_value > HAND_VALUE_MAX:
                    print("You busted! You lost! :(")
                    result = "loss"
                    flag_2 = False
            elif play == "stay":
                new_dealer_hand_value = initial_dealer_hand_value
                new_dealer_hand = dealer_hand
                # dealer draws until hand value is greater than or
                # equal to 17
                while new_dealer_hand_value < MAX_DEALER_DRAW_VALUE:
                    new_dealer_hand = hit_card_deal(dealer_hand, live_deck)
                    new_dealer_hand_value += \
                        hand_value_calculator(new_dealer_hand)
                    if initial_dealer_hand_value <= 10:
                        ace_status = ["<"]
                    else:
                        ace_status = [">"]
                new_dealer_hand_value = hand_value_calculator(new_dealer_hand)
                print("The dealer's hand is now:", new_dealer_hand,
                      "and has a value of", new_dealer_hand_value)
                if initial_user_hand_value > HAND_VALUE_MAX:
                    if new_dealer_hand_value > HAND_VALUE_MAX:
                        print("You and the dealer both busted. It's a tie.")
                        result = "tie"
                        flag_2 = False
                    else:
                        print("You busted! You lost! :(")
                        result = "loss"
                        flag_2 = False
                elif new_dealer_hand_value > HAND_VALUE_MAX:
                    print("Dealer busted, you win.")
                    result = "win"
                    flag_2 = False
                else:
                    if new_user_hand_value > new_dealer_hand_value:
                        print("You beat the dealer!")
                        result = "win"
                        flag_2 = False
                    else:
                        print("The dealer wins")
                        result = "loss"
                        flag_2 = False

        # determines whether to add to subtract from current number of quatloos
        if result == "win":
            quatloos = quatloos + bet
        elif result == "loss":
            quatloos = quatloos - bet
        play_again = input("Would you like to play again? [yes/no] ")
        if play_again == "no":
            print("You ended the game with", quatloos, "quatloos!")
            flag = False


if __name__ == "__main__":
    # asks user for number of decks, the seed, and number of retriever cards
    user_decks = int(input("How many decks of cars would you like to use? "))
    user_seed = input("What seed would you like to use? ")
    random.seed(user_seed)
    user_retriever_cards = \
        int(input("How many Retriever cards would you like to add? "))
    # starts the game and runs until ended in the loop
    game_loop(user_decks, user_retriever_cards)


