#pragma once

///@brief PoolAllocator�ł��B
///@tparam T �m�ۂ������f�[�^�̌^
///@tparam MAXSIZE �ő�m�ۉ\�Ȍ�
///@detail �v�Z����O(1)�Ń��������m�ہA������ł��܂��B
template<class T, size_t MAXSIZE> class PoolAllocator
{
public:

	///@brief �R���X�g���N�^
	[[nodiscard]]
	PoolAllocator() noexcept
	{

		//���ꂼ��̃`�����N�Ɏ��̃`�����N�̃|�C���^������
		for (size_t i = 0; i < MAXSIZE - 1; ++i)
		{
			new(m_data + (chunkSize * i))char* (m_data + (chunkSize * (i + 1)));
		}

		//�Ō�̃`�����N�ɂ�nullptr������
		new(m_data + (chunkSize * (MAXSIZE - 1)))char* (nullptr);
	}

	///@brief ���������m�ۂ��܂��B
	///@return �m�ۂ����������̃|�C���^�B
	///@detail ���������m�ۂł��Ȃ��ꍇ��nullptr��Ԃ��܂��B
	[[nodiscard]]
	T* Alloc()
	{
		//�������ɋ󂫂��Ȃ��Ȃ�nullptr��Ԃ�
		if (not m_first)
		{
			return nullptr;
		}

		char* result = m_first;

		m_first = *reinterpret_cast<char**>(m_first);

		++m_size;

		return new(result)T{};
	}

	///@brief ��������������܂��B
	///@param addr ���������J������|�C���^�B
	///@detail nullptr��n�����ꍇ�͉������܂���B
	void Free(T* addr)noexcept
	{
		//nullptr�Ȃ牽�����Ȃ�
		if (not addr)
		{
			return;
		}

		*reinterpret_cast<char**>(addr) = m_first;

		m_first = reinterpret_cast<char*>(addr);

		--m_size;
	}

	///@brief �g�p����Ă���v�f����Ԃ��܂��B
	///@return �v�f��
	[[nodiscard]]
	size_t Size()const noexcept
	{
		return m_size;
	}

private:

	///@brief �`�����N�̃T�C�Y�ł��B
	///@detail �^T�ƃ`�����N�ւ̃|�C���^�^�̑傫�����̃T�C�Y�ɂȂ�܂��B
	constexpr static size_t chunkSize = (std::max)(sizeof(T), sizeof(char*));

	///@brief �������v�[���ł��B
	///@detail �^T���A���̋󂢂Ă���`�����N�ւ̃|�C���^������܂��B
	char m_data[chunkSize * MAXSIZE];

	///@brief �ŏ��̋󂢂Ă���`�����N�ւ̃|�C���^�ł��B
	///@detail ���������󂢂Ė�������nullptr���w���܂��B
	char* m_first = m_data;

	///@brief �g�p����Ă���`�����N�̌��ł��B
	size_t m_size = 0;
};
