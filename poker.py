kRating = {
    'A': 14, 'K': 13, 'Q': 12, 'J': 11, 'T': 10, '9': 9, '8': 8,
    '7': 7, '6': 6, '5': 5, '4': 4, '3': 3, '2': 2,
}


def check_winner(card, hands):
    winners = []
    for i in range(len(hands)):
        if hands[i][0][0] == hands[i][1][0] and hands[i][0][0] == card[0]:
            winners.append((300 + kRating[hands[i][0][0]], i))
            continue
        if hands[i][0][0] == hands[i][1][0] or hands[i][0][0] == card[0]:
            winners.append((200 + kRating[hands[i][0][0]], i))
            continue
        if hands[i][1][0] == card[0]:
            winners.append((200 + kRating[hands[i][1][0]], i))
            continue
        max_card = max(kRating[hands[i][0][0]],
                       kRating[hands[i][1][0]], kRating[card[0]])
        winners.append((max_card, i))
    result = False
    winners.sort(reverse=True)
    winner = winners[0]
    if winner[1] == 0:
        result = True
    else:
        for w in winners:
            if w[0] == winner[0] and w[1] == 0:
                result = True
                break
    return result


def main():
    deck = ["AS", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "TS", "JS",
            "QS", "KS", "AH", "2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H",
            "TH", "JH", "QH", "KH", "AD", "2D", "3D", "4D", "5D", "6D", "7D",
            "8D", "9D", "TD", "JD", "QD", "KD", "AC", "2C", "3C", "4C", "5C",
            "6C", "7C", "8C", "9C", "TC", "JC", "QC", "KC"]
    t = int(input())
    hands = []
    deck_copy = [deck.copy() for _ in range(t)]
    for test in range(t):
        n = int(input())
        player_hands = []
        for _ in range(n):
            hand = input().split()
            player_hands.append((hand[0], hand[1]))
            deck_copy[test].remove(hand[0])
            deck_copy[test].remove(hand[1])
        hands.append(player_hands)

    for i in range(t):
        win_deck = [card for card in deck_copy[i]
                    if check_winner(card, hands[i])]
        print(len(win_deck))
        for card in win_deck:
            print(card)


if __name__ == "__main__":
    main()
