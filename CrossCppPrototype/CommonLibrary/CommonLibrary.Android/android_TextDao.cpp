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
		TextDao *textDao = getHandle<TextDao>(env, obj);
		vector<Text*> texts = textDao->findAll();
		
		jclass listClass = env->FindClass("java/util/ArrayList");
		jmethodID listInit = env->GetMethodID(listClass, "<init>", "(Ljava/util/ArrayList;)V");
		jobject listObject = env->NewObject(listClass, listInit);
		jmethodID listAdd = env->GetMethodID(listClass, "add", "(Ljava/lang/Object;)V");
		
		jclass classText = env->FindClass("dk/bobbyz/crosscppandroidapp/commonlibrary/model/Text");
		jmethodID classTextInit = env->GetMethodID(classText, "<init>", "(ILjava/lang/String;)V");
		
		for (int i = 0; i < texts.size(); i++)
		{
			env->CallVoidMethod(listObject, listAdd, env->NewObject(classText, classTextInit, texts[i]->getId(), env->NewStringUTF(texts[i]->getText().c_str())));
		}
	}

/*
 * Class:     dk_bobbyz_crosscppandroidapp_commonlibrary_impl_TextDaoImpl
 * Method:    insert
 * Signature: (JLdk/bobbyz/crosscppandroidapp/commonlibrary/model/Text;)V
 */
	JNIEXPORT void JNICALL Java_dk_bobbyz_crosscppandroidapp_commonlibrary_impl_TextDaoImpl_insert
		(JNIEnv *env, jobject obj, jobject aText)
	{
		TextDao *textDao = getHandle<TextDao>(env, obj);
		
		jclass classText = env->FindClass("dk/bobbyz/crosscppandroidapp/commonlibrary/model/Text");
		jmethodID getText = env->GetMethodID(classText, "getText", "()Ljava/lang/String;");

		jstring jTextText = (jstring)env->CallObjectMethod(aText, getText);
		Text *text = new Text(env->GetStringUTFChars(jTextText, 0));
		textDao->insert(text);
	}

#ifdef __cplusplus
}
#endif
