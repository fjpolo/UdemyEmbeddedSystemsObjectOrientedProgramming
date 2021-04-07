#ifndef __MCAL_REG_H
#define __MCAL_REG_H

#include <cstdint>
#include "mcal_reg_access.h"
#include "mcal_reg_access_dynamic.h"


namespace mcal{
	namespace reg{
		// Global base addresses
		const std::uint32_t periph_base							= 0x40000000U;
		
		// Individual unit base addresses
		const std::uint32_t ahb1_periph_base			= periph_base + 0x00020000U;
		const std::uint32_t rcc_base							= periph_base + 0x00003800U;
		const std::uint32_t ahb1enr								= rcc_base + 0x0030U;
		const std::uint32_t ahb2enr								= rcc_base + 0x0034U;
		const std::uint32_t ahb3enr								= rcc_base + 0x0038U;
		const std::uint32_t apb1enr								= rcc_base + 0x0040U; 			
		const std::uint32_t apb2enr								= rcc_base + 0x0044U; 			
		
		//
		const std::uint32_t gpioa_base						= ahb1_periph_base + 0x0000U;
		const std::uint32_t gpiob_base						= ahb1_periph_base + 0x0400U;
		const std::uint32_t gpioc_base						= ahb1_periph_base + 0x0800U;
		const std::uint32_t gpiod_base						= ahb1_periph_base + 0x0C00U;
		const std::uint32_t gpioe_base						= ahb1_periph_base + 0x1000U;
		const std::uint32_t gpiof_base						= ahb1_periph_base + 0x1400U;
		const std::uint32_t gpiog_base						= ahb1_periph_base + 0x1800U;
		const std::uint32_t gpioh_base						= ahb1_periph_base + 0x1C00U;
		const std::uint32_t gpioi_base						= ahb1_periph_base + 0x2000U;
		
		// USART base addresses - APB1
		
		// USART base addresses - APB2
		const std::uint32_t uart1_base						= periph_base + 0x11000U;	// USART1 - 0x4001 1000
		const std::uint32_t uart6_base						= periph_base + 0x11400U;	// USART6 - 0x4001 1400
		
		// SysTick Base address
		const std::uint32_t scb_base							= 0xE000E000U;
		const std::uint32_t systick_base 					= scb_base + 0x010U;
		
		// TIM2 Base Address
		const std::uint32_t tim2_base							= periph_base;
		// TIM3 Base Address
		const std::uint32_t tim3_base							= periph_base + 0x0400U;
		
		//ADC base
		const std::uint32_t adc1_base							= periph_base + 0x00012000U;
		



		// USART registers
		const std::uint32_t sr_offset							= 0x00U;
		const std::uint32_t dr_offset							= 0x04U;
		const std::uint32_t brr_offset						= 0x08U;
		const std::uint32_t cr1_offset						= 0x0CU;
		const std::uint32_t cr2_offset						= 0x10U;
		const std::uint32_t cr3_offset						= 0x14U;
		const std::uint32_t gtpr_offset						= 0x18U;

		const std::uint32_t uart6_sr							= uart6_base + sr_offset;
		const std::uint32_t uart6_dr							= uart6_base + dr_offset;
		const std::uint32_t uart6_brr							= uart6_base + brr_offset;
		const std::uint32_t uart6_cr1							= uart6_base + cr1_offset;
		const std::uint32_t uart6_cr2							= uart6_base + cr2_offset;
		const std::uint32_t uart6_cr3							= uart6_base + cr3_offset;
		const std::uint32_t uart6_gtpr						= uart6_base + gtpr_offset;
		
		// Port registers
		const std::uint32_t moder_offset					= 0x00U;
		const std::uint32_t otyper_offset					= 0x004;
		const std::uint32_t ospeedr_offset					= 0x08U;
		const std::uint32_t pupdr_offset					= 0x0CU;
		const std::uint32_t idr_offset						= 0x10U;
		const std::uint32_t odr_offset						= 0x14U;
		const std::uint32_t bssr_offset						= 0x18U;
		const std::uint32_t lckr_offset						= 0x1CU;
		const std::uint32_t afrl_offset						= 0x20U;
		const std::uint32_t afrh_offset						= 0x24U;
		
		// USART registers
		typedef struct{
			volatile std::uint32_t SR;
			volatile std::uint32_t DR;
			volatile std::uint32_t BRR;
			volatile std::uint32_t CR1;
			volatile std::uint32_t CR2;
			volatile std::uint32_t CR3;
			volatile std::uint32_t GTPR;
		}USART_TypeDef;
		
		//
		//		#define UART1														((USART_TypeDef*)mcal::reg::uart1_base)
		//		#define UART6														((USART_TypeDef*)mcal::reg::uart6_base)
//		USART_TypeDef *	UART6 =  ((USART_TypeDef*)mcal::reg::uart6_base);

		// GPIOA
		const std::uint32_t gpioa_moder						= gpioa_base + moder_offset;
		const std::uint32_t gpioa_otyper					= gpioa_base + otyper_offset;
		const std::uint32_t gpioa_ospeedr					= gpioa_base + ospeedr_offset;
		const std::uint32_t gpioa_pupdr						= gpioa_base + pupdr_offset;
		const std::uint32_t gpioa_idr							= gpioa_base + idr_offset;
		const std::uint32_t gpioa_odr							= gpioa_base + odr_offset;
		const std::uint32_t gpioa_bssr						= gpioa_base + bssr_offset;
		const std::uint32_t gpioa_lckr						= gpioa_base + lckr_offset;
		const std::uint32_t gpioa_afrl						= gpioa_base + afrl_offset;
		const std::uint32_t gpioa_afrh						= gpioa_base + afrh_offset;
		
		// GPIOB
		const std::uint32_t gpiob_moder						= gpiob_base + moder_offset;
		const std::uint32_t gpiob_otyper					= gpiob_base + otyper_offset;
		const std::uint32_t gpiob_ospeedr					= gpiob_base + ospeedr_offset;
		const std::uint32_t gpiob_pupdr						= gpiob_base + pupdr_offset;
		const std::uint32_t gpiob_idr							= gpiob_base + idr_offset;
		const std::uint32_t gpiob_odr							= gpiob_base + odr_offset;
		const std::uint32_t gpiob_bssr						= gpiob_base + bssr_offset;
		const std::uint32_t gpiob_lckr						= gpiob_base + lckr_offset;
		const std::uint32_t gpiob_afrl						= gpiob_base + afrl_offset;
		const std::uint32_t gpiob_afrh						= gpiob_base + afrh_offset;
		
		// GPIOC
		const std::uint32_t gpioc_moder						= gpioc_base + moder_offset;
		const std::uint32_t gpioc_otyper					= gpioc_base + otyper_offset;
		const std::uint32_t gpioc_ospeedr					= gpioc_base + ospeedr_offset;
		const std::uint32_t gpioc_pupdr						= gpioc_base + pupdr_offset;
		const std::uint32_t gpioc_idr							= gpioc_base + idr_offset;
		const std::uint32_t gpioc_odr							= gpioc_base + odr_offset;
		const std::uint32_t gpioc_bssr						= gpioc_base + bssr_offset;
		const std::uint32_t gpioc_lckr						= gpioc_base + lckr_offset;
		const std::uint32_t gpioc_afrl						= gpioc_base + afrl_offset;
		const std::uint32_t gpioc_afrh						= gpioc_base + afrh_offset;
		
		// GPIOD
		const std::uint32_t gpiod_moder						= gpiod_base + moder_offset;
		const std::uint32_t gpiod_otyper					= gpiod_base + otyper_offset;
		const std::uint32_t gpiod_ospeedr					= gpiod_base + ospeedr_offset;
		const std::uint32_t gpiod_pupdr						= gpiod_base + pupdr_offset;
		const std::uint32_t gpiod_idr							= gpiod_base + idr_offset;
		const std::uint32_t gpiod_odr							= gpiod_base + odr_offset;
		const std::uint32_t gpiod_bssr						= gpiod_base + bssr_offset;
		const std::uint32_t gpiod_lckr						= gpiod_base + lckr_offset;
		const std::uint32_t gpiod_afrl						= gpiod_base + afrl_offset;
		const std::uint32_t gpiod_afrh						= gpiod_base + afrh_offset;
	
		// GPIOE
		const std::uint32_t gpioe_moder						= gpioe_base + moder_offset;
		const std::uint32_t gpioe_otyper					= gpioe_base + otyper_offset;
		const std::uint32_t gpioe_ospeedr					= gpioe_base + ospeedr_offset;
		const std::uint32_t gpioe_pupdr						= gpioe_base + pupdr_offset;
		const std::uint32_t gpioe_idr							= gpioe_base + idr_offset;
		const std::uint32_t gpioe_odr							= gpioe_base + odr_offset;
		const std::uint32_t gpioe_bssr						= gpioe_base + bssr_offset;
		const std::uint32_t gpioe_lckr						= gpioe_base + lckr_offset;
		const std::uint32_t gpioe_afrl						= gpioe_base + afrl_offset;
		const std::uint32_t gpioe_afrh						= gpioe_base + afrh_offset;

		// GPIOF
		const std::uint32_t gpiof_moder						= gpiof_base + moder_offset;
		const std::uint32_t gpiof_otyper					= gpiof_base + otyper_offset;
		const std::uint32_t gpiof_ospeedr					= gpiof_base + ospeedr_offset;
		const std::uint32_t gpiof_pupdr						= gpiof_base + pupdr_offset;
		const std::uint32_t gpiof_idr							= gpiof_base + idr_offset;
		const std::uint32_t gpiof_odr							= gpiof_base + odr_offset;
		const std::uint32_t gpiof_bssr						= gpiof_base + bssr_offset;
		const std::uint32_t gpiof_lckr						= gpiof_base + lckr_offset;
		const std::uint32_t gpiof_afrl						= gpiof_base + afrl_offset;
		const std::uint32_t gpiof_afrh						= gpiof_base + afrh_offset;
		
		// GPIOG
		const std::uint32_t gpiog_moder						= gpiog_base + moder_offset;
		const std::uint32_t gpiog_otyper					= gpiog_base + otyper_offset;
		const std::uint32_t gpiog_ospeedr					= gpiog_base + ospeedr_offset;
		const std::uint32_t gpiog_pupdr						= gpiog_base + pupdr_offset;
		const std::uint32_t gpiog_idr							= gpiog_base + idr_offset;
		const std::uint32_t gpiog_odr							= gpiog_base + odr_offset;
		const std::uint32_t gpiog_bssr						= gpiog_base + bssr_offset;
		const std::uint32_t gpiog_lckr						= gpiog_base + lckr_offset;
		const std::uint32_t gpiog_afrl						= gpiog_base + afrl_offset;
		const std::uint32_t gpiog_afrh						= gpiog_base + afrh_offset;
		
		// GPIOH
		const std::uint32_t gpioh_moder						= gpioh_base + moder_offset;
		const std::uint32_t gpioh_otyper					= gpioh_base + otyper_offset;
		const std::uint32_t gpioh_ospeedr					= gpioh_base + ospeedr_offset;
		const std::uint32_t gpioh_pupdr						= gpioh_base + pupdr_offset;
		const std::uint32_t gpioh_idr							= gpioh_base + idr_offset;
		const std::uint32_t gpioh_odr							= gpioh_base + odr_offset;
		const std::uint32_t gpioh_bssr						= gpioh_base + bssr_offset;
		const std::uint32_t gpioh_lckr						= gpioh_base + lckr_offset;
		const std::uint32_t gpioh_afrl						= gpioh_base + afrl_offset;
		const std::uint32_t gpioh_afrh						= gpioh_base + afrh_offset;
		
		// GPIOI
		const std::uint32_t gpioi_moder						= gpioi_base + moder_offset;
		const std::uint32_t gpioi_otyper					= gpioi_base + otyper_offset;
		const std::uint32_t gpioi_ospeedr					= gpioi_base + ospeedr_offset;
		const std::uint32_t gpioi_pupdr						= gpioi_base + pupdr_offset;
		const std::uint32_t gpioi_idr							= gpioi_base + idr_offset;
		const std::uint32_t gpioi_odr							= gpioi_base + odr_offset;
		const std::uint32_t gpioi_bssr						= gpioi_base + bssr_offset;
		const std::uint32_t gpioi_lckr						= gpioi_base + lckr_offset;
		const std::uint32_t gpioi_afrl						= gpioi_base + afrl_offset;
		const std::uint32_t gpioi_afrh						= gpioi_base + afrh_offset;

		// SysTick Registers offsets
		const std::uint32_t ctrl_offset						= 0x0000U;
		const std::uint32_t load_offset						= 0x0004U;
		const std::uint32_t val_offset						= 0x0008U;	
		const std::uint32_t calib_offset					= 0x000CU;

		// SysTick Registers
		const std::uint32_t systick_ctrl					= systick_base + ctrl_offset;
		const std::uint32_t systick_load					= systick_base + load_offset;
		const std::uint32_t systick_val						= systick_base + val_offset;	
		const std::uint32_t systick_calib					= systick_base + calib_offset;

		// SysTick Registers struct
		typedef struct{
			volatile std::uint32_t	CTRL;
			volatile std::uint32_t	LOAD;
			volatile std::uint32_t	VAL;
			volatile std::uint32_t	CALIB;
		}SYSTICK_TypeDef;
		
//		// SysTick Registers struct pointer
//		SYSTICK_TypeDef * SYSTICK = ((SYSTICK_TypeDef *)mcal::reg::systick_base);
		
		// TIM2 registers offsets	
		const std::uint32_t tim_cr1_offset				= 0x00U;
		const std::uint32_t tim_cr2_offset				= 0x04U;
		const std::uint32_t tim_smcr_offset				= 0x08U;
		const std::uint32_t tim_dier_offset				= 0x0CU;
		const std::uint32_t tim_sr_offset					= 0x10U;
		const std::uint32_t tim_egr_offset				= 0x14U;
		const std::uint32_t tim_ccmr1_offset			= 0x18U;
		const std::uint32_t tim_ccmr2_offset			= 0x1CU;
		const std::uint32_t tim_ccer_offset				= 0x20U;
		const std::uint32_t tim_cnt_offset				= 0x24U;
		const std::uint32_t tim_psc_offset				= 0x28U;
		const std::uint32_t tim_arr_offset				= 0x2CU;
		const std::uint32_t tim_ccr1_offset				= 0x34U;
		const std::uint32_t tim_ccr2_offset				= 0x38U;
		const std::uint32_t tim_ccr3_offset				= 0x3CU;
		const std::uint32_t tim_ccr4_offset				= 0x40U;
		const std::uint32_t tim_dcr_offset				= 0x48U;
		const std::uint32_t tim_dmar_offset				= 0x4CU;
		const std::uint32_t tim_or_offset					= 0x50U;
		
		// TIM2 registers		
		const std::uint32_t tim2_cr1							= tim2_base + tim_cr1_offset;
		const std::uint32_t tim2_cr2							= tim2_base + tim_cr2_offset;
		const std::uint32_t tim2_smcr							= tim2_base + tim_smcr_offset;
		const std::uint32_t tim2_dier							= tim2_base + tim_dier_offset;
		const std::uint32_t tim2_sr								= tim2_base + tim_sr_offset;
		const std::uint32_t tim2_egr							= tim2_base + tim_egr_offset;
		const std::uint32_t tim2_ccmr1						= tim2_base + tim_ccmr1_offset;
		const std::uint32_t tim2_ccmr2						= tim2_base + tim_ccmr2_offset;
		const std::uint32_t tim2_ccer							= tim2_base + tim_ccer_offset;
		const std::uint32_t tim2_cnt							= tim2_base + tim_cnt_offset;
		const std::uint32_t tim2_psc							= tim2_base + tim_psc_offset;
		const std::uint32_t tim2_arr							= tim2_base + tim_arr_offset;
		const std::uint32_t tim2_ccr1							= tim2_base + tim_ccr1_offset;
		const std::uint32_t tim2_ccr2							= tim2_base + tim_ccr2_offset;
		const std::uint32_t tim2_ccr3							= tim2_base + tim_ccr3_offset;
		const std::uint32_t tim2_ccr4							= tim2_base + tim_ccr4_offset;
		const std::uint32_t tim2_dcr							= tim2_base + tim_dcr_offset;
		const std::uint32_t tim2_dmar							= tim2_base + tim_dmar_offset;
		const std::uint32_t tim2_or								= tim2_base + tim_or_offset;
		
		
		// TIM2 registers	struct
		typedef struct{
				volatile std::uint32_t CR1;							/*!<TIM xx Register, Address offset: 0xXX>*/
				volatile std::uint32_t CR2;							/*!<TIM xx Register, Address offset: 0xXX>*/
				volatile std::uint32_t SMCR;						/*!<TIM xx Register, Address offset: 0xXX>*/
				volatile std::uint32_t DIER;						/*!<TIM xx Register, Address offset: 0xXX>*/
				volatile std::uint32_t SR;							/*!<TIM xx Register, Address offset: 0xXX>*/
				volatile std::uint32_t EGR;							/*!<TIM xx Register, Address offset: 0xXX>*/
				volatile std::uint32_t CCRM1;						/*!<TIM xx Register, Address offset: 0xXX>*/
				volatile std::uint32_t CCRM2;						/*!<TIM xx Register, Address offset: 0xXX>*/
				volatile std::uint32_t CCER;						/*!<TIM xx Register, Address offset: 0xXX>*/
				volatile std::uint32_t CNT;							/*!<TIM xx Register, Address offset: 0xXX>*/
				volatile std::uint32_t PSC;							/*!<TIM xx Register, Address offset: 0xXX>*/
				volatile std::uint32_t ARR;							/*!<TIM xx Register, Address offset: 0xXX>*/
//				volatile std::uint32_t RCR;							/*!<TIM xx Register, Address offset: 0xXX>*/
				volatile std::uint32_t CCR1;						/*!<TIM xx Register, Address offset: 0xXX>*/
				volatile std::uint32_t CCR2;						/*!<TIM xx Register, Address offset: 0xXX>*/
				volatile std::uint32_t CCR3;						/*!<TIM xx Register, Address offset: 0xXX>*/
				volatile std::uint32_t CCR4;						/*!<TIM xx Register, Address offset: 0xXX>*/
//				volatile std::uint32_t BDTR;						/*!<TIM xx Register, Address offset: 0xXX>*/
				volatile std::uint32_t DCR;							/*!<TIM xx Register, Address offset: 0xXX>*/
				volatile std::uint32_t DMAR;						/*!<TIM xx Register, Address offset: 0xXX>*/
				volatile std::uint32_t OR;							/*!<TIM xx Register, Address offset: 0xXX>*/				
		}TIM_TypeDef;
		
		
		// TIM3 registers		
		const std::uint32_t tim3_cr1							= tim3_base + tim_cr1_offset;
		const std::uint32_t tim3_cr2							= tim3_base + tim_cr2_offset;
		const std::uint32_t tim3_smcr							= tim3_base + tim_smcr_offset;
		const std::uint32_t tim3_dier							= tim3_base + tim_dier_offset;
		const std::uint32_t tim3_sr								= tim3_base + tim_sr_offset;
		const std::uint32_t tim3_egr							= tim3_base + tim_egr_offset;
		const std::uint32_t tim3_ccmr1						= tim3_base + tim_ccmr1_offset;
		const std::uint32_t tim3_ccmr2						= tim3_base + tim_ccmr2_offset;
		const std::uint32_t tim3_ccer							= tim3_base + tim_ccer_offset;
		const std::uint32_t tim3_cnt							= tim3_base + tim_cnt_offset;
		const std::uint32_t tim3_psc							= tim3_base + tim_psc_offset;
		const std::uint32_t tim3_arr							= tim3_base + tim_arr_offset;
		const std::uint32_t tim3_ccr1							= tim3_base + tim_ccr1_offset;
		const std::uint32_t tim3_ccr2							= tim3_base + tim_ccr2_offset;
		const std::uint32_t tim3_ccr3							= tim3_base + tim_ccr3_offset;
		const std::uint32_t tim3_ccr4							= tim3_base + tim_ccr4_offset;
		const std::uint32_t tim3_dcr							= tim3_base + tim_dcr_offset;
		const std::uint32_t tim3_dmar							= tim3_base + tim_dmar_offset;
		const std::uint32_t tim3_or								= tim3_base + tim_or_offset;
	
	
		// ADC register offsets
		const std::uint32_t adc_sr_offset					= 0x00U;
		const std::uint32_t adc_cr1_offset				= 0x04U;
		const std::uint32_t adc_cr2_offset				= 0x08U;
		const std::uint32_t adc_smpr1_offset			= 0x0CU;
		const std::uint32_t adc_smpr2_offset			= 0x10U;
		const std::uint32_t adc_jofr1_offset			= 0x14U;
		const std::uint32_t adc_jofr2_offset			= 0x18U;
		const std::uint32_t adc_jofr3_offset			= 0x1CU;
		const std::uint32_t adc_jofr4_offset			= 0x20U;		
		const std::uint32_t adc_htr_offset				= 0x24U;
		const std::uint32_t adc_ltr_offset				= 0x28U;
		const std::uint32_t adc_sqr1_offset				= 0x2CU;
		const std::uint32_t adc_sqr2_offset				= 0x30U;
		const std::uint32_t adc_sqr3_offset				= 0x34U;
		const std::uint32_t adc_jsqr_offset				= 0x38U;
		const std::uint32_t adc_jdr1_offset				= 0x3CU;
		const std::uint32_t adc_jdr2_offset				= 0x40U;
		const std::uint32_t adc_jdr3_offset				= 0x44U;
		const std::uint32_t adc_jdr4_offset				= 0x48U;
		const std::uint32_t adc_dr_offset					= 0x4CU;
		
		// ADC register
		const std::uint32_t adc1_sr								= adc1_base + adc_sr_offset;
		const std::uint32_t adc1_cr1								= adc1_base + adc_cr1_offset;
		const std::uint32_t adc1_cr2								= adc1_base + adc_cr2_offset;
		const std::uint32_t adc1_smpr1							= adc1_base + adc_smpr1_offset;
		const std::uint32_t adc1_smpr2							= adc1_base + adc_smpr2_offset;
		const std::uint32_t adc1_jofr1							= adc1_base + adc_jofr1_offset;
		const std::uint32_t adc1_jofr2							= adc1_base + adc_jofr2_offset;
		const std::uint32_t adc1_jofr3							= adc1_base + adc_jofr3_offset;
		const std::uint32_t adc1_jofr4							= adc1_base + adc_jofr4_offset;		
		const std::uint32_t adc1_htr								= adc1_base + adc_htr_offset;
		const std::uint32_t adc1_ltr								= adc1_base + adc_ltr_offset;
		const std::uint32_t adc1_sqr1							= adc1_base + adc_sqr1_offset;
		const std::uint32_t adc1_sqr2							= adc1_base + adc_sqr2_offset;
		const std::uint32_t adc1_sqr3							= adc1_base + adc_sqr3_offset;
		const std::uint32_t adc1_jsqr							= adc1_base + adc_jsqr_offset;
		const std::uint32_t adc1_jdr1							= adc1_base + adc_jdr1_offset;
		const std::uint32_t adc1_jdr2							= adc1_base + adc_jdr2_offset;
		const std::uint32_t adc1_jdr3							= adc1_base + adc_jdr3_offset;
		const std::uint32_t adc1_jdr4							= adc1_base + adc_jdr4_offset;
		const std::uint32_t adc1_dr								= adc1_base + adc_dr_offset;

		//ADC_TypeDef
		typedef struct{
			volatile std::uint32_t SR;
			volatile std::uint32_t CR1;
			volatile std::uint32_t CR2;
			volatile std::uint32_t SMPR1;
			volatile std::uint32_t SMPR2;
			volatile std::uint32_t JOFR1;
			volatile std::uint32_t JOFR2;
			volatile std::uint32_t JOFR3;
			volatile std::uint32_t JOFR4;
			volatile std::uint32_t HTR;
			volatile std::uint32_t LTR;
			volatile std::uint32_t SQR1;
			volatile std::uint32_t SQR2;
			volatile std::uint32_t SQR3;
			volatile std::uint32_t JSQR;
			volatile std::uint32_t JDR1;
			volatile std::uint32_t JDR2;
			volatile std::uint32_t JDR3;
			volatile std::uint32_t JDR4;
			volatile std::uint32_t DR;
		}ADC_TypeDef;
		



	} // END Namespace reg
} // END Namespace mcal

#endif // __MCAL_REG_H

