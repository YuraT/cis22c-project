#ifndef INC_08_TEAM_PROJECT_HASHNODE_H
#define INC_08_TEAM_PROJECT_HASHNODE_H

template <typename T>
class HashNode
{
private:
    T item;
    int occupied; // 1 -> occupied, 0 -> empty from start, -1 -> empty after removal
    int numCollisions;

public:
    // constructors
    HashNode()
    {
        occupied = 0;
        numCollisions = 0;
    }
    HashNode(T anItem)
    {
        item = anItem;
        occupied = 1;
        numCollisions = 0;
    }
    HashNode(T anItem, int ocp, int nCol)
    {
        item = anItem;
        occupied = ocp;
        numCollisions = nCol;
    }
    // setters
    void setItem(const T &anItem) { item = anItem; }
    void setOccupied(int ocp) { occupied = ocp; }
    void setNumCollisions(int nCol) { numCollisions = nCol; }

    // getters
    T getItem() const { return item; }
    int getOccupied() const { return occupied; }
    int getNumCollisions() const { return numCollisions; }
};

#endif // INC_08_TEAM_PROJECT_HASHNODE_H
