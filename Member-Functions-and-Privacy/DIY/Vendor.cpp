// Author: Tushardeep Singh
// Seneca College Alumni

#include "./Vendor.h"

namespace seneca
{
  // Empty function, no use
  void Vendor::setEmpty()
  {
    return;
  }
  
  // Orders handled by Icecream::takeOrdersUtils
  void Vendor::takeOrders()
  {
    Icecream::takeOrdersUtils();
  }

  // Empty function, no use
  void Vendor::clearData()
  {
    return;
  }

  // Order display handled by Icecream::printOrder
  void Vendor::displayOrders()
  {
    Icecream::printOrder();
  }
}