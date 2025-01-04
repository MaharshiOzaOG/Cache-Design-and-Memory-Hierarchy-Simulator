#ifndef SIM_CACHE_H
#define SIM_CACHE_H

//lib for log-base2
#include <bits/stdc++.h>
#include <cmath>


typedef 
struct {
   uint32_t BLOCKSIZE;
   uint32_t L1_SIZE;
   uint32_t L1_ASSOC;
   uint32_t L2_SIZE;
   uint32_t L2_ASSOC;
   uint32_t PREF_N;
   uint32_t PREF_M;
} cache_params_t;




//Building general Cache Class
  class Cache_c
  {

	  public:
	  int32_t SIZE;
	  int32_t ASSOC;
	  int32_t BLOCKSIZE;
	  int32_t Sets;
	 
	  int32_t num_blockOffsetBits;
	  int32_t num_Index;
	  int32_t num_Tag;
	  
	  
	//Variables where the num_Tag, num_Index, and BlockOffset values be saved.
      int32_t L1_tag;
	  int32_t L1_blockOffset;
	  int32_t L1_index;
   
	  bool iscompletlyEmpty = true;
	  bool iscompletlyFull = false;
	  int PF_N;
	  int PF_M;
   	//Variables where the num_Tag, num_Index, and BlockOffset values be saved.
     /* int32_t L2_tag;
	  int32_t L2_blockOffset;
	  int32_t L2_index;*/
   //
	//bool performREADOperationCPU();
	//bool performREADtoL1();

	//bool set_Valid_ND_DIRT(/*int8_t*/);
	bool checkCacheSet(int, bool, int32_t);
	//bool L1_Calling(char, int);
	
	void L1_parsingCacheParams( int32_t, bool, int);
	//void L2_parsingCacheParams( int32_t addr );
	


	void display_L1_L2_shortcontents();
	void display_L1(const std::string&);
	void RorW_func(int32_t, bool, int);

	void PerformMissLogic(int, bool, int32_t);

	//bool check_if_SB_Hit();
	void LRU_update_C(int);
	void SB_LRU_update_C(int);

	bool CHECK_IF_SB_HIT(int, int, int, int32_t, bool);
	void Perform_SB_Hit_logic(int , int, int , bool);
	void Perform_SB_Miss_logic(int, int32_t, bool, bool);
	void updateStreamBuffer(int, int32_t, int, bool);

	uint32_t hexToDecimal(const std::string& hexStr);
	std::string decimalToBinary(uint32_t decimalValue);
	//std::string convert
	  enum CacheBlockDirty
		  {
		  	CLEAN,
			DIRTY,
			High_Impedence
		  };
		  
	  enum CacheBlockValid
		  {
		  	NOT_VALID,
			VALID,
			NONE
		  };
		  
		  
		// Function to convert enum value to a string
	 const char* cacheBlockDirtyToString(CacheBlockDirty state) 
	 {
		switch (state) 
		{
			case DIRTY:	return "DIRTY";
			case CLEAN:  return "CLEAN";
			default		:   return "Unknown";
		}
	 }
	 
	 // Function to convert enum value to a string
	 const char* cacheBlockValidToString(CacheBlockValid state) 
	 {
		switch (state) 
		{
			case VALID:	return "VALID    ";
			case NOT_VALID:  return "NOT_VALID";
			default		:   return "Unknown";
		}
	 }
	 
	  struct CacheBlock
		  {
		  	CacheBlockDirty dirty_s;	//Make struct {isDirty, notDirty}
			int32_t LRU;
		  	CacheBlockValid Valid_s;	//Make struct {isDirty, notDirty}
			int32_t TAG;
			int32_t BLOCK_ADDR;	//Temp
			/*Change this location */bool cachesetEmpty;
		  	//bool Valid;	//Make Struct {isValid, notValid}
		  	//int32_t data;	//Ignore
		  	
		  	// Default constructor
		  	CacheBlock(): dirty_s(CLEAN),LRU(0), Valid_s(NOT_VALID), TAG(0), BLOCK_ADDR(0), cachesetEmpty(true) {}
		  };

	  //struct StreamBuffer {
		 // int32_t TAG_sb;
		 // int32_t TAG_IDX_sb;
		 // int32_t BLOCK_ADDR_sb;
		 // //int32_t LRU_sb;
		 // //CacheBlockValid Valid_s;
	  //};
	  struct StreamBuffer {
		  int32_t HEAD_sb;         // HEAD_sb will be at the stream buffer set level
		  int32_t LRU_sb;          // LRU value for the stream buffer set
		  CacheBlockValid Valid_s_sb; // Validity status for the stream buffer set
		  //int32_t TAG_sb;
		  int32_t TAG_IDX_sb;
		  int32_t BLOCK_ADDR_sb;

		  StreamBuffer(): HEAD_sb(0), LRU_sb(0), Valid_s_sb(NOT_VALID), TAG_IDX_sb(0), BLOCK_ADDR_sb(0){}
	  };
	  CacheBlock** cacheMatrix;
	  StreamBuffer** StreamBuf;
	  //void Cache_c::printCacheMatrix();
	  //calculating num_Tag, num_Index, BlockOffset based on Inputs
	  //void CacheSetup (int32_t SIZE, int32_t ASSOC, int32_t BLOCKSIZE )
	  Cache_c (int32_t SIZE, int32_t ASSOC, int32_t BLOCKSIZE, int32_t PF_N, int32_t PF_M):SIZE(SIZE), ASSOC(ASSOC), BLOCKSIZE(BLOCKSIZE), PF_N(PF_N), PF_M(PF_M)
	  {			  
		  /* this->SIZE = SIZE;
		  this->ASSOC = ASSOC;
		  this->BLOCKSIZE = BLOCKSIZE; */
		  //this->PF_N = 7;
		  //this->PF_M = 6;
		  //std::cout << "PF_N" << PF_N;
		  //std::cout << "PF_M" << PF_M;
		  //find SET in general (L1 & L2)
		  Sets = SIZE/(ASSOC * BLOCKSIZE);
//		  std::cout << "Sets" << Sets << std::endl;;
		  //now find BO, Indx, num_Tag
		  num_blockOffsetBits = log2(BLOCKSIZE);
		  num_Index = log2(Sets);
		  num_Tag = 32 - num_blockOffsetBits - num_Index;
		  //std::cout << "num_Index" << num_Index << std::endl;
		  //std::cout << "num_Tag" << num_Tag << std::endl;
		  
		  // Constructor to initialize cacheMatrix
		  //Cache_c(int sets, int assoc) : Sets(sets), ASSOC(assoc) 
		  
			cacheMatrix = new CacheBlock*[Sets];
			for (int i = 0; i < Sets; i++) 
			{
				//int assoc = ASSOC + 1;
				cacheMatrix[i] = new CacheBlock[ASSOC];
				cacheMatrix[i][0].LRU = 0;
				//std::cout << "all LRU values" << cacheMatrix[i][0].LRU;
				cacheMatrix[i][0].cachesetEmpty = true; // Initialize dirty
				//std::cout << assoc;
				for (int j = 0; j < (ASSOC); j++)
				{
					cacheMatrix[i][j].LRU = j;	// cacheMatrix[i][j].LRU + 1;
					cacheMatrix[i][j].Valid_s = NOT_VALID; // Initialize Valid
					cacheMatrix[i][j].dirty_s = CLEAN; // Initialize dirty
					cacheMatrix[i][j].TAG = 0; // Initialize dirty
					cacheMatrix[i][j].BLOCK_ADDR = 0; // Initialize BlockAddr
					//if(j = (assoc))
					//	cacheMatrix[i][j].cachesetEmpty = true; // Initialize dirty
					//
					/* printf("Valid:   		%u\n", cacheMatrix[i][j].Valid);
					printf("dirty:   		%u\n", cacheMatrix[i][j].dirty);
					printf("LRU:   			%u\n", cacheMatrix[i][j].LRU); */
					
				}
			}
			//std::cout << "DONE DONE HAHA1";
		  StreamBuf = new StreamBuffer*[PF_N];  // Create array of pointers to StreamBuffer arrays
		  //int* LRU_sb = new int[PF_N];  // Array to store LRU values
		  //int* HEAD_sb = new int[PF_N];  // Array to store HEAD_sb for each stream buffer set (PF_N)
		  //CacheBlockValid* Valid_s = new CacheBlockValid[PF_N];  // Array to store validity status
		  //std::cout << "DONE DONE HAHA";
		  // Loop through and initialize each stream buffer set
		  for (int i = 0; i < PF_N; i++) {
			  StreamBuf[i] = new StreamBuffer[PF_M];  // Allocate array for PF_M elements
			  StreamBuf[i][0].LRU_sb = i;  // Only assign LRU_sb for the first element (position 0)
			  //if()
			  /*std::cout << "LRU value for StreamBuf[" << i << "][0] = "
				  << StreamBuf[i][0].LRU_sb << std::endl;*/

			  StreamBuf[i][0].Valid_s_sb = NOT_VALID;  // Initialize validity status
			  StreamBuf[i][0].HEAD_sb = 0;  // Initialize the HEAD_sb for each stream buffer set

			  for (int j = 0; j < PF_M; j++) {
				  // Other initializations for all elements in the second dimension
				  StreamBuf[i][j].TAG_IDX_sb = 0;  // Initialize tag index
				  //std::cout << "   " << std::hex << StreamBuf[i][j].TAG_IDX_sb;
			  }
			  //std::cout << std::endl;
		  }
		  
     }
	  


//	   void printCacheMatrix()
//		{
			//for (int i = 0; i < Sets; i++) 
			//{
			//	printf("XXXXXXXXXXXXXXXXXXXXXXX \n");
			//		for (int j = 0; j < ASSOC; ++j) 
			//		{
			//			
			//			printf("Valid:   		%s\n", cacheBlockValidToString(cacheMatrix[i][j].Valid_s));
			//			printf("dirty:   		%s\n", cacheBlockDirtyToString(cacheMatrix[i][j].dirty_s));
			//			printf("LRU:   			%u\n", cacheMatrix[i][j].LRU);
			//			printf("TAG:   			%u\n", cacheMatrix[i][j].TAG);
			//		}
			//}
//		}

  };
// Put additional data structures here as per your requirement.
  ///*static*/ int32_t L1_Write = 0;	//global var
  /*static*/ int32_t L1_Write_MISS = 0;	//global var
  /*static*/ int32_t L1_Read_HITT = 0;	//global var
  /*static*/ int32_t L1_READ_HIT_CPU = 0;	//global var

  int32_t FOUND_ASSOC;
  int32_t CPU_ADDR;
  bool changeL1_2_L2 = false;
  bool L2_Exist = false;
  bool L1_Prefetch_Exist = false;
  bool L2_Prefetch_Exist = false;
  bool LRU_DIRTY_WB = false;
  int32_t LRU_WB_ADDR;
  int Main_MEM_Traffic_WB2L1 = 0;
  int Main_MEM_Traffic_WA2L1 = 0;

  int Main_MEM_Traffic_WB2L2 = 0;
  int Main_MEM_Traffic_WA2L2 = 0;
  int Main_MEM_Traffic_L1_Miss_deamnd = 0;
  int Main_MEM_Traffic_L2_Miss_deamnd = 0;


  int Main_MEM_Traffic = 0;

  int L1_WB_L2 = 0;
  int L1_WA_L2 = 0;
  int L1_WB_MM = 0;
  int L1_WA_MM = 0;
  int L2_WB_MM = 0;
  int L2_WA_MM = 0;

  int L1_WriteBack = 0;
  int L2_WriteBack = 0;

  int L2_Read = 0;
  int L1_Read = 0;
  int L1_Write = 0;
  int L1_Read_miss = 0;
  //int L2_Read_miss = 0;



  int L1_prefetch = 0;
  int Cache_Hit_N_SB_Miss_count = 0;
  int Main_MEM_Traffic_L1_Pf = 0;

  int L2_prefetch = 0;
  int Main_MEM_Traffic_L2_Pf = 0;


  //For L2
  int L2_writes = 0;	//same as L1_WriteBack
  int L2_read_miss = 0;
  int L2_write_miss = 0;
  //void L1_Calling();
  //void display_L1_L2_Allcontents();
  //void display_L1_L2_shortcontents();
  
#endif
