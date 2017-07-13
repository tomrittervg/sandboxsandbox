#pragma once
#include <stdio.h>
#include <windows.h>
#include "Util.h"

typedef void(__stdcall funcptr)(void);

void AllocateRWX();
void AllocateRW();
void AllocateRX();
void AllocateX();
void AllocateR();

void AllocateRW_Then_RX();
