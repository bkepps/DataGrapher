;;; Segment .text (6C941000)

;; fn6CA1E7F0: 6CA1E7F0
;;   Called from:
;;     6CA1E89E (in fn6CA1E892)
fn6CA1E7F0 proc
	push	ebp
	mov	ebp,esp
	push	ebx
	sub	esp,24
	mov	eax,[6CA4FA34]
	mov	ebx,[ebp+08]
	mov	[esp],eax
	call	6CA1EAEC
	mov	[ebp-10],eax
	inc	eax
	jnz	6CA1E81A

l6CA1E80D:
	mov	[esp],ebx
	call	dword ptr [6CA557C0]
	mov	ebx,eax
	jmp	6CA1E88A

l6CA1E81A:
	mov	dword ptr [esp],00000008
	call	6CA1F668
	mov	eax,[6CA4FA34]
	mov	[esp],eax
	call	6CA1EAEC
	mov	[ebp-10],eax
	mov	eax,[6CA4FA30]
	mov	[esp],eax
	call	6CA1EAEC
	mov	[esp],ebx
	mov	[ebp-0C],eax
	lea	eax,[ebp-0C]
	mov	[esp+08],eax
	lea	eax,[ebp-10]
	mov	[esp+04],eax
	call	6CA1F680
	mov	ebx,eax
	mov	eax,[ebp-10]
	mov	[esp],eax
	call	6CA1EAF4
	mov	[6CA4FA34],eax
	mov	eax,[ebp-0C]
	mov	[esp],eax
	call	6CA1EAF4
	mov	dword ptr [esp],00000008
	mov	[6CA4FA30],eax
	call	6CA1F660

l6CA1E88A:
	add	esp,24
	mov	eax,ebx
	pop	ebx
	pop	ebp
	ret

;; fn6CA1E892: 6CA1E892
;;   Called from:
;;     6CA1E912 (in fn6CA1E8D8)
fn6CA1E892 proc
	push	ebp
	mov	ebp,esp
	sub	esp,18
	mov	eax,[ebp+08]
	mov	[esp],eax
	call	6CA1E7F0
	leave
	test	eax,eax
	setz	al
	movzx	eax,al
	neg	eax
	ret
6CA1E8AF                                              90                .
6CA1E8B0 A1 60 30 A2 6C 8B 00 85 C0 75 01 C3 55 89 E5 83 .`0.l....u..U...
6CA1E8C0 EC 08 FF D0 83 05 60 30 A2 6C 04 A1 60 30 A2 6C ......`0.l..`0.l
6CA1E8D0 8B 00 85 C0 75 EC C9 C3                         ....u...       

;; fn6CA1E8D8: 6CA1E8D8
;;   Called from:
;;     6CA1E930 (in fn6CA1E91D)
fn6CA1E8D8 proc
	push	ebp
	mov	ebp,esp
	push	ebx
	sub	esp,14
	mov	ebx,[6CA1F720]
	cmp	ebx,FF
	jnz	6CA1E8FD

l6CA1E8EA:
	xor	ebx,ebx

l6CA1E8EC:
	lea	eax,[ebx+01]
	cmp	dword ptr [6CA1F720+eax*4],00
	jz	6CA1E8FD

l6CA1E8F9:
	mov	ebx,eax
	jmp	6CA1E8EC

l6CA1E8FD:
	test	ebx,ebx
	jz	6CA1E90B

l6CA1E901:
	call	dword ptr [6CA1F720+ebx*4]
	dec	ebx
	jmp	6CA1E8FD

l6CA1E90B:
	mov	dword ptr [esp],6CA1E8B0
	call	6CA1E892
	add	esp,14
	pop	ebx
	pop	ebp
	ret

;; fn6CA1E91D: 6CA1E91D
;;   Called from:
;;     6C941279 (in fn6C9411E9)
fn6CA1E91D proc
	cmp	dword ptr [6CA4F698],00
	jnz	6CA1E932

l6CA1E926:
	mov	dword ptr [6CA4F698],00000001
	jmp	6CA1E8D8

l6CA1E932:
	ret
6CA1E933          90                                        .           

;; fn6CA1E934: 6CA1E934
;;   Called from:
;;     6C941348 (in DllMain)
fn6CA1E934 proc
	push	ebp
	mov	ebp,esp
	push	edi
	push	esi
	push	ebx
	sub	esp,3C
	mov	eax,[6CA23070]
	mov	dword ptr [ebp-28],00000000
	mov	dword ptr [ebp-24],00000000
	cmp	eax,BB40E64E
	jz	6CA1E960

l6CA1E957:
	not	eax
	mov	[6CA23074],eax
	jmp	6CA1E9C5

l6CA1E960:
	lea	eax,[ebp-28]
	mov	[esp],eax
	call	dword ptr [6CA556D8]
	mov	edx,[ebp-28]
	xor	edx,[ebp-24]
	mov	[ebp-2C],edx
	push	eax
	call	dword ptr [6CA556A4]
	mov	edi,eax
	call	dword ptr [6CA556AC]
	mov	esi,eax
	call	dword ptr [6CA556DC]
	mov	ebx,eax
	lea	eax,[ebp-20]
	mov	[esp],eax
	call	dword ptr [6CA55720]
	push	edx
	mov	edx,[ebp-2C]
	xor	edx,[ebp-20]
	xor	edx,[ebp-1C]
	xor	edi,edx
	xor	esi,edi
	xor	esi,ebx
	cmp	esi,BB40E64E
	jnz	6CA1E9B7

l6CA1E9B2:
	mov	esi,BB40E64F

l6CA1E9B7:
	mov	[6CA23070],esi
	not	esi
	mov	[6CA23074],esi

l6CA1E9C5:
	lea	esp,[ebp-0C]
	pop	ebx
	pop	esi
	pop	edi
	pop	ebp
	ret
6CA1E9CD                                        55 89 E5              U..
6CA1E9D0 83 EC 28 C7 05 80 F9 A4 6C 09 04 00 C0 8B 45 04 ..(.....l.....E.
6CA1E9E0 8D 55 04 C7 05 84 F9 A4 6C 01 00 00 00 89 15 64 .U......l......d
6CA1E9F0 F7 A4 6C A3 58 F7 A4 6C A3 8C F9 A4 6C 8B 45 08 ..l.X..l....l.E.
6CA1EA00 C7 04 24 00 00 00 00 A3 4C F7 A4 6C A1 70 30 A2 ..$.....L..l.p0.
6CA1EA10 6C 89 45 F0 A1 74 30 A2 6C 89 45 F4 FF 15 50 57 l.E..t0.l.E...PW
6CA1EA20 A5 6C 50 C7 04 24 A8 A6 A4 6C FF 15 6C 57 A5 6C .lP..$...l..lW.l
6CA1EA30 52 FF 15 A0 56 A5 6C 89 04 24 C7 44 24 04 09 04 R...V.l..$.D$...
6CA1EA40 00 C0 FF 15 58 57 A5 6C 51 51 E8 09 0C 00 00 90 ....XW.lQQ......
6CA1EA50 55 89 E5 83 EC 18 8B 45 0C 83 F8 03 74 04 85 C0 U......E....t...
6CA1EA60 75 16 8B 55 10 89 44 24 04 8B 45 08 89 54 24 08 u..U..D$..E..T$.
6CA1EA70 89 04 24 E8 1E 05 00 00 C9 B8 01 00 00 00 C2 0C ..$.............
6CA1EA80 00                                              .              

;; fn6CA1EA81: 6CA1EA81
;;   Called from:
;;     6C9411D0 (in fn6C94103E)
fn6CA1EA81 proc
	push	ebp
	mov	ebp,esp
	push	ebx
	sub	esp,14
	cmp	dword ptr [6CA2306C],02
	mov	eax,[ebp+0C]
	jz	6CA1EA9E

l6CA1EA94:
	mov	dword ptr [6CA2306C],00000002

l6CA1EA9E:
	cmp	eax,02
	jz	6CA1EAC2

l6CA1EAA3:
	dec	eax
	jnz	6CA1EADC

l6CA1EAA6:
	mov	eax,[ebp+10]
	mov	dword ptr [esp+04],00000001
	mov	[esp+08],eax
	mov	eax,[ebp+08]
	mov	[esp],eax
	call	6CA1EF96
	jmp	6CA1EADC

l6CA1EAC2:
	mov	ebx,6CA58028

l6CA1EAC7:
	cmp	ebx,6CA58028
	jz	6CA1EADC

l6CA1EACF:
	mov	eax,[ebx]
	test	eax,eax
	jz	6CA1EAD7

l6CA1EAD5:
	call	eax

l6CA1EAD7:
	add	ebx,04
	jmp	6CA1EAC7

l6CA1EADC:
	add	esp,14
	mov	eax,00000001
	pop	ebx
	pop	ebp
	ret	000C
6CA1EAE9                            31 C0 C3                      1..   

;; fn6CA1EAEC: 6CA1EAEC
;;   Called from:
;;     6C9410AC (in fn6C94103E)
;;     6C9410BF (in fn6C94103E)
;;     6CA1E802 (in fn6CA1E7F0)
;;     6CA1E82E (in fn6CA1E7F0)
;;     6CA1E83E (in fn6CA1E7F0)
fn6CA1EAEC proc
	push	ebp
	mov	ebp,esp
	mov	eax,[ebp+08]
	pop	ebp
	ret

;; fn6CA1EAF4: 6CA1EAF4
;;   Called from:
;;     6CA1E864 (in fn6CA1E7F0)
;;     6CA1E874 (in fn6CA1E7F0)
fn6CA1EAF4 proc
	push	ebp
	mov	ebp,esp
	mov	eax,[ebp+08]
	pop	ebp
	ret

;; fn6CA1EAFC: 6CA1EAFC
;;   Called from:
;;     6CA1EBF5 (in fn6CA1EB3E)
;;     6CA1EC50 (in fn6CA1EB3E)
;;     6CA1EDC3 (in fn6CA1EC63)
fn6CA1EAFC proc
	push	ebp
	mov	ebp,esp
	push	ebx
	lea	ebx,[ebp+0C]
	sub	esp,14
	mov	eax,[6CA557B8]
	mov	dword ptr [esp],6CA4A6B4
	add	eax,40
	mov	[esp+04],eax
	call	6CA1F648
	mov	eax,[ebp+08]
	mov	[esp+08],ebx
	mov	[esp+04],eax
	mov	eax,[6CA557B8]
	add	eax,40
	mov	[esp],eax
	call	6CA1F610
	call	6CA1F658

;; fn6CA1EB3E: 6CA1EB3E
;;   Called from:
;;     6CA1EB39 (in fn6CA1EAFC)
;;     6CA1ED15 (in fn6CA1EC63)
;;     6CA1ED6F (in fn6CA1EC63)
;;     6CA1EDF3 (in fn6CA1EC63)
;;     6CA1EE04 (in fn6CA1EC63)
fn6CA1EB3E proc
	push	ebp
	mov	ebp,esp
	push	edi
	push	esi
	push	ebx
	xor	ebx,ebx
	sub	esp,3C
	mov	ecx,[6CA4F9FC]
	mov	esi,[6CA4F9F8]
	lea	edx,[ecx+0C]

l6CA1EB58:
	cmp	esi,ebx
	jle	6CA1EB76

l6CA1EB5C:
	mov	ecx,[edx]
	cmp	ecx,eax
	ja	6CA1EB70

l6CA1EB62:
	mov	edi,[edx+04]
	add	ecx,[edi+08]
	cmp	eax,ecx
	jc	6CA1EC5B

l6CA1EB70:
	inc	ebx
	add	edx,14
	jmp	6CA1EB58

l6CA1EB76:
	mov	[esp],eax
	mov	esi,eax
	call	6CA1F130
	mov	edi,eax
	test	eax,eax
	jnz	6CA1EB96

l6CA1EB86:
	mov	[esp+04],esi
	mov	dword ptr [esp],6CA4A6D0
	jmp	6CA1EC50

l6CA1EB96:
	imul	ebx,ebx,14
	mov	eax,[6CA4F9FC]
	add	eax,ebx
	mov	[eax+10],edi
	mov	dword ptr [eax],00000000
	call	6CA1F1E2
	mov	edx,[6CA4F9FC]
	add	eax,[edi+0C]
	mov	[edx+ebx+0C],eax
	lea	edx,[ebp-34]
	mov	dword ptr [esp+08],0000001C
	mov	[esp+04],edx
	mov	[esp],eax
	call	dword ptr [6CA55784]
	sub	esp,0C
	test	eax,eax
	jnz	6CA1EBFA

l6CA1EBDA:
	mov	eax,[6CA4F9FC]
	mov	eax,[eax+ebx+0C]
	mov	[esp+08],eax
	mov	eax,[edi+08]
	mov	dword ptr [esp],6CA4A6F0
	mov	[esp+04],eax
	call	6CA1EAFC

l6CA1EBFA:
	mov	eax,[ebp-20]
	lea	edx,[eax-40]
	and	edx,BF
	jz	6CA1EC55

l6CA1EC05:
	sub	eax,04
	and	eax,FB
	jz	6CA1EC55

l6CA1EC0D:
	mov	eax,[ebp-34]
	mov	edx,[ebp-28]
	add	ebx,[6CA4F9FC]
	mov	[ebx+04],eax
	mov	[ebx+08],edx
	mov	[esp+0C],ebx
	mov	dword ptr [esp+08],00000040
	mov	[esp+04],edx
	mov	[esp],eax
	call	dword ptr [6CA55780]
	sub	esp,10
	test	eax,eax
	jnz	6CA1EC55

l6CA1EC3F:
	call	dword ptr [6CA556B8]
	mov	dword ptr [esp],6CA4A721
	mov	[esp+04],eax

l6CA1EC50:
	call	6CA1EAFC

l6CA1EC55:
	inc	dword ptr [6CA4F9F8]

l6CA1EC5B:
	lea	esp,[ebp-0C]
	pop	ebx
	pop	esi
	pop	edi
	pop	ebp
	ret

;; fn6CA1EC63: 6CA1EC63
;;   Called from:
;;     6C94120C (in fn6C9411E9)
fn6CA1EC63 proc
	push	ebp
	mov	ebp,esp
	push	edi
	push	esi
	push	ebx
	sub	esp,3C
	mov	eax,[6CA4F9F4]
	mov	[ebp-2C],eax
	test	eax,eax
	jnz	6CA1EE53

l6CA1EC7C:
	mov	dword ptr [6CA4F9F4],00000001
	call	6CA1F164
	imul	eax,eax,14
	add	eax,1B
	shr	eax,04
	shl	eax,04
	call	6CA1F2C4
	mov	dword ptr [6CA4F9F8],00000000
	sub	esp,eax
	lea	eax,[esp+1F]
	and	eax,F0
	mov	[6CA4F9FC],eax
	mov	eax,6CA4C6EC
	sub	eax,6CA4C6EC
	cmp	eax,07
	jle	6CA1EE53

l6CA1ECC7:
	mov	ebx,6CA4C6EC
	cmp	eax,0B
	jle	6CA1ECEA

l6CA1ECD1:
	mov	eax,[6CA4C6F0]
	or	eax,[6CA4C6EC]
	or	eax,[6CA4C6F4]
	mov	eax,6CA4C6F8
	cmovz	ebx,eax

l6CA1ECEA:
	cmp	dword ptr [ebx],00
	jnz	6CA1ECF5

l6CA1ECEF:
	cmp	dword ptr [ebx+04],00
	jz	6CA1ED22

l6CA1ECF5:
	cmp	ebx,6CA4C6EC
	jnc	6CA1EE48

l6CA1ED01:
	mov	esi,[ebx+04]
	mov	edi,[ebx]
	add	ebx,08
	add	edi,[esi+6C940000]
	lea	eax,[esi+6C940000]
	call	6CA1EB3E
	mov	[esi+6C940000],edi
	jmp	6CA1ECF5

l6CA1ED22:
	mov	eax,[ebx+08]
	add	ebx,0C
	cmp	eax,01
	jz	6CA1ED7F

l6CA1ED2D:
	mov	[esp+04],eax
	mov	dword ptr [esp],6CA4A748
	jmp	6CA1EDC3

l6CA1ED3D:
	cmp	byte ptr [edi+6C940000],00
	movzx	esi,byte ptr [edi+6C940000]
	jns	6CA1ED53

l6CA1ED4D:
	or	esi,FFFFFF00

l6CA1ED53:
	sub	esi,[ebp-30]
	add	esi,ecx
	cmp	edx,10
	jz	6CA1EDF3

l6CA1ED61:
	cmp	edx,20
	jz	6CA1EE04

l6CA1ED6A:
	cmp	edx,08
	jnz	6CA1ED7C

l6CA1ED6F:
	call	6CA1EB3E
	mov	eax,esi
	mov	[edi+6C940000],al

l6CA1ED7C:
	add	ebx,0C

l6CA1ED7F:
	cmp	ebx,6CA4C6EC
	jnc	6CA1EE48

l6CA1ED8B:
	mov	edx,[ebx]
	mov	edi,[ebx+04]
	lea	ecx,[edx+6C940000]
	lea	eax,[edi+6C940000]
	mov	[ebp-30],ecx
	mov	ecx,[edx+6C940000]
	movzx	edx,byte ptr [ebx+08]
	cmp	edx,10
	jz	6CA1EDC8

l6CA1EDAE:
	cmp	edx,20
	jz	6CA1EDE8

l6CA1EDB3:
	cmp	edx,08
	jz	6CA1ED3D

l6CA1EDB8:
	mov	[esp+04],edx
	mov	dword ptr [esp],6CA4A77A

l6CA1EDC3:
	call	6CA1EAFC

l6CA1EDC8:
	cmp	word ptr [edi+6C940000],00
	movzx	esi,word ptr [edi+6C940000]
	jns	6CA1ED53

l6CA1EDDD:
	or	esi,FFFF0000
	jmp	6CA1ED53

l6CA1EDE8:
	mov	esi,[edi+6C940000]
	jmp	6CA1ED53

l6CA1EDF3:
	call	6CA1EB3E
	mov	[edi+6C940000],si
	jmp	6CA1ED7C

l6CA1EE04:
	call	6CA1EB3E
	mov	[edi+6C940000],esi
	jmp	6CA1ED7C

l6CA1EE14:
	imul	eax,[ebp-2C],14
	add	eax,[6CA4F9FC]
	mov	edx,[eax]
	test	edx,edx
	jz	6CA1EE45

l6CA1EE24:
	lea	ecx,[ebp-1C]
	mov	[esp+08],edx
	mov	[esp+0C],ecx
	mov	edx,[eax+08]
	mov	[esp+04],edx
	mov	eax,[eax+04]
	mov	[esp],eax
	call	dword ptr [6CA55780]
	sub	esp,10

l6CA1EE45:
	inc	dword ptr [ebp-2C]

l6CA1EE48:
	mov	eax,[ebp-2C]
	cmp	eax,[6CA4F9F8]
	jl	6CA1EE14

l6CA1EE53:
	lea	esp,[ebp-0C]
	pop	ebx
	pop	esi
	pop	edi
	pop	ebp
	ret
6CA1EE5B                                  90                        .   

;; fn6CA1EE5C: 6CA1EE5C
;;   Called from:
;;     6CA1EFEC (in fn6CA1EF96)
;;     6CA1F045 (in fn6CA1EF96)
fn6CA1EE5C proc
	push	ebp
	mov	ebp,esp
	push	esi
	push	ebx
	sub	esp,10
	mov	dword ptr [esp],6CA4FA08
	call	dword ptr [6CA5568C]
	mov	ebx,[6CA4FA00]
	push	ecx

l6CA1EE78:
	test	ebx,ebx
	jz	6CA1EEA5

l6CA1EE7C:
	mov	eax,[ebx]
	mov	[esp],eax
	call	dword ptr [6CA55760]
	mov	esi,eax
	push	edx
	call	dword ptr [6CA556B8]
	test	eax,eax
	jnz	6CA1EEA0

l6CA1EE94:
	test	esi,esi
	jz	6CA1EEA0

l6CA1EE98:
	mov	eax,[ebx+04]
	mov	[esp],esi
	call	eax

l6CA1EEA0:
	mov	ebx,[ebx+08]
	jmp	6CA1EE78

l6CA1EEA5:
	mov	dword ptr [esp],6CA4FA08
	call	dword ptr [6CA55700]
	push	eax
	lea	esp,[ebp-08]
	pop	ebx
	pop	esi
	pop	ebp
	ret
6CA1EEBA                               55 89 E5 56 31 F6           U..V1.
6CA1EEC0 53 83 EC 10 A1 04 FA A4 6C 85 C0 74 54 C7 44 24 S.......l..tT.D$
6CA1EED0 04 0C 00 00 00 C7 04 24 01 00 00 00 E8 6F 07 00 .......$.....o..
6CA1EEE0 00 89 C3 85 C0 74 37 8B 45 08 C7 04 24 08 FA A4 .....t7.E...$...
6CA1EEF0 6C 89 03 8B 45 0C 89 43 04 FF 15 8C 56 A5 6C 50 l...E..C....V.lP
6CA1EF00 A1 00 FA A4 6C 89 1D 00 FA A4 6C 89 43 08 C7 04 ....l.....l.C...
6CA1EF10 24 08 FA A4 6C FF 15 00 57 A5 6C 52 EB 03 83 CE $...l...W.lR....
6CA1EF20 FF 8D 65 F8 89 F0 5B 5E 5D C3 A1 04 FA A4 6C 85 ..e...[^].....l.
6CA1EF30 C0 74 60 55 89 E5 83 EC 18 C7 04 24 08 FA A4 6C .t`U.......$...l
6CA1EF40 FF 15 8C 56 A5 6C A1 00 FA A4 6C 52 31 D2 85 C0 ...V.l....lR1...
6CA1EF50 74 2F 8B 08 3B 4D 08 75 1F 85 D2 75 0B 8B 50 08 t/..;M.u...u..P.
6CA1EF60 89 15 00 FA A4 6C EB 06 8B 48 08 89 4A 08 89 04 .....l...H..J...
6CA1EF70 24 E8 CA 06 00 00 EB 09 8B 48 08 89 C2 89 C8 EB $........H......
6CA1EF80 CD C7 04 24 08 FA A4 6C FF 15 00 57 A5 6C 50 31 ...$...l...W.lP1
6CA1EF90 C0 C9 C3 31 C0 C3                               ...1..         

;; fn6CA1EF96: 6CA1EF96
;;   Called from:
;;     6CA1EABB (in fn6CA1EA81)
fn6CA1EF96 proc
	push	ebp
	mov	ebp,esp
	push	ebx
	sub	esp,14
	mov	eax,[ebp+0C]
	cmp	eax,01
	jz	6CA1EFC0

l6CA1EFA5:
	test	eax,eax
	jz	6CA1EFE3

l6CA1EFA9:
	cmp	eax,02
	jz	6CA1F035

l6CA1EFB2:
	cmp	eax,03
	jz	6CA1F03C

l6CA1EFBB:
	jmp	6CA1F04A

l6CA1EFC0:
	mov	eax,[6CA4FA04]
	test	eax,eax
	jnz	6CA1EFD7

l6CA1EFC9:
	mov	dword ptr [esp],6CA4FA08
	call	dword ptr [6CA556F4]
	push	edx

l6CA1EFD7:
	mov	dword ptr [6CA4FA04],00000001
	jmp	6CA1F04A

l6CA1EFE3:
	mov	eax,[6CA4FA04]
	test	eax,eax
	jz	6CA1EFF1

l6CA1EFEC:
	call	6CA1EE5C

l6CA1EFF1:
	mov	eax,[6CA4FA04]
	dec	eax
	mov	eax,[6CA4FA00]
	jnz	6CA1F04A

l6CA1EFFE:
	test	eax,eax
	jz	6CA1F011

l6CA1F002:
	mov	ebx,[eax+08]
	mov	[esp],eax
	call	6CA1F640
	mov	eax,ebx
	jmp	6CA1EFFE

l6CA1F011:
	mov	dword ptr [6CA4FA00],00000000
	mov	dword ptr [6CA4FA04],00000000
	mov	dword ptr [esp],6CA4FA08
	call	dword ptr [6CA55684]
	push	eax
	jmp	6CA1F04A

l6CA1F035:
	call	6CA1F2C0
	jmp	6CA1F04A

l6CA1F03C:
	mov	eax,[6CA4FA04]
	test	eax,eax
	jz	6CA1F04A

l6CA1F045:
	call	6CA1EE5C

l6CA1F04A:
	mov	eax,00000001
	mov	ebx,[ebp-04]
	leave
	ret

;; fn6CA1F054: 6CA1F054
;;   Called from:
;;     6CA1F13D (in fn6CA1F130)
;;     6CA1F171 (in fn6CA1F164)
;;     6CA1F1EF (in fn6CA1F1E2)
fn6CA1F054 proc
	push	ebp
	xor	eax,eax
	mov	ebp,esp
	mov	edx,[ebp+08]
	cmp	word ptr [edx],5A4D
	jnz	6CA1F079

l6CA1F063:
	add	edx,[edx+3C]
	cmp	dword ptr [edx],00004550
	jnz	6CA1F079

l6CA1F06E:
	xor	eax,eax
	cmp	word ptr [edx+18],010B
	setz	al

l6CA1F079:
	pop	ebp
	ret

;; fn6CA1F07B: 6CA1F07B
;;   Called from:
;;     6CA1F15D (in fn6CA1F130)
fn6CA1F07B proc
	push	ebp
	mov	ebp,esp
	push	esi
	mov	edx,[ebp+08]
	mov	ecx,[ebp+0C]
	push	ebx
	xor	ebx,ebx
	add	edx,[edx+3C]
	movzx	eax,word ptr [edx+14]
	movzx	esi,word ptr [edx+06]
	lea	eax,[edx+eax+18]

l6CA1F097:
	cmp	esi,ebx
	jbe	6CA1F0AF

l6CA1F09B:
	mov	edx,[eax+0C]
	cmp	edx,ecx
	ja	6CA1F0A9

l6CA1F0A2:
	add	edx,[eax+08]
	cmp	edx,ecx
	ja	6CA1F0B1

l6CA1F0A9:
	inc	ebx
	add	eax,28
	jmp	6CA1F097

l6CA1F0AF:
	xor	eax,eax

l6CA1F0B1:
	pop	ebx
	pop	esi
	pop	ebp
	ret
6CA1F0B5                55 31 C0 83 C9 FF 89 E5 57 56 53      U1......WVS
6CA1F0C0 31 DB 83 EC 1C 8B 7D 08 F2 AE 89 C8 F7 D0 48 83 1.....}.......H.
6CA1F0D0 F8 08 77 52 C7 04 24 00 00 94 6C E8 74 FF FF FF ..wR..$...l.t...
6CA1F0E0 85 C0 74 42 A1 3C 00 94 6C 31 FF 0F B7 90 14 00 ..tB.<..l1......
6CA1F0F0 94 6C 05 00 00 94 6C 0F B7 70 06 8D 5C 10 18 39 .l....l..p..\..9
6CA1F100 FE 76 21 8B 45 08 C7 44 24 08 08 00 00 00 89 1C .v!.E..D$.......
6CA1F110 24 89 44 24 04 E8 FE 04 00 00 85 C0 74 08 47 83 $.D$........t.G.
6CA1F120 C3 28 EB DB 31 DB 83 C4 1C 89 D8 5B 5E 5F 5D C3 .(..1......[^_].

;; fn6CA1F130: 6CA1F130
;;   Called from:
;;     6CA1EB7B (in fn6CA1EB3E)
fn6CA1F130 proc
	push	ebp
	mov	ebp,esp
	sub	esp,18
	mov	dword ptr [esp],6C940000
	call	6CA1F054
	mov	edx,eax
	xor	eax,eax
	test	edx,edx
	jz	6CA1F162

l6CA1F14A:
	mov	eax,[ebp+08]
	mov	dword ptr [esp],6C940000
	sub	eax,6C940000
	mov	[esp+04],eax
	call	6CA1F07B

l6CA1F162:
	leave
	ret

;; fn6CA1F164: 6CA1F164
;;   Called from:
;;     6CA1EC86 (in fn6CA1EC63)
fn6CA1F164 proc
	push	ebp
	mov	ebp,esp
	sub	esp,18
	mov	dword ptr [esp],6C940000
	call	6CA1F054
	xor	edx,edx
	test	eax,eax
	jz	6CA1F188

l6CA1F17C:
	mov	eax,[6C94003C]
	movzx	edx,word ptr [eax+6C940006]

l6CA1F188:
	leave
	mov	eax,edx
	ret
6CA1F18C                                     55 89 E5 53             U..S
6CA1F190 83 EC 14 8B 4D 08 C7 04 24 00 00 94 6C E8 B2 FE ....M...$...l...
6CA1F1A0 FF FF 31 D2 85 C0 74 32 A1 3C 00 94 6C 0F B7 90 ..1...t2.<..l...
6CA1F1B0 14 00 94 6C 05 00 00 94 6C 0F B7 58 06 8D 54 10 ...l....l..X..T.
6CA1F1C0 18 31 C0 39 C3 76 11 F6 42 27 20 74 05 85 C9 74 .1.9.v..B' t...t
6CA1F1D0 09 49 40 83 C2 28 EB EB 31 D2 83 C4 14 89 D0 5B .I@..(..1......[
6CA1F1E0 5D C3                                           ].             

;; fn6CA1F1E2: 6CA1F1E2
;;   Called from:
;;     6CA1EBA9 (in fn6CA1EB3E)
fn6CA1F1E2 proc
	push	ebp
	mov	ebp,esp
	sub	esp,18
	mov	dword ptr [esp],6C940000
	call	6CA1F054
	mov	edx,00000000
	leave
	test	eax,eax
	mov	eax,6C940000
	cmovz	eax,edx

l6CA1F204:
	ret
6CA1F205                55 89 E5 83 EC 18 C7 04 24 00 00      U.......$..
6CA1F210 94 6C E8 3D FE FF FF 85 C0 74 28 8B 45 08 C7 04 .l.=.....t(.E...
6CA1F220 24 00 00 94 6C 2D 00 00 94 6C 89 44 24 04 E8 48 $...l-...l.D$..H
6CA1F230 FE FF FF 89 C2 31 C0 85 D2 74 08 8B 42 24 F7 D0 .....1...t..B$..
6CA1F240 C1 E8 1F C9 C3 55 89 E5 56 53 83 EC 10 8B 75 08 .....U..VS....u.
6CA1F250 C7 04 24 00 00 94 6C E8 F8 FD FF FF 31 C9 85 C0 ..$...l.....1...
6CA1F260 74 52 A1 3C 00 94 6C 8B 98 80 00 94 6C 85 DB 74 tR.<..l.....l..t
6CA1F270 43 89 5C 24 04 C7 04 24 00 00 94 6C E8 FA FD FF C.\$...$...l....
6CA1F280 FF 31 C9 85 C0 74 2D 81 C3 00 00 94 6C 89 DA 74 .1...t-.....l..t
6CA1F290 23 83 7A 04 00 75 06 83 7A 0C 00 74 15 85 F6 7F #.z..u..z..t....
6CA1F2A0 0B 8B 4A 0C 81 C1 00 00 94 6C EB 08 4E 83 C2 14 ..J......l..N...
6CA1F2B0 EB DF 31 C9 83 C4 10 89 C8 5B 5E 5D C3 90 90 90 ..1......[^]....

;; fn6CA1F2C0: 6CA1F2C0
;;   Called from:
;;     6CA1F035 (in fn6CA1EF96)
fn6CA1F2C0 proc
	fninit
	ret
6CA1F2C3          90                                        .           

;; fn6CA1F2C4: 6CA1F2C4
;;   Called from:
;;     6CA1EC97 (in fn6CA1EC63)
fn6CA1F2C4 proc
	push	ecx
	push	eax
	cmp	eax,00001000
	lea	ecx,[esp+0C]
	jc	6CA1F2E6

l6CA1F2D1:
	sub	ecx,00001000
	or	dword ptr [ecx],00
	sub	eax,00001000
	cmp	eax,00001000
	ja	6CA1F2D1

l6CA1F2E6:
	sub	ecx,eax
	or	dword ptr [ecx],00
	pop	eax
	pop	ecx
	ret
6CA1F2EE                                           90 90               ..
6CA1F2F0 55 57 56 53 83 EC 1C 8B 5C 24 34 8B 4C 24 30 C7 UWVS....\$4.L$0.
6CA1F300 44 24 08 00 00 00 00 8B 44 24 38 8B 54 24 3C 89 D$......D$8.T$<.
6CA1F310 0C 24 89 DD 89 5C 24 04 85 DB 79 18 F7 D9 C7 44 .$...\$...y....D
6CA1F320 24 08 FF FF FF FF 83 D3 00 89 0C 24 F7 DB 89 5C $..........$...\
6CA1F330 24 04 89 DD 89 D3 85 D2 79 0D F7 D8 F7 54 24 08 $.......y....T$.
6CA1F340 83 D2 00 F7 DA 89 D3 89 C7 8B 04 24 85 DB 75 50 ...........$..uP
6CA1F350 39 EF 76 2C 89 EA 31 F6 F7 F7 89 C1 89 C8 8B 4C 9.v,..1........L
6CA1F360 24 08 89 F2 85 C9 74 07 F7 D8 83 D2 00 F7 DA 83 $.....t.........
6CA1F370 C4 1C 5B 5E 5F 5D C3 8D B4 26 00 00 00 00 66 90 ..[^_]...&....f.
6CA1F380 85 FF 75 0B B8 01 00 00 00 31 D2 F7 F3 89 C7 31 ..u......1.....1
6CA1F390 D2 89 E8 F7 F7 89 C6 8B 04 24 F7 F7 89 C1 EB BC .........$......
6CA1F3A0 39 EB 77 1C 0F BD F3 83 F6 1F 75 24 39 EB 72 07 9.w.......u$9.r.
6CA1F3B0 31 C9 3B 3C 24 77 A5 B9 01 00 00 00 EB 9E 66 90 1.;<$w........f.
6CA1F3C0 31 F6 31 C9 EB 96 8D B4 26 00 00 00 00 8D 76 00 1.1.....&.....v.
6CA1F3D0 B8 20 00 00 00 89 F1 89 FA 29 F0 D3 E3 89 C1 D3 . .......)......
6CA1F3E0 EA 89 F1 09 DA D3 E7 89 EB 89 C1 D3 EB 89 54 24 ..............T$
6CA1F3F0 0C 89 F1 8B 14 24 D3 E5 89 C1 D3 EA 09 D5 89 DA .....$..........
6CA1F400 89 E8 F7 74 24 0C 89 D3 89 C5 F7 E7 39 D3 72 20 ...t$.......9.r 
6CA1F410 8B 3C 24 89 F1 D3 E7 39 C7 73 04 39 D3 74 11 89 .<$....9.s.9.t..
6CA1F420 E9 31 F6 E9 34 FF FF FF 8D B4 26 00 00 00 00 90 .1..4.....&.....
6CA1F430 8D 4D FF 31 F6 E9 22 FF FF FF 90 90 90 90 90 90 .M.1..".........
6CA1F440 55 57 56 53 83 EC 2C 8B 44 24 40 8B 5C 24 44 8B UWVS..,.D$@.\$D.
6CA1F450 6C 24 4C 8B 74 24 48 89 44 24 0C 89 DA 85 ED 75 l$L.t$H.D$.....u
6CA1F460 54 39 DE 76 2B F7 F6 31 FF 89 C1 8B 6C 24 50 89 T9.v+..1....l$P.
6CA1F470 C8 85 ED 74 0D 8B 74 24 50 89 16 C7 46 04 00 00 ...t..t$P...F...
6CA1F480 00 00 83 C4 2C 89 FA 5B 5E 5F 5D C3 8D 74 26 00 ....,..[^_]..t&.
6CA1F490 89 F7 85 F6 75 0B B8 01 00 00 00 31 D2 F7 F6 89 ....u......1....
6CA1F4A0 C7 89 D8 31 D2 F7 F7 89 C3 8B 44 24 0C F7 F7 89 ...1......D$....
6CA1F4B0 DF 89 C1 EB B6 39 DD 76 27 8B 74 24 50 85 F6 0F .....9.v'.t$P...
6CA1F4C0 84 0B 01 00 00 8B 44 24 50 8B 7C 24 0C 89 58 04 ......D$P.|$..X.
6CA1F4D0 89 38 83 C4 2C 31 FF 31 C0 5B 89 FA 5E 5F 5D C3 .8..,1.1.[..^_].
6CA1F4E0 0F BD FD 83 F7 1F 75 38 39 DD 0F 82 F0 00 00 00 ......u89.......
6CA1F4F0 89 C1 31 C0 3B 74 24 0C 0F 86 E2 00 00 00 8B 5C ..1.;t$........\
6CA1F500 24 50 85 DB 0F 84 78 FF FF FF 8B 5C 24 50 89 0B $P....x....\$P..
6CA1F510 89 53 04 E9 6A FF FF FF 8D B4 26 00 00 00 00 90 .S..j.....&.....
6CA1F520 B8 20 00 00 00 89 F9 89 C2 D3 E5 89 F0 29 FA 89 . ...........)..
6CA1F530 D1 89 54 24 1C D3 E8 89 F9 D3 E6 09 C5 89 D1 89 ..T$............
6CA1F540 D8 D3 E8 89 74 24 10 89 F9 89 C6 8B 44 24 0C D3 ....t$......D$..
6CA1F550 E3 89 D1 89 F2 D3 E8 89 F9 09 C3 8B 44 24 0C D3 ............D$..
6CA1F560 E0 89 44 24 18 89 D8 F7 F5 89 D6 89 C1 89 C3 F7 ..D$............
6CA1F570 64 24 10 89 44 24 0C 89 54 24 14 39 D6 72 08 75 d$..D$..T$.9.r.u
6CA1F580 17 39 44 24 18 73 11 2B 44 24 10 19 EA 89 54 24 .9D$.s.+D$....T$
6CA1F590 14 8D 59 FF 89 44 24 0C 8B 54 24 50 89 D8 85 D2 ..Y..D$..T$P....
6CA1F5A0 74 52 0F B6 4C 24 1C 8B 54 24 18 2B 54 24 0C 1B tR..L$..T$.+T$..
6CA1F5B0 74 24 14 89 F3 D3 E3 89 F9 8B 7C 24 50 D3 EA D3 t$........|$P...
6CA1F5C0 EE 09 DA 89 77 04 89 17 31 FF E9 B3 FE FF FF 90 ....w...1.......
6CA1F5D0 31 FF 31 C0 E9 A9 FE FF FF 8D B4 26 00 00 00 00 1.1........&....
6CA1F5E0 89 DA 8B 4C 24 0C B8 01 00 00 00 29 F1 19 EA E9 ...L$......)....
6CA1F5F0 0A FF FF FF 31 FF E9 87 FE FF FF 90 90 90 90 90 ....1...........

;; fn6CA1F600: 6CA1F600
;;   Called from:
;;     6C94123F (in fn6C9411E9)
;;     6C9412C2 (in fn6C9411E9)
;;     6C9412F7 (in fn6C9411E9)
fn6CA1F600 proc
	mov	eax,00000001
	ret	000C

;; fn6CA1F608: 6CA1F608
;;   Called from:
;;     6C941289 (in fn6C9411E9)
;;     6C9412AB (in fn6C9411E9)
fn6CA1F608 proc
	mov	eax,00000001
	ret	000C
6CA1F610 FF 25 EC 57 A5 6C 90 90 FF 25 E8 57 A5 6C 90 90 .%.W.l...%.W.l..
6CA1F620 FF 25 E4 57 A5 6C 90 90 FF 25 E0 57 A5 6C 90 90 .%.W.l...%.W.l..
6CA1F630 FF 25 DC 57 A5 6C 90 90 FF 25 D8 57 A5 6C 90 90 .%.W.l...%.W.l..
6CA1F640 FF 25 D4 57 A5 6C 90 90 FF 25 D0 57 A5 6C 90 90 .%.W.l...%.W.l..
6CA1F650 FF 25 CC 57 A5 6C 90 90 FF 25 C8 57 A5 6C 90 90 .%.W.l...%.W.l..
6CA1F660 FF 25 C4 57 A5 6C 90 90 FF 25 BC 57 A5 6C 90 90 .%.W.l...%.W.l..
6CA1F670 FF 25 B4 57 A5 6C 90 90 FF 25 B0 57 A5 6C 90 90 .%.W.l...%.W.l..
6CA1F680 FF 25 AC 57 A5 6C 90 90 FF 25 1C 57 A5 6C 90 90 .%.W.l...%.W.l..
6CA1F690 FF 25 18 57 A5 6C 90 90 FF 25 80 56 A5 6C 90 90 .%.W.l...%.V.l..
6CA1F6A0 8B 83 B0 01 00 00 A3 08 00 00 00 0F 0B 90 90 90 ................
6CA1F6B0 A1 0C 00 00 00 0F 0B A1 00 00 00 00 0F 0B 90 90 ................
6CA1F6C0 A1 3C 00 00 00 0F 0B A1 24 00 00 00 0F 0B A1 3C .<......$......<
6CA1F6D0 00 00 00 0F 0B 90 90 90 A1 04 00 00 00 0F 0B 89 ................
6CA1F6E0 C7 BE 12 00 00 00 B9 04 00 00 00 F3 A5 0F 0B A1 ................
6CA1F6F0 00 00 00 00 0F 0B 90 90 A1 00 00 00 00 0F 0B A1 ................
6CA1F700 80 04 00 00 0F 0B 90 90 66 90 66 90 66 90 66 90 ........f.f.f.f.
6CA1F710 E9 4B 1C F2 FF 90 90 90 90 90 90 90 90 90 90 90 .K..............
6CA1F720 FF FF FF FF 10 F7 A1 6C 00 00 00 00 FF FF FF FF .......l........
6CA1F730 00 00 00 00                                     ....           
