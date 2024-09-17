# Purpose
Our application manages a collection of unique CPU data, allowing users to insert, delete, and search for data, along with many more features.

# Data
CPU object with the following member variables:
- CPU ID (string, primary key). Ex: "Ryzen 5 5600G"
- Release Year (int). Ex: 2021
- Core Count (int). Ex: 6
- Architecture (string). Ex: "Cezanne"
- Base Clock (double, in GHz). Ex: 3.90

# Hashing
We used a simple alphanumeric hash because our hash size was fairly small relative to the keys’ summed ASCII values.

```cpp
int key_to_index(const CPU &key, int size) {
    string k = key.getCpuId();
    int sum = 0;
    for (int i = 0; k[i]; i++)
        sum += k[i];
    return sum % size;
}
```

# Collision Resolution
We used Linear Probing for our collision resolution method. This method resolves collisions between synonym items by putting the second item in the nearest empty bucket after the bucket it should be put into were the first item not already in it.

One disadvantage of the Linear Probing method is that there is a maximum number of items that can be put into the hash table, which is the size of the array. One way to fix this is to rehash the array once it reaches a certain amount of items within it.

Rehashing is creating a new, larger array and putting each item from the old array into a new position in that array. This allows for more items and also has the benefit of making searching shorter since in a larger array, there will tend to be fewer collisions.
