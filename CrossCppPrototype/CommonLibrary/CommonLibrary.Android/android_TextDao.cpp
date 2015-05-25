#include "handle.h"
#include "android_TextDao.h"
#include "TextDao.h"
/* Header for class dk_bobbyz_crosscppandroidapp_commonlibrary_impl_TextDaoImpl */

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     dk_bobbyz_crosscppandroidapp_commonlibrary_impl_TextDaoImpl
 * Method:    initTextDao
 * Signature: (Ljava/lang/String;)J
 */
	JNIEXPORT jlong JNICALL Java_dk_bobbyz_crosscppandroidapp_commonlibrary_impl_TextDaoImpl_initTextDao
		(JNIEnv *env, jobject obj, jstring dbPath)
	{
		LOGD("TextDaoImpl", "init");
		const char *str = env->GetStringUTFChars(dbPath, 0);
		TextDao *textDao = new TextDao(env->GetStringUTFChars(dbPath, 0));
		setHandle(env, obj, textDao);
	}

/*
 * Class:     dk_bobbyz_crosscppandroidapp_commonlibrary_impl_TextDaoImpl
 * Method:    destructTextDao
 * Signature: (J)V
 */
	JNIEXPORT void JNICALL Java_dk_bobbyz_crosscppandroidapp_commonlibrary_impl_TextDaoImpl_destructTextDao
		(JNIEnv *env, jobject obj)
	{
		LOGD("TextDaoImpl", "destruct");
		TextDao *textDao = getHandle<TextDao>(env, obj);
		textDao->~TextDao();
	}

/*
 * Class:     dk_bobbyz_crosscppandroidapp_commonlibrary_impl_TextDaoImpl
 * Method:    findAll
 * Signature: (J)Ljava/util/List;
 */
	JNIEXPORT jobject JNICALL Java_dk_bobbyz_crosscppandroidapp_commonlibrary_impl_TextDaoImpl_findAll
		(JNIEnv *env, jobject obj)
	{
		LOGD("TextDaoImpl", "findAll_begin");
		TextDao *textDao = getHandle<TextDao>(env, obj);
		LOGD("TextDaoImpl", "findAll1");
		vector<Text*> texts = textDao->findAll();
		LOGD("TextDaoImpl", "findAll2");
		jclass listClass = env->FindClass("java/util/ArrayList");
		LOGD("TextDaoImpl", "findAll3");
		jmethodID listInit = env->GetMethodID(listClass, "<init>", "(Ljava/util/ArrayList;)V");
		LOGD("TextDaoImpl", "findAll4");
		jobject listObject = env->NewObject(listClass, listInit);
		LOGD("TextDaoImpl", "findAll5");
		jmethodID listAdd = env->GetMethodID(listClass, "add", "(Ljava/lang/Object;)V");
		LOGD("TextDaoImpl", "findAll6");
		
		jclass classText = env->FindClass("dk/bobbyz/crosscppandroidapp/commonlibrary/model/Text");
		LOGD("TextDaoImpl", "findAll7");
		jmethodID classTextInit = env->GetMethodID(classText, "<init>", "(ILjava/lang/String;)V");
		LOGD("TextDaoImpl", "findAll8");
		
		for (int i = 0; i < texts.size(); i++)
		{
			LOGD("TextDaoImpl", "findAll9");
			env->CallVoidMethod(listObject, listAdd, env->NewObject(classText, classTextInit, texts[i]->getId(), env->NewStringUTF(texts[i]->getText().c_str())));
			LOGD("TextDaoImpl", "findAll10");
		}
		LOGD("TextDaoImpl", "findAll_end");
	}

/*
 * Class:     dk_bobbyz_crosscppandroidapp_commonlibrary_impl_TextDaoImpl
 * Method:    insert
 * Signature: (JLdk/bobbyz/crosscppandroidapp/commonlibrary/model/Text;)V
 */
	JNIEXPORT void JNICALL Java_dk_bobbyz_crosscppandroidapp_commonlibrary_impl_TextDaoImpl_insert
		(JNIEnv *env, jobject obj, jobject aText)
	{
		LOGD("TextDaoImpl", "insert_begin");
		TextDao *textDao = getHandle<TextDao>(env, obj);
		LOGD("TextDaoImpl", "insert1");
		jclass classText = env->FindClass("dk/bobbyz/crosscppandroidapp/commonlibrary/model/Text");
		LOGD("TextDaoImpl", "insert2");
		jmethodID getText = env->GetMethodID(classText, "getText", "()Ljava/lang/String;");
		LOGD("TextDaoImpl", "insert3");

		jstring jTextText = (jstring)env->CallObjectMethod(aText, getText);
		LOGD("TextDaoImpl", "insert4");
		Text *text = new Text(env->GetStringUTFChars(jTextText, 0));
		LOGD("TextDaoImpl", "insert5");
		textDao->insert(text);
		LOGD("TextDaoImpl", "insert_end");
	}

#ifdef __cplusplus
}
#endif
