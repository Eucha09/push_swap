# push_swap

정렬해야 하는 int 값들과 두 개의 스택, 그리고 이 스택을 조작하는 명령어 집합이 주어졌을 때 최소한의 명령어를 이용하여 정렬하는 알고리즘 구현

## Mandatory part

두 개의 스택 a와 b가 주어진다.

초기상태
- 스택 a에는 랜덤한 개수의 정수들이 들어가 있다   
- 스택 b는 비어있다

목표는 스택 a에 정수들을 오름차순으로 정렬하는 것이다.

주어진 명령어
- **sa** : ```swap a``` - 스택 a의 top에 위치한 두 개의 원소의 순서를 맞바꿉니다. 스택 a가 비어있거나 원소가 1개만 있을 때는 아무 동작도 하지 않습니다.
- **sb** : ```swap b``` - 스택 b의 top에 위치한 두 개의 원소의 순서를 맞바꿉니다. 스택 b가 비어있거나 원소가 1개만 있을 때는 아무 동작도 하지 않습니다.
- **ss** - ```sa```와 ```sb```를 동시에 수행합니다.
- **pa** : ```push a``` - 스택 b의 top에 위치한 원소 한 개를 스택 a의 top으로 옮깁니다. 스택 b가 비어있을 경우에는 아무 동작도 하지 않습니다.
- **pb** : ```push b``` - 스택 a의 top에 위치한 원소 한 개를 스택 b의 top으로 옮깁니다. 스택 a가 비어있을 경우에는 아무 동작도 하지 않습니다.
- **ra** : ```rotate a``` - 스택 a의 원소를 한 칸씩 위로 옮깁니다. 스택의 첫 번째 원소는 맨 마지막 원소가 됩니다.
- **rb** : ```rotate b``` - 스택 b의 원소를 한 칸씩 위로 옮깁니다. 스택의 첫 번째 원소는 맨 마지막 원소가 됩니다.
- **rr** : ```ra```와 ```rb```를 동시에 수행합니다.
- **rra** : ```reverse rotate a``` - 스택 a의 원소를 한 칸씩 아래로 옮깁니다. 스택의 마지막 원소는 맨 첫 번째 원소가 됩니다.
- **rrb** : ```reverse rotate b``` - 스택 b의 원소를 한 칸씩 아래로 옮깁니다. 스택의 마지막 원소는 맨 첫 번째 원소가 됩니다.
- **rrr** : ```rra```와 ```rrb```를 동시에 수행합니다.

### 스택 구현

동적배열 방식으로 구현하였다.   
기존 스택과 다른 점은 나중 rotate 연산을 구현하기 위해 위 아래 다 push와 pop이 가능하도록 구현하였다. (사실상 원형 deque 구조를 띄고 있음)

**스택 구조체**

```c
typedef struct s_stack
{
	int	*arr; // 실제 원소들을 담고 있을 배열
	int	capacity; // 배열 전체 용량
	int	top; // 스택의 top을 가리키는 인덱스
	int	bottom; // 스택의 bottom을 가리키는 인덱스
}	t_stack;
```

**구현한 함수**

```c
t_stack	*ft_stack_new(void); // 스택 생성
void	ft_stack_clear(t_stack *stack); // 스택 free
int	ft_stack_size(t_stack *stack); // 스택 사이즈 반환

void	ft_stack_push(t_stack *stack, int value); // push_top과 동일
void	ft_stack_push_top(t_stack *stack, int value); // 스택에서 제일 위에 삽입
void	ft_stack_push_bottom(t_stack *stack, int value); // 스택에서 제일 아래에 삽입

int	ft_stack_pop(t_stack *stack); // pop_top과 동일
int	ft_stack_pop_top(t_stack *stack); // 스택에서 제일 위에 있는 원소를 꺼내 반환
int	ft_stack_pop_bottom(t_stack *stack); // 스택에서 제일 아래에 있는 원소를 꺼내 반환 

int	ft_stack_top_first(t_stack *stack); // 제일 위에 있는 원소 반환
int	ft_stack_top_second(t_stack *stack); // 위에서 2번째 원소 반환
int	ft_stack_bottom_first(t_stack *stack); // 제일 아래에 있는 원소 반환
int	ft_stack_bottom_second(t_stack *stack); // 아래에서 2번째 원소 반환
```

### 명령어 구현

스택 a와 b를 구조체 하나로 묶었고 명령어들을 함수화하여 구현하였다.

```c
typedef struct s_stack_pair
{
	t_stack	*a;
	t_stack	*b;
}	t_stack_pair;

t_stack_pair	*stack_pair_new(void);
void		stack_pair_clear(t_stack_pair *s);

void		sa(t_stack_pair *s);
void		sb(t_stack_pair *s);
void		ss(t_stack_pair *s);
void		pa(t_stack_pair *s);
void		pb(t_stack_pair *s);
void		ra(t_stack_pair *s);
void		rb(t_stack_pair *s);
void		rr(t_stack_pair *s);
void		rra(t_stack_pair *s);
void		rrb(t_stack_pair *s);
void		rrr(t_stack_pair *s);
```

### push_swap 정렬 알고리즘 구현

```
Stack	   a	       b

	*     *     *     *
	*     *     *     *
	*  0  *     *  1  *
	*     *     *     *
	* --- *     * --- *
	*     *     *     *
	*  3  *     *  2  *
	*     *     *     *
	* * * *	    * * * *
```

스택을 위와 같이 4개의 구역으로 나누었다.

x구역의 원소를 y구역으로 이동시키려면 아래와 같이 명령어를 호출하면 된다.   
x -> y   
0 -> 1 : ```pb```   
0 -> 2 : ```pb``` ```rb```   
0 -> 3 : ```ra```   
...

정렬은 병합정렬 알고리즘 방식을 사용하였다.

초기 원소들이 구역 0에 모여있다고 하였을 때   
스택 내 원소들의 배열을 3개의 균등한 크기로 분할하고 각 분할된 부분 배열을 정렬한 다음, 3개의 정렬된 부분 배열을 병합하여 전체가 정렬된 배열이 되게 하는 방식으로 구현하였다.

```c
void	push_swap_sort(t_stack_pair *s, int size, int order)
{
	int	seg_size[3];

	// size가 2이하일 경우 분할할 필요없이 swap 연산만으로 정렬
	if (size <= 2)
		return (sort_size2(s, size, order));
	
	// 전체 size를 3개의 균일한 크기로 분할
	seg_size[1] = size / 3;
	seg_size[0] = (size - (seg_size[1])) / 2;
	seg_size[2] = size - seg_size[0] - seg_size[1];

	// 각 분할된 부분 배열을 정렬하고 다른 구역으로 옮겨놓는다.
	push_swap_sort(s, seg_size[0], order);
	move_stack(s, 0, 1, seg_size[0]); // 0 -> 1
	push_swap_sort(s, seg_size[1], order);
	move_stack(s, 0, 2, seg_size[1]); // 0 -> 2
	push_swap_sort(s, seg_size[2], order);
	move_stack(s, 0, 3, seg_size[2]); // 0 -> 3

	// 다른 구역에 있는 정렬된 부분 배열들을 합친다.
	merge(s, seg_size, order);
}
```
