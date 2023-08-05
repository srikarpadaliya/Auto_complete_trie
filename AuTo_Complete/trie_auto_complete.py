class Node:
    def __init__(self):
        self.trie = [None] * 26
        self.flag = False

    def contains_char(self, c):
        return self.trie[ord(c) - ord('a')] is not None

    def add_new_char(self, c, ref):
        self.trie[ord(c) - ord('a')] = ref

    def get_to_node(self, c):
        return self.trie[ord(c) - ord('a')]

    def set_end(self):
        self.flag = True

    def is_end(self):
        return self.flag


class Trie:
    def __init__(self):
        self.root = Node()

    def insert(self, word):
        head = self.root
        n = len(word)
        for i in range(n):
            if not head.contains_char(word[i]):
                head.add_new_char(word[i], Node())
            head = head.get_to_node(word[i])
        head.set_end()

    def search(self, word):
        head = self.root
        n = len(word)
        for i in range(n):
            if not head.contains_char(word[i]):
                return False
            head = head.get_to_node(word[i])
        return head.is_end()


def is_last_node(root):
    for i in range(26):
        if root.contains_char(chr(i + ord('a'))):
            return False
    return True


def suggest(root, s, ans):
    if root.is_end():
        ans.append(s)

    if is_last_node(root):
        s = s[:-1]
        return

    for i in range(26):
        if root.contains_char(chr(i + ord('a'))):
            s += chr(i + ord('a'))
            suggest(root.get_to_node(chr(i + ord('a'))), s, ans)
            s = s[:-1]  # Remove the last character before backtracking


def print_suggestions(root, s):
    temp = root
    ans = []

    for i in range(len(s)):
        if not temp.contains_char(s[i]):
            return ans
        temp = temp.get_to_node(s[i])

    current = temp.is_end()
    last_node = is_last_node(temp)

    if last_node and current:
        ans.append(s)
        return ans

    if not last_node:
        new_string = s
        suggest(temp, new_string, ans)
        return ans

    return ans


if __name__ == "__main__":
    obj = Trie()

    obj.insert("hell")
    obj.insert("dog")
    obj.insert("heli")
    obj.insert("help")
    obj.insert("helps")
    obj.insert("helping")
    obj.insert("hello")
    obj.insert("helis")
    obj.insert("cat")

    ans = print_suggestions(obj.root, "hel")

    if not ans:
        print("No suggestion found!")
    else:
        for suggestion in ans:
            print(suggestion)
