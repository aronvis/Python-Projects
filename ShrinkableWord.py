def is_shrinkable(word, lexicon):
    if word not in lexicon:
        return False
    if len(word) == 1:
        return True
    for letter_index in range(len(word)):
        shrunken_word = word[:letter_index] + word[letter_index+1:]
        if shrunken_word in lexicon and is_shrinkable(shrunken_word, lexicon):
            return True
    return False