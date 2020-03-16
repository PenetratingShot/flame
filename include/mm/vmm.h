/*
    vmm.h
    Copyright Shreyas Lad (PenetratingShot) 2020
    Virtual Memory Manager
*/

#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <mm/pmm.h>
#include <string.h>

extern uint64_t KNL_HIGH_VMA;

#define TABLESIZE 0x1000
#define PAGESIZE2 0x200000

#define HIGH_VMA 0xFFFF800000000000
#define RMFLAGS 0x000FFFFFFFFFF000
#define TABLEPRESENT (1 << 0)
#define TABLEWRITE (1 << 1)
#define TABLEUSER (1 << 2)
#define TABLEHUGE (1 << 7)

#define SUPERVISOR 0
#define USER 1

typedef struct {
    size_t pml1off;
    size_t pml2off;
    size_t pml3off;
    size_t pml4off;
} offset_t;

void setPML4(uint64_t* PML4);
void invlpg(uint64_t* vaddr);
void tlbflush();

uint64_t* getpaddr(void* vaddr);
offset_t vtoof(uint64_t* vaddr); // virtual address to offset

void vmap(uint64_t* vaddr, uint64_t* paddr, uint64_t* pml4ptr, uint64_t permission);
void vfree(uint64_t* vaddr, size_t pages);

void test();