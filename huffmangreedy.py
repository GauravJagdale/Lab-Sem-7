import heapq
from collections import defaultdict

# Define a class for HuffmanNode
class HuffmanNode:
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None

    # Custom comparison for priority queue
    def __lt__(self, other):
        return self.freq < other.freq  # Greedy strategy: Select nodes with lowest frequencies first

# Function to build the Huffman tree
def build_huffman_tree(data, frequencies):
    pq = [HuffmanNode(data[i], frequencies[i]) for i in range(len(data)]
    
    # Build the Huffman tree using a priority queue (greedy strategy: merge lowest frequency nodes)
    heapq.heapify(pq)

    while len(pq) > 1:
        left = heapq.heappop(pq)
        right = heapq.heappop(pq)
        internal_node = HuffmanNode('$', left.freq + right.freq)  # Create internal node
        internal_node.left = left
        internal_node.right = right
        heapq.heappush(pq, internal_node)

    return pq[0]  # Root of the Huffman tree

# Function to print Huffman codes
def print_huffman_codes(root, code, huffman_codes):
    if root:
        if root.char != '$':
            huffman_codes[root.char] = code
        print_huffman_codes(root.left, code + "0", huffman_codes)
        print_huffman_codes(root.right, code + "1", huffman_codes)

# Main function
def main():
    data = []
    frequencies = []

    n = int(input("Enter the number of characters: "))
    for i in range(n):
        char = input(f"Enter character {i + 1}: ")
        freq = int(input(f"Enter frequency for {char}: "))
        data.append(char)
        frequencies.append(freq)

    huffman_tree = build_huffman_tree(data, frequencies)
    huffman_codes = {}
    print_huffman_codes(huffman_tree, '', huffman_codes)

    print("Huffman Codes:")
    for char, code in huffman_codes.items():
        print(f"{char}: {code}")

if __name__ == "__main__":
    main()
