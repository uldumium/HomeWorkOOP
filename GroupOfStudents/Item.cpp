#include "Item.h"

Item::Item()
{
	Item::nameItem = "N/O";
}

Item::Item( std::string nameItem )
{
	Item::nameItem = nameItem;
}

void Item::setNameItem( std::string nameItem )
{
	Item::nameItem = nameItem;
}

std::string Item::getNameItem()
{
	return Item::nameItem;
}
