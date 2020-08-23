global multiply
section .text
multiply:
  mov eax, edi
  imul esi
  ret
