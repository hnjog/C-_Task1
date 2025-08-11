#pragma once

#define IsValid(a) a == nullptr
#define SafeDelete(a) if(a != nullptr) {delete a; a= nullptr;}