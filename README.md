# push_swap

## 프로젝트 목표
push swap은 다양한 정렬 알고리즘에 대해 배울 수 있는 42개의 프로젝트입니다.

## 프로젝트 주제
이 프로젝트의 목표는 stack의 연산인 latest instruction(LIFO)을 중심으로 랜덤하게 번호가 적힌 원소들의 스택을 정렬하는 것입니다. 고유하고 랜덤한 번호를 가진 스택을 두 개만 사용할 수 있습니다.

다음에 해당하는 작업만 사용할 수 있습니다 :

**sa** : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
is only one or no elements).

**sb** : swap b - 스택 b의 맨 위에 있는 처음 두 요소를 바꿉니다. (요소가 하나뿐이거나 없는 경우 아무것도 하지 않습니다.)

**ss** : sa와 sb를 동시에.

**pa** : push a - b의 맨 위에 있는 첫 번째 원소를 a의 맨 위에 놓습니다. (b가 비어 있으면 아무 작업도 안합니다.)

**pb** : push b - a의 맨 위에 있는 첫 번째 원소를 b의 맨 위에 놓습니다. (a가 비어 있으면 아무 작업도 안합니다.)

**ra** : rotate a - 스택 a의 모든 원소를 1씩 위로 이동시킵니다. (첫 번째 요소가 마지막 요소가 됩니다.)

**rb** : rotate b - shift up all elements of stack b by 1. The first element becomes
the last one.

**rr** : ra와 rb를 동시에.

**rra** : reverse rotate a - 스택 a의 모든 원소를 1씩 아래로 이동시킵니다. 마지막 요소가 첫 번째 요소가 됩니다.

**rrb** : reverse rotate b - 스택 b의 모든 요소를 1만큼 아래로 이동시킨다. 마지막 요소
첫 번째 요소가 됩니다.

**rrr** : rra와 rrb를 동시에

## 실행하는 법

### Linux 환경
```
$ git clone https://github.com/silim124/push_swap
$ cd push_swap/
```
### 컴파일
```
$ make
```
### 실행
push_swap 파일을 다음과 같이 랜덤 값으로 실행합니다.
```
./push_swap 3 2 1 4 6 5
sa
rra
.
.
.
```
