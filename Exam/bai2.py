def counter_word(text):
    words = text.split()
    counter = {}
    for word in words:
        counter[word] = counter.get(word, 0) + 1 
    return counter


text = "hello world hello python python"
print(counter_word(text))  
