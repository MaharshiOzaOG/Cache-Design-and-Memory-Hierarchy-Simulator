#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "sim.h"

//lib for log-base2
#include <bits/stdc++.h>
#include <cmath>

#include <sstream>
#include <string>
#include <bitset>

/* void C::setName(const std::string& newName) {
    name = newName;
}

// Getter for name
std::string C::getName() const {
    return name;
}

// Setter for value
void C::setValue(int newValue) {
    value = newValue;
}

// Getter for value
int C::getValue() const {
    return value; */
#if 0
bool Cache_c::check_Valid_ND_DIRT(idx)
{

	if (cache[idx].cacheMatrix[L1_index][/*SAVE_num_ASSOC*/].VALID == L1_TAG)
	{
		if (!Valid)
		{
			//CPU performs Write Operation

			/*set Valid bit*/   cache[idx].cacheMatrix[L1_Index][ASSOC].Valid_s = VALID;
			/*Set dirty bit*/	cache[idx].cacheMatrix[L1_Index][ASSOC].dirty_s = DIRTY;
			L1_Write++;
			return true;
		}
		else if (Valid)
		{
			//Set Valid --> Not needed but still	//cache[idx].cacheMatrix[L1_Index][ASSOC].Valid_s = VALID;
			/*Set dirty bit*/	cache[idx].cacheMatrix[L1_Index][ASSOC].dirty_s = DIRTY;
			L1_Write++;
			return true;
		}
	}
	
	return false;
}
#endif
#if 0
bool Cache_c::set_Valid_ND_DIRT(int8_t idx)
{
	if (cache[idx].cacheMatrix[L1_index][/*SAVE_num_ASSOC*/FOUND_ASSOC].TAG == L1_tag)
	{
		if(!cacheMatrix[L1_index][FOUND_ASSOC].Valid_s)
		{
			//CPU performs Write Operation
			
			/*set Valid bit*/   cache[idx].cacheMatrix[L1_index][ASSOC].Valid_s = VALID;
			/*Set dirty bit*/	cache[idx].cacheMatrix[L1_index][ASSOC].dirty_s = DIRTY;
			L1_Write++;
			return true;
		}
		else if (cacheMatrix[i][j].Valid_s == VALID)
		{
			//Set Valid --> Not needed but still	//cache[idx].cacheMatrix[L1_Index][ASSOC].Valid_s = VALID;
			/*Set dirty bit*/	cache[idx].cacheMatrix[L1_index][ASSOC].dirty_s = DIRTY;
			L1_Write++;
			return true;
		}
	}

	return false;
}
#endif
//bool Cache_c::performREADOperationCPU()
//{
//	bool CPU_READ_DONE = false;
//	if (cacheMatrix[L1_index][FOUND_ASSOC].TAG == L1_tag)	//Not required as already checked in this function <checkCacheSet>
//	{
//		//Just set the dirty bit for that particular Block Offset.
//		cacheMatrix[L1_index][FOUND_ASSOC].dirty_s = DIRTY;
//		L1_READ_HIT_CPU++;
//		CPU_READ_DONE = true;
//	}
//	return CPU_READ_DONE;
//}
//bool Cache_c::performREADtoL1()
//{
//	if (cacheMatrix[L1_index][FOUND_ASSOC/*NANANAN*/].dirty_s == CLEAN)
//	{
//		cacheMatrix[L1_index][FOUND_ASSOC].TAG = L1_tag;
//		//DEL-if (cacheMatrix[L1_index][FOUND_ASSOC].TAG == L1_tag)		//THIS is Redundunt----->//Note L1_index => L2_index and FOUND_ASSOC => L2_ASSOC
//		//DEL-//{															//Cause cache[0] is calling it.
//			//Set the TAG and dirty bit to clear.
//		cacheMatrix[L1_index][FOUND_ASSOC].dirty_s = CLEAN;
//		cacheMatrix[L1_index][FOUND_ASSOC].Valid_s = VALID;
//		//UPDATE LRU
//		return true;
//	}
//	else if (cacheMatrix[L1_index][FOUND_ASSOC].dirty_s == DIRTY)
//	{
//		//Perform Write Back
//		
//		cacheMatrix[L1_index][FOUND_ASSOC].dirty_s = CLEAN;
//		
//		//Perform Write Back Over
//		cacheMatrix[L1_index][FOUND_ASSOC].TAG = L1_tag;
//		cacheMatrix[L1_index][FOUND_ASSOC].dirty_s = CLEAN;
//		cacheMatrix[L1_index][FOUND_ASSOC].Valid_s = VALID;
//		return true;
//	}
//}


#if 0
bool Cache_c::L1_Calling(char rw_, int lvl_)
{
	// Call L1 function.
	//for (int8_t idx = 0; idx < 2; idx++)
		bool valid = checkCacheSet(/*idx*/);
		//printf("VVAALLIIDD %d", valid);
		//std::count << valid;


		//CHECK FOR THE DIRTY BIT
		//bool var = func check dirty bit


		//if(dirty id clean)
		//{niche wala}

		if (valid && lvl_ == 0/*&& (idx == 0)*/)	//ONLY WHEN L1 is THERE NO L2
		{
			printf("Perform CPU OPRATION");
#if 0
			// Perform Whatever operation on L1_ONLY then
			if (/*WRITE OPERATION*/rw_ == 'w')
			{
				//printf("valid = 1 , idx = 0");
				//Call Write Operation Function
				bool TRUE = set_Valid_ND_DIRT(idx);
			}
			else if (/*READ OPERATION*/rw_ == 'r')
			{
				//Call Read Operation Function
				check_Valid_ND_DIRT(idx);
			}
			break;
#endif
		}
		if (valid && lvl_ == 1/*&& (idx == 1)*/)		//tag FOUND in L2
		{
			printf("L1L1L1L1L1L1L1L1L1L1L1L1L1L1L1L1L1L1L1L1L1L1L1L1L1L1L1L1L1L1L1L1L1L1L1L1L1L1L1L1L1L1L1\n");
			printf("// Perform Read to L1");
			/*This is kinda Imp *///cache[0].cacheMatrix[cache[0].Index][cache[0].ASSOC].TAG = cache[1].cacheMatrix[cache[1].Index][cache[1].ASSOC].TAG;

			//if it a L1 miss then 
				//check for LRU--> from that paticular cache set in L1
					//after finding LRU check if that LRU is dirty.
						//if dirty -->then perform WriteBack to L2 of that LRU--> ASSOC in L2	//Missed a case where---> this if that ASSOC not present in L2 then???
						// also clean that L1.
					//NOW Perform the WriteAllocate from L2 to L1.
								  
								  
								  
								  
								  
								  
								  
								  
								  
								  
								  //Check if L1 block is dirty (Check Dirty based on LRU cause we need to evict that LRU wala data)
			
			//if true ---> bool = cache[lvl /*This should be L2*/] MAKE DIFF FUNC IS GOOD performREADtoL1(HITT, L1_DIRTY); // Actually performs Allocate L2 by Mem

			//else --> {Perform Only ReadOp to L1 on that LRU by evict that data Based on that LRU}

			//performWRITE_BACK

			/*bool L2_check = <TRUE>*/
		}
		if(!valid && lvl_ == 1/*!L1_Check && !L2_Check*/)	//Not found in L1 and L2 (tag != tag)
		{
			
			
			//  lvl == 2 inside the if condition.
			printf("L2L2L2L2L2L2L2L2L2L2L2L2L2L2L2L2L2L2L2L2L2L2L2L2L2L2L2L2L2L2L2L2L2L2L2L2L2L2L2L2L2L2L2\n");
			printf("//Set the tag of L2 in the position of cacheMatrix[L1_Index]Note that this is Actually L2_Index[ASSOC].dirty_s = CLEAN;\n");
			printf("//Set the tag of L2 in the position of cacheMatrix[L1_Index]Note that this is Actually L2_Index[ASSOC].Valid_s = VALID;\n");
			printf("//Set the tag of L2 in the position of cacheMatrix[L1_Index]Note that this is Actually L2_Index[ASSOC].TAG = L1_tag;\n");
			printf("//MEM_TRANS++;\n");

			bool = cache[lvl /*This should be L2*/]performREADtoL1(MISS); // Actually performs Allocate L2 by Mem
			valid = true;

			//UPDATES LRU --> Call a function from here OK
		}
	return valid;
}
#endif

	
void Cache_c::LRU_update_C(int i)
{
	for (int j = 0; j < ASSOC; j++)
	{
		if (cacheMatrix[L1_index][j].LRU < cacheMatrix[L1_index][i].LRU) {
				cacheMatrix[L1_index][j].LRU++;
		}

	}
	cacheMatrix[L1_index][i].LRU = 0;
}

void Cache_c::SB_LRU_update_C(int i)
{
	for (int j = 0; j < PF_N; j++)
	{
		if (StreamBuf[j][0].LRU_sb < StreamBuf[i][0].LRU_sb) {
			StreamBuf[j][0].LRU_sb++;
		}

	}
	StreamBuf[i][0].LRU_sb = 0;

	/*for (int j = 0; j < PF_N; j++)
	{
		std::cout << "	LRU_Update =" << StreamBuf[i][0].LRU_sb;
	}*/
}
// Convert hexadecimal string to integer
uint32_t Cache_c::hexToDecimal(const std::string& hexStr) 
{
	uint32_t decimalValue;
	std::stringstream ss;
	ss << std::hex << hexStr; // Convert hex string to decimal
	ss >> decimalValue;
	return decimalValue;
}
	
// Convert integer to binary string
std::string Cache_c::decimalToBinary(uint32_t decimalValue) 
{
	std::bitset<32> binaryValue(decimalValue); // Create a bitset of size 32
	return binaryValue.to_string(); // Convert bitset to string
}

bool Cache_c::checkCacheSet(int lvl_, bool read1_write0, int32_t addr)
{
	//std::cout << "\n\n ===== CheckCacheSet =====";
	bool LocalHit = false;
	//printf("L1_index DEBUG OUT:   			%u\n", L1_index);
	//printf("this->ASSOC:   			%u\n", ASSOC);
	//ALSO CHECK FOR CACHE BLOCK VALIDITY IN THIS FUNCTION and AFTER GOTO tag compare
	for (int i = 0; i < /*this->*//*cache[lvl_].*/ASSOC; i++)
	{
		//printf("L1_index DEBUG IN:   			%u\n", L1_index);
//		if(lvl_)
//			printf("L2_tag HIT CHECK??:   			%u ====%u\n", cacheMatrix[L1_index][i].TAG, L1_tag);
		//printf("Cmat TAG DEBUG IN:   			%u\n", cacheMatrix[L1_index][i].TAG);

		if (/*cache[lvl_].*/cacheMatrix[L1_index][i].TAG == /*cache[lvl_].*/L1_tag)
		{
			if (!read1_write0) {
				/*cache[lvl_].*/cacheMatrix[L1_index][i].dirty_s = DIRTY;
			}
			//Update_LRU();
			L1_Read_HITT++;				//PUT CONDITION THAT IF IT IS r----> THEN READ MISS ELSE WRITE MISS
			LocalHit = true;
			//std::cout << LocalHit << std::endl;
			//Save the value of SAVE_num_ASSOC will be used lateron
//			printf("HITHITHIT :   			%u\n", i);
			FOUND_ASSOC = i;
			LRU_update_C(i);
			break;
		}
	}
	if (LocalHit) {
		/*if (L2_Exist) {

		}*/
		if (L1_Prefetch_Exist || L2_Prefetch_Exist)//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		{
			//std::cout << "L1_Read_Pre";
			int Hit_SB_i = 0;
			int Hit_SB_j = 0;
			//Initial case assumed--> L1 Prefetcher is prefilled.
			
			if (!CHECK_IF_SB_HIT(lvl_, Hit_SB_i, Hit_SB_j, addr, true))/*This is for L1 SB-->*/
			{
				Cache_Hit_N_SB_Miss_count++;
				//std::cout << "C->H and PF->Miss";
				//Perform_SB_Miss_logic(lvl_, addr);
				//Do Nothing

			}
		}
		else  // L2 and L1-Prefetch Nathi Valo case.
		{
			//Main_MEM_Traffic++;
		}


		//if(L2_Prefetch_Exist){
		//	int Hit_SB_i = 0;
		//	int Hit_SB_j = 0;
		//	if (!CHECK_IF_SB_HIT(lvl_, Hit_SB_i, Hit_SB_j, addr, false))/*This is for L2 SB-->*/
		//	{
		//		Perform_SB_Miss_logic(lvl_, addr);
		//	}
		//}
	}
#if 0
	if (!LocalHit)		//PUT CONDITION THAT IF IT IS r----> THEN READ MISS ELSE WRITE MISS
	{
		L1_Write_MISS++;	//Wrong place ment u need to put if (L1) elseif (L2)
		// Send read-request to Lower Cache Level
	}
#endif
	return LocalHit;
}

void Cache_c::L1_parsingCacheParams( int32_t addr, bool print /*= false*/, int lvl_ )
{
	//std::cout << "BEFORE" << lvl_ << std::endl;
	//std::cout << "Address: 0x" << std::hex << addr << std::dec << std::endl;
	//std::cout << "num_blockOffsetBits: " <<  /*cache[lvl_].*/num_blockOffsetBits << std::endl;
	//std::cout << "num_Index: " << /*cache[lvl_].*/num_Index << std::endl;

	// Calculate the mask for the block offset, index, and tag
    int32_t blockOffsetMask = (1 << /*cache[lvl_].*/num_blockOffsetBits) - 1;
	//int32_t tag_index = (addr >> num_blockOffsetBits);
    int32_t indexMask = (1 << /*cache[lvl_].*/num_Index) - 1;

    // Extract block offset
    /*cache[lvl_].*/L1_blockOffset /*L1L2_BlockOffset*/ = addr & blockOffsetMask;

    // Extract index
	/*cache[lvl_].*/L1_index/* L1L2_Index*/ = (addr >> /*cache[lvl_].*/num_blockOffsetBits) & indexMask;	//set_num
	///*cache[lvl_].*/L1_index/* L1L2_Index*/ = (tag_index & indexMask);

    // Extract tag
	/*cache[lvl_].*/L1_tag/*L1L2_Tag*/ = addr >> (/*cache[lvl_].*/num_blockOffsetBits + /*cache[lvl_].*/num_Index);		//tag_recvd
    // Print results
//	std::cout << "level" << lvl_ << std::endl;
	if (lvl_ == 1) {
//		std::cout << "Cache_Level" << lvl_ << std::endl;
//		std::cout << "Address: 0x" << std::hex << addr << std::dec << std::endl;
//		//std::cout << "L1_blockOffset: " << std::hex << /*cache[lvl_].*/L1_blockOffset << std::endl;
//		std::cout << "L1_index: " << std::hex << /*cache[lvl_].*/L1_index << std::endl;
//		std::cout << "L1_tag: " << std::hex << /*cache[lvl_].*/L1_tag << std::endl;
	}
	if(print)
	{
		
		// Output results	
		std::stringstream addr_string;
		addr_string<<addr;
		std::string hexAddress = addr_string.str();//"1234"; // Sample hexadecimal address
		uint32_t decimalAddress = Cache_c::hexToDecimal(hexAddress);
		std::string binaryAddress = Cache_c::decimalToBinary(decimalAddress);
		/* //Extra...													
		std::cout << "addr: " << addr << std::endl;
		std::cout << "Hex Address: " << hexAddress << std::endl;
		std::cout << "Decimal Address: " << decimalAddress << std::endl;
		std::cout << "Binary Address: " << binaryAddress << std::endl; */
	}
     
		
}
//bool Cache_c::CHECK_IF_SB_HIT(int lvl, int* Hit_SB_i, int* Hit_SB_j, int32_t addr)
//bool Cache_c::CHECK_IF_SB_HIT(int lvl, int Hit_SB_i, int Hit_SB_j, int32_t addr, bool hit_frm_Cache )

bool Cache_c::CHECK_IF_SB_HIT(int lvl, int Hit_SB_i, int Hit_SB_j, int32_t addr, bool hit_frm_Cache) {
	bool is_hit_SB = false;
	int MRU = PF_N + 1;  // Start with the highest possible LRU
	int hit_i = -1;
	int hit_j = -1;
	int tag = addr >> num_blockOffsetBits;

	// Scan through the stream buffers to find a hit and the least recently used buffer
	for (int i = 0; i < PF_N; i++) {
		if (StreamBuf[i][0].Valid_s_sb == VALID) {
			for (int j = 0; j < PF_M; j++) {
				if (StreamBuf[i][j].TAG_IDX_sb == tag) {
					// Hit found, update MRU and track hit location
					if (StreamBuf[i][0].LRU_sb <= MRU) {
						MRU = StreamBuf[i][0].LRU_sb;
						hit_i = i;
						hit_j = j;
						is_hit_SB = true;
					}
				}
			}
		}
	}

	// If a hit was found, proceed with the necessary updates
	if (is_hit_SB){//(hit_frm_Cache && is_hit_SB) || (!hit_frm_Cache && is_hit_SB)) {
		//Main_MEM_Traffic += hit_j;

		// Update prefetch counters based on cache level
		if (!lvl) {
			L1_prefetch += (hit_j+1);
		}
		else {
			L2_prefetch += (hit_j+1);
		}

		// Update stream buffer head and tags
		StreamBuf[hit_i][0].HEAD_sb = StreamBuf[hit_i][hit_j].TAG_IDX_sb;
		for (int k = 0; k < PF_M; k++) {
			StreamBuf[hit_i][k].TAG_IDX_sb = StreamBuf[hit_i][0].HEAD_sb + k + 1;
		}

		// Update LRU for the hit stream buffer
		SB_LRU_update_C(hit_i);
	}

	// Return true if a hit occurred in the stream buffer
	return is_hit_SB;
}




void Cache_c::updateStreamBuffer(int lvl, int32_t addr, int i , bool is_Cache_Hit)
{
	//std::cout << "StreamBuf[i][0].HEAD_sb Before" << StreamBuf[i][0].HEAD_sb << std::endl;

	StreamBuf[i][0].HEAD_sb = (addr >> num_blockOffsetBits);
	StreamBuf[i][0].Valid_s_sb = VALID;
	//std::cout << "StreamBuf[i][0].HEAD_sb After" << StreamBuf[i][0].HEAD_sb << std::endl;
	//std::cout << "addr" << std::hex << addr << std::endl;
	for (int j = 0; j < PF_M; j++) {

		StreamBuf[i][j].TAG_IDX_sb = StreamBuf[i][0].HEAD_sb + /*(*/j /*% Sets)*/ + 1;
		//Main_MEM_Traffic++;

		if (!lvl) {
			if (!is_Cache_Hit) {
				L1_prefetch++;
				Main_MEM_Traffic_L1_Pf++;
			}
		}
		else {
			if (!is_Cache_Hit) {
				L2_prefetch++;
				Main_MEM_Traffic_L2_Pf++;
			}
		}
	}
	/*for (int i = 0; i < PF_N; i++) {
		for (int j = 0; j < PF_M; j++) {
			std::cout << "" << StreamBuf[i][j].HEAD_sb;
		}
		std::cout << std::endl;
	}*/

}

void Cache_c::Perform_SB_Miss_logic(int lvl, int32_t addr, bool is_Cache_Hit, bool read1_write0)
{
	//iscompletlyEmpty = true;
	//Check if any stream Buffer empty
	for (int i = 0; i < PF_N; i++) {
		
		if (StreamBuf[i][0].Valid_s_sb == VALID) {
			iscompletlyEmpty = false;
		}
	}
	if (iscompletlyEmpty) {
		updateStreamBuffer(lvl,addr, 0, is_Cache_Hit);
		SB_LRU_update_C(0);
		//std::cout << "okokokok";
		iscompletlyEmpty = false;
		if (PF_N != 1)
			iscompletlyFull = false;
		else
			iscompletlyFull = true;

	}
	else if (!iscompletlyEmpty)
	{
		if (!iscompletlyFull)	//if yes 
		{
			for (int i = 0; i < PF_N; i++) {
				if (i == (PF_N - 1)) {
					iscompletlyFull = true;
				}

				if (StreamBuf[i][0].Valid_s_sb == NOT_VALID) {
					//then go serially and find the next Block and fill it up.
					// by calling updateBuffer function.
					updateStreamBuffer(lvl, addr, i, is_Cache_Hit);
					SB_LRU_update_C(i);
					break;
				}

				
			}


		}
		else
		{
			//find the LRU from the SB
			for (int i = 0; i < PF_N; i++) {
				if (StreamBuf[i][0].LRU_sb == (PF_N - 1)) {
				//Now implement the updateBuffer function.
					updateStreamBuffer(lvl, addr, i, is_Cache_Hit);
					SB_LRU_update_C(i);
					break;
				}
			
			}
		}
	
	}


}

void Cache_c::PerformMissLogic(int lvl, bool read1_write0, int32_t addr)
{
	if (/*cache[lvl].*/cacheMatrix[L1_index][0].cachesetEmpty){
		for (int i = 0; i < /*cache[lvl].*/(ASSOC); i++){
			if (/*cache[lvl].*/cacheMatrix[L1_index][i].Valid_s == NOT_VALID) {
//				std::cout << "Which way " << i << std::endl;
				//Perform the CPU Operation--> I know this seems weird but remember i found this logic while sleeping that day.
				/*cache[lvl].*/cacheMatrix[L1_index][i].TAG = /*cache[lvl].*/L1_tag;
				/*cache[lvl].*/cacheMatrix[L1_index][i].Valid_s = VALID;
				/*cache[lvl].*/cacheMatrix[L1_index][i].BLOCK_ADDR = addr;
//				std::cout << "cacheMatrix[L1_index][i].BLOCK_ADDR  " << std::hex <<cacheMatrix[L1_index][i].BLOCK_ADDR << std::endl;
				//Increse the Block Usage;
				//std::cout << "\n\n ===== cachesetEmpty is empty =====";
			//}
					    
				if (!read1_write0) {
					/*cache[lvl].*/cacheMatrix[L1_index][i].dirty_s = DIRTY;
//					if (lvl == 1)
//						std::cout << "\n\n ===== DIRTY is Printing cacheMatrix[L1_index][i].dirty_s =====" << cacheMatrix[L1_index][i].dirty_s << std::endl;
				}

				if (i == /*cache[lvl].*/ASSOC - 1) {
					/*cache[lvl].*/cacheMatrix[L1_index][0].cachesetEmpty = false;
				}

				//Update the L1 Read, Write Misses etc

				//IMP//Perform Write Call to L2 Cache
				if (!lvl) {		//IMP//-> if present in L1
					
					
					if (read1_write0) {		//IMP//If L1 read happens

						if (L2_Exist)
						{
					
							//IMP//If L2 is present so next state is L2.
							//LRU_update_C(i);		//IMP//This is LRU update for L1
							LRU_WB_ADDR = addr;//IMP// No need to implement WB here though // y? u ask cause L1 is empty soooo.. we are not checking dirty bit//OR//cacheMatrix[L1_index][i].BLOCK_ADDR;
							changeL1_2_L2 = true;//false;
							//break;
						}
						else
						{//When L2 is not existing.
							if (L1_Prefetch_Exist)//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
							{
								//std::cout << "L1_Read_Pre";
								int Hit_SB_i = 0;
								int Hit_SB_j = 0;
								//Initial case assumed--> L1 Prefetcher is prefilled.

								if (!CHECK_IF_SB_HIT(lvl, Hit_SB_i, Hit_SB_j, addr, false))/*This is for L1 SB-->*/
								{

									Perform_SB_Miss_logic(lvl, addr, false, read1_write0);
									L1_Read_miss++;
									Main_MEM_Traffic_L1_Miss_deamnd++;
								}
							}
							else  // L2 and L1-Prefetch Nathi Valo case.
							{
								Main_MEM_Traffic_WA2L1++;
								L1_WA_MM++;
							}
						}
					}
					else	/*L1- Writing*/
					{
						if(L2_Exist){
							//LRU_update_C(i);		//IMP//If L1 write happens
							changeL1_2_L2 = true;
							L1_WA_L2++;
							//break;
						}
						else
						{//When L2 is not existing.
							//std::cout << "L1_Write_Pre";
							//Initial case assumed--> L1 Prefetcher is prefilled.
							if (L1_Prefetch_Exist)	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
							{
								int Hit_SB_i = 0;
								int Hit_SB_j = 0;
								//Initial case assumed--> L1 Prefetcher is prefilled.

								if (!CHECK_IF_SB_HIT(lvl, Hit_SB_i, Hit_SB_j, addr , false))/*This is for L1 SB-->*/
								{
									//std::cout << "Am I goin here --->	";
									Perform_SB_Miss_logic(lvl, addr, false, read1_write0);
									L1_Write_MISS++;
									Main_MEM_Traffic_L1_Miss_deamnd++;
								}
							}
							else
							{
								Main_MEM_Traffic_WA2L1++;
								L1_WA_MM++;
							}
						}
						
					}
					//RorW_func(addr, true, 1 );
				}
				else   // This is L2
				{
					if (L2_Prefetch_Exist)
					{
						int Hit_SB_i = 0;
						int Hit_SB_j = 0;
						if (!CHECK_IF_SB_HIT(lvl, Hit_SB_i, Hit_SB_j, addr, false))/*This is for L2 SB-->*/
						{
							Main_MEM_Traffic_L2_Miss_deamnd++;
							if (read1_write0)
								L2_read_miss++;
							else
								L2_write_miss++;

							Perform_SB_Miss_logic(lvl, addr, false, read1_write0);
						}
						
					}
					else
					{
						Main_MEM_Traffic_WA2L2++;
						L2_WA_MM++;
						//Do nothing
						//\\Main_MEM_Traffic++;
					}
				}
				LRU_update_C(i);
				break;
			}
		}
	}

	else {

		for (int i = 0; i < /*cache[lvl].*/ASSOC; i++) {

			if (/*cache[lvl].*/cacheMatrix[L1_index][i].LRU == /*cache[lvl].*/(ASSOC -1)) {	//LRU
//				std::cout << "LRU == ASSOC -1 " << i << std::endl;
				if (/*cache[lvl].*/cacheMatrix[L1_index][i].dirty_s == DIRTY) {
					if (!lvl) {
						LRU_DIRTY_WB = true;
						/*cache[lvl].*/cacheMatrix[L1_index][i].dirty_s = CLEAN;
//						std::cout << "Bhai Cleaned " << i << std::endl;
						// Save my LRU Addr for WB.
						LRU_WB_ADDR = cacheMatrix[L1_index][i].BLOCK_ADDR;
//						std::cout << "LRU_WB_ADDR  " << LRU_WB_ADDR << std::endl;
			//RorW_func(cacheMatrix[L1_index][i].BLOCK_ADDR, false, 1);		//LRU wala Addr


						if (L2_Exist) {		//IMP//SB
							changeL1_2_L2 = true;
							/*L1_WriteBack += */L1_WB_L2++;
							L1_WA_L2++;
						}
						else {
							//VO BADA WALA UTHANA
							//Implement L1-SB
							if (L1_Prefetch_Exist)	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
							{
								int Hit_SB_i = 0; 
								int Hit_SB_j = 0;
								//Initial case assumed--> L1 Prefetcher is prefilled.

								if (!CHECK_IF_SB_HIT(lvl, Hit_SB_i, Hit_SB_j, addr, false))/*This is for L1 SB-->*/
								{
									/* Hit L1 SB
									Perform L1 SB Hit --> Perform prefetching from Main-Memory Only the upper wall if HIT.
									Perform_SB1_Case2_Logic();
									Perform_SB_Hit_logic(lvl, &Hit_SB_i, &Hit_SB_j);
								}*/
								
									//Miss L1 SB
									//Perform L1 SB Miss --> Perform prefetcher from memory
									if (read1_write0) {
										L1_Read_miss++;
										Main_MEM_Traffic_L1_Miss_deamnd++;
									}
									else {
										L1_Write_MISS++;
										Main_MEM_Traffic_L1_Miss_deamnd++;
									}
									Perform_SB_Miss_logic(lvl, addr, false, read1_write0);

								}
								////\\\\Main_MEM_Traffic++;
								////\\\\Main_MEM_Traffic++;
								L1_WB_MM++;
							}
							else
							{
								Main_MEM_Traffic_WB2L1++;// FOR WB
								Main_MEM_Traffic_WA2L1++;// FOR WA
								/*L1_WriteBack += */L1_WB_MM++;
								L1_WA_MM++;
							}
						}
						//break;
						
						
						//cache[1].RorW_func(/*addr*/cache[lvl].cacheMatrix[L1_Index][i].BLOCK_ADDR, false, 1);
						//cache[1].RorW_func(addr, false, 1);
					}
					else {	//Assume this functionality to be Write-Back to main MEM.			//For L2 logic
						/*cache[lvl].*/cacheMatrix[L1_index][i].dirty_s = CLEAN;
						//cache[lvl].cacheMatrix[L1_Index][i].TAG == CLEAN;
						//cache[lvl].cacheMatrix[L1_Index][i].BLOCK_ADDR == addr_LRU;
						if (L2_Prefetch_Exist)
						{
							int Hit_SB_i = 0;
							int Hit_SB_j = 0;
							if (!CHECK_IF_SB_HIT(lvl, Hit_SB_i, Hit_SB_j, addr, false))/*This is for L2 SB-->*/
							{
								if (read1_write0) {
									L2_read_miss++;
									Main_MEM_Traffic_L2_Miss_deamnd++;
								}
								else {
									L2_write_miss++;
									Main_MEM_Traffic_L2_Miss_deamnd++;
								}
								//Main_MEM_Traffic_L2_Miss_deamnd++;
								Perform_SB_Miss_logic(lvl, addr, false, read1_write0);
							}
							L2_WB_MM++;////\\\\//
						}
						else
						{
							//Do Nothing
							//Main_MEM_Traffic++;
							//Main_MEM_Traffic++;
							L2_WB_MM++;
							L2_WA_MM++;
							Main_MEM_Traffic_WB2L2++;
							Main_MEM_Traffic_WA2L2++;
						}
					}
						
				}
				else {	//IF clean che LRU
					if (!lvl) {
						if (L2_Exist) {	//IMP//SB
							changeL1_2_L2 = true;
							L1_WA_L2++;
						}
						else {
							//VO BADA VALA UTHANA
							if (L1_Prefetch_Exist)	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
							{
								int Hit_SB_i = 0;
								int Hit_SB_j = 0;
								//Initial case assumed--> L1 Prefetcher is prefilled.

								if (!CHECK_IF_SB_HIT(lvl, Hit_SB_i, Hit_SB_j, addr, false))/*This is for L1 SB-->*/
								{
									if (read1_write0) {
										L1_Read_miss++;
										Main_MEM_Traffic_L1_Miss_deamnd++;
									}
									else {
										L1_Write_MISS++;
										Main_MEM_Traffic_L1_Miss_deamnd++;
									}
									Perform_SB_Miss_logic(lvl, addr, false, read1_write0);

								}
							}
							else
							{
								Main_MEM_Traffic_WA2L1++;// FOR WA
								L1_WA_MM++;			   	 // For WA
							}
						}
					}/*DO-NOTHING*/

					else {	//Assume this functionality to be Write-Back to main MEM.			//For L2 logic
						
						if (L2_Prefetch_Exist)
						{
							int Hit_SB_i = 0;
							int Hit_SB_j = 0;
							if (!CHECK_IF_SB_HIT(lvl, Hit_SB_i, Hit_SB_j, addr, false))/*This is for L2 SB-->*/
							{
								if (read1_write0) {
									L2_read_miss++;
									Main_MEM_Traffic_L2_Miss_deamnd++;
								}
								else {
									L2_write_miss++;
									Main_MEM_Traffic_L2_Miss_deamnd++;
								}
								//Main_MEM_Traffic_L1_Miss_deamnd++;
								Perform_SB_Miss_logic(lvl, addr, false, read1_write0);
							}
						}
						else
						{
							//Do Nothing
							//Main_MEM_Traffic++;
							Main_MEM_Traffic_WA2L2++;
							L2_WA_MM++;
						}

					}
				}
				//FROM HERE EVERYTHING IS CLEAN IF U KNOW WHAT I MEAN
				//Insert block to cache
				//if (!lvl) {	//Perform Write Back operation from Main Memory to L2 of CPU addr.
				//	//RorW_func(addr, true, 1);	//CPU OP wala addr
				//	changeL1_2_L2 = true;
				//	std::cout << "Breaking OUT" << std::endl;
				//	break;
				//	//cache[1].RorW_func(addr, false, 1);
				//
				//}
				/*cache[lvl].*/cacheMatrix[L1_index][i].TAG = L1_tag;	//CPU Operation L1/L2
				/*cache[lvl].*/cacheMatrix[L1_index][i].BLOCK_ADDR = addr;	//CPU Operation L1/L2




				if (!read1_write0) {
					/*cache[lvl].*/cacheMatrix[L1_index][i].dirty_s = DIRTY;	//CPU OP L1/L2
//					std::cout << "SET DIRTY" << std::endl;
				}
				else {	//READ
					if (lvl) {
						/*cache[lvl].*/cacheMatrix[L1_index][i].dirty_s = CLEAN;		//IMP//Doing this twice see at line 405.
					}
					cacheMatrix[L1_index][i].dirty_s = CLEAN;
				}




				//LRU Update
				LRU_update_C(i);
				//std::cout << /*"Valid"  <<*/ cacheBlockValidToString(cacheMatrix[L1_index][i].Valid_s) << "	"
				//	<< cacheBlockDirtyToString(cacheMatrix[L1_index][i].dirty_s) << "	"
				//	<< std::hex << cacheMatrix[L1_index][i].TAG << std::dec << "	"
				//	<< "LRU" << "->" << cacheMatrix[L1_index][i].LRU << "||" << std::endl << std::endl << std::endl;

				break;
			}
		}
	}
		
}
void Cache_c::RorW_func(int32_t addr, bool read1_write0, int lvl)		
{
	//if (!LRU_TAG_ADDR)
	/*if (lvl == 0)
		std::cout << addr << std::endl;*/

	L1_parsingCacheParams(addr, false, lvl);			//I WANT THIS FUNCTION OUT FROM HERE----> WANT TO CALL ONLY ONCE>
	/*else
		newLRU_addr_Parsing(addr, false, lvl);*/
	if (!checkCacheSet( lvl, read1_write0, addr))	//Perform Hit Logic inside checkCacheSet Function.
	{
		//IMP//SB--> See if SB is available
		// also chech if 
//		std::cout << "\n\n ===== L1 Cache Miss =====" << std::endl;
		//bool HIT = false;
		if (!lvl) {
			if (read1_write0) {
				if (!L1_Prefetch_Exist)
				{
					L1_Read_miss++;
				}
			}
			else {
				if (!L1_Prefetch_Exist)
				{
					L1_Write_MISS++;
				}
			}

		}
		else {
			
			if (read1_write0) {
				if (!L2_Prefetch_Exist) {
					L2_read_miss++;
				}
			}
			else {
				if (!L2_Prefetch_Exist) {
					L2_write_miss++;
				}
			}
		}


		PerformMissLogic(lvl, read1_write0, addr);
	}
}

/*  "argc" holds the number of command-line arguments.
    "argv[]" holds the arguments themselves.

    Example:
    ./sim 32 8192 4 262144 8 3 10 gcc_trace.txt
    argc = 9
    argv[0] = "./sim"
    argv[1] = "32"
    argv[2] = "8192"
    ... and so on
*/
int main(int argc, char* argv[])
{
	FILE* fp;			// File pointer.
	char* trace_file;		// This variable holds the trace file name.
	cache_params_t params;	// Look at the sim.h header file for the definition of struct cache_params_t.
	char rw;			// This variable holds the request's type (read or write) obtained from the trace.
	uint32_t addr;		// This variable holds the request's address obtained from the trace.
	// The header file <inttypes.h> above defines signed and unsigned integers of various sizes in a machine-agnostic way.  "uint32_t" is an unsigned integer of 32 bits.

   //CacheBlock& block = cacheMatrix;



   // Exit with an error if the number of command-line arguments is incorrect.
	if (argc != 9) {
		printf("Error: Expected 8 command-line arguments but was provided %d.\n", (argc - 1));
		exit(EXIT_FAILURE);
	}

	// "atoi()" (included by <stdlib.h>) converts a string (char *) to an integer (int).
	params.BLOCKSIZE = (uint32_t)atoi(argv[1]);
	params.L1_SIZE = (uint32_t)atoi(argv[2]);
	params.L1_ASSOC = (uint32_t)atoi(argv[3]);
	params.L2_SIZE = (uint32_t)atoi(argv[4]);
	params.L2_ASSOC = (uint32_t)atoi(argv[5]);
	params.PREF_N = (uint32_t)atoi(argv[6]);
	params.PREF_M = (uint32_t)atoi(argv[7]);
	trace_file = argv[8];

	// Open the trace file for reading.
	fp = fopen(trace_file, "r");
	if (fp == (FILE*)NULL) {
		// Exit with an error if file open failed.
		printf("Error: Unable to open file %s\n", trace_file);
		exit(EXIT_FAILURE);
	}

	// Print simulator configuration.
	printf("===== Simulator configuration =====\n");
	printf("BLOCKSIZE:  %u\n", params.BLOCKSIZE);
	printf("L1_SIZE:    %u\n", params.L1_SIZE);
	printf("L1_ASSOC:   %u\n", params.L1_ASSOC);
	printf("L2_SIZE:    %u\n", params.L2_SIZE);
	printf("L2_ASSOC:   %u\n", params.L2_ASSOC);
	printf("PREF_N:     %u\n", params.PREF_N);
	printf("PREF_M:     %u\n", params.PREF_M);
	printf("trace_file: %s\n", trace_file);
	printf("\n");

	////##################################################################################################
	////##################################################################################################
	////##################################################################################################

	/* Cache_c L1(params.L1_SIZE, params.L1_ASSOC, params.BLOCKSIZE);
	Cache_c L2(params.L2_SIZE, params.L2_ASSOC, params.BLOCKSIZE); */
	//L1_Prefetch_Exist = false;
	//L2_Prefetch_Exist = false;
	//if ((params.PREF_M && params.PREF_N))
	//{
	//	L1_Prefetch_Exist = true;
	//	L2_Prefetch_Exist = true;
	//	//std::cout << "PF_N" << params.PREF_N;
	//	//std::cout << "PF_M" << params.PREF_M;
	//}

	//if (params.L2_SIZE != 0) {
	//	L2_Exist = true;
	//	if (!params.PREF_N) {
	//		L1_Prefetch_Exist = false;
	//		L2_Prefetch_Exist = false;
	//	}

	//}
	//else {
	//	L2_Exist = false;
	//	params.L2_SIZE = 1;
	//	params.L2_ASSOC = 1;
	//	L2_Prefetch_Exist = false;
	//	if(!params.PREF_N)
	//		L1_Prefetch_Exist = false;
	//	
	//	
	//}

	////

	//if (L1_Exist) {

	//	if (L2_Exist) {
	//		if (L2_Prefetch_Exist) {
	//			Cache_c cache
	//		}
	//	}
	//}
	//Cache_c cache[2] = { Cache_c(params.L1_SIZE, params.L1_ASSOC, params.BLOCKSIZE, params.PREF_N, params.PREF_M), // Initialize the first element
	//						Cache_c(params.L2_SIZE, params.L2_ASSOC, params.BLOCKSIZE, 0/*params.PREF_N*/, 0/*params.PREF_M*/) };
	L2_Exist = false;
	L1_Prefetch_Exist = false;
	L2_Prefetch_Exist = false;

	if (params.L2_SIZE) {
		L2_Exist = true;
		if (params.PREF_N) {
			L2_Prefetch_Exist = true;
		}
			 
	}
	else if (params.PREF_N) {
		L1_Prefetch_Exist = true;
	}
	
	Cache_c L1(params.L1_SIZE, params.L1_ASSOC, params.BLOCKSIZE,
		L1_Prefetch_Exist ? params.PREF_N : 0,
		L1_Prefetch_Exist ? params.PREF_M : 0); // Initialize L1

	Cache_c L2(L2_Exist ? params.L2_SIZE : 1, L2_Exist ? params.L2_ASSOC : 1,
		params.BLOCKSIZE, L2_Prefetch_Exist ? params.PREF_N : 0/*params.PREF_N*/,
		L2_Prefetch_Exist ? params.PREF_M : 0/*params.PREF_M*/); // Initialize L2 with default values if not existing

	//else {
	//	// L2 does not exist, so we initialize it with minimal or default values
	//	cache[1] = Cache_c(1, 1, params.BLOCKSIZE, 0, 0);
	//	std::cout << "L2 cache disabled, minimal values initialized." << std::endl;
	//}
	///////////////////////////////////////////////////////
	// Issue the request to the L1 cache instance here.
	///////////////////////////////////////////////////////

	while (fscanf(fp, "%c %x\n", &rw, &addr) == 2)
	{	// Stay in the loop if fscanf() successfully parsed two tokens as specified.
		if (rw == 'r')
		{
			L1_Read++;
//			printf("r %x\n", addr);
			CPU_ADDR = addr;
			//L1.RorW_func(CPU_ADDR,true,0);	//CPU Performs operation in L1 == 0;
			L1.RorW_func(addr,true,0);	//CPU Performs operation in L1 == 0;
			if (changeL1_2_L2 /*&& L2_Exist*//*&& L2_LRU*/) {
				if (L2_Exist) {
					//std::cout << "READ Went to L2";
					if (LRU_DIRTY_WB) {		//IMP//also add in this if condition && is empty.
						//					std::cout << "LRU_DIRTY_WB" << std::endl;
						//L1_WriteBack++;
						L2.RorW_func(LRU_WB_ADDR, false, 1);
						L2_writes++;
						LRU_DIRTY_WB = false;
						
					}
					//				std::cout << "L2 will READ " << std::endl;
					//				std::cout << "L2-->2" << addr << std::endl;
					//				std::cout << "L2-->3" << std::endl;
					L2.RorW_func(addr, true, 1);
					//LRU_Update(i);
					changeL1_2_L2 = false;
					L2_Read++;
				}
				/*else
					Main_MEM_Traffic++;*/
			}
			else {

			}
			//changeL1_2_L2 = false;

		}
		else if (rw == 'w')
		{
//			printf("w %x\n", addr);
			CPU_ADDR = addr;
			L1_Write++;
			//L1.RorW_func(CPU_ADDR,false,0);	//CPU Performs operation in L1 == 0;
			L1.RorW_func(addr,false,0);	//CPU Performs operation in L1 == 0;
			if (changeL1_2_L2 ) {
				if (L2_Exist)
				{
					if (LRU_DIRTY_WB) {		//IMP//also add in this if condition && is empty.
						//					std::cout << "LRU_DIRTY_WB" << std::endl;
						//					std::cout << "L2 will now WRITE" << std::endl;
						//L1_WriteBack++;
						L2.RorW_func(LRU_WB_ADDR, false, 1);
						L2_writes++;
						LRU_DIRTY_WB = false;
						
					}

					//				std::cout << "L2 will now READ" << std::endl;
					//				std::cout << "L2--> " << LRU_WB_ADDR << std::endl;
					//				std::cout << "L2--> " << std::endl;
					L2.RorW_func(addr/*OR->LRU_WB_ADDR*/, true, 1);//IMP//has to be true cause L2 will never write UNLESS L1 dose WB.
					changeL1_2_L2 = false;
					L2_Read++;
				}
				/*else
					Main_MEM_Traffic++;*/
			}
			//changeL1_2_L2 = false;
		}	
		else
		{
			printf("Error: Unknown request type %c.\n", rw);
			exit(EXIT_FAILURE);
		}

	}

	//if (!lvl) {
		if (L2_Exist)
		{
			//L1_WriteBack += L1_WB_L2;
			if (L2_Prefetch_Exist)
			{
				L1_WriteBack += L1_WB_L2;
				L2_WriteBack += L2_WB_MM;
				Main_MEM_Traffic = L2_read_miss + L2_write_miss + L2_WriteBack + L2_prefetch;//+ L2_WriteBack + L2_WA_MM + Main_MEM_Traffic_L1_Miss_deamnd;

			}
			else {
				L1_WriteBack += L1_WB_L2;
				L2_WriteBack += L2_WB_MM;
				Main_MEM_Traffic = Main_MEM_Traffic_WB2L2 + Main_MEM_Traffic_WA2L2;
			}
		}
		else
		{
			if (L1_Prefetch_Exist)
			{
				//if(read)
				// Do Nothing
				//L1_prefetcher += L1_prefetch;

				L1_WriteBack += L1_WB_MM;
				Main_MEM_Traffic = L1_WriteBack + L1_prefetch + Main_MEM_Traffic_L1_Miss_deamnd;
			}
			else {
				L1_WriteBack += Main_MEM_Traffic_WB2L1;		//Note in this case L1_WB_MM = Main_MEM_Traffic_WB2L1
				Main_MEM_Traffic += Main_MEM_Traffic_WB2L1 + Main_MEM_Traffic_WA2L1;
			}
		}
	//}
	/*else {

	}*/
	//std::cout << "\n\n ===== L1 contents =====";
	//for (int i = 0; i < L1.Sets; i++)
	//{
	//	std::cout << "\n  set   " << i << ":   ";
	//	//int assoc = L1.ASSOC + 1;
	//	for (int j = 0; j < L1.ASSOC; j++)
	//	{
	//		//if (L1.cacheMatrix[i][j].dirty_s == true) {
	//			//std::cout << "\n  set   " << i << ":   ";

	//			std::cout << /*"Valid"  <<*/ L1.cacheBlockValidToString(L1.cacheMatrix[i][j].Valid_s) << "	" << L1.cacheBlockDirtyToString(L1.cacheMatrix[i][j].dirty_s) << "	T" << std::hex << L1.cacheMatrix[i][j].TAG << std::dec << "	" << "L" << L1.cacheMatrix[i][j].LRU << "			||			";

	//		//}
	//		//else
	//			//std::cout << std::hex << L1.cacheMatrix[i][j].TAG << std::dec << "    ";
	//	}
	//}
	//std::cout << "\n\n HARDCODE PRINT L1 s0 ass1";
	//std::cout << /*"Valid"  <<*/ L1.cacheBlockValidToString(L1.cacheMatrix[0][1].Valid_s) << "	" << L1.cacheBlockDirtyToString(cache[0].cacheMatrix[0][1].dirty_s);
	 
	//std::cout << "\n\n ===== L1 contents =====";
	//for (int i = 0; i < L1.Sets; i++)
	//{

	//	std::cout << "\n  set   "<<i<< ":   ";


	//	//int assoc = L1.ASSOC + 1;
	//	for (int j = 0; j < L1.ASSOC; j++)
	//	{
	//		if (L1.cacheMatrix[i][j].dirty_s == true) {

	//			//std::cout << "\n  set   " << i << ":   ";

	//			//std::cout << /*"Valid"  <<*/ L1.cacheBlockValidToString(L1.cacheMatrix[i][j].Valid_s) << "	" << L1.cacheBlockDirtyToString(L1.cacheMatrix[i][j].dirty_s) << "	T" << std::hex << L1.cacheMatrix[i][j].TAG << std::dec << "	" << "L" << L1.cacheMatrix[i][j].LRU << "			||			";
	//			//for(int k = 0; k < L1.cacheMatrix[i][j].)
	//			std::cout << std::hex << L1.cacheMatrix[i][j].TAG << std::dec << " D  ";

	//		}
	//		else
	//			std::cout << std::hex << L1.cacheMatrix[i][j].TAG << std::dec << "    ";
	//	}
	//}

	std::cout << "===== L1 contents =====";
	for (int i = 0; i < L1.Sets; i++)
	{

		std::cout << "\nset   " << i << ":   ";


		//int assoc = L1.ASSOC + 1;
		if (L1.ASSOC > 1) {
			for (int j = 0; j < L1.ASSOC; j++)
			{
				for (int k = 0; k < L1.ASSOC - j - 1; k++)
					if (L1.cacheMatrix[i][k].LRU > L1.cacheMatrix[i][k + 1].LRU) {
						std::swap(L1.cacheMatrix[i][k], L1.cacheMatrix[i][k + 1]);
					}
				//if (L1.cacheMatrix[i][j].dirty_s == true) {

				//	//std::cout << "\n  set   " << i << ":   ";

				//	//std::cout << /*"Valid"  <<*/ L1.cacheBlockValidToString(L1.cacheMatrix[i][j].Valid_s) << "	" << L1.cacheBlockDirtyToString(L1.cacheMatrix[i][j].dirty_s) << "	T" << std::hex << L1.cacheMatrix[i][j].TAG << std::dec << "	" << "L" << L1.cacheMatrix[i][j].LRU << "			||			";
				//	//for(int k = 0; k < L1.cacheMatrix[i][j].)
				//	std::cout << std::hex << L1.cacheMatrix[i][j].TAG << std::dec << " D  ";

				//}
				//else
				//	std::cout << std::hex << L1.cacheMatrix[i][j].TAG << std::dec << "    ";

			}
		}
		for (int j = 0; j < L1.ASSOC; j++)
		{
			if (L1.cacheMatrix[i][j].dirty_s == true) {
				std::cout << std::hex << L1.cacheMatrix[i][j].TAG << std::dec << " D  ";

			}
			else
				std::cout << std::hex << L1.cacheMatrix[i][j].TAG << std::dec << "    ";

		}
		
	}
	std::cout << "\n";

	//if (L2_Exist) {////printf("Dirty:   		%s\n", L2.cacheBlockDirtyToString(L2.cacheMatrix[0][2].dirty_s)); */
	//	std::cout << "\n\n ===== L2 contents =====";
	//	for (int i = 0; i < L2.Sets; i++)
	//	{
	//		std::cout << "\n  set   " << i << ":   ";
	//		//int assoc = cache[0].ASSOC + 1;
	//		for (int j = 0; j < L2.ASSOC; j++)
	//		{
	//			if (L2.cacheMatrix[i][j].dirty_s == true) {

	//				//std::cout << "\n  set   " << i << ":   ";
	//				//std::cout << /*"Valid"  <<*/ L2.cacheBlockValidToString(L2.cacheMatrix[i][j].Valid_s) << "	" << L2.cacheBlockDirtyToString(L2.cacheMatrix[i][j].dirty_s) << "	T" << std::hex << L2.cacheMatrix[i][j].TAG << std::dec << "	" << "L" << L2.cacheMatrix[i][j].LRU << "			||			";
	//				std::cout << std::hex << L2.cacheMatrix[i][j].TAG << std::dec << " D  ";
	//			}
	//			else
	//				std::cout << std::hex << L2.cacheMatrix[i][j].TAG << std::dec << "    ";
	//		}
	//	}
	//}
	






	if (L2_Exist)
	{
		std::cout << "\n===== L2 contents =====";
		for (int i = 0; i < L2.Sets; i++)
		{

			std::cout << "\nset   " << i << ":   ";


			//int assoc = L1.ASSOC + 1;
			if (L2.ASSOC > 1) {
				for (int j = 0; j < L2.ASSOC; j++)
				{
					for (int k = 0; k < L2.ASSOC - j - 1; k++)
						if (L2.cacheMatrix[i][k].LRU > L2.cacheMatrix[i][k + 1].LRU) {
							std::swap(L2.cacheMatrix[i][k], L2.cacheMatrix[i][k + 1]);
						}
					//if (L1.cacheMatrix[i][j].dirty_s == true) {

					//	//std::cout << "\n  set   " << i << ":   ";

					//	//std::cout << /*"Valid"  <<*/ L1.cacheBlockValidToString(L1.cacheMatrix[i][j].Valid_s) << "	" << L1.cacheBlockDirtyToString(L1.cacheMatrix[i][j].dirty_s) << "	T" << std::hex << L1.cacheMatrix[i][j].TAG << std::dec << "	" << "L" << L1.cacheMatrix[i][j].LRU << "			||			";
					//	//for(int k = 0; k < L1.cacheMatrix[i][j].)
					//	std::cout << std::hex << L1.cacheMatrix[i][j].TAG << std::dec << " D  ";

					//}
					//else
					//	std::cout << std::hex << L1.cacheMatrix[i][j].TAG << std::dec << "    ";

				}
			}
			for (int j = 0; j < L2.ASSOC; j++)
			{
				if (L2.cacheMatrix[i][j].Valid_s) {  // Check if the entry is valid
					if (L2.cacheMatrix[i][j].dirty_s == true) {
						std::cout << std::hex << L2.cacheMatrix[i][j].TAG << std::dec << " D  ";

					}
					else
						std::cout << std::hex << L2.cacheMatrix[i][j].TAG << std::dec << "    ";
				}
				/*else {
					std::cout << "       ";
				}*/


			}
		}
		std::cout << "\n";
	}

	//if (L1_Prefetch_Exist)
	//{
	//	std::cout << "\n\n===== Stream Buffer(s) contents ===== \n";
	//	for (int i = 0; i < params.PREF_N; i++)
	//	{
	//		if (L2.ASSOC > 1) {

	//			for (int k = 0; k < params.PREF_N - i - 1; k++)
	//			{
	//				if (L1.StreamBuf[k][0].LRU_sb > L2.StreamBuf[k + 1][0].LRU_sb) {
	//					std::swap(L2.StreamBuf[k][0], L2.StreamBuf[k + 1][0]);
	//				}
	//			}
	//		} 
	//	}
	//	for (int i = 0; i < params.PREF_N; i++)
	//	{
	//		if (L1.StreamBuf[i][0].Valid_s_sb == true)
	//		{
	//			//std::cout << "\n\n===== Stream Buffer(s) contents ===== \n";
	//			for (int j = 0; j < params.PREF_M; j++) {
	//				std::cout << "   " << std::hex << L1.StreamBuf[i][j].TAG_IDX_sb;// << /*dec << " D "*/;
	//			}

	//		}
	//		//std::cout << "->LRU   " /*<< std::hex*/ << L1.StreamBuf[i][0].LRU_sb;// << /*dec << " D "*/;
	//		std::cout << std::endl;
	//		/*else
	//			cout << "   " << hex << L1.victim_L1[i].block_address << dec;*/
	//	}
	//}

	//if (L1_Prefetch_Exist) {
	//	std::cout << "\n\n===== Stream Buffer(s) contents ===== \n";

	//	// Sorting logic if L2.ASSOC > 1
	//	if (L2.ASSOC > 1) {
	//		for (int k = 0; k < params.PREF_N - 1; k++) {
	//			for (int j = 0; j < params.PREF_N - k - 1; j++) {
	//				if (L1.StreamBuf[j][0].LRU_sb > L1.StreamBuf[j + 1][0].LRU_sb) {
	//					std::swap(L1.StreamBuf[j][0], L1.StreamBuf[j + 1][0]);
	//				}
	//			}
	//		}
	//	}

	//	// Printing the contents of the Stream Buffer
	//	for (int i = 0; i < params.PREF_N; i++) {
	//		if (L1.StreamBuf[i][0].Valid_s_sb) {
	//			for (int j = 0; j < params.PREF_M; j++) {
	//				std::cout << "   " << std::hex << L1.StreamBuf[i][j].TAG_IDX_sb;
	//			}
	//			std::cout << std::endl; // Print a new line after each valid entry
	//		}
	//	}
	//}

	if (L1_Prefetch_Exist) {
		std::cout << "\n===== Stream Buffer(s) contents ===== \n";

		// Sorting logic if L2.ASSOC > 1
		if (params.PREF_N > 1 ) {
			for (int k = 0; k < params.PREF_N - 1; k++) {
				for (int j = 0; j < params.PREF_N - k - 1; j++) {
					if (L1.StreamBuf[j][0].LRU_sb > L1.StreamBuf[j + 1][0].LRU_sb) {
						for(int l = 0; l < params.PREF_M; l++)
							std::swap(L1.StreamBuf[j][l], L1.StreamBuf[j + 1][l]);
					}
				}
			}
		}

		// Printing the contents of the Stream Buffer
		for (int i = 0; i < params.PREF_N; i++) {
			if (L1.StreamBuf[i][0].Valid_s_sb) {
				for (int j = 0; j < params.PREF_M; j++) {
					// Print the TAG_IDX_sb with leading spaces for alignment
					std::cout << "  " << std::hex << L1.StreamBuf[i][j].TAG_IDX_sb /*<< std::dec << std::endl*/;
				}
			}
			std::cout << std::endl;
		}
	}


	//if (L2_Exist) {
	//	std::cout << "\n\n ===== L2 contents =====";
	//	for (int i = 0; i < L2.Sets; i++) {
	//		std::cout << "\n  set   " << i << ":   ";

	//		// Sort cache blocks by LRU if ASSOC > 1
	//		if (L2.ASSOC > 1) {
	//			for (int j = 0; j < L2.ASSOC - 1; j++) {  // Adjusted loop condition
	//				for (int k = 0; k < L2.ASSOC - j - 1; k++) {
	//					if (L2.cacheMatrix[i][k].LRU > L2.cacheMatrix[i][k + 1].LRU) {
	//						std::swap(L2.cacheMatrix[i][k], L2.cacheMatrix[i][k + 1]);
	//					}
	//				}
	//			}
	//		}

	//		// Print the contents
	//		for (int j = 0; j < L2.ASSOC; j++) {
	//			if (L2.cacheMatrix[i][j].Valid_s) {  // Check if the entry is valid
	//				if (L2.cacheMatrix[i][j].dirty_s) {
	//					std::cout << std::hex << L2.cacheMatrix[i][j].TAG << std::dec << " D  ";
	//				}
	//				else {
	//					std::cout << std::hex << L2.cacheMatrix[i][j].TAG << std::dec << "    ";
	//				}
	//			}
	//			else {
	//				std::cout << "       ";  // Placeholder for invalid entries
	//			}
	//		}
	//	}
	//}




	

	//if (L2_Prefetch_Exist) {
	//	std::cout << "\n\n===== Stream Buffer(s) contents ===== \n";
	//	for (int i = 0; i < params.PREF_N; i++)
	//	{
	//		if (L2.StreamBuf[i][0].Valid_s_sb == true)
	//		{
	//			//std::cout << "\n\n===== Stream Buffer(s) contents ===== \n";
	//			for (int j = 0; j < params.PREF_M; j++)
	//				std::cout << "   " << std::hex << L2.StreamBuf[i][j].TAG_IDX_sb;// << /*dec << " D "*/;

	//		}
	//		//std::cout << "->LRU   " /*<< std::hex*/ << L2.StreamBuf[i][0].LRU_sb;// << /*dec << " D "*/;
	//		std::cout << std::endl;
	//		/*else
	//			cout << "   " << hex << L1.victim_L1[i].block_address << dec;*/
	//	}
	//}
	if (L2_Prefetch_Exist) {
		std::cout << "\n===== Stream Buffer(s) contents ===== \n";

		// Sorting logic if L2.ASSOC > 1
		if (params.PREF_N > 1) {
			for (int k = 0; k < params.PREF_N ; k++) {
				for (int j = 0; j < params.PREF_N - k - 1; j++) {
					if (L2.StreamBuf[j][0].LRU_sb > L2.StreamBuf[j + 1][0].LRU_sb) {
						for(int l = 0; l < params.PREF_M; l++)
							std::swap(L2.StreamBuf[j][l], L2.StreamBuf[j + 1][l]);
					}
				}
			}
		}

		// Printing the contents of the Stream Buffer
		for (int i = 0; i < params.PREF_N; i++) {
			if (L2.StreamBuf[i][0].Valid_s_sb) {
				for (int j = 0; j < params.PREF_M; j++) {
					// Print the TAG_IDX_sb with leading spaces for alignment
					std::cout << "  " << std::hex << L2.StreamBuf[i][j].TAG_IDX_sb /*<< std::dec << std::endl*/;
				}
			}
			std::cout << std::endl;
		}
	}

	
	std::cout << "\n===== Measurements =====";
	std::cout << "\na. L1 reads:			" << std::dec << L1_Read;
	std::cout << "\nb. L1 read misses:		" << L1_Read_miss;
	std::cout << "\nc. L1 writes:			" << L1_Write;
	std::cout << "\nd. L1 write misses:		" << L1_Write_MISS;
	std::cout << "\ne. L1 miss rate:		"<< std::fixed<<std::setprecision(4)<<(((double)L1_Read_miss + L1_Write_MISS) / (L1_Read + L1_Write));
	std::cout << "\nf. L1 writebacks:		" << L1_WriteBack;
	std::cout << "\ng. L1 prefetches:		" << L1_prefetch;
	std::cout << "\nh. L2 reads (demand):		" << L2_Read;
	std::cout << "\ni. L2 read misses (demand):	" << L2_read_miss;
	std::cout << "\nj. L2 reads (prefetch):		" << 0;//<< L2_prefetch;
	std::cout << "\nk. L2 read misses (prefetch):  " << 0;//<< L2_prefetch;
	std::cout << "\nl. L2 writes:			" << L2_writes;
	std::cout << "\nm. L2 write misses:		" << L2_write_miss;
	double temp_miss_rate = 0;
	if (L2_Exist)
	{
		temp_miss_rate = ((double)L2_read_miss / L2_Read);
	}
	std::cout << "\nn. L2 miss rate:		" <<std::fixed << std::setprecision(4) << temp_miss_rate;
	std::cout << "\no. L2 writebacks:		" << L2_WriteBack;
	std::cout << "\np. L2 prefetches:		" << L2_prefetch;
	std::cout << "\nq. memory traffic:		" << Main_MEM_Traffic;

	return(0);

}