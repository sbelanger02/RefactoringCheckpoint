#include "GildedRose.h"
#include <map>
#include <string.h>

using namespace std;

GildedRose::GildedRose(vector<Item> & items) : items(items)
{}

const string GildedRose::_Brie("Aged Brie");
const string GildedRose::_Backstage("Backstage passes to a TAFKAL80ETC concert");
const string GildedRose::_Sulfuras("Sulfuras, Hand of Ragnaros");

void GildedRose::updateProperties()
{
    for (int i = 0; i < items.size(); i++)
    {
        decreaseSellIn(items[i]);
        updateQualityOfItem(items[i]);
    }
}

void GildedRose::updateQualityOfItem(Item& item)
{
    typedef void (GildedRose::*FuncPtr)(Item&);
    map<string, FuncPtr> itemTypeMapper;
    itemTypeMapper.insert(make_pair(_Brie, &GildedRose::updateBrie));
    itemTypeMapper.insert(make_pair(_Backstage, &GildedRose::updateBackstage));
    itemTypeMapper.insert(make_pair(_Sulfuras, &GildedRose::updateSulfuras));
    map<string, FuncPtr>::const_iterator typeFinder = itemTypeMapper.find(item.name);

    if (typeFinder != itemTypeMapper.end())
    {
        FuncPtr funcPtr = typeFinder->second;
        (this->*funcPtr)(item);
    }
    else
    {
        defaultUpdate(item);
    }
}

void GildedRose::defaultUpdate(Item& item)
{
    decreaseQuality(item);
    if (item.sellIn < 0)
    {
        increaseQuality(item);
    }
}

void GildedRose::updateSulfuras(Item& item)
{
    (void)0;
}

void GildedRose::increaseQuality(Item& item)
{
    if (item.quality < 50)
    {
        item.quality = item.quality + 1;
    }
}

void GildedRose::decreaseQuality(Item& item)
{
    if (item.quality < 0)
    {
        item.quality = item.quality - 1;
    }
}

void decreaseSellIn(Item& item)
{
    if (item.name != _Sulfuras)
    {
        item.sellIn = item.sellIn - 1;
    }
}

/*void GildedRose::updateQuality() 
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i].name != "Aged Brie" && items[i].name != "Backstage passes to a TAFKAL80ETC concert")
        {
            if (items[i].quality > 0)
            {
                if (items[i].name != "Sulfuras, Hand of Ragnaros")
                {
                    items[i].quality = items[i].quality - 1;
                }
            }
        }
        else
        {
            if (items[i].quality < 50)
            {
                items[i].quality = items[i].quality + 1;

                if (items[i].name == "Backstage passes to a TAFKAL80ETC concert")
                {
                    if (items[i].sellIn < 11)
                    {
                        if (items[i].quality < 50)
                        {
                            items[i].quality = items[i].quality + 1;
                        }
                    }

                    if (items[i].sellIn < 6)
                    {
                        if (items[i].quality < 50)
                        {
                            items[i].quality = items[i].quality + 1;
                        }
                    }
                }
            }
        }

        if (items[i].name != "Sulfuras, Hand of Ragnaros")
        {
            items[i].sellIn = items[i].sellIn - 1;
        }

        if (items[i].sellIn < 0)
        {
            if (items[i].name != "Aged Brie")
            {
                if (items[i].name != "Backstage passes to a TAFKAL80ETC concert")
                {
                    if (items[i].quality > 0)
                    {
                        if (items[i].name != "Sulfuras, Hand of Ragnaros")
                        {
                            items[i].quality = items[i].quality - 1;
                        }
                    }
                }
                else
                {
                    items[i].quality = items[i].quality - items[i].quality;
                }
            }
            else
            {
                if (items[i].quality < 50)
                {
                    items[i].quality = items[i].quality + 1;
                }
            }
        }
    }
} */