#include <string>
#include <vector>

using namespace std;

class Item
{
public:
    string name;
    int sellIn;
    int quality;
    Item(string name, int sellIn, int quality) : name(name), sellIn(sellIn), quality(quality) 
    {}
};

class GildedRose
{
    static const string _Brie;
    static const string _Backstage;
    static const string _Sulfuras;

public:
    vector<Item> & items;
    GildedRose(vector<Item> & items);
    void updateProperties();
private:
    void decreaseQuality(Item& item);
    void decreaseSellIn(Item& item);
    void increaseQuality(Item& item);
    void updateQualityOfItem(Item& item);
    void updateBrie(Item& item);
    void updateBackstage(Item& item);
    void updateSulfuras(Item& item);
    void defaultUpdate(Item& item);
    
};


