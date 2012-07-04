/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "libnfs-zdr.h"
#include "libnfs-raw-nlm.h"

bool_t
zdr_nlm_fh4 (ZDR *zdrs, nlm_fh4 *objp)
{
	register int32_t *buf;

	 if (!zdr_bytes (zdrs, (char **)&objp->data.data_val, (u_int *) &objp->data.data_len, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
zdr_nlm4_oh (ZDR *zdrs, nlm4_oh *objp)
{
	register int32_t *buf;

	 if (!zdr_string (zdrs, objp, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
zdr_nlm_cookie (ZDR *zdrs, nlm_cookie *objp)
{
	register int32_t *buf;

	 if (!zdr_bytes (zdrs, (char **)&objp->data.data_val, (u_int *) &objp->data.data_len, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
zdr_nlmstat4 (ZDR *zdrs, nlmstat4 *objp)
{
	register int32_t *buf;

	 if (!zdr_enum (zdrs, (enum_t *) objp))
		 return FALSE;
	return TRUE;
}

bool_t
zdr_nlm4_holder (ZDR *zdrs, nlm4_holder *objp)
{
	register int32_t *buf;

	 if (!zdr_bool (zdrs, &objp->exclusive))
		 return FALSE;
	 if (!zdr_u_int (zdrs, &objp->svid))
		 return FALSE;
	 if (!zdr_nlm4_oh (zdrs, &objp->oh))
		 return FALSE;
	 if (!zdr_u_quad_t (zdrs, &objp->l_offset))
		 return FALSE;
	 if (!zdr_u_quad_t (zdrs, &objp->l_len))
		 return FALSE;
	return TRUE;
}

bool_t
zdr_nlm4_lock (ZDR *zdrs, nlm4_lock *objp)
{
	register int32_t *buf;

	 if (!zdr_string (zdrs, &objp->caller_name, NLM_MAXNAME))
		 return FALSE;
	 if (!zdr_nlm_fh4 (zdrs, &objp->fh))
		 return FALSE;
	 if (!zdr_nlm4_oh (zdrs, &objp->oh))
		 return FALSE;
	 if (!zdr_u_int (zdrs, &objp->svid))
		 return FALSE;
	 if (!zdr_u_quad_t (zdrs, &objp->l_offset))
		 return FALSE;
	 if (!zdr_u_quad_t (zdrs, &objp->l_len))
		 return FALSE;
	return TRUE;
}

bool_t
zdr_nlm4_share (ZDR *zdrs, nlm4_share *objp)
{
	register int32_t *buf;

	 if (!zdr_string (zdrs, &objp->caller_name, NLM_MAXNAME))
		 return FALSE;
	 if (!zdr_nlm_fh4 (zdrs, &objp->fh))
		 return FALSE;
	 if (!zdr_nlm4_oh (zdrs, &objp->oh))
		 return FALSE;
	 if (!zdr_u_int (zdrs, &objp->mode))
		 return FALSE;
	 if (!zdr_u_int (zdrs, &objp->access))
		 return FALSE;
	return TRUE;
}

bool_t
zdr_nlm4_testres_denied (ZDR *zdrs, nlm4_testres_denied *objp)
{
	register int32_t *buf;

	 if (!zdr_nlm4_holder (zdrs, &objp->holder))
		 return FALSE;
	return TRUE;
}

bool_t
zdr_nlm4_testreply (ZDR *zdrs, nlm4_testreply *objp)
{
	register int32_t *buf;

	 if (!zdr_nlmstat4 (zdrs, &objp->status))
		 return FALSE;
	switch (objp->status) {
	case NLM4_DENIED:
		 if (!zdr_nlm4_testres_denied (zdrs, &objp->nlm4_testreply_u.lock))
			 return FALSE;
		break;
	default:
		break;
	}
	return TRUE;
}

bool_t
zdr_NLM4_TESTres (ZDR *zdrs, NLM4_TESTres *objp)
{
	register int32_t *buf;

	 if (!zdr_nlm_cookie (zdrs, &objp->cookie))
		 return FALSE;
	 if (!zdr_nlm4_testreply (zdrs, &objp->reply))
		 return FALSE;
	return TRUE;
}

bool_t
zdr_NLM4_TESTargs (ZDR *zdrs, NLM4_TESTargs *objp)
{
	register int32_t *buf;

	 if (!zdr_nlm_cookie (zdrs, &objp->cookie))
		 return FALSE;
	 if (!zdr_bool (zdrs, &objp->exclusive))
		 return FALSE;
	 if (!zdr_nlm4_lock (zdrs, &objp->lock))
		 return FALSE;
	return TRUE;
}

bool_t
zdr_NLM4_CANCres (ZDR *zdrs, NLM4_CANCres *objp)
{
	register int32_t *buf;

	 if (!zdr_nlm_cookie (zdrs, &objp->cookie))
		 return FALSE;
	 if (!zdr_nlmstat4 (zdrs, &objp->status))
		 return FALSE;
	return TRUE;
}

bool_t
zdr_NLM4_CANCargs (ZDR *zdrs, NLM4_CANCargs *objp)
{
	register int32_t *buf;

	 if (!zdr_nlm_cookie (zdrs, &objp->cookie))
		 return FALSE;
	 if (!zdr_bool (zdrs, &objp->block))
		 return FALSE;
	 if (!zdr_bool (zdrs, &objp->exclusive))
		 return FALSE;
	 if (!zdr_nlm4_lock (zdrs, &objp->lock))
		 return FALSE;
	return TRUE;
}

bool_t
zdr_NLM4_UNLOCKres (ZDR *zdrs, NLM4_UNLOCKres *objp)
{
	register int32_t *buf;

	 if (!zdr_nlm_cookie (zdrs, &objp->cookie))
		 return FALSE;
	 if (!zdr_nlmstat4 (zdrs, &objp->status))
		 return FALSE;
	return TRUE;
}

bool_t
zdr_NLM4_UNLOCKargs (ZDR *zdrs, NLM4_UNLOCKargs *objp)
{
	register int32_t *buf;

	 if (!zdr_nlm_cookie (zdrs, &objp->cookie))
		 return FALSE;
	 if (!zdr_nlm4_lock (zdrs, &objp->lock))
		 return FALSE;
	return TRUE;
}

bool_t
zdr_NLM4_LOCKres (ZDR *zdrs, NLM4_LOCKres *objp)
{
	register int32_t *buf;

	 if (!zdr_nlm_cookie (zdrs, &objp->cookie))
		 return FALSE;
	 if (!zdr_nlmstat4 (zdrs, &objp->status))
		 return FALSE;
	return TRUE;
}

bool_t
zdr_NLM4_LOCKargs (ZDR *zdrs, NLM4_LOCKargs *objp)
{
	register int32_t *buf;

	 if (!zdr_nlm_cookie (zdrs, &objp->cookie))
		 return FALSE;
	 if (!zdr_bool (zdrs, &objp->block))
		 return FALSE;
	 if (!zdr_bool (zdrs, &objp->exclusive))
		 return FALSE;
	 if (!zdr_nlm4_lock (zdrs, &objp->lock))
		 return FALSE;
	 if (!zdr_bool (zdrs, &objp->reclaim))
		 return FALSE;
	 if (!zdr_int (zdrs, &objp->state))
		 return FALSE;
	return TRUE;
}

bool_t
zdr_NLM4_GRANTEDargs (ZDR *zdrs, NLM4_GRANTEDargs *objp)
{
	register int32_t *buf;

	 if (!zdr_nlm_cookie (zdrs, &objp->cookie))
		 return FALSE;
	 if (!zdr_bool (zdrs, &objp->exclusive))
		 return FALSE;
	 if (!zdr_nlm4_lock (zdrs, &objp->lock))
		 return FALSE;
	return TRUE;
}

bool_t
zdr_NLM4_GRANTEDres (ZDR *zdrs, NLM4_GRANTEDres *objp)
{
	register int32_t *buf;

	 if (!zdr_nlm_cookie (zdrs, &objp->cookie))
		 return FALSE;
	 if (!zdr_nlmstat4 (zdrs, &objp->status))
		 return FALSE;
	return TRUE;
}
