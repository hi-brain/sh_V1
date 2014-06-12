// -*- C++ -*-
/*!
 * @file  sh_V1.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "sh_V1.h"

// Module specification
// <rtc-template block="module_spec">
static const char* sh_v1_spec[] =
  {
    "implementation_id", "sh_V1",
    "type_name",         "sh_V1",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "VenderName",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
sh_V1::sh_V1(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_input1In("input1", m_input1),
    m_input2In("input2", m_input2),
    m_output1Out("output1", m_output1),
    m_output2Out("output2", m_output2)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
sh_V1::~sh_V1()
{
}



RTC::ReturnCode_t sh_V1::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("input1", m_input1In);
  addInPort("input2", m_input2In);
  
  // Set OutPort buffer
  addOutPort("output1", m_output1Out);
  addOutPort("output2", m_output2Out);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t sh_V1::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t sh_V1::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t sh_V1::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t sh_V1::onActivated(RTC::UniqueId ec_id)
{
	if(!shV1Initialize()){
		std::cerr << "ライブラリを初期化できません" << std::endl;
		return RTC::RTC_ERROR;
	}
  return RTC::RTC_OK;
}


RTC::ReturnCode_t sh_V1::onDeactivated(RTC::UniqueId ec_id)
{
	shV1Terminate();
	return RTC::RTC_OK;
}


RTC::ReturnCode_t sh_V1::onExecute(RTC::UniqueId ec_id)
{
	if(!m_input2In.isNew()){
		return RTC::RTC_OK;
	}
	m_input2In.read();

	mwArray input(1, 4, mxCELL_CLASS);
	mwArray range(1, 3, mxDOUBLE_CLASS);//作る画像のサイズ

	range(1,1) = m_input2.width;//39
	range(1,2) = m_input2.length;//39
	range(1,3) = m_input2.time;//50
	double xrange = range(1,1);
	double yrange = range(1,2);
	double trange = range(1,3);
	std::cerr << "x = " << xrange << std::endl;
	std::cerr << "y = " << yrange << std::endl;
	std::cerr << "t = " << trange << std::endl;

	/////////////////////////////////////////////////////////////////////
	std::cerr << "データの復元_sの読み込み(V1)" << std::endl;
	mwSize dims[3] = {m_input2.width, m_input2.length, m_input2.time};
	mwArray s_copy(3, dims, mxDOUBLE_CLASS);
	int num = 0;
	double *data_s_copy = new double [m_input2.time * m_input2.length * m_input2.width];
	for (num = 0; num < m_input2.time * m_input2.length * m_input2.width ; num++) {
		data_s_copy[num] = m_input2.s_data[num];
	}
	s_copy.SetData(data_s_copy, m_input2.time * m_input2.length * m_input2.width);
	//////////////////////////////////////////////////////////////////////////
	std::cerr << "デフォルトパラメータの読み込み(V1)" << std::endl;
	//デフォルトパラメータの読み込み
	mwArray pars;
	shPars(1, pars);//デフォルトパラメータを.matから読み込みparsに入れる
	///////////////////////////////////////////////////////////

	std::cerr << pars << std::endl;
	std::cerr << "モデル本体の処理開始(V1)" << std::endl;
	//outputここから
	mwArray output(1, 2, mxCELL_CLASS);//出力の入れ物
	mwArray pop;//細胞のポピュレーションpop
	mwArray ind;//インデックス
	//outputここまで

	mwArray type("mtPattern");//文字列の宣言_どの段階まで処理を行うか

	mwArray stimulus = s_copy;
	mwArray stageName = type;

	mwArray inputV1_a(1, 2, mxCELL_CLASS);//出力の入れ物
	inputV1_a.Get(1,1).Set(stimulus);//
	inputV1_a.Get(1,2).Set(pars);//	
	shModelV1Linear(2, output,  inputV1_a);

	pop = output.Get(2, 1, 1); 
	ind = output.Get(2, 1, 2); 

	std::cerr << "V1野の処理shModelV1Linear終了(V1)" << std::endl;

	mwArray inputV1_b(1, 3, mxCELL_CLASS);//
	inputV1_b.Get(1,1).Set(pop);//pop
	inputV1_b.Get(1,2).Set(ind);//ind
	inputV1_b.Get(1,3).Set(pars);//
	shModelFullWaveRectification(2, output, inputV1_b);

	pop = output.Get(2, 1, 1);
	ind = output.Get(2, 1, 2);

	std::cerr << "V1野の処理shModelFullWaveRectification終了(V1)" << std::endl;

	mwArray inputV1_c(1, 3, mxCELL_CLASS);
	inputV1_c.Get(1,1).Set(pop);
	inputV1_c.Get(1,2).Set(ind);
	inputV1_c.Get(1,3).Set(pars);
	shModelV1Blur(2, output, inputV1_c);

	pop = output.Get(2, 1, 1); 
	ind = output.Get(2, 1, 2); 

	std::cerr << "V1野の処理shModelV1Blur終了(V1)" << std::endl;

	mwArray inputV1_d(1, 3, mxCELL_CLASS);
	inputV1_d.Get(1,1).Set(pop);
	inputV1_d.Get(1,2).Set(ind);
	inputV1_d.Get(1,3).Set(pars);
	shModelV1Normalization(2, output, inputV1_d);

	pop = output.Get(2, 1, 1); 
	ind = output.Get(2, 1, 2); 

	std::cerr << "V1野の処理shModelV1Normalization終了(V1)" << std::endl;

	double a = 0;

	/////////////////////////
	std::cerr << "pop(V1)" << std::endl;
	mwArray pop2(output.Get(2, 1, 1));//popの確保(2, 1, 2)がind
	std::cerr << "NumberOfDimensions(V1) : " << pop2.NumberOfDimensions() << std::endl;

	mwArray pop2_dims = pop2.GetDimensions();
	int pop2_dim1 =  pop2_dims.Get(1, 1);//int型に変換する必要あり
	int pop2_dim2 =  pop2_dims.Get(1, 2);
	std::cerr << "1 : (V1)" << pop2_dim1 << std::endl;//18522
	std::cerr << "2 : (V1)" << pop2_dim2 << std::endl;//28

	std::cerr << "NumberOfElements(V1) : " << pop2.NumberOfElements() << std::endl;

	std::cerr << "ind(V1)" << std::endl;
	mwArray ind2(output.Get(2, 1, 2));//indの確保
	std::cerr << "NumberOfDimensions(V1) : " << ind2.NumberOfDimensions() << std::endl;

	mwArray ind2_dims = ind2.GetDimensions();
	int ind2_dim1 =  ind2_dims.Get(1, 1);//int型に変換する必要あり
	int ind2_dim2 =  ind2_dims.Get(1, 2);
	std::cerr << "1 : (V1)" << ind2_dim1 << std::endl;//18522
	std::cerr << "2 : (V1)" << ind2_dim2 << std::endl;//28

	std::cerr << "NumberOfElements(V1) : " << ind2.NumberOfElements() << std::endl;//28

	for(int y = 1; y <= ind2_dim2; y++) {
		for(int x = 1; x <= ind2_dim1; x++) {
			a = ind2.Get((mwSize)2, x, y);//mwArrayの呼び出し
			std::cerr << a << std::endl;
		}
	}
	//////////////////////////

	//pop_18522*28
	m_output2.pop_length = pop2_dim1;
	m_output2.pop_width = pop2_dim2;
		
	std::cerr << "popをsequence型に変換(V1)" << std::endl;
//	std::cerr << pop2_dim1 * pop2_dim2 << std::endl;
//	m_output2.pop.length(518616);
	m_output2.pop.length(pop2_dim1 * pop2_dim2);//popの配列の確保
		
	num = 0;
	double *data_copy_pop = new double [pop2_dim1 * pop2_dim2];
	pop.GetData(data_copy_pop, pop2_dim1 * pop2_dim2);

	for (num = 0; num < pop2_dim1 * pop2_dim2 ; num++) {
		m_output2.pop[num] = data_copy_pop[num];
	}

	std::cerr << "indをsequence型に変換(V1)" << std::endl;

	//ind_2*4/
	m_output2.ind_length = ind2_dim1;
	m_output2.ind_width = ind2_dim2;

	m_output2.ind.length(ind2_dim1 * ind2_dim2);//popの配列の確保
		
	double *data_copy_ind = new double [ind2_dim1 * ind2_dim2];
	ind.GetData(data_copy_ind, ind2_dim1 * ind2_dim2);

	for (num = 0; num < ind2_dim1 * ind2_dim2; num++) {
		m_output2.ind[num] = data_copy_ind[num];
	}

	std::cerr << "MT野への書き出し(V1)" << std::endl;
	m_output2Out.write();//書き出し_異常発生..接続カット
	std::cerr << "V1_end" << std::endl;

	delete[] data_s_copy;
	delete[] data_copy_pop;
	delete[] data_copy_ind;

	return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t sh_V1::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t sh_V1::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t sh_V1::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t sh_V1::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t sh_V1::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void sh_V1Init(RTC::Manager* manager)
  {
    coil::Properties profile(sh_v1_spec);
    manager->registerFactory(profile,
                             RTC::Create<sh_V1>,
                             RTC::Delete<sh_V1>);
  }
  
};


