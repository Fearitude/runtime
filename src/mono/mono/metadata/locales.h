/*
 * locales.h: Culture-sensitive handling
 *
 * Authors:
 *	Dick Porter (dick@ximian.com)
 *
 * (C) 2003 Ximian, Inc.
 */

#ifndef _MONO_METADATA_LOCALES_H_
#define _MONO_METADATA_LOCALES_H_

#include <glib.h>

#include <mono/metadata/object.h>

/* This is a copy of System.Globalization.CompareOptions */
typedef enum {
	CompareOptions_None=0x00,
	CompareOptions_IgnoreCase=0x01,
	CompareOptions_IgnoreNonSpace=0x02,
	CompareOptions_IgnoreSymbols=0x04,
	CompareOptions_IgnoreKanaType=0x08,
	CompareOptions_IgnoreWidth=0x10,
	CompareOptions_StringSort=0x20000000,
	CompareOptions_Ordinal=0x40000000
} MonoCompareOptions;

extern void ves_icall_System_Globalization_CultureInfo_construct_internal_locale (MonoCultureInfo *this, MonoString *locale);
extern MonoBoolean ves_icall_System_Globalization_CultureInfo_construct_internal_locale_from_current_locale (MonoCultureInfo *ci);
extern MonoBoolean ves_icall_System_Globalization_CultureInfo_construct_internal_locale_from_lcid (MonoCultureInfo *this, gint lcid);
extern MonoBoolean ves_icall_System_Globalization_CultureInfo_construct_internal_locale_from_name (MonoCultureInfo *this, MonoString *name);
extern MonoBoolean ves_icall_System_Globalization_CultureInfo_construct_internal_locale_from_specific_name (MonoCultureInfo *ci, MonoString *name);
extern MonoArray *ves_icall_System_Globalization_CultureInfo_internal_get_cultures (MonoBoolean neutral, MonoBoolean specific, MonoBoolean installed);
extern MonoBoolean ves_icall_System_Globalization_CultureInfo_internal_is_lcid_neutral (gint lcid, MonoBoolean *is_neutral);
extern void ves_icall_System_Globalization_CultureInfo_construct_datetime_format (MonoCultureInfo *this);
extern void ves_icall_System_Globalization_CultureInfo_construct_number_format (MonoCultureInfo *this);
extern void ves_icall_System_Globalization_CompareInfo_construct_compareinfo (MonoCompareInfo *comp, MonoString *locale);
extern int ves_icall_System_Globalization_CompareInfo_internal_compare (MonoCompareInfo *this, MonoString *str1, gint32 off1, gint32 len1, MonoString *str2, gint32 off2, gint32 len2, gint32 options);
extern void ves_icall_System_Globalization_CompareInfo_free_internal_collator (MonoCompareInfo *this);
extern void ves_icall_System_Globalization_CompareInfo_assign_sortkey (MonoCompareInfo *this, MonoSortKey *key, MonoString *source, gint32 options);
extern int ves_icall_System_Globalization_CompareInfo_internal_index (MonoCompareInfo *this, MonoString *source, gint32 sindex, gint32 count, MonoString *value, gint32 options, MonoBoolean first);
extern int ves_icall_System_Globalization_CompareInfo_internal_index_char (MonoCompareInfo *this, MonoString *source, gint32 sindex, gint32 count, gunichar2 value, gint32 options, MonoBoolean first);
extern int ves_icall_System_Threading_Thread_current_lcid (void);
extern MonoString *ves_icall_System_String_InternalReplace_Str_Comp (MonoString *this, MonoString *old, MonoString *new, MonoCompareInfo *comp);
extern MonoString *ves_icall_System_String_InternalToLower_Comp (MonoString *this, MonoCultureInfo *cult);
extern MonoString *ves_icall_System_String_InternalToUpper_Comp (MonoString *this, MonoCultureInfo *cult);
extern gunichar2 ves_icall_System_Char_InternalToUpper_Comp (gunichar2 c, MonoCultureInfo *cult);
extern gunichar2 ves_icall_System_Char_InternalToLower_Comp (gunichar2 c, MonoCultureInfo *cult);

#endif /* _MONO_METADATA_FILEIO_H_ */
