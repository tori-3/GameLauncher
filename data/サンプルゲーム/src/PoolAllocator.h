#pragma once

///@brief PoolAllocatorです。
///@tparam T 確保したいデータの型
///@tparam MAXSIZE 最大確保可能な個数
///@detail 計算時間O(1)でメモリを確保、解放ができます。
template<class T, size_t MAXSIZE> class PoolAllocator
{
public:

	///@brief コンストラクタ
	[[nodiscard]]
	PoolAllocator() noexcept
	{

		//それぞれのチャンクに次のチャンクのポインタを入れる
		for (size_t i = 0; i < MAXSIZE - 1; ++i)
		{
			new(m_data + (chunkSize * i))char* (m_data + (chunkSize * (i + 1)));
		}

		//最後のチャンクにはnullptrを入れる
		new(m_data + (chunkSize * (MAXSIZE - 1)))char* (nullptr);
	}

	///@brief メモリを確保します。
	///@return 確保したメモリのポインタ。
	///@detail メモリを確保できない場合はnullptrを返します。
	[[nodiscard]]
	T* Alloc()
	{
		//メモリに空きがないならnullptrを返す
		if (not m_first)
		{
			return nullptr;
		}

		char* result = m_first;

		m_first = *reinterpret_cast<char**>(m_first);

		++m_size;

		return new(result)T{};
	}

	///@brief メモリを解放します。
	///@param addr メモリを開放するポインタ。
	///@detail nullptrを渡した場合は何もしません。
	void Free(T* addr)noexcept
	{
		//nullptrなら何もしない
		if (not addr)
		{
			return;
		}

		*reinterpret_cast<char**>(addr) = m_first;

		m_first = reinterpret_cast<char*>(addr);

		--m_size;
	}

	///@brief 使用されている要素数を返します。
	///@return 要素数
	[[nodiscard]]
	size_t Size()const noexcept
	{
		return m_size;
	}

private:

	///@brief チャンクのサイズです。
	///@detail 型Tとチャンクへのポインタ型の大きい方のサイズになります。
	constexpr static size_t chunkSize = (std::max)(sizeof(T), sizeof(char*));

	///@brief メモリプールです。
	///@detail 型Tか、次の空いているチャンクへのポインタが入ります。
	char m_data[chunkSize * MAXSIZE];

	///@brief 最初の空いているチャンクへのポインタです。
	///@detail メモリが空いて無い時はnullptrを指します。
	char* m_first = m_data;

	///@brief 使用されているチャンクの個数です。
	size_t m_size = 0;
};
