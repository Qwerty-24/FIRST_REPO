// Hash Table Implementation Template
// Instructions: Implement the missing function definitions for each class.
// Each function has comments indicating what it should do.

#include <iostream>
#include <list>
#include <string>
#include <stdexcept>

//-------------------- HASH FUNCTION HELPERS --------------------
// Helper function to hash strings using Horner's rule
int hashString(const std::string& str, int tableSize) {
    // TODO: Implement string hashing function using Horner's rule
    // Use a prime number as the base (e.g., 31)
    // Return hash value modulo tableSize
    unsigned int h = 0;
    for (char c : str) h = (h * 31 + c) % tableSize;
    return h;
}

// Helper function to hash integers
int hashInt(int key, int tableSize) {
    // TODO: Implement simple integer hash function
    // Consider using the division method: h(k) = k mod tableSize
    return (key % tableSize + tableSize) % tableSize;
}

//-------------------- SEPARATE CHAINING HASH TABLE --------------------
// Generic hash table using separate chaining for collision resolution
template <typename K, typename V>
class SeparateChainingHashTable {
private:
    // Each bucket contains a list of key-value pairs
    struct KeyValuePair {
        K key;
        V value;
        KeyValuePair(const K& k, const V& v) : key(k), value(v) {}
    };

    std::list<KeyValuePair>* buckets; // Array of linked lists
    int tableSize;                    // Number of buckets
    int itemCount;                    // Total number of items in the hash table

    // Hash function - will be defined differently for different key types
    int hash(const K& key) const {
        // TODO: Implement hash function selector based on key type
        struct Selector {
            int operator()(const std::string& k, int s) { return hashString(k, s); }
            int operator()(int k, int s) { return hashInt(k, s); }
        };
        return Selector()(key, tableSize);
    }

public:
    // Constructor: Initialize hash table with given size
    SeparateChainingHashTable(int size = 101) {
        // TODO: Implement constructor
        tableSize = size; itemCount = 0;
        buckets = new std::list<KeyValuePair>[tableSize];
    }

    // Destructor: Free dynamically allocated memory
    ~SeparateChainingHashTable() {
        // TODO: Implement destructor
        delete[] buckets;
    }

    // Insert a key-value pair into the hash table
    // If key already exists, update its value
    void insert(const K& key, const V& value) {
        // TODO: Implement insert function
        int h = hash(key);
        for (auto& p : buckets[h]){
            if (p.key == key) { p.value = value; return; }
        }
        buckets[h].push_back(KeyValuePair(key, value));
        itemCount++;
    }

    // Remove a key-value pair from the hash table
    // Throw exception if key not found
    void remove(const K& key) {
        // TODO: Implement remove function
        int h = hash(key);
        for (auto it = buckets[h].begin(); it != buckets[h].end(); ++it){
            if (it->key == key) { buckets[h].erase(it); itemCount--; return; }
        }
        throw std::runtime_error("Key not found");
    }

    // Search for a value associated with the given key
    // Throw exception if key not found
    V search(const K& key) const {
        // TODO: Implement search function
        int h = hash(key);
        for (const auto& p : buckets[h]){
            if (p.key == key) return p.value;
        }
        throw std::runtime_error("Key not found");
    }

    // Check if the hash table contains the given key
    bool contains(const K& key) const {
        // TODO: Implement contains function
        int h = hash(key);
        for (const auto& p : buckets[h]){
            if (p.key == key) return true;
        }
        return false;
    }

    // Return the current load factor
    float loadFactor() const {
        // TODO: Implement load factor calculation
        return (float)itemCount / tableSize;
    }

    // Return number of items in the hash table
    int size() const {
        // TODO: Implement size function
        return itemCount;
    }

    // Display the hash table (for debugging)
    void display() const {
        // TODO: Implement display function
        for (int i = 0; i < tableSize; i++){
            std::cout << "Bucket " << i << ": ";
            for (const auto& p : buckets[i]) std::cout << "[" << p.key << ":" << p.value << "] ";
            std::cout << std::endl;
        }
    }
};

//-------------------- OPEN ADDRESSING HASH TABLE --------------------
// Generic hash table using open addressing for collision resolution
template <typename K, typename V>
class OpenAddressingHashTable {
private:
    enum EntryStatus { EMPTY, OCCUPIED, DELETED };

    struct Entry {
        K key;
        V value;
        EntryStatus status;
        
        Entry() : status(EMPTY) {}
    };

    Entry* table;      // Array of entries
    int tableSize;     // Size of the table
    int itemCount;     // Number of items in the table

    // Hash function
    int hash(const K& key) const {
        // TODO: Implement hash function selector based on key type
        struct Selector {
            int operator()(const std::string& k, int s) { return hashString(k, s); }
            int operator()(int k, int s) { return hashInt(k, s); }
        };
        return Selector()(key, tableSize);
    }

    // Probe function for collision resolution (linear probing)
    int probe(int hash, int i) const {
        // TODO: Implement linear probing
        return (hash + i) % tableSize;
    }

public:
    // Constructor: Initialize hash table with given size
    OpenAddressingHashTable(int size = 101) {
        // TODO: Implement constructor
        tableSize = size; itemCount = 0;
        table = new Entry[tableSize];
    }

    // Destructor: Free dynamically allocated memory
    ~OpenAddressingHashTable() {
        // TODO: Implement destructor
        delete[] table;
    }

    // Insert a key-value pair into the hash table
    // If key already exists, update its value
    // If table is full, throw an exception
    void insert(const K& key, const V& value) {
        // TODO: Implement insert function
        if (itemCount >= tableSize) throw std::overflow_error("Hash table is full");
        int h = hash(key), del_idx = -1;
        for (int i = 0; i < tableSize; i++){
            int idx = probe(h, i);
            if (table[idx].status == EMPTY){
                idx = (del_idx != -1) ? del_idx : idx;
                table[idx].key = key; table[idx].value = value; table[idx].status = OCCUPIED;
                itemCount++; return;
            }
            if (table[idx].status == OCCUPIED && table[idx].key == key){
                table[idx].value = value; return;
            }
            if (table[idx].status == DELETED && del_idx == -1) del_idx = idx;
        }
        if (del_idx != -1){
            table[del_idx].key = key; table[del_idx].value = value; table[del_idx].status = OCCUPIED;
            itemCount++;
        }
    }

    // Remove a key-value pair from the hash table
    // Throw exception if key not found
    void remove(const K& key) {
        // TODO: Implement remove function
        int h = hash(key);
        for (int i = 0; i < tableSize; i++){
            int idx = probe(h, i);
            if (table[idx].status == EMPTY) break;
            if (table[idx].status == OCCUPIED && table[idx].key == key){
                table[idx].status = DELETED; itemCount--; return;
            }
        }
        throw std::runtime_error("Key not found");
    }

    // Search for a value associated with the given key
    // Throw exception if key not found
    V search(const K& key) const {
        // TODO: Implement search function
        int h = hash(key);
        for (int i = 0; i < tableSize; i++){
            int idx = probe(h, i);
            if (table[idx].status == EMPTY) break;
            if (table[idx].status == OCCUPIED && table[idx].key == key) return table[idx].value;
        }
        throw std::runtime_error("Key not found");
    }

    // Check if the hash table contains the given key
    bool contains(const K& key) const {
        // TODO: Implement contains function
        int h = hash(key);
        for (int i = 0; i < tableSize; i++){
            int idx = probe(h, i);
            if (table[idx].status == EMPTY) break;
            if (table[idx].status == OCCUPIED && table[idx].key == key) return true;
        }
        return false;
    }

    // Return the current load factor
    float loadFactor() const {
        // TODO: Implement load factor calculation
        return (float)itemCount / tableSize;
    }

    // Return number of items in the hash table
    int size() const {
        // TODO: Implement size function
        return itemCount;
    }

    // Display the hash table (for debugging)
    void display() const {
        // TODO: Implement display function
        for (int i = 0; i < tableSize; i++){
            if (table[i].status == OCCUPIED) std::cout << "Slot " << i << ": [" << table[i].key << ":" << table[i].value << "]\n";
            else if (table[i].status == DELETED) std::cout << "Slot " << i << ": [DELETED]\n";
            else std::cout << "Slot " << i << ": [EMPTY]\n";
        }
    }
};

//-------------------- TESTING FUNCTION --------------------
void testHashTables() {
    // Test separate chaining hash table with string keys
    std::cout << "Testing Separate Chaining Hash Table with string keys:\n";
    SeparateChainingHashTable<std::string, int> scHashTable(10);
    
    // Insert some key-value pairs
    scHashTable.insert("apple", 5);
    scHashTable.insert("banana", 8);
    scHashTable.insert("cherry", 12);
    scHashTable.insert("date", 15);
    scHashTable.insert("elderberry", 20);
    scHashTable.insert("fig", 25);
    
    // Display the table
    std::cout << "After insertions:\n";
    scHashTable.display();
    
    // Search for some keys
    try {
        std::cout << "Value for 'apple': " << scHashTable.search("apple") << std::endl;
        std::cout << "Value for 'banana': " << scHashTable.search("banana") << std::endl;
        std::cout << "Value for 'grape': " << scHashTable.search("grape") << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    // Remove a key
    std::cout << "Removing 'banana'..." << std::endl;
    scHashTable.remove("banana");
    
    // Display the table again
    std::cout << "After removal:\n";
    scHashTable.display();
    
    // Test contains method
    std::cout << "Contains 'apple': " << (scHashTable.contains("apple") ? "Yes" : "No") << std::endl;
    std::cout << "Contains 'banana': " << (scHashTable.contains("banana") ? "Yes" : "No") << std::endl;
    
    // Test load factor
    std::cout << "Load factor: " << scHashTable.loadFactor() << std::endl;
    std::cout << "Size: " << scHashTable.size() << std::endl;
    
    // Test open addressing hash table with integer keys
    std::cout << "\nTesting Open Addressing Hash Table with integer keys:\n";
    OpenAddressingHashTable<int, std::string> oaHashTable(10);
    
    // Insert some key-value pairs
    oaHashTable.insert(5, "five");
    oaHashTable.insert(15, "fifteen");
    oaHashTable.insert(25, "twenty-five");
    oaHashTable.insert(35, "thirty-five");
    oaHashTable.insert(45, "forty-five");
    
    // Display the table
    std::cout << "After insertions:\n";
    oaHashTable.display();
    
    // Search for some keys
    try {
        std::cout << "Value for 5: " << oaHashTable.search(5) << std::endl;
        std::cout << "Value for 15: " << oaHashTable.search(15) << std::endl;
        std::cout << "Value for 100: " << oaHashTable.search(100) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    // Remove a key
    std::cout << "Removing 15..." << std::endl;
    oaHashTable.remove(15);
    
    // Display the table again
    std::cout << "After removal:\n";
    oaHashTable.display();
    
    // Test contains method
    std::cout << "Contains 5: " << (oaHashTable.contains(5) ? "Yes" : "No") << std::endl;
    std::cout << "Contains 15: " << (oaHashTable.contains(15) ? "Yes" : "No") << std::endl;
    
    // Test load factor
    std::cout << "Load factor: " << oaHashTable.loadFactor() << std::endl;
    std::cout << "Size: " << oaHashTable.size() << std::endl;
}

int main() {
    testHashTables();
    return 0;
}