/*
** vm.h for vm
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Mar 21 10:36:14 2016 marc brout
** Last update Mon Mar 21 10:54:52 2016 marc brout
*/

#ifndef VM_H_
# define VM_H_

typedef enum		e_vm_index
  {
    FIRST		= 0,
    LIVE		= 1,
    LD			= 2,
    ST			= 3,
    ADD			= 4,
    SUB			= 5,
    AND			= 6,
    OR			= 7,
    XOR			= 8,
    ZJUMP		= 9,
    LDI			= 10,
    STI			= 11,
    FORK		= 12,
    LLD			= 13,
    LLDI		= 14,
    LFORK		= 15,
    AFF			= 16
  }			t_vm_index;

#endif VM_H_
