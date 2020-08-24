#pragma once
/**
 * This file re-uses parts of TypeScript compiler API definitions which are
 * available at https://github.com/microsoft/TypeScript/blob/v3.5.3/lib/typescript.d.ts
 * Lots of modifications and original additions includes.
 * Original copyright for parts of the file is retained below.
 */

/*! *****************************************************************************
Copyright (c) Microsoft Corporation. All rights reserved.
Licensed under the Apache License, Version 2.0 (the "License"); you may not use
this file except in compliance with the License. You may obtain a copy of the
License at http://www.apache.org/licenses/LICENSE-2.0

THIS CODE IS PROVIDED ON AN *AS IS* BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION ANY IMPLIED
WARRANTIES OR CONDITIONS OF TITLE, FITNESS FOR A PARTICULAR PURPOSE,
MERCHANTABLITY OR NON-INFRINGEMENT.

See the Apache Version 2.0 License for specific language governing permissions
and limitations under the License.
***************************************************************************** */

#include <emscripten/val.h>
#include <optional>
#include "explicit_cast.h"
#include "range_defines.h"
#include "js_types.h"
#include "js_callback.h"
#include "js_bootstrap.h"

namespace tc::js_defs {
enum class _enum_js_jts_dSyntaxKind {
	Unknown = 0,
	EndOfFileToken = 1,
	SingleLineCommentTrivia = 2,
	MultiLineCommentTrivia = 3,
	NewLineTrivia = 4,
	WhitespaceTrivia = 5,
	ShebangTrivia = 6,
	ConflictMarkerTrivia = 7,
	NumericLiteral = 8,
	BigIntLiteral = 9,
	StringLiteral = 10,
	JsxText = 11,
	JsxTextAllWhiteSpaces = 12,
	RegularExpressionLiteral = 13,
	NoSubstitutionTemplateLiteral = 14,
	TemplateHead = 15,
	TemplateMiddle = 16,
	TemplateTail = 17,
	OpenBraceToken = 18,
	CloseBraceToken = 19,
	OpenParenToken = 20,
	CloseParenToken = 21,
	OpenBracketToken = 22,
	CloseBracketToken = 23,
	DotToken = 24,
	DotDotDotToken = 25,
	SemicolonToken = 26,
	CommaToken = 27,
	LessThanToken = 28,
	LessThanSlashToken = 29,
	GreaterThanToken = 30,
	LessThanEqualsToken = 31,
	GreaterThanEqualsToken = 32,
	EqualsEqualsToken = 33,
	ExclamationEqualsToken = 34,
	EqualsEqualsEqualsToken = 35,
	ExclamationEqualsEqualsToken = 36,
	EqualsGreaterThanToken = 37,
	PlusToken = 38,
	MinusToken = 39,
	AsteriskToken = 40,
	AsteriskAsteriskToken = 41,
	SlashToken = 42,
	PercentToken = 43,
	PlusPlusToken = 44,
	MinusMinusToken = 45,
	LessThanLessThanToken = 46,
	GreaterThanGreaterThanToken = 47,
	GreaterThanGreaterThanGreaterThanToken = 48,
	AmpersandToken = 49,
	BarToken = 50,
	CaretToken = 51,
	ExclamationToken = 52,
	TildeToken = 53,
	AmpersandAmpersandToken = 54,
	BarBarToken = 55,
	QuestionToken = 56,
	ColonToken = 57,
	AtToken = 58,
	BacktickToken = 59,
	EqualsToken = 60,
	PlusEqualsToken = 61,
	MinusEqualsToken = 62,
	AsteriskEqualsToken = 63,
	AsteriskAsteriskEqualsToken = 64,
	SlashEqualsToken = 65,
	PercentEqualsToken = 66,
	LessThanLessThanEqualsToken = 67,
	GreaterThanGreaterThanEqualsToken = 68,
	GreaterThanGreaterThanGreaterThanEqualsToken = 69,
	AmpersandEqualsToken = 70,
	BarEqualsToken = 71,
	CaretEqualsToken = 72,
	Identifier = 73,
	BreakKeyword = 74,
	CaseKeyword = 75,
	CatchKeyword = 76,
	ClassKeyword = 77,
	ConstKeyword = 78,
	ContinueKeyword = 79,
	DebuggerKeyword = 80,
	DefaultKeyword = 81,
	DeleteKeyword = 82,
	DoKeyword = 83,
	ElseKeyword = 84,
	EnumKeyword = 85,
	ExportKeyword = 86,
	ExtendsKeyword = 87,
	FalseKeyword = 88,
	FinallyKeyword = 89,
	ForKeyword = 90,
	FunctionKeyword = 91,
	IfKeyword = 92,
	ImportKeyword = 93,
	InKeyword = 94,
	InstanceOfKeyword = 95,
	NewKeyword = 96,
	NullKeyword = 97,
	ReturnKeyword = 98,
	SuperKeyword = 99,
	SwitchKeyword = 100,
	ThisKeyword = 101,
	ThrowKeyword = 102,
	TrueKeyword = 103,
	TryKeyword = 104,
	TypeOfKeyword = 105,
	VarKeyword = 106,
	VoidKeyword = 107,
	WhileKeyword = 108,
	WithKeyword = 109,
	ImplementsKeyword = 110,
	InterfaceKeyword = 111,
	LetKeyword = 112,
	PackageKeyword = 113,
	PrivateKeyword = 114,
	ProtectedKeyword = 115,
	PublicKeyword = 116,
	StaticKeyword = 117,
	YieldKeyword = 118,
	AbstractKeyword = 119,
	AsKeyword = 120,
	AnyKeyword = 121,
	AsyncKeyword = 122,
	AwaitKeyword = 123,
	BooleanKeyword = 124,
	ConstructorKeyword = 125,
	DeclareKeyword = 126,
	GetKeyword = 127,
	InferKeyword = 128,
	IsKeyword = 129,
	KeyOfKeyword = 130,
	ModuleKeyword = 131,
	NamespaceKeyword = 132,
	NeverKeyword = 133,
	ReadonlyKeyword = 134,
	RequireKeyword = 135,
	NumberKeyword = 136,
	ObjectKeyword = 137,
	SetKeyword = 138,
	StringKeyword = 139,
	SymbolKeyword = 140,
	TypeKeyword = 141,
	UndefinedKeyword = 142,
	UniqueKeyword = 143,
	UnknownKeyword = 144,
	FromKeyword = 145,
	GlobalKeyword = 146,
	BigIntKeyword = 147,
	OfKeyword = 148,
	QualifiedName = 149,
	ComputedPropertyName = 150,
	TypeParameter = 151,
	Parameter = 152,
	Decorator = 153,
	PropertySignature = 154,
	PropertyDeclaration = 155,
	MethodSignature = 156,
	MethodDeclaration = 157,
	Constructor = 158,
	GetAccessor = 159,
	SetAccessor = 160,
	CallSignature = 161,
	ConstructSignature = 162,
	IndexSignature = 163,
	TypePredicate = 164,
	TypeReference = 165,
	FunctionType = 166,
	ConstructorType = 167,
	TypeQuery = 168,
	TypeLiteral = 169,
	ArrayType = 170,
	TupleType = 171,
	OptionalType = 172,
	RestType = 173,
	UnionType = 174,
	IntersectionType = 175,
	ConditionalType = 176,
	InferType = 177,
	ParenthesizedType = 178,
	ThisType = 179,
	TypeOperator = 180,
	IndexedAccessType = 181,
	MappedType = 182,
	LiteralType = 183,
	ImportType = 184,
	ObjectBindingPattern = 185,
	ArrayBindingPattern = 186,
	BindingElement = 187,
	ArrayLiteralExpression = 188,
	ObjectLiteralExpression = 189,
	PropertyAccessExpression = 190,
	ElementAccessExpression = 191,
	CallExpression = 192,
	NewExpression = 193,
	TaggedTemplateExpression = 194,
	TypeAssertionExpression = 195,
	ParenthesizedExpression = 196,
	FunctionExpression = 197,
	ArrowFunction = 198,
	DeleteExpression = 199,
	TypeOfExpression = 200,
	VoidExpression = 201,
	AwaitExpression = 202,
	PrefixUnaryExpression = 203,
	PostfixUnaryExpression = 204,
	BinaryExpression = 205,
	ConditionalExpression = 206,
	TemplateExpression = 207,
	YieldExpression = 208,
	SpreadElement = 209,
	ClassExpression = 210,
	OmittedExpression = 211,
	ExpressionWithTypeArguments = 212,
	AsExpression = 213,
	NonNullExpression = 214,
	MetaProperty = 215,
	SyntheticExpression = 216,
	TemplateSpan = 217,
	SemicolonClassElement = 218,
	Block = 219,
	VariableStatement = 220,
	EmptyStatement = 221,
	ExpressionStatement = 222,
	IfStatement = 223,
	DoStatement = 224,
	WhileStatement = 225,
	ForStatement = 226,
	ForInStatement = 227,
	ForOfStatement = 228,
	ContinueStatement = 229,
	BreakStatement = 230,
	ReturnStatement = 231,
	WithStatement = 232,
	SwitchStatement = 233,
	LabeledStatement = 234,
	ThrowStatement = 235,
	TryStatement = 236,
	DebuggerStatement = 237,
	VariableDeclaration = 238,
	VariableDeclarationList = 239,
	FunctionDeclaration = 240,
	ClassDeclaration = 241,
	InterfaceDeclaration = 242,
	TypeAliasDeclaration = 243,
	EnumDeclaration = 244,
	ModuleDeclaration = 245,
	ModuleBlock = 246,
	CaseBlock = 247,
	NamespaceExportDeclaration = 248,
	ImportEqualsDeclaration = 249,
	ImportDeclaration = 250,
	ImportClause = 251,
	NamespaceImport = 252,
	NamedImports = 253,
	ImportSpecifier = 254,
	ExportAssignment = 255,
	ExportDeclaration = 256,
	NamedExports = 257,
	ExportSpecifier = 258,
	MissingDeclaration = 259,
	ExternalModuleReference = 260,
	JsxElement = 261,
	JsxSelfClosingElement = 262,
	JsxOpeningElement = 263,
	JsxClosingElement = 264,
	JsxFragment = 265,
	JsxOpeningFragment = 266,
	JsxClosingFragment = 267,
	JsxAttribute = 268,
	JsxAttributes = 269,
	JsxSpreadAttribute = 270,
	JsxExpression = 271,
	CaseClause = 272,
	DefaultClause = 273,
	HeritageClause = 274,
	CatchClause = 275,
	PropertyAssignment = 276,
	ShorthandPropertyAssignment = 277,
	SpreadAssignment = 278,
	EnumMember = 279,
	UnparsedPrologue = 280,
	UnparsedPrepend = 281,
	UnparsedText = 282,
	UnparsedInternalText = 283,
	UnparsedSyntheticReference = 284,
	SourceFile = 285,
	Bundle = 286,
	UnparsedSource = 287,
	InputFiles = 288,
	JSDocTypeExpression = 289,
	JSDocAllType = 290,
	JSDocUnknownType = 291,
	JSDocNullableType = 292,
	JSDocNonNullableType = 293,
	JSDocOptionalType = 294,
	JSDocFunctionType = 295,
	JSDocVariadicType = 296,
	JSDocComment = 297,
	JSDocTypeLiteral = 298,
	JSDocSignature = 299,
	JSDocTag = 300,
	JSDocAugmentsTag = 301,
	JSDocClassTag = 302,
	JSDocCallbackTag = 303,
	JSDocEnumTag = 304,
	JSDocParameterTag = 305,
	JSDocReturnTag = 306,
	JSDocThisTag = 307,
	JSDocTypeTag = 308,
	JSDocTemplateTag = 309,
	JSDocTypedefTag = 310,
	JSDocPropertyTag = 311,
	SyntaxList = 312,
	NotEmittedStatement = 313,
	PartiallyEmittedExpression = 314,
	CommaListExpression = 315,
	MergeDeclarationMarker = 316,
	EndOfDeclarationMarker = 317,
	Count = 318,
	FirstAssignment = 60,
	LastAssignment = 72,
	FirstCompoundAssignment = 61,
	LastCompoundAssignment = 72,
	FirstReservedWord = 74,
	LastReservedWord = 109,
	FirstKeyword = 74,
	LastKeyword = 148,
	FirstFutureReservedWord = 110,
	LastFutureReservedWord = 118,
	FirstTypeNode = 164,
	LastTypeNode = 184,
	FirstPunctuation = 18,
	LastPunctuation = 72,
	FirstToken = 0,
	LastToken = 148,
	FirstTriviaToken = 2,
	LastTriviaToken = 7,
	FirstLiteralToken = 8,
	LastLiteralToken = 14,
	FirstTemplateToken = 14,
	LastTemplateToken = 17,
	FirstBinaryOperator = 28,
	LastBinaryOperator = 72,
	FirstNode = 149,
	FirstJSDocNode = 289,
	LastJSDocNode = 311,
	FirstJSDocTagNode = 300,
	LastJSDocTagNode = 311,
};
enum class _enum_js_jts_dNodeFlags {
	None = 0,
	Let = 1,
	Const = 2,
	NestedNamespace = 4,
	Synthesized = 8,
	Namespace = 16,
	ExportContext = 32,
	ContainsThis = 64,
	HasImplicitReturn = 128,
	HasExplicitReturn = 256,
	GlobalAugmentation = 512,
	HasAsyncFunctions = 1024,
	DisallowInContext = 2048,
	YieldContext = 4096,
	DecoratorContext = 8192,
	AwaitContext = 16384,
	ThisNodeHasError = 32768,
	JavaScriptFile = 65536,
	ThisNodeOrAnySubNodesHasError = 131072,
	HasAggregatedChildData = 262144,
	JSDoc = 2097152,
	JsonFile = 16777216,
	BlockScoped = 3,
	ReachabilityCheckFlags = 384,
	ReachabilityAndEmitFlags = 1408,
	ContextFlags = 12679168,
	TypeExcludesFlags = 20480,
};
enum class _enum_js_jts_dModifierFlags {
	None = 0,
	Export = 1,
	Ambient = 2,
	Public = 4,
	Private = 8,
	Protected = 16,
	Static = 32,
	Readonly = 64,
	Abstract = 128,
	Async = 256,
	Default = 512,
	Const = 2048,
	HasComputedFlags = 536870912,
	AccessibilityModifier = 28,
	ParameterPropertyModifier = 92,
	NonPublicAccessibilityModifier = 24,
	TypeScriptModifier = 2270,
	ExportDefault = 513,
	All = 3071,
};
enum class _enum_js_jts_dJsxFlags {
	None = 0,
	IntrinsicNamedElement = 1,
	IntrinsicIndexedElement = 2,
	IntrinsicElement = 3,
};
enum class _enum_js_jts_dTokenFlags {
	None = 0,
	Scientific = 16,
	Octal = 32,
	HexSpecifier = 64,
	BinarySpecifier = 128,
	OctalSpecifier = 256,
};
enum class _enum_js_jts_dFlowFlags {
	Unreachable = 1,
	Start = 2,
	BranchLabel = 4,
	LoopLabel = 8,
	Assignment = 16,
	TrueCondition = 32,
	FalseCondition = 64,
	SwitchClause = 128,
	ArrayMutation = 256,
	Referenced = 512,
	Shared = 1024,
	PreFinally = 2048,
	AfterFinally = 4096,
	Label = 12,
	Condition = 96,
};
enum class _enum_js_jts_dExitStatus {
	Success = 0,
	DiagnosticsPresent_OutputsSkipped = 1,
	DiagnosticsPresent_OutputsGenerated = 2,
};
enum class _enum_js_jts_dNodeBuilderFlags {
	None = 0,
	NoTruncation = 1,
	WriteArrayAsGenericType = 2,
	GenerateNamesForShadowedTypeParams = 4,
	UseStructuralFallback = 8,
	ForbidIndexedAccessSymbolReferences = 16,
	WriteTypeArgumentsOfSignature = 32,
	UseFullyQualifiedType = 64,
	UseOnlyExternalAliasing = 128,
	SuppressAnyReturnType = 256,
	WriteTypeParametersInQualifiedName = 512,
	MultilineObjectLiterals = 1024,
	WriteClassExpressionAsTypeLiteral = 2048,
	UseTypeOfFunction = 4096,
	OmitParameterModifiers = 8192,
	UseAliasDefinedOutsideCurrentScope = 16384,
	AllowThisInObjectLiteral = 32768,
	AllowQualifedNameInPlaceOfIdentifier = 65536,
	AllowAnonymousIdentifier = 131072,
	AllowEmptyUnionOrIntersection = 262144,
	AllowEmptyTuple = 524288,
	AllowUniqueESSymbolType = 1048576,
	AllowEmptyIndexInfoType = 2097152,
	AllowNodeModulesRelativePaths = 67108864,
	IgnoreErrors = 70221824,
	InObjectTypeLiteral = 4194304,
	InTypeAlias = 8388608,
	InInitialEntityName = 16777216,
	InReverseMappedType = 33554432,
};
enum class _enum_js_jts_dTypeFormatFlags {
	None = 0,
	NoTruncation = 1,
	WriteArrayAsGenericType = 2,
	UseStructuralFallback = 8,
	WriteTypeArgumentsOfSignature = 32,
	UseFullyQualifiedType = 64,
	SuppressAnyReturnType = 256,
	MultilineObjectLiterals = 1024,
	WriteClassExpressionAsTypeLiteral = 2048,
	UseTypeOfFunction = 4096,
	OmitParameterModifiers = 8192,
	UseAliasDefinedOutsideCurrentScope = 16384,
	AllowUniqueESSymbolType = 1048576,
	AddUndefined = 131072,
	WriteArrowStyleSignature = 262144,
	InArrayType = 524288,
	InElementType = 2097152,
	InFirstTypeArgument = 4194304,
	InTypeAlias = 8388608,
	WriteOwnNameForAnyLike = 0,
	NodeBuilderFlagsMask = 9469291,
};
enum class _enum_js_jts_dSymbolFormatFlags {
	None = 0,
	WriteTypeParametersOrArguments = 1,
	UseOnlyExternalAliasing = 2,
	AllowAnyNodeKind = 4,
	UseAliasDefinedOutsideCurrentScope = 8,
};
enum class _enum_js_jts_dTypePredicateKind {
	This = 0,
	Identifier = 1,
};
enum class _enum_js_jts_dSymbolFlags {
	None = 0,
	FunctionScopedVariable = 1,
	BlockScopedVariable = 2,
	Property = 4,
	EnumMember = 8,
	Function = 16,
	Class = 32,
	Interface = 64,
	ConstEnum = 128,
	RegularEnum = 256,
	ValueModule = 512,
	NamespaceModule = 1024,
	TypeLiteral = 2048,
	ObjectLiteral = 4096,
	Method = 8192,
	Constructor = 16384,
	GetAccessor = 32768,
	SetAccessor = 65536,
	Signature = 131072,
	TypeParameter = 262144,
	TypeAlias = 524288,
	ExportValue = 1048576,
	Alias = 2097152,
	Prototype = 4194304,
	ExportStar = 8388608,
	Optional = 16777216,
	Transient = 33554432,
	Assignment = 67108864,
	ModuleExports = 134217728,
	Enum = 384,
	Variable = 3,
	Value = 67220415,
	Type = 67897832,
	Namespace = 1920,
	Module = 1536,
	Accessor = 98304,
	FunctionScopedVariableExcludes = 67220414,
	BlockScopedVariableExcludes = 67220415,
	ParameterExcludes = 67220415,
	PropertyExcludes = 0,
	EnumMemberExcludes = 68008959,
	FunctionExcludes = 67219887,
	ClassExcludes = 68008383,
	InterfaceExcludes = 67897736,
	RegularEnumExcludes = 68008191,
	ConstEnumExcludes = 68008831,
	ValueModuleExcludes = 110735,
	NamespaceModuleExcludes = 0,
	MethodExcludes = 67212223,
	GetAccessorExcludes = 67154879,
	SetAccessorExcludes = 67187647,
	TypeParameterExcludes = 67635688,
	TypeAliasExcludes = 67897832,
	AliasExcludes = 2097152,
	ModuleMember = 2623475,
	ExportHasLocal = 944,
	BlockScoped = 418,
	PropertyOrAccessor = 98308,
	ClassMember = 106500,
};
enum class _enum_js_jts_dInternalSymbolName {
	Call,
	Constructor,
	New,
	Index,
	ExportStar,
	Global,
	Missing,
	Type,
	Object,
	JSXAttributes,
	Class,
	Function,
	Computed,
	Resolving,
	ExportEquals,
	Default,
	This,
};
enum class _enum_js_jts_dTypeFlags {
	Any = 1,
	Unknown = 2,
	String = 4,
	Number = 8,
	Boolean = 16,
	Enum = 32,
	BigInt = 64,
	StringLiteral = 128,
	NumberLiteral = 256,
	BooleanLiteral = 512,
	EnumLiteral = 1024,
	BigIntLiteral = 2048,
	ESSymbol = 4096,
	UniqueESSymbol = 8192,
	Void = 16384,
	Undefined = 32768,
	Null = 65536,
	Never = 131072,
	TypeParameter = 262144,
	Object = 524288,
	Union = 1048576,
	Intersection = 2097152,
	Index = 4194304,
	IndexedAccess = 8388608,
	Conditional = 16777216,
	Substitution = 33554432,
	NonPrimitive = 67108864,
	Literal = 2944,
	Unit = 109440,
	StringOrNumberLiteral = 384,
	PossiblyFalsy = 117724,
	StringLike = 132,
	NumberLike = 296,
	BigIntLike = 2112,
	BooleanLike = 528,
	EnumLike = 1056,
	ESSymbolLike = 12288,
	VoidLike = 49152,
	UnionOrIntersection = 3145728,
	StructuredType = 3670016,
	TypeVariable = 8650752,
	InstantiableNonPrimitive = 58982400,
	InstantiablePrimitive = 4194304,
	Instantiable = 63176704,
	StructuredOrInstantiable = 66846720,
	Narrowable = 133970943,
	NotUnionOrUnit = 67637251,
};
enum class _enum_js_jts_dObjectFlags {
	Class = 1,
	Interface = 2,
	Reference = 4,
	Tuple = 8,
	Anonymous = 16,
	Mapped = 32,
	Instantiated = 64,
	ObjectLiteral = 128,
	EvolvingArray = 256,
	ObjectLiteralPatternWithComputedProperties = 512,
	ContainsSpread = 1024,
	ReverseMapped = 2048,
	JsxAttributes = 4096,
	MarkerType = 8192,
	JSLiteral = 16384,
	FreshLiteral = 32768,
	ClassOrInterface = 3,
};
enum class _enum_js_jts_dSignatureKind {
	Call = 0,
	Construct = 1,
};
enum class _enum_js_jts_dIndexKind {
	String = 0,
	Number = 1,
};
enum class _enum_js_jts_dInferencePriority {
	NakedTypeVariable = 1,
	HomomorphicMappedType = 2,
	PartialHomomorphicMappedType = 4,
	MappedTypeConstraint = 8,
	ReturnType = 16,
	LiteralKeyof = 32,
	NoConstraints = 64,
	AlwaysStrict = 128,
	PriorityImpliesCombination = 56,
};
enum class _enum_js_jts_dDiagnosticCategory {
	Warning = 0,
	Error = 1,
	Suggestion = 2,
	Message = 3,
};
enum class _enum_js_jts_dModuleResolutionKind {
	Classic = 1,
	NodeJs = 2,
};
enum class _enum_js_jts_dModuleKind {
	None = 0,
	CommonJS = 1,
	AMD = 2,
	UMD = 3,
	System = 4,
	ES2015 = 5,
	ESNext = 6,
};
enum class _enum_js_jts_dJsxEmit {
	None = 0,
	Preserve = 1,
	React = 2,
	ReactNative = 3,
};
enum class _enum_js_jts_dNewLineKind {
	CarriageReturnLineFeed = 0,
	LineFeed = 1,
};
enum class _enum_js_jts_dScriptKind {
	Unknown = 0,
	JS = 1,
	JSX = 2,
	TS = 3,
	TSX = 4,
	External = 5,
	JSON = 6,
	Deferred = 7,
};
enum class _enum_js_jts_dScriptTarget {
	ES3 = 0,
	ES5 = 1,
	ES2015 = 2,
	ES2016 = 3,
	ES2017 = 4,
	ES2018 = 5,
	ES2019 = 6,
	ES2020 = 7,
	ESNext = 8,
	JSON = 100,
	Latest = 8,
};
enum class _enum_js_jts_dLanguageVariant {
	Standard = 0,
	JSX = 1,
};
enum class _enum_js_jts_dWatchDirectoryFlags {
	None = 0,
	Recursive = 1,
};
enum class _enum_js_jts_dExtension {
	Ts,
	Tsx,
	Dts,
	Js,
	Jsx,
	Json,
	TsBuildInfo,
};
enum class _enum_js_jts_dEmitFlags {
	None = 0,
	SingleLine = 1,
	AdviseOnEmitNode = 2,
	NoSubstitution = 4,
	CapturesThis = 8,
	NoLeadingSourceMap = 16,
	NoTrailingSourceMap = 32,
	NoSourceMap = 48,
	NoNestedSourceMaps = 64,
	NoTokenLeadingSourceMaps = 128,
	NoTokenTrailingSourceMaps = 256,
	NoTokenSourceMaps = 384,
	NoLeadingComments = 512,
	NoTrailingComments = 1024,
	NoComments = 1536,
	NoNestedComments = 2048,
	HelperName = 4096,
	ExportName = 8192,
	LocalName = 16384,
	InternalName = 32768,
	Indented = 65536,
	NoIndentation = 131072,
	AsyncFunctionBody = 262144,
	ReuseTempVariableScope = 524288,
	CustomPrologue = 1048576,
	NoHoisting = 2097152,
	HasEndOfDeclarationMarker = 4194304,
	Iterator = 8388608,
	NoAsciiEscaping = 16777216,
};
enum class _enum_js_jts_dEmitHint {
	SourceFile = 0,
	Expression = 1,
	IdentifierName = 2,
	MappedTypeParameter = 3,
	Unspecified = 4,
	EmbeddedStatement = 5,
};
enum class _enum_js_jts_dListFormat {
	None = 0,
	SingleLine = 0,
	MultiLine = 1,
	PreserveLines = 2,
	LinesMask = 3,
	NotDelimited = 0,
	BarDelimited = 4,
	AmpersandDelimited = 8,
	CommaDelimited = 16,
	AsteriskDelimited = 32,
	DelimitersMask = 60,
	AllowTrailingComma = 64,
	Indented = 128,
	SpaceBetweenBraces = 256,
	SpaceBetweenSiblings = 512,
	Braces = 1024,
	Parenthesis = 2048,
	AngleBrackets = 4096,
	SquareBrackets = 8192,
	BracketsMask = 15360,
	OptionalIfUndefined = 16384,
	OptionalIfEmpty = 32768,
	Optional = 49152,
	PreferNewLine = 65536,
	NoTrailingNewLine = 131072,
	NoInterveningComments = 262144,
	NoSpaceIfEmpty = 524288,
	SingleElement = 1048576,
	Modifiers = 262656,
	HeritageClauses = 512,
	SingleLineTypeLiteralMembers = 768,
	MultiLineTypeLiteralMembers = 32897,
	TupleTypeElements = 528,
	UnionTypeConstituents = 516,
	IntersectionTypeConstituents = 520,
	ObjectBindingPatternElements = 525136,
	ArrayBindingPatternElements = 524880,
	ObjectLiteralExpressionProperties = 526226,
	ArrayLiteralExpressionElements = 8914,
	CommaListElements = 528,
	CallExpressionArguments = 2576,
	NewExpressionArguments = 18960,
	TemplateExpressionSpans = 262144,
	SingleLineBlockStatements = 768,
	MultiLineBlockStatements = 129,
	VariableDeclarationList = 528,
	SingleLineFunctionBodyStatements = 768,
	MultiLineFunctionBodyStatements = 1,
	ClassHeritageClauses = 0,
	ClassMembers = 129,
	InterfaceMembers = 129,
	EnumMembers = 145,
	CaseBlockClauses = 129,
	NamedImportsOrExportsElements = 525136,
	JsxElementOrFragmentChildren = 262144,
	JsxElementAttributes = 262656,
	CaseOrDefaultClauseStatements = 163969,
	HeritageClauseTypes = 528,
	SourceFileStatements = 131073,
	Decorators = 49153,
	TypeArguments = 53776,
	TypeParameters = 53776,
	Parameters = 2576,
	IndexSignatureParameters = 8848,
	JSDocComment = 33,
};
enum class _enum_js_jts_dFileWatcherEventKind {
	Created = 0,
	Changed = 1,
	Deleted = 2,
};
enum class _enum_js_jts_dHighlightSpanKind {
	none,
	definition,
	reference,
	writtenReference,
};
enum class _enum_js_jts_dIndentStyle {
	None = 0,
	Block = 1,
	Smart = 2,
};
enum class _enum_js_jts_dSymbolDisplayPartKind {
	aliasName = 0,
	className = 1,
	enumName = 2,
	fieldName = 3,
	interfaceName = 4,
	keyword = 5,
	lineBreak = 6,
	numericLiteral = 7,
	stringLiteral = 8,
	localName = 9,
	methodName = 10,
	moduleName = 11,
	operator_ = 12,
	parameterName = 13,
	propertyName = 14,
	punctuation = 15,
	space = 16,
	text = 17,
	typeParameterName = 18,
	enumMemberName = 19,
	functionName = 20,
	regularExpressionLiteral = 21,
};
enum class _enum_js_jts_dOutliningSpanKind {
	Comment,
	Region,
	Code,
	Imports,
};
enum class _enum_js_jts_dOutputFileType {
	JavaScript = 0,
	SourceMap = 1,
	Declaration = 2,
};
enum class _enum_js_jts_dEndOfLineState {
	None = 0,
	InMultiLineCommentTrivia = 1,
	InSingleQuoteStringLiteral = 2,
	InDoubleQuoteStringLiteral = 3,
	InTemplateHeadOrNoSubstitutionTemplate = 4,
	InTemplateMiddleOrTail = 5,
	InTemplateSubstitutionPosition = 6,
};
enum class _enum_js_jts_dTokenClass {
	Punctuation = 0,
	Keyword = 1,
	Operator = 2,
	Comment = 3,
	Whitespace = 4,
	Identifier = 5,
	NumberLiteral = 6,
	BigIntLiteral = 7,
	StringLiteral = 8,
	RegExpLiteral = 9,
};
enum class _enum_js_jts_dScriptElementKind {
	unknown,
	warning,
	keyword,
	scriptElement,
	moduleElement,
	classElement,
	localClassElement,
	interfaceElement,
	typeElement,
	enumElement,
	enumMemberElement,
	variableElement,
	localVariableElement,
	functionElement,
	localFunctionElement,
	memberFunctionElement,
	memberGetAccessorElement,
	memberSetAccessorElement,
	memberVariableElement,
	constructorImplementationElement,
	callSignatureElement,
	indexSignatureElement,
	constructSignatureElement,
	parameterElement,
	typeParameterElement,
	primitiveType,
	label,
	alias,
	constElement,
	letElement,
	directory,
	externalModuleName,
	jsxAttribute,
	string,
};
enum class _enum_js_jts_dScriptElementKindModifier {
	none,
	publicMemberModifier,
	privateMemberModifier,
	protectedMemberModifier,
	exportedModifier,
	ambientModifier,
	staticModifier,
	abstractModifier,
	optionalModifier,
	dtsModifier,
	tsModifier,
	tsxModifier,
	jsModifier,
	jsxModifier,
	jsonModifier,
};
enum class _enum_js_jts_dClassificationTypeNames {
	comment,
	identifier,
	keyword,
	numericLiteral,
	bigintLiteral,
	operator_,
	stringLiteral,
	whiteSpace,
	text,
	punctuation,
	className,
	enumName,
	interfaceName,
	moduleName,
	typeParameterName,
	typeAliasName,
	parameterName,
	docCommentTagName,
	jsxOpenTagName,
	jsxCloseTagName,
	jsxSelfClosingTagName,
	jsxAttribute,
	jsxText,
	jsxAttributeStringLiteralValue,
};
enum class _enum_js_jts_dClassificationType {
	comment = 1,
	identifier = 2,
	keyword = 3,
	numericLiteral = 4,
	operator_ = 5,
	stringLiteral = 6,
	regularExpressionLiteral = 7,
	whiteSpace = 8,
	text = 9,
	punctuation = 10,
	className = 11,
	enumName = 12,
	interfaceName = 13,
	moduleName = 14,
	typeParameterName = 15,
	typeAliasName = 16,
	parameterName = 17,
	docCommentTagName = 18,
	jsxOpenTagName = 19,
	jsxCloseTagName = 20,
	jsxSelfClosingTagName = 21,
	jsxAttribute = 22,
	jsxText = 23,
	jsxAttributeStringLiteralValue = 24,
	bigintLiteral = 25,
};
} // namespace tc::js_defs
namespace tc::jst {
template<> struct IsJsIntegralEnum<js_defs::_enum_js_jts_dSyntaxKind> : std::true_type {};
template<> struct IsJsIntegralEnum<js_defs::_enum_js_jts_dNodeFlags> : std::true_type {};
template<> struct IsJsIntegralEnum<js_defs::_enum_js_jts_dModifierFlags> : std::true_type {};
template<> struct IsJsIntegralEnum<js_defs::_enum_js_jts_dJsxFlags> : std::true_type {};
template<> struct IsJsIntegralEnum<js_defs::_enum_js_jts_dTokenFlags> : std::true_type {};
template<> struct IsJsIntegralEnum<js_defs::_enum_js_jts_dFlowFlags> : std::true_type {};
template<> struct IsJsIntegralEnum<js_defs::_enum_js_jts_dExitStatus> : std::true_type {};
template<> struct IsJsIntegralEnum<js_defs::_enum_js_jts_dNodeBuilderFlags> : std::true_type {};
template<> struct IsJsIntegralEnum<js_defs::_enum_js_jts_dTypeFormatFlags> : std::true_type {};
template<> struct IsJsIntegralEnum<js_defs::_enum_js_jts_dSymbolFormatFlags> : std::true_type {};
template<> struct IsJsIntegralEnum<js_defs::_enum_js_jts_dTypePredicateKind> : std::true_type {};
template<> struct IsJsIntegralEnum<js_defs::_enum_js_jts_dSymbolFlags> : std::true_type {};
template<> struct IsJsHeterogeneousEnum<js_defs::_enum_js_jts_dInternalSymbolName> : std::true_type {
	static inline auto const& Values() {
		using E = js_defs::_enum_js_jts_dInternalSymbolName;
		static tc::unordered_map<E, jst::js_unknown> vals{
			{E::Call, js_string("__call")},
			{E::Constructor, js_string("__constructor")},
			{E::New, js_string("__new")},
			{E::Index, js_string("__index")},
			{E::ExportStar, js_string("__export")},
			{E::Global, js_string("__global")},
			{E::Missing, js_string("__missing")},
			{E::Type, js_string("__type")},
			{E::Object, js_string("__object")},
			{E::JSXAttributes, js_string("__jsxAttributes")},
			{E::Class, js_string("__class")},
			{E::Function, js_string("__function")},
			{E::Computed, js_string("__computed")},
			{E::Resolving, js_string("__resolving__")},
			{E::ExportEquals, js_string("export=")},
			{E::Default, js_string("default")},
			{E::This, js_string("this")}
		};
		return vals;
	}
};
template<> struct IsJsIntegralEnum<js_defs::_enum_js_jts_dTypeFlags> : std::true_type {};
template<> struct IsJsIntegralEnum<js_defs::_enum_js_jts_dObjectFlags> : std::true_type {};
template<> struct IsJsIntegralEnum<js_defs::_enum_js_jts_dSignatureKind> : std::true_type {};
template<> struct IsJsIntegralEnum<js_defs::_enum_js_jts_dIndexKind> : std::true_type {};
template<> struct IsJsIntegralEnum<js_defs::_enum_js_jts_dInferencePriority> : std::true_type {};
template<> struct IsJsIntegralEnum<js_defs::_enum_js_jts_dDiagnosticCategory> : std::true_type {};
template<> struct IsJsIntegralEnum<js_defs::_enum_js_jts_dModuleResolutionKind> : std::true_type {};
template<> struct IsJsIntegralEnum<js_defs::_enum_js_jts_dModuleKind> : std::true_type {};
template<> struct IsJsIntegralEnum<js_defs::_enum_js_jts_dJsxEmit> : std::true_type {};
template<> struct IsJsIntegralEnum<js_defs::_enum_js_jts_dNewLineKind> : std::true_type {};
template<> struct IsJsIntegralEnum<js_defs::_enum_js_jts_dScriptKind> : std::true_type {};
template<> struct IsJsIntegralEnum<js_defs::_enum_js_jts_dScriptTarget> : std::true_type {};
template<> struct IsJsIntegralEnum<js_defs::_enum_js_jts_dLanguageVariant> : std::true_type {};
template<> struct IsJsIntegralEnum<js_defs::_enum_js_jts_dWatchDirectoryFlags> : std::true_type {};
template<> struct IsJsHeterogeneousEnum<js_defs::_enum_js_jts_dExtension> : std::true_type {
	static inline auto const& Values() {
		using E = js_defs::_enum_js_jts_dExtension;
		static tc::unordered_map<E, jst::js_unknown> vals{
			{E::Ts, js_string(".ts")},
			{E::Tsx, js_string(".tsx")},
			{E::Dts, js_string(".d.ts")},
			{E::Js, js_string(".js")},
			{E::Jsx, js_string(".jsx")},
			{E::Json, js_string(".json")},
			{E::TsBuildInfo, js_string(".tsbuildinfo")}
		};
		return vals;
	}
};
template<> struct IsJsIntegralEnum<js_defs::_enum_js_jts_dEmitFlags> : std::true_type {};
template<> struct IsJsIntegralEnum<js_defs::_enum_js_jts_dEmitHint> : std::true_type {};
template<> struct IsJsIntegralEnum<js_defs::_enum_js_jts_dListFormat> : std::true_type {};
template<> struct IsJsIntegralEnum<js_defs::_enum_js_jts_dFileWatcherEventKind> : std::true_type {};
template<> struct IsJsHeterogeneousEnum<js_defs::_enum_js_jts_dHighlightSpanKind> : std::true_type {
	static inline auto const& Values() {
		using E = js_defs::_enum_js_jts_dHighlightSpanKind;
		static tc::unordered_map<E, jst::js_unknown> vals{
			{E::none, js_string("none")},
			{E::definition, js_string("definition")},
			{E::reference, js_string("reference")},
			{E::writtenReference, js_string("writtenReference")}
		};
		return vals;
	}
};
template<> struct IsJsIntegralEnum<js_defs::_enum_js_jts_dIndentStyle> : std::true_type {};
template<> struct IsJsIntegralEnum<js_defs::_enum_js_jts_dSymbolDisplayPartKind> : std::true_type {};
template<> struct IsJsHeterogeneousEnum<js_defs::_enum_js_jts_dOutliningSpanKind> : std::true_type {
	static inline auto const& Values() {
		using E = js_defs::_enum_js_jts_dOutliningSpanKind;
		static tc::unordered_map<E, jst::js_unknown> vals{
			{E::Comment, js_string("comment")},
			{E::Region, js_string("region")},
			{E::Code, js_string("code")},
			{E::Imports, js_string("imports")}
		};
		return vals;
	}
};
template<> struct IsJsIntegralEnum<js_defs::_enum_js_jts_dOutputFileType> : std::true_type {};
template<> struct IsJsIntegralEnum<js_defs::_enum_js_jts_dEndOfLineState> : std::true_type {};
template<> struct IsJsIntegralEnum<js_defs::_enum_js_jts_dTokenClass> : std::true_type {};
template<> struct IsJsHeterogeneousEnum<js_defs::_enum_js_jts_dScriptElementKind> : std::true_type {
	static inline auto const& Values() {
		using E = js_defs::_enum_js_jts_dScriptElementKind;
		static tc::unordered_map<E, jst::js_unknown> vals{
			{E::unknown, js_string("")},
			{E::warning, js_string("warning")},
			{E::keyword, js_string("keyword")},
			{E::scriptElement, js_string("script")},
			{E::moduleElement, js_string("module")},
			{E::classElement, js_string("class")},
			{E::localClassElement, js_string("local class")},
			{E::interfaceElement, js_string("interface")},
			{E::typeElement, js_string("type")},
			{E::enumElement, js_string("enum")},
			{E::enumMemberElement, js_string("enum member")},
			{E::variableElement, js_string("var")},
			{E::localVariableElement, js_string("local var")},
			{E::functionElement, js_string("function")},
			{E::localFunctionElement, js_string("local function")},
			{E::memberFunctionElement, js_string("method")},
			{E::memberGetAccessorElement, js_string("getter")},
			{E::memberSetAccessorElement, js_string("setter")},
			{E::memberVariableElement, js_string("property")},
			{E::constructorImplementationElement, js_string("constructor")},
			{E::callSignatureElement, js_string("call")},
			{E::indexSignatureElement, js_string("index")},
			{E::constructSignatureElement, js_string("construct")},
			{E::parameterElement, js_string("parameter")},
			{E::typeParameterElement, js_string("type parameter")},
			{E::primitiveType, js_string("primitive type")},
			{E::label, js_string("label")},
			{E::alias, js_string("alias")},
			{E::constElement, js_string("const")},
			{E::letElement, js_string("let")},
			{E::directory, js_string("directory")},
			{E::externalModuleName, js_string("external module name")},
			{E::jsxAttribute, js_string("JSX attribute")},
			{E::string, js_string("string")}
		};
		return vals;
	}
};
template<> struct IsJsHeterogeneousEnum<js_defs::_enum_js_jts_dScriptElementKindModifier> : std::true_type {
	static inline auto const& Values() {
		using E = js_defs::_enum_js_jts_dScriptElementKindModifier;
		static tc::unordered_map<E, jst::js_unknown> vals{
			{E::none, js_string("")},
			{E::publicMemberModifier, js_string("public")},
			{E::privateMemberModifier, js_string("private")},
			{E::protectedMemberModifier, js_string("protected")},
			{E::exportedModifier, js_string("export")},
			{E::ambientModifier, js_string("declare")},
			{E::staticModifier, js_string("static")},
			{E::abstractModifier, js_string("abstract")},
			{E::optionalModifier, js_string("optional")},
			{E::dtsModifier, js_string(".d.ts")},
			{E::tsModifier, js_string(".ts")},
			{E::tsxModifier, js_string(".tsx")},
			{E::jsModifier, js_string(".js")},
			{E::jsxModifier, js_string(".jsx")},
			{E::jsonModifier, js_string(".json")}
		};
		return vals;
	}
};
template<> struct IsJsHeterogeneousEnum<js_defs::_enum_js_jts_dClassificationTypeNames> : std::true_type {
	static inline auto const& Values() {
		using E = js_defs::_enum_js_jts_dClassificationTypeNames;
		static tc::unordered_map<E, jst::js_unknown> vals{
			{E::comment, js_string("comment")},
			{E::identifier, js_string("identifier")},
			{E::keyword, js_string("keyword")},
			{E::numericLiteral, js_string("number")},
			{E::bigintLiteral, js_string("bigint")},
			{E::operator_, js_string("operator")},
			{E::stringLiteral, js_string("string")},
			{E::whiteSpace, js_string("whitespace")},
			{E::text, js_string("text")},
			{E::punctuation, js_string("punctuation")},
			{E::className, js_string("class name")},
			{E::enumName, js_string("enum name")},
			{E::interfaceName, js_string("interface name")},
			{E::moduleName, js_string("module name")},
			{E::typeParameterName, js_string("type parameter name")},
			{E::typeAliasName, js_string("type alias name")},
			{E::parameterName, js_string("parameter name")},
			{E::docCommentTagName, js_string("doc comment tag name")},
			{E::jsxOpenTagName, js_string("jsx open tag name")},
			{E::jsxCloseTagName, js_string("jsx close tag name")},
			{E::jsxSelfClosingTagName, js_string("jsx self closing tag name")},
			{E::jsxAttribute, js_string("jsx attribute")},
			{E::jsxText, js_string("jsx text")},
			{E::jsxAttributeStringLiteralValue, js_string("jsx attribute string literal value")}
		};
		return vals;
	}
};
template<> struct IsJsIntegralEnum<js_defs::_enum_js_jts_dClassificationType> : std::true_type {};
} // namespace tc::jst
namespace tc::js_defs {
	using namespace jst; // no ADL
	using _js_jts_dSyntaxKind = _enum_js_jts_dSyntaxKind;
	using _js_jts_dNodeFlags = _enum_js_jts_dNodeFlags;
	using _js_jts_dModifierFlags = _enum_js_jts_dModifierFlags;
	using _js_jts_dJsxFlags = _enum_js_jts_dJsxFlags;
	using _js_jts_dTokenFlags = _enum_js_jts_dTokenFlags;
	using _js_jts_dFlowFlags = _enum_js_jts_dFlowFlags;
	using _js_jts_dExitStatus = _enum_js_jts_dExitStatus;
	using _js_jts_dNodeBuilderFlags = _enum_js_jts_dNodeBuilderFlags;
	using _js_jts_dTypeFormatFlags = _enum_js_jts_dTypeFormatFlags;
	using _js_jts_dSymbolFormatFlags = _enum_js_jts_dSymbolFormatFlags;
	using _js_jts_dTypePredicateKind = _enum_js_jts_dTypePredicateKind;
	using _js_jts_dSymbolFlags = _enum_js_jts_dSymbolFlags;
	using _js_jts_dInternalSymbolName = _enum_js_jts_dInternalSymbolName;
	using _js_jts_dTypeFlags = _enum_js_jts_dTypeFlags;
	using _js_jts_dObjectFlags = _enum_js_jts_dObjectFlags;
	using _js_jts_dSignatureKind = _enum_js_jts_dSignatureKind;
	using _js_jts_dIndexKind = _enum_js_jts_dIndexKind;
	using _js_jts_dInferencePriority = _enum_js_jts_dInferencePriority;
	using _js_jts_dDiagnosticCategory = _enum_js_jts_dDiagnosticCategory;
	using _js_jts_dModuleResolutionKind = _enum_js_jts_dModuleResolutionKind;
	using _js_jts_dModuleKind = _enum_js_jts_dModuleKind;
	using _js_jts_dJsxEmit = _enum_js_jts_dJsxEmit;
	using _js_jts_dNewLineKind = _enum_js_jts_dNewLineKind;
	using _js_jts_dScriptKind = _enum_js_jts_dScriptKind;
	using _js_jts_dScriptTarget = _enum_js_jts_dScriptTarget;
	using _js_jts_dLanguageVariant = _enum_js_jts_dLanguageVariant;
	using _js_jts_dWatchDirectoryFlags = _enum_js_jts_dWatchDirectoryFlags;
	using _js_jts_dExtension = _enum_js_jts_dExtension;
	using _js_jts_dEmitFlags = _enum_js_jts_dEmitFlags;
	using _js_jts_dEmitHint = _enum_js_jts_dEmitHint;
	using _js_jts_dListFormat = _enum_js_jts_dListFormat;
	using _js_jts_dFileWatcherEventKind = _enum_js_jts_dFileWatcherEventKind;
	using _js_jts_dHighlightSpanKind = _enum_js_jts_dHighlightSpanKind;
	using _js_jts_dIndentStyle = _enum_js_jts_dIndentStyle;
	using _js_jts_dSymbolDisplayPartKind = _enum_js_jts_dSymbolDisplayPartKind;
	using _js_jts_dOutliningSpanKind = _enum_js_jts_dOutliningSpanKind;
	using _js_jts_dOutputFileType = _enum_js_jts_dOutputFileType;
	using _js_jts_dEndOfLineState = _enum_js_jts_dEndOfLineState;
	using _js_jts_dTokenClass = _enum_js_jts_dTokenClass;
	using _js_jts_dScriptElementKind = _enum_js_jts_dScriptElementKind;
	using _js_jts_dScriptElementKindModifier = _enum_js_jts_dScriptElementKindModifier;
	using _js_jts_dClassificationTypeNames = _enum_js_jts_dClassificationTypeNames;
	using _js_jts_dClassificationType = _enum_js_jts_dClassificationType;
	struct _impl_js_j_qts_q;
	using _js_j_qts_q = js_ref<_impl_js_j_qts_q>;
	struct _impl_js_jts_dMapLike;
	using _js_jts_dMapLike = js_ref<_impl_js_jts_dMapLike>;
	struct _impl_js_jts_dSortedReadonlyArray;
	using _js_jts_dSortedReadonlyArray = js_ref<_impl_js_jts_dSortedReadonlyArray>;
	struct _impl_js_jts_dSortedArray;
	using _js_jts_dSortedArray = js_ref<_impl_js_jts_dSortedArray>;
	struct _impl_js_jts_dReadonlyMap;
	using _js_jts_dReadonlyMap = js_ref<_impl_js_jts_dReadonlyMap>;
	struct _impl_js_jts_dMap;
	using _js_jts_dMap = js_ref<_impl_js_jts_dMap>;
	struct _impl_js_jts_dIterator;
	using _js_jts_dIterator = js_ref<_impl_js_jts_dIterator>;
	struct _impl_js_jts_dPush;
	using _js_jts_dPush = js_ref<_impl_js_jts_dPush>;
	struct _impl_js_jts_dTextRange;
	using _js_jts_dTextRange = js_ref<_impl_js_jts_dTextRange>;
	struct _impl_js_jts_dNode;
	using _js_jts_dNode = js_ref<_impl_js_jts_dNode>;
	struct _impl_js_jts_dJSDocContainer;
	using _js_jts_dJSDocContainer = js_ref<_impl_js_jts_dJSDocContainer>;
	struct _impl_js_jts_dNodeArray;
	using _js_jts_dNodeArray = js_ref<_impl_js_jts_dNodeArray>;
	struct _impl_js_jts_dToken;
	using _js_jts_dToken = js_ref<_impl_js_jts_dToken>;
	struct _impl_js_jts_dExpression;
	using _js_jts_dExpression = js_ref<_impl_js_jts_dExpression>;
	struct _impl_js_jts_dUnaryExpression;
	using _js_jts_dUnaryExpression = js_ref<_impl_js_jts_dUnaryExpression>;
	struct _impl_js_jts_dUpdateExpression;
	using _js_jts_dUpdateExpression = js_ref<_impl_js_jts_dUpdateExpression>;
	struct _impl_js_jts_dLeftHandSideExpression;
	using _js_jts_dLeftHandSideExpression = js_ref<_impl_js_jts_dLeftHandSideExpression>;
	struct _impl_js_jts_dMemberExpression;
	using _js_jts_dMemberExpression = js_ref<_impl_js_jts_dMemberExpression>;
	struct _impl_js_jts_dPrimaryExpression;
	using _js_jts_dPrimaryExpression = js_ref<_impl_js_jts_dPrimaryExpression>;
	struct _impl_js_jts_dDeclaration;
	using _js_jts_dDeclaration = js_ref<_impl_js_jts_dDeclaration>;
	struct _impl_js_jts_dIdentifier;
	using _js_jts_dIdentifier = js_ref<_impl_js_jts_dIdentifier>;
	struct _impl_js_jts_dTransientIdentifier;
	using _js_jts_dTransientIdentifier = js_ref<_impl_js_jts_dTransientIdentifier>;
	struct _impl_js_jts_dQualifiedName;
	using _js_jts_dQualifiedName = js_ref<_impl_js_jts_dQualifiedName>;
	struct _impl_js_jts_dNamedDeclaration;
	using _js_jts_dNamedDeclaration = js_ref<_impl_js_jts_dNamedDeclaration>;
	struct _impl_js_jts_dStatement;
	using _js_jts_dStatement = js_ref<_impl_js_jts_dStatement>;
	struct _impl_js_jts_dDeclarationStatement;
	using _js_jts_dDeclarationStatement = js_ref<_impl_js_jts_dDeclarationStatement>;
	struct _impl_js_jts_dComputedPropertyName;
	using _js_jts_dComputedPropertyName = js_ref<_impl_js_jts_dComputedPropertyName>;
	struct _impl_js_jts_dDecorator;
	using _js_jts_dDecorator = js_ref<_impl_js_jts_dDecorator>;
	struct _impl_js_jts_dTypeParameterDeclaration;
	using _js_jts_dTypeParameterDeclaration = js_ref<_impl_js_jts_dTypeParameterDeclaration>;
	struct _impl_js_jts_dSignatureDeclarationBase;
	using _js_jts_dSignatureDeclarationBase = js_ref<_impl_js_jts_dSignatureDeclarationBase>;
	struct _impl_js_jts_dTypeElement;
	using _js_jts_dTypeElement = js_ref<_impl_js_jts_dTypeElement>;
	struct _impl_js_jts_dCallSignatureDeclaration;
	using _js_jts_dCallSignatureDeclaration = js_ref<_impl_js_jts_dCallSignatureDeclaration>;
	struct _impl_js_jts_dConstructSignatureDeclaration;
	using _js_jts_dConstructSignatureDeclaration = js_ref<_impl_js_jts_dConstructSignatureDeclaration>;
	struct _impl_js_jts_dVariableDeclaration;
	using _js_jts_dVariableDeclaration = js_ref<_impl_js_jts_dVariableDeclaration>;
	struct _impl_js_jts_dVariableDeclarationList;
	using _js_jts_dVariableDeclarationList = js_ref<_impl_js_jts_dVariableDeclarationList>;
	struct _impl_js_jts_dParameterDeclaration;
	using _js_jts_dParameterDeclaration = js_ref<_impl_js_jts_dParameterDeclaration>;
	struct _impl_js_jts_dBindingElement;
	using _js_jts_dBindingElement = js_ref<_impl_js_jts_dBindingElement>;
	struct _impl_js_jts_dPropertySignature;
	using _js_jts_dPropertySignature = js_ref<_impl_js_jts_dPropertySignature>;
	struct _impl_js_jts_dClassElement;
	using _js_jts_dClassElement = js_ref<_impl_js_jts_dClassElement>;
	struct _impl_js_jts_dPropertyDeclaration;
	using _js_jts_dPropertyDeclaration = js_ref<_impl_js_jts_dPropertyDeclaration>;
	struct _impl_js_jts_dObjectLiteralElement;
	using _js_jts_dObjectLiteralElement = js_ref<_impl_js_jts_dObjectLiteralElement>;
	struct _impl_js_jts_dPropertyAssignment;
	using _js_jts_dPropertyAssignment = js_ref<_impl_js_jts_dPropertyAssignment>;
	struct _impl_js_jts_dShorthandPropertyAssignment;
	using _js_jts_dShorthandPropertyAssignment = js_ref<_impl_js_jts_dShorthandPropertyAssignment>;
	struct _impl_js_jts_dSpreadAssignment;
	using _js_jts_dSpreadAssignment = js_ref<_impl_js_jts_dSpreadAssignment>;
	struct _impl_js_jts_dPropertyLikeDeclaration;
	using _js_jts_dPropertyLikeDeclaration = js_ref<_impl_js_jts_dPropertyLikeDeclaration>;
	struct _impl_js_jts_dObjectBindingPattern;
	using _js_jts_dObjectBindingPattern = js_ref<_impl_js_jts_dObjectBindingPattern>;
	struct _impl_js_jts_dArrayBindingPattern;
	using _js_jts_dArrayBindingPattern = js_ref<_impl_js_jts_dArrayBindingPattern>;
	struct _impl_js_jts_dFunctionLikeDeclarationBase;
	using _js_jts_dFunctionLikeDeclarationBase = js_ref<_impl_js_jts_dFunctionLikeDeclarationBase>;
	struct _impl_js_jts_dFunctionDeclaration;
	using _js_jts_dFunctionDeclaration = js_ref<_impl_js_jts_dFunctionDeclaration>;
	struct _impl_js_jts_dMethodSignature;
	using _js_jts_dMethodSignature = js_ref<_impl_js_jts_dMethodSignature>;
	struct _impl_js_jts_dMethodDeclaration;
	using _js_jts_dMethodDeclaration = js_ref<_impl_js_jts_dMethodDeclaration>;
	struct _impl_js_jts_dConstructorDeclaration;
	using _js_jts_dConstructorDeclaration = js_ref<_impl_js_jts_dConstructorDeclaration>;
	struct _impl_js_jts_dSemicolonClassElement;
	using _js_jts_dSemicolonClassElement = js_ref<_impl_js_jts_dSemicolonClassElement>;
	struct _impl_js_jts_dGetAccessorDeclaration;
	using _js_jts_dGetAccessorDeclaration = js_ref<_impl_js_jts_dGetAccessorDeclaration>;
	struct _impl_js_jts_dSetAccessorDeclaration;
	using _js_jts_dSetAccessorDeclaration = js_ref<_impl_js_jts_dSetAccessorDeclaration>;
	struct _impl_js_jts_dIndexSignatureDeclaration;
	using _js_jts_dIndexSignatureDeclaration = js_ref<_impl_js_jts_dIndexSignatureDeclaration>;
	struct _impl_js_jts_dTypeNode;
	using _js_jts_dTypeNode = js_ref<_impl_js_jts_dTypeNode>;
	struct _impl_js_jts_dKeywordTypeNode;
	using _js_jts_dKeywordTypeNode = js_ref<_impl_js_jts_dKeywordTypeNode>;
	struct _impl_js_jts_dNodeWithTypeArguments;
	using _js_jts_dNodeWithTypeArguments = js_ref<_impl_js_jts_dNodeWithTypeArguments>;
	struct _impl_js_jts_dImportTypeNode;
	using _js_jts_dImportTypeNode = js_ref<_impl_js_jts_dImportTypeNode>;
	struct _impl_js_jts_dThisTypeNode;
	using _js_jts_dThisTypeNode = js_ref<_impl_js_jts_dThisTypeNode>;
	struct _impl_js_jts_dFunctionOrConstructorTypeNodeBase;
	using _js_jts_dFunctionOrConstructorTypeNodeBase = js_ref<_impl_js_jts_dFunctionOrConstructorTypeNodeBase>;
	struct _impl_js_jts_dFunctionTypeNode;
	using _js_jts_dFunctionTypeNode = js_ref<_impl_js_jts_dFunctionTypeNode>;
	struct _impl_js_jts_dConstructorTypeNode;
	using _js_jts_dConstructorTypeNode = js_ref<_impl_js_jts_dConstructorTypeNode>;
	struct _impl_js_jts_dTypeReferenceNode;
	using _js_jts_dTypeReferenceNode = js_ref<_impl_js_jts_dTypeReferenceNode>;
	struct _impl_js_jts_dTypePredicateNode;
	using _js_jts_dTypePredicateNode = js_ref<_impl_js_jts_dTypePredicateNode>;
	struct _impl_js_jts_dTypeQueryNode;
	using _js_jts_dTypeQueryNode = js_ref<_impl_js_jts_dTypeQueryNode>;
	struct _impl_js_jts_dTypeLiteralNode;
	using _js_jts_dTypeLiteralNode = js_ref<_impl_js_jts_dTypeLiteralNode>;
	struct _impl_js_jts_dArrayTypeNode;
	using _js_jts_dArrayTypeNode = js_ref<_impl_js_jts_dArrayTypeNode>;
	struct _impl_js_jts_dTupleTypeNode;
	using _js_jts_dTupleTypeNode = js_ref<_impl_js_jts_dTupleTypeNode>;
	struct _impl_js_jts_dOptionalTypeNode;
	using _js_jts_dOptionalTypeNode = js_ref<_impl_js_jts_dOptionalTypeNode>;
	struct _impl_js_jts_dRestTypeNode;
	using _js_jts_dRestTypeNode = js_ref<_impl_js_jts_dRestTypeNode>;
	struct _impl_js_jts_dUnionTypeNode;
	using _js_jts_dUnionTypeNode = js_ref<_impl_js_jts_dUnionTypeNode>;
	struct _impl_js_jts_dIntersectionTypeNode;
	using _js_jts_dIntersectionTypeNode = js_ref<_impl_js_jts_dIntersectionTypeNode>;
	struct _impl_js_jts_dConditionalTypeNode;
	using _js_jts_dConditionalTypeNode = js_ref<_impl_js_jts_dConditionalTypeNode>;
	struct _impl_js_jts_dInferTypeNode;
	using _js_jts_dInferTypeNode = js_ref<_impl_js_jts_dInferTypeNode>;
	struct _impl_js_jts_dParenthesizedTypeNode;
	using _js_jts_dParenthesizedTypeNode = js_ref<_impl_js_jts_dParenthesizedTypeNode>;
	struct _impl_js_jts_dTypeOperatorNode;
	using _js_jts_dTypeOperatorNode = js_ref<_impl_js_jts_dTypeOperatorNode>;
	struct _impl_js_jts_dIndexedAccessTypeNode;
	using _js_jts_dIndexedAccessTypeNode = js_ref<_impl_js_jts_dIndexedAccessTypeNode>;
	struct _impl_js_jts_dMappedTypeNode;
	using _js_jts_dMappedTypeNode = js_ref<_impl_js_jts_dMappedTypeNode>;
	struct _impl_js_jts_dLiteralTypeNode;
	using _js_jts_dLiteralTypeNode = js_ref<_impl_js_jts_dLiteralTypeNode>;
	struct _impl_js_jts_dLiteralLikeNode;
	using _js_jts_dLiteralLikeNode = js_ref<_impl_js_jts_dLiteralLikeNode>;
	struct _impl_js_jts_dLiteralExpression;
	using _js_jts_dLiteralExpression = js_ref<_impl_js_jts_dLiteralExpression>;
	struct _impl_js_jts_dStringLiteral;
	using _js_jts_dStringLiteral = js_ref<_impl_js_jts_dStringLiteral>;
	struct _impl_js_jts_dOmittedExpression;
	using _js_jts_dOmittedExpression = js_ref<_impl_js_jts_dOmittedExpression>;
	struct _impl_js_jts_dPartiallyEmittedExpression;
	using _js_jts_dPartiallyEmittedExpression = js_ref<_impl_js_jts_dPartiallyEmittedExpression>;
	struct _impl_js_jts_dPrefixUnaryExpression;
	using _js_jts_dPrefixUnaryExpression = js_ref<_impl_js_jts_dPrefixUnaryExpression>;
	struct _impl_js_jts_dPostfixUnaryExpression;
	using _js_jts_dPostfixUnaryExpression = js_ref<_impl_js_jts_dPostfixUnaryExpression>;
	struct _impl_js_jts_dNullLiteral;
	using _js_jts_dNullLiteral = js_ref<_impl_js_jts_dNullLiteral>;
	struct _impl_js_jts_dBooleanLiteral;
	using _js_jts_dBooleanLiteral = js_ref<_impl_js_jts_dBooleanLiteral>;
	struct _impl_js_jts_dThisExpression;
	using _js_jts_dThisExpression = js_ref<_impl_js_jts_dThisExpression>;
	struct _impl_js_jts_dSuperExpression;
	using _js_jts_dSuperExpression = js_ref<_impl_js_jts_dSuperExpression>;
	struct _impl_js_jts_dImportExpression;
	using _js_jts_dImportExpression = js_ref<_impl_js_jts_dImportExpression>;
	struct _impl_js_jts_dDeleteExpression;
	using _js_jts_dDeleteExpression = js_ref<_impl_js_jts_dDeleteExpression>;
	struct _impl_js_jts_dTypeOfExpression;
	using _js_jts_dTypeOfExpression = js_ref<_impl_js_jts_dTypeOfExpression>;
	struct _impl_js_jts_dVoidExpression;
	using _js_jts_dVoidExpression = js_ref<_impl_js_jts_dVoidExpression>;
	struct _impl_js_jts_dAwaitExpression;
	using _js_jts_dAwaitExpression = js_ref<_impl_js_jts_dAwaitExpression>;
	struct _impl_js_jts_dYieldExpression;
	using _js_jts_dYieldExpression = js_ref<_impl_js_jts_dYieldExpression>;
	struct _impl_js_jts_dSyntheticExpression;
	using _js_jts_dSyntheticExpression = js_ref<_impl_js_jts_dSyntheticExpression>;
	struct _impl_js_jts_dBinaryExpression;
	using _js_jts_dBinaryExpression = js_ref<_impl_js_jts_dBinaryExpression>;
	struct _impl_js_jts_dAssignmentExpression;
	using _js_jts_dAssignmentExpression = js_ref<_impl_js_jts_dAssignmentExpression>;
	struct _impl_js_jts_dObjectDestructuringAssignment;
	using _js_jts_dObjectDestructuringAssignment = js_ref<_impl_js_jts_dObjectDestructuringAssignment>;
	struct _impl_js_jts_dArrayDestructuringAssignment;
	using _js_jts_dArrayDestructuringAssignment = js_ref<_impl_js_jts_dArrayDestructuringAssignment>;
	struct _impl_js_jts_dConditionalExpression;
	using _js_jts_dConditionalExpression = js_ref<_impl_js_jts_dConditionalExpression>;
	struct _impl_js_jts_dFunctionExpression;
	using _js_jts_dFunctionExpression = js_ref<_impl_js_jts_dFunctionExpression>;
	struct _impl_js_jts_dArrowFunction;
	using _js_jts_dArrowFunction = js_ref<_impl_js_jts_dArrowFunction>;
	struct _impl_js_jts_dRegularExpressionLiteral;
	using _js_jts_dRegularExpressionLiteral = js_ref<_impl_js_jts_dRegularExpressionLiteral>;
	struct _impl_js_jts_dNoSubstitutionTemplateLiteral;
	using _js_jts_dNoSubstitutionTemplateLiteral = js_ref<_impl_js_jts_dNoSubstitutionTemplateLiteral>;
	struct _impl_js_jts_dNumericLiteral;
	using _js_jts_dNumericLiteral = js_ref<_impl_js_jts_dNumericLiteral>;
	struct _impl_js_jts_dBigIntLiteral;
	using _js_jts_dBigIntLiteral = js_ref<_impl_js_jts_dBigIntLiteral>;
	struct _impl_js_jts_dTemplateHead;
	using _js_jts_dTemplateHead = js_ref<_impl_js_jts_dTemplateHead>;
	struct _impl_js_jts_dTemplateMiddle;
	using _js_jts_dTemplateMiddle = js_ref<_impl_js_jts_dTemplateMiddle>;
	struct _impl_js_jts_dTemplateTail;
	using _js_jts_dTemplateTail = js_ref<_impl_js_jts_dTemplateTail>;
	struct _impl_js_jts_dTemplateExpression;
	using _js_jts_dTemplateExpression = js_ref<_impl_js_jts_dTemplateExpression>;
	struct _impl_js_jts_dTemplateSpan;
	using _js_jts_dTemplateSpan = js_ref<_impl_js_jts_dTemplateSpan>;
	struct _impl_js_jts_dParenthesizedExpression;
	using _js_jts_dParenthesizedExpression = js_ref<_impl_js_jts_dParenthesizedExpression>;
	struct _impl_js_jts_dArrayLiteralExpression;
	using _js_jts_dArrayLiteralExpression = js_ref<_impl_js_jts_dArrayLiteralExpression>;
	struct _impl_js_jts_dSpreadElement;
	using _js_jts_dSpreadElement = js_ref<_impl_js_jts_dSpreadElement>;
	struct _impl_js_jts_dObjectLiteralExpressionBase;
	using _js_jts_dObjectLiteralExpressionBase = js_ref<_impl_js_jts_dObjectLiteralExpressionBase>;
	struct _impl_js_jts_dObjectLiteralExpression;
	using _js_jts_dObjectLiteralExpression = js_ref<_impl_js_jts_dObjectLiteralExpression>;
	struct _impl_js_jts_dPropertyAccessExpression;
	using _js_jts_dPropertyAccessExpression = js_ref<_impl_js_jts_dPropertyAccessExpression>;
	struct _impl_js_jts_dSuperPropertyAccessExpression;
	using _js_jts_dSuperPropertyAccessExpression = js_ref<_impl_js_jts_dSuperPropertyAccessExpression>;
	struct _impl_js_jts_dPropertyAccessEntityNameExpression;
	using _js_jts_dPropertyAccessEntityNameExpression = js_ref<_impl_js_jts_dPropertyAccessEntityNameExpression>;
	struct _impl_js_jts_dElementAccessExpression;
	using _js_jts_dElementAccessExpression = js_ref<_impl_js_jts_dElementAccessExpression>;
	struct _impl_js_jts_dSuperElementAccessExpression;
	using _js_jts_dSuperElementAccessExpression = js_ref<_impl_js_jts_dSuperElementAccessExpression>;
	struct _impl_js_jts_dCallExpression;
	using _js_jts_dCallExpression = js_ref<_impl_js_jts_dCallExpression>;
	struct _impl_js_jts_dSuperCall;
	using _js_jts_dSuperCall = js_ref<_impl_js_jts_dSuperCall>;
	struct _impl_js_jts_dImportCall;
	using _js_jts_dImportCall = js_ref<_impl_js_jts_dImportCall>;
	struct _impl_js_jts_dExpressionWithTypeArguments;
	using _js_jts_dExpressionWithTypeArguments = js_ref<_impl_js_jts_dExpressionWithTypeArguments>;
	struct _impl_js_jts_dNewExpression;
	using _js_jts_dNewExpression = js_ref<_impl_js_jts_dNewExpression>;
	struct _impl_js_jts_dTaggedTemplateExpression;
	using _js_jts_dTaggedTemplateExpression = js_ref<_impl_js_jts_dTaggedTemplateExpression>;
	struct _impl_js_jts_dAsExpression;
	using _js_jts_dAsExpression = js_ref<_impl_js_jts_dAsExpression>;
	struct _impl_js_jts_dTypeAssertion;
	using _js_jts_dTypeAssertion = js_ref<_impl_js_jts_dTypeAssertion>;
	struct _impl_js_jts_dNonNullExpression;
	using _js_jts_dNonNullExpression = js_ref<_impl_js_jts_dNonNullExpression>;
	struct _impl_js_jts_dMetaProperty;
	using _js_jts_dMetaProperty = js_ref<_impl_js_jts_dMetaProperty>;
	struct _impl_js_jts_dJsxElement;
	using _js_jts_dJsxElement = js_ref<_impl_js_jts_dJsxElement>;
	struct _impl_js_jts_dJsxTagNamePropertyAccess;
	using _js_jts_dJsxTagNamePropertyAccess = js_ref<_impl_js_jts_dJsxTagNamePropertyAccess>;
	struct _impl_js_jts_dJsxAttributes;
	using _js_jts_dJsxAttributes = js_ref<_impl_js_jts_dJsxAttributes>;
	struct _impl_js_jts_dJsxOpeningElement;
	using _js_jts_dJsxOpeningElement = js_ref<_impl_js_jts_dJsxOpeningElement>;
	struct _impl_js_jts_dJsxSelfClosingElement;
	using _js_jts_dJsxSelfClosingElement = js_ref<_impl_js_jts_dJsxSelfClosingElement>;
	struct _impl_js_jts_dJsxFragment;
	using _js_jts_dJsxFragment = js_ref<_impl_js_jts_dJsxFragment>;
	struct _impl_js_jts_dJsxOpeningFragment;
	using _js_jts_dJsxOpeningFragment = js_ref<_impl_js_jts_dJsxOpeningFragment>;
	struct _impl_js_jts_dJsxClosingFragment;
	using _js_jts_dJsxClosingFragment = js_ref<_impl_js_jts_dJsxClosingFragment>;
	struct _impl_js_jts_dJsxAttribute;
	using _js_jts_dJsxAttribute = js_ref<_impl_js_jts_dJsxAttribute>;
	struct _impl_js_jts_dJsxSpreadAttribute;
	using _js_jts_dJsxSpreadAttribute = js_ref<_impl_js_jts_dJsxSpreadAttribute>;
	struct _impl_js_jts_dJsxClosingElement;
	using _js_jts_dJsxClosingElement = js_ref<_impl_js_jts_dJsxClosingElement>;
	struct _impl_js_jts_dJsxExpression;
	using _js_jts_dJsxExpression = js_ref<_impl_js_jts_dJsxExpression>;
	struct _impl_js_jts_dJsxText;
	using _js_jts_dJsxText = js_ref<_impl_js_jts_dJsxText>;
	struct _impl_js_jts_dNotEmittedStatement;
	using _js_jts_dNotEmittedStatement = js_ref<_impl_js_jts_dNotEmittedStatement>;
	struct _impl_js_jts_dCommaListExpression;
	using _js_jts_dCommaListExpression = js_ref<_impl_js_jts_dCommaListExpression>;
	struct _impl_js_jts_dEmptyStatement;
	using _js_jts_dEmptyStatement = js_ref<_impl_js_jts_dEmptyStatement>;
	struct _impl_js_jts_dDebuggerStatement;
	using _js_jts_dDebuggerStatement = js_ref<_impl_js_jts_dDebuggerStatement>;
	struct _impl_js_jts_dMissingDeclaration;
	using _js_jts_dMissingDeclaration = js_ref<_impl_js_jts_dMissingDeclaration>;
	struct _impl_js_jts_dBlock;
	using _js_jts_dBlock = js_ref<_impl_js_jts_dBlock>;
	struct _impl_js_jts_dVariableStatement;
	using _js_jts_dVariableStatement = js_ref<_impl_js_jts_dVariableStatement>;
	struct _impl_js_jts_dExpressionStatement;
	using _js_jts_dExpressionStatement = js_ref<_impl_js_jts_dExpressionStatement>;
	struct _impl_js_jts_dIfStatement;
	using _js_jts_dIfStatement = js_ref<_impl_js_jts_dIfStatement>;
	struct _impl_js_jts_dIterationStatement;
	using _js_jts_dIterationStatement = js_ref<_impl_js_jts_dIterationStatement>;
	struct _impl_js_jts_dDoStatement;
	using _js_jts_dDoStatement = js_ref<_impl_js_jts_dDoStatement>;
	struct _impl_js_jts_dWhileStatement;
	using _js_jts_dWhileStatement = js_ref<_impl_js_jts_dWhileStatement>;
	struct _impl_js_jts_dForStatement;
	using _js_jts_dForStatement = js_ref<_impl_js_jts_dForStatement>;
	struct _impl_js_jts_dForInStatement;
	using _js_jts_dForInStatement = js_ref<_impl_js_jts_dForInStatement>;
	struct _impl_js_jts_dForOfStatement;
	using _js_jts_dForOfStatement = js_ref<_impl_js_jts_dForOfStatement>;
	struct _impl_js_jts_dBreakStatement;
	using _js_jts_dBreakStatement = js_ref<_impl_js_jts_dBreakStatement>;
	struct _impl_js_jts_dContinueStatement;
	using _js_jts_dContinueStatement = js_ref<_impl_js_jts_dContinueStatement>;
	struct _impl_js_jts_dReturnStatement;
	using _js_jts_dReturnStatement = js_ref<_impl_js_jts_dReturnStatement>;
	struct _impl_js_jts_dWithStatement;
	using _js_jts_dWithStatement = js_ref<_impl_js_jts_dWithStatement>;
	struct _impl_js_jts_dSwitchStatement;
	using _js_jts_dSwitchStatement = js_ref<_impl_js_jts_dSwitchStatement>;
	struct _impl_js_jts_dCaseBlock;
	using _js_jts_dCaseBlock = js_ref<_impl_js_jts_dCaseBlock>;
	struct _impl_js_jts_dCaseClause;
	using _js_jts_dCaseClause = js_ref<_impl_js_jts_dCaseClause>;
	struct _impl_js_jts_dDefaultClause;
	using _js_jts_dDefaultClause = js_ref<_impl_js_jts_dDefaultClause>;
	struct _impl_js_jts_dLabeledStatement;
	using _js_jts_dLabeledStatement = js_ref<_impl_js_jts_dLabeledStatement>;
	struct _impl_js_jts_dThrowStatement;
	using _js_jts_dThrowStatement = js_ref<_impl_js_jts_dThrowStatement>;
	struct _impl_js_jts_dTryStatement;
	using _js_jts_dTryStatement = js_ref<_impl_js_jts_dTryStatement>;
	struct _impl_js_jts_dCatchClause;
	using _js_jts_dCatchClause = js_ref<_impl_js_jts_dCatchClause>;
	struct _impl_js_jts_dClassLikeDeclarationBase;
	using _js_jts_dClassLikeDeclarationBase = js_ref<_impl_js_jts_dClassLikeDeclarationBase>;
	struct _impl_js_jts_dClassDeclaration;
	using _js_jts_dClassDeclaration = js_ref<_impl_js_jts_dClassDeclaration>;
	struct _impl_js_jts_dClassExpression;
	using _js_jts_dClassExpression = js_ref<_impl_js_jts_dClassExpression>;
	struct _impl_js_jts_dInterfaceDeclaration;
	using _js_jts_dInterfaceDeclaration = js_ref<_impl_js_jts_dInterfaceDeclaration>;
	struct _impl_js_jts_dHeritageClause;
	using _js_jts_dHeritageClause = js_ref<_impl_js_jts_dHeritageClause>;
	struct _impl_js_jts_dTypeAliasDeclaration;
	using _js_jts_dTypeAliasDeclaration = js_ref<_impl_js_jts_dTypeAliasDeclaration>;
	struct _impl_js_jts_dEnumMember;
	using _js_jts_dEnumMember = js_ref<_impl_js_jts_dEnumMember>;
	struct _impl_js_jts_dEnumDeclaration;
	using _js_jts_dEnumDeclaration = js_ref<_impl_js_jts_dEnumDeclaration>;
	struct _impl_js_jts_dModuleDeclaration;
	using _js_jts_dModuleDeclaration = js_ref<_impl_js_jts_dModuleDeclaration>;
	struct _impl_js_jts_dNamespaceDeclaration;
	using _js_jts_dNamespaceDeclaration = js_ref<_impl_js_jts_dNamespaceDeclaration>;
	struct _impl_js_jts_dJSDocNamespaceDeclaration;
	using _js_jts_dJSDocNamespaceDeclaration = js_ref<_impl_js_jts_dJSDocNamespaceDeclaration>;
	struct _impl_js_jts_dModuleBlock;
	using _js_jts_dModuleBlock = js_ref<_impl_js_jts_dModuleBlock>;
	struct _impl_js_jts_dImportEqualsDeclaration;
	using _js_jts_dImportEqualsDeclaration = js_ref<_impl_js_jts_dImportEqualsDeclaration>;
	struct _impl_js_jts_dExternalModuleReference;
	using _js_jts_dExternalModuleReference = js_ref<_impl_js_jts_dExternalModuleReference>;
	struct _impl_js_jts_dImportDeclaration;
	using _js_jts_dImportDeclaration = js_ref<_impl_js_jts_dImportDeclaration>;
	struct _impl_js_jts_dImportClause;
	using _js_jts_dImportClause = js_ref<_impl_js_jts_dImportClause>;
	struct _impl_js_jts_dNamespaceImport;
	using _js_jts_dNamespaceImport = js_ref<_impl_js_jts_dNamespaceImport>;
	struct _impl_js_jts_dNamespaceExportDeclaration;
	using _js_jts_dNamespaceExportDeclaration = js_ref<_impl_js_jts_dNamespaceExportDeclaration>;
	struct _impl_js_jts_dExportDeclaration;
	using _js_jts_dExportDeclaration = js_ref<_impl_js_jts_dExportDeclaration>;
	struct _impl_js_jts_dNamedImports;
	using _js_jts_dNamedImports = js_ref<_impl_js_jts_dNamedImports>;
	struct _impl_js_jts_dNamedExports;
	using _js_jts_dNamedExports = js_ref<_impl_js_jts_dNamedExports>;
	struct _impl_js_jts_dImportSpecifier;
	using _js_jts_dImportSpecifier = js_ref<_impl_js_jts_dImportSpecifier>;
	struct _impl_js_jts_dExportSpecifier;
	using _js_jts_dExportSpecifier = js_ref<_impl_js_jts_dExportSpecifier>;
	struct _impl_js_jts_dExportAssignment;
	using _js_jts_dExportAssignment = js_ref<_impl_js_jts_dExportAssignment>;
	struct _impl_js_jts_dFileReference;
	using _js_jts_dFileReference = js_ref<_impl_js_jts_dFileReference>;
	struct _impl_js_jts_dCheckJsDirective;
	using _js_jts_dCheckJsDirective = js_ref<_impl_js_jts_dCheckJsDirective>;
	struct _impl_js_jts_dCommentRange;
	using _js_jts_dCommentRange = js_ref<_impl_js_jts_dCommentRange>;
	struct _impl_js_jts_dSynthesizedComment;
	using _js_jts_dSynthesizedComment = js_ref<_impl_js_jts_dSynthesizedComment>;
	struct _impl_js_jts_dJSDocTypeExpression;
	using _js_jts_dJSDocTypeExpression = js_ref<_impl_js_jts_dJSDocTypeExpression>;
	struct _impl_js_jts_dJSDocType;
	using _js_jts_dJSDocType = js_ref<_impl_js_jts_dJSDocType>;
	struct _impl_js_jts_dJSDocAllType;
	using _js_jts_dJSDocAllType = js_ref<_impl_js_jts_dJSDocAllType>;
	struct _impl_js_jts_dJSDocUnknownType;
	using _js_jts_dJSDocUnknownType = js_ref<_impl_js_jts_dJSDocUnknownType>;
	struct _impl_js_jts_dJSDocNonNullableType;
	using _js_jts_dJSDocNonNullableType = js_ref<_impl_js_jts_dJSDocNonNullableType>;
	struct _impl_js_jts_dJSDocNullableType;
	using _js_jts_dJSDocNullableType = js_ref<_impl_js_jts_dJSDocNullableType>;
	struct _impl_js_jts_dJSDocOptionalType;
	using _js_jts_dJSDocOptionalType = js_ref<_impl_js_jts_dJSDocOptionalType>;
	struct _impl_js_jts_dJSDocFunctionType;
	using _js_jts_dJSDocFunctionType = js_ref<_impl_js_jts_dJSDocFunctionType>;
	struct _impl_js_jts_dJSDocVariadicType;
	using _js_jts_dJSDocVariadicType = js_ref<_impl_js_jts_dJSDocVariadicType>;
	struct _impl_js_jts_dJSDoc;
	using _js_jts_dJSDoc = js_ref<_impl_js_jts_dJSDoc>;
	struct _impl_js_jts_dJSDocTag;
	using _js_jts_dJSDocTag = js_ref<_impl_js_jts_dJSDocTag>;
	struct _impl_js_jts_dJSDocUnknownTag;
	using _js_jts_dJSDocUnknownTag = js_ref<_impl_js_jts_dJSDocUnknownTag>;
	struct _impl_js_jts_dJSDocAugmentsTag;
	using _js_jts_dJSDocAugmentsTag = js_ref<_impl_js_jts_dJSDocAugmentsTag>;
	struct _impl_js_jts_dJSDocClassTag;
	using _js_jts_dJSDocClassTag = js_ref<_impl_js_jts_dJSDocClassTag>;
	struct _impl_js_jts_dJSDocEnumTag;
	using _js_jts_dJSDocEnumTag = js_ref<_impl_js_jts_dJSDocEnumTag>;
	struct _impl_js_jts_dJSDocThisTag;
	using _js_jts_dJSDocThisTag = js_ref<_impl_js_jts_dJSDocThisTag>;
	struct _impl_js_jts_dJSDocTemplateTag;
	using _js_jts_dJSDocTemplateTag = js_ref<_impl_js_jts_dJSDocTemplateTag>;
	struct _impl_js_jts_dJSDocReturnTag;
	using _js_jts_dJSDocReturnTag = js_ref<_impl_js_jts_dJSDocReturnTag>;
	struct _impl_js_jts_dJSDocTypeTag;
	using _js_jts_dJSDocTypeTag = js_ref<_impl_js_jts_dJSDocTypeTag>;
	struct _impl_js_jts_dJSDocTypedefTag;
	using _js_jts_dJSDocTypedefTag = js_ref<_impl_js_jts_dJSDocTypedefTag>;
	struct _impl_js_jts_dJSDocCallbackTag;
	using _js_jts_dJSDocCallbackTag = js_ref<_impl_js_jts_dJSDocCallbackTag>;
	struct _impl_js_jts_dJSDocSignature;
	using _js_jts_dJSDocSignature = js_ref<_impl_js_jts_dJSDocSignature>;
	struct _impl_js_jts_dJSDocPropertyLikeTag;
	using _js_jts_dJSDocPropertyLikeTag = js_ref<_impl_js_jts_dJSDocPropertyLikeTag>;
	struct _impl_js_jts_dJSDocPropertyTag;
	using _js_jts_dJSDocPropertyTag = js_ref<_impl_js_jts_dJSDocPropertyTag>;
	struct _impl_js_jts_dJSDocParameterTag;
	using _js_jts_dJSDocParameterTag = js_ref<_impl_js_jts_dJSDocParameterTag>;
	struct _impl_js_jts_dJSDocTypeLiteral;
	using _js_jts_dJSDocTypeLiteral = js_ref<_impl_js_jts_dJSDocTypeLiteral>;
	struct _impl_js_jts_dFlowLock;
	using _js_jts_dFlowLock = js_ref<_impl_js_jts_dFlowLock>;
	struct _impl_js_jts_dFlowNodeBase;
	using _js_jts_dFlowNodeBase = js_ref<_impl_js_jts_dFlowNodeBase>;
	struct _impl_js_jts_dAfterFinallyFlow;
	using _js_jts_dAfterFinallyFlow = js_ref<_impl_js_jts_dAfterFinallyFlow>;
	struct _impl_js_jts_dPreFinallyFlow;
	using _js_jts_dPreFinallyFlow = js_ref<_impl_js_jts_dPreFinallyFlow>;
	struct _impl_js_jts_dFlowStart;
	using _js_jts_dFlowStart = js_ref<_impl_js_jts_dFlowStart>;
	struct _impl_js_jts_dFlowLabel;
	using _js_jts_dFlowLabel = js_ref<_impl_js_jts_dFlowLabel>;
	struct _impl_js_jts_dFlowAssignment;
	using _js_jts_dFlowAssignment = js_ref<_impl_js_jts_dFlowAssignment>;
	struct _impl_js_jts_dFlowCondition;
	using _js_jts_dFlowCondition = js_ref<_impl_js_jts_dFlowCondition>;
	struct _impl_js_jts_dFlowSwitchClause;
	using _js_jts_dFlowSwitchClause = js_ref<_impl_js_jts_dFlowSwitchClause>;
	struct _impl_js_jts_dFlowArrayMutation;
	using _js_jts_dFlowArrayMutation = js_ref<_impl_js_jts_dFlowArrayMutation>;
	struct _impl_js_jts_dIncompleteType;
	using _js_jts_dIncompleteType = js_ref<_impl_js_jts_dIncompleteType>;
	struct _impl_js_jts_dAmdDependency;
	using _js_jts_dAmdDependency = js_ref<_impl_js_jts_dAmdDependency>;
	struct _impl_js_jts_dSourceFile;
	using _js_jts_dSourceFile = js_ref<_impl_js_jts_dSourceFile>;
	struct _impl_js_jts_dBundle;
	using _js_jts_dBundle = js_ref<_impl_js_jts_dBundle>;
	struct _impl_js_jts_dInputFiles;
	using _js_jts_dInputFiles = js_ref<_impl_js_jts_dInputFiles>;
	struct _impl_js_jts_dUnparsedSource;
	using _js_jts_dUnparsedSource = js_ref<_impl_js_jts_dUnparsedSource>;
	struct _impl_js_jts_dUnparsedSection;
	using _js_jts_dUnparsedSection = js_ref<_impl_js_jts_dUnparsedSection>;
	struct _impl_js_jts_dUnparsedPrologue;
	using _js_jts_dUnparsedPrologue = js_ref<_impl_js_jts_dUnparsedPrologue>;
	struct _impl_js_jts_dUnparsedPrepend;
	using _js_jts_dUnparsedPrepend = js_ref<_impl_js_jts_dUnparsedPrepend>;
	struct _impl_js_jts_dUnparsedTextLike;
	using _js_jts_dUnparsedTextLike = js_ref<_impl_js_jts_dUnparsedTextLike>;
	struct _impl_js_jts_dUnparsedSyntheticReference;
	using _js_jts_dUnparsedSyntheticReference = js_ref<_impl_js_jts_dUnparsedSyntheticReference>;
	struct _impl_js_jts_dJsonSourceFile;
	using _js_jts_dJsonSourceFile = js_ref<_impl_js_jts_dJsonSourceFile>;
	struct _impl_js_jts_dTsConfigSourceFile;
	using _js_jts_dTsConfigSourceFile = js_ref<_impl_js_jts_dTsConfigSourceFile>;
	struct _impl_js_jts_dJsonMinusNumericLiteral;
	using _js_jts_dJsonMinusNumericLiteral = js_ref<_impl_js_jts_dJsonMinusNumericLiteral>;
	struct _impl_js_jts_dJsonObjectExpressionStatement;
	using _js_jts_dJsonObjectExpressionStatement = js_ref<_impl_js_jts_dJsonObjectExpressionStatement>;
	struct _impl_js_jts_dScriptReferenceHost;
	using _js_jts_dScriptReferenceHost = js_ref<_impl_js_jts_dScriptReferenceHost>;
	struct _impl_js_jts_dParseConfigHost;
	using _js_jts_dParseConfigHost = js_ref<_impl_js_jts_dParseConfigHost>;
	struct _impl_js_jts_dOperationCanceledException;
	using _js_jts_dOperationCanceledException = js_ref<_impl_js_jts_dOperationCanceledException>;
	struct _impl_js_jts_dCancellationToken;
	using _js_jts_dCancellationToken = js_ref<_impl_js_jts_dCancellationToken>;
	struct _impl_js_jts_dProgram;
	using _js_jts_dProgram = js_ref<_impl_js_jts_dProgram>;
	struct _impl_js_jts_dResolvedProjectReference;
	using _js_jts_dResolvedProjectReference = js_ref<_impl_js_jts_dResolvedProjectReference>;
	struct _impl_js_jts_dCustomTransformer;
	using _js_jts_dCustomTransformer = js_ref<_impl_js_jts_dCustomTransformer>;
	struct _impl_js_jts_dCustomTransformers;
	using _js_jts_dCustomTransformers = js_ref<_impl_js_jts_dCustomTransformers>;
	struct _impl_js_jts_dSourceMapSpan;
	using _js_jts_dSourceMapSpan = js_ref<_impl_js_jts_dSourceMapSpan>;
	struct _impl_js_jts_dEmitResult;
	using _js_jts_dEmitResult = js_ref<_impl_js_jts_dEmitResult>;
	struct _impl_js_jts_dTypeChecker;
	using _js_jts_dTypeChecker = js_ref<_impl_js_jts_dTypeChecker>;
	struct _impl_js_jts_dTypePredicateBase;
	using _js_jts_dTypePredicateBase = js_ref<_impl_js_jts_dTypePredicateBase>;
	struct _impl_js_jts_dThisTypePredicate;
	using _js_jts_dThisTypePredicate = js_ref<_impl_js_jts_dThisTypePredicate>;
	struct _impl_js_jts_dIdentifierTypePredicate;
	using _js_jts_dIdentifierTypePredicate = js_ref<_impl_js_jts_dIdentifierTypePredicate>;
	struct _impl_js_jts_dSymbol;
	using _js_jts_dSymbol = js_ref<_impl_js_jts_dSymbol>;
	struct _impl_js_jts_dReadonlyUnderscoreEscapedMap;
	using _js_jts_dReadonlyUnderscoreEscapedMap = js_ref<_impl_js_jts_dReadonlyUnderscoreEscapedMap>;
	struct _impl_js_jts_dUnderscoreEscapedMap;
	using _js_jts_dUnderscoreEscapedMap = js_ref<_impl_js_jts_dUnderscoreEscapedMap>;
	struct _impl_js_jts_dType;
	using _js_jts_dType = js_ref<_impl_js_jts_dType>;
	struct _impl_js_jts_dLiteralType;
	using _js_jts_dLiteralType = js_ref<_impl_js_jts_dLiteralType>;
	struct _impl_js_jts_dUniqueESSymbolType;
	using _js_jts_dUniqueESSymbolType = js_ref<_impl_js_jts_dUniqueESSymbolType>;
	struct _impl_js_jts_dStringLiteralType;
	using _js_jts_dStringLiteralType = js_ref<_impl_js_jts_dStringLiteralType>;
	struct _impl_js_jts_dNumberLiteralType;
	using _js_jts_dNumberLiteralType = js_ref<_impl_js_jts_dNumberLiteralType>;
	struct _impl_js_jts_dBigIntLiteralType;
	using _js_jts_dBigIntLiteralType = js_ref<_impl_js_jts_dBigIntLiteralType>;
	struct _impl_js_jts_dEnumType;
	using _js_jts_dEnumType = js_ref<_impl_js_jts_dEnumType>;
	struct _impl_js_jts_dObjectType;
	using _js_jts_dObjectType = js_ref<_impl_js_jts_dObjectType>;
	struct _impl_js_jts_dInterfaceType;
	using _js_jts_dInterfaceType = js_ref<_impl_js_jts_dInterfaceType>;
	struct _impl_js_jts_dInterfaceTypeWithDeclaredMembers;
	using _js_jts_dInterfaceTypeWithDeclaredMembers = js_ref<_impl_js_jts_dInterfaceTypeWithDeclaredMembers>;
	struct _impl_js_jts_dTypeReference;
	using _js_jts_dTypeReference = js_ref<_impl_js_jts_dTypeReference>;
	struct _impl_js_jts_dGenericType;
	using _js_jts_dGenericType = js_ref<_impl_js_jts_dGenericType>;
	struct _impl_js_jts_dTupleType;
	using _js_jts_dTupleType = js_ref<_impl_js_jts_dTupleType>;
	struct _impl_js_jts_dTupleTypeReference;
	using _js_jts_dTupleTypeReference = js_ref<_impl_js_jts_dTupleTypeReference>;
	struct _impl_js_jts_dUnionOrIntersectionType;
	using _js_jts_dUnionOrIntersectionType = js_ref<_impl_js_jts_dUnionOrIntersectionType>;
	struct _impl_js_jts_dUnionType;
	using _js_jts_dUnionType = js_ref<_impl_js_jts_dUnionType>;
	struct _impl_js_jts_dIntersectionType;
	using _js_jts_dIntersectionType = js_ref<_impl_js_jts_dIntersectionType>;
	struct _impl_js_jts_dEvolvingArrayType;
	using _js_jts_dEvolvingArrayType = js_ref<_impl_js_jts_dEvolvingArrayType>;
	struct _impl_js_jts_dInstantiableType;
	using _js_jts_dInstantiableType = js_ref<_impl_js_jts_dInstantiableType>;
	struct _impl_js_jts_dTypeParameter;
	using _js_jts_dTypeParameter = js_ref<_impl_js_jts_dTypeParameter>;
	struct _impl_js_jts_dIndexedAccessType;
	using _js_jts_dIndexedAccessType = js_ref<_impl_js_jts_dIndexedAccessType>;
	struct _impl_js_jts_dIndexType;
	using _js_jts_dIndexType = js_ref<_impl_js_jts_dIndexType>;
	struct _impl_js_jts_dConditionalRoot;
	using _js_jts_dConditionalRoot = js_ref<_impl_js_jts_dConditionalRoot>;
	struct _impl_js_jts_dConditionalType;
	using _js_jts_dConditionalType = js_ref<_impl_js_jts_dConditionalType>;
	struct _impl_js_jts_dSubstitutionType;
	using _js_jts_dSubstitutionType = js_ref<_impl_js_jts_dSubstitutionType>;
	struct _impl_js_jts_dSignature;
	using _js_jts_dSignature = js_ref<_impl_js_jts_dSignature>;
	struct _impl_js_jts_dIndexInfo;
	using _js_jts_dIndexInfo = js_ref<_impl_js_jts_dIndexInfo>;
	struct _impl_js_jts_dFileExtensionInfo;
	using _js_jts_dFileExtensionInfo = js_ref<_impl_js_jts_dFileExtensionInfo>;
	struct _impl_js_jts_dDiagnosticMessage;
	using _js_jts_dDiagnosticMessage = js_ref<_impl_js_jts_dDiagnosticMessage>;
	struct _impl_js_jts_dDiagnosticMessageChain;
	using _js_jts_dDiagnosticMessageChain = js_ref<_impl_js_jts_dDiagnosticMessageChain>;
	struct _impl_js_jts_dDiagnosticRelatedInformation;
	using _js_jts_dDiagnosticRelatedInformation = js_ref<_impl_js_jts_dDiagnosticRelatedInformation>;
	struct _impl_js_jts_dDiagnostic;
	using _js_jts_dDiagnostic = js_ref<_impl_js_jts_dDiagnostic>;
	struct _impl_js_jts_dDiagnosticWithLocation;
	using _js_jts_dDiagnosticWithLocation = js_ref<_impl_js_jts_dDiagnosticWithLocation>;
	struct _impl_js_jts_dPluginImport;
	using _js_jts_dPluginImport = js_ref<_impl_js_jts_dPluginImport>;
	struct _impl_js_jts_dProjectReference;
	using _js_jts_dProjectReference = js_ref<_impl_js_jts_dProjectReference>;
	struct _impl_js_jts_dCompilerOptions;
	using _js_jts_dCompilerOptions = js_ref<_impl_js_jts_dCompilerOptions>;
	struct _impl_js_jts_dTypeAcquisition;
	using _js_jts_dTypeAcquisition = js_ref<_impl_js_jts_dTypeAcquisition>;
	struct _impl_js_jts_dLineAndCharacter;
	using _js_jts_dLineAndCharacter = js_ref<_impl_js_jts_dLineAndCharacter>;
	struct _impl_js_jts_dParsedCommandLine;
	using _js_jts_dParsedCommandLine = js_ref<_impl_js_jts_dParsedCommandLine>;
	struct _impl_js_jts_dExpandResult;
	using _js_jts_dExpandResult = js_ref<_impl_js_jts_dExpandResult>;
	struct _impl_js_jts_dCreateProgramOptions;
	using _js_jts_dCreateProgramOptions = js_ref<_impl_js_jts_dCreateProgramOptions>;
	struct _impl_js_jts_dModuleResolutionHost;
	using _js_jts_dModuleResolutionHost = js_ref<_impl_js_jts_dModuleResolutionHost>;
	struct _impl_js_jts_dResolvedModule;
	using _js_jts_dResolvedModule = js_ref<_impl_js_jts_dResolvedModule>;
	struct _impl_js_jts_dResolvedModuleFull;
	using _js_jts_dResolvedModuleFull = js_ref<_impl_js_jts_dResolvedModuleFull>;
	struct _impl_js_jts_dPackageId;
	using _js_jts_dPackageId = js_ref<_impl_js_jts_dPackageId>;
	struct _impl_js_jts_dResolvedModuleWithFailedLookupLocations;
	using _js_jts_dResolvedModuleWithFailedLookupLocations = js_ref<_impl_js_jts_dResolvedModuleWithFailedLookupLocations>;
	struct _impl_js_jts_dResolvedTypeReferenceDirective;
	using _js_jts_dResolvedTypeReferenceDirective = js_ref<_impl_js_jts_dResolvedTypeReferenceDirective>;
	struct _impl_js_jts_dResolvedTypeReferenceDirectiveWithFailedLookupLocations;
	using _js_jts_dResolvedTypeReferenceDirectiveWithFailedLookupLocations = js_ref<_impl_js_jts_dResolvedTypeReferenceDirectiveWithFailedLookupLocations>;
	struct _impl_js_jts_dCompilerHost;
	using _js_jts_dCompilerHost = js_ref<_impl_js_jts_dCompilerHost>;
	struct _impl_js_jts_dSourceMapRange;
	using _js_jts_dSourceMapRange = js_ref<_impl_js_jts_dSourceMapRange>;
	struct _impl_js_jts_dSourceMapSource;
	using _js_jts_dSourceMapSource = js_ref<_impl_js_jts_dSourceMapSource>;
	struct _impl_js_jts_dEmitHelper;
	using _js_jts_dEmitHelper = js_ref<_impl_js_jts_dEmitHelper>;
	struct _impl_js_jts_dUnscopedEmitHelper;
	using _js_jts_dUnscopedEmitHelper = js_ref<_impl_js_jts_dUnscopedEmitHelper>;
	struct _impl_js_jts_dTransformationContext;
	using _js_jts_dTransformationContext = js_ref<_impl_js_jts_dTransformationContext>;
	struct _impl_js_jts_dTransformationResult;
	using _js_jts_dTransformationResult = js_ref<_impl_js_jts_dTransformationResult>;
	struct _impl_js_jts_dPrinter;
	using _js_jts_dPrinter = js_ref<_impl_js_jts_dPrinter>;
	struct _impl_js_jts_dPrintHandlers;
	using _js_jts_dPrintHandlers = js_ref<_impl_js_jts_dPrintHandlers>;
	struct _impl_js_jts_dPrinterOptions;
	using _js_jts_dPrinterOptions = js_ref<_impl_js_jts_dPrinterOptions>;
	struct _impl_js_jts_dGetEffectiveTypeRootsHost;
	using _js_jts_dGetEffectiveTypeRootsHost = js_ref<_impl_js_jts_dGetEffectiveTypeRootsHost>;
	struct _impl_js_jts_dTextSpan;
	using _js_jts_dTextSpan = js_ref<_impl_js_jts_dTextSpan>;
	struct _impl_js_jts_dTextChangeRange;
	using _js_jts_dTextChangeRange = js_ref<_impl_js_jts_dTextChangeRange>;
	struct _impl_js_jts_dSyntaxList;
	using _js_jts_dSyntaxList = js_ref<_impl_js_jts_dSyntaxList>;
	struct _impl_js_jts_dUserPreferences;
	using _js_jts_dUserPreferences = js_ref<_impl_js_jts_dUserPreferences>;
	struct _impl_js_jts_dPseudoBigInt;
	using _js_jts_dPseudoBigInt = js_ref<_impl_js_jts_dPseudoBigInt>;
	struct _impl_js_jts_dSystem;
	using _js_jts_dSystem = js_ref<_impl_js_jts_dSystem>;
	struct _impl_js_jts_dFileWatcher;
	using _js_jts_dFileWatcher = js_ref<_impl_js_jts_dFileWatcher>;
	struct _impl_js_jts_dScanner;
	using _js_jts_dScanner = js_ref<_impl_js_jts_dScanner>;
	struct _impl_js_jts_dConfigFileDiagnosticsReporter;
	using _js_jts_dConfigFileDiagnosticsReporter = js_ref<_impl_js_jts_dConfigFileDiagnosticsReporter>;
	struct _impl_js_jts_dParseConfigFileHost;
	using _js_jts_dParseConfigFileHost = js_ref<_impl_js_jts_dParseConfigFileHost>;
	struct _impl_js_jts_dParsedTsconfig;
	using _js_jts_dParsedTsconfig = js_ref<_impl_js_jts_dParsedTsconfig>;
	struct _impl_js_jts_dExtendedConfigCacheEntry;
	using _js_jts_dExtendedConfigCacheEntry = js_ref<_impl_js_jts_dExtendedConfigCacheEntry>;
	struct _impl_js_jts_dNonRelativeModuleNameResolutionCache;
	using _js_jts_dNonRelativeModuleNameResolutionCache = js_ref<_impl_js_jts_dNonRelativeModuleNameResolutionCache>;
	struct _impl_js_jts_dModuleResolutionCache;
	using _js_jts_dModuleResolutionCache = js_ref<_impl_js_jts_dModuleResolutionCache>;
	struct _impl_js_jts_dPerModuleNameCache;
	using _js_jts_dPerModuleNameCache = js_ref<_impl_js_jts_dPerModuleNameCache>;
	struct _impl_js_jts_dFormatDiagnosticsHost;
	using _js_jts_dFormatDiagnosticsHost = js_ref<_impl_js_jts_dFormatDiagnosticsHost>;
	struct _impl_js_jts_dResolveProjectReferencePathHost;
	using _js_jts_dResolveProjectReferencePathHost = js_ref<_impl_js_jts_dResolveProjectReferencePathHost>;
	struct _impl_js_jts_dEmitOutput;
	using _js_jts_dEmitOutput = js_ref<_impl_js_jts_dEmitOutput>;
	struct _impl_js_jts_dOutputFile;
	using _js_jts_dOutputFile = js_ref<_impl_js_jts_dOutputFile>;
	struct _impl_js_jts_dBuilderProgramHost;
	using _js_jts_dBuilderProgramHost = js_ref<_impl_js_jts_dBuilderProgramHost>;
	struct _impl_js_jts_dBuilderProgram;
	using _js_jts_dBuilderProgram = js_ref<_impl_js_jts_dBuilderProgram>;
	struct _impl_js_jts_dSemanticDiagnosticsBuilderProgram;
	using _js_jts_dSemanticDiagnosticsBuilderProgram = js_ref<_impl_js_jts_dSemanticDiagnosticsBuilderProgram>;
	struct _impl_js_jts_dEmitAndSemanticDiagnosticsBuilderProgram;
	using _js_jts_dEmitAndSemanticDiagnosticsBuilderProgram = js_ref<_impl_js_jts_dEmitAndSemanticDiagnosticsBuilderProgram>;
	struct _impl_js_jts_dWatchHost;
	using _js_jts_dWatchHost = js_ref<_impl_js_jts_dWatchHost>;
	struct _impl_js_jts_dProgramHost;
	using _js_jts_dProgramHost = js_ref<_impl_js_jts_dProgramHost>;
	struct _impl_js_jts_dWatchCompilerHost;
	using _js_jts_dWatchCompilerHost = js_ref<_impl_js_jts_dWatchCompilerHost>;
	struct _impl_js_jts_dWatchCompilerHostOfFilesAndCompilerOptions;
	using _js_jts_dWatchCompilerHostOfFilesAndCompilerOptions = js_ref<_impl_js_jts_dWatchCompilerHostOfFilesAndCompilerOptions>;
	struct _impl_js_jts_dWatchCompilerHostOfConfigFile;
	using _js_jts_dWatchCompilerHostOfConfigFile = js_ref<_impl_js_jts_dWatchCompilerHostOfConfigFile>;
	struct _impl_js_jts_dWatch;
	using _js_jts_dWatch = js_ref<_impl_js_jts_dWatch>;
	struct _impl_js_jts_dWatchOfConfigFile;
	using _js_jts_dWatchOfConfigFile = js_ref<_impl_js_jts_dWatchOfConfigFile>;
	struct _impl_js_jts_dWatchOfFilesAndCompilerOptions;
	using _js_jts_dWatchOfFilesAndCompilerOptions = js_ref<_impl_js_jts_dWatchOfFilesAndCompilerOptions>;
	struct _impl_js_jts_dserver;
	using _js_jts_dserver = js_ref<_impl_js_jts_dserver>;
	struct _impl_js_jts_dserver_dTypingInstallerResponse;
	using _js_jts_dserver_dTypingInstallerResponse = js_ref<_impl_js_jts_dserver_dTypingInstallerResponse>;
	struct _impl_js_jts_dserver_dTypingInstallerRequestWithProjectName;
	using _js_jts_dserver_dTypingInstallerRequestWithProjectName = js_ref<_impl_js_jts_dserver_dTypingInstallerRequestWithProjectName>;
	struct _impl_js_jts_dserver_dDiscoverTypings;
	using _js_jts_dserver_dDiscoverTypings = js_ref<_impl_js_jts_dserver_dDiscoverTypings>;
	struct _impl_js_jts_dserver_dCloseProject;
	using _js_jts_dserver_dCloseProject = js_ref<_impl_js_jts_dserver_dCloseProject>;
	struct _impl_js_jts_dserver_dTypesRegistryRequest;
	using _js_jts_dserver_dTypesRegistryRequest = js_ref<_impl_js_jts_dserver_dTypesRegistryRequest>;
	struct _impl_js_jts_dserver_dInstallPackageRequest;
	using _js_jts_dserver_dInstallPackageRequest = js_ref<_impl_js_jts_dserver_dInstallPackageRequest>;
	struct _impl_js_jts_dserver_dProjectResponse;
	using _js_jts_dserver_dProjectResponse = js_ref<_impl_js_jts_dserver_dProjectResponse>;
	struct _impl_js_jts_dserver_dPackageInstalledResponse;
	using _js_jts_dserver_dPackageInstalledResponse = js_ref<_impl_js_jts_dserver_dPackageInstalledResponse>;
	struct _impl_js_jts_dserver_dInitializationFailedResponse;
	using _js_jts_dserver_dInitializationFailedResponse = js_ref<_impl_js_jts_dserver_dInitializationFailedResponse>;
	struct _impl_js_jts_dserver_dInvalidateCachedTypings;
	using _js_jts_dserver_dInvalidateCachedTypings = js_ref<_impl_js_jts_dserver_dInvalidateCachedTypings>;
	struct _impl_js_jts_dserver_dInstallTypes;
	using _js_jts_dserver_dInstallTypes = js_ref<_impl_js_jts_dserver_dInstallTypes>;
	struct _impl_js_jts_dserver_dBeginInstallTypes;
	using _js_jts_dserver_dBeginInstallTypes = js_ref<_impl_js_jts_dserver_dBeginInstallTypes>;
	struct _impl_js_jts_dserver_dEndInstallTypes;
	using _js_jts_dserver_dEndInstallTypes = js_ref<_impl_js_jts_dserver_dEndInstallTypes>;
	struct _impl_js_jts_dserver_dSetTypings;
	using _js_jts_dserver_dSetTypings = js_ref<_impl_js_jts_dserver_dSetTypings>;
	struct _impl_js_jts_dSourceFileLike;
	using _js_jts_dSourceFileLike = js_ref<_impl_js_jts_dSourceFileLike>;
	struct _impl_js_jts_dIScriptSnapshot;
	using _js_jts_dIScriptSnapshot = js_ref<_impl_js_jts_dIScriptSnapshot>;
	struct _impl_js_jts_dScriptSnapshot;
	using _js_jts_dScriptSnapshot = js_ref<_impl_js_jts_dScriptSnapshot>;
	struct _impl_js_jts_dPreProcessedFileInfo;
	using _js_jts_dPreProcessedFileInfo = js_ref<_impl_js_jts_dPreProcessedFileInfo>;
	struct _impl_js_jts_dHostCancellationToken;
	using _js_jts_dHostCancellationToken = js_ref<_impl_js_jts_dHostCancellationToken>;
	struct _impl_js_jts_dInstallPackageOptions;
	using _js_jts_dInstallPackageOptions = js_ref<_impl_js_jts_dInstallPackageOptions>;
	struct _impl_js_jts_dLanguageServiceHost;
	using _js_jts_dLanguageServiceHost = js_ref<_impl_js_jts_dLanguageServiceHost>;
	struct _impl_js_jts_dLanguageService;
	using _js_jts_dLanguageService = js_ref<_impl_js_jts_dLanguageService>;
	struct _impl_js_jts_dJsxClosingTagInfo;
	using _js_jts_dJsxClosingTagInfo = js_ref<_impl_js_jts_dJsxClosingTagInfo>;
	struct _impl_js_jts_dCombinedCodeFixScope;
	using _js_jts_dCombinedCodeFixScope = js_ref<_impl_js_jts_dCombinedCodeFixScope>;
	struct _impl_js_jts_dGetCompletionsAtPositionOptions;
	using _js_jts_dGetCompletionsAtPositionOptions = js_ref<_impl_js_jts_dGetCompletionsAtPositionOptions>;
	struct _impl_js_jts_dSignatureHelpItemsOptions;
	using _js_jts_dSignatureHelpItemsOptions = js_ref<_impl_js_jts_dSignatureHelpItemsOptions>;
	struct _impl_js_jts_dSignatureHelpInvokedReason;
	using _js_jts_dSignatureHelpInvokedReason = js_ref<_impl_js_jts_dSignatureHelpInvokedReason>;
	struct _impl_js_jts_dSignatureHelpCharacterTypedReason;
	using _js_jts_dSignatureHelpCharacterTypedReason = js_ref<_impl_js_jts_dSignatureHelpCharacterTypedReason>;
	struct _impl_js_jts_dSignatureHelpRetriggeredReason;
	using _js_jts_dSignatureHelpRetriggeredReason = js_ref<_impl_js_jts_dSignatureHelpRetriggeredReason>;
	struct _impl_js_jts_dApplyCodeActionCommandResult;
	using _js_jts_dApplyCodeActionCommandResult = js_ref<_impl_js_jts_dApplyCodeActionCommandResult>;
	struct _impl_js_jts_dClassifications;
	using _js_jts_dClassifications = js_ref<_impl_js_jts_dClassifications>;
	struct _impl_js_jts_dClassifiedSpan;
	using _js_jts_dClassifiedSpan = js_ref<_impl_js_jts_dClassifiedSpan>;
	struct _impl_js_jts_dNavigationBarItem;
	using _js_jts_dNavigationBarItem = js_ref<_impl_js_jts_dNavigationBarItem>;
	struct _impl_js_jts_dNavigationTree;
	using _js_jts_dNavigationTree = js_ref<_impl_js_jts_dNavigationTree>;
	struct _impl_js_jts_dTodoCommentDescriptor;
	using _js_jts_dTodoCommentDescriptor = js_ref<_impl_js_jts_dTodoCommentDescriptor>;
	struct _impl_js_jts_dTodoComment;
	using _js_jts_dTodoComment = js_ref<_impl_js_jts_dTodoComment>;
	struct _impl_js_jts_dTextChange;
	using _js_jts_dTextChange = js_ref<_impl_js_jts_dTextChange>;
	struct _impl_js_jts_dFileTextChanges;
	using _js_jts_dFileTextChanges = js_ref<_impl_js_jts_dFileTextChanges>;
	struct _impl_js_jts_dCodeAction;
	using _js_jts_dCodeAction = js_ref<_impl_js_jts_dCodeAction>;
	struct _impl_js_jts_dCodeFixAction;
	using _js_jts_dCodeFixAction = js_ref<_impl_js_jts_dCodeFixAction>;
	struct _impl_js_jts_dCombinedCodeActions;
	using _js_jts_dCombinedCodeActions = js_ref<_impl_js_jts_dCombinedCodeActions>;
	struct _impl_js_jts_dInstallPackageAction;
	using _js_jts_dInstallPackageAction = js_ref<_impl_js_jts_dInstallPackageAction>;
	struct _impl_js_jts_dApplicableRefactorInfo;
	using _js_jts_dApplicableRefactorInfo = js_ref<_impl_js_jts_dApplicableRefactorInfo>;
	struct _impl_js_jts_dRefactorActionInfo;
	using _js_jts_dRefactorActionInfo = js_ref<_impl_js_jts_dRefactorActionInfo>;
	struct _impl_js_jts_dRefactorEditInfo;
	using _js_jts_dRefactorEditInfo = js_ref<_impl_js_jts_dRefactorEditInfo>;
	struct _impl_js_jts_dTextInsertion;
	using _js_jts_dTextInsertion = js_ref<_impl_js_jts_dTextInsertion>;
	struct _impl_js_jts_dDocumentSpan;
	using _js_jts_dDocumentSpan = js_ref<_impl_js_jts_dDocumentSpan>;
	struct _impl_js_jts_dRenameLocation;
	using _js_jts_dRenameLocation = js_ref<_impl_js_jts_dRenameLocation>;
	struct _impl_js_jts_dReferenceEntry;
	using _js_jts_dReferenceEntry = js_ref<_impl_js_jts_dReferenceEntry>;
	struct _impl_js_jts_dImplementationLocation;
	using _js_jts_dImplementationLocation = js_ref<_impl_js_jts_dImplementationLocation>;
	struct _impl_js_jts_dDocumentHighlights;
	using _js_jts_dDocumentHighlights = js_ref<_impl_js_jts_dDocumentHighlights>;
	struct _impl_js_jts_dHighlightSpan;
	using _js_jts_dHighlightSpan = js_ref<_impl_js_jts_dHighlightSpan>;
	struct _impl_js_jts_dNavigateToItem;
	using _js_jts_dNavigateToItem = js_ref<_impl_js_jts_dNavigateToItem>;
	struct _impl_js_jts_dEditorOptions;
	using _js_jts_dEditorOptions = js_ref<_impl_js_jts_dEditorOptions>;
	struct _impl_js_jts_dEditorSettings;
	using _js_jts_dEditorSettings = js_ref<_impl_js_jts_dEditorSettings>;
	struct _impl_js_jts_dFormatCodeOptions;
	using _js_jts_dFormatCodeOptions = js_ref<_impl_js_jts_dFormatCodeOptions>;
	struct _impl_js_jts_dFormatCodeSettings;
	using _js_jts_dFormatCodeSettings = js_ref<_impl_js_jts_dFormatCodeSettings>;
	struct _impl_js_jts_dDefinitionInfo;
	using _js_jts_dDefinitionInfo = js_ref<_impl_js_jts_dDefinitionInfo>;
	struct _impl_js_jts_dDefinitionInfoAndBoundSpan;
	using _js_jts_dDefinitionInfoAndBoundSpan = js_ref<_impl_js_jts_dDefinitionInfoAndBoundSpan>;
	struct _impl_js_jts_dReferencedSymbolDefinitionInfo;
	using _js_jts_dReferencedSymbolDefinitionInfo = js_ref<_impl_js_jts_dReferencedSymbolDefinitionInfo>;
	struct _impl_js_jts_dReferencedSymbol;
	using _js_jts_dReferencedSymbol = js_ref<_impl_js_jts_dReferencedSymbol>;
	struct _impl_js_jts_dSymbolDisplayPart;
	using _js_jts_dSymbolDisplayPart = js_ref<_impl_js_jts_dSymbolDisplayPart>;
	struct _impl_js_jts_dJSDocTagInfo;
	using _js_jts_dJSDocTagInfo = js_ref<_impl_js_jts_dJSDocTagInfo>;
	struct _impl_js_jts_dQuickInfo;
	using _js_jts_dQuickInfo = js_ref<_impl_js_jts_dQuickInfo>;
	struct _impl_js_jts_dRenameInfoSuccess;
	using _js_jts_dRenameInfoSuccess = js_ref<_impl_js_jts_dRenameInfoSuccess>;
	struct _impl_js_jts_dRenameInfoFailure;
	using _js_jts_dRenameInfoFailure = js_ref<_impl_js_jts_dRenameInfoFailure>;
	struct _impl_js_jts_dRenameInfoOptions;
	using _js_jts_dRenameInfoOptions = js_ref<_impl_js_jts_dRenameInfoOptions>;
	struct _impl_js_jts_dSignatureHelpParameter;
	using _js_jts_dSignatureHelpParameter = js_ref<_impl_js_jts_dSignatureHelpParameter>;
	struct _impl_js_jts_dSelectionRange;
	using _js_jts_dSelectionRange = js_ref<_impl_js_jts_dSelectionRange>;
	struct _impl_js_jts_dSignatureHelpItem;
	using _js_jts_dSignatureHelpItem = js_ref<_impl_js_jts_dSignatureHelpItem>;
	struct _impl_js_jts_dSignatureHelpItems;
	using _js_jts_dSignatureHelpItems = js_ref<_impl_js_jts_dSignatureHelpItems>;
	struct _impl_js_jts_dCompletionInfo;
	using _js_jts_dCompletionInfo = js_ref<_impl_js_jts_dCompletionInfo>;
	struct _impl_js_jts_dCompletionEntry;
	using _js_jts_dCompletionEntry = js_ref<_impl_js_jts_dCompletionEntry>;
	struct _impl_js_jts_dCompletionEntryDetails;
	using _js_jts_dCompletionEntryDetails = js_ref<_impl_js_jts_dCompletionEntryDetails>;
	struct _impl_js_jts_dOutliningSpan;
	using _js_jts_dOutliningSpan = js_ref<_impl_js_jts_dOutliningSpan>;
	struct _impl_js_jts_dClassificationResult;
	using _js_jts_dClassificationResult = js_ref<_impl_js_jts_dClassificationResult>;
	struct _impl_js_jts_dClassificationInfo;
	using _js_jts_dClassificationInfo = js_ref<_impl_js_jts_dClassificationInfo>;
	struct _impl_js_jts_dClassifier;
	using _js_jts_dClassifier = js_ref<_impl_js_jts_dClassifier>;
	struct _impl_js_jts_dDocumentRegistry;
	using _js_jts_dDocumentRegistry = js_ref<_impl_js_jts_dDocumentRegistry>;
	struct _impl_js_jts_dTranspileOptions;
	using _js_jts_dTranspileOptions = js_ref<_impl_js_jts_dTranspileOptions>;
	struct _impl_js_jts_dTranspileOutput;
	using _js_jts_dTranspileOutput = js_ref<_impl_js_jts_dTranspileOutput>;
	struct _impl_js_j_qts_q : virtual IObject {
		struct _tcjs_definitions {
			using MapLike = _js_jts_dMapLike;
			using SortedReadonlyArray = _js_jts_dSortedReadonlyArray;
			using SortedArray = _js_jts_dSortedArray;
			using ReadonlyMap = _js_jts_dReadonlyMap;
			using Map = _js_jts_dMap;
			using Iterator = _js_jts_dIterator;
			using Push = _js_jts_dPush;
			using TextRange = _js_jts_dTextRange;
			using SyntaxKind = _js_jts_dSyntaxKind;
			using NodeFlags = _js_jts_dNodeFlags;
			using ModifierFlags = _js_jts_dModifierFlags;
			using JsxFlags = _js_jts_dJsxFlags;
			using Node = _js_jts_dNode;
			using JSDocContainer = _js_jts_dJSDocContainer;
			using NodeArray = _js_jts_dNodeArray;
			using Token = _js_jts_dToken;
			using Identifier = _js_jts_dIdentifier;
			using TransientIdentifier = _js_jts_dTransientIdentifier;
			using QualifiedName = _js_jts_dQualifiedName;
			using Declaration = _js_jts_dDeclaration;
			using NamedDeclaration = _js_jts_dNamedDeclaration;
			using DeclarationStatement = _js_jts_dDeclarationStatement;
			using ComputedPropertyName = _js_jts_dComputedPropertyName;
			using Decorator = _js_jts_dDecorator;
			using TypeParameterDeclaration = _js_jts_dTypeParameterDeclaration;
			using SignatureDeclarationBase = _js_jts_dSignatureDeclarationBase;
			using CallSignatureDeclaration = _js_jts_dCallSignatureDeclaration;
			using ConstructSignatureDeclaration = _js_jts_dConstructSignatureDeclaration;
			using VariableDeclaration = _js_jts_dVariableDeclaration;
			using VariableDeclarationList = _js_jts_dVariableDeclarationList;
			using ParameterDeclaration = _js_jts_dParameterDeclaration;
			using BindingElement = _js_jts_dBindingElement;
			using PropertySignature = _js_jts_dPropertySignature;
			using PropertyDeclaration = _js_jts_dPropertyDeclaration;
			using ObjectLiteralElement = _js_jts_dObjectLiteralElement;
			using PropertyAssignment = _js_jts_dPropertyAssignment;
			using ShorthandPropertyAssignment = _js_jts_dShorthandPropertyAssignment;
			using SpreadAssignment = _js_jts_dSpreadAssignment;
			using PropertyLikeDeclaration = _js_jts_dPropertyLikeDeclaration;
			using ObjectBindingPattern = _js_jts_dObjectBindingPattern;
			using ArrayBindingPattern = _js_jts_dArrayBindingPattern;
			using FunctionLikeDeclarationBase = _js_jts_dFunctionLikeDeclarationBase;
			using FunctionDeclaration = _js_jts_dFunctionDeclaration;
			using MethodSignature = _js_jts_dMethodSignature;
			using MethodDeclaration = _js_jts_dMethodDeclaration;
			using ConstructorDeclaration = _js_jts_dConstructorDeclaration;
			using SemicolonClassElement = _js_jts_dSemicolonClassElement;
			using GetAccessorDeclaration = _js_jts_dGetAccessorDeclaration;
			using SetAccessorDeclaration = _js_jts_dSetAccessorDeclaration;
			using IndexSignatureDeclaration = _js_jts_dIndexSignatureDeclaration;
			using TypeNode = _js_jts_dTypeNode;
			using KeywordTypeNode = _js_jts_dKeywordTypeNode;
			using ImportTypeNode = _js_jts_dImportTypeNode;
			using ThisTypeNode = _js_jts_dThisTypeNode;
			using FunctionOrConstructorTypeNodeBase = _js_jts_dFunctionOrConstructorTypeNodeBase;
			using FunctionTypeNode = _js_jts_dFunctionTypeNode;
			using ConstructorTypeNode = _js_jts_dConstructorTypeNode;
			using NodeWithTypeArguments = _js_jts_dNodeWithTypeArguments;
			using TypeReferenceNode = _js_jts_dTypeReferenceNode;
			using TypePredicateNode = _js_jts_dTypePredicateNode;
			using TypeQueryNode = _js_jts_dTypeQueryNode;
			using TypeLiteralNode = _js_jts_dTypeLiteralNode;
			using ArrayTypeNode = _js_jts_dArrayTypeNode;
			using TupleTypeNode = _js_jts_dTupleTypeNode;
			using OptionalTypeNode = _js_jts_dOptionalTypeNode;
			using RestTypeNode = _js_jts_dRestTypeNode;
			using UnionTypeNode = _js_jts_dUnionTypeNode;
			using IntersectionTypeNode = _js_jts_dIntersectionTypeNode;
			using ConditionalTypeNode = _js_jts_dConditionalTypeNode;
			using InferTypeNode = _js_jts_dInferTypeNode;
			using ParenthesizedTypeNode = _js_jts_dParenthesizedTypeNode;
			using TypeOperatorNode = _js_jts_dTypeOperatorNode;
			using IndexedAccessTypeNode = _js_jts_dIndexedAccessTypeNode;
			using MappedTypeNode = _js_jts_dMappedTypeNode;
			using LiteralTypeNode = _js_jts_dLiteralTypeNode;
			using StringLiteral = _js_jts_dStringLiteral;
			using Expression = _js_jts_dExpression;
			using OmittedExpression = _js_jts_dOmittedExpression;
			using PartiallyEmittedExpression = _js_jts_dPartiallyEmittedExpression;
			using UnaryExpression = _js_jts_dUnaryExpression;
			using UpdateExpression = _js_jts_dUpdateExpression;
			using PrefixUnaryExpression = _js_jts_dPrefixUnaryExpression;
			using PostfixUnaryExpression = _js_jts_dPostfixUnaryExpression;
			using LeftHandSideExpression = _js_jts_dLeftHandSideExpression;
			using MemberExpression = _js_jts_dMemberExpression;
			using PrimaryExpression = _js_jts_dPrimaryExpression;
			using NullLiteral = _js_jts_dNullLiteral;
			using BooleanLiteral = _js_jts_dBooleanLiteral;
			using ThisExpression = _js_jts_dThisExpression;
			using SuperExpression = _js_jts_dSuperExpression;
			using ImportExpression = _js_jts_dImportExpression;
			using DeleteExpression = _js_jts_dDeleteExpression;
			using TypeOfExpression = _js_jts_dTypeOfExpression;
			using VoidExpression = _js_jts_dVoidExpression;
			using AwaitExpression = _js_jts_dAwaitExpression;
			using YieldExpression = _js_jts_dYieldExpression;
			using SyntheticExpression = _js_jts_dSyntheticExpression;
			using BinaryExpression = _js_jts_dBinaryExpression;
			using AssignmentExpression = _js_jts_dAssignmentExpression;
			using ObjectDestructuringAssignment = _js_jts_dObjectDestructuringAssignment;
			using ArrayDestructuringAssignment = _js_jts_dArrayDestructuringAssignment;
			using ConditionalExpression = _js_jts_dConditionalExpression;
			using FunctionExpression = _js_jts_dFunctionExpression;
			using ArrowFunction = _js_jts_dArrowFunction;
			using LiteralLikeNode = _js_jts_dLiteralLikeNode;
			using LiteralExpression = _js_jts_dLiteralExpression;
			using RegularExpressionLiteral = _js_jts_dRegularExpressionLiteral;
			using NoSubstitutionTemplateLiteral = _js_jts_dNoSubstitutionTemplateLiteral;
			using TokenFlags = _js_jts_dTokenFlags;
			using NumericLiteral = _js_jts_dNumericLiteral;
			using BigIntLiteral = _js_jts_dBigIntLiteral;
			using TemplateHead = _js_jts_dTemplateHead;
			using TemplateMiddle = _js_jts_dTemplateMiddle;
			using TemplateTail = _js_jts_dTemplateTail;
			using TemplateExpression = _js_jts_dTemplateExpression;
			using TemplateSpan = _js_jts_dTemplateSpan;
			using ParenthesizedExpression = _js_jts_dParenthesizedExpression;
			using ArrayLiteralExpression = _js_jts_dArrayLiteralExpression;
			using SpreadElement = _js_jts_dSpreadElement;
			using ObjectLiteralExpressionBase = _js_jts_dObjectLiteralExpressionBase;
			using ObjectLiteralExpression = _js_jts_dObjectLiteralExpression;
			using PropertyAccessExpression = _js_jts_dPropertyAccessExpression;
			using SuperPropertyAccessExpression = _js_jts_dSuperPropertyAccessExpression;
			using PropertyAccessEntityNameExpression = _js_jts_dPropertyAccessEntityNameExpression;
			using ElementAccessExpression = _js_jts_dElementAccessExpression;
			using SuperElementAccessExpression = _js_jts_dSuperElementAccessExpression;
			using CallExpression = _js_jts_dCallExpression;
			using SuperCall = _js_jts_dSuperCall;
			using ImportCall = _js_jts_dImportCall;
			using ExpressionWithTypeArguments = _js_jts_dExpressionWithTypeArguments;
			using NewExpression = _js_jts_dNewExpression;
			using TaggedTemplateExpression = _js_jts_dTaggedTemplateExpression;
			using AsExpression = _js_jts_dAsExpression;
			using TypeAssertion = _js_jts_dTypeAssertion;
			using NonNullExpression = _js_jts_dNonNullExpression;
			using MetaProperty = _js_jts_dMetaProperty;
			using JsxElement = _js_jts_dJsxElement;
			using JsxTagNamePropertyAccess = _js_jts_dJsxTagNamePropertyAccess;
			using JsxAttributes = _js_jts_dJsxAttributes;
			using JsxOpeningElement = _js_jts_dJsxOpeningElement;
			using JsxSelfClosingElement = _js_jts_dJsxSelfClosingElement;
			using JsxFragment = _js_jts_dJsxFragment;
			using JsxOpeningFragment = _js_jts_dJsxOpeningFragment;
			using JsxClosingFragment = _js_jts_dJsxClosingFragment;
			using JsxAttribute = _js_jts_dJsxAttribute;
			using JsxSpreadAttribute = _js_jts_dJsxSpreadAttribute;
			using JsxClosingElement = _js_jts_dJsxClosingElement;
			using JsxExpression = _js_jts_dJsxExpression;
			using JsxText = _js_jts_dJsxText;
			using Statement = _js_jts_dStatement;
			using NotEmittedStatement = _js_jts_dNotEmittedStatement;
			using CommaListExpression = _js_jts_dCommaListExpression;
			using EmptyStatement = _js_jts_dEmptyStatement;
			using DebuggerStatement = _js_jts_dDebuggerStatement;
			using MissingDeclaration = _js_jts_dMissingDeclaration;
			using Block = _js_jts_dBlock;
			using VariableStatement = _js_jts_dVariableStatement;
			using ExpressionStatement = _js_jts_dExpressionStatement;
			using IfStatement = _js_jts_dIfStatement;
			using IterationStatement = _js_jts_dIterationStatement;
			using DoStatement = _js_jts_dDoStatement;
			using WhileStatement = _js_jts_dWhileStatement;
			using ForStatement = _js_jts_dForStatement;
			using ForInStatement = _js_jts_dForInStatement;
			using ForOfStatement = _js_jts_dForOfStatement;
			using BreakStatement = _js_jts_dBreakStatement;
			using ContinueStatement = _js_jts_dContinueStatement;
			using ReturnStatement = _js_jts_dReturnStatement;
			using WithStatement = _js_jts_dWithStatement;
			using SwitchStatement = _js_jts_dSwitchStatement;
			using CaseBlock = _js_jts_dCaseBlock;
			using CaseClause = _js_jts_dCaseClause;
			using DefaultClause = _js_jts_dDefaultClause;
			using LabeledStatement = _js_jts_dLabeledStatement;
			using ThrowStatement = _js_jts_dThrowStatement;
			using TryStatement = _js_jts_dTryStatement;
			using CatchClause = _js_jts_dCatchClause;
			using ClassLikeDeclarationBase = _js_jts_dClassLikeDeclarationBase;
			using ClassDeclaration = _js_jts_dClassDeclaration;
			using ClassExpression = _js_jts_dClassExpression;
			using ClassElement = _js_jts_dClassElement;
			using TypeElement = _js_jts_dTypeElement;
			using InterfaceDeclaration = _js_jts_dInterfaceDeclaration;
			using HeritageClause = _js_jts_dHeritageClause;
			using TypeAliasDeclaration = _js_jts_dTypeAliasDeclaration;
			using EnumMember = _js_jts_dEnumMember;
			using EnumDeclaration = _js_jts_dEnumDeclaration;
			using ModuleDeclaration = _js_jts_dModuleDeclaration;
			using NamespaceDeclaration = _js_jts_dNamespaceDeclaration;
			using JSDocNamespaceDeclaration = _js_jts_dJSDocNamespaceDeclaration;
			using ModuleBlock = _js_jts_dModuleBlock;
			using ImportEqualsDeclaration = _js_jts_dImportEqualsDeclaration;
			using ExternalModuleReference = _js_jts_dExternalModuleReference;
			using ImportDeclaration = _js_jts_dImportDeclaration;
			using ImportClause = _js_jts_dImportClause;
			using NamespaceImport = _js_jts_dNamespaceImport;
			using NamespaceExportDeclaration = _js_jts_dNamespaceExportDeclaration;
			using ExportDeclaration = _js_jts_dExportDeclaration;
			using NamedImports = _js_jts_dNamedImports;
			using NamedExports = _js_jts_dNamedExports;
			using ImportSpecifier = _js_jts_dImportSpecifier;
			using ExportSpecifier = _js_jts_dExportSpecifier;
			using ExportAssignment = _js_jts_dExportAssignment;
			using FileReference = _js_jts_dFileReference;
			using CheckJsDirective = _js_jts_dCheckJsDirective;
			using CommentRange = _js_jts_dCommentRange;
			using SynthesizedComment = _js_jts_dSynthesizedComment;
			using JSDocTypeExpression = _js_jts_dJSDocTypeExpression;
			using JSDocType = _js_jts_dJSDocType;
			using JSDocAllType = _js_jts_dJSDocAllType;
			using JSDocUnknownType = _js_jts_dJSDocUnknownType;
			using JSDocNonNullableType = _js_jts_dJSDocNonNullableType;
			using JSDocNullableType = _js_jts_dJSDocNullableType;
			using JSDocOptionalType = _js_jts_dJSDocOptionalType;
			using JSDocFunctionType = _js_jts_dJSDocFunctionType;
			using JSDocVariadicType = _js_jts_dJSDocVariadicType;
			using JSDoc = _js_jts_dJSDoc;
			using JSDocTag = _js_jts_dJSDocTag;
			using JSDocUnknownTag = _js_jts_dJSDocUnknownTag;
			using JSDocAugmentsTag = _js_jts_dJSDocAugmentsTag;
			using JSDocClassTag = _js_jts_dJSDocClassTag;
			using JSDocEnumTag = _js_jts_dJSDocEnumTag;
			using JSDocThisTag = _js_jts_dJSDocThisTag;
			using JSDocTemplateTag = _js_jts_dJSDocTemplateTag;
			using JSDocReturnTag = _js_jts_dJSDocReturnTag;
			using JSDocTypeTag = _js_jts_dJSDocTypeTag;
			using JSDocTypedefTag = _js_jts_dJSDocTypedefTag;
			using JSDocCallbackTag = _js_jts_dJSDocCallbackTag;
			using JSDocSignature = _js_jts_dJSDocSignature;
			using JSDocPropertyLikeTag = _js_jts_dJSDocPropertyLikeTag;
			using JSDocPropertyTag = _js_jts_dJSDocPropertyTag;
			using JSDocParameterTag = _js_jts_dJSDocParameterTag;
			using JSDocTypeLiteral = _js_jts_dJSDocTypeLiteral;
			using FlowFlags = _js_jts_dFlowFlags;
			using FlowLock = _js_jts_dFlowLock;
			using AfterFinallyFlow = _js_jts_dAfterFinallyFlow;
			using PreFinallyFlow = _js_jts_dPreFinallyFlow;
			using FlowNodeBase = _js_jts_dFlowNodeBase;
			using FlowStart = _js_jts_dFlowStart;
			using FlowLabel = _js_jts_dFlowLabel;
			using FlowAssignment = _js_jts_dFlowAssignment;
			using FlowCondition = _js_jts_dFlowCondition;
			using FlowSwitchClause = _js_jts_dFlowSwitchClause;
			using FlowArrayMutation = _js_jts_dFlowArrayMutation;
			using IncompleteType = _js_jts_dIncompleteType;
			using AmdDependency = _js_jts_dAmdDependency;
			using SourceFile = _js_jts_dSourceFile;
			using Bundle = _js_jts_dBundle;
			using InputFiles = _js_jts_dInputFiles;
			using UnparsedSource = _js_jts_dUnparsedSource;
			using UnparsedSection = _js_jts_dUnparsedSection;
			using UnparsedPrologue = _js_jts_dUnparsedPrologue;
			using UnparsedPrepend = _js_jts_dUnparsedPrepend;
			using UnparsedTextLike = _js_jts_dUnparsedTextLike;
			using UnparsedSyntheticReference = _js_jts_dUnparsedSyntheticReference;
			using JsonSourceFile = _js_jts_dJsonSourceFile;
			using TsConfigSourceFile = _js_jts_dTsConfigSourceFile;
			using JsonMinusNumericLiteral = _js_jts_dJsonMinusNumericLiteral;
			using JsonObjectExpressionStatement = _js_jts_dJsonObjectExpressionStatement;
			using ScriptReferenceHost = _js_jts_dScriptReferenceHost;
			using ParseConfigHost = _js_jts_dParseConfigHost;
			using OperationCanceledException = _js_jts_dOperationCanceledException;
			using CancellationToken = _js_jts_dCancellationToken;
			using Program = _js_jts_dProgram;
			using ResolvedProjectReference = _js_jts_dResolvedProjectReference;
			using CustomTransformer = _js_jts_dCustomTransformer;
			using CustomTransformers = _js_jts_dCustomTransformers;
			using SourceMapSpan = _js_jts_dSourceMapSpan;
			using ExitStatus = _js_jts_dExitStatus;
			using EmitResult = _js_jts_dEmitResult;
			using TypeChecker = _js_jts_dTypeChecker;
			using NodeBuilderFlags = _js_jts_dNodeBuilderFlags;
			using TypeFormatFlags = _js_jts_dTypeFormatFlags;
			using SymbolFormatFlags = _js_jts_dSymbolFormatFlags;
			using TypePredicateKind = _js_jts_dTypePredicateKind;
			using TypePredicateBase = _js_jts_dTypePredicateBase;
			using ThisTypePredicate = _js_jts_dThisTypePredicate;
			using IdentifierTypePredicate = _js_jts_dIdentifierTypePredicate;
			using SymbolFlags = _js_jts_dSymbolFlags;
			using Symbol = _js_jts_dSymbol;
			using InternalSymbolName = _js_jts_dInternalSymbolName;
			using ReadonlyUnderscoreEscapedMap = _js_jts_dReadonlyUnderscoreEscapedMap;
			using UnderscoreEscapedMap = _js_jts_dUnderscoreEscapedMap;
			using TypeFlags = _js_jts_dTypeFlags;
			using Type = _js_jts_dType;
			using LiteralType = _js_jts_dLiteralType;
			using UniqueESSymbolType = _js_jts_dUniqueESSymbolType;
			using StringLiteralType = _js_jts_dStringLiteralType;
			using NumberLiteralType = _js_jts_dNumberLiteralType;
			using BigIntLiteralType = _js_jts_dBigIntLiteralType;
			using EnumType = _js_jts_dEnumType;
			using ObjectFlags = _js_jts_dObjectFlags;
			using ObjectType = _js_jts_dObjectType;
			using InterfaceType = _js_jts_dInterfaceType;
			using InterfaceTypeWithDeclaredMembers = _js_jts_dInterfaceTypeWithDeclaredMembers;
			using TypeReference = _js_jts_dTypeReference;
			using GenericType = _js_jts_dGenericType;
			using TupleType = _js_jts_dTupleType;
			using TupleTypeReference = _js_jts_dTupleTypeReference;
			using UnionOrIntersectionType = _js_jts_dUnionOrIntersectionType;
			using UnionType = _js_jts_dUnionType;
			using IntersectionType = _js_jts_dIntersectionType;
			using EvolvingArrayType = _js_jts_dEvolvingArrayType;
			using InstantiableType = _js_jts_dInstantiableType;
			using TypeParameter = _js_jts_dTypeParameter;
			using IndexedAccessType = _js_jts_dIndexedAccessType;
			using IndexType = _js_jts_dIndexType;
			using ConditionalRoot = _js_jts_dConditionalRoot;
			using ConditionalType = _js_jts_dConditionalType;
			using SubstitutionType = _js_jts_dSubstitutionType;
			using SignatureKind = _js_jts_dSignatureKind;
			using Signature = _js_jts_dSignature;
			using IndexKind = _js_jts_dIndexKind;
			using IndexInfo = _js_jts_dIndexInfo;
			using InferencePriority = _js_jts_dInferencePriority;
			using FileExtensionInfo = _js_jts_dFileExtensionInfo;
			using DiagnosticMessage = _js_jts_dDiagnosticMessage;
			using DiagnosticMessageChain = _js_jts_dDiagnosticMessageChain;
			using Diagnostic = _js_jts_dDiagnostic;
			using DiagnosticRelatedInformation = _js_jts_dDiagnosticRelatedInformation;
			using DiagnosticWithLocation = _js_jts_dDiagnosticWithLocation;
			using DiagnosticCategory = _js_jts_dDiagnosticCategory;
			using ModuleResolutionKind = _js_jts_dModuleResolutionKind;
			using PluginImport = _js_jts_dPluginImport;
			using ProjectReference = _js_jts_dProjectReference;
			using CompilerOptions = _js_jts_dCompilerOptions;
			using TypeAcquisition = _js_jts_dTypeAcquisition;
			using ModuleKind = _js_jts_dModuleKind;
			using JsxEmit = _js_jts_dJsxEmit;
			using NewLineKind = _js_jts_dNewLineKind;
			using LineAndCharacter = _js_jts_dLineAndCharacter;
			using ScriptKind = _js_jts_dScriptKind;
			using ScriptTarget = _js_jts_dScriptTarget;
			using LanguageVariant = _js_jts_dLanguageVariant;
			using ParsedCommandLine = _js_jts_dParsedCommandLine;
			using WatchDirectoryFlags = _js_jts_dWatchDirectoryFlags;
			using ExpandResult = _js_jts_dExpandResult;
			using CreateProgramOptions = _js_jts_dCreateProgramOptions;
			using ModuleResolutionHost = _js_jts_dModuleResolutionHost;
			using ResolvedModule = _js_jts_dResolvedModule;
			using ResolvedModuleFull = _js_jts_dResolvedModuleFull;
			using PackageId = _js_jts_dPackageId;
			using Extension = _js_jts_dExtension;
			using ResolvedModuleWithFailedLookupLocations = _js_jts_dResolvedModuleWithFailedLookupLocations;
			using ResolvedTypeReferenceDirective = _js_jts_dResolvedTypeReferenceDirective;
			using ResolvedTypeReferenceDirectiveWithFailedLookupLocations = _js_jts_dResolvedTypeReferenceDirectiveWithFailedLookupLocations;
			using CompilerHost = _js_jts_dCompilerHost;
			using SourceMapRange = _js_jts_dSourceMapRange;
			using SourceMapSource = _js_jts_dSourceMapSource;
			using EmitFlags = _js_jts_dEmitFlags;
			using EmitHelper = _js_jts_dEmitHelper;
			using UnscopedEmitHelper = _js_jts_dUnscopedEmitHelper;
			using EmitHint = _js_jts_dEmitHint;
			using TransformationContext = _js_jts_dTransformationContext;
			using TransformationResult = _js_jts_dTransformationResult;
			using Printer = _js_jts_dPrinter;
			using PrintHandlers = _js_jts_dPrintHandlers;
			using PrinterOptions = _js_jts_dPrinterOptions;
			using GetEffectiveTypeRootsHost = _js_jts_dGetEffectiveTypeRootsHost;
			using TextSpan = _js_jts_dTextSpan;
			using TextChangeRange = _js_jts_dTextChangeRange;
			using SyntaxList = _js_jts_dSyntaxList;
			using ListFormat = _js_jts_dListFormat;
			using UserPreferences = _js_jts_dUserPreferences;
			using PseudoBigInt = _js_jts_dPseudoBigInt;
			using FileWatcherEventKind = _js_jts_dFileWatcherEventKind;
			using System = _js_jts_dSystem;
			using FileWatcher = _js_jts_dFileWatcher;
			using Scanner = _js_jts_dScanner;
			using ConfigFileDiagnosticsReporter = _js_jts_dConfigFileDiagnosticsReporter;
			using ParseConfigFileHost = _js_jts_dParseConfigFileHost;
			using ParsedTsconfig = _js_jts_dParsedTsconfig;
			using ExtendedConfigCacheEntry = _js_jts_dExtendedConfigCacheEntry;
			using ModuleResolutionCache = _js_jts_dModuleResolutionCache;
			using NonRelativeModuleNameResolutionCache = _js_jts_dNonRelativeModuleNameResolutionCache;
			using PerModuleNameCache = _js_jts_dPerModuleNameCache;
			using FormatDiagnosticsHost = _js_jts_dFormatDiagnosticsHost;
			using ResolveProjectReferencePathHost = _js_jts_dResolveProjectReferencePathHost;
			using EmitOutput = _js_jts_dEmitOutput;
			using OutputFile = _js_jts_dOutputFile;
			using BuilderProgramHost = _js_jts_dBuilderProgramHost;
			using BuilderProgram = _js_jts_dBuilderProgram;
			using SemanticDiagnosticsBuilderProgram = _js_jts_dSemanticDiagnosticsBuilderProgram;
			using EmitAndSemanticDiagnosticsBuilderProgram = _js_jts_dEmitAndSemanticDiagnosticsBuilderProgram;
			using WatchHost = _js_jts_dWatchHost;
			using ProgramHost = _js_jts_dProgramHost;
			using WatchCompilerHost = _js_jts_dWatchCompilerHost;
			using WatchCompilerHostOfFilesAndCompilerOptions = _js_jts_dWatchCompilerHostOfFilesAndCompilerOptions;
			using WatchCompilerHostOfConfigFile = _js_jts_dWatchCompilerHostOfConfigFile;
			using Watch = _js_jts_dWatch;
			using WatchOfConfigFile = _js_jts_dWatchOfConfigFile;
			using WatchOfFilesAndCompilerOptions = _js_jts_dWatchOfFilesAndCompilerOptions;
			using server = _js_jts_dserver;
			using SourceFileLike = _js_jts_dSourceFileLike;
			using IScriptSnapshot = _js_jts_dIScriptSnapshot;
			using ScriptSnapshot = _js_jts_dScriptSnapshot;
			using PreProcessedFileInfo = _js_jts_dPreProcessedFileInfo;
			using HostCancellationToken = _js_jts_dHostCancellationToken;
			using InstallPackageOptions = _js_jts_dInstallPackageOptions;
			using LanguageServiceHost = _js_jts_dLanguageServiceHost;
			using LanguageService = _js_jts_dLanguageService;
			using JsxClosingTagInfo = _js_jts_dJsxClosingTagInfo;
			using CombinedCodeFixScope = _js_jts_dCombinedCodeFixScope;
			using GetCompletionsAtPositionOptions = _js_jts_dGetCompletionsAtPositionOptions;
			using SignatureHelpItemsOptions = _js_jts_dSignatureHelpItemsOptions;
			using SignatureHelpInvokedReason = _js_jts_dSignatureHelpInvokedReason;
			using SignatureHelpCharacterTypedReason = _js_jts_dSignatureHelpCharacterTypedReason;
			using SignatureHelpRetriggeredReason = _js_jts_dSignatureHelpRetriggeredReason;
			using ApplyCodeActionCommandResult = _js_jts_dApplyCodeActionCommandResult;
			using Classifications = _js_jts_dClassifications;
			using ClassifiedSpan = _js_jts_dClassifiedSpan;
			using NavigationBarItem = _js_jts_dNavigationBarItem;
			using NavigationTree = _js_jts_dNavigationTree;
			using TodoCommentDescriptor = _js_jts_dTodoCommentDescriptor;
			using TodoComment = _js_jts_dTodoComment;
			using TextChange = _js_jts_dTextChange;
			using FileTextChanges = _js_jts_dFileTextChanges;
			using CodeAction = _js_jts_dCodeAction;
			using CodeFixAction = _js_jts_dCodeFixAction;
			using CombinedCodeActions = _js_jts_dCombinedCodeActions;
			using InstallPackageAction = _js_jts_dInstallPackageAction;
			using ApplicableRefactorInfo = _js_jts_dApplicableRefactorInfo;
			using RefactorActionInfo = _js_jts_dRefactorActionInfo;
			using RefactorEditInfo = _js_jts_dRefactorEditInfo;
			using TextInsertion = _js_jts_dTextInsertion;
			using DocumentSpan = _js_jts_dDocumentSpan;
			using RenameLocation = _js_jts_dRenameLocation;
			using ReferenceEntry = _js_jts_dReferenceEntry;
			using ImplementationLocation = _js_jts_dImplementationLocation;
			using DocumentHighlights = _js_jts_dDocumentHighlights;
			using HighlightSpanKind = _js_jts_dHighlightSpanKind;
			using HighlightSpan = _js_jts_dHighlightSpan;
			using NavigateToItem = _js_jts_dNavigateToItem;
			using IndentStyle = _js_jts_dIndentStyle;
			using EditorOptions = _js_jts_dEditorOptions;
			using EditorSettings = _js_jts_dEditorSettings;
			using FormatCodeOptions = _js_jts_dFormatCodeOptions;
			using FormatCodeSettings = _js_jts_dFormatCodeSettings;
			using DefinitionInfo = _js_jts_dDefinitionInfo;
			using DefinitionInfoAndBoundSpan = _js_jts_dDefinitionInfoAndBoundSpan;
			using ReferencedSymbolDefinitionInfo = _js_jts_dReferencedSymbolDefinitionInfo;
			using ReferencedSymbol = _js_jts_dReferencedSymbol;
			using SymbolDisplayPartKind = _js_jts_dSymbolDisplayPartKind;
			using SymbolDisplayPart = _js_jts_dSymbolDisplayPart;
			using JSDocTagInfo = _js_jts_dJSDocTagInfo;
			using QuickInfo = _js_jts_dQuickInfo;
			using RenameInfoSuccess = _js_jts_dRenameInfoSuccess;
			using RenameInfoFailure = _js_jts_dRenameInfoFailure;
			using RenameInfoOptions = _js_jts_dRenameInfoOptions;
			using SignatureHelpParameter = _js_jts_dSignatureHelpParameter;
			using SelectionRange = _js_jts_dSelectionRange;
			using SignatureHelpItem = _js_jts_dSignatureHelpItem;
			using SignatureHelpItems = _js_jts_dSignatureHelpItems;
			using CompletionInfo = _js_jts_dCompletionInfo;
			using CompletionEntry = _js_jts_dCompletionEntry;
			using CompletionEntryDetails = _js_jts_dCompletionEntryDetails;
			using OutliningSpan = _js_jts_dOutliningSpan;
			using OutliningSpanKind = _js_jts_dOutliningSpanKind;
			using OutputFileType = _js_jts_dOutputFileType;
			using EndOfLineState = _js_jts_dEndOfLineState;
			using TokenClass = _js_jts_dTokenClass;
			using ClassificationResult = _js_jts_dClassificationResult;
			using ClassificationInfo = _js_jts_dClassificationInfo;
			using Classifier = _js_jts_dClassifier;
			using ScriptElementKind = _js_jts_dScriptElementKind;
			using ScriptElementKindModifier = _js_jts_dScriptElementKindModifier;
			using ClassificationTypeNames = _js_jts_dClassificationTypeNames;
			using ClassificationType = _js_jts_dClassificationType;
			using DocumentRegistry = _js_jts_dDocumentRegistry;
			using TranspileOptions = _js_jts_dTranspileOptions;
			using TranspileOutput = _js_jts_dTranspileOutput;
			static auto addEmitHelper(js_unknown /*flags=262144: T ()*/ node, _js_jts_dEmitHelper helper) noexcept;
			static auto addEmitHelpers(js_unknown /*flags=262144: T ()*/ node, js_union<js::Array<_js_jts_dEmitHelper>, js_undefined> helpers = js_undefined()) noexcept;
			static auto addSyntheticLeadingComment(js_unknown /*flags=262144: T ()*/ node, _js_jts_dSyntaxKind /*SyntaxKind.SingleLineCommentTrivia*/ kind, js_string text, js_union<bool /*false*/, js_undefined> hasTrailingNewLine = js_undefined()) noexcept;
			static auto addSyntheticTrailingComment(js_unknown /*flags=262144: T ()*/ node, _js_jts_dSyntaxKind /*SyntaxKind.SingleLineCommentTrivia*/ kind, js_string text, js_union<bool /*false*/, js_undefined> hasTrailingNewLine = js_undefined()) noexcept;
			static auto classicNameResolver(js_string moduleName, js_string containingFile, _js_jts_dCompilerOptions compilerOptions, _js_jts_dModuleResolutionHost host, js_union<_js_jts_dNonRelativeModuleNameResolutionCache, js_undefined> cache = js_undefined(), js_union<_js_jts_dResolvedProjectReference, js_undefined> redirectedReference = js_undefined()) noexcept;
			static auto collapseTextChangeRangesAcrossMultipleVersions(js::ReadonlyArray<_js_jts_dTextChangeRange> changes) noexcept;
			static auto convertCompilerOptionsFromJson(js_unknown jsonOptions, js_string basePath, js_union<js_string, js_undefined> configFileName = js_undefined()) noexcept;
			static auto convertToObject(_js_jts_dJsonSourceFile sourceFile, js_unknown /*flags=524288: Push<Diagnostic> (TypeReference=ts.Push)*/ errors) noexcept;
			static auto convertTypeAcquisitionFromJson(js_unknown jsonOptions, js_string basePath, js_union<js_string, js_undefined> configFileName = js_undefined()) noexcept;
			static auto couldStartTrivia(js_string text, double pos) noexcept;
			static auto createAbstractBuilder(_js_jts_dProgram newProgram, _js_jts_dBuilderProgramHost host, js_union<_js_jts_dBuilderProgram, js_undefined> oldProgram = js_undefined(), js_union<js::ReadonlyArray<_js_jts_dDiagnostic>, js_undefined> configFileParsingDiagnostics = js_undefined()) noexcept;
			static auto createAbstractBuilder(js_union<js::ReadonlyArray<js_string>, js_undefined> rootNames = js_undefined(), js_union<_js_jts_dCompilerOptions, js_undefined> options = js_undefined(), js_union<_js_jts_dCompilerHost, js_undefined> host = js_undefined(), js_union<_js_jts_dBuilderProgram, js_undefined> oldProgram = js_undefined(), js_union<js::ReadonlyArray<_js_jts_dDiagnostic>, js_undefined> configFileParsingDiagnostics = js_undefined(), js_union<js::ReadonlyArray<_js_jts_dProjectReference>, js_undefined> projectReferences = js_undefined()) noexcept;
			static auto createAdd(_js_jts_dExpression left, _js_jts_dExpression right) noexcept;
			static auto createArrayBindingPattern(js::ReadonlyArray<js_union<_js_jts_dBindingElement, _js_jts_dOmittedExpression>> elements) noexcept;
			static auto createArrayLiteral(js_union<js::ReadonlyArray<_js_jts_dExpression>, js_undefined> elements = js_undefined(), js_union<bool /*false*/, js_undefined> multiLine = js_undefined()) noexcept;
			static auto createArrayTypeNode(_js_jts_dTypeNode elementType) noexcept;
			static auto createArrowFunction(js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, js_union<_js_jts_dTypeNode, js_undefined> type, js_unknown /*flags=1048576: Token<SyntaxKind.EqualsGreaterThanToken> | undefined ()*/ equalsGreaterThanToken, js_union<_js_jts_dBlock, _js_jts_dExpression> body) noexcept;
			static auto createAsExpression(_js_jts_dExpression expression, _js_jts_dTypeNode type) noexcept;
			static auto createAssignment(_js_jts_dExpression left, _js_jts_dExpression right) noexcept;
			static auto createAssignment(js_union<_js_jts_dArrayLiteralExpression, _js_jts_dObjectLiteralExpression> left, _js_jts_dExpression right) noexcept;
			static auto createAwait(_js_jts_dExpression expression) noexcept;
			static auto createBigIntLiteral(js_string value) noexcept;
			static auto createBinary(_js_jts_dExpression left, js_unknown /*flags=1048576: SyntaxKind.CommaToken | SyntaxKind.LessThanToken | SyntaxKind.GreaterThanToken | SyntaxKind.LessThanEqualsToken | SyntaxKind.GreaterThanEqualsToken | SyntaxKind.EqualsEqualsToken | SyntaxKind.ExclamationEqualsToken | SyntaxKind.EqualsEqualsEqualsToken | SyntaxKind.ExclamationEqualsEqualsToken | SyntaxKind.PlusToken ... ()*/ operator_, _js_jts_dExpression right) noexcept;
			static auto createBindingElement(js_unknown /*flags=1048576: Token<SyntaxKind.DotDotDotToken> | undefined ()*/ dotDotDotToken, js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral, js_string, js_undefined> propertyName, js_union<_js_jts_dArrayBindingPattern, _js_jts_dIdentifier, _js_jts_dObjectBindingPattern, js_string> name, js_union<_js_jts_dExpression, js_undefined> initializer = js_undefined()) noexcept;
			static auto createBlock(js::ReadonlyArray<_js_jts_dStatement> statements, js_union<bool /*false*/, js_undefined> multiLine = js_undefined()) noexcept;
			static auto createBreak(js_union<_js_jts_dIdentifier, js_string, js_undefined> label = js_undefined()) noexcept;
			static auto createBundle(js::ReadonlyArray<_js_jts_dSourceFile> sourceFiles, js_union<js::ReadonlyArray<js_union<_js_jts_dInputFiles, _js_jts_dUnparsedSource>>, js_undefined> prepends = js_undefined()) noexcept;
			static auto createCall(_js_jts_dExpression expression, js_union<js::ReadonlyArray<_js_jts_dTypeNode>, js_undefined> typeArguments = js_undefined(), js_union<js::ReadonlyArray<_js_jts_dExpression>, js_undefined> argumentsArray = js_undefined()) noexcept;
			static auto createCallSignature(js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, js_union<_js_jts_dTypeNode, js_undefined> type = js_undefined()) noexcept;
			static auto createCaseBlock(js::ReadonlyArray<js_union<_js_jts_dCaseClause, _js_jts_dDefaultClause>> clauses) noexcept;
			static auto createCaseClause(_js_jts_dExpression expression, js::ReadonlyArray<_js_jts_dStatement> statements) noexcept;
			static auto createCatchClause(js_union<_js_jts_dVariableDeclaration, js_string, js_undefined> variableDeclaration, _js_jts_dBlock block) noexcept;
			static auto createClassDeclaration(js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dIdentifier, js_string, js_undefined> name, js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, js_union<js::ReadonlyArray<_js_jts_dHeritageClause>, js_undefined> heritageClauses, js::ReadonlyArray<_js_jts_dClassElement> members) noexcept;
			static auto createClassExpression(js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dIdentifier, js_string, js_undefined> name, js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, js_union<js::ReadonlyArray<_js_jts_dHeritageClause>, js_undefined> heritageClauses, js::ReadonlyArray<_js_jts_dClassElement> members) noexcept;
			static auto createClassifier() noexcept;
			static auto createComma(_js_jts_dExpression left, _js_jts_dExpression right) noexcept;
			static auto createCommaList(js::ReadonlyArray<_js_jts_dExpression> elements) noexcept;
			static auto createCompilerHost(_js_jts_dCompilerOptions options, js_union<bool /*false*/, js_undefined> setParentNodes = js_undefined()) noexcept;
			static auto createComputedPropertyName(_js_jts_dExpression expression) noexcept;
			static auto createConditional(_js_jts_dExpression condition, _js_jts_dExpression whenTrue, _js_jts_dExpression whenFalse) noexcept;
			static auto createConditional(_js_jts_dExpression condition, js_unknown /*flags=524288: Token<SyntaxKind.QuestionToken> (TypeReference=ts.Token)*/ questionToken, _js_jts_dExpression whenTrue, js_unknown /*flags=524288: Token<SyntaxKind.ColonToken> (TypeReference=ts.Token)*/ colonToken, _js_jts_dExpression whenFalse) noexcept;
			static auto createConditionalTypeNode(_js_jts_dTypeNode checkType, _js_jts_dTypeNode extendsType, _js_jts_dTypeNode trueType, _js_jts_dTypeNode falseType) noexcept;
			static auto createConstructSignature(js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, js_union<_js_jts_dTypeNode, js_undefined> type = js_undefined()) noexcept;
			static auto createConstructor(js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, js_union<_js_jts_dBlock, js_undefined> body = js_undefined()) noexcept;
			static auto createConstructorTypeNode(js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, js_union<_js_jts_dTypeNode, js_undefined> type = js_undefined()) noexcept;
			static auto createContinue(js_union<_js_jts_dIdentifier, js_string, js_undefined> label = js_undefined()) noexcept;
			static auto createDebuggerStatement() noexcept;
			static auto createDecorator(_js_jts_dExpression expression) noexcept;
			static auto createDefaultClause(js::ReadonlyArray<_js_jts_dStatement> statements) noexcept;
			static auto createDelete(_js_jts_dExpression expression) noexcept;
			static auto createDo(_js_jts_dStatement statement, _js_jts_dExpression expression) noexcept;
			static auto createDocumentRegistry(js_union<bool /*false*/, js_undefined> useCaseSensitiveFileNames = js_undefined(), js_union<js_string, js_undefined> currentDirectory = js_undefined()) noexcept;
			static auto createElementAccess(_js_jts_dExpression expression, js_union<_js_jts_dExpression, double> index) noexcept;
			static auto createEmitAndSemanticDiagnosticsBuilderProgram(_js_jts_dProgram newProgram, _js_jts_dBuilderProgramHost host, js_union<_js_jts_dEmitAndSemanticDiagnosticsBuilderProgram, js_undefined> oldProgram = js_undefined(), js_union<js::ReadonlyArray<_js_jts_dDiagnostic>, js_undefined> configFileParsingDiagnostics = js_undefined()) noexcept;
			static auto createEmitAndSemanticDiagnosticsBuilderProgram(js_union<js::ReadonlyArray<js_string>, js_undefined> rootNames = js_undefined(), js_union<_js_jts_dCompilerOptions, js_undefined> options = js_undefined(), js_union<_js_jts_dCompilerHost, js_undefined> host = js_undefined(), js_union<_js_jts_dEmitAndSemanticDiagnosticsBuilderProgram, js_undefined> oldProgram = js_undefined(), js_union<js::ReadonlyArray<_js_jts_dDiagnostic>, js_undefined> configFileParsingDiagnostics = js_undefined(), js_union<js::ReadonlyArray<_js_jts_dProjectReference>, js_undefined> projectReferences = js_undefined()) noexcept;
			static auto createEmptyStatement() noexcept;
			static auto createEnumDeclaration(js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dIdentifier, js_string> name, js::ReadonlyArray<_js_jts_dEnumMember> members) noexcept;
			static auto createEnumMember(js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral, js_string> name, js_union<_js_jts_dExpression, js_undefined> initializer = js_undefined()) noexcept;
			static auto createExportAssignment(js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<bool /*false*/, js_undefined> isExportEquals, _js_jts_dExpression expression) noexcept;
			static auto createExportDeclaration(js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators = js_undefined(), js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers = js_undefined(), js_union<_js_jts_dNamedExports, js_undefined> exportClause = js_undefined(), js_union<_js_jts_dExpression, js_undefined> moduleSpecifier = js_undefined()) noexcept;
			static auto createExportDefault(_js_jts_dExpression expression) noexcept;
			static auto createExportSpecifier(js_union<_js_jts_dIdentifier, js_string, js_undefined> propertyName, js_union<_js_jts_dIdentifier, js_string> name) noexcept;
			static auto createExpressionStatement(_js_jts_dExpression expression) noexcept;
			static auto createExpressionWithTypeArguments(js_union<js::ReadonlyArray<_js_jts_dTypeNode>, js_undefined> typeArguments, _js_jts_dExpression expression) noexcept;
			static auto createExternalModuleExport(_js_jts_dIdentifier exportName) noexcept;
			static auto createExternalModuleReference(_js_jts_dExpression expression) noexcept;
			static auto createFalse() noexcept;
			static auto createFileLevelUniqueName(js_string text) noexcept;
			static auto createFor(js_union<_js_jts_dExpression, _js_jts_dVariableDeclarationList, js_undefined> initializer, js_union<_js_jts_dExpression, js_undefined> condition, js_union<_js_jts_dExpression, js_undefined> incrementor, _js_jts_dStatement statement) noexcept;
			static auto createForIn(js_union<_js_jts_dExpression, _js_jts_dVariableDeclarationList> initializer, _js_jts_dExpression expression, _js_jts_dStatement statement) noexcept;
			static auto createForOf(js_unknown /*flags=1048576: Token<SyntaxKind.AwaitKeyword> | undefined ()*/ awaitModifier, js_union<_js_jts_dExpression, _js_jts_dVariableDeclarationList> initializer, _js_jts_dExpression expression, _js_jts_dStatement statement) noexcept;
			static auto createFunctionDeclaration(js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_unknown /*flags=1048576: Token<SyntaxKind.AsteriskToken> | undefined ()*/ asteriskToken, js_union<_js_jts_dIdentifier, js_string, js_undefined> name, js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, js_union<_js_jts_dTypeNode, js_undefined> type = js_undefined(), js_union<_js_jts_dBlock, js_undefined> body = js_undefined()) noexcept;
			static auto createFunctionExpression(js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_unknown /*flags=1048576: Token<SyntaxKind.AsteriskToken> | undefined ()*/ asteriskToken, js_union<_js_jts_dIdentifier, js_string, js_undefined> name, js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, js_union<js::ReadonlyArray<_js_jts_dParameterDeclaration>, js_undefined> parameters, js_union<_js_jts_dTypeNode, js_undefined> type, _js_jts_dBlock body) noexcept;
			static auto createFunctionTypeNode(js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, js_union<_js_jts_dTypeNode, js_undefined> type = js_undefined()) noexcept;
			static auto createGetAccessor(js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral, js_string> name, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, js_union<_js_jts_dTypeNode, js_undefined> type = js_undefined(), js_union<_js_jts_dBlock, js_undefined> body = js_undefined()) noexcept;
			static auto createHeritageClause(_js_jts_dSyntaxKind /*SyntaxKind.ExtendsKeyword*/ token, js::ReadonlyArray<_js_jts_dExpressionWithTypeArguments> types) noexcept;
			static auto createIdentifier(js_string text) noexcept;
			static auto createIf(_js_jts_dExpression expression, _js_jts_dStatement thenStatement, js_union<_js_jts_dStatement, js_undefined> elseStatement = js_undefined()) noexcept;
			static auto createImmediatelyInvokedArrowFunction(js::ReadonlyArray<_js_jts_dStatement> statements) noexcept;
			static auto createImmediatelyInvokedArrowFunction(js::ReadonlyArray<_js_jts_dStatement> statements, _js_jts_dParameterDeclaration param, _js_jts_dExpression paramValue) noexcept;
			static auto createImmediatelyInvokedFunctionExpression(js::ReadonlyArray<_js_jts_dStatement> statements) noexcept;
			static auto createImmediatelyInvokedFunctionExpression(js::ReadonlyArray<_js_jts_dStatement> statements, _js_jts_dParameterDeclaration param, _js_jts_dExpression paramValue) noexcept;
			static auto createImportClause(js_union<_js_jts_dIdentifier, js_undefined> name = js_undefined(), js_union<_js_jts_dNamedImports, _js_jts_dNamespaceImport, js_undefined> namedBindings = js_undefined()) noexcept;
			static auto createImportDeclaration(js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dImportClause, js_undefined> importClause, _js_jts_dExpression moduleSpecifier) noexcept;
			static auto createImportEqualsDeclaration(js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dIdentifier, js_string> name, js_union<_js_jts_dExternalModuleReference, _js_jts_dIdentifier, _js_jts_dQualifiedName> moduleReference) noexcept;
			static auto createImportSpecifier(js_union<_js_jts_dIdentifier, js_undefined> propertyName, _js_jts_dIdentifier name) noexcept;
			static auto createImportTypeNode(_js_jts_dTypeNode argument, js_union<_js_jts_dIdentifier, _js_jts_dQualifiedName, js_undefined> qualifier = js_undefined(), js_union<js::ReadonlyArray<_js_jts_dTypeNode>, js_undefined> typeArguments = js_undefined(), js_union<bool /*false*/, js_undefined> isTypeOf = js_undefined()) noexcept;
			static auto createIndexSignature(js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, _js_jts_dTypeNode type) noexcept;
			static auto createIndexedAccessTypeNode(_js_jts_dTypeNode objectType, _js_jts_dTypeNode indexType) noexcept;
			static auto createInferTypeNode(_js_jts_dTypeParameterDeclaration typeParameter) noexcept;
			static auto createInputFiles(js_function<js_union<js_string, js_undefined>(js_string)> readFileText, js_string javascriptPath, js_union<js_string, js_undefined> javascriptMapPath, js_string declarationPath, js_union<js_string, js_undefined> declarationMapPath = js_undefined(), js_union<js_string, js_undefined> buildInfoPath = js_undefined()) noexcept;
			static auto createInputFiles(js_string javascriptText, js_string declarationText) noexcept;
			static auto createInputFiles(js_string javascriptText, js_string declarationText, js_union<js_string, js_undefined> javascriptMapPath = js_undefined(), js_union<js_string, js_undefined> javascriptMapText = js_undefined(), js_union<js_string, js_undefined> declarationMapPath = js_undefined(), js_union<js_string, js_undefined> declarationMapText = js_undefined()) noexcept;
			static auto createInterfaceDeclaration(js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dIdentifier, js_string> name, js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, js_union<js::ReadonlyArray<_js_jts_dHeritageClause>, js_undefined> heritageClauses, js::ReadonlyArray<_js_jts_dTypeElement> members) noexcept;
			static auto createIntersectionTypeNode(js::ReadonlyArray<_js_jts_dTypeNode> types) noexcept;
			static auto createJsxAttribute(_js_jts_dIdentifier name, js_union<_js_jts_dJsxExpression, _js_jts_dStringLiteral> initializer) noexcept;
			static auto createJsxAttributes(js::ReadonlyArray<js_union<_js_jts_dJsxAttribute, _js_jts_dJsxSpreadAttribute>> properties) noexcept;
			static auto createJsxClosingElement(js_union<_js_jts_dIdentifier, _js_jts_dJsxTagNamePropertyAccess, _js_jts_dThisExpression> tagName) noexcept;
			static auto createJsxElement(_js_jts_dJsxOpeningElement openingElement, js::ReadonlyArray<js_union<_js_jts_dJsxElement, _js_jts_dJsxExpression, _js_jts_dJsxFragment, _js_jts_dJsxSelfClosingElement, _js_jts_dJsxText>> children, _js_jts_dJsxClosingElement closingElement) noexcept;
			static auto createJsxExpression(js_unknown /*flags=1048576: Token<SyntaxKind.DotDotDotToken> | undefined ()*/ dotDotDotToken = js_undefined(), js_union<_js_jts_dExpression, js_undefined> expression = js_undefined()) noexcept;
			static auto createJsxFragment(_js_jts_dJsxOpeningFragment openingFragment, js::ReadonlyArray<js_union<_js_jts_dJsxElement, _js_jts_dJsxExpression, _js_jts_dJsxFragment, _js_jts_dJsxSelfClosingElement, _js_jts_dJsxText>> children, _js_jts_dJsxClosingFragment closingFragment) noexcept;
			static auto createJsxJsxClosingFragment() noexcept;
			static auto createJsxOpeningElement(js_union<_js_jts_dIdentifier, _js_jts_dJsxTagNamePropertyAccess, _js_jts_dThisExpression> tagName, js_union<js::ReadonlyArray<_js_jts_dTypeNode>, js_undefined> typeArguments, _js_jts_dJsxAttributes attributes) noexcept;
			static auto createJsxOpeningFragment() noexcept;
			static auto createJsxSelfClosingElement(js_union<_js_jts_dIdentifier, _js_jts_dJsxTagNamePropertyAccess, _js_jts_dThisExpression> tagName, js_union<js::ReadonlyArray<_js_jts_dTypeNode>, js_undefined> typeArguments, _js_jts_dJsxAttributes attributes) noexcept;
			static auto createJsxSpreadAttribute(_js_jts_dExpression expression) noexcept;
			static auto createJsxText(js_string text, js_union<bool /*false*/, js_undefined> containsOnlyTriviaWhiteSpaces = js_undefined()) noexcept;
			static auto createKeywordTypeNode(_js_jts_dSyntaxKind /*SyntaxKind.NullKeyword*/ kind) noexcept;
			static auto createLabel(js_union<_js_jts_dIdentifier, js_string> label, _js_jts_dStatement statement) noexcept;
			static auto createLanguageService(_js_jts_dLanguageServiceHost host, js_union<_js_jts_dDocumentRegistry, js_undefined> documentRegistry = js_undefined(), js_union<bool /*false*/, js_undefined> syntaxOnly = js_undefined()) noexcept;
			static auto createLanguageServiceSourceFile(js_string fileName, _js_jts_dIScriptSnapshot scriptSnapshot, _js_jts_dScriptTarget /*ScriptTarget.ES3*/ scriptTarget, js_string version, bool /*false*/ setNodeParents, js_union<_js_jts_dScriptKind /*ScriptKind.TS*/, js_undefined> scriptKind = js_undefined()) noexcept;
			static auto createLessThan(_js_jts_dExpression left, _js_jts_dExpression right) noexcept;
			static auto createLiteral(bool /*false*/ value) noexcept;
			static auto createLiteral(js_union<_js_jts_dIdentifier, _js_jts_dNoSubstitutionTemplateLiteral, _js_jts_dNumericLiteral, _js_jts_dStringLiteral, js_string> value) noexcept;
			static auto createLiteral(js_union<_js_jts_dPseudoBigInt, bool /*false*/, double, js_string> value) noexcept;
			static auto createLiteral(js_union<_js_jts_dPseudoBigInt, double> value) noexcept;
			static auto createLiteralTypeNode(js_union<_js_jts_dBooleanLiteral, _js_jts_dLiteralExpression, _js_jts_dPrefixUnaryExpression> literal) noexcept;
			static auto createLogicalAnd(_js_jts_dExpression left, _js_jts_dExpression right) noexcept;
			static auto createLogicalNot(_js_jts_dExpression operand) noexcept;
			static auto createLogicalOr(_js_jts_dExpression left, _js_jts_dExpression right) noexcept;
			static auto createLoopVariable() noexcept;
			static auto createMappedTypeNode(js_unknown /*flags=1048576: Token<SyntaxKind.ReadonlyKeyword> | Token<SyntaxKind.PlusToken> | Token<SyntaxKind.MinusToken> | undefined ()*/ readonlyToken, _js_jts_dTypeParameterDeclaration typeParameter, js_unknown /*flags=1048576: Token<SyntaxKind.QuestionToken> | Token<SyntaxKind.PlusToken> | Token<SyntaxKind.MinusToken> | undefined ()*/ questionToken = js_undefined(), js_union<_js_jts_dTypeNode, js_undefined> type = js_undefined()) noexcept;
			static auto createMetaProperty(_js_jts_dSyntaxKind /*SyntaxKind.ImportKeyword*/ keywordToken, _js_jts_dIdentifier name) noexcept;
			static auto createMethod(js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_unknown /*flags=1048576: Token<SyntaxKind.AsteriskToken> | undefined ()*/ asteriskToken, js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral, js_string> name, js_unknown /*flags=1048576: Token<SyntaxKind.QuestionToken> | undefined ()*/ questionToken, js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, js_union<_js_jts_dTypeNode, js_undefined> type = js_undefined(), js_union<_js_jts_dBlock, js_undefined> body = js_undefined()) noexcept;
			static auto createMethodSignature(js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, js_union<_js_jts_dTypeNode, js_undefined> type, js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral, js_string> name, js_unknown /*flags=1048576: Token<SyntaxKind.QuestionToken> | undefined ()*/ questionToken = js_undefined()) noexcept;
			static auto createModifier(js_unknown /*flags=262144: T ()*/ kind) noexcept;
			static auto createModifiersFromModifierFlags(_js_jts_dModifierFlags /*ModifierFlags.None*/ flags) noexcept;
			static auto createModuleBlock(js::ReadonlyArray<_js_jts_dStatement> statements) noexcept;
			static auto createModuleDeclaration(js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dIdentifier, _js_jts_dStringLiteral> name, js_union<_js_jts_dIdentifier, _js_jts_dJSDocNamespaceDeclaration, _js_jts_dModuleBlock, _js_jts_dNamespaceDeclaration, js_undefined> body = js_undefined(), js_union<_js_jts_dNodeFlags /*NodeFlags.YieldContext*/, js_undefined> flags = js_undefined()) noexcept;
			static auto createModuleResolutionCache(js_string currentDirectory, js_function<js_string(js_string)> getCanonicalFileName, js_union<_js_jts_dCompilerOptions, js_undefined> options = js_undefined()) noexcept;
			static auto createNamedExports(js::ReadonlyArray<_js_jts_dExportSpecifier> elements) noexcept;
			static auto createNamedImports(js::ReadonlyArray<_js_jts_dImportSpecifier> elements) noexcept;
			static auto createNamespaceExportDeclaration(js_union<_js_jts_dIdentifier, js_string> name) noexcept;
			static auto createNamespaceImport(_js_jts_dIdentifier name) noexcept;
			static auto createNew(_js_jts_dExpression expression, js_union<js::ReadonlyArray<_js_jts_dTypeNode>, js_undefined> typeArguments = js_undefined(), js_union<js::ReadonlyArray<_js_jts_dExpression>, js_undefined> argumentsArray = js_undefined()) noexcept;
			static auto createNoSubstitutionTemplateLiteral(js_string text) noexcept;
			static auto createNode(_js_jts_dSyntaxKind /*SyntaxKind.Unknown*/ kind, js_union<double, js_undefined> pos = js_undefined(), js_union<double, js_undefined> end = js_undefined()) noexcept;
			static auto createNodeArray(js_union<js::ReadonlyArray<js_unknown /*flags=262144: T ()*/>, js_undefined> elements = js_undefined(), js_union<bool /*false*/, js_undefined> hasTrailingComma = js_undefined()) noexcept;
			static auto createNonNullExpression(_js_jts_dExpression expression) noexcept;
			static auto createNotEmittedStatement(_js_jts_dNode original) noexcept;
			static auto createNull() noexcept;
			static auto createNumericLiteral(js_string value, js_union<_js_jts_dTokenFlags /*TokenFlags.Octal*/, js_undefined> numericLiteralFlags = js_undefined()) noexcept;
			static auto createObjectBindingPattern(js::ReadonlyArray<_js_jts_dBindingElement> elements) noexcept;
			static auto createObjectLiteral(js_union<js::ReadonlyArray<js_union<_js_jts_dGetAccessorDeclaration, _js_jts_dMethodDeclaration, _js_jts_dPropertyAssignment, _js_jts_dSetAccessorDeclaration, _js_jts_dShorthandPropertyAssignment, _js_jts_dSpreadAssignment>>, js_undefined> properties = js_undefined(), js_union<bool /*false*/, js_undefined> multiLine = js_undefined()) noexcept;
			static auto createOmittedExpression() noexcept;
			static auto createOptimisticUniqueName(js_string text) noexcept;
			static auto createOptionalTypeNode(_js_jts_dTypeNode type) noexcept;
			static auto createParameter(js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_unknown /*flags=1048576: Token<SyntaxKind.DotDotDotToken> | undefined ()*/ dotDotDotToken, js_union<_js_jts_dArrayBindingPattern, _js_jts_dIdentifier, _js_jts_dObjectBindingPattern, js_string> name, js_unknown /*flags=1048576: Token<SyntaxKind.QuestionToken> | undefined ()*/ questionToken = js_undefined(), js_union<_js_jts_dTypeNode, js_undefined> type = js_undefined(), js_union<_js_jts_dExpression, js_undefined> initializer = js_undefined()) noexcept;
			static auto createParen(_js_jts_dExpression expression) noexcept;
			static auto createParenthesizedType(_js_jts_dTypeNode type) noexcept;
			static auto createPartiallyEmittedExpression(_js_jts_dExpression expression, js_union<_js_jts_dNode, js_undefined> original = js_undefined()) noexcept;
			static auto createPostfix(_js_jts_dExpression operand, _js_jts_dSyntaxKind /*SyntaxKind.PlusPlusToken*/ operator_) noexcept;
			static auto createPostfixIncrement(_js_jts_dExpression operand) noexcept;
			static auto createPrefix(_js_jts_dSyntaxKind /*SyntaxKind.PlusToken*/ operator_, _js_jts_dExpression operand) noexcept;
			static auto createPrinter(js_union<_js_jts_dPrinterOptions, js_undefined> printerOptions = js_undefined(), js_union<_js_jts_dPrintHandlers, js_undefined> handlers = js_undefined()) noexcept;
			static auto createProgram(_js_jts_dCreateProgramOptions createProgramOptions) noexcept;
			static auto createProgram(js::ReadonlyArray<js_string> rootNames, _js_jts_dCompilerOptions options, js_union<_js_jts_dCompilerHost, js_undefined> host = js_undefined(), js_union<_js_jts_dProgram, js_undefined> oldProgram = js_undefined(), js_union<js::ReadonlyArray<_js_jts_dDiagnostic>, js_undefined> configFileParsingDiagnostics = js_undefined()) noexcept;
			static auto createProperty(js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral, js_string> name, js_unknown /*flags=1048576: Token<SyntaxKind.QuestionToken> | Token<SyntaxKind.ExclamationToken> | undefined ()*/ questionOrExclamationToken = js_undefined(), js_union<_js_jts_dTypeNode, js_undefined> type = js_undefined(), js_union<_js_jts_dExpression, js_undefined> initializer = js_undefined()) noexcept;
			static auto createPropertyAccess(_js_jts_dExpression expression, js_union<_js_jts_dIdentifier, js_string> name) noexcept;
			static auto createPropertyAssignment(js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral, js_string> name, _js_jts_dExpression initializer) noexcept;
			static auto createPropertySignature(js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral, js_string> name, js_unknown /*flags=1048576: Token<SyntaxKind.QuestionToken> | undefined ()*/ questionToken = js_undefined(), js_union<_js_jts_dTypeNode, js_undefined> type = js_undefined(), js_union<_js_jts_dExpression, js_undefined> initializer = js_undefined()) noexcept;
			static auto createQualifiedName(js_union<_js_jts_dIdentifier, _js_jts_dQualifiedName> left, js_union<_js_jts_dIdentifier, js_string> right) noexcept;
			static auto createRegularExpressionLiteral(js_string text) noexcept;
			static auto createRestTypeNode(_js_jts_dTypeNode type) noexcept;
			static auto createReturn(js_union<_js_jts_dExpression, js_undefined> expression = js_undefined()) noexcept;
			static auto createScanner(_js_jts_dScriptTarget /*ScriptTarget.ES3*/ languageVersion, bool /*false*/ skipTrivia, js_union<_js_jts_dLanguageVariant /*LanguageVariant.Standard*/, js_undefined> languageVariant = js_undefined(), js_union<js_string, js_undefined> textInitial = js_undefined(), js_union<js_function<void(_js_jts_dDiagnosticMessage, double)>, js_undefined> onError = js_undefined(), js_union<double, js_undefined> start = js_undefined(), js_union<double, js_undefined> length = js_undefined()) noexcept;
			static auto createSemanticDiagnosticsBuilderProgram(_js_jts_dProgram newProgram, _js_jts_dBuilderProgramHost host, js_union<_js_jts_dSemanticDiagnosticsBuilderProgram, js_undefined> oldProgram = js_undefined(), js_union<js::ReadonlyArray<_js_jts_dDiagnostic>, js_undefined> configFileParsingDiagnostics = js_undefined()) noexcept;
			static auto createSemanticDiagnosticsBuilderProgram(js_union<js::ReadonlyArray<js_string>, js_undefined> rootNames = js_undefined(), js_union<_js_jts_dCompilerOptions, js_undefined> options = js_undefined(), js_union<_js_jts_dCompilerHost, js_undefined> host = js_undefined(), js_union<_js_jts_dSemanticDiagnosticsBuilderProgram, js_undefined> oldProgram = js_undefined(), js_union<js::ReadonlyArray<_js_jts_dDiagnostic>, js_undefined> configFileParsingDiagnostics = js_undefined(), js_union<js::ReadonlyArray<_js_jts_dProjectReference>, js_undefined> projectReferences = js_undefined()) noexcept;
			static auto createSemicolonClassElement() noexcept;
			static auto createSetAccessor(js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral, js_string> name, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, js_union<_js_jts_dBlock, js_undefined> body = js_undefined()) noexcept;
			static auto createShorthandPropertyAssignment(js_union<_js_jts_dIdentifier, js_string> name, js_union<_js_jts_dExpression, js_undefined> objectAssignmentInitializer = js_undefined()) noexcept;
			static auto createSourceFile(js_string fileName, js_string sourceText, _js_jts_dScriptTarget /*ScriptTarget.ES3*/ languageVersion, js_union<bool /*false*/, js_undefined> setParentNodes = js_undefined(), js_union<_js_jts_dScriptKind /*ScriptKind.TS*/, js_undefined> scriptKind = js_undefined()) noexcept;
			static auto createSourceMapSource(js_string fileName, js_string text, js_union<js_function<double(double)>, js_undefined> skipTrivia = js_undefined()) noexcept;
			static auto createSpread(_js_jts_dExpression expression) noexcept;
			static auto createSpreadAssignment(_js_jts_dExpression expression) noexcept;
			static auto createStrictEquality(_js_jts_dExpression left, _js_jts_dExpression right) noexcept;
			static auto createStrictInequality(_js_jts_dExpression left, _js_jts_dExpression right) noexcept;
			static auto createStringLiteral(js_string text) noexcept;
			static auto createSubtract(_js_jts_dExpression left, _js_jts_dExpression right) noexcept;
			static auto createSuper() noexcept;
			static auto createSwitch(_js_jts_dExpression expression, _js_jts_dCaseBlock caseBlock) noexcept;
			static auto createTaggedTemplate(_js_jts_dExpression tag, js_union<_js_jts_dNoSubstitutionTemplateLiteral, _js_jts_dTemplateExpression> template_) noexcept;
			static auto createTaggedTemplate(_js_jts_dExpression tag, js_union<js::ReadonlyArray<_js_jts_dTypeNode>, js_undefined> typeArguments, js_union<_js_jts_dNoSubstitutionTemplateLiteral, _js_jts_dTemplateExpression> template_) noexcept;
			static auto createTempVariable(js_union<js_function<void(_js_jts_dIdentifier)>, js_undefined> recordTempVariable = js_undefined()) noexcept;
			static auto createTemplateExpression(_js_jts_dTemplateHead head, js::ReadonlyArray<_js_jts_dTemplateSpan> templateSpans) noexcept;
			static auto createTemplateHead(js_string text) noexcept;
			static auto createTemplateMiddle(js_string text) noexcept;
			static auto createTemplateSpan(_js_jts_dExpression expression, js_union<_js_jts_dTemplateMiddle, _js_jts_dTemplateTail> literal) noexcept;
			static auto createTemplateTail(js_string text) noexcept;
			static auto createTextChangeRange(_js_jts_dTextSpan span, double newLength) noexcept;
			static auto createTextSpan(double start, double length) noexcept;
			static auto createTextSpanFromBounds(double start, double end) noexcept;
			static auto createThis() noexcept;
			static auto createThisTypeNode() noexcept;
			static auto createThrow(_js_jts_dExpression expression) noexcept;
			static auto createToken(js_unknown /*flags=262144: TKind ()*/ token) noexcept;
			static auto createTrue() noexcept;
			static auto createTry(_js_jts_dBlock tryBlock, js_union<_js_jts_dCatchClause, js_undefined> catchClause = js_undefined(), js_union<_js_jts_dBlock, js_undefined> finallyBlock = js_undefined()) noexcept;
			static auto createTupleTypeNode(js::ReadonlyArray<_js_jts_dTypeNode> elementTypes) noexcept;
			static auto createTypeAliasDeclaration(js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dIdentifier, js_string> name, js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, _js_jts_dTypeNode type) noexcept;
			static auto createTypeAssertion(_js_jts_dTypeNode type, _js_jts_dExpression expression) noexcept;
			static auto createTypeLiteralNode(js_union<js::ReadonlyArray<_js_jts_dTypeElement>, js_undefined> members = js_undefined()) noexcept;
			static auto createTypeOf(_js_jts_dExpression expression) noexcept;
			static auto createTypeOperatorNode(_js_jts_dSyntaxKind /*SyntaxKind.KeyOfKeyword*/ operator_, _js_jts_dTypeNode type) noexcept;
			static auto createTypeOperatorNode(_js_jts_dTypeNode type) noexcept;
			static auto createTypeParameterDeclaration(js_union<_js_jts_dIdentifier, js_string> name, js_union<_js_jts_dTypeNode, js_undefined> constraint = js_undefined(), js_union<_js_jts_dTypeNode, js_undefined> defaultType = js_undefined()) noexcept;
			static auto createTypePredicateNode(js_union<_js_jts_dIdentifier, _js_jts_dThisTypeNode, js_string> parameterName, _js_jts_dTypeNode type) noexcept;
			static auto createTypeQueryNode(js_union<_js_jts_dIdentifier, _js_jts_dQualifiedName> exprName) noexcept;
			static auto createTypeReferenceNode(js_union<_js_jts_dIdentifier, _js_jts_dQualifiedName, js_string> typeName, js_union<js::ReadonlyArray<_js_jts_dTypeNode>, js_undefined> typeArguments = js_undefined()) noexcept;
			static auto createUnionOrIntersectionTypeNode(_js_jts_dSyntaxKind /*SyntaxKind.UnionType*/ kind, js::ReadonlyArray<_js_jts_dTypeNode> types) noexcept;
			static auto createUnionTypeNode(js::ReadonlyArray<_js_jts_dTypeNode> types) noexcept;
			static auto createUniqueName(js_string text) noexcept;
			static auto createUnparsedSourceFile(_js_jts_dInputFiles inputFile, js_string /*"js"*/ type, js_union<bool /*false*/, js_undefined> stripInternal = js_undefined()) noexcept;
			static auto createUnparsedSourceFile(js_string text) noexcept;
			static auto createUnparsedSourceFile(js_string text, js_union<js_string, js_undefined> mapPath = js_undefined(), js_union<js_string, js_undefined> map = js_undefined()) noexcept;
			static auto createVariableDeclaration(js_union<_js_jts_dArrayBindingPattern, _js_jts_dIdentifier, _js_jts_dObjectBindingPattern, js_string> name, js_union<_js_jts_dTypeNode, js_undefined> type = js_undefined(), js_union<_js_jts_dExpression, js_undefined> initializer = js_undefined()) noexcept;
			static auto createVariableDeclarationList(js::ReadonlyArray<_js_jts_dVariableDeclaration> declarations, js_union<_js_jts_dNodeFlags /*NodeFlags.YieldContext*/, js_undefined> flags = js_undefined()) noexcept;
			static auto createVariableStatement(js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dVariableDeclarationList, js::ReadonlyArray<_js_jts_dVariableDeclaration>> declarationList) noexcept;
			static auto createVoid(_js_jts_dExpression expression) noexcept;
			static auto createVoidZero() noexcept;
			static auto createWatchCompilerHost(js::Array<js_string> rootFiles, _js_jts_dCompilerOptions options, _js_jts_dSystem system, js_unknown /*flags=1048576: CreateProgram<T> | undefined ()*/ createProgram = js_undefined(), js_union<js_function<void(_js_jts_dDiagnostic)>, js_undefined> reportDiagnostic = js_undefined(), js_union<js_function<void(_js_jts_dDiagnostic, js_string, _js_jts_dCompilerOptions)>, js_undefined> reportWatchStatus = js_undefined(), js_union<js::ReadonlyArray<_js_jts_dProjectReference>, js_undefined> projectReferences = js_undefined()) noexcept;
			static auto createWatchCompilerHost(js_string configFileName, js_union<_js_jts_dCompilerOptions, js_undefined> optionsToExtend, _js_jts_dSystem system, js_unknown /*flags=1048576: CreateProgram<T> | undefined ()*/ createProgram = js_undefined(), js_union<js_function<void(_js_jts_dDiagnostic)>, js_undefined> reportDiagnostic = js_undefined(), js_union<js_function<void(_js_jts_dDiagnostic, js_string, _js_jts_dCompilerOptions)>, js_undefined> reportWatchStatus = js_undefined()) noexcept;
			static auto createWatchProgram(js_unknown /*flags=524288: WatchCompilerHostOfFilesAndCompilerOptions<T> (TypeReference=ts.WatchCompilerHostOfFilesAndCompilerOptions)*/ host) noexcept;
			static auto createWhile(_js_jts_dExpression expression, _js_jts_dStatement statement) noexcept;
			static auto createWith(_js_jts_dExpression expression, _js_jts_dStatement statement) noexcept;
			static auto createYield(js_union<_js_jts_dExpression, js_undefined> expression = js_undefined()) noexcept;
			static auto createYield(js_unknown /*flags=1048576: Token<SyntaxKind.AsteriskToken> | undefined ()*/ asteriskToken, _js_jts_dExpression expression) noexcept;
			static auto decodedTextSpanIntersectsWith(double start1, double length1, double start2, double length2) noexcept;
			static auto displayPartsToString(js_union<js::Array<_js_jts_dSymbolDisplayPart>, js_undefined> displayParts = js_undefined()) noexcept;
			static auto disposeEmitNodes(_js_jts_dSourceFile sourceFile) noexcept;
			static auto escapeLeadingUnderscores(js_string identifier) noexcept;
			static auto findConfigFile(js_string searchPath, js_function<bool /*false*/(js_string)> fileExists, js_union<js_string, js_undefined> configName = js_undefined()) noexcept;
			static auto flattenDiagnosticMessageText(js_union<_js_jts_dDiagnosticMessageChain, js_string, js_undefined> messageText, js_string newLine) noexcept;
			static auto forEachChild(_js_jts_dNode node, js_function<js_unknown /*flags=1048576: T | undefined ()*/(_js_jts_dNode)> cbNode, js_union<js_function<js_unknown /*flags=1048576: T | undefined ()*/(js_unknown /*flags=524288: NodeArray<Node> (TypeReference=ts.NodeArray)*/)>, js_undefined> cbNodes = js_undefined()) noexcept;
			static auto forEachLeadingCommentRange(js_string text, double pos, js_function<js_unknown /*flags=262144: U ()*/(double, double, _js_jts_dSyntaxKind /*SyntaxKind.SingleLineCommentTrivia*/, bool /*false*/, js_unknown /*flags=262144: T ()*/)> cb, js_unknown /*flags=262144: T ()*/ state) noexcept;
			static auto forEachLeadingCommentRange(js_string text, double pos, js_function<js_unknown /*flags=262144: U ()*/(double, double, _js_jts_dSyntaxKind /*SyntaxKind.SingleLineCommentTrivia*/, bool /*false*/)> cb) noexcept;
			static auto forEachTrailingCommentRange(js_string text, double pos, js_function<js_unknown /*flags=262144: U ()*/(double, double, _js_jts_dSyntaxKind /*SyntaxKind.SingleLineCommentTrivia*/, bool /*false*/, js_unknown /*flags=262144: T ()*/)> cb, js_unknown /*flags=262144: T ()*/ state) noexcept;
			static auto forEachTrailingCommentRange(js_string text, double pos, js_function<js_unknown /*flags=262144: U ()*/(double, double, _js_jts_dSyntaxKind /*SyntaxKind.SingleLineCommentTrivia*/, bool /*false*/)> cb) noexcept;
			static auto formatDiagnostic(_js_jts_dDiagnostic diagnostic, _js_jts_dFormatDiagnosticsHost host) noexcept;
			static auto formatDiagnostics(js::ReadonlyArray<_js_jts_dDiagnostic> diagnostics, _js_jts_dFormatDiagnosticsHost host) noexcept;
			static auto formatDiagnosticsWithColorAndContext(js::ReadonlyArray<_js_jts_dDiagnostic> diagnostics, _js_jts_dFormatDiagnosticsHost host) noexcept;
			static auto getAllJSDocTagsOfKind(_js_jts_dNode node, _js_jts_dSyntaxKind /*SyntaxKind.Unknown*/ kind) noexcept;
			static auto getAutomaticTypeDirectiveNames(_js_jts_dCompilerOptions options, _js_jts_dModuleResolutionHost host) noexcept;
			static auto getCombinedModifierFlags(_js_jts_dDeclaration node) noexcept;
			static auto getCombinedNodeFlags(_js_jts_dNode node) noexcept;
			static auto getCommentRange(_js_jts_dNode node) noexcept;
			static auto getConfigFileParsingDiagnostics(_js_jts_dParsedCommandLine configFileParseResult) noexcept;
			static auto getConstantValue(js_union<_js_jts_dElementAccessExpression, _js_jts_dPropertyAccessExpression> node) noexcept;
			static auto getDefaultCompilerOptions() noexcept;
			static auto getDefaultFormatCodeSettings(js_union<js_string, js_undefined> newLineCharacter = js_undefined()) noexcept;
			static auto getDefaultLibFileName(_js_jts_dCompilerOptions options) noexcept;
			static auto getDefaultLibFilePath(_js_jts_dCompilerOptions options) noexcept;
			static auto getEffectiveConstraintOfTypeParameter(_js_jts_dTypeParameterDeclaration node) noexcept;
			static auto getEffectiveTypeParameterDeclarations(js_union<_js_jts_dArrowFunction, _js_jts_dCallSignatureDeclaration, _js_jts_dClassDeclaration, _js_jts_dClassExpression, _js_jts_dConstructSignatureDeclaration, _js_jts_dConstructorDeclaration, _js_jts_dConstructorTypeNode, _js_jts_dFunctionDeclaration, _js_jts_dFunctionExpression, _js_jts_dFunctionTypeNode, _js_jts_dGetAccessorDeclaration, _js_jts_dIndexSignatureDeclaration, _js_jts_dInterfaceDeclaration, _js_jts_dJSDocCallbackTag, _js_jts_dJSDocFunctionType, _js_jts_dJSDocSignature, _js_jts_dJSDocTemplateTag, _js_jts_dJSDocTypedefTag, _js_jts_dMethodDeclaration, _js_jts_dMethodSignature, _js_jts_dSetAccessorDeclaration, _js_jts_dTypeAliasDeclaration> node) noexcept;
			static auto getEffectiveTypeRoots(_js_jts_dCompilerOptions options, _js_jts_dGetEffectiveTypeRootsHost host) noexcept;
			static auto getEmitHelpers(_js_jts_dNode node) noexcept;
			static auto getGeneratedNameForNode(js_union<_js_jts_dNode, js_undefined> node = js_undefined()) noexcept;
			static auto getJSDocAugmentsTag(_js_jts_dNode node) noexcept;
			static auto getJSDocClassTag(_js_jts_dNode node) noexcept;
			static auto getJSDocEnumTag(_js_jts_dNode node) noexcept;
			static auto getJSDocParameterTags(_js_jts_dParameterDeclaration param) noexcept;
			static auto getJSDocReturnTag(_js_jts_dNode node) noexcept;
			static auto getJSDocReturnType(_js_jts_dNode node) noexcept;
			static auto getJSDocTags(_js_jts_dNode node) noexcept;
			static auto getJSDocTemplateTag(_js_jts_dNode node) noexcept;
			static auto getJSDocThisTag(_js_jts_dNode node) noexcept;
			static auto getJSDocType(_js_jts_dNode node) noexcept;
			static auto getJSDocTypeParameterTags(_js_jts_dTypeParameterDeclaration param) noexcept;
			static auto getJSDocTypeTag(_js_jts_dNode node) noexcept;
			static auto getLeadingCommentRanges(js_string text, double pos) noexcept;
			static auto getLineAndCharacterOfPosition(_js_jts_dSourceFileLike sourceFile, double position) noexcept;
			static auto getMutableClone(js_unknown /*flags=262144: T ()*/ node) noexcept;
			static auto getNameOfDeclaration(js_union<_js_jts_dDeclaration, _js_jts_dExpression> declaration) noexcept;
			static auto getNameOfJSDocTypedef(_js_jts_dJSDocTypedefTag declaration) noexcept;
			static auto getNodeMajorVersion() noexcept;
			static auto getOriginalNode(_js_jts_dNode node) noexcept;
			static auto getOriginalNode(_js_jts_dNode node, js_function<bool /*false*/(_js_jts_dNode)> nodeTest) noexcept;
			static auto getOriginalNode(js_union<_js_jts_dNode, js_undefined> node = js_undefined()) noexcept;
			static auto getOriginalNode(js_union<_js_jts_dNode, js_undefined> node, js_function<bool /*false*/(js_union<_js_jts_dNode, js_undefined>)> nodeTest) noexcept;
			static auto getParseTreeNode(_js_jts_dNode node) noexcept;
			static auto getParseTreeNode(js_union<_js_jts_dNode, js_undefined> node = js_undefined(), js_union<js_function<bool /*false*/(_js_jts_dNode)>, js_undefined> nodeTest = js_undefined()) noexcept;
			static auto getParsedCommandLineOfConfigFile(js_string configFileName, _js_jts_dCompilerOptions optionsToExtend, _js_jts_dParseConfigFileHost host, js_unknown /*flags=1048576: Map<ExtendedConfigCacheEntry> | undefined ()*/ extendedConfigCache = js_undefined()) noexcept;
			static auto getPositionOfLineAndCharacter(_js_jts_dSourceFileLike sourceFile, double line, double character) noexcept;
			static auto getPreEmitDiagnostics(_js_jts_dProgram program, js_union<_js_jts_dSourceFile, js_undefined> sourceFile = js_undefined(), js_union<_js_jts_dCancellationToken, js_undefined> cancellationToken = js_undefined()) noexcept;
			static auto getShebang(js_string text) noexcept;
			static auto getSourceMapRange(_js_jts_dNode node) noexcept;
			static auto getSupportedCodeFixes() noexcept;
			static auto getSyntheticLeadingComments(_js_jts_dNode node) noexcept;
			static auto getSyntheticTrailingComments(_js_jts_dNode node) noexcept;
			static auto getTokenSourceMapRange(_js_jts_dNode node, _js_jts_dSyntaxKind /*SyntaxKind.Unknown*/ token) noexcept;
			static auto getTrailingCommentRanges(js_string text, double pos) noexcept;
			static auto getTypeParameterOwner(_js_jts_dDeclaration d) noexcept;
			static auto hasJSDocParameterTags(js_union<_js_jts_dArrowFunction, _js_jts_dCallSignatureDeclaration, _js_jts_dConstructSignatureDeclaration, _js_jts_dConstructorDeclaration, _js_jts_dConstructorTypeNode, _js_jts_dFunctionDeclaration, _js_jts_dFunctionExpression, _js_jts_dFunctionTypeNode, _js_jts_dGetAccessorDeclaration, _js_jts_dIndexSignatureDeclaration, _js_jts_dJSDocFunctionType, _js_jts_dMethodDeclaration, _js_jts_dMethodSignature, _js_jts_dSetAccessorDeclaration> node) noexcept;
			static auto idText(_js_jts_dIdentifier identifier) noexcept;
			static auto isAccessor(_js_jts_dNode node) noexcept;
			static auto isArrayBindingPattern(_js_jts_dNode node) noexcept;
			static auto isArrayLiteralExpression(_js_jts_dNode node) noexcept;
			static auto isArrayTypeNode(_js_jts_dNode node) noexcept;
			static auto isArrowFunction(_js_jts_dNode node) noexcept;
			static auto isAsExpression(_js_jts_dNode node) noexcept;
			static auto isAssertionExpression(_js_jts_dNode node) noexcept;
			static auto isAwaitExpression(_js_jts_dNode node) noexcept;
			static auto isBigIntLiteral(_js_jts_dNode node) noexcept;
			static auto isBinaryExpression(_js_jts_dNode node) noexcept;
			static auto isBindingElement(_js_jts_dNode node) noexcept;
			static auto isBindingName(_js_jts_dNode node) noexcept;
			static auto isBlock(_js_jts_dNode node) noexcept;
			static auto isBreakOrContinueStatement(_js_jts_dNode node) noexcept;
			static auto isBreakStatement(_js_jts_dNode node) noexcept;
			static auto isBundle(_js_jts_dNode node) noexcept;
			static auto isCallExpression(_js_jts_dNode node) noexcept;
			static auto isCallLikeExpression(_js_jts_dNode node) noexcept;
			static auto isCallOrNewExpression(_js_jts_dNode node) noexcept;
			static auto isCallSignatureDeclaration(_js_jts_dNode node) noexcept;
			static auto isCaseBlock(_js_jts_dNode node) noexcept;
			static auto isCaseClause(_js_jts_dNode node) noexcept;
			static auto isCaseOrDefaultClause(_js_jts_dNode node) noexcept;
			static auto isCatchClause(_js_jts_dNode node) noexcept;
			static auto isClassDeclaration(_js_jts_dNode node) noexcept;
			static auto isClassElement(_js_jts_dNode node) noexcept;
			static auto isClassExpression(_js_jts_dNode node) noexcept;
			static auto isClassLike(_js_jts_dNode node) noexcept;
			static auto isClassOrTypeElement(_js_jts_dNode node) noexcept;
			static auto isComputedPropertyName(_js_jts_dNode node) noexcept;
			static auto isConditionalExpression(_js_jts_dNode node) noexcept;
			static auto isConditionalTypeNode(_js_jts_dNode node) noexcept;
			static auto isConstTypeReference(_js_jts_dNode node) noexcept;
			static auto isConstructSignatureDeclaration(_js_jts_dNode node) noexcept;
			static auto isConstructorDeclaration(_js_jts_dNode node) noexcept;
			static auto isConstructorTypeNode(_js_jts_dNode node) noexcept;
			static auto isContinueStatement(_js_jts_dNode node) noexcept;
			static auto isDebuggerStatement(_js_jts_dNode node) noexcept;
			static auto isDecorator(_js_jts_dNode node) noexcept;
			static auto isDefaultClause(_js_jts_dNode node) noexcept;
			static auto isDeleteExpression(_js_jts_dNode node) noexcept;
			static auto isDoStatement(_js_jts_dNode node) noexcept;
			static auto isElementAccessExpression(_js_jts_dNode node) noexcept;
			static auto isEmptyBindingElement(_js_jts_dBindingElement node) noexcept;
			static auto isEmptyBindingPattern(js_union<_js_jts_dArrayBindingPattern, _js_jts_dIdentifier, _js_jts_dObjectBindingPattern> node) noexcept;
			static auto isEmptyStatement(_js_jts_dNode node) noexcept;
			static auto isEntityName(_js_jts_dNode node) noexcept;
			static auto isEnumDeclaration(_js_jts_dNode node) noexcept;
			static auto isEnumMember(_js_jts_dNode node) noexcept;
			static auto isExportAssignment(_js_jts_dNode node) noexcept;
			static auto isExportDeclaration(_js_jts_dNode node) noexcept;
			static auto isExportSpecifier(_js_jts_dNode node) noexcept;
			static auto isExpressionStatement(_js_jts_dNode node) noexcept;
			static auto isExpressionWithTypeArguments(_js_jts_dNode node) noexcept;
			static auto isExternalModule(_js_jts_dSourceFile file) noexcept;
			static auto isExternalModuleNameRelative(js_string moduleName) noexcept;
			static auto isExternalModuleReference(_js_jts_dNode node) noexcept;
			static auto isForInStatement(_js_jts_dNode node) noexcept;
			static auto isForOfStatement(_js_jts_dNode node) noexcept;
			static auto isForStatement(_js_jts_dNode node) noexcept;
			static auto isFunctionDeclaration(_js_jts_dNode node) noexcept;
			static auto isFunctionExpression(_js_jts_dNode node) noexcept;
			static auto isFunctionLike(_js_jts_dNode node) noexcept;
			static auto isFunctionOrConstructorTypeNode(_js_jts_dNode node) noexcept;
			static auto isFunctionTypeNode(_js_jts_dNode node) noexcept;
			static auto isGetAccessor(_js_jts_dNode node) noexcept;
			static auto isGetAccessorDeclaration(_js_jts_dNode node) noexcept;
			static auto isHeritageClause(_js_jts_dNode node) noexcept;
			static auto isIdentifier(_js_jts_dNode node) noexcept;
			static auto isIdentifierPart(double ch, js_union<_js_jts_dScriptTarget /*ScriptTarget.ES2017*/, js_undefined> languageVersion = js_undefined()) noexcept;
			static auto isIdentifierStart(double ch, js_union<_js_jts_dScriptTarget /*ScriptTarget.ES2017*/, js_undefined> languageVersion = js_undefined()) noexcept;
			static auto isIfStatement(_js_jts_dNode node) noexcept;
			static auto isImportClause(_js_jts_dNode node) noexcept;
			static auto isImportDeclaration(_js_jts_dNode node) noexcept;
			static auto isImportEqualsDeclaration(_js_jts_dNode node) noexcept;
			static auto isImportOrExportSpecifier(_js_jts_dNode node) noexcept;
			static auto isImportSpecifier(_js_jts_dNode node) noexcept;
			static auto isImportTypeNode(_js_jts_dNode node) noexcept;
			static auto isIndexSignatureDeclaration(_js_jts_dNode node) noexcept;
			static auto isIndexedAccessTypeNode(_js_jts_dNode node) noexcept;
			static auto isInferTypeNode(_js_jts_dNode node) noexcept;
			static auto isInterfaceDeclaration(_js_jts_dNode node) noexcept;
			static auto isIntersectionTypeNode(_js_jts_dNode node) noexcept;
			static auto isIterationStatement(_js_jts_dNode node, bool /*false*/ lookInLabeledStatements) noexcept;
			static auto isJSDoc(_js_jts_dNode node) noexcept;
			static auto isJSDocAllType(_js_jts_dJSDocAllType node) noexcept;
			static auto isJSDocAugmentsTag(_js_jts_dNode node) noexcept;
			static auto isJSDocCallbackTag(_js_jts_dNode node) noexcept;
			static auto isJSDocClassTag(_js_jts_dNode node) noexcept;
			static auto isJSDocCommentContainingNode(_js_jts_dNode node) noexcept;
			static auto isJSDocEnumTag(_js_jts_dNode node) noexcept;
			static auto isJSDocFunctionType(_js_jts_dNode node) noexcept;
			static auto isJSDocNonNullableType(_js_jts_dNode node) noexcept;
			static auto isJSDocNullableType(_js_jts_dNode node) noexcept;
			static auto isJSDocOptionalType(_js_jts_dNode node) noexcept;
			static auto isJSDocParameterTag(_js_jts_dNode node) noexcept;
			static auto isJSDocPropertyLikeTag(_js_jts_dNode node) noexcept;
			static auto isJSDocPropertyTag(_js_jts_dNode node) noexcept;
			static auto isJSDocReturnTag(_js_jts_dNode node) noexcept;
			static auto isJSDocSignature(_js_jts_dNode node) noexcept;
			static auto isJSDocTemplateTag(_js_jts_dNode node) noexcept;
			static auto isJSDocThisTag(_js_jts_dNode node) noexcept;
			static auto isJSDocTypeExpression(_js_jts_dNode node) noexcept;
			static auto isJSDocTypeLiteral(_js_jts_dNode node) noexcept;
			static auto isJSDocTypeTag(_js_jts_dNode node) noexcept;
			static auto isJSDocTypedefTag(_js_jts_dNode node) noexcept;
			static auto isJSDocUnknownType(_js_jts_dNode node) noexcept;
			static auto isJSDocVariadicType(_js_jts_dNode node) noexcept;
			static auto isJsxAttribute(_js_jts_dNode node) noexcept;
			static auto isJsxAttributes(_js_jts_dNode node) noexcept;
			static auto isJsxClosingElement(_js_jts_dNode node) noexcept;
			static auto isJsxClosingFragment(_js_jts_dNode node) noexcept;
			static auto isJsxElement(_js_jts_dNode node) noexcept;
			static auto isJsxExpression(_js_jts_dNode node) noexcept;
			static auto isJsxFragment(_js_jts_dNode node) noexcept;
			static auto isJsxOpeningElement(_js_jts_dNode node) noexcept;
			static auto isJsxOpeningFragment(_js_jts_dNode node) noexcept;
			static auto isJsxOpeningLikeElement(_js_jts_dNode node) noexcept;
			static auto isJsxSelfClosingElement(_js_jts_dNode node) noexcept;
			static auto isJsxSpreadAttribute(_js_jts_dNode node) noexcept;
			static auto isJsxText(_js_jts_dNode node) noexcept;
			static auto isLabeledStatement(_js_jts_dNode node) noexcept;
			static auto isLineBreak(double ch) noexcept;
			static auto isLiteralExpression(_js_jts_dNode node) noexcept;
			static auto isLiteralTypeNode(_js_jts_dNode node) noexcept;
			static auto isMappedTypeNode(_js_jts_dNode node) noexcept;
			static auto isMetaProperty(_js_jts_dNode node) noexcept;
			static auto isMethodDeclaration(_js_jts_dNode node) noexcept;
			static auto isMethodSignature(_js_jts_dNode node) noexcept;
			static auto isMissingDeclaration(_js_jts_dNode node) noexcept;
			static auto isModifier(_js_jts_dNode node) noexcept;
			static auto isModuleBlock(_js_jts_dNode node) noexcept;
			static auto isModuleDeclaration(_js_jts_dNode node) noexcept;
			static auto isNamedExports(_js_jts_dNode node) noexcept;
			static auto isNamedImports(_js_jts_dNode node) noexcept;
			static auto isNamespaceExportDeclaration(_js_jts_dNode node) noexcept;
			static auto isNamespaceImport(_js_jts_dNode node) noexcept;
			static auto isNewExpression(_js_jts_dNode node) noexcept;
			static auto isNoSubstitutionTemplateLiteral(_js_jts_dNode node) noexcept;
			static auto isNonNullExpression(_js_jts_dNode node) noexcept;
			static auto isNumericLiteral(_js_jts_dNode node) noexcept;
			static auto isObjectBindingPattern(_js_jts_dNode node) noexcept;
			static auto isObjectLiteralElement(_js_jts_dNode node) noexcept;
			static auto isObjectLiteralElementLike(_js_jts_dNode node) noexcept;
			static auto isObjectLiteralExpression(_js_jts_dNode node) noexcept;
			static auto isOmittedExpression(_js_jts_dNode node) noexcept;
			static auto isParameter(_js_jts_dNode node) noexcept;
			static auto isParameterPropertyDeclaration(_js_jts_dNode node) noexcept;
			static auto isParenthesizedExpression(_js_jts_dNode node) noexcept;
			static auto isParenthesizedTypeNode(_js_jts_dNode node) noexcept;
			static auto isParseTreeNode(_js_jts_dNode node) noexcept;
			static auto isPostfixUnaryExpression(_js_jts_dNode node) noexcept;
			static auto isPrefixUnaryExpression(_js_jts_dNode node) noexcept;
			static auto isPropertyAccessExpression(_js_jts_dNode node) noexcept;
			static auto isPropertyAccessOrQualifiedName(_js_jts_dNode node) noexcept;
			static auto isPropertyAssignment(_js_jts_dNode node) noexcept;
			static auto isPropertyDeclaration(_js_jts_dNode node) noexcept;
			static auto isPropertyName(_js_jts_dNode node) noexcept;
			static auto isPropertySignature(_js_jts_dNode node) noexcept;
			static auto isQualifiedName(_js_jts_dNode node) noexcept;
			static auto isRegularExpressionLiteral(_js_jts_dNode node) noexcept;
			static auto isReturnStatement(_js_jts_dNode node) noexcept;
			static auto isSemicolonClassElement(_js_jts_dNode node) noexcept;
			static auto isSetAccessor(_js_jts_dNode node) noexcept;
			static auto isSetAccessorDeclaration(_js_jts_dNode node) noexcept;
			static auto isShorthandPropertyAssignment(_js_jts_dNode node) noexcept;
			static auto isSourceFile(_js_jts_dNode node) noexcept;
			static auto isSpreadAssignment(_js_jts_dNode node) noexcept;
			static auto isSpreadElement(_js_jts_dNode node) noexcept;
			static auto isStringLiteral(_js_jts_dNode node) noexcept;
			static auto isStringLiteralLike(_js_jts_dNode node) noexcept;
			static auto isStringTextContainingNode(_js_jts_dNode node) noexcept;
			static auto isSwitchStatement(_js_jts_dNode node) noexcept;
			static auto isTaggedTemplateExpression(_js_jts_dNode node) noexcept;
			static auto isTemplateExpression(_js_jts_dNode node) noexcept;
			static auto isTemplateHead(_js_jts_dNode node) noexcept;
			static auto isTemplateLiteral(_js_jts_dNode node) noexcept;
			static auto isTemplateLiteralToken(_js_jts_dNode node) noexcept;
			static auto isTemplateMiddle(_js_jts_dNode node) noexcept;
			static auto isTemplateMiddleOrTemplateTail(_js_jts_dNode node) noexcept;
			static auto isTemplateSpan(_js_jts_dNode node) noexcept;
			static auto isTemplateTail(_js_jts_dNode node) noexcept;
			static auto isThisTypeNode(_js_jts_dNode node) noexcept;
			static auto isThrowStatement(_js_jts_dNode node) noexcept;
			static auto isToken(_js_jts_dNode n) noexcept;
			static auto isTryStatement(_js_jts_dNode node) noexcept;
			static auto isTupleTypeNode(_js_jts_dNode node) noexcept;
			static auto isTypeAliasDeclaration(_js_jts_dNode node) noexcept;
			static auto isTypeAssertion(_js_jts_dNode node) noexcept;
			static auto isTypeElement(_js_jts_dNode node) noexcept;
			static auto isTypeLiteralNode(_js_jts_dNode node) noexcept;
			static auto isTypeNode(_js_jts_dNode node) noexcept;
			static auto isTypeOfExpression(_js_jts_dNode node) noexcept;
			static auto isTypeOperatorNode(_js_jts_dNode node) noexcept;
			static auto isTypeParameterDeclaration(_js_jts_dNode node) noexcept;
			static auto isTypePredicateNode(_js_jts_dNode node) noexcept;
			static auto isTypeQueryNode(_js_jts_dNode node) noexcept;
			static auto isTypeReferenceNode(_js_jts_dNode node) noexcept;
			static auto isUnionTypeNode(_js_jts_dNode node) noexcept;
			static auto isUnparsedNode(_js_jts_dNode node) noexcept;
			static auto isUnparsedPrepend(_js_jts_dNode node) noexcept;
			static auto isUnparsedSource(_js_jts_dNode node) noexcept;
			static auto isUnparsedTextLike(_js_jts_dNode node) noexcept;
			static auto isVariableDeclaration(_js_jts_dNode node) noexcept;
			static auto isVariableDeclarationList(_js_jts_dNode node) noexcept;
			static auto isVariableStatement(_js_jts_dNode node) noexcept;
			static auto isVoidExpression(_js_jts_dNode node) noexcept;
			static auto isWhileStatement(_js_jts_dNode node) noexcept;
			static auto isWhiteSpaceLike(double ch) noexcept;
			static auto isWhiteSpaceSingleLine(double ch) noexcept;
			static auto isWithStatement(_js_jts_dNode node) noexcept;
			static auto isYieldExpression(_js_jts_dNode node) noexcept;
			static auto moveEmitHelpers(_js_jts_dNode source, _js_jts_dNode target, js_function<bool /*false*/(_js_jts_dEmitHelper)> predicate) noexcept;
			static auto moveSyntheticComments(js_unknown /*flags=262144: T ()*/ node, _js_jts_dNode original) noexcept;
			static auto nodeModuleNameResolver(js_string moduleName, js_string containingFile, _js_jts_dCompilerOptions compilerOptions, _js_jts_dModuleResolutionHost host, js_union<_js_jts_dModuleResolutionCache, js_undefined> cache = js_undefined(), js_union<_js_jts_dResolvedProjectReference, js_undefined> redirectedReference = js_undefined()) noexcept;
			static auto parseCommandLine(js::ReadonlyArray<js_string> commandLine, js_union<js_function<js_union<js_string, js_undefined>(js_string)>, js_undefined> readFile = js_undefined()) noexcept;
			static auto parseConfigFileTextToJson(js_string fileName, js_string jsonText) noexcept;
			static auto parseIsolatedEntityName(js_string text, _js_jts_dScriptTarget /*ScriptTarget.ES3*/ languageVersion) noexcept;
			static auto parseJsonConfigFileContent(js_unknown json, _js_jts_dParseConfigHost host, js_string basePath, js_union<_js_jts_dCompilerOptions, js_undefined> existingOptions = js_undefined(), js_union<js_string, js_undefined> configFileName = js_undefined(), js_union<js::Array<js_unknown /*flags=2097152: Path ()*/>, js_undefined> resolutionStack = js_undefined(), js_union<js::ReadonlyArray<_js_jts_dFileExtensionInfo>, js_undefined> extraFileExtensions = js_undefined(), js_unknown /*flags=1048576: Map<ExtendedConfigCacheEntry> | undefined ()*/ extendedConfigCache = js_undefined()) noexcept;
			static auto parseJsonSourceFileConfigFileContent(_js_jts_dTsConfigSourceFile sourceFile, _js_jts_dParseConfigHost host, js_string basePath, js_union<_js_jts_dCompilerOptions, js_undefined> existingOptions = js_undefined(), js_union<js_string, js_undefined> configFileName = js_undefined(), js_union<js::Array<js_unknown /*flags=2097152: Path ()*/>, js_undefined> resolutionStack = js_undefined(), js_union<js::ReadonlyArray<_js_jts_dFileExtensionInfo>, js_undefined> extraFileExtensions = js_undefined(), js_unknown /*flags=1048576: Map<ExtendedConfigCacheEntry> | undefined ()*/ extendedConfigCache = js_undefined()) noexcept;
			static auto parseJsonText(js_string fileName, js_string sourceText) noexcept;
			static auto preProcessFile(js_string sourceText, js_union<bool /*false*/, js_undefined> readImportFiles = js_undefined(), js_union<bool /*false*/, js_undefined> detectJavaScriptImports = js_undefined()) noexcept;
			static auto readConfigFile(js_string fileName, js_function<js_union<js_string, js_undefined>(js_string)> readFile) noexcept;
			static auto readJsonConfigFile(js_string fileName, js_function<js_union<js_string, js_undefined>(js_string)> readFile) noexcept;
			static auto reduceEachLeadingCommentRange(js_string text, double pos, js_function<js_unknown /*flags=262144: U ()*/(double, double, _js_jts_dSyntaxKind /*SyntaxKind.SingleLineCommentTrivia*/, bool /*false*/, js_unknown /*flags=262144: T ()*/, js_unknown /*flags=262144: U ()*/)> cb, js_unknown /*flags=262144: T ()*/ state, js_unknown /*flags=262144: U ()*/ initial) noexcept;
			static auto reduceEachTrailingCommentRange(js_string text, double pos, js_function<js_unknown /*flags=262144: U ()*/(double, double, _js_jts_dSyntaxKind /*SyntaxKind.SingleLineCommentTrivia*/, bool /*false*/, js_unknown /*flags=262144: T ()*/, js_unknown /*flags=262144: U ()*/)> cb, js_unknown /*flags=262144: T ()*/ state, js_unknown /*flags=262144: U ()*/ initial) noexcept;
			static auto removeEmitHelper(_js_jts_dNode node, _js_jts_dEmitHelper helper) noexcept;
			static auto resolveModuleName(js_string moduleName, js_string containingFile, _js_jts_dCompilerOptions compilerOptions, _js_jts_dModuleResolutionHost host, js_union<_js_jts_dModuleResolutionCache, js_undefined> cache = js_undefined(), js_union<_js_jts_dResolvedProjectReference, js_undefined> redirectedReference = js_undefined()) noexcept;
			static auto resolveModuleNameFromCache(js_string moduleName, js_string containingFile, _js_jts_dModuleResolutionCache cache) noexcept;
			static auto resolveProjectReferencePath(_js_jts_dProjectReference ref) noexcept;
			static auto resolveProjectReferencePath(_js_jts_dResolveProjectReferencePathHost host, _js_jts_dProjectReference ref) noexcept;
			static auto resolveTripleslashReference(js_string moduleName, js_string containingFile) noexcept;
			static auto resolveTypeReferenceDirective(js_string typeReferenceDirectiveName, js_union<js_string, js_undefined> containingFile, _js_jts_dCompilerOptions options, _js_jts_dModuleResolutionHost host, js_union<_js_jts_dResolvedProjectReference, js_undefined> redirectedReference = js_undefined()) noexcept;
			static auto setCommentRange(js_unknown /*flags=262144: T ()*/ node, _js_jts_dTextRange range) noexcept;
			static auto setConstantValue(js_union<_js_jts_dElementAccessExpression, _js_jts_dPropertyAccessExpression> node, js_union<double, js_string> value) noexcept;
			static auto setEmitFlags(js_unknown /*flags=262144: T ()*/ node, _js_jts_dEmitFlags /*EmitFlags.None*/ emitFlags) noexcept;
			static auto setOriginalNode(js_unknown /*flags=262144: T ()*/ node, js_union<_js_jts_dNode, js_undefined> original = js_undefined()) noexcept;
			static auto setSourceMapRange(js_unknown /*flags=262144: T ()*/ node, js_union<_js_jts_dSourceMapRange, js_undefined> range = js_undefined()) noexcept;
			static auto setSyntheticLeadingComments(js_unknown /*flags=262144: T ()*/ node, js_union<js::Array<_js_jts_dSynthesizedComment>, js_undefined> comments = js_undefined()) noexcept;
			static auto setSyntheticTrailingComments(js_unknown /*flags=262144: T ()*/ node, js_union<js::Array<_js_jts_dSynthesizedComment>, js_undefined> comments = js_undefined()) noexcept;
			static auto setTextRange(js_unknown /*flags=262144: T ()*/ range, js_union<_js_jts_dTextRange, js_undefined> location = js_undefined()) noexcept;
			static auto setTokenSourceMapRange(js_unknown /*flags=262144: T ()*/ node, _js_jts_dSyntaxKind /*SyntaxKind.Unknown*/ token, js_union<_js_jts_dSourceMapRange, js_undefined> range = js_undefined()) noexcept;
			static auto skipPartiallyEmittedExpressions(_js_jts_dExpression node) noexcept;
			static auto skipPartiallyEmittedExpressions(_js_jts_dNode node) noexcept;
			static auto sortAndDeduplicateDiagnostics(js::ReadonlyArray<js_unknown /*flags=262144: T ()*/> diagnostics) noexcept;
			static auto symbolName(_js_jts_dSymbol symbol) noexcept;
			static auto textChangeRangeIsUnchanged(_js_jts_dTextChangeRange range) noexcept;
			static auto textChangeRangeNewSpan(_js_jts_dTextChangeRange range) noexcept;
			static auto textSpanContainsPosition(_js_jts_dTextSpan span, double position) noexcept;
			static auto textSpanContainsTextSpan(_js_jts_dTextSpan span, _js_jts_dTextSpan other) noexcept;
			static auto textSpanEnd(_js_jts_dTextSpan span) noexcept;
			static auto textSpanIntersection(_js_jts_dTextSpan span1, _js_jts_dTextSpan span2) noexcept;
			static auto textSpanIntersectsWith(_js_jts_dTextSpan span, double start, double length) noexcept;
			static auto textSpanIntersectsWithPosition(_js_jts_dTextSpan span, double position) noexcept;
			static auto textSpanIntersectsWithTextSpan(_js_jts_dTextSpan span, _js_jts_dTextSpan other) noexcept;
			static auto textSpanIsEmpty(_js_jts_dTextSpan span) noexcept;
			static auto textSpanOverlap(_js_jts_dTextSpan span1, _js_jts_dTextSpan span2) noexcept;
			static auto textSpanOverlapsWith(_js_jts_dTextSpan span, _js_jts_dTextSpan other) noexcept;
			static auto toEditorSettings(js_union<_js_jts_dEditorOptions, _js_jts_dEditorSettings> options) noexcept;
			static auto tokenToString(_js_jts_dSyntaxKind /*SyntaxKind.Unknown*/ t) noexcept;
			static auto transform(js_unknown /*flags=1048576: T | T[] ()*/ source, js::Array<js_unknown /*flags=524288: TransformerFactory<T> ()*/> transformers, js_union<_js_jts_dCompilerOptions, js_undefined> compilerOptions = js_undefined()) noexcept;
			static auto transpile(js_string input, js_union<_js_jts_dCompilerOptions, js_undefined> compilerOptions = js_undefined(), js_union<js_string, js_undefined> fileName = js_undefined(), js_union<js::Array<_js_jts_dDiagnostic>, js_undefined> diagnostics = js_undefined(), js_union<js_string, js_undefined> moduleName = js_undefined()) noexcept;
			static auto transpileModule(js_string input, _js_jts_dTranspileOptions transpileOptions) noexcept;
			static auto unescapeLeadingUnderscores(js_unknown /*flags=1048576: __String ()*/ identifier) noexcept;
			static auto updateArrayBindingPattern(_js_jts_dArrayBindingPattern node, js::ReadonlyArray<js_union<_js_jts_dBindingElement, _js_jts_dOmittedExpression>> elements) noexcept;
			static auto updateArrayLiteral(_js_jts_dArrayLiteralExpression node, js::ReadonlyArray<_js_jts_dExpression> elements) noexcept;
			static auto updateArrayTypeNode(_js_jts_dArrayTypeNode node, _js_jts_dTypeNode elementType) noexcept;
			static auto updateArrowFunction(_js_jts_dArrowFunction node, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, js_union<_js_jts_dTypeNode, js_undefined> type, js_unknown /*flags=524288: Token<SyntaxKind.EqualsGreaterThanToken> (TypeReference=ts.Token)*/ equalsGreaterThanToken, js_union<_js_jts_dBlock, _js_jts_dExpression> body) noexcept;
			static auto updateAsExpression(_js_jts_dAsExpression node, _js_jts_dExpression expression, _js_jts_dTypeNode type) noexcept;
			static auto updateAwait(_js_jts_dAwaitExpression node, _js_jts_dExpression expression) noexcept;
			static auto updateBinary(_js_jts_dBinaryExpression node, _js_jts_dExpression left, _js_jts_dExpression right, js_unknown /*flags=1048576: SyntaxKind.CommaToken | SyntaxKind.LessThanToken | SyntaxKind.GreaterThanToken | SyntaxKind.LessThanEqualsToken | SyntaxKind.GreaterThanEqualsToken | SyntaxKind.EqualsEqualsToken | SyntaxKind.ExclamationEqualsToken | SyntaxKind.EqualsEqualsEqualsToken | SyntaxKind.ExclamationEqualsEqualsToken | SyntaxKind.PlusToken ... ()*/ operator_ = js_undefined()) noexcept;
			static auto updateBindingElement(_js_jts_dBindingElement node, js_unknown /*flags=1048576: Token<SyntaxKind.DotDotDotToken> | undefined ()*/ dotDotDotToken, js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral, js_undefined> propertyName, js_union<_js_jts_dArrayBindingPattern, _js_jts_dIdentifier, _js_jts_dObjectBindingPattern> name, js_union<_js_jts_dExpression, js_undefined> initializer = js_undefined()) noexcept;
			static auto updateBlock(_js_jts_dBlock node, js::ReadonlyArray<_js_jts_dStatement> statements) noexcept;
			static auto updateBreak(_js_jts_dBreakStatement node, js_union<_js_jts_dIdentifier, js_undefined> label = js_undefined()) noexcept;
			static auto updateBundle(_js_jts_dBundle node, js::ReadonlyArray<_js_jts_dSourceFile> sourceFiles, js_union<js::ReadonlyArray<js_union<_js_jts_dInputFiles, _js_jts_dUnparsedSource>>, js_undefined> prepends = js_undefined()) noexcept;
			static auto updateCall(_js_jts_dCallExpression node, _js_jts_dExpression expression, js_union<js::ReadonlyArray<_js_jts_dTypeNode>, js_undefined> typeArguments, js::ReadonlyArray<_js_jts_dExpression> argumentsArray) noexcept;
			static auto updateCallSignature(_js_jts_dCallSignatureDeclaration node, js_unknown /*flags=1048576: NodeArray<TypeParameterDeclaration> | undefined ()*/ typeParameters, js_unknown /*flags=524288: NodeArray<ParameterDeclaration> (TypeReference=ts.NodeArray)*/ parameters, js_union<_js_jts_dTypeNode, js_undefined> type = js_undefined()) noexcept;
			static auto updateCaseBlock(_js_jts_dCaseBlock node, js::ReadonlyArray<js_union<_js_jts_dCaseClause, _js_jts_dDefaultClause>> clauses) noexcept;
			static auto updateCaseClause(_js_jts_dCaseClause node, _js_jts_dExpression expression, js::ReadonlyArray<_js_jts_dStatement> statements) noexcept;
			static auto updateCatchClause(_js_jts_dCatchClause node, js_union<_js_jts_dVariableDeclaration, js_undefined> variableDeclaration, _js_jts_dBlock block) noexcept;
			static auto updateClassDeclaration(_js_jts_dClassDeclaration node, js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dIdentifier, js_undefined> name, js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, js_union<js::ReadonlyArray<_js_jts_dHeritageClause>, js_undefined> heritageClauses, js::ReadonlyArray<_js_jts_dClassElement> members) noexcept;
			static auto updateClassExpression(_js_jts_dClassExpression node, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dIdentifier, js_undefined> name, js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, js_union<js::ReadonlyArray<_js_jts_dHeritageClause>, js_undefined> heritageClauses, js::ReadonlyArray<_js_jts_dClassElement> members) noexcept;
			static auto updateCommaList(_js_jts_dCommaListExpression node, js::ReadonlyArray<_js_jts_dExpression> elements) noexcept;
			static auto updateComputedPropertyName(_js_jts_dComputedPropertyName node, _js_jts_dExpression expression) noexcept;
			static auto updateConditional(_js_jts_dConditionalExpression node, _js_jts_dExpression condition, js_unknown /*flags=524288: Token<SyntaxKind.QuestionToken> (TypeReference=ts.Token)*/ questionToken, _js_jts_dExpression whenTrue, js_unknown /*flags=524288: Token<SyntaxKind.ColonToken> (TypeReference=ts.Token)*/ colonToken, _js_jts_dExpression whenFalse) noexcept;
			static auto updateConditionalTypeNode(_js_jts_dConditionalTypeNode node, _js_jts_dTypeNode checkType, _js_jts_dTypeNode extendsType, _js_jts_dTypeNode trueType, _js_jts_dTypeNode falseType) noexcept;
			static auto updateConstructSignature(_js_jts_dConstructSignatureDeclaration node, js_unknown /*flags=1048576: NodeArray<TypeParameterDeclaration> | undefined ()*/ typeParameters, js_unknown /*flags=524288: NodeArray<ParameterDeclaration> (TypeReference=ts.NodeArray)*/ parameters, js_union<_js_jts_dTypeNode, js_undefined> type = js_undefined()) noexcept;
			static auto updateConstructor(_js_jts_dConstructorDeclaration node, js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, js_union<_js_jts_dBlock, js_undefined> body = js_undefined()) noexcept;
			static auto updateConstructorTypeNode(_js_jts_dConstructorTypeNode node, js_unknown /*flags=1048576: NodeArray<TypeParameterDeclaration> | undefined ()*/ typeParameters, js_unknown /*flags=524288: NodeArray<ParameterDeclaration> (TypeReference=ts.NodeArray)*/ parameters, js_union<_js_jts_dTypeNode, js_undefined> type = js_undefined()) noexcept;
			static auto updateContinue(_js_jts_dContinueStatement node, js_union<_js_jts_dIdentifier, js_undefined> label = js_undefined()) noexcept;
			static auto updateDecorator(_js_jts_dDecorator node, _js_jts_dExpression expression) noexcept;
			static auto updateDefaultClause(_js_jts_dDefaultClause node, js::ReadonlyArray<_js_jts_dStatement> statements) noexcept;
			static auto updateDelete(_js_jts_dDeleteExpression node, _js_jts_dExpression expression) noexcept;
			static auto updateDo(_js_jts_dDoStatement node, _js_jts_dStatement statement, _js_jts_dExpression expression) noexcept;
			static auto updateElementAccess(_js_jts_dElementAccessExpression node, _js_jts_dExpression expression, _js_jts_dExpression argumentExpression) noexcept;
			static auto updateEnumDeclaration(_js_jts_dEnumDeclaration node, js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, _js_jts_dIdentifier name, js::ReadonlyArray<_js_jts_dEnumMember> members) noexcept;
			static auto updateEnumMember(_js_jts_dEnumMember node, js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral> name, js_union<_js_jts_dExpression, js_undefined> initializer = js_undefined()) noexcept;
			static auto updateExportAssignment(_js_jts_dExportAssignment node, js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, _js_jts_dExpression expression) noexcept;
			static auto updateExportDeclaration(_js_jts_dExportDeclaration node, js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators = js_undefined(), js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers = js_undefined(), js_union<_js_jts_dNamedExports, js_undefined> exportClause = js_undefined(), js_union<_js_jts_dExpression, js_undefined> moduleSpecifier = js_undefined()) noexcept;
			static auto updateExportSpecifier(_js_jts_dExportSpecifier node, js_union<_js_jts_dIdentifier, js_undefined> propertyName, _js_jts_dIdentifier name) noexcept;
			static auto updateExpressionStatement(_js_jts_dExpressionStatement node, _js_jts_dExpression expression) noexcept;
			static auto updateExpressionWithTypeArguments(_js_jts_dExpressionWithTypeArguments node, js_union<js::ReadonlyArray<_js_jts_dTypeNode>, js_undefined> typeArguments, _js_jts_dExpression expression) noexcept;
			static auto updateExternalModuleReference(_js_jts_dExternalModuleReference node, _js_jts_dExpression expression) noexcept;
			static auto updateFor(_js_jts_dForStatement node, js_union<_js_jts_dExpression, _js_jts_dVariableDeclarationList, js_undefined> initializer, js_union<_js_jts_dExpression, js_undefined> condition, js_union<_js_jts_dExpression, js_undefined> incrementor, _js_jts_dStatement statement) noexcept;
			static auto updateForIn(_js_jts_dForInStatement node, js_union<_js_jts_dExpression, _js_jts_dVariableDeclarationList> initializer, _js_jts_dExpression expression, _js_jts_dStatement statement) noexcept;
			static auto updateForOf(_js_jts_dForOfStatement node, js_unknown /*flags=1048576: Token<SyntaxKind.AwaitKeyword> | undefined ()*/ awaitModifier, js_union<_js_jts_dExpression, _js_jts_dVariableDeclarationList> initializer, _js_jts_dExpression expression, _js_jts_dStatement statement) noexcept;
			static auto updateFunctionDeclaration(_js_jts_dFunctionDeclaration node, js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_unknown /*flags=1048576: Token<SyntaxKind.AsteriskToken> | undefined ()*/ asteriskToken, js_union<_js_jts_dIdentifier, js_undefined> name, js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, js_union<_js_jts_dTypeNode, js_undefined> type = js_undefined(), js_union<_js_jts_dBlock, js_undefined> body = js_undefined()) noexcept;
			static auto updateFunctionExpression(_js_jts_dFunctionExpression node, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_unknown /*flags=1048576: Token<SyntaxKind.AsteriskToken> | undefined ()*/ asteriskToken, js_union<_js_jts_dIdentifier, js_undefined> name, js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, js_union<_js_jts_dTypeNode, js_undefined> type, _js_jts_dBlock body) noexcept;
			static auto updateFunctionTypeNode(_js_jts_dFunctionTypeNode node, js_unknown /*flags=1048576: NodeArray<TypeParameterDeclaration> | undefined ()*/ typeParameters, js_unknown /*flags=524288: NodeArray<ParameterDeclaration> (TypeReference=ts.NodeArray)*/ parameters, js_union<_js_jts_dTypeNode, js_undefined> type = js_undefined()) noexcept;
			static auto updateGetAccessor(_js_jts_dGetAccessorDeclaration node, js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral> name, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, js_union<_js_jts_dTypeNode, js_undefined> type = js_undefined(), js_union<_js_jts_dBlock, js_undefined> body = js_undefined()) noexcept;
			static auto updateHeritageClause(_js_jts_dHeritageClause node, js::ReadonlyArray<_js_jts_dExpressionWithTypeArguments> types) noexcept;
			static auto updateIdentifier(_js_jts_dIdentifier node) noexcept;
			static auto updateIf(_js_jts_dIfStatement node, _js_jts_dExpression expression, _js_jts_dStatement thenStatement, js_union<_js_jts_dStatement, js_undefined> elseStatement = js_undefined()) noexcept;
			static auto updateImportClause(_js_jts_dImportClause node, js_union<_js_jts_dIdentifier, js_undefined> name = js_undefined(), js_union<_js_jts_dNamedImports, _js_jts_dNamespaceImport, js_undefined> namedBindings = js_undefined()) noexcept;
			static auto updateImportDeclaration(_js_jts_dImportDeclaration node, js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dImportClause, js_undefined> importClause, _js_jts_dExpression moduleSpecifier) noexcept;
			static auto updateImportEqualsDeclaration(_js_jts_dImportEqualsDeclaration node, js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, _js_jts_dIdentifier name, js_union<_js_jts_dExternalModuleReference, _js_jts_dIdentifier, _js_jts_dQualifiedName> moduleReference) noexcept;
			static auto updateImportSpecifier(_js_jts_dImportSpecifier node, js_union<_js_jts_dIdentifier, js_undefined> propertyName, _js_jts_dIdentifier name) noexcept;
			static auto updateImportTypeNode(_js_jts_dImportTypeNode node, _js_jts_dTypeNode argument, js_union<_js_jts_dIdentifier, _js_jts_dQualifiedName, js_undefined> qualifier = js_undefined(), js_union<js::ReadonlyArray<_js_jts_dTypeNode>, js_undefined> typeArguments = js_undefined(), js_union<bool /*false*/, js_undefined> isTypeOf = js_undefined()) noexcept;
			static auto updateIndexSignature(_js_jts_dIndexSignatureDeclaration node, js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, _js_jts_dTypeNode type) noexcept;
			static auto updateIndexedAccessTypeNode(_js_jts_dIndexedAccessTypeNode node, _js_jts_dTypeNode objectType, _js_jts_dTypeNode indexType) noexcept;
			static auto updateInferTypeNode(_js_jts_dInferTypeNode node, _js_jts_dTypeParameterDeclaration typeParameter) noexcept;
			static auto updateInterfaceDeclaration(_js_jts_dInterfaceDeclaration node, js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, _js_jts_dIdentifier name, js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, js_union<js::ReadonlyArray<_js_jts_dHeritageClause>, js_undefined> heritageClauses, js::ReadonlyArray<_js_jts_dTypeElement> members) noexcept;
			static auto updateIntersectionTypeNode(_js_jts_dIntersectionTypeNode node, js_unknown /*flags=524288: NodeArray<TypeNode> (TypeReference=ts.NodeArray)*/ types) noexcept;
			static auto updateJsxAttribute(_js_jts_dJsxAttribute node, _js_jts_dIdentifier name, js_union<_js_jts_dJsxExpression, _js_jts_dStringLiteral> initializer) noexcept;
			static auto updateJsxAttributes(_js_jts_dJsxAttributes node, js::ReadonlyArray<js_union<_js_jts_dJsxAttribute, _js_jts_dJsxSpreadAttribute>> properties) noexcept;
			static auto updateJsxClosingElement(_js_jts_dJsxClosingElement node, js_union<_js_jts_dIdentifier, _js_jts_dJsxTagNamePropertyAccess, _js_jts_dThisExpression> tagName) noexcept;
			static auto updateJsxElement(_js_jts_dJsxElement node, _js_jts_dJsxOpeningElement openingElement, js::ReadonlyArray<js_union<_js_jts_dJsxElement, _js_jts_dJsxExpression, _js_jts_dJsxFragment, _js_jts_dJsxSelfClosingElement, _js_jts_dJsxText>> children, _js_jts_dJsxClosingElement closingElement) noexcept;
			static auto updateJsxExpression(_js_jts_dJsxExpression node, js_union<_js_jts_dExpression, js_undefined> expression = js_undefined()) noexcept;
			static auto updateJsxFragment(_js_jts_dJsxFragment node, _js_jts_dJsxOpeningFragment openingFragment, js::ReadonlyArray<js_union<_js_jts_dJsxElement, _js_jts_dJsxExpression, _js_jts_dJsxFragment, _js_jts_dJsxSelfClosingElement, _js_jts_dJsxText>> children, _js_jts_dJsxClosingFragment closingFragment) noexcept;
			static auto updateJsxOpeningElement(_js_jts_dJsxOpeningElement node, js_union<_js_jts_dIdentifier, _js_jts_dJsxTagNamePropertyAccess, _js_jts_dThisExpression> tagName, js_union<js::ReadonlyArray<_js_jts_dTypeNode>, js_undefined> typeArguments, _js_jts_dJsxAttributes attributes) noexcept;
			static auto updateJsxSelfClosingElement(_js_jts_dJsxSelfClosingElement node, js_union<_js_jts_dIdentifier, _js_jts_dJsxTagNamePropertyAccess, _js_jts_dThisExpression> tagName, js_union<js::ReadonlyArray<_js_jts_dTypeNode>, js_undefined> typeArguments, _js_jts_dJsxAttributes attributes) noexcept;
			static auto updateJsxSpreadAttribute(_js_jts_dJsxSpreadAttribute node, _js_jts_dExpression expression) noexcept;
			static auto updateJsxText(_js_jts_dJsxText node, js_string text, js_union<bool /*false*/, js_undefined> containsOnlyTriviaWhiteSpaces = js_undefined()) noexcept;
			static auto updateLabel(_js_jts_dLabeledStatement node, _js_jts_dIdentifier label, _js_jts_dStatement statement) noexcept;
			static auto updateLanguageServiceSourceFile(_js_jts_dSourceFile sourceFile, _js_jts_dIScriptSnapshot scriptSnapshot, js_string version, js_union<_js_jts_dTextChangeRange, js_undefined> textChangeRange = js_undefined(), js_union<bool /*false*/, js_undefined> aggressiveChecks = js_undefined()) noexcept;
			static auto updateLiteralTypeNode(_js_jts_dLiteralTypeNode node, js_union<_js_jts_dBooleanLiteral, _js_jts_dLiteralExpression, _js_jts_dPrefixUnaryExpression> literal) noexcept;
			static auto updateMappedTypeNode(_js_jts_dMappedTypeNode node, js_unknown /*flags=1048576: Token<SyntaxKind.ReadonlyKeyword> | Token<SyntaxKind.PlusToken> | Token<SyntaxKind.MinusToken> | undefined ()*/ readonlyToken, _js_jts_dTypeParameterDeclaration typeParameter, js_unknown /*flags=1048576: Token<SyntaxKind.QuestionToken> | Token<SyntaxKind.PlusToken> | Token<SyntaxKind.MinusToken> | undefined ()*/ questionToken = js_undefined(), js_union<_js_jts_dTypeNode, js_undefined> type = js_undefined()) noexcept;
			static auto updateMetaProperty(_js_jts_dMetaProperty node, _js_jts_dIdentifier name) noexcept;
			static auto updateMethod(_js_jts_dMethodDeclaration node, js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_unknown /*flags=1048576: Token<SyntaxKind.AsteriskToken> | undefined ()*/ asteriskToken, js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral> name, js_unknown /*flags=1048576: Token<SyntaxKind.QuestionToken> | undefined ()*/ questionToken, js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, js_union<_js_jts_dTypeNode, js_undefined> type = js_undefined(), js_union<_js_jts_dBlock, js_undefined> body = js_undefined()) noexcept;
			static auto updateMethodSignature(_js_jts_dMethodSignature node, js_unknown /*flags=1048576: NodeArray<TypeParameterDeclaration> | undefined ()*/ typeParameters, js_unknown /*flags=524288: NodeArray<ParameterDeclaration> (TypeReference=ts.NodeArray)*/ parameters, js_union<_js_jts_dTypeNode, js_undefined> type, js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral> name, js_unknown /*flags=1048576: Token<SyntaxKind.QuestionToken> | undefined ()*/ questionToken = js_undefined()) noexcept;
			static auto updateModuleBlock(_js_jts_dModuleBlock node, js::ReadonlyArray<_js_jts_dStatement> statements) noexcept;
			static auto updateModuleDeclaration(_js_jts_dModuleDeclaration node, js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dIdentifier, _js_jts_dStringLiteral> name, js_union<_js_jts_dIdentifier, _js_jts_dJSDocNamespaceDeclaration, _js_jts_dModuleBlock, _js_jts_dNamespaceDeclaration, js_undefined> body = js_undefined()) noexcept;
			static auto updateNamedExports(_js_jts_dNamedExports node, js::ReadonlyArray<_js_jts_dExportSpecifier> elements) noexcept;
			static auto updateNamedImports(_js_jts_dNamedImports node, js::ReadonlyArray<_js_jts_dImportSpecifier> elements) noexcept;
			static auto updateNamespaceExportDeclaration(_js_jts_dNamespaceExportDeclaration node, _js_jts_dIdentifier name) noexcept;
			static auto updateNamespaceImport(_js_jts_dNamespaceImport node, _js_jts_dIdentifier name) noexcept;
			static auto updateNew(_js_jts_dNewExpression node, _js_jts_dExpression expression, js_union<js::ReadonlyArray<_js_jts_dTypeNode>, js_undefined> typeArguments = js_undefined(), js_union<js::ReadonlyArray<_js_jts_dExpression>, js_undefined> argumentsArray = js_undefined()) noexcept;
			static auto updateNonNullExpression(_js_jts_dNonNullExpression node, _js_jts_dExpression expression) noexcept;
			static auto updateObjectBindingPattern(_js_jts_dObjectBindingPattern node, js::ReadonlyArray<_js_jts_dBindingElement> elements) noexcept;
			static auto updateObjectLiteral(_js_jts_dObjectLiteralExpression node, js::ReadonlyArray<js_union<_js_jts_dGetAccessorDeclaration, _js_jts_dMethodDeclaration, _js_jts_dPropertyAssignment, _js_jts_dSetAccessorDeclaration, _js_jts_dShorthandPropertyAssignment, _js_jts_dSpreadAssignment>> properties) noexcept;
			static auto updateOptionalTypeNode(_js_jts_dOptionalTypeNode node, _js_jts_dTypeNode type) noexcept;
			static auto updateParameter(_js_jts_dParameterDeclaration node, js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_unknown /*flags=1048576: Token<SyntaxKind.DotDotDotToken> | undefined ()*/ dotDotDotToken, js_union<_js_jts_dArrayBindingPattern, _js_jts_dIdentifier, _js_jts_dObjectBindingPattern, js_string> name, js_unknown /*flags=1048576: Token<SyntaxKind.QuestionToken> | undefined ()*/ questionToken = js_undefined(), js_union<_js_jts_dTypeNode, js_undefined> type = js_undefined(), js_union<_js_jts_dExpression, js_undefined> initializer = js_undefined()) noexcept;
			static auto updateParen(_js_jts_dParenthesizedExpression node, _js_jts_dExpression expression) noexcept;
			static auto updateParenthesizedType(_js_jts_dParenthesizedTypeNode node, _js_jts_dTypeNode type) noexcept;
			static auto updatePartiallyEmittedExpression(_js_jts_dPartiallyEmittedExpression node, _js_jts_dExpression expression) noexcept;
			static auto updatePostfix(_js_jts_dPostfixUnaryExpression node, _js_jts_dExpression operand) noexcept;
			static auto updatePrefix(_js_jts_dPrefixUnaryExpression node, _js_jts_dExpression operand) noexcept;
			static auto updateProperty(_js_jts_dPropertyDeclaration node, js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral, js_string> name, js_unknown /*flags=1048576: Token<SyntaxKind.QuestionToken> | Token<SyntaxKind.ExclamationToken> | undefined ()*/ questionOrExclamationToken = js_undefined(), js_union<_js_jts_dTypeNode, js_undefined> type = js_undefined(), js_union<_js_jts_dExpression, js_undefined> initializer = js_undefined()) noexcept;
			static auto updatePropertyAccess(_js_jts_dPropertyAccessExpression node, _js_jts_dExpression expression, _js_jts_dIdentifier name) noexcept;
			static auto updatePropertyAssignment(_js_jts_dPropertyAssignment node, js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral> name, _js_jts_dExpression initializer) noexcept;
			static auto updatePropertySignature(_js_jts_dPropertySignature node, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral> name, js_unknown /*flags=1048576: Token<SyntaxKind.QuestionToken> | undefined ()*/ questionToken = js_undefined(), js_union<_js_jts_dTypeNode, js_undefined> type = js_undefined(), js_union<_js_jts_dExpression, js_undefined> initializer = js_undefined()) noexcept;
			static auto updateQualifiedName(_js_jts_dQualifiedName node, js_union<_js_jts_dIdentifier, _js_jts_dQualifiedName> left, _js_jts_dIdentifier right) noexcept;
			static auto updateRestTypeNode(_js_jts_dRestTypeNode node, _js_jts_dTypeNode type) noexcept;
			static auto updateReturn(_js_jts_dReturnStatement node, js_union<_js_jts_dExpression, js_undefined> expression = js_undefined()) noexcept;
			static auto updateSetAccessor(_js_jts_dSetAccessorDeclaration node, js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral> name, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, js_union<_js_jts_dBlock, js_undefined> body = js_undefined()) noexcept;
			static auto updateShorthandPropertyAssignment(_js_jts_dShorthandPropertyAssignment node, _js_jts_dIdentifier name, js_union<_js_jts_dExpression, js_undefined> objectAssignmentInitializer = js_undefined()) noexcept;
			static auto updateSourceFile(_js_jts_dSourceFile sourceFile, js_string newText, _js_jts_dTextChangeRange textChangeRange, js_union<bool /*false*/, js_undefined> aggressiveChecks = js_undefined()) noexcept;
			static auto updateSourceFileNode(_js_jts_dSourceFile node, js::ReadonlyArray<_js_jts_dStatement> statements, js_union<bool /*false*/, js_undefined> isDeclarationFile = js_undefined(), js_union<js::ReadonlyArray<_js_jts_dFileReference>, js_undefined> referencedFiles = js_undefined(), js_union<js::ReadonlyArray<_js_jts_dFileReference>, js_undefined> typeReferences = js_undefined(), js_union<bool /*false*/, js_undefined> hasNoDefaultLib = js_undefined(), js_union<js::ReadonlyArray<_js_jts_dFileReference>, js_undefined> libReferences = js_undefined()) noexcept;
			static auto updateSpread(_js_jts_dSpreadElement node, _js_jts_dExpression expression) noexcept;
			static auto updateSpreadAssignment(_js_jts_dSpreadAssignment node, _js_jts_dExpression expression) noexcept;
			static auto updateSwitch(_js_jts_dSwitchStatement node, _js_jts_dExpression expression, _js_jts_dCaseBlock caseBlock) noexcept;
			static auto updateTaggedTemplate(_js_jts_dTaggedTemplateExpression node, _js_jts_dExpression tag, js_union<_js_jts_dNoSubstitutionTemplateLiteral, _js_jts_dTemplateExpression> template_) noexcept;
			static auto updateTaggedTemplate(_js_jts_dTaggedTemplateExpression node, _js_jts_dExpression tag, js_union<js::ReadonlyArray<_js_jts_dTypeNode>, js_undefined> typeArguments, js_union<_js_jts_dNoSubstitutionTemplateLiteral, _js_jts_dTemplateExpression> template_) noexcept;
			static auto updateTemplateExpression(_js_jts_dTemplateExpression node, _js_jts_dTemplateHead head, js::ReadonlyArray<_js_jts_dTemplateSpan> templateSpans) noexcept;
			static auto updateTemplateSpan(_js_jts_dTemplateSpan node, _js_jts_dExpression expression, js_union<_js_jts_dTemplateMiddle, _js_jts_dTemplateTail> literal) noexcept;
			static auto updateThrow(_js_jts_dThrowStatement node, _js_jts_dExpression expression) noexcept;
			static auto updateTry(_js_jts_dTryStatement node, _js_jts_dBlock tryBlock, js_union<_js_jts_dCatchClause, js_undefined> catchClause = js_undefined(), js_union<_js_jts_dBlock, js_undefined> finallyBlock = js_undefined()) noexcept;
			static auto updateTupleTypeNode(_js_jts_dTupleTypeNode node, js::ReadonlyArray<_js_jts_dTypeNode> elementTypes) noexcept;
			static auto updateTypeAliasDeclaration(_js_jts_dTypeAliasDeclaration node, js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, _js_jts_dIdentifier name, js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, _js_jts_dTypeNode type) noexcept;
			static auto updateTypeAssertion(_js_jts_dTypeAssertion node, _js_jts_dTypeNode type, _js_jts_dExpression expression) noexcept;
			static auto updateTypeLiteralNode(_js_jts_dTypeLiteralNode node, js_unknown /*flags=524288: NodeArray<TypeElement> (TypeReference=ts.NodeArray)*/ members) noexcept;
			static auto updateTypeOf(_js_jts_dTypeOfExpression node, _js_jts_dExpression expression) noexcept;
			static auto updateTypeOperatorNode(_js_jts_dTypeOperatorNode node, _js_jts_dTypeNode type) noexcept;
			static auto updateTypeParameterDeclaration(_js_jts_dTypeParameterDeclaration node, _js_jts_dIdentifier name, js_union<_js_jts_dTypeNode, js_undefined> constraint = js_undefined(), js_union<_js_jts_dTypeNode, js_undefined> defaultType = js_undefined()) noexcept;
			static auto updateTypePredicateNode(_js_jts_dTypePredicateNode node, js_union<_js_jts_dIdentifier, _js_jts_dThisTypeNode> parameterName, _js_jts_dTypeNode type) noexcept;
			static auto updateTypeQueryNode(_js_jts_dTypeQueryNode node, js_union<_js_jts_dIdentifier, _js_jts_dQualifiedName> exprName) noexcept;
			static auto updateTypeReferenceNode(_js_jts_dTypeReferenceNode node, js_union<_js_jts_dIdentifier, _js_jts_dQualifiedName> typeName, js_unknown /*flags=1048576: NodeArray<TypeNode> | undefined ()*/ typeArguments = js_undefined()) noexcept;
			static auto updateUnionTypeNode(_js_jts_dUnionTypeNode node, js_unknown /*flags=524288: NodeArray<TypeNode> (TypeReference=ts.NodeArray)*/ types) noexcept;
			static auto updateVariableDeclaration(_js_jts_dVariableDeclaration node, js_union<_js_jts_dArrayBindingPattern, _js_jts_dIdentifier, _js_jts_dObjectBindingPattern> name, js_union<_js_jts_dTypeNode, js_undefined> type = js_undefined(), js_union<_js_jts_dExpression, js_undefined> initializer = js_undefined()) noexcept;
			static auto updateVariableDeclarationList(_js_jts_dVariableDeclarationList node, js::ReadonlyArray<_js_jts_dVariableDeclaration> declarations) noexcept;
			static auto updateVariableStatement(_js_jts_dVariableStatement node, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, _js_jts_dVariableDeclarationList declarationList) noexcept;
			static auto updateVoid(_js_jts_dVoidExpression node, _js_jts_dExpression expression) noexcept;
			static auto updateWhile(_js_jts_dWhileStatement node, _js_jts_dExpression expression, _js_jts_dStatement statement) noexcept;
			static auto updateWith(_js_jts_dWithStatement node, _js_jts_dExpression expression, _js_jts_dStatement statement) noexcept;
			static auto updateYield(_js_jts_dYieldExpression node, js_unknown /*flags=1048576: Token<SyntaxKind.AsteriskToken> | undefined ()*/ asteriskToken, _js_jts_dExpression expression) noexcept;
			static auto validateLocaleAndSetLanguage(js_string locale, js_unknown /*flags=524288: { getExecutingFilePath(): string; resolvePath(path: string): string; fileExists(fileName: string): boolean; readFile(fileName: string): string | undefined; } (AnonymousTypeWithTypeLiteral(members:[getExecutingFilePath, resolvePath, fileExists, readFile]))*/ sys, js_unknown /*flags=1048576: Push<Diagnostic> | undefined ()*/ errors = js_undefined()) noexcept;
			static auto visitEachChild(js_unknown /*flags=262144: T ()*/ node, js_function<js_union<_js_jts_dNode, js::Array<_js_jts_dNode>, js_undefined>(_js_jts_dNode)> visitor, _js_jts_dTransformationContext context) noexcept;
			static auto visitEachChild(js_unknown /*flags=1048576: T | undefined ()*/ node, js_function<js_union<_js_jts_dNode, js::Array<_js_jts_dNode>, js_undefined>(_js_jts_dNode)> visitor, _js_jts_dTransformationContext context, js_unknown /*flags=1048576: { <T extends Node>(nodes: NodeArray<T> | undefined, visitor: Visitor, test?: ((node: Node) => boolean) | undefined, start?: number | undefined, count?: number | undefined): NodeArray<T>; <T extends Node>(nodes: NodeArray<...> | undefined, visitor: Visitor, test?: ((node: Node) => boolean) | undefined, start?: number... ()*/ nodesVisitor = js_undefined(), js_union<js_function<js_union<_js_jts_dNode, js::Array<_js_jts_dNode>, js_undefined>(_js_jts_dNode)>, js_undefined> tokenVisitor = js_undefined()) noexcept;
			static auto visitFunctionBody(_js_jts_dBlock node, js_function<js_union<_js_jts_dNode, js::Array<_js_jts_dNode>, js_undefined>(_js_jts_dNode)> visitor, _js_jts_dTransformationContext context) noexcept;
			static auto visitFunctionBody(js_union<_js_jts_dBlock, _js_jts_dExpression> node, js_function<js_union<_js_jts_dNode, js::Array<_js_jts_dNode>, js_undefined>(_js_jts_dNode)> visitor, _js_jts_dTransformationContext context) noexcept;
			static auto visitFunctionBody(js_union<_js_jts_dBlock, js_undefined> node, js_function<js_union<_js_jts_dNode, js::Array<_js_jts_dNode>, js_undefined>(_js_jts_dNode)> visitor, _js_jts_dTransformationContext context) noexcept;
			static auto visitLexicalEnvironment(js_unknown /*flags=524288: NodeArray<Statement> (TypeReference=ts.NodeArray)*/ statements, js_function<js_union<_js_jts_dNode, js::Array<_js_jts_dNode>, js_undefined>(_js_jts_dNode)> visitor, _js_jts_dTransformationContext context, js_union<double, js_undefined> start = js_undefined(), js_union<bool /*false*/, js_undefined> ensureUseStrict = js_undefined()) noexcept;
			static auto visitNode(js_unknown /*flags=1048576: T | undefined ()*/ node = js_undefined(), js_union<js_function<js_union<_js_jts_dNode, js::Array<_js_jts_dNode>, js_undefined>(_js_jts_dNode)>, js_undefined> visitor = js_undefined(), js_union<js_function<bool /*false*/(_js_jts_dNode)>, js_undefined> test = js_undefined(), js_union<js_function<js_unknown /*flags=262144: T ()*/(js_unknown /*flags=524288: NodeArray<Node> (TypeReference=ts.NodeArray)*/)>, js_undefined> lift = js_undefined()) noexcept;
			static auto visitNodes(js_unknown /*flags=1048576: NodeArray<T> | undefined ()*/ nodes, js_function<js_union<_js_jts_dNode, js::Array<_js_jts_dNode>, js_undefined>(_js_jts_dNode)> visitor, js_union<js_function<bool /*false*/(_js_jts_dNode)>, js_undefined> test = js_undefined(), js_union<double, js_undefined> start = js_undefined(), js_union<double, js_undefined> count = js_undefined()) noexcept;
			static auto visitParameterList(js_unknown /*flags=1048576: NodeArray<ParameterDeclaration> | undefined ()*/ nodes, js_function<js_union<_js_jts_dNode, js::Array<_js_jts_dNode>, js_undefined>(_js_jts_dNode)> visitor, _js_jts_dTransformationContext context, js_unknown /*flags=1048576: { <T extends Node>(nodes: NodeArray<T> | undefined, visitor: Visitor, test?: ((node: Node) => boolean) | undefined, start?: number | undefined, count?: number | undefined): NodeArray<T>; <T extends Node>(nodes: NodeArray<...> | undefined, visitor: Visitor, test?: ((node: Node) => boolean) | undefined, start?: number... ()*/ nodesVisitor = js_undefined()) noexcept;
			static auto walkUpBindingElementsAndPatterns(_js_jts_dBindingElement binding) noexcept;
			static auto createStatement() noexcept;
			static void createStatement(js_unknown /*flags=524288: (expression: Expression) => ExpressionStatement ()*/ v) noexcept;
			static auto disableIncrementalParsing() noexcept;
			static void disableIncrementalParsing(bool /*false*/ v) noexcept;
			static auto servicesVersion() noexcept;
			static void servicesVersion(js_string /*"0.8"*/ v) noexcept;
			static auto sys() noexcept;
			static void sys(_js_jts_dSystem v) noexcept;
			static auto unchangedTextChangeRange() noexcept;
			static void unchangedTextChangeRange(_js_jts_dTextChangeRange v) noexcept;
			static auto updateStatement() noexcept;
			static void updateStatement(js_unknown /*flags=524288: (node: ExpressionStatement, expression: Expression) => ExpressionStatement ()*/ v) noexcept;
			static auto version() noexcept;
			static void version(js_string v) noexcept;
			static auto versionMajorMinor() noexcept;
			static void versionMajorMinor(js_string /*"3.5"*/ v) noexcept;
		};
	};
	struct _impl_js_jts_dMapLike : virtual IObject {
		struct _tcjs_definitions {
		};
	};
	struct _impl_js_jts_dSortedReadonlyArray : virtual IObject {
		struct _tcjs_definitions {
		};
		auto _u_uu_usortedArrayBrand() noexcept;
		void _u_uu_usortedArrayBrand(js_unknown v) noexcept;
	};
	struct _impl_js_jts_dSortedArray : virtual IObject {
		struct _tcjs_definitions {
		};
		auto _u_uu_usortedArrayBrand() noexcept;
		void _u_uu_usortedArrayBrand(js_unknown v) noexcept;
	};
	struct _impl_js_jts_dReadonlyMap : virtual IObject {
		struct _tcjs_definitions {
		};
		auto size() noexcept;
		auto entries() noexcept;
		auto forEach(js_function<void(js_unknown /*flags=262144: T ()*/, js_string)> action) noexcept;
		auto get(js_string key) noexcept;
		auto has(js_string key) noexcept;
		auto keys() noexcept;
		auto values() noexcept;
	};
	struct _impl_js_jts_dMap : virtual IObject {
		struct _tcjs_definitions {
		};
		auto clear() noexcept;
		auto delete_(js_string key) noexcept;
		auto set(js_string key, js_unknown /*flags=262144: T ()*/ value) noexcept;
	};
	struct _impl_js_jts_dIterator : virtual IObject {
		struct _tcjs_definitions {
		};
		auto next() noexcept;
	};
	struct _impl_js_jts_dPush : virtual IObject {
		struct _tcjs_definitions {
		};
		auto push(js::Array<js_unknown /*flags=262144: T ()*/> values) noexcept;
	};
	struct _impl_js_jts_dTextRange : virtual IObject {
		struct _tcjs_definitions {
		};
		auto pos() noexcept;
		void pos(double v) noexcept;
		auto end() noexcept;
		void end(double v) noexcept;
	};
	struct _impl_js_jts_dNode : virtual _impl_js_jts_dTextRange {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.Unknown*/ v) noexcept;
		auto flags() noexcept;
		void flags(_js_jts_dNodeFlags /*NodeFlags.None*/ v) noexcept;
		auto parent() noexcept;
		void parent(_js_jts_dNode v) noexcept;
		auto forEachChild(js_function<js_unknown /*flags=1048576: T | undefined ()*/(_js_jts_dNode)> cbNode, js_union<js_function<js_unknown /*flags=1048576: T | undefined ()*/(js_unknown /*flags=524288: NodeArray<Node> (TypeReference=ts.NodeArray)*/)>, js_undefined> cbNodeArray = js_undefined()) noexcept;
		auto getChildAt(double index, js_union<_js_jts_dSourceFile, js_undefined> sourceFile = js_undefined()) noexcept;
		auto getChildCount(js_union<_js_jts_dSourceFile, js_undefined> sourceFile = js_undefined()) noexcept;
		auto getChildren(js_union<_js_jts_dSourceFile, js_undefined> sourceFile = js_undefined()) noexcept;
		auto getEnd() noexcept;
		auto getFirstToken(js_union<_js_jts_dSourceFile, js_undefined> sourceFile = js_undefined()) noexcept;
		auto getFullStart() noexcept;
		auto getFullText(js_union<_js_jts_dSourceFile, js_undefined> sourceFile = js_undefined()) noexcept;
		auto getFullWidth() noexcept;
		auto getLastToken(js_union<_js_jts_dSourceFile, js_undefined> sourceFile = js_undefined()) noexcept;
		auto getLeadingTriviaWidth(js_union<_js_jts_dSourceFile, js_undefined> sourceFile = js_undefined()) noexcept;
		auto getSourceFile() noexcept;
		auto getStart(js_union<_js_jts_dSourceFile, js_undefined> sourceFile = js_undefined(), js_union<bool /*false*/, js_undefined> includeJsDocComment = js_undefined()) noexcept;
		auto getText(js_union<_js_jts_dSourceFile, js_undefined> sourceFile = js_undefined()) noexcept;
		auto getWidth(js_union<_js_jts_dSourceFileLike, js_undefined> sourceFile = js_undefined()) noexcept;
	};
	struct _impl_js_jts_dJSDocContainer : virtual IObject {
		struct _tcjs_definitions {
		};
	};
	struct _impl_js_jts_dNodeArray : virtual _impl_js_jts_dTextRange {
		struct _tcjs_definitions {
		};
	};
	struct _impl_js_jts_dToken : virtual _impl_js_jts_dNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(js_unknown /*flags=262144: TKind ()*/ v) noexcept;
	};
	struct _impl_js_jts_dExpression : virtual _impl_js_jts_dNode {
		struct _tcjs_definitions {
		};
		auto _expressionBrand() noexcept;
		void _expressionBrand(js_unknown v) noexcept;
	};
	struct _impl_js_jts_dUnaryExpression : virtual _impl_js_jts_dExpression {
		struct _tcjs_definitions {
		};
		auto _unaryExpressionBrand() noexcept;
		void _unaryExpressionBrand(js_unknown v) noexcept;
	};
	struct _impl_js_jts_dUpdateExpression : virtual _impl_js_jts_dUnaryExpression {
		struct _tcjs_definitions {
		};
		auto _updateExpressionBrand() noexcept;
		void _updateExpressionBrand(js_unknown v) noexcept;
	};
	struct _impl_js_jts_dLeftHandSideExpression : virtual _impl_js_jts_dUpdateExpression {
		struct _tcjs_definitions {
		};
		auto _leftHandSideExpressionBrand() noexcept;
		void _leftHandSideExpressionBrand(js_unknown v) noexcept;
	};
	struct _impl_js_jts_dMemberExpression : virtual _impl_js_jts_dLeftHandSideExpression {
		struct _tcjs_definitions {
		};
		auto _memberExpressionBrand() noexcept;
		void _memberExpressionBrand(js_unknown v) noexcept;
	};
	struct _impl_js_jts_dPrimaryExpression : virtual _impl_js_jts_dMemberExpression {
		struct _tcjs_definitions {
		};
		auto _primaryExpressionBrand() noexcept;
		void _primaryExpressionBrand(js_unknown v) noexcept;
	};
	struct _impl_js_jts_dDeclaration : virtual _impl_js_jts_dNode {
		struct _tcjs_definitions {
		};
		auto _declarationBrand() noexcept;
		void _declarationBrand(js_unknown v) noexcept;
	};
	struct _impl_js_jts_dIdentifier : virtual _impl_js_jts_dPrimaryExpression, virtual _impl_js_jts_dDeclaration {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.Identifier*/ v) noexcept;
		auto escapedText() noexcept;
		void escapedText(js_unknown /*flags=1048576: __String ()*/ v) noexcept;
		auto text() noexcept;
	};
	struct _impl_js_jts_dTransientIdentifier : virtual _impl_js_jts_dIdentifier {
		struct _tcjs_definitions {
		};
		auto resolvedSymbol() noexcept;
		void resolvedSymbol(_js_jts_dSymbol v) noexcept;
	};
	struct _impl_js_jts_dQualifiedName : virtual _impl_js_jts_dNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.QualifiedName*/ v) noexcept;
		auto left() noexcept;
		void left(js_union<_js_jts_dIdentifier, _js_jts_dQualifiedName> v) noexcept;
		auto right() noexcept;
		void right(_js_jts_dIdentifier v) noexcept;
	};
	struct _impl_js_jts_dNamedDeclaration : virtual _impl_js_jts_dDeclaration {
		struct _tcjs_definitions {
		};
	};
	struct _impl_js_jts_dStatement : virtual _impl_js_jts_dNode {
		struct _tcjs_definitions {
		};
		auto _statementBrand() noexcept;
		void _statementBrand(js_unknown v) noexcept;
	};
	struct _impl_js_jts_dDeclarationStatement : virtual _impl_js_jts_dNamedDeclaration, virtual _impl_js_jts_dStatement {
		struct _tcjs_definitions {
		};
	};
	struct _impl_js_jts_dComputedPropertyName : virtual _impl_js_jts_dNode {
		struct _tcjs_definitions {
		};
		auto parent() noexcept;
		void parent(_js_jts_dDeclaration v) noexcept;
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ComputedPropertyName*/ v) noexcept;
		auto expression() noexcept;
		void expression(_js_jts_dExpression v) noexcept;
	};
	struct _impl_js_jts_dDecorator : virtual _impl_js_jts_dNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.Decorator*/ v) noexcept;
		auto parent() noexcept;
		void parent(_js_jts_dNamedDeclaration v) noexcept;
		auto expression() noexcept;
		void expression(_js_jts_dLeftHandSideExpression v) noexcept;
	};
	struct _impl_js_jts_dTypeParameterDeclaration : virtual _impl_js_jts_dNamedDeclaration {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.TypeParameter*/ v) noexcept;
		auto parent() noexcept;
		void parent(js_union<_js_jts_dArrowFunction, _js_jts_dCallSignatureDeclaration, _js_jts_dClassDeclaration, _js_jts_dClassExpression, _js_jts_dConstructSignatureDeclaration, _js_jts_dConstructorDeclaration, _js_jts_dConstructorTypeNode, _js_jts_dFunctionDeclaration, _js_jts_dFunctionExpression, _js_jts_dFunctionTypeNode, _js_jts_dGetAccessorDeclaration, _js_jts_dIndexSignatureDeclaration, _js_jts_dInferTypeNode, _js_jts_dInterfaceDeclaration, _js_jts_dJSDocFunctionType, _js_jts_dJSDocTemplateTag, _js_jts_dMethodDeclaration, _js_jts_dMethodSignature, _js_jts_dSetAccessorDeclaration, _js_jts_dTypeAliasDeclaration> v) noexcept;
		auto name() noexcept;
		void name(_js_jts_dIdentifier v) noexcept;
	};
	struct _impl_js_jts_dSignatureDeclarationBase : virtual _impl_js_jts_dNamedDeclaration, virtual _impl_js_jts_dJSDocContainer {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.MethodSignature*/ v) noexcept;
		auto parameters() noexcept;
		void parameters(js_unknown /*flags=524288: NodeArray<ParameterDeclaration> (TypeReference=ts.NodeArray)*/ v) noexcept;
	};
	struct _impl_js_jts_dTypeElement : virtual _impl_js_jts_dNamedDeclaration {
		struct _tcjs_definitions {
		};
		auto _typeElementBrand() noexcept;
		void _typeElementBrand(js_unknown v) noexcept;
	};
	struct _impl_js_jts_dCallSignatureDeclaration : virtual _impl_js_jts_dSignatureDeclarationBase, virtual _impl_js_jts_dTypeElement {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.CallSignature*/ v) noexcept;
	};
	struct _impl_js_jts_dConstructSignatureDeclaration : virtual _impl_js_jts_dSignatureDeclarationBase, virtual _impl_js_jts_dTypeElement {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ConstructSignature*/ v) noexcept;
	};
	struct _impl_js_jts_dVariableDeclaration : virtual _impl_js_jts_dNamedDeclaration {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.VariableDeclaration*/ v) noexcept;
		auto parent() noexcept;
		void parent(js_union<_js_jts_dCatchClause, _js_jts_dVariableDeclarationList> v) noexcept;
		auto name() noexcept;
		void name(js_union<_js_jts_dArrayBindingPattern, _js_jts_dIdentifier, _js_jts_dObjectBindingPattern> v) noexcept;
	};
	struct _impl_js_jts_dVariableDeclarationList : virtual _impl_js_jts_dNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.VariableDeclarationList*/ v) noexcept;
		auto parent() noexcept;
		void parent(js_union<_js_jts_dForInStatement, _js_jts_dForOfStatement, _js_jts_dForStatement, _js_jts_dVariableStatement> v) noexcept;
		auto declarations() noexcept;
		void declarations(js_unknown /*flags=524288: NodeArray<VariableDeclaration> (TypeReference=ts.NodeArray)*/ v) noexcept;
	};
	struct _impl_js_jts_dParameterDeclaration : virtual _impl_js_jts_dNamedDeclaration, virtual _impl_js_jts_dJSDocContainer {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.Parameter*/ v) noexcept;
		auto parent() noexcept;
		void parent(js_union<_js_jts_dArrowFunction, _js_jts_dCallSignatureDeclaration, _js_jts_dConstructSignatureDeclaration, _js_jts_dConstructorDeclaration, _js_jts_dConstructorTypeNode, _js_jts_dFunctionDeclaration, _js_jts_dFunctionExpression, _js_jts_dFunctionTypeNode, _js_jts_dGetAccessorDeclaration, _js_jts_dIndexSignatureDeclaration, _js_jts_dJSDocFunctionType, _js_jts_dMethodDeclaration, _js_jts_dMethodSignature, _js_jts_dSetAccessorDeclaration> v) noexcept;
		auto name() noexcept;
		void name(js_union<_js_jts_dArrayBindingPattern, _js_jts_dIdentifier, _js_jts_dObjectBindingPattern> v) noexcept;
	};
	struct _impl_js_jts_dBindingElement : virtual _impl_js_jts_dNamedDeclaration {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.BindingElement*/ v) noexcept;
		auto parent() noexcept;
		void parent(js_union<_js_jts_dArrayBindingPattern, _js_jts_dObjectBindingPattern> v) noexcept;
		auto name() noexcept;
		void name(js_union<_js_jts_dArrayBindingPattern, _js_jts_dIdentifier, _js_jts_dObjectBindingPattern> v) noexcept;
	};
	struct _impl_js_jts_dPropertySignature : virtual _impl_js_jts_dTypeElement, virtual _impl_js_jts_dJSDocContainer {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.PropertySignature*/ v) noexcept;
		auto name() noexcept;
		void name(js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral> v) noexcept;
	};
	struct _impl_js_jts_dClassElement : virtual _impl_js_jts_dNamedDeclaration {
		struct _tcjs_definitions {
		};
		auto _classElementBrand() noexcept;
		void _classElementBrand(js_unknown v) noexcept;
	};
	struct _impl_js_jts_dPropertyDeclaration : virtual _impl_js_jts_dClassElement, virtual _impl_js_jts_dJSDocContainer {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.PropertyDeclaration*/ v) noexcept;
		auto parent() noexcept;
		void parent(js_union<_js_jts_dClassDeclaration, _js_jts_dClassExpression> v) noexcept;
		auto name() noexcept;
		void name(js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral> v) noexcept;
	};
	struct _impl_js_jts_dObjectLiteralElement : virtual _impl_js_jts_dNamedDeclaration {
		struct _tcjs_definitions {
		};
		auto _objectLiteralBrand() noexcept;
		void _objectLiteralBrand(js_unknown v) noexcept;
	};
	struct _impl_js_jts_dPropertyAssignment : virtual _impl_js_jts_dObjectLiteralElement, virtual _impl_js_jts_dJSDocContainer {
		struct _tcjs_definitions {
		};
		auto parent() noexcept;
		void parent(_js_jts_dObjectLiteralExpression v) noexcept;
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.PropertyAssignment*/ v) noexcept;
		auto name() noexcept;
		void name(js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral> v) noexcept;
		auto initializer() noexcept;
		void initializer(_js_jts_dExpression v) noexcept;
	};
	struct _impl_js_jts_dShorthandPropertyAssignment : virtual _impl_js_jts_dObjectLiteralElement, virtual _impl_js_jts_dJSDocContainer {
		struct _tcjs_definitions {
		};
		auto parent() noexcept;
		void parent(_js_jts_dObjectLiteralExpression v) noexcept;
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ShorthandPropertyAssignment*/ v) noexcept;
		auto name() noexcept;
		void name(_js_jts_dIdentifier v) noexcept;
	};
	struct _impl_js_jts_dSpreadAssignment : virtual _impl_js_jts_dObjectLiteralElement, virtual _impl_js_jts_dJSDocContainer {
		struct _tcjs_definitions {
		};
		auto parent() noexcept;
		void parent(_js_jts_dObjectLiteralExpression v) noexcept;
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.SpreadAssignment*/ v) noexcept;
		auto expression() noexcept;
		void expression(_js_jts_dExpression v) noexcept;
	};
	struct _impl_js_jts_dPropertyLikeDeclaration : virtual _impl_js_jts_dNamedDeclaration {
		struct _tcjs_definitions {
		};
		auto name() noexcept;
		void name(js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral> v) noexcept;
	};
	struct _impl_js_jts_dObjectBindingPattern : virtual _impl_js_jts_dNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ObjectBindingPattern*/ v) noexcept;
		auto parent() noexcept;
		void parent(js_union<_js_jts_dBindingElement, _js_jts_dParameterDeclaration, _js_jts_dVariableDeclaration> v) noexcept;
		auto elements() noexcept;
		void elements(js_unknown /*flags=524288: NodeArray<BindingElement> (TypeReference=ts.NodeArray)*/ v) noexcept;
	};
	struct _impl_js_jts_dArrayBindingPattern : virtual _impl_js_jts_dNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ArrayBindingPattern*/ v) noexcept;
		auto parent() noexcept;
		void parent(js_union<_js_jts_dBindingElement, _js_jts_dParameterDeclaration, _js_jts_dVariableDeclaration> v) noexcept;
		auto elements() noexcept;
		void elements(js_unknown /*flags=524288: NodeArray<ArrayBindingElement> (TypeReference=ts.NodeArray)*/ v) noexcept;
	};
	struct _impl_js_jts_dFunctionLikeDeclarationBase : virtual _impl_js_jts_dSignatureDeclarationBase {
		struct _tcjs_definitions {
		};
		auto _functionLikeDeclarationBrand() noexcept;
		void _functionLikeDeclarationBrand(js_unknown v) noexcept;
	};
	struct _impl_js_jts_dFunctionDeclaration : virtual _impl_js_jts_dFunctionLikeDeclarationBase, virtual _impl_js_jts_dDeclarationStatement {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.FunctionDeclaration*/ v) noexcept;
	};
	struct _impl_js_jts_dMethodSignature : virtual _impl_js_jts_dSignatureDeclarationBase, virtual _impl_js_jts_dTypeElement {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.MethodSignature*/ v) noexcept;
		auto parent() noexcept;
		void parent(js_union<_js_jts_dClassDeclaration, _js_jts_dClassExpression, _js_jts_dInterfaceDeclaration, _js_jts_dTypeLiteralNode> v) noexcept;
		auto name() noexcept;
		void name(js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral> v) noexcept;
	};
	struct _impl_js_jts_dMethodDeclaration : virtual _impl_js_jts_dFunctionLikeDeclarationBase, virtual _impl_js_jts_dClassElement, virtual _impl_js_jts_dObjectLiteralElement, virtual _impl_js_jts_dJSDocContainer {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.MethodDeclaration*/ v) noexcept;
		auto parent() noexcept;
		void parent(js_union<_js_jts_dClassDeclaration, _js_jts_dClassExpression, _js_jts_dObjectLiteralExpression> v) noexcept;
		auto name() noexcept;
		void name(js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral> v) noexcept;
	};
	struct _impl_js_jts_dConstructorDeclaration : virtual _impl_js_jts_dFunctionLikeDeclarationBase, virtual _impl_js_jts_dClassElement, virtual _impl_js_jts_dJSDocContainer {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.Constructor*/ v) noexcept;
		auto parent() noexcept;
		void parent(js_union<_js_jts_dClassDeclaration, _js_jts_dClassExpression> v) noexcept;
	};
	struct _impl_js_jts_dSemicolonClassElement : virtual _impl_js_jts_dClassElement {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.SemicolonClassElement*/ v) noexcept;
		auto parent() noexcept;
		void parent(js_union<_js_jts_dClassDeclaration, _js_jts_dClassExpression> v) noexcept;
	};
	struct _impl_js_jts_dGetAccessorDeclaration : virtual _impl_js_jts_dFunctionLikeDeclarationBase, virtual _impl_js_jts_dClassElement, virtual _impl_js_jts_dObjectLiteralElement, virtual _impl_js_jts_dJSDocContainer {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.GetAccessor*/ v) noexcept;
		auto parent() noexcept;
		void parent(js_union<_js_jts_dClassDeclaration, _js_jts_dClassExpression, _js_jts_dObjectLiteralExpression> v) noexcept;
		auto name() noexcept;
		void name(js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral> v) noexcept;
	};
	struct _impl_js_jts_dSetAccessorDeclaration : virtual _impl_js_jts_dFunctionLikeDeclarationBase, virtual _impl_js_jts_dClassElement, virtual _impl_js_jts_dObjectLiteralElement, virtual _impl_js_jts_dJSDocContainer {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.SetAccessor*/ v) noexcept;
		auto parent() noexcept;
		void parent(js_union<_js_jts_dClassDeclaration, _js_jts_dClassExpression, _js_jts_dObjectLiteralExpression> v) noexcept;
		auto name() noexcept;
		void name(js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral> v) noexcept;
	};
	struct _impl_js_jts_dIndexSignatureDeclaration : virtual _impl_js_jts_dSignatureDeclarationBase, virtual _impl_js_jts_dClassElement, virtual _impl_js_jts_dTypeElement {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.IndexSignature*/ v) noexcept;
		auto parent() noexcept;
		void parent(js_union<_js_jts_dClassDeclaration, _js_jts_dClassExpression, _js_jts_dInterfaceDeclaration, _js_jts_dTypeLiteralNode> v) noexcept;
	};
	struct _impl_js_jts_dTypeNode : virtual _impl_js_jts_dNode {
		struct _tcjs_definitions {
		};
		auto _typeNodeBrand() noexcept;
		void _typeNodeBrand(js_unknown v) noexcept;
	};
	struct _impl_js_jts_dKeywordTypeNode : virtual _impl_js_jts_dTypeNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.NullKeyword*/ v) noexcept;
	};
	struct _impl_js_jts_dNodeWithTypeArguments : virtual _impl_js_jts_dTypeNode {
		struct _tcjs_definitions {
		};
	};
	struct _impl_js_jts_dImportTypeNode : virtual _impl_js_jts_dNodeWithTypeArguments {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ImportType*/ v) noexcept;
		auto argument() noexcept;
		void argument(_js_jts_dTypeNode v) noexcept;
	};
	struct _impl_js_jts_dThisTypeNode : virtual _impl_js_jts_dTypeNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ThisType*/ v) noexcept;
	};
	struct _impl_js_jts_dFunctionOrConstructorTypeNodeBase : virtual _impl_js_jts_dTypeNode, virtual _impl_js_jts_dSignatureDeclarationBase {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.FunctionType*/ v) noexcept;
		auto type() noexcept;
		void type(_js_jts_dTypeNode v) noexcept;
	};
	struct _impl_js_jts_dFunctionTypeNode : virtual _impl_js_jts_dFunctionOrConstructorTypeNodeBase {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.FunctionType*/ v) noexcept;
	};
	struct _impl_js_jts_dConstructorTypeNode : virtual _impl_js_jts_dFunctionOrConstructorTypeNodeBase {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ConstructorType*/ v) noexcept;
	};
	struct _impl_js_jts_dTypeReferenceNode : virtual _impl_js_jts_dNodeWithTypeArguments {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.TypeReference*/ v) noexcept;
		auto typeName() noexcept;
		void typeName(js_union<_js_jts_dIdentifier, _js_jts_dQualifiedName> v) noexcept;
	};
	struct _impl_js_jts_dTypePredicateNode : virtual _impl_js_jts_dTypeNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.TypePredicate*/ v) noexcept;
		auto parent() noexcept;
		void parent(js_union<_js_jts_dArrowFunction, _js_jts_dCallSignatureDeclaration, _js_jts_dConstructSignatureDeclaration, _js_jts_dConstructorDeclaration, _js_jts_dConstructorTypeNode, _js_jts_dFunctionDeclaration, _js_jts_dFunctionExpression, _js_jts_dFunctionTypeNode, _js_jts_dGetAccessorDeclaration, _js_jts_dIndexSignatureDeclaration, _js_jts_dJSDocFunctionType, _js_jts_dJSDocTypeExpression, _js_jts_dMethodDeclaration, _js_jts_dMethodSignature, _js_jts_dSetAccessorDeclaration> v) noexcept;
		auto parameterName() noexcept;
		void parameterName(js_union<_js_jts_dIdentifier, _js_jts_dThisTypeNode> v) noexcept;
		auto type() noexcept;
		void type(_js_jts_dTypeNode v) noexcept;
	};
	struct _impl_js_jts_dTypeQueryNode : virtual _impl_js_jts_dTypeNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.TypeQuery*/ v) noexcept;
		auto exprName() noexcept;
		void exprName(js_union<_js_jts_dIdentifier, _js_jts_dQualifiedName> v) noexcept;
	};
	struct _impl_js_jts_dTypeLiteralNode : virtual _impl_js_jts_dTypeNode, virtual _impl_js_jts_dDeclaration {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.TypeLiteral*/ v) noexcept;
		auto members() noexcept;
		void members(js_unknown /*flags=524288: NodeArray<TypeElement> (TypeReference=ts.NodeArray)*/ v) noexcept;
	};
	struct _impl_js_jts_dArrayTypeNode : virtual _impl_js_jts_dTypeNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ArrayType*/ v) noexcept;
		auto elementType() noexcept;
		void elementType(_js_jts_dTypeNode v) noexcept;
	};
	struct _impl_js_jts_dTupleTypeNode : virtual _impl_js_jts_dTypeNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.TupleType*/ v) noexcept;
		auto elementTypes() noexcept;
		void elementTypes(js_unknown /*flags=524288: NodeArray<TypeNode> (TypeReference=ts.NodeArray)*/ v) noexcept;
	};
	struct _impl_js_jts_dOptionalTypeNode : virtual _impl_js_jts_dTypeNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.OptionalType*/ v) noexcept;
		auto type() noexcept;
		void type(_js_jts_dTypeNode v) noexcept;
	};
	struct _impl_js_jts_dRestTypeNode : virtual _impl_js_jts_dTypeNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.RestType*/ v) noexcept;
		auto type() noexcept;
		void type(_js_jts_dTypeNode v) noexcept;
	};
	struct _impl_js_jts_dUnionTypeNode : virtual _impl_js_jts_dTypeNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.UnionType*/ v) noexcept;
		auto types() noexcept;
		void types(js_unknown /*flags=524288: NodeArray<TypeNode> (TypeReference=ts.NodeArray)*/ v) noexcept;
	};
	struct _impl_js_jts_dIntersectionTypeNode : virtual _impl_js_jts_dTypeNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.IntersectionType*/ v) noexcept;
		auto types() noexcept;
		void types(js_unknown /*flags=524288: NodeArray<TypeNode> (TypeReference=ts.NodeArray)*/ v) noexcept;
	};
	struct _impl_js_jts_dConditionalTypeNode : virtual _impl_js_jts_dTypeNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ConditionalType*/ v) noexcept;
		auto checkType() noexcept;
		void checkType(_js_jts_dTypeNode v) noexcept;
		auto extendsType() noexcept;
		void extendsType(_js_jts_dTypeNode v) noexcept;
		auto trueType() noexcept;
		void trueType(_js_jts_dTypeNode v) noexcept;
		auto falseType() noexcept;
		void falseType(_js_jts_dTypeNode v) noexcept;
	};
	struct _impl_js_jts_dInferTypeNode : virtual _impl_js_jts_dTypeNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.InferType*/ v) noexcept;
		auto typeParameter() noexcept;
		void typeParameter(_js_jts_dTypeParameterDeclaration v) noexcept;
	};
	struct _impl_js_jts_dParenthesizedTypeNode : virtual _impl_js_jts_dTypeNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ParenthesizedType*/ v) noexcept;
		auto type() noexcept;
		void type(_js_jts_dTypeNode v) noexcept;
	};
	struct _impl_js_jts_dTypeOperatorNode : virtual _impl_js_jts_dTypeNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.TypeOperator*/ v) noexcept;
		auto operator_() noexcept;
		void operator_(_js_jts_dSyntaxKind /*SyntaxKind.KeyOfKeyword*/ v) noexcept;
		auto type() noexcept;
		void type(_js_jts_dTypeNode v) noexcept;
	};
	struct _impl_js_jts_dIndexedAccessTypeNode : virtual _impl_js_jts_dTypeNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.IndexedAccessType*/ v) noexcept;
		auto objectType() noexcept;
		void objectType(_js_jts_dTypeNode v) noexcept;
		auto indexType() noexcept;
		void indexType(_js_jts_dTypeNode v) noexcept;
	};
	struct _impl_js_jts_dMappedTypeNode : virtual _impl_js_jts_dTypeNode, virtual _impl_js_jts_dDeclaration {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.MappedType*/ v) noexcept;
		auto typeParameter() noexcept;
		void typeParameter(_js_jts_dTypeParameterDeclaration v) noexcept;
	};
	struct _impl_js_jts_dLiteralTypeNode : virtual _impl_js_jts_dTypeNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.LiteralType*/ v) noexcept;
		auto literal() noexcept;
		void literal(js_union<_js_jts_dBooleanLiteral, _js_jts_dLiteralExpression, _js_jts_dPrefixUnaryExpression> v) noexcept;
	};
	struct _impl_js_jts_dLiteralLikeNode : virtual _impl_js_jts_dNode {
		struct _tcjs_definitions {
		};
		auto text() noexcept;
		void text(js_string v) noexcept;
	};
	struct _impl_js_jts_dLiteralExpression : virtual _impl_js_jts_dLiteralLikeNode, virtual _impl_js_jts_dPrimaryExpression {
		struct _tcjs_definitions {
		};
		auto _literalExpressionBrand() noexcept;
		void _literalExpressionBrand(js_unknown v) noexcept;
	};
	struct _impl_js_jts_dStringLiteral : virtual _impl_js_jts_dLiteralExpression {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.StringLiteral*/ v) noexcept;
	};
	struct _impl_js_jts_dOmittedExpression : virtual _impl_js_jts_dExpression {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.OmittedExpression*/ v) noexcept;
	};
	struct _impl_js_jts_dPartiallyEmittedExpression : virtual _impl_js_jts_dLeftHandSideExpression {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.PartiallyEmittedExpression*/ v) noexcept;
		auto expression() noexcept;
		void expression(_js_jts_dExpression v) noexcept;
	};
	struct _impl_js_jts_dPrefixUnaryExpression : virtual _impl_js_jts_dUpdateExpression {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.PrefixUnaryExpression*/ v) noexcept;
		auto operator_() noexcept;
		void operator_(_js_jts_dSyntaxKind /*SyntaxKind.PlusToken*/ v) noexcept;
		auto operand() noexcept;
		void operand(_js_jts_dUnaryExpression v) noexcept;
	};
	struct _impl_js_jts_dPostfixUnaryExpression : virtual _impl_js_jts_dUpdateExpression {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.PostfixUnaryExpression*/ v) noexcept;
		auto operand() noexcept;
		void operand(_js_jts_dLeftHandSideExpression v) noexcept;
		auto operator_() noexcept;
		void operator_(_js_jts_dSyntaxKind /*SyntaxKind.PlusPlusToken*/ v) noexcept;
	};
	struct _impl_js_jts_dNullLiteral : virtual _impl_js_jts_dPrimaryExpression, virtual _impl_js_jts_dTypeNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.NullKeyword*/ v) noexcept;
	};
	struct _impl_js_jts_dBooleanLiteral : virtual _impl_js_jts_dPrimaryExpression, virtual _impl_js_jts_dTypeNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.FalseKeyword*/ v) noexcept;
	};
	struct _impl_js_jts_dThisExpression : virtual _impl_js_jts_dPrimaryExpression, virtual _impl_js_jts_dKeywordTypeNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ThisKeyword*/ v) noexcept;
	};
	struct _impl_js_jts_dSuperExpression : virtual _impl_js_jts_dPrimaryExpression {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.SuperKeyword*/ v) noexcept;
	};
	struct _impl_js_jts_dImportExpression : virtual _impl_js_jts_dPrimaryExpression {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ImportKeyword*/ v) noexcept;
	};
	struct _impl_js_jts_dDeleteExpression : virtual _impl_js_jts_dUnaryExpression {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.DeleteExpression*/ v) noexcept;
		auto expression() noexcept;
		void expression(_js_jts_dUnaryExpression v) noexcept;
	};
	struct _impl_js_jts_dTypeOfExpression : virtual _impl_js_jts_dUnaryExpression {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.TypeOfExpression*/ v) noexcept;
		auto expression() noexcept;
		void expression(_js_jts_dUnaryExpression v) noexcept;
	};
	struct _impl_js_jts_dVoidExpression : virtual _impl_js_jts_dUnaryExpression {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.VoidExpression*/ v) noexcept;
		auto expression() noexcept;
		void expression(_js_jts_dUnaryExpression v) noexcept;
	};
	struct _impl_js_jts_dAwaitExpression : virtual _impl_js_jts_dUnaryExpression {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.AwaitExpression*/ v) noexcept;
		auto expression() noexcept;
		void expression(_js_jts_dUnaryExpression v) noexcept;
	};
	struct _impl_js_jts_dYieldExpression : virtual _impl_js_jts_dExpression {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.YieldExpression*/ v) noexcept;
	};
	struct _impl_js_jts_dSyntheticExpression : virtual _impl_js_jts_dExpression {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.SyntheticExpression*/ v) noexcept;
		auto isSpread() noexcept;
		void isSpread(bool /*false*/ v) noexcept;
		auto type() noexcept;
		void type(_js_jts_dType v) noexcept;
	};
	struct _impl_js_jts_dBinaryExpression : virtual _impl_js_jts_dExpression, virtual _impl_js_jts_dDeclaration {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.BinaryExpression*/ v) noexcept;
		auto left() noexcept;
		void left(_js_jts_dExpression v) noexcept;
		auto operatorToken() noexcept;
		void operatorToken(js_unknown /*flags=524288: Token<BinaryOperator> (TypeReference=ts.Token)*/ v) noexcept;
		auto right() noexcept;
		void right(_js_jts_dExpression v) noexcept;
	};
	struct _impl_js_jts_dAssignmentExpression : virtual _impl_js_jts_dBinaryExpression {
		struct _tcjs_definitions {
		};
		auto left() noexcept;
		void left(_js_jts_dLeftHandSideExpression v) noexcept;
		auto operatorToken() noexcept;
		void operatorToken(js_unknown /*flags=262144: TOperator ()*/ v) noexcept;
	};
	struct _impl_js_jts_dObjectDestructuringAssignment : virtual IObject {
		struct _tcjs_definitions {
		};
		auto left() noexcept;
		void left(_js_jts_dObjectLiteralExpression v) noexcept;
	};
	struct _impl_js_jts_dArrayDestructuringAssignment : virtual IObject {
		struct _tcjs_definitions {
		};
		auto left() noexcept;
		void left(_js_jts_dArrayLiteralExpression v) noexcept;
	};
	struct _impl_js_jts_dConditionalExpression : virtual _impl_js_jts_dExpression {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ConditionalExpression*/ v) noexcept;
		auto condition() noexcept;
		void condition(_js_jts_dExpression v) noexcept;
		auto questionToken() noexcept;
		void questionToken(js_unknown /*flags=524288: Token<SyntaxKind.QuestionToken> (TypeReference=ts.Token)*/ v) noexcept;
		auto whenTrue() noexcept;
		void whenTrue(_js_jts_dExpression v) noexcept;
		auto colonToken() noexcept;
		void colonToken(js_unknown /*flags=524288: Token<SyntaxKind.ColonToken> (TypeReference=ts.Token)*/ v) noexcept;
		auto whenFalse() noexcept;
		void whenFalse(_js_jts_dExpression v) noexcept;
	};
	struct _impl_js_jts_dFunctionExpression : virtual _impl_js_jts_dPrimaryExpression, virtual _impl_js_jts_dFunctionLikeDeclarationBase, virtual _impl_js_jts_dJSDocContainer {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.FunctionExpression*/ v) noexcept;
		auto body() noexcept;
		void body(_js_jts_dBlock v) noexcept;
	};
	struct _impl_js_jts_dArrowFunction : virtual _impl_js_jts_dExpression, virtual _impl_js_jts_dFunctionLikeDeclarationBase, virtual _impl_js_jts_dJSDocContainer {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ArrowFunction*/ v) noexcept;
		auto equalsGreaterThanToken() noexcept;
		void equalsGreaterThanToken(js_unknown /*flags=524288: Token<SyntaxKind.EqualsGreaterThanToken> (TypeReference=ts.Token)*/ v) noexcept;
		auto body() noexcept;
		void body(js_union<_js_jts_dBlock, _js_jts_dExpression> v) noexcept;
		auto name() noexcept;
		void name(js_unknown /*flags=131072: never ()*/ v) noexcept;
	};
	struct _impl_js_jts_dRegularExpressionLiteral : virtual _impl_js_jts_dLiteralExpression {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.RegularExpressionLiteral*/ v) noexcept;
	};
	struct _impl_js_jts_dNoSubstitutionTemplateLiteral : virtual _impl_js_jts_dLiteralExpression {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.NoSubstitutionTemplateLiteral*/ v) noexcept;
	};
	struct _impl_js_jts_dNumericLiteral : virtual _impl_js_jts_dLiteralExpression {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.NumericLiteral*/ v) noexcept;
	};
	struct _impl_js_jts_dBigIntLiteral : virtual _impl_js_jts_dLiteralExpression {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.BigIntLiteral*/ v) noexcept;
	};
	struct _impl_js_jts_dTemplateHead : virtual _impl_js_jts_dLiteralLikeNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.TemplateHead*/ v) noexcept;
		auto parent() noexcept;
		void parent(_js_jts_dTemplateExpression v) noexcept;
	};
	struct _impl_js_jts_dTemplateMiddle : virtual _impl_js_jts_dLiteralLikeNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.TemplateMiddle*/ v) noexcept;
		auto parent() noexcept;
		void parent(_js_jts_dTemplateSpan v) noexcept;
	};
	struct _impl_js_jts_dTemplateTail : virtual _impl_js_jts_dLiteralLikeNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.TemplateTail*/ v) noexcept;
		auto parent() noexcept;
		void parent(_js_jts_dTemplateSpan v) noexcept;
	};
	struct _impl_js_jts_dTemplateExpression : virtual _impl_js_jts_dPrimaryExpression {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.TemplateExpression*/ v) noexcept;
		auto head() noexcept;
		void head(_js_jts_dTemplateHead v) noexcept;
		auto templateSpans() noexcept;
		void templateSpans(js_unknown /*flags=524288: NodeArray<TemplateSpan> (TypeReference=ts.NodeArray)*/ v) noexcept;
	};
	struct _impl_js_jts_dTemplateSpan : virtual _impl_js_jts_dNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.TemplateSpan*/ v) noexcept;
		auto parent() noexcept;
		void parent(_js_jts_dTemplateExpression v) noexcept;
		auto expression() noexcept;
		void expression(_js_jts_dExpression v) noexcept;
		auto literal() noexcept;
		void literal(js_union<_js_jts_dTemplateMiddle, _js_jts_dTemplateTail> v) noexcept;
	};
	struct _impl_js_jts_dParenthesizedExpression : virtual _impl_js_jts_dPrimaryExpression, virtual _impl_js_jts_dJSDocContainer {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ParenthesizedExpression*/ v) noexcept;
		auto expression() noexcept;
		void expression(_js_jts_dExpression v) noexcept;
	};
	struct _impl_js_jts_dArrayLiteralExpression : virtual _impl_js_jts_dPrimaryExpression {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ArrayLiteralExpression*/ v) noexcept;
		auto elements() noexcept;
		void elements(js_unknown /*flags=524288: NodeArray<Expression> (TypeReference=ts.NodeArray)*/ v) noexcept;
	};
	struct _impl_js_jts_dSpreadElement : virtual _impl_js_jts_dExpression {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.SpreadElement*/ v) noexcept;
		auto parent() noexcept;
		void parent(js_union<_js_jts_dArrayLiteralExpression, _js_jts_dCallExpression, _js_jts_dNewExpression> v) noexcept;
		auto expression() noexcept;
		void expression(_js_jts_dExpression v) noexcept;
	};
	struct _impl_js_jts_dObjectLiteralExpressionBase : virtual _impl_js_jts_dPrimaryExpression, virtual _impl_js_jts_dDeclaration {
		struct _tcjs_definitions {
		};
		auto properties() noexcept;
		void properties(js_unknown /*flags=524288: NodeArray<T> (TypeReference=ts.NodeArray)*/ v) noexcept;
	};
	struct _impl_js_jts_dObjectLiteralExpression : virtual IObject {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ObjectLiteralExpression*/ v) noexcept;
	};
	struct _impl_js_jts_dPropertyAccessExpression : virtual _impl_js_jts_dMemberExpression, virtual _impl_js_jts_dNamedDeclaration {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.PropertyAccessExpression*/ v) noexcept;
		auto expression() noexcept;
		void expression(_js_jts_dLeftHandSideExpression v) noexcept;
		auto name() noexcept;
		void name(_js_jts_dIdentifier v) noexcept;
	};
	struct _impl_js_jts_dSuperPropertyAccessExpression : virtual _impl_js_jts_dPropertyAccessExpression {
		struct _tcjs_definitions {
		};
		auto expression() noexcept;
		void expression(_js_jts_dSuperExpression v) noexcept;
	};
	struct _impl_js_jts_dPropertyAccessEntityNameExpression : virtual _impl_js_jts_dPropertyAccessExpression {
		struct _tcjs_definitions {
		};
		auto expression() noexcept;
		void expression(js_union<_js_jts_dIdentifier, _js_jts_dPropertyAccessEntityNameExpression> v) noexcept;
	};
	struct _impl_js_jts_dElementAccessExpression : virtual _impl_js_jts_dMemberExpression {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ElementAccessExpression*/ v) noexcept;
		auto expression() noexcept;
		void expression(_js_jts_dLeftHandSideExpression v) noexcept;
		auto argumentExpression() noexcept;
		void argumentExpression(_js_jts_dExpression v) noexcept;
	};
	struct _impl_js_jts_dSuperElementAccessExpression : virtual _impl_js_jts_dElementAccessExpression {
		struct _tcjs_definitions {
		};
		auto expression() noexcept;
		void expression(_js_jts_dSuperExpression v) noexcept;
	};
	struct _impl_js_jts_dCallExpression : virtual _impl_js_jts_dLeftHandSideExpression, virtual _impl_js_jts_dDeclaration {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.CallExpression*/ v) noexcept;
		auto expression() noexcept;
		void expression(_js_jts_dLeftHandSideExpression v) noexcept;
		auto arguments() noexcept;
		void arguments(js_unknown /*flags=524288: NodeArray<Expression> (TypeReference=ts.NodeArray)*/ v) noexcept;
	};
	struct _impl_js_jts_dSuperCall : virtual _impl_js_jts_dCallExpression {
		struct _tcjs_definitions {
		};
		auto expression() noexcept;
		void expression(_js_jts_dSuperExpression v) noexcept;
	};
	struct _impl_js_jts_dImportCall : virtual _impl_js_jts_dCallExpression {
		struct _tcjs_definitions {
		};
		auto expression() noexcept;
		void expression(_js_jts_dImportExpression v) noexcept;
	};
	struct _impl_js_jts_dExpressionWithTypeArguments : virtual _impl_js_jts_dNodeWithTypeArguments {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ExpressionWithTypeArguments*/ v) noexcept;
		auto parent() noexcept;
		void parent(js_union<_js_jts_dHeritageClause, _js_jts_dJSDocAugmentsTag> v) noexcept;
		auto expression() noexcept;
		void expression(_js_jts_dLeftHandSideExpression v) noexcept;
	};
	struct _impl_js_jts_dNewExpression : virtual _impl_js_jts_dPrimaryExpression, virtual _impl_js_jts_dDeclaration {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.NewExpression*/ v) noexcept;
		auto expression() noexcept;
		void expression(_js_jts_dLeftHandSideExpression v) noexcept;
	};
	struct _impl_js_jts_dTaggedTemplateExpression : virtual _impl_js_jts_dMemberExpression {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.TaggedTemplateExpression*/ v) noexcept;
		auto tag() noexcept;
		void tag(_js_jts_dLeftHandSideExpression v) noexcept;
		auto template_() noexcept;
		void template_(js_union<_js_jts_dNoSubstitutionTemplateLiteral, _js_jts_dTemplateExpression> v) noexcept;
	};
	struct _impl_js_jts_dAsExpression : virtual _impl_js_jts_dExpression {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.AsExpression*/ v) noexcept;
		auto expression() noexcept;
		void expression(_js_jts_dExpression v) noexcept;
		auto type() noexcept;
		void type(_js_jts_dTypeNode v) noexcept;
	};
	struct _impl_js_jts_dTypeAssertion : virtual _impl_js_jts_dUnaryExpression {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.TypeAssertionExpression*/ v) noexcept;
		auto type() noexcept;
		void type(_js_jts_dTypeNode v) noexcept;
		auto expression() noexcept;
		void expression(_js_jts_dUnaryExpression v) noexcept;
	};
	struct _impl_js_jts_dNonNullExpression : virtual _impl_js_jts_dLeftHandSideExpression {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.NonNullExpression*/ v) noexcept;
		auto expression() noexcept;
		void expression(_js_jts_dExpression v) noexcept;
	};
	struct _impl_js_jts_dMetaProperty : virtual _impl_js_jts_dPrimaryExpression {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.MetaProperty*/ v) noexcept;
		auto keywordToken() noexcept;
		void keywordToken(_js_jts_dSyntaxKind /*SyntaxKind.ImportKeyword*/ v) noexcept;
		auto name() noexcept;
		void name(_js_jts_dIdentifier v) noexcept;
	};
	struct _impl_js_jts_dJsxElement : virtual _impl_js_jts_dPrimaryExpression {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.JsxElement*/ v) noexcept;
		auto openingElement() noexcept;
		void openingElement(_js_jts_dJsxOpeningElement v) noexcept;
		auto children() noexcept;
		void children(js_unknown /*flags=524288: NodeArray<JsxChild> (TypeReference=ts.NodeArray)*/ v) noexcept;
		auto closingElement() noexcept;
		void closingElement(_js_jts_dJsxClosingElement v) noexcept;
	};
	struct _impl_js_jts_dJsxTagNamePropertyAccess : virtual _impl_js_jts_dPropertyAccessExpression {
		struct _tcjs_definitions {
		};
		auto expression() noexcept;
		void expression(js_union<_js_jts_dIdentifier, _js_jts_dJsxTagNamePropertyAccess, _js_jts_dThisExpression> v) noexcept;
	};
	struct _impl_js_jts_dJsxAttributes : virtual IObject {
		struct _tcjs_definitions {
		};
		auto parent() noexcept;
		void parent(js_union<_js_jts_dJsxOpeningElement, _js_jts_dJsxSelfClosingElement> v) noexcept;
	};
	struct _impl_js_jts_dJsxOpeningElement : virtual _impl_js_jts_dExpression {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.JsxOpeningElement*/ v) noexcept;
		auto parent() noexcept;
		void parent(_js_jts_dJsxElement v) noexcept;
		auto tagName() noexcept;
		void tagName(js_union<_js_jts_dIdentifier, _js_jts_dJsxTagNamePropertyAccess, _js_jts_dThisExpression> v) noexcept;
		auto attributes() noexcept;
		void attributes(_js_jts_dJsxAttributes v) noexcept;
	};
	struct _impl_js_jts_dJsxSelfClosingElement : virtual _impl_js_jts_dPrimaryExpression {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.JsxSelfClosingElement*/ v) noexcept;
		auto tagName() noexcept;
		void tagName(js_union<_js_jts_dIdentifier, _js_jts_dJsxTagNamePropertyAccess, _js_jts_dThisExpression> v) noexcept;
		auto attributes() noexcept;
		void attributes(_js_jts_dJsxAttributes v) noexcept;
	};
	struct _impl_js_jts_dJsxFragment : virtual _impl_js_jts_dPrimaryExpression {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.JsxFragment*/ v) noexcept;
		auto openingFragment() noexcept;
		void openingFragment(_js_jts_dJsxOpeningFragment v) noexcept;
		auto children() noexcept;
		void children(js_unknown /*flags=524288: NodeArray<JsxChild> (TypeReference=ts.NodeArray)*/ v) noexcept;
		auto closingFragment() noexcept;
		void closingFragment(_js_jts_dJsxClosingFragment v) noexcept;
	};
	struct _impl_js_jts_dJsxOpeningFragment : virtual _impl_js_jts_dExpression {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.JsxOpeningFragment*/ v) noexcept;
		auto parent() noexcept;
		void parent(_js_jts_dJsxFragment v) noexcept;
	};
	struct _impl_js_jts_dJsxClosingFragment : virtual _impl_js_jts_dExpression {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.JsxClosingFragment*/ v) noexcept;
		auto parent() noexcept;
		void parent(_js_jts_dJsxFragment v) noexcept;
	};
	struct _impl_js_jts_dJsxAttribute : virtual _impl_js_jts_dObjectLiteralElement {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.JsxAttribute*/ v) noexcept;
		auto parent() noexcept;
		void parent(_js_jts_dJsxAttributes v) noexcept;
		auto name() noexcept;
		void name(_js_jts_dIdentifier v) noexcept;
	};
	struct _impl_js_jts_dJsxSpreadAttribute : virtual _impl_js_jts_dObjectLiteralElement {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.JsxSpreadAttribute*/ v) noexcept;
		auto parent() noexcept;
		void parent(_js_jts_dJsxAttributes v) noexcept;
		auto expression() noexcept;
		void expression(_js_jts_dExpression v) noexcept;
	};
	struct _impl_js_jts_dJsxClosingElement : virtual _impl_js_jts_dNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.JsxClosingElement*/ v) noexcept;
		auto parent() noexcept;
		void parent(_js_jts_dJsxElement v) noexcept;
		auto tagName() noexcept;
		void tagName(js_union<_js_jts_dIdentifier, _js_jts_dJsxTagNamePropertyAccess, _js_jts_dThisExpression> v) noexcept;
	};
	struct _impl_js_jts_dJsxExpression : virtual _impl_js_jts_dExpression {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.JsxExpression*/ v) noexcept;
		auto parent() noexcept;
		void parent(js_union<_js_jts_dJsxAttribute, _js_jts_dJsxElement, _js_jts_dJsxSpreadAttribute> v) noexcept;
	};
	struct _impl_js_jts_dJsxText : virtual _impl_js_jts_dLiteralLikeNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.JsxText*/ v) noexcept;
		auto containsOnlyTriviaWhiteSpaces() noexcept;
		void containsOnlyTriviaWhiteSpaces(bool /*false*/ v) noexcept;
		auto parent() noexcept;
		void parent(_js_jts_dJsxElement v) noexcept;
	};
	struct _impl_js_jts_dNotEmittedStatement : virtual _impl_js_jts_dStatement {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.NotEmittedStatement*/ v) noexcept;
	};
	struct _impl_js_jts_dCommaListExpression : virtual _impl_js_jts_dExpression {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.CommaListExpression*/ v) noexcept;
		auto elements() noexcept;
		void elements(js_unknown /*flags=524288: NodeArray<Expression> (TypeReference=ts.NodeArray)*/ v) noexcept;
	};
	struct _impl_js_jts_dEmptyStatement : virtual _impl_js_jts_dStatement {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.EmptyStatement*/ v) noexcept;
	};
	struct _impl_js_jts_dDebuggerStatement : virtual _impl_js_jts_dStatement {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.DebuggerStatement*/ v) noexcept;
	};
	struct _impl_js_jts_dMissingDeclaration : virtual _impl_js_jts_dDeclarationStatement {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.MissingDeclaration*/ v) noexcept;
	};
	struct _impl_js_jts_dBlock : virtual _impl_js_jts_dStatement {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.Block*/ v) noexcept;
		auto statements() noexcept;
		void statements(js_unknown /*flags=524288: NodeArray<Statement> (TypeReference=ts.NodeArray)*/ v) noexcept;
	};
	struct _impl_js_jts_dVariableStatement : virtual _impl_js_jts_dStatement, virtual _impl_js_jts_dJSDocContainer {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.VariableStatement*/ v) noexcept;
		auto declarationList() noexcept;
		void declarationList(_js_jts_dVariableDeclarationList v) noexcept;
	};
	struct _impl_js_jts_dExpressionStatement : virtual _impl_js_jts_dStatement, virtual _impl_js_jts_dJSDocContainer {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ExpressionStatement*/ v) noexcept;
		auto expression() noexcept;
		void expression(_js_jts_dExpression v) noexcept;
	};
	struct _impl_js_jts_dIfStatement : virtual _impl_js_jts_dStatement {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.IfStatement*/ v) noexcept;
		auto expression() noexcept;
		void expression(_js_jts_dExpression v) noexcept;
		auto thenStatement() noexcept;
		void thenStatement(_js_jts_dStatement v) noexcept;
	};
	struct _impl_js_jts_dIterationStatement : virtual _impl_js_jts_dStatement {
		struct _tcjs_definitions {
		};
		auto statement() noexcept;
		void statement(_js_jts_dStatement v) noexcept;
	};
	struct _impl_js_jts_dDoStatement : virtual _impl_js_jts_dIterationStatement {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.DoStatement*/ v) noexcept;
		auto expression() noexcept;
		void expression(_js_jts_dExpression v) noexcept;
	};
	struct _impl_js_jts_dWhileStatement : virtual _impl_js_jts_dIterationStatement {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.WhileStatement*/ v) noexcept;
		auto expression() noexcept;
		void expression(_js_jts_dExpression v) noexcept;
	};
	struct _impl_js_jts_dForStatement : virtual _impl_js_jts_dIterationStatement {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ForStatement*/ v) noexcept;
	};
	struct _impl_js_jts_dForInStatement : virtual _impl_js_jts_dIterationStatement {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ForInStatement*/ v) noexcept;
		auto initializer() noexcept;
		void initializer(js_union<_js_jts_dExpression, _js_jts_dVariableDeclarationList> v) noexcept;
		auto expression() noexcept;
		void expression(_js_jts_dExpression v) noexcept;
	};
	struct _impl_js_jts_dForOfStatement : virtual _impl_js_jts_dIterationStatement {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ForOfStatement*/ v) noexcept;
		auto initializer() noexcept;
		void initializer(js_union<_js_jts_dExpression, _js_jts_dVariableDeclarationList> v) noexcept;
		auto expression() noexcept;
		void expression(_js_jts_dExpression v) noexcept;
	};
	struct _impl_js_jts_dBreakStatement : virtual _impl_js_jts_dStatement {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.BreakStatement*/ v) noexcept;
	};
	struct _impl_js_jts_dContinueStatement : virtual _impl_js_jts_dStatement {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ContinueStatement*/ v) noexcept;
	};
	struct _impl_js_jts_dReturnStatement : virtual _impl_js_jts_dStatement {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ReturnStatement*/ v) noexcept;
	};
	struct _impl_js_jts_dWithStatement : virtual _impl_js_jts_dStatement {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.WithStatement*/ v) noexcept;
		auto expression() noexcept;
		void expression(_js_jts_dExpression v) noexcept;
		auto statement() noexcept;
		void statement(_js_jts_dStatement v) noexcept;
	};
	struct _impl_js_jts_dSwitchStatement : virtual _impl_js_jts_dStatement {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.SwitchStatement*/ v) noexcept;
		auto expression() noexcept;
		void expression(_js_jts_dExpression v) noexcept;
		auto caseBlock() noexcept;
		void caseBlock(_js_jts_dCaseBlock v) noexcept;
	};
	struct _impl_js_jts_dCaseBlock : virtual _impl_js_jts_dNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.CaseBlock*/ v) noexcept;
		auto parent() noexcept;
		void parent(_js_jts_dSwitchStatement v) noexcept;
		auto clauses() noexcept;
		void clauses(js_unknown /*flags=524288: NodeArray<CaseOrDefaultClause> (TypeReference=ts.NodeArray)*/ v) noexcept;
	};
	struct _impl_js_jts_dCaseClause : virtual _impl_js_jts_dNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.CaseClause*/ v) noexcept;
		auto parent() noexcept;
		void parent(_js_jts_dCaseBlock v) noexcept;
		auto expression() noexcept;
		void expression(_js_jts_dExpression v) noexcept;
		auto statements() noexcept;
		void statements(js_unknown /*flags=524288: NodeArray<Statement> (TypeReference=ts.NodeArray)*/ v) noexcept;
	};
	struct _impl_js_jts_dDefaultClause : virtual _impl_js_jts_dNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.DefaultClause*/ v) noexcept;
		auto parent() noexcept;
		void parent(_js_jts_dCaseBlock v) noexcept;
		auto statements() noexcept;
		void statements(js_unknown /*flags=524288: NodeArray<Statement> (TypeReference=ts.NodeArray)*/ v) noexcept;
	};
	struct _impl_js_jts_dLabeledStatement : virtual _impl_js_jts_dStatement, virtual _impl_js_jts_dJSDocContainer {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.LabeledStatement*/ v) noexcept;
		auto label() noexcept;
		void label(_js_jts_dIdentifier v) noexcept;
		auto statement() noexcept;
		void statement(_js_jts_dStatement v) noexcept;
	};
	struct _impl_js_jts_dThrowStatement : virtual _impl_js_jts_dStatement {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ThrowStatement*/ v) noexcept;
	};
	struct _impl_js_jts_dTryStatement : virtual _impl_js_jts_dStatement {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.TryStatement*/ v) noexcept;
		auto tryBlock() noexcept;
		void tryBlock(_js_jts_dBlock v) noexcept;
	};
	struct _impl_js_jts_dCatchClause : virtual _impl_js_jts_dNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.CatchClause*/ v) noexcept;
		auto parent() noexcept;
		void parent(_js_jts_dTryStatement v) noexcept;
		auto block() noexcept;
		void block(_js_jts_dBlock v) noexcept;
	};
	struct _impl_js_jts_dClassLikeDeclarationBase : virtual _impl_js_jts_dNamedDeclaration, virtual _impl_js_jts_dJSDocContainer {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ClassExpression*/ v) noexcept;
		auto members() noexcept;
		void members(js_unknown /*flags=524288: NodeArray<ClassElement> (TypeReference=ts.NodeArray)*/ v) noexcept;
	};
	struct _impl_js_jts_dClassDeclaration : virtual _impl_js_jts_dClassLikeDeclarationBase, virtual _impl_js_jts_dDeclarationStatement {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ClassDeclaration*/ v) noexcept;
	};
	struct _impl_js_jts_dClassExpression : virtual _impl_js_jts_dClassLikeDeclarationBase, virtual _impl_js_jts_dPrimaryExpression {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ClassExpression*/ v) noexcept;
	};
	struct _impl_js_jts_dInterfaceDeclaration : virtual _impl_js_jts_dDeclarationStatement, virtual _impl_js_jts_dJSDocContainer {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.InterfaceDeclaration*/ v) noexcept;
		auto name() noexcept;
		void name(_js_jts_dIdentifier v) noexcept;
		auto members() noexcept;
		void members(js_unknown /*flags=524288: NodeArray<TypeElement> (TypeReference=ts.NodeArray)*/ v) noexcept;
	};
	struct _impl_js_jts_dHeritageClause : virtual _impl_js_jts_dNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.HeritageClause*/ v) noexcept;
		auto parent() noexcept;
		void parent(js_union<_js_jts_dClassDeclaration, _js_jts_dClassExpression, _js_jts_dInterfaceDeclaration> v) noexcept;
		auto token() noexcept;
		void token(_js_jts_dSyntaxKind /*SyntaxKind.ExtendsKeyword*/ v) noexcept;
		auto types() noexcept;
		void types(js_unknown /*flags=524288: NodeArray<ExpressionWithTypeArguments> (TypeReference=ts.NodeArray)*/ v) noexcept;
	};
	struct _impl_js_jts_dTypeAliasDeclaration : virtual _impl_js_jts_dDeclarationStatement, virtual _impl_js_jts_dJSDocContainer {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.TypeAliasDeclaration*/ v) noexcept;
		auto name() noexcept;
		void name(_js_jts_dIdentifier v) noexcept;
		auto type() noexcept;
		void type(_js_jts_dTypeNode v) noexcept;
	};
	struct _impl_js_jts_dEnumMember : virtual _impl_js_jts_dNamedDeclaration, virtual _impl_js_jts_dJSDocContainer {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.EnumMember*/ v) noexcept;
		auto parent() noexcept;
		void parent(_js_jts_dEnumDeclaration v) noexcept;
		auto name() noexcept;
		void name(js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral> v) noexcept;
	};
	struct _impl_js_jts_dEnumDeclaration : virtual _impl_js_jts_dDeclarationStatement, virtual _impl_js_jts_dJSDocContainer {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.EnumDeclaration*/ v) noexcept;
		auto name() noexcept;
		void name(_js_jts_dIdentifier v) noexcept;
		auto members() noexcept;
		void members(js_unknown /*flags=524288: NodeArray<EnumMember> (TypeReference=ts.NodeArray)*/ v) noexcept;
	};
	struct _impl_js_jts_dModuleDeclaration : virtual _impl_js_jts_dDeclarationStatement, virtual _impl_js_jts_dJSDocContainer {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ModuleDeclaration*/ v) noexcept;
		auto parent() noexcept;
		void parent(js_union<_js_jts_dIdentifier, _js_jts_dJSDocNamespaceDeclaration, _js_jts_dModuleBlock, _js_jts_dNamespaceDeclaration, _js_jts_dSourceFile> v) noexcept;
		auto name() noexcept;
		void name(js_union<_js_jts_dIdentifier, _js_jts_dStringLiteral> v) noexcept;
	};
	struct _impl_js_jts_dNamespaceDeclaration : virtual _impl_js_jts_dModuleDeclaration {
		struct _tcjs_definitions {
		};
		auto name() noexcept;
		void name(_js_jts_dIdentifier v) noexcept;
		auto body() noexcept;
		void body(js_union<_js_jts_dModuleBlock, _js_jts_dNamespaceDeclaration> v) noexcept;
	};
	struct _impl_js_jts_dJSDocNamespaceDeclaration : virtual _impl_js_jts_dModuleDeclaration {
		struct _tcjs_definitions {
		};
		auto name() noexcept;
		void name(_js_jts_dIdentifier v) noexcept;
	};
	struct _impl_js_jts_dModuleBlock : virtual _impl_js_jts_dNode, virtual _impl_js_jts_dStatement {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ModuleBlock*/ v) noexcept;
		auto parent() noexcept;
		void parent(_js_jts_dModuleDeclaration v) noexcept;
		auto statements() noexcept;
		void statements(js_unknown /*flags=524288: NodeArray<Statement> (TypeReference=ts.NodeArray)*/ v) noexcept;
	};
	struct _impl_js_jts_dImportEqualsDeclaration : virtual _impl_js_jts_dDeclarationStatement, virtual _impl_js_jts_dJSDocContainer {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ImportEqualsDeclaration*/ v) noexcept;
		auto parent() noexcept;
		void parent(js_union<_js_jts_dModuleBlock, _js_jts_dSourceFile> v) noexcept;
		auto name() noexcept;
		void name(_js_jts_dIdentifier v) noexcept;
		auto moduleReference() noexcept;
		void moduleReference(js_union<_js_jts_dExternalModuleReference, _js_jts_dIdentifier, _js_jts_dQualifiedName> v) noexcept;
	};
	struct _impl_js_jts_dExternalModuleReference : virtual _impl_js_jts_dNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ExternalModuleReference*/ v) noexcept;
		auto parent() noexcept;
		void parent(_js_jts_dImportEqualsDeclaration v) noexcept;
		auto expression() noexcept;
		void expression(_js_jts_dExpression v) noexcept;
	};
	struct _impl_js_jts_dImportDeclaration : virtual _impl_js_jts_dStatement {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ImportDeclaration*/ v) noexcept;
		auto parent() noexcept;
		void parent(js_union<_js_jts_dModuleBlock, _js_jts_dSourceFile> v) noexcept;
		auto moduleSpecifier() noexcept;
		void moduleSpecifier(_js_jts_dExpression v) noexcept;
	};
	struct _impl_js_jts_dImportClause : virtual _impl_js_jts_dNamedDeclaration {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ImportClause*/ v) noexcept;
		auto parent() noexcept;
		void parent(_js_jts_dImportDeclaration v) noexcept;
	};
	struct _impl_js_jts_dNamespaceImport : virtual _impl_js_jts_dNamedDeclaration {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.NamespaceImport*/ v) noexcept;
		auto parent() noexcept;
		void parent(_js_jts_dImportClause v) noexcept;
		auto name() noexcept;
		void name(_js_jts_dIdentifier v) noexcept;
	};
	struct _impl_js_jts_dNamespaceExportDeclaration : virtual _impl_js_jts_dDeclarationStatement {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.NamespaceExportDeclaration*/ v) noexcept;
		auto name() noexcept;
		void name(_js_jts_dIdentifier v) noexcept;
	};
	struct _impl_js_jts_dExportDeclaration : virtual _impl_js_jts_dDeclarationStatement, virtual _impl_js_jts_dJSDocContainer {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ExportDeclaration*/ v) noexcept;
		auto parent() noexcept;
		void parent(js_union<_js_jts_dModuleBlock, _js_jts_dSourceFile> v) noexcept;
	};
	struct _impl_js_jts_dNamedImports : virtual _impl_js_jts_dNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.NamedImports*/ v) noexcept;
		auto parent() noexcept;
		void parent(_js_jts_dImportClause v) noexcept;
		auto elements() noexcept;
		void elements(js_unknown /*flags=524288: NodeArray<ImportSpecifier> (TypeReference=ts.NodeArray)*/ v) noexcept;
	};
	struct _impl_js_jts_dNamedExports : virtual _impl_js_jts_dNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.NamedExports*/ v) noexcept;
		auto parent() noexcept;
		void parent(_js_jts_dExportDeclaration v) noexcept;
		auto elements() noexcept;
		void elements(js_unknown /*flags=524288: NodeArray<ExportSpecifier> (TypeReference=ts.NodeArray)*/ v) noexcept;
	};
	struct _impl_js_jts_dImportSpecifier : virtual _impl_js_jts_dNamedDeclaration {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ImportSpecifier*/ v) noexcept;
		auto parent() noexcept;
		void parent(_js_jts_dNamedImports v) noexcept;
		auto name() noexcept;
		void name(_js_jts_dIdentifier v) noexcept;
	};
	struct _impl_js_jts_dExportSpecifier : virtual _impl_js_jts_dNamedDeclaration {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ExportSpecifier*/ v) noexcept;
		auto parent() noexcept;
		void parent(_js_jts_dNamedExports v) noexcept;
		auto name() noexcept;
		void name(_js_jts_dIdentifier v) noexcept;
	};
	struct _impl_js_jts_dExportAssignment : virtual _impl_js_jts_dDeclarationStatement {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.ExportAssignment*/ v) noexcept;
		auto parent() noexcept;
		void parent(_js_jts_dSourceFile v) noexcept;
		auto expression() noexcept;
		void expression(_js_jts_dExpression v) noexcept;
	};
	struct _impl_js_jts_dFileReference : virtual _impl_js_jts_dTextRange {
		struct _tcjs_definitions {
		};
		auto fileName() noexcept;
		void fileName(js_string v) noexcept;
	};
	struct _impl_js_jts_dCheckJsDirective : virtual _impl_js_jts_dTextRange {
		struct _tcjs_definitions {
		};
		auto enabled() noexcept;
		void enabled(bool /*false*/ v) noexcept;
	};
	struct _impl_js_jts_dCommentRange : virtual _impl_js_jts_dTextRange {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.SingleLineCommentTrivia*/ v) noexcept;
	};
	struct _impl_js_jts_dSynthesizedComment : virtual _impl_js_jts_dCommentRange {
		struct _tcjs_definitions {
		};
		auto text() noexcept;
		void text(js_string v) noexcept;
		auto pos() noexcept;
		void pos(double /*-1*/ v) noexcept;
		auto end() noexcept;
		void end(double /*-1*/ v) noexcept;
	};
	struct _impl_js_jts_dJSDocTypeExpression : virtual _impl_js_jts_dTypeNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocTypeExpression*/ v) noexcept;
		auto type() noexcept;
		void type(_js_jts_dTypeNode v) noexcept;
	};
	struct _impl_js_jts_dJSDocType : virtual _impl_js_jts_dTypeNode {
		struct _tcjs_definitions {
		};
		auto _jsDocTypeBrand() noexcept;
		void _jsDocTypeBrand(js_unknown v) noexcept;
	};
	struct _impl_js_jts_dJSDocAllType : virtual _impl_js_jts_dJSDocType {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocAllType*/ v) noexcept;
	};
	struct _impl_js_jts_dJSDocUnknownType : virtual _impl_js_jts_dJSDocType {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocUnknownType*/ v) noexcept;
	};
	struct _impl_js_jts_dJSDocNonNullableType : virtual _impl_js_jts_dJSDocType {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocNonNullableType*/ v) noexcept;
		auto type() noexcept;
		void type(_js_jts_dTypeNode v) noexcept;
	};
	struct _impl_js_jts_dJSDocNullableType : virtual _impl_js_jts_dJSDocType {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocNullableType*/ v) noexcept;
		auto type() noexcept;
		void type(_js_jts_dTypeNode v) noexcept;
	};
	struct _impl_js_jts_dJSDocOptionalType : virtual _impl_js_jts_dJSDocType {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocOptionalType*/ v) noexcept;
		auto type() noexcept;
		void type(_js_jts_dTypeNode v) noexcept;
	};
	struct _impl_js_jts_dJSDocFunctionType : virtual _impl_js_jts_dJSDocType, virtual _impl_js_jts_dSignatureDeclarationBase {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocFunctionType*/ v) noexcept;
	};
	struct _impl_js_jts_dJSDocVariadicType : virtual _impl_js_jts_dJSDocType {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocVariadicType*/ v) noexcept;
		auto type() noexcept;
		void type(_js_jts_dTypeNode v) noexcept;
	};
	struct _impl_js_jts_dJSDoc : virtual _impl_js_jts_dNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocComment*/ v) noexcept;
		auto parent() noexcept;
		void parent(js_unknown /*flags=1048576: HasJSDoc ()*/ v) noexcept;
	};
	struct _impl_js_jts_dJSDocTag : virtual _impl_js_jts_dNode {
		struct _tcjs_definitions {
		};
		auto parent() noexcept;
		void parent(js_union<_js_jts_dJSDoc, _js_jts_dJSDocTypeLiteral> v) noexcept;
		auto tagName() noexcept;
		void tagName(_js_jts_dIdentifier v) noexcept;
	};
	struct _impl_js_jts_dJSDocUnknownTag : virtual _impl_js_jts_dJSDocTag {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocTag*/ v) noexcept;
	};
	struct _impl_js_jts_dJSDocAugmentsTag : virtual _impl_js_jts_dJSDocTag {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocAugmentsTag*/ v) noexcept;
		auto class_() noexcept;
		void class_(js_unknown /*flags=2097152: ExpressionWithTypeArguments & { expression: EntityNameExpression; } ()*/ v) noexcept;
	};
	struct _impl_js_jts_dJSDocClassTag : virtual _impl_js_jts_dJSDocTag {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocClassTag*/ v) noexcept;
	};
	struct _impl_js_jts_dJSDocEnumTag : virtual _impl_js_jts_dJSDocTag {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocEnumTag*/ v) noexcept;
	};
	struct _impl_js_jts_dJSDocThisTag : virtual _impl_js_jts_dJSDocTag {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocThisTag*/ v) noexcept;
	};
	struct _impl_js_jts_dJSDocTemplateTag : virtual _impl_js_jts_dJSDocTag {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocTemplateTag*/ v) noexcept;
		auto constraint() noexcept;
		void constraint(js_union<_js_jts_dJSDocTypeExpression, js_undefined> v) noexcept;
		auto typeParameters() noexcept;
		void typeParameters(js_unknown /*flags=524288: NodeArray<TypeParameterDeclaration> (TypeReference=ts.NodeArray)*/ v) noexcept;
	};
	struct _impl_js_jts_dJSDocReturnTag : virtual _impl_js_jts_dJSDocTag {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocReturnTag*/ v) noexcept;
	};
	struct _impl_js_jts_dJSDocTypeTag : virtual _impl_js_jts_dJSDocTag {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocTypeTag*/ v) noexcept;
		auto typeExpression() noexcept;
		void typeExpression(_js_jts_dJSDocTypeExpression v) noexcept;
	};
	struct _impl_js_jts_dJSDocTypedefTag : virtual _impl_js_jts_dJSDocTag, virtual _impl_js_jts_dNamedDeclaration {
		struct _tcjs_definitions {
		};
		auto parent() noexcept;
		void parent(_js_jts_dJSDoc v) noexcept;
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocTypedefTag*/ v) noexcept;
	};
	struct _impl_js_jts_dJSDocCallbackTag : virtual _impl_js_jts_dJSDocTag, virtual _impl_js_jts_dNamedDeclaration {
		struct _tcjs_definitions {
		};
		auto parent() noexcept;
		void parent(_js_jts_dJSDoc v) noexcept;
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocCallbackTag*/ v) noexcept;
		auto typeExpression() noexcept;
		void typeExpression(_js_jts_dJSDocSignature v) noexcept;
	};
	struct _impl_js_jts_dJSDocSignature : virtual _impl_js_jts_dJSDocType, virtual _impl_js_jts_dDeclaration {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocSignature*/ v) noexcept;
		auto parameters() noexcept;
		void parameters(js::ReadonlyArray<_js_jts_dJSDocParameterTag> v) noexcept;
		auto type() noexcept;
		void type(js_union<_js_jts_dJSDocReturnTag, js_undefined> v) noexcept;
	};
	struct _impl_js_jts_dJSDocPropertyLikeTag : virtual _impl_js_jts_dJSDocTag, virtual _impl_js_jts_dDeclaration {
		struct _tcjs_definitions {
		};
		auto parent() noexcept;
		void parent(_js_jts_dJSDoc v) noexcept;
		auto name() noexcept;
		void name(js_union<_js_jts_dIdentifier, _js_jts_dQualifiedName> v) noexcept;
		auto isNameFirst() noexcept;
		void isNameFirst(bool /*false*/ v) noexcept;
		auto isBracketed() noexcept;
		void isBracketed(bool /*false*/ v) noexcept;
	};
	struct _impl_js_jts_dJSDocPropertyTag : virtual _impl_js_jts_dJSDocPropertyLikeTag {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocPropertyTag*/ v) noexcept;
	};
	struct _impl_js_jts_dJSDocParameterTag : virtual _impl_js_jts_dJSDocPropertyLikeTag {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocParameterTag*/ v) noexcept;
	};
	struct _impl_js_jts_dJSDocTypeLiteral : virtual _impl_js_jts_dJSDocType {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocTypeLiteral*/ v) noexcept;
	};
	struct _impl_js_jts_dFlowLock : virtual IObject {
		struct _tcjs_definitions {
		};
	};
	struct _impl_js_jts_dFlowNodeBase : virtual IObject {
		struct _tcjs_definitions {
		};
		auto flags() noexcept;
		void flags(_js_jts_dFlowFlags /*FlowFlags.Unreachable*/ v) noexcept;
	};
	struct _impl_js_jts_dAfterFinallyFlow : virtual _impl_js_jts_dFlowNodeBase, virtual _impl_js_jts_dFlowLock {
		struct _tcjs_definitions {
		};
		auto antecedent() noexcept;
		void antecedent(js_union<_js_jts_dAfterFinallyFlow, _js_jts_dFlowArrayMutation, _js_jts_dFlowAssignment, _js_jts_dFlowCondition, _js_jts_dFlowLabel, _js_jts_dFlowStart, _js_jts_dFlowSwitchClause, _js_jts_dPreFinallyFlow> v) noexcept;
	};
	struct _impl_js_jts_dPreFinallyFlow : virtual _impl_js_jts_dFlowNodeBase {
		struct _tcjs_definitions {
		};
		auto antecedent() noexcept;
		void antecedent(js_union<_js_jts_dAfterFinallyFlow, _js_jts_dFlowArrayMutation, _js_jts_dFlowAssignment, _js_jts_dFlowCondition, _js_jts_dFlowLabel, _js_jts_dFlowStart, _js_jts_dFlowSwitchClause, _js_jts_dPreFinallyFlow> v) noexcept;
		auto lock() noexcept;
		void lock(_js_jts_dFlowLock v) noexcept;
	};
	struct _impl_js_jts_dFlowStart : virtual _impl_js_jts_dFlowNodeBase {
		struct _tcjs_definitions {
		};
	};
	struct _impl_js_jts_dFlowLabel : virtual _impl_js_jts_dFlowNodeBase {
		struct _tcjs_definitions {
		};
		auto antecedents() noexcept;
		void antecedents(js_union<js::Array<js_union<_js_jts_dAfterFinallyFlow, _js_jts_dFlowArrayMutation, _js_jts_dFlowAssignment, _js_jts_dFlowCondition, _js_jts_dFlowLabel, _js_jts_dFlowStart, _js_jts_dFlowSwitchClause, _js_jts_dPreFinallyFlow>>, js_undefined> v) noexcept;
	};
	struct _impl_js_jts_dFlowAssignment : virtual _impl_js_jts_dFlowNodeBase {
		struct _tcjs_definitions {
		};
		auto node() noexcept;
		void node(js_union<_js_jts_dBindingElement, _js_jts_dExpression, _js_jts_dVariableDeclaration> v) noexcept;
		auto antecedent() noexcept;
		void antecedent(js_union<_js_jts_dAfterFinallyFlow, _js_jts_dFlowArrayMutation, _js_jts_dFlowAssignment, _js_jts_dFlowCondition, _js_jts_dFlowLabel, _js_jts_dFlowStart, _js_jts_dFlowSwitchClause, _js_jts_dPreFinallyFlow> v) noexcept;
	};
	struct _impl_js_jts_dFlowCondition : virtual _impl_js_jts_dFlowNodeBase {
		struct _tcjs_definitions {
		};
		auto expression() noexcept;
		void expression(_js_jts_dExpression v) noexcept;
		auto antecedent() noexcept;
		void antecedent(js_union<_js_jts_dAfterFinallyFlow, _js_jts_dFlowArrayMutation, _js_jts_dFlowAssignment, _js_jts_dFlowCondition, _js_jts_dFlowLabel, _js_jts_dFlowStart, _js_jts_dFlowSwitchClause, _js_jts_dPreFinallyFlow> v) noexcept;
	};
	struct _impl_js_jts_dFlowSwitchClause : virtual _impl_js_jts_dFlowNodeBase {
		struct _tcjs_definitions {
		};
		auto switchStatement() noexcept;
		void switchStatement(_js_jts_dSwitchStatement v) noexcept;
		auto clauseStart() noexcept;
		void clauseStart(double v) noexcept;
		auto clauseEnd() noexcept;
		void clauseEnd(double v) noexcept;
		auto antecedent() noexcept;
		void antecedent(js_union<_js_jts_dAfterFinallyFlow, _js_jts_dFlowArrayMutation, _js_jts_dFlowAssignment, _js_jts_dFlowCondition, _js_jts_dFlowLabel, _js_jts_dFlowStart, _js_jts_dFlowSwitchClause, _js_jts_dPreFinallyFlow> v) noexcept;
	};
	struct _impl_js_jts_dFlowArrayMutation : virtual _impl_js_jts_dFlowNodeBase {
		struct _tcjs_definitions {
		};
		auto node() noexcept;
		void node(js_union<_js_jts_dBinaryExpression, _js_jts_dCallExpression> v) noexcept;
		auto antecedent() noexcept;
		void antecedent(js_union<_js_jts_dAfterFinallyFlow, _js_jts_dFlowArrayMutation, _js_jts_dFlowAssignment, _js_jts_dFlowCondition, _js_jts_dFlowLabel, _js_jts_dFlowStart, _js_jts_dFlowSwitchClause, _js_jts_dPreFinallyFlow> v) noexcept;
	};
	struct _impl_js_jts_dIncompleteType : virtual IObject {
		struct _tcjs_definitions {
		};
		auto flags() noexcept;
		void flags(_js_jts_dTypeFlags /*TypeFlags.Any*/ v) noexcept;
		auto type() noexcept;
		void type(_js_jts_dType v) noexcept;
	};
	struct _impl_js_jts_dAmdDependency : virtual IObject {
		struct _tcjs_definitions {
		};
		auto path() noexcept;
		void path(js_string v) noexcept;
	};
	struct _impl_js_jts_dSourceFile : virtual _impl_js_jts_dDeclaration {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.SourceFile*/ v) noexcept;
		auto statements() noexcept;
		void statements(js_unknown /*flags=524288: NodeArray<Statement> (TypeReference=ts.NodeArray)*/ v) noexcept;
		auto endOfFileToken() noexcept;
		void endOfFileToken(js_unknown /*flags=524288: Token<SyntaxKind.EndOfFileToken> (TypeReference=ts.Token)*/ v) noexcept;
		auto fileName() noexcept;
		void fileName(js_string v) noexcept;
		auto text() noexcept;
		void text(js_string v) noexcept;
		auto amdDependencies() noexcept;
		void amdDependencies(js::ReadonlyArray<_js_jts_dAmdDependency> v) noexcept;
		auto referencedFiles() noexcept;
		void referencedFiles(js::ReadonlyArray<_js_jts_dFileReference> v) noexcept;
		auto typeReferenceDirectives() noexcept;
		void typeReferenceDirectives(js::ReadonlyArray<_js_jts_dFileReference> v) noexcept;
		auto libReferenceDirectives() noexcept;
		void libReferenceDirectives(js::ReadonlyArray<_js_jts_dFileReference> v) noexcept;
		auto languageVariant() noexcept;
		void languageVariant(_js_jts_dLanguageVariant /*LanguageVariant.Standard*/ v) noexcept;
		auto isDeclarationFile() noexcept;
		void isDeclarationFile(bool /*false*/ v) noexcept;
		auto hasNoDefaultLib() noexcept;
		void hasNoDefaultLib(bool /*false*/ v) noexcept;
		auto languageVersion() noexcept;
		void languageVersion(_js_jts_dScriptTarget /*ScriptTarget.ES3*/ v) noexcept;
		auto getLineAndCharacterOfPosition(double pos) noexcept;
		auto getLineEndOfPosition(double pos) noexcept;
		auto getLineStarts() noexcept;
		auto getPositionOfLineAndCharacter(double line, double character) noexcept;
		auto update(js_string newText, _js_jts_dTextChangeRange textChangeRange) noexcept;
	};
	struct _impl_js_jts_dBundle : virtual _impl_js_jts_dNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.Bundle*/ v) noexcept;
		auto prepends() noexcept;
		void prepends(js::ReadonlyArray<js_union<_js_jts_dInputFiles, _js_jts_dUnparsedSource>> v) noexcept;
		auto sourceFiles() noexcept;
		void sourceFiles(js::ReadonlyArray<_js_jts_dSourceFile> v) noexcept;
	};
	struct _impl_js_jts_dInputFiles : virtual _impl_js_jts_dNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.InputFiles*/ v) noexcept;
		auto javascriptText() noexcept;
		void javascriptText(js_string v) noexcept;
		auto declarationText() noexcept;
		void declarationText(js_string v) noexcept;
	};
	struct _impl_js_jts_dUnparsedSource : virtual _impl_js_jts_dNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.UnparsedSource*/ v) noexcept;
		auto fileName() noexcept;
		void fileName(js_string v) noexcept;
		auto text() noexcept;
		void text(js_string v) noexcept;
		auto prologues() noexcept;
		void prologues(js::ReadonlyArray<_js_jts_dUnparsedPrologue> v) noexcept;
		auto helpers() noexcept;
		void helpers(js_union<js::ReadonlyArray<_js_jts_dUnscopedEmitHelper>, js_undefined> v) noexcept;
		auto referencedFiles() noexcept;
		void referencedFiles(js::ReadonlyArray<_js_jts_dFileReference> v) noexcept;
		auto typeReferenceDirectives() noexcept;
		void typeReferenceDirectives(js_union<js::ReadonlyArray<js_string>, js_undefined> v) noexcept;
		auto libReferenceDirectives() noexcept;
		void libReferenceDirectives(js::ReadonlyArray<_js_jts_dFileReference> v) noexcept;
		auto texts() noexcept;
		void texts(js::ReadonlyArray<js_union<_js_jts_dUnparsedPrepend, _js_jts_dUnparsedTextLike>> v) noexcept;
	};
	struct _impl_js_jts_dUnparsedSection : virtual _impl_js_jts_dNode {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.Unknown*/ v) noexcept;
		auto parent() noexcept;
		void parent(_js_jts_dUnparsedSource v) noexcept;
	};
	struct _impl_js_jts_dUnparsedPrologue : virtual _impl_js_jts_dUnparsedSection {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.UnparsedPrologue*/ v) noexcept;
		auto data() noexcept;
		void data(js_string v) noexcept;
		auto parent() noexcept;
		void parent(_js_jts_dUnparsedSource v) noexcept;
	};
	struct _impl_js_jts_dUnparsedPrepend : virtual _impl_js_jts_dUnparsedSection {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.UnparsedPrepend*/ v) noexcept;
		auto data() noexcept;
		void data(js_string v) noexcept;
		auto parent() noexcept;
		void parent(_js_jts_dUnparsedSource v) noexcept;
		auto texts() noexcept;
		void texts(js::ReadonlyArray<_js_jts_dUnparsedTextLike> v) noexcept;
	};
	struct _impl_js_jts_dUnparsedTextLike : virtual _impl_js_jts_dUnparsedSection {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.UnparsedText*/ v) noexcept;
		auto parent() noexcept;
		void parent(_js_jts_dUnparsedSource v) noexcept;
	};
	struct _impl_js_jts_dUnparsedSyntheticReference : virtual _impl_js_jts_dUnparsedSection {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.UnparsedSyntheticReference*/ v) noexcept;
		auto parent() noexcept;
		void parent(_js_jts_dUnparsedSource v) noexcept;
	};
	struct _impl_js_jts_dJsonSourceFile : virtual _impl_js_jts_dSourceFile {
		struct _tcjs_definitions {
		};
		auto statements() noexcept;
		void statements(js_unknown /*flags=524288: NodeArray<JsonObjectExpressionStatement> (TypeReference=ts.NodeArray)*/ v) noexcept;
	};
	struct _impl_js_jts_dTsConfigSourceFile : virtual _impl_js_jts_dJsonSourceFile {
		struct _tcjs_definitions {
		};
	};
	struct _impl_js_jts_dJsonMinusNumericLiteral : virtual _impl_js_jts_dPrefixUnaryExpression {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dSyntaxKind /*SyntaxKind.PrefixUnaryExpression*/ v) noexcept;
		auto operator_() noexcept;
		void operator_(_js_jts_dSyntaxKind /*SyntaxKind.MinusToken*/ v) noexcept;
		auto operand() noexcept;
		void operand(_js_jts_dNumericLiteral v) noexcept;
	};
	struct _impl_js_jts_dJsonObjectExpressionStatement : virtual _impl_js_jts_dExpressionStatement {
		struct _tcjs_definitions {
		};
		auto expression() noexcept;
		void expression(js_union<_js_jts_dArrayLiteralExpression, _js_jts_dBooleanLiteral, _js_jts_dJsonMinusNumericLiteral, _js_jts_dNullLiteral, _js_jts_dNumericLiteral, _js_jts_dObjectLiteralExpression, _js_jts_dStringLiteral> v) noexcept;
	};
	struct _impl_js_jts_dScriptReferenceHost : virtual IObject {
		struct _tcjs_definitions {
		};
		auto getCompilerOptions() noexcept;
		auto getCurrentDirectory() noexcept;
		auto getSourceFile(js_string fileName) noexcept;
		auto getSourceFileByPath(js_unknown /*flags=2097152: Path ()*/ path) noexcept;
	};
	struct _impl_js_jts_dParseConfigHost : virtual IObject {
		struct _tcjs_definitions {
		};
		auto useCaseSensitiveFileNames() noexcept;
		void useCaseSensitiveFileNames(bool /*false*/ v) noexcept;
		auto fileExists(js_string path) noexcept;
		auto readDirectory(js_string rootDir, js::ReadonlyArray<js_string> extensions, js_union<js::ReadonlyArray<js_string>, js_undefined> excludes, js::ReadonlyArray<js_string> includes, js_union<double, js_undefined> depth = js_undefined()) noexcept;
		auto readFile(js_string path) noexcept;
	};
	struct _impl_js_jts_dOperationCanceledException : virtual IObject {
		struct _tcjs_definitions {
		};
		static auto _tcjs_construct() noexcept;
	};
	struct _impl_js_jts_dCancellationToken : virtual IObject {
		struct _tcjs_definitions {
		};
		auto isCancellationRequested() noexcept;
		auto throwIfCancellationRequested() noexcept;
	};
	struct _impl_js_jts_dProgram : virtual _impl_js_jts_dScriptReferenceHost {
		struct _tcjs_definitions {
		};
		auto emit(js_union<_js_jts_dSourceFile, js_undefined> targetSourceFile = js_undefined(), js_union<js_function<void(js_string, js_string, bool /*false*/, js_union<js_function<void(js_string)>, js_undefined>, js_union<js::ReadonlyArray<_js_jts_dSourceFile>, js_undefined>)>, js_undefined> writeFile = js_undefined(), js_union<_js_jts_dCancellationToken, js_undefined> cancellationToken = js_undefined(), js_union<bool /*false*/, js_undefined> emitOnlyDtsFiles = js_undefined(), js_union<_js_jts_dCustomTransformers, js_undefined> customTransformers = js_undefined()) noexcept;
		auto getConfigFileParsingDiagnostics() noexcept;
		auto getDeclarationDiagnostics(js_union<_js_jts_dSourceFile, js_undefined> sourceFile = js_undefined(), js_union<_js_jts_dCancellationToken, js_undefined> cancellationToken = js_undefined()) noexcept;
		auto getGlobalDiagnostics(js_union<_js_jts_dCancellationToken, js_undefined> cancellationToken = js_undefined()) noexcept;
		auto getOptionsDiagnostics(js_union<_js_jts_dCancellationToken, js_undefined> cancellationToken = js_undefined()) noexcept;
		auto getProjectReferences() noexcept;
		auto getResolvedProjectReferences() noexcept;
		auto getRootFileNames() noexcept;
		auto getSemanticDiagnostics(js_union<_js_jts_dSourceFile, js_undefined> sourceFile = js_undefined(), js_union<_js_jts_dCancellationToken, js_undefined> cancellationToken = js_undefined()) noexcept;
		auto getSourceFiles() noexcept;
		auto getSyntacticDiagnostics(js_union<_js_jts_dSourceFile, js_undefined> sourceFile = js_undefined(), js_union<_js_jts_dCancellationToken, js_undefined> cancellationToken = js_undefined()) noexcept;
		auto getTypeChecker() noexcept;
		auto isSourceFileDefaultLibrary(_js_jts_dSourceFile file) noexcept;
		auto isSourceFileFromExternalLibrary(_js_jts_dSourceFile file) noexcept;
	};
	struct _impl_js_jts_dResolvedProjectReference : virtual IObject {
		struct _tcjs_definitions {
		};
		auto commandLine() noexcept;
		void commandLine(_js_jts_dParsedCommandLine v) noexcept;
		auto sourceFile() noexcept;
		void sourceFile(_js_jts_dSourceFile v) noexcept;
	};
	struct _impl_js_jts_dCustomTransformer : virtual IObject {
		struct _tcjs_definitions {
		};
		auto transformBundle(_js_jts_dBundle node) noexcept;
		auto transformSourceFile(_js_jts_dSourceFile node) noexcept;
	};
	struct _impl_js_jts_dCustomTransformers : virtual IObject {
		struct _tcjs_definitions {
		};
	};
	struct _impl_js_jts_dSourceMapSpan : virtual IObject {
		struct _tcjs_definitions {
		};
		auto emittedLine() noexcept;
		void emittedLine(double v) noexcept;
		auto emittedColumn() noexcept;
		void emittedColumn(double v) noexcept;
		auto sourceLine() noexcept;
		void sourceLine(double v) noexcept;
		auto sourceColumn() noexcept;
		void sourceColumn(double v) noexcept;
		auto sourceIndex() noexcept;
		void sourceIndex(double v) noexcept;
	};
	struct _impl_js_jts_dEmitResult : virtual IObject {
		struct _tcjs_definitions {
		};
		auto emitSkipped() noexcept;
		void emitSkipped(bool /*false*/ v) noexcept;
		auto diagnostics() noexcept;
		void diagnostics(js::ReadonlyArray<_js_jts_dDiagnostic> v) noexcept;
	};
	struct _impl_js_jts_dTypeChecker : virtual IObject {
		struct _tcjs_definitions {
		};
		auto getAliasedSymbol(_js_jts_dSymbol symbol) noexcept;
		auto getAmbientModules() noexcept;
		auto getApparentType(_js_jts_dType type) noexcept;
		auto getAugmentedPropertiesOfType(_js_jts_dType type) noexcept;
		auto getBaseConstraintOfType(_js_jts_dType type) noexcept;
		auto getBaseTypeOfLiteralType(_js_jts_dType type) noexcept;
		auto getBaseTypes(_js_jts_dInterfaceType type) noexcept;
		auto getConstantValue(js_union<_js_jts_dElementAccessExpression, _js_jts_dEnumMember, _js_jts_dPropertyAccessExpression> node) noexcept;
		auto getContextualType(_js_jts_dExpression node) noexcept;
		auto getDeclaredTypeOfSymbol(_js_jts_dSymbol symbol) noexcept;
		auto getDefaultFromTypeParameter(_js_jts_dType type) noexcept;
		auto getExportSpecifierLocalTargetSymbol(_js_jts_dExportSpecifier location) noexcept;
		auto getExportSymbolOfSymbol(_js_jts_dSymbol symbol) noexcept;
		auto getExportsOfModule(_js_jts_dSymbol moduleSymbol) noexcept;
		auto getFullyQualifiedName(_js_jts_dSymbol symbol) noexcept;
		auto getIndexInfoOfType(_js_jts_dType type, _js_jts_dIndexKind /*IndexKind.String*/ kind) noexcept;
		auto getIndexTypeOfType(_js_jts_dType type, _js_jts_dIndexKind /*IndexKind.String*/ kind) noexcept;
		auto getJsxIntrinsicTagNamesAt(_js_jts_dNode location) noexcept;
		auto getNonNullableType(_js_jts_dType type) noexcept;
		auto getNullableType(_js_jts_dType type, _js_jts_dTypeFlags /*TypeFlags.Any*/ flags) noexcept;
		auto getPropertiesOfType(_js_jts_dType type) noexcept;
		auto getPropertyOfType(_js_jts_dType type, js_string propertyName) noexcept;
		auto getPropertySymbolOfDestructuringAssignment(_js_jts_dIdentifier location) noexcept;
		auto getResolvedSignature(js_union<_js_jts_dCallExpression, _js_jts_dDecorator, _js_jts_dJsxOpeningElement, _js_jts_dJsxSelfClosingElement, _js_jts_dNewExpression, _js_jts_dTaggedTemplateExpression> node, js_union<js::Array<_js_jts_dSignature>, js_undefined> candidatesOutArray = js_undefined(), js_union<double, js_undefined> argumentCount = js_undefined()) noexcept;
		auto getReturnTypeOfSignature(_js_jts_dSignature signature) noexcept;
		auto getRootSymbols(_js_jts_dSymbol symbol) noexcept;
		auto getShorthandAssignmentValueSymbol(_js_jts_dNode location) noexcept;
		auto getSignatureFromDeclaration(js_union<_js_jts_dArrowFunction, _js_jts_dCallSignatureDeclaration, _js_jts_dConstructSignatureDeclaration, _js_jts_dConstructorDeclaration, _js_jts_dConstructorTypeNode, _js_jts_dFunctionDeclaration, _js_jts_dFunctionExpression, _js_jts_dFunctionTypeNode, _js_jts_dGetAccessorDeclaration, _js_jts_dIndexSignatureDeclaration, _js_jts_dJSDocFunctionType, _js_jts_dMethodDeclaration, _js_jts_dMethodSignature, _js_jts_dSetAccessorDeclaration> declaration) noexcept;
		auto getSignaturesOfType(_js_jts_dType type, _js_jts_dSignatureKind /*SignatureKind.Call*/ kind) noexcept;
		auto getSymbolAtLocation(_js_jts_dNode node) noexcept;
		auto getSymbolsInScope(_js_jts_dNode location, _js_jts_dSymbolFlags /*SymbolFlags.None*/ meaning) noexcept;
		auto getSymbolsOfParameterPropertyDeclaration(_js_jts_dParameterDeclaration parameter, js_string parameterName) noexcept;
		auto getTypeAtLocation(_js_jts_dNode node) noexcept;
		auto getTypeFromTypeNode(_js_jts_dTypeNode node) noexcept;
		auto getTypeOfAssignmentPattern(js_union<_js_jts_dArrayLiteralExpression, _js_jts_dObjectLiteralExpression> pattern) noexcept;
		auto getTypeOfSymbolAtLocation(_js_jts_dSymbol symbol, _js_jts_dNode node) noexcept;
		auto getWidenedType(_js_jts_dType type) noexcept;
		auto indexInfoToIndexSignatureDeclaration(_js_jts_dIndexInfo indexInfo, _js_jts_dIndexKind /*IndexKind.String*/ kind, js_union<_js_jts_dNode, js_undefined> enclosingDeclaration = js_undefined(), js_union<_js_jts_dNodeBuilderFlags /*NodeBuilderFlags.OmitParameterModifiers*/, js_undefined> flags = js_undefined()) noexcept;
		auto isArgumentsSymbol(_js_jts_dSymbol symbol) noexcept;
		auto isImplementationOfOverload(js_union<_js_jts_dArrowFunction, _js_jts_dCallSignatureDeclaration, _js_jts_dConstructSignatureDeclaration, _js_jts_dConstructorDeclaration, _js_jts_dConstructorTypeNode, _js_jts_dFunctionDeclaration, _js_jts_dFunctionExpression, _js_jts_dFunctionTypeNode, _js_jts_dGetAccessorDeclaration, _js_jts_dIndexSignatureDeclaration, _js_jts_dJSDocFunctionType, _js_jts_dMethodDeclaration, _js_jts_dMethodSignature, _js_jts_dSetAccessorDeclaration> node) noexcept;
		auto isOptionalParameter(_js_jts_dParameterDeclaration node) noexcept;
		auto isUndefinedSymbol(_js_jts_dSymbol symbol) noexcept;
		auto isUnknownSymbol(_js_jts_dSymbol symbol) noexcept;
		auto isValidPropertyAccess(js_union<_js_jts_dImportTypeNode, _js_jts_dPropertyAccessExpression, _js_jts_dQualifiedName> node, js_string propertyName) noexcept;
		auto runWithCancellationToken(_js_jts_dCancellationToken token, js_function<js_unknown /*flags=262144: T ()*/(_js_jts_dTypeChecker)> cb) noexcept;
		auto signatureToSignatureDeclaration(_js_jts_dSignature signature, _js_jts_dSyntaxKind /*SyntaxKind.Unknown*/ kind, js_union<_js_jts_dNode, js_undefined> enclosingDeclaration = js_undefined(), js_union<_js_jts_dNodeBuilderFlags /*NodeBuilderFlags.OmitParameterModifiers*/, js_undefined> flags = js_undefined()) noexcept;
		auto signatureToString(_js_jts_dSignature signature, js_union<_js_jts_dNode, js_undefined> enclosingDeclaration = js_undefined(), js_union<_js_jts_dTypeFormatFlags /*TypeFormatFlags.UseTypeOfFunction*/, js_undefined> flags = js_undefined(), js_union<_js_jts_dSignatureKind /*SignatureKind.Call*/, js_undefined> kind = js_undefined()) noexcept;
		auto symbolToEntityName(_js_jts_dSymbol symbol, _js_jts_dSymbolFlags /*SymbolFlags.None*/ meaning, js_union<_js_jts_dNode, js_undefined> enclosingDeclaration = js_undefined(), js_union<_js_jts_dNodeBuilderFlags /*NodeBuilderFlags.OmitParameterModifiers*/, js_undefined> flags = js_undefined()) noexcept;
		auto symbolToExpression(_js_jts_dSymbol symbol, _js_jts_dSymbolFlags /*SymbolFlags.None*/ meaning, js_union<_js_jts_dNode, js_undefined> enclosingDeclaration = js_undefined(), js_union<_js_jts_dNodeBuilderFlags /*NodeBuilderFlags.OmitParameterModifiers*/, js_undefined> flags = js_undefined()) noexcept;
		auto symbolToParameterDeclaration(_js_jts_dSymbol symbol, js_union<_js_jts_dNode, js_undefined> enclosingDeclaration = js_undefined(), js_union<_js_jts_dNodeBuilderFlags /*NodeBuilderFlags.OmitParameterModifiers*/, js_undefined> flags = js_undefined()) noexcept;
		auto symbolToString(_js_jts_dSymbol symbol, js_union<_js_jts_dNode, js_undefined> enclosingDeclaration = js_undefined(), js_union<_js_jts_dSymbolFlags /*SymbolFlags.Transient*/, js_undefined> meaning = js_undefined(), js_union<_js_jts_dSymbolFormatFlags /*SymbolFormatFlags.None*/, js_undefined> flags = js_undefined()) noexcept;
		auto symbolToTypeParameterDeclarations(_js_jts_dSymbol symbol, js_union<_js_jts_dNode, js_undefined> enclosingDeclaration = js_undefined(), js_union<_js_jts_dNodeBuilderFlags /*NodeBuilderFlags.OmitParameterModifiers*/, js_undefined> flags = js_undefined()) noexcept;
		auto tryGetMemberInModuleExports(js_string memberName, _js_jts_dSymbol moduleSymbol) noexcept;
		auto typeParameterToDeclaration(_js_jts_dTypeParameter parameter, js_union<_js_jts_dNode, js_undefined> enclosingDeclaration = js_undefined(), js_union<_js_jts_dNodeBuilderFlags /*NodeBuilderFlags.OmitParameterModifiers*/, js_undefined> flags = js_undefined()) noexcept;
		auto typePredicateToString(js_union<_js_jts_dIdentifierTypePredicate, _js_jts_dThisTypePredicate> predicate, js_union<_js_jts_dNode, js_undefined> enclosingDeclaration = js_undefined(), js_union<_js_jts_dTypeFormatFlags /*TypeFormatFlags.UseTypeOfFunction*/, js_undefined> flags = js_undefined()) noexcept;
		auto typeToString(_js_jts_dType type, js_union<_js_jts_dNode, js_undefined> enclosingDeclaration = js_undefined(), js_union<_js_jts_dTypeFormatFlags /*TypeFormatFlags.UseTypeOfFunction*/, js_undefined> flags = js_undefined()) noexcept;
		auto typeToTypeNode(_js_jts_dType type, js_union<_js_jts_dNode, js_undefined> enclosingDeclaration = js_undefined(), js_union<_js_jts_dNodeBuilderFlags /*NodeBuilderFlags.OmitParameterModifiers*/, js_undefined> flags = js_undefined()) noexcept;
	};
	struct _impl_js_jts_dTypePredicateBase : virtual IObject {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dTypePredicateKind /*TypePredicateKind.This*/ v) noexcept;
		auto type() noexcept;
		void type(_js_jts_dType v) noexcept;
	};
	struct _impl_js_jts_dThisTypePredicate : virtual _impl_js_jts_dTypePredicateBase {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dTypePredicateKind /*TypePredicateKind.This*/ v) noexcept;
	};
	struct _impl_js_jts_dIdentifierTypePredicate : virtual _impl_js_jts_dTypePredicateBase {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dTypePredicateKind /*TypePredicateKind.Identifier*/ v) noexcept;
		auto parameterName() noexcept;
		void parameterName(js_string v) noexcept;
		auto parameterIndex() noexcept;
		void parameterIndex(double v) noexcept;
	};
	struct _impl_js_jts_dSymbol : virtual IObject {
		struct _tcjs_definitions {
		};
		auto flags() noexcept;
		void flags(_js_jts_dSymbolFlags /*SymbolFlags.None*/ v) noexcept;
		auto escapedName() noexcept;
		void escapedName(js_unknown /*flags=1048576: __String ()*/ v) noexcept;
		auto declarations() noexcept;
		void declarations(js::Array<_js_jts_dDeclaration> v) noexcept;
		auto valueDeclaration() noexcept;
		void valueDeclaration(_js_jts_dDeclaration v) noexcept;
		auto name() noexcept;
		auto getDeclarations() noexcept;
		auto getDocumentationComment(js_union<_js_jts_dTypeChecker, js_undefined> typeChecker = js_undefined()) noexcept;
		auto getEscapedName() noexcept;
		auto getFlags() noexcept;
		auto getJsDocTags() noexcept;
		auto getName() noexcept;
	};
	struct _impl_js_jts_dReadonlyUnderscoreEscapedMap : virtual IObject {
		struct _tcjs_definitions {
		};
		auto size() noexcept;
		auto entries() noexcept;
		auto forEach(js_function<void(js_unknown /*flags=262144: T ()*/, js_unknown /*flags=1048576: __String ()*/)> action) noexcept;
		auto get(js_unknown /*flags=1048576: __String ()*/ key) noexcept;
		auto has(js_unknown /*flags=1048576: __String ()*/ key) noexcept;
		auto keys() noexcept;
		auto values() noexcept;
	};
	struct _impl_js_jts_dUnderscoreEscapedMap : virtual IObject {
		struct _tcjs_definitions {
		};
		auto clear() noexcept;
		auto delete_(js_unknown /*flags=1048576: __String ()*/ key) noexcept;
		auto set(js_unknown /*flags=1048576: __String ()*/ key, js_unknown /*flags=262144: T ()*/ value) noexcept;
	};
	struct _impl_js_jts_dType : virtual IObject {
		struct _tcjs_definitions {
		};
		auto flags() noexcept;
		void flags(_js_jts_dTypeFlags /*TypeFlags.Any*/ v) noexcept;
		auto symbol() noexcept;
		void symbol(_js_jts_dSymbol v) noexcept;
		auto getApparentProperties() noexcept;
		auto getBaseTypes() noexcept;
		auto getCallSignatures() noexcept;
		auto getConstraint() noexcept;
		auto getConstructSignatures() noexcept;
		auto getDefault() noexcept;
		auto getFlags() noexcept;
		auto getNonNullableType() noexcept;
		auto getNumberIndexType() noexcept;
		auto getProperties() noexcept;
		auto getProperty(js_string propertyName) noexcept;
		auto getStringIndexType() noexcept;
		auto getSymbol() noexcept;
		auto isClass() noexcept;
		auto isClassOrInterface() noexcept;
		auto isIntersection() noexcept;
		auto isLiteral() noexcept;
		auto isNumberLiteral() noexcept;
		auto isStringLiteral() noexcept;
		auto isTypeParameter() noexcept;
		auto isUnion() noexcept;
		auto isUnionOrIntersection() noexcept;
	};
	struct _impl_js_jts_dLiteralType : virtual _impl_js_jts_dType {
		struct _tcjs_definitions {
		};
		auto value() noexcept;
		void value(js_union<_js_jts_dPseudoBigInt, double, js_string> v) noexcept;
		auto freshType() noexcept;
		void freshType(_js_jts_dLiteralType v) noexcept;
		auto regularType() noexcept;
		void regularType(_js_jts_dLiteralType v) noexcept;
	};
	struct _impl_js_jts_dUniqueESSymbolType : virtual _impl_js_jts_dType {
		struct _tcjs_definitions {
		};
		auto symbol() noexcept;
		void symbol(_js_jts_dSymbol v) noexcept;
		auto escapedName() noexcept;
		void escapedName(js_unknown /*flags=1048576: __String ()*/ v) noexcept;
	};
	struct _impl_js_jts_dStringLiteralType : virtual _impl_js_jts_dLiteralType {
		struct _tcjs_definitions {
		};
		auto value() noexcept;
		void value(js_string v) noexcept;
	};
	struct _impl_js_jts_dNumberLiteralType : virtual _impl_js_jts_dLiteralType {
		struct _tcjs_definitions {
		};
		auto value() noexcept;
		void value(double v) noexcept;
	};
	struct _impl_js_jts_dBigIntLiteralType : virtual _impl_js_jts_dLiteralType {
		struct _tcjs_definitions {
		};
		auto value() noexcept;
		void value(_js_jts_dPseudoBigInt v) noexcept;
	};
	struct _impl_js_jts_dEnumType : virtual _impl_js_jts_dType {
		struct _tcjs_definitions {
		};
	};
	struct _impl_js_jts_dObjectType : virtual _impl_js_jts_dType {
		struct _tcjs_definitions {
		};
		auto objectFlags() noexcept;
		void objectFlags(_js_jts_dObjectFlags /*ObjectFlags.Class*/ v) noexcept;
	};
	struct _impl_js_jts_dInterfaceType : virtual _impl_js_jts_dObjectType {
		struct _tcjs_definitions {
		};
		auto typeParameters() noexcept;
		void typeParameters(js_union<js::Array<_js_jts_dTypeParameter>, js_undefined> v) noexcept;
		auto outerTypeParameters() noexcept;
		void outerTypeParameters(js_union<js::Array<_js_jts_dTypeParameter>, js_undefined> v) noexcept;
		auto localTypeParameters() noexcept;
		void localTypeParameters(js_union<js::Array<_js_jts_dTypeParameter>, js_undefined> v) noexcept;
		auto thisType() noexcept;
		void thisType(js_union<_js_jts_dTypeParameter, js_undefined> v) noexcept;
	};
	struct _impl_js_jts_dInterfaceTypeWithDeclaredMembers : virtual _impl_js_jts_dInterfaceType {
		struct _tcjs_definitions {
		};
		auto declaredProperties() noexcept;
		void declaredProperties(js::Array<_js_jts_dSymbol> v) noexcept;
		auto declaredCallSignatures() noexcept;
		void declaredCallSignatures(js::Array<_js_jts_dSignature> v) noexcept;
		auto declaredConstructSignatures() noexcept;
		void declaredConstructSignatures(js::Array<_js_jts_dSignature> v) noexcept;
	};
	struct _impl_js_jts_dTypeReference : virtual _impl_js_jts_dObjectType {
		struct _tcjs_definitions {
		};
		auto target() noexcept;
		void target(_js_jts_dGenericType v) noexcept;
	};
	struct _impl_js_jts_dGenericType : virtual _impl_js_jts_dInterfaceType, virtual _impl_js_jts_dTypeReference {
		struct _tcjs_definitions {
		};
	};
	struct _impl_js_jts_dTupleType : virtual _impl_js_jts_dGenericType {
		struct _tcjs_definitions {
		};
		auto minLength() noexcept;
		void minLength(double v) noexcept;
		auto hasRestElement() noexcept;
		void hasRestElement(bool /*false*/ v) noexcept;
		auto readonly() noexcept;
		void readonly(bool /*false*/ v) noexcept;
	};
	struct _impl_js_jts_dTupleTypeReference : virtual _impl_js_jts_dTypeReference {
		struct _tcjs_definitions {
		};
		auto target() noexcept;
		void target(_js_jts_dTupleType v) noexcept;
	};
	struct _impl_js_jts_dUnionOrIntersectionType : virtual _impl_js_jts_dType {
		struct _tcjs_definitions {
		};
		auto types() noexcept;
		void types(js::Array<_js_jts_dType> v) noexcept;
	};
	struct _impl_js_jts_dUnionType : virtual _impl_js_jts_dUnionOrIntersectionType {
		struct _tcjs_definitions {
		};
	};
	struct _impl_js_jts_dIntersectionType : virtual _impl_js_jts_dUnionOrIntersectionType {
		struct _tcjs_definitions {
		};
	};
	struct _impl_js_jts_dEvolvingArrayType : virtual _impl_js_jts_dObjectType {
		struct _tcjs_definitions {
		};
		auto elementType() noexcept;
		void elementType(_js_jts_dType v) noexcept;
	};
	struct _impl_js_jts_dInstantiableType : virtual _impl_js_jts_dType {
		struct _tcjs_definitions {
		};
	};
	struct _impl_js_jts_dTypeParameter : virtual _impl_js_jts_dInstantiableType {
		struct _tcjs_definitions {
		};
	};
	struct _impl_js_jts_dIndexedAccessType : virtual _impl_js_jts_dInstantiableType {
		struct _tcjs_definitions {
		};
		auto objectType() noexcept;
		void objectType(_js_jts_dType v) noexcept;
		auto indexType() noexcept;
		void indexType(_js_jts_dType v) noexcept;
	};
	struct _impl_js_jts_dIndexType : virtual _impl_js_jts_dInstantiableType {
		struct _tcjs_definitions {
		};
		auto type() noexcept;
		void type(js_union<_js_jts_dInstantiableType, _js_jts_dUnionOrIntersectionType> v) noexcept;
	};
	struct _impl_js_jts_dConditionalRoot : virtual IObject {
		struct _tcjs_definitions {
		};
		auto node() noexcept;
		void node(_js_jts_dConditionalTypeNode v) noexcept;
		auto checkType() noexcept;
		void checkType(_js_jts_dType v) noexcept;
		auto extendsType() noexcept;
		void extendsType(_js_jts_dType v) noexcept;
		auto trueType() noexcept;
		void trueType(_js_jts_dType v) noexcept;
		auto falseType() noexcept;
		void falseType(_js_jts_dType v) noexcept;
		auto isDistributive() noexcept;
		void isDistributive(bool /*false*/ v) noexcept;
	};
	struct _impl_js_jts_dConditionalType : virtual _impl_js_jts_dInstantiableType {
		struct _tcjs_definitions {
		};
		auto root() noexcept;
		void root(_js_jts_dConditionalRoot v) noexcept;
		auto checkType() noexcept;
		void checkType(_js_jts_dType v) noexcept;
		auto extendsType() noexcept;
		void extendsType(_js_jts_dType v) noexcept;
		auto resolvedTrueType() noexcept;
		void resolvedTrueType(_js_jts_dType v) noexcept;
		auto resolvedFalseType() noexcept;
		void resolvedFalseType(_js_jts_dType v) noexcept;
	};
	struct _impl_js_jts_dSubstitutionType : virtual _impl_js_jts_dInstantiableType {
		struct _tcjs_definitions {
		};
		auto typeVariable() noexcept;
		void typeVariable(js_union<_js_jts_dIndexedAccessType, _js_jts_dTypeParameter> v) noexcept;
		auto substitute() noexcept;
		void substitute(_js_jts_dType v) noexcept;
	};
	struct _impl_js_jts_dSignature : virtual IObject {
		struct _tcjs_definitions {
		};
		auto parameters() noexcept;
		void parameters(js::ReadonlyArray<_js_jts_dSymbol> v) noexcept;
		auto getDeclaration() noexcept;
		auto getDocumentationComment(js_union<_js_jts_dTypeChecker, js_undefined> typeChecker = js_undefined()) noexcept;
		auto getJsDocTags() noexcept;
		auto getParameters() noexcept;
		auto getReturnType() noexcept;
		auto getTypeParameters() noexcept;
	};
	struct _impl_js_jts_dIndexInfo : virtual IObject {
		struct _tcjs_definitions {
		};
		auto type() noexcept;
		void type(_js_jts_dType v) noexcept;
		auto isReadonly() noexcept;
		void isReadonly(bool /*false*/ v) noexcept;
	};
	struct _impl_js_jts_dFileExtensionInfo : virtual IObject {
		struct _tcjs_definitions {
		};
		auto extension() noexcept;
		void extension(js_string v) noexcept;
		auto isMixedContent() noexcept;
		void isMixedContent(bool /*false*/ v) noexcept;
	};
	struct _impl_js_jts_dDiagnosticMessage : virtual IObject {
		struct _tcjs_definitions {
		};
		auto key() noexcept;
		void key(js_string v) noexcept;
		auto category() noexcept;
		void category(_js_jts_dDiagnosticCategory /*DiagnosticCategory.Warning*/ v) noexcept;
		auto code() noexcept;
		void code(double v) noexcept;
		auto message() noexcept;
		void message(js_string v) noexcept;
	};
	struct _impl_js_jts_dDiagnosticMessageChain : virtual IObject {
		struct _tcjs_definitions {
		};
		auto messageText() noexcept;
		void messageText(js_string v) noexcept;
		auto category() noexcept;
		void category(_js_jts_dDiagnosticCategory /*DiagnosticCategory.Warning*/ v) noexcept;
		auto code() noexcept;
		void code(double v) noexcept;
	};
	struct _impl_js_jts_dDiagnosticRelatedInformation : virtual IObject {
		struct _tcjs_definitions {
		};
		auto category() noexcept;
		void category(_js_jts_dDiagnosticCategory /*DiagnosticCategory.Warning*/ v) noexcept;
		auto code() noexcept;
		void code(double v) noexcept;
		auto file() noexcept;
		void file(js_union<_js_jts_dSourceFile, js_undefined> v) noexcept;
		auto start() noexcept;
		void start(js_union<double, js_undefined> v) noexcept;
		auto length() noexcept;
		void length(js_union<double, js_undefined> v) noexcept;
		auto messageText() noexcept;
		void messageText(js_union<_js_jts_dDiagnosticMessageChain, js_string> v) noexcept;
	};
	struct _impl_js_jts_dDiagnostic : virtual _impl_js_jts_dDiagnosticRelatedInformation {
		struct _tcjs_definitions {
		};
	};
	struct _impl_js_jts_dDiagnosticWithLocation : virtual _impl_js_jts_dDiagnostic {
		struct _tcjs_definitions {
		};
		auto file() noexcept;
		void file(_js_jts_dSourceFile v) noexcept;
		auto start() noexcept;
		void start(double v) noexcept;
		auto length() noexcept;
		void length(double v) noexcept;
	};
	struct _impl_js_jts_dPluginImport : virtual IObject {
		struct _tcjs_definitions {
		};
		auto name() noexcept;
		void name(js_string v) noexcept;
	};
	struct _impl_js_jts_dProjectReference : virtual IObject {
		struct _tcjs_definitions {
		};
		auto path() noexcept;
		void path(js_string v) noexcept;
	};
	struct _impl_js_jts_dCompilerOptions : virtual IObject {
		struct _tcjs_definitions {
		};
	};
	struct _impl_js_jts_dTypeAcquisition : virtual IObject {
		struct _tcjs_definitions {
		};
	};
	struct _impl_js_jts_dLineAndCharacter : virtual IObject {
		struct _tcjs_definitions {
		};
		auto line() noexcept;
		void line(double v) noexcept;
		auto character() noexcept;
		void character(double v) noexcept;
	};
	struct _impl_js_jts_dParsedCommandLine : virtual IObject {
		struct _tcjs_definitions {
		};
		auto options() noexcept;
		void options(_js_jts_dCompilerOptions v) noexcept;
		auto fileNames() noexcept;
		void fileNames(js::Array<js_string> v) noexcept;
		auto errors() noexcept;
		void errors(js::Array<_js_jts_dDiagnostic> v) noexcept;
	};
	struct _impl_js_jts_dExpandResult : virtual IObject {
		struct _tcjs_definitions {
		};
		auto fileNames() noexcept;
		void fileNames(js::Array<js_string> v) noexcept;
		auto wildcardDirectories() noexcept;
		void wildcardDirectories(js_unknown /*flags=524288: MapLike<WatchDirectoryFlags> (TypeReference=ts.MapLike)*/ v) noexcept;
	};
	struct _impl_js_jts_dCreateProgramOptions : virtual IObject {
		struct _tcjs_definitions {
		};
		auto rootNames() noexcept;
		void rootNames(js::ReadonlyArray<js_string> v) noexcept;
		auto options() noexcept;
		void options(_js_jts_dCompilerOptions v) noexcept;
	};
	struct _impl_js_jts_dModuleResolutionHost : virtual IObject {
		struct _tcjs_definitions {
		};
		auto fileExists(js_string fileName) noexcept;
		auto readFile(js_string fileName) noexcept;
	};
	struct _impl_js_jts_dResolvedModule : virtual IObject {
		struct _tcjs_definitions {
		};
		auto resolvedFileName() noexcept;
		void resolvedFileName(js_string v) noexcept;
	};
	struct _impl_js_jts_dResolvedModuleFull : virtual _impl_js_jts_dResolvedModule {
		struct _tcjs_definitions {
		};
		auto extension() noexcept;
		void extension(_js_jts_dExtension /*Extension.Ts*/ v) noexcept;
	};
	struct _impl_js_jts_dPackageId : virtual IObject {
		struct _tcjs_definitions {
		};
		auto name() noexcept;
		void name(js_string v) noexcept;
		auto subModuleName() noexcept;
		void subModuleName(js_string v) noexcept;
		auto version() noexcept;
		void version(js_string v) noexcept;
	};
	struct _impl_js_jts_dResolvedModuleWithFailedLookupLocations : virtual IObject {
		struct _tcjs_definitions {
		};
		auto resolvedModule() noexcept;
	};
	struct _impl_js_jts_dResolvedTypeReferenceDirective : virtual IObject {
		struct _tcjs_definitions {
		};
		auto primary() noexcept;
		void primary(bool /*false*/ v) noexcept;
		auto resolvedFileName() noexcept;
		void resolvedFileName(js_union<js_string, js_undefined> v) noexcept;
	};
	struct _impl_js_jts_dResolvedTypeReferenceDirectiveWithFailedLookupLocations : virtual IObject {
		struct _tcjs_definitions {
		};
		auto resolvedTypeReferenceDirective() noexcept;
		auto failedLookupLocations() noexcept;
	};
	struct _impl_js_jts_dCompilerHost : virtual _impl_js_jts_dModuleResolutionHost {
		struct _tcjs_definitions {
		};
		auto writeFile() noexcept;
		void writeFile(js_function<void(js_string, js_string, bool /*false*/, js_union<js_function<void(js_string)>, js_undefined>, js_union<js::ReadonlyArray<_js_jts_dSourceFile>, js_undefined>)> v) noexcept;
		auto getCanonicalFileName(js_string fileName) noexcept;
		auto getCurrentDirectory() noexcept;
		auto getDefaultLibFileName(_js_jts_dCompilerOptions options) noexcept;
		auto getNewLine() noexcept;
		auto getSourceFile(js_string fileName, _js_jts_dScriptTarget /*ScriptTarget.ES3*/ languageVersion, js_union<js_function<void(js_string)>, js_undefined> onError = js_undefined(), js_union<bool /*false*/, js_undefined> shouldCreateNewSourceFile = js_undefined()) noexcept;
		auto useCaseSensitiveFileNames() noexcept;
	};
	struct _impl_js_jts_dSourceMapRange : virtual _impl_js_jts_dTextRange {
		struct _tcjs_definitions {
		};
	};
	struct _impl_js_jts_dSourceMapSource : virtual IObject {
		struct _tcjs_definitions {
		};
		auto fileName() noexcept;
		void fileName(js_string v) noexcept;
		auto text() noexcept;
		void text(js_string v) noexcept;
		auto getLineAndCharacterOfPosition(double pos) noexcept;
	};
	struct _impl_js_jts_dEmitHelper : virtual IObject {
		struct _tcjs_definitions {
		};
		auto name() noexcept;
		auto scoped() noexcept;
		auto text() noexcept;
	};
	struct _impl_js_jts_dUnscopedEmitHelper : virtual _impl_js_jts_dEmitHelper {
		struct _tcjs_definitions {
		};
		auto scoped() noexcept;
		auto text() noexcept;
	};
	struct _impl_js_jts_dTransformationContext : virtual IObject {
		struct _tcjs_definitions {
		};
		auto onSubstituteNode() noexcept;
		void onSubstituteNode(js_function<_js_jts_dNode(_js_jts_dEmitHint /*EmitHint.SourceFile*/, _js_jts_dNode)> v) noexcept;
		auto onEmitNode() noexcept;
		void onEmitNode(js_function<void(_js_jts_dEmitHint /*EmitHint.SourceFile*/, _js_jts_dNode, js_function<void(_js_jts_dEmitHint /*EmitHint.SourceFile*/, _js_jts_dNode)>)> v) noexcept;
		auto enableEmitNotification(_js_jts_dSyntaxKind /*SyntaxKind.Unknown*/ kind) noexcept;
		auto enableSubstitution(_js_jts_dSyntaxKind /*SyntaxKind.Unknown*/ kind) noexcept;
		auto endLexicalEnvironment() noexcept;
		auto getCompilerOptions() noexcept;
		auto hoistFunctionDeclaration(_js_jts_dFunctionDeclaration node) noexcept;
		auto hoistVariableDeclaration(_js_jts_dIdentifier node) noexcept;
		auto isEmitNotificationEnabled(_js_jts_dNode node) noexcept;
		auto isSubstitutionEnabled(_js_jts_dNode node) noexcept;
		auto readEmitHelpers() noexcept;
		auto requestEmitHelper(_js_jts_dEmitHelper helper) noexcept;
		auto resumeLexicalEnvironment() noexcept;
		auto startLexicalEnvironment() noexcept;
		auto suspendLexicalEnvironment() noexcept;
	};
	struct _impl_js_jts_dTransformationResult : virtual IObject {
		struct _tcjs_definitions {
		};
		auto transformed() noexcept;
		void transformed(js::Array<js_unknown /*flags=262144: T ()*/> v) noexcept;
		auto dispose() noexcept;
		auto emitNodeWithNotification(_js_jts_dEmitHint /*EmitHint.SourceFile*/ hint, _js_jts_dNode node, js_function<void(_js_jts_dEmitHint /*EmitHint.SourceFile*/, _js_jts_dNode)> emitCallback) noexcept;
		auto substituteNode(_js_jts_dEmitHint /*EmitHint.SourceFile*/ hint, _js_jts_dNode node) noexcept;
	};
	struct _impl_js_jts_dPrinter : virtual IObject {
		struct _tcjs_definitions {
		};
		auto printBundle(_js_jts_dBundle bundle) noexcept;
		auto printFile(_js_jts_dSourceFile sourceFile) noexcept;
		auto printList(_js_jts_dListFormat /*ListFormat.None*/ format, js_unknown /*flags=524288: NodeArray<T> (TypeReference=ts.NodeArray)*/ list, _js_jts_dSourceFile sourceFile) noexcept;
		auto printNode(_js_jts_dEmitHint /*EmitHint.SourceFile*/ hint, _js_jts_dNode node, _js_jts_dSourceFile sourceFile) noexcept;
	};
	struct _impl_js_jts_dPrintHandlers : virtual IObject {
		struct _tcjs_definitions {
		};
	};
	struct _impl_js_jts_dPrinterOptions : virtual IObject {
		struct _tcjs_definitions {
		};
	};
	struct _impl_js_jts_dGetEffectiveTypeRootsHost : virtual IObject {
		struct _tcjs_definitions {
		};
	};
	struct _impl_js_jts_dTextSpan : virtual IObject {
		struct _tcjs_definitions {
		};
		auto start() noexcept;
		void start(double v) noexcept;
		auto length() noexcept;
		void length(double v) noexcept;
	};
	struct _impl_js_jts_dTextChangeRange : virtual IObject {
		struct _tcjs_definitions {
		};
		auto span() noexcept;
		void span(_js_jts_dTextSpan v) noexcept;
		auto newLength() noexcept;
		void newLength(double v) noexcept;
	};
	struct _impl_js_jts_dSyntaxList : virtual _impl_js_jts_dNode {
		struct _tcjs_definitions {
		};
		auto _children() noexcept;
		void _children(js::Array<_js_jts_dNode> v) noexcept;
	};
	struct _impl_js_jts_dUserPreferences : virtual IObject {
		struct _tcjs_definitions {
		};
	};
	struct _impl_js_jts_dPseudoBigInt : virtual IObject {
		struct _tcjs_definitions {
		};
		auto negative() noexcept;
		void negative(bool /*false*/ v) noexcept;
		auto base10Value() noexcept;
		void base10Value(js_string v) noexcept;
	};
	struct _impl_js_jts_dSystem : virtual IObject {
		struct _tcjs_definitions {
		};
		auto args() noexcept;
		void args(js::Array<js_string> v) noexcept;
		auto newLine() noexcept;
		void newLine(js_string v) noexcept;
		auto useCaseSensitiveFileNames() noexcept;
		void useCaseSensitiveFileNames(bool /*false*/ v) noexcept;
		auto createDirectory(js_string path) noexcept;
		auto directoryExists(js_string path) noexcept;
		auto exit(js_union<double, js_undefined> exitCode = js_undefined()) noexcept;
		auto fileExists(js_string path) noexcept;
		auto getCurrentDirectory() noexcept;
		auto getDirectories(js_string path) noexcept;
		auto getExecutingFilePath() noexcept;
		auto readDirectory(js_string path, js_union<js::ReadonlyArray<js_string>, js_undefined> extensions = js_undefined(), js_union<js::ReadonlyArray<js_string>, js_undefined> exclude = js_undefined(), js_union<js::ReadonlyArray<js_string>, js_undefined> include = js_undefined(), js_union<double, js_undefined> depth = js_undefined()) noexcept;
		auto readFile(js_string path, js_union<js_string, js_undefined> encoding = js_undefined()) noexcept;
		auto resolvePath(js_string path) noexcept;
		auto write(js_string s) noexcept;
		auto writeFile(js_string path, js_string data, js_union<bool /*false*/, js_undefined> writeByteOrderMark = js_undefined()) noexcept;
	};
	struct _impl_js_jts_dFileWatcher : virtual IObject {
		struct _tcjs_definitions {
		};
		auto close() noexcept;
	};
	struct _impl_js_jts_dScanner : virtual IObject {
		struct _tcjs_definitions {
		};
		auto getStartPos() noexcept;
		auto getText() noexcept;
		auto getTextPos() noexcept;
		auto getToken() noexcept;
		auto getTokenPos() noexcept;
		auto getTokenText() noexcept;
		auto getTokenValue() noexcept;
		auto hasExtendedUnicodeEscape() noexcept;
		auto hasPrecedingLineBreak() noexcept;
		auto isIdentifier() noexcept;
		auto isReservedWord() noexcept;
		auto isUnterminated() noexcept;
		auto lookAhead(js_function<js_unknown /*flags=262144: T ()*/()> callback) noexcept;
		auto reScanGreaterToken() noexcept;
		auto reScanJsxToken() noexcept;
		auto reScanLessThanToken() noexcept;
		auto reScanSlashToken() noexcept;
		auto reScanTemplateToken() noexcept;
		auto scan() noexcept;
		auto scanJsDocToken() noexcept;
		auto scanJsxAttributeValue() noexcept;
		auto scanJsxIdentifier() noexcept;
		auto scanJsxToken() noexcept;
		auto scanRange(double start, double length, js_function<js_unknown /*flags=262144: T ()*/()> callback) noexcept;
		auto setLanguageVariant(_js_jts_dLanguageVariant /*LanguageVariant.Standard*/ variant) noexcept;
		auto setOnError(js_union<js_function<void(_js_jts_dDiagnosticMessage, double)>, js_undefined> onError = js_undefined()) noexcept;
		auto setScriptTarget(_js_jts_dScriptTarget /*ScriptTarget.ES3*/ scriptTarget) noexcept;
		auto setText(js_union<js_string, js_undefined> text = js_undefined(), js_union<double, js_undefined> start = js_undefined(), js_union<double, js_undefined> length = js_undefined()) noexcept;
		auto setTextPos(double textPos) noexcept;
		auto tryScan(js_function<js_unknown /*flags=262144: T ()*/()> callback) noexcept;
	};
	struct _impl_js_jts_dConfigFileDiagnosticsReporter : virtual IObject {
		struct _tcjs_definitions {
		};
		auto onUnRecoverableConfigFileDiagnostic() noexcept;
		void onUnRecoverableConfigFileDiagnostic(js_function<void(_js_jts_dDiagnostic)> v) noexcept;
	};
	struct _impl_js_jts_dParseConfigFileHost : virtual _impl_js_jts_dParseConfigHost, virtual _impl_js_jts_dConfigFileDiagnosticsReporter {
		struct _tcjs_definitions {
		};
		auto getCurrentDirectory() noexcept;
	};
	struct _impl_js_jts_dParsedTsconfig : virtual IObject {
		struct _tcjs_definitions {
		};
		auto raw() noexcept;
		void raw(js_unknown v) noexcept;
	};
	struct _impl_js_jts_dExtendedConfigCacheEntry : virtual IObject {
		struct _tcjs_definitions {
		};
		auto extendedResult() noexcept;
		void extendedResult(_js_jts_dTsConfigSourceFile v) noexcept;
		auto extendedConfig() noexcept;
		void extendedConfig(js_union<_js_jts_dParsedTsconfig, js_undefined> v) noexcept;
	};
	struct _impl_js_jts_dNonRelativeModuleNameResolutionCache : virtual IObject {
		struct _tcjs_definitions {
		};
		auto getOrCreateCacheForModuleName(js_string nonRelativeModuleName, js_union<_js_jts_dResolvedProjectReference, js_undefined> redirectedReference = js_undefined()) noexcept;
	};
	struct _impl_js_jts_dModuleResolutionCache : virtual _impl_js_jts_dNonRelativeModuleNameResolutionCache {
		struct _tcjs_definitions {
		};
		auto getOrCreateCacheForDirectory(js_string directoryName, js_union<_js_jts_dResolvedProjectReference, js_undefined> redirectedReference = js_undefined()) noexcept;
	};
	struct _impl_js_jts_dPerModuleNameCache : virtual IObject {
		struct _tcjs_definitions {
		};
		auto get(js_string directory) noexcept;
		auto set(js_string directory, _js_jts_dResolvedModuleWithFailedLookupLocations result) noexcept;
	};
	struct _impl_js_jts_dFormatDiagnosticsHost : virtual IObject {
		struct _tcjs_definitions {
		};
		auto getCanonicalFileName(js_string fileName) noexcept;
		auto getCurrentDirectory() noexcept;
		auto getNewLine() noexcept;
	};
	struct _impl_js_jts_dResolveProjectReferencePathHost : virtual IObject {
		struct _tcjs_definitions {
		};
		auto fileExists(js_string fileName) noexcept;
	};
	struct _impl_js_jts_dEmitOutput : virtual IObject {
		struct _tcjs_definitions {
		};
		auto outputFiles() noexcept;
		void outputFiles(js::Array<_js_jts_dOutputFile> v) noexcept;
		auto emitSkipped() noexcept;
		void emitSkipped(bool /*false*/ v) noexcept;
	};
	struct _impl_js_jts_dOutputFile : virtual IObject {
		struct _tcjs_definitions {
		};
		auto name() noexcept;
		void name(js_string v) noexcept;
		auto writeByteOrderMark() noexcept;
		void writeByteOrderMark(bool /*false*/ v) noexcept;
		auto text() noexcept;
		void text(js_string v) noexcept;
	};
	struct _impl_js_jts_dBuilderProgramHost : virtual IObject {
		struct _tcjs_definitions {
		};
		auto useCaseSensitiveFileNames() noexcept;
	};
	struct _impl_js_jts_dBuilderProgram : virtual IObject {
		struct _tcjs_definitions {
		};
		auto emit(js_union<_js_jts_dSourceFile, js_undefined> targetSourceFile = js_undefined(), js_union<js_function<void(js_string, js_string, bool /*false*/, js_union<js_function<void(js_string)>, js_undefined>, js_union<js::ReadonlyArray<_js_jts_dSourceFile>, js_undefined>)>, js_undefined> writeFile = js_undefined(), js_union<_js_jts_dCancellationToken, js_undefined> cancellationToken = js_undefined(), js_union<bool /*false*/, js_undefined> emitOnlyDtsFiles = js_undefined(), js_union<_js_jts_dCustomTransformers, js_undefined> customTransformers = js_undefined()) noexcept;
		auto getAllDependencies(_js_jts_dSourceFile sourceFile) noexcept;
		auto getCompilerOptions() noexcept;
		auto getConfigFileParsingDiagnostics() noexcept;
		auto getCurrentDirectory() noexcept;
		auto getDeclarationDiagnostics(js_union<_js_jts_dSourceFile, js_undefined> sourceFile = js_undefined(), js_union<_js_jts_dCancellationToken, js_undefined> cancellationToken = js_undefined()) noexcept;
		auto getGlobalDiagnostics(js_union<_js_jts_dCancellationToken, js_undefined> cancellationToken = js_undefined()) noexcept;
		auto getOptionsDiagnostics(js_union<_js_jts_dCancellationToken, js_undefined> cancellationToken = js_undefined()) noexcept;
		auto getProgram() noexcept;
		auto getSemanticDiagnostics(js_union<_js_jts_dSourceFile, js_undefined> sourceFile = js_undefined(), js_union<_js_jts_dCancellationToken, js_undefined> cancellationToken = js_undefined()) noexcept;
		auto getSourceFile(js_string fileName) noexcept;
		auto getSourceFiles() noexcept;
		auto getSyntacticDiagnostics(js_union<_js_jts_dSourceFile, js_undefined> sourceFile = js_undefined(), js_union<_js_jts_dCancellationToken, js_undefined> cancellationToken = js_undefined()) noexcept;
	};
	struct _impl_js_jts_dSemanticDiagnosticsBuilderProgram : virtual _impl_js_jts_dBuilderProgram {
		struct _tcjs_definitions {
		};
		auto getSemanticDiagnosticsOfNextAffectedFile(js_union<_js_jts_dCancellationToken, js_undefined> cancellationToken = js_undefined(), js_union<js_function<bool /*false*/(_js_jts_dSourceFile)>, js_undefined> ignoreSourceFile = js_undefined()) noexcept;
	};
	struct _impl_js_jts_dEmitAndSemanticDiagnosticsBuilderProgram : virtual _impl_js_jts_dBuilderProgram {
		struct _tcjs_definitions {
		};
		auto emitNextAffectedFile(js_union<js_function<void(js_string, js_string, bool /*false*/, js_union<js_function<void(js_string)>, js_undefined>, js_union<js::ReadonlyArray<_js_jts_dSourceFile>, js_undefined>)>, js_undefined> writeFile = js_undefined(), js_union<_js_jts_dCancellationToken, js_undefined> cancellationToken = js_undefined(), js_union<bool /*false*/, js_undefined> emitOnlyDtsFiles = js_undefined(), js_union<_js_jts_dCustomTransformers, js_undefined> customTransformers = js_undefined()) noexcept;
	};
	struct _impl_js_jts_dWatchHost : virtual IObject {
		struct _tcjs_definitions {
		};
		auto watchDirectory(js_string path, js_function<void(js_string)> callback, js_union<bool /*false*/, js_undefined> recursive = js_undefined()) noexcept;
		auto watchFile(js_string path, js_function<void(js_string, _js_jts_dFileWatcherEventKind /*FileWatcherEventKind.Created*/)> callback, js_union<double, js_undefined> pollingInterval = js_undefined()) noexcept;
	};
	struct _impl_js_jts_dProgramHost : virtual IObject {
		struct _tcjs_definitions {
		};
		auto createProgram() noexcept;
		void createProgram(js_unknown /*flags=524288: CreateProgram<T> ()*/ v) noexcept;
		auto fileExists(js_string path) noexcept;
		auto getCurrentDirectory() noexcept;
		auto getDefaultLibFileName(_js_jts_dCompilerOptions options) noexcept;
		auto getNewLine() noexcept;
		auto readFile(js_string path, js_union<js_string, js_undefined> encoding = js_undefined()) noexcept;
		auto useCaseSensitiveFileNames() noexcept;
	};
	struct _impl_js_jts_dWatchCompilerHost : virtual _impl_js_jts_dWatchHost {
		struct _tcjs_definitions {
		};
	};
	struct _impl_js_jts_dWatchCompilerHostOfFilesAndCompilerOptions : virtual IObject {
		struct _tcjs_definitions {
		};
		auto rootFiles() noexcept;
		void rootFiles(js::Array<js_string> v) noexcept;
		auto options() noexcept;
		void options(_js_jts_dCompilerOptions v) noexcept;
	};
	struct _impl_js_jts_dWatchCompilerHostOfConfigFile : virtual _impl_js_jts_dConfigFileDiagnosticsReporter {
		struct _tcjs_definitions {
		};
		auto configFileName() noexcept;
		void configFileName(js_string v) noexcept;
		auto readDirectory(js_string path, js_union<js::ReadonlyArray<js_string>, js_undefined> extensions = js_undefined(), js_union<js::ReadonlyArray<js_string>, js_undefined> exclude = js_undefined(), js_union<js::ReadonlyArray<js_string>, js_undefined> include = js_undefined(), js_union<double, js_undefined> depth = js_undefined()) noexcept;
	};
	struct _impl_js_jts_dWatch : virtual IObject {
		struct _tcjs_definitions {
		};
		auto getProgram() noexcept;
	};
	struct _impl_js_jts_dWatchOfConfigFile : virtual IObject {
		struct _tcjs_definitions {
		};
	};
	struct _impl_js_jts_dWatchOfFilesAndCompilerOptions : virtual IObject {
		struct _tcjs_definitions {
		};
		auto updateRootFileNames(js::Array<js_string> fileNames) noexcept;
	};
	struct _impl_js_jts_dserver : virtual IObject {
		struct _tcjs_definitions {
			using TypingInstallerResponse = _js_jts_dserver_dTypingInstallerResponse;
			using TypingInstallerRequestWithProjectName = _js_jts_dserver_dTypingInstallerRequestWithProjectName;
			using DiscoverTypings = _js_jts_dserver_dDiscoverTypings;
			using CloseProject = _js_jts_dserver_dCloseProject;
			using TypesRegistryRequest = _js_jts_dserver_dTypesRegistryRequest;
			using InstallPackageRequest = _js_jts_dserver_dInstallPackageRequest;
			using PackageInstalledResponse = _js_jts_dserver_dPackageInstalledResponse;
			using InitializationFailedResponse = _js_jts_dserver_dInitializationFailedResponse;
			using ProjectResponse = _js_jts_dserver_dProjectResponse;
			using InvalidateCachedTypings = _js_jts_dserver_dInvalidateCachedTypings;
			using InstallTypes = _js_jts_dserver_dInstallTypes;
			using BeginInstallTypes = _js_jts_dserver_dBeginInstallTypes;
			using EndInstallTypes = _js_jts_dserver_dEndInstallTypes;
			using SetTypings = _js_jts_dserver_dSetTypings;
		};
	};
	struct _impl_js_jts_dserver_dTypingInstallerResponse : virtual IObject {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
	};
	struct _impl_js_jts_dserver_dTypingInstallerRequestWithProjectName : virtual IObject {
		struct _tcjs_definitions {
		};
		auto projectName() noexcept;
	};
	struct _impl_js_jts_dserver_dDiscoverTypings : virtual _impl_js_jts_dserver_dTypingInstallerRequestWithProjectName {
		struct _tcjs_definitions {
		};
		auto fileNames() noexcept;
		auto projectRootPath() noexcept;
		auto compilerOptions() noexcept;
		auto typeAcquisition() noexcept;
		auto unresolvedImports() noexcept;
		auto kind() noexcept;
	};
	struct _impl_js_jts_dserver_dCloseProject : virtual _impl_js_jts_dserver_dTypingInstallerRequestWithProjectName {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
	};
	struct _impl_js_jts_dserver_dTypesRegistryRequest : virtual IObject {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
	};
	struct _impl_js_jts_dserver_dInstallPackageRequest : virtual _impl_js_jts_dserver_dTypingInstallerRequestWithProjectName {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		auto fileName() noexcept;
		auto packageName() noexcept;
		auto projectRootPath() noexcept;
	};
	struct _impl_js_jts_dserver_dProjectResponse : virtual _impl_js_jts_dserver_dTypingInstallerResponse {
		struct _tcjs_definitions {
		};
		auto projectName() noexcept;
	};
	struct _impl_js_jts_dserver_dPackageInstalledResponse : virtual _impl_js_jts_dserver_dProjectResponse {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		auto success() noexcept;
		auto message() noexcept;
	};
	struct _impl_js_jts_dserver_dInitializationFailedResponse : virtual _impl_js_jts_dserver_dTypingInstallerResponse {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		auto message() noexcept;
	};
	struct _impl_js_jts_dserver_dInvalidateCachedTypings : virtual _impl_js_jts_dserver_dProjectResponse {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
	};
	struct _impl_js_jts_dserver_dInstallTypes : virtual _impl_js_jts_dserver_dProjectResponse {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		auto eventId() noexcept;
		auto typingsInstallerVersion() noexcept;
		auto packagesToInstall() noexcept;
	};
	struct _impl_js_jts_dserver_dBeginInstallTypes : virtual _impl_js_jts_dserver_dInstallTypes {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
	};
	struct _impl_js_jts_dserver_dEndInstallTypes : virtual _impl_js_jts_dserver_dInstallTypes {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		auto installSuccess() noexcept;
	};
	struct _impl_js_jts_dserver_dSetTypings : virtual _impl_js_jts_dserver_dProjectResponse {
		struct _tcjs_definitions {
		};
		auto typeAcquisition() noexcept;
		auto compilerOptions() noexcept;
		auto typings() noexcept;
		auto unresolvedImports() noexcept;
		auto kind() noexcept;
	};
	struct _impl_js_jts_dSourceFileLike : virtual IObject {
		struct _tcjs_definitions {
		};
		auto getLineAndCharacterOfPosition(double pos) noexcept;
	};
	struct _impl_js_jts_dIScriptSnapshot : virtual IObject {
		struct _tcjs_definitions {
		};
		auto getChangeRange(_js_jts_dIScriptSnapshot oldSnapshot) noexcept;
		auto getLength() noexcept;
		auto getText(double start, double end) noexcept;
	};
	struct _impl_js_jts_dScriptSnapshot : virtual IObject {
		struct _tcjs_definitions {
			static auto fromString(js_string text) noexcept;
		};
	};
	struct _impl_js_jts_dPreProcessedFileInfo : virtual IObject {
		struct _tcjs_definitions {
		};
		auto referencedFiles() noexcept;
		void referencedFiles(js::Array<_js_jts_dFileReference> v) noexcept;
		auto typeReferenceDirectives() noexcept;
		void typeReferenceDirectives(js::Array<_js_jts_dFileReference> v) noexcept;
		auto libReferenceDirectives() noexcept;
		void libReferenceDirectives(js::Array<_js_jts_dFileReference> v) noexcept;
		auto importedFiles() noexcept;
		void importedFiles(js::Array<_js_jts_dFileReference> v) noexcept;
		auto isLibFile() noexcept;
		void isLibFile(bool /*false*/ v) noexcept;
	};
	struct _impl_js_jts_dHostCancellationToken : virtual IObject {
		struct _tcjs_definitions {
		};
		auto isCancellationRequested() noexcept;
	};
	struct _impl_js_jts_dInstallPackageOptions : virtual IObject {
		struct _tcjs_definitions {
		};
		auto fileName() noexcept;
		void fileName(js_unknown /*flags=2097152: Path ()*/ v) noexcept;
		auto packageName() noexcept;
		void packageName(js_string v) noexcept;
	};
	struct _impl_js_jts_dLanguageServiceHost : virtual _impl_js_jts_dGetEffectiveTypeRootsHost {
		struct _tcjs_definitions {
		};
		auto getCompilationSettings() noexcept;
		auto getCurrentDirectory() noexcept;
		auto getDefaultLibFileName(_js_jts_dCompilerOptions options) noexcept;
		auto getScriptFileNames() noexcept;
		auto getScriptSnapshot(js_string fileName) noexcept;
		auto getScriptVersion(js_string fileName) noexcept;
	};
	struct _impl_js_jts_dLanguageService : virtual IObject {
		struct _tcjs_definitions {
		};
		auto applyCodeActionCommand(_js_jts_dInstallPackageAction action, js_union<_js_jts_dFormatCodeSettings, js_undefined> formatSettings = js_undefined()) noexcept;
		auto applyCodeActionCommand(js::Array<_js_jts_dInstallPackageAction> action, js_union<_js_jts_dFormatCodeSettings, js_undefined> formatSettings = js_undefined()) noexcept;
		auto applyCodeActionCommand(js_string fileName, _js_jts_dInstallPackageAction action) noexcept;
		auto applyCodeActionCommand(js_string fileName, js::Array<_js_jts_dInstallPackageAction> action) noexcept;
		auto applyCodeActionCommand(js_string fileName, js_union<_js_jts_dInstallPackageAction, js::Array<_js_jts_dInstallPackageAction>> action) noexcept;
		auto applyCodeActionCommand(js_union<_js_jts_dInstallPackageAction, js::Array<_js_jts_dInstallPackageAction>> action, js_union<_js_jts_dFormatCodeSettings, js_undefined> formatSettings = js_undefined()) noexcept;
		auto cleanupSemanticCache() noexcept;
		auto dispose() noexcept;
		auto findReferences(js_string fileName, double position) noexcept;
		auto findRenameLocations(js_string fileName, double position, bool /*false*/ findInStrings, bool /*false*/ findInComments, js_union<bool /*false*/, js_undefined> providePrefixAndSuffixTextForRename = js_undefined()) noexcept;
		auto getApplicableRefactors(js_string fileName, js_union<_js_jts_dTextRange, double> positionOrRange, js_union<_js_jts_dUserPreferences, js_undefined> preferences = js_undefined()) noexcept;
		auto getBraceMatchingAtPosition(js_string fileName, double position) noexcept;
		auto getBreakpointStatementAtPosition(js_string fileName, double position) noexcept;
		auto getCodeFixesAtPosition(js_string fileName, double start, double end, js::ReadonlyArray<double> errorCodes, _js_jts_dFormatCodeSettings formatOptions, _js_jts_dUserPreferences preferences) noexcept;
		auto getCombinedCodeFix(_js_jts_dCombinedCodeFixScope scope, js_unknown /*flags=524288: {} ()*/ fixId, _js_jts_dFormatCodeSettings formatOptions, _js_jts_dUserPreferences preferences) noexcept;
		auto getCompilerOptionsDiagnostics() noexcept;
		auto getCompletionEntryDetails(js_string fileName, double position, js_string name, js_union<_js_jts_dFormatCodeOptions, _js_jts_dFormatCodeSettings, js_undefined> formatOptions = js_undefined(), js_union<js_string, js_undefined> source = js_undefined(), js_union<_js_jts_dUserPreferences, js_undefined> preferences = js_undefined()) noexcept;
		auto getCompletionEntrySymbol(js_string fileName, double position, js_string name, js_union<js_string, js_undefined> source = js_undefined()) noexcept;
		auto getCompletionsAtPosition(js_string fileName, double position, js_union<_js_jts_dGetCompletionsAtPositionOptions, js_undefined> options = js_undefined()) noexcept;
		auto getDefinitionAndBoundSpan(js_string fileName, double position) noexcept;
		auto getDefinitionAtPosition(js_string fileName, double position) noexcept;
		auto getDocCommentTemplateAtPosition(js_string fileName, double position) noexcept;
		auto getDocumentHighlights(js_string fileName, double position, js::Array<js_string> filesToSearch) noexcept;
		auto getEditsForFileRename(js_string oldFilePath, js_string newFilePath, _js_jts_dFormatCodeSettings formatOptions, js_union<_js_jts_dUserPreferences, js_undefined> preferences = js_undefined()) noexcept;
		auto getEditsForRefactor(js_string fileName, _js_jts_dFormatCodeSettings formatOptions, js_union<_js_jts_dTextRange, double> positionOrRange, js_string refactorName, js_string actionName, js_union<_js_jts_dUserPreferences, js_undefined> preferences = js_undefined()) noexcept;
		auto getEmitOutput(js_string fileName, js_union<bool /*false*/, js_undefined> emitOnlyDtsFiles = js_undefined()) noexcept;
		auto getEncodedSemanticClassifications(js_string fileName, _js_jts_dTextSpan span) noexcept;
		auto getEncodedSyntacticClassifications(js_string fileName, _js_jts_dTextSpan span) noexcept;
		auto getFormattingEditsAfterKeystroke(js_string fileName, double position, js_string key, js_union<_js_jts_dFormatCodeOptions, _js_jts_dFormatCodeSettings> options) noexcept;
		auto getFormattingEditsForDocument(js_string fileName, js_union<_js_jts_dFormatCodeOptions, _js_jts_dFormatCodeSettings> options) noexcept;
		auto getFormattingEditsForRange(js_string fileName, double start, double end, js_union<_js_jts_dFormatCodeOptions, _js_jts_dFormatCodeSettings> options) noexcept;
		auto getImplementationAtPosition(js_string fileName, double position) noexcept;
		auto getIndentationAtPosition(js_string fileName, double position, js_union<_js_jts_dEditorOptions, _js_jts_dEditorSettings> options) noexcept;
		auto getJsxClosingTagAtPosition(js_string fileName, double position) noexcept;
		auto getNameOrDottedNameSpan(js_string fileName, double startPos, double endPos) noexcept;
		auto getNavigateToItems(js_string searchValue, js_union<double, js_undefined> maxResultCount = js_undefined(), js_union<js_string, js_undefined> fileName = js_undefined(), js_union<bool /*false*/, js_undefined> excludeDtsFiles = js_undefined()) noexcept;
		auto getNavigationBarItems(js_string fileName) noexcept;
		auto getNavigationTree(js_string fileName) noexcept;
		auto getOccurrencesAtPosition(js_string fileName, double position) noexcept;
		auto getOutliningSpans(js_string fileName) noexcept;
		auto getProgram() noexcept;
		auto getQuickInfoAtPosition(js_string fileName, double position) noexcept;
		auto getReferencesAtPosition(js_string fileName, double position) noexcept;
		auto getRenameInfo(js_string fileName, double position, js_union<_js_jts_dRenameInfoOptions, js_undefined> options = js_undefined()) noexcept;
		auto getSemanticClassifications(js_string fileName, _js_jts_dTextSpan span) noexcept;
		auto getSemanticDiagnostics(js_string fileName) noexcept;
		auto getSignatureHelpItems(js_string fileName, double position, js_union<_js_jts_dSignatureHelpItemsOptions, js_undefined> options = js_undefined()) noexcept;
		auto getSmartSelectionRange(js_string fileName, double position) noexcept;
		auto getSpanOfEnclosingComment(js_string fileName, double position, bool /*false*/ onlyMultiLine) noexcept;
		auto getSuggestionDiagnostics(js_string fileName) noexcept;
		auto getSyntacticClassifications(js_string fileName, _js_jts_dTextSpan span) noexcept;
		auto getSyntacticDiagnostics(js_string fileName) noexcept;
		auto getTodoComments(js_string fileName, js::Array<_js_jts_dTodoCommentDescriptor> descriptors) noexcept;
		auto getTypeDefinitionAtPosition(js_string fileName, double position) noexcept;
		auto isValidBraceCompletionAtPosition(js_string fileName, double position, double openingBrace) noexcept;
		auto organizeImports(_js_jts_dCombinedCodeFixScope scope, _js_jts_dFormatCodeSettings formatOptions, js_union<_js_jts_dUserPreferences, js_undefined> preferences = js_undefined()) noexcept;
	};
	struct _impl_js_jts_dJsxClosingTagInfo : virtual IObject {
		struct _tcjs_definitions {
		};
		auto newText() noexcept;
	};
	struct _impl_js_jts_dCombinedCodeFixScope : virtual IObject {
		struct _tcjs_definitions {
		};
		auto type() noexcept;
		void type(js_string /*"file"*/ v) noexcept;
		auto fileName() noexcept;
		void fileName(js_string v) noexcept;
	};
	struct _impl_js_jts_dGetCompletionsAtPositionOptions : virtual _impl_js_jts_dUserPreferences {
		struct _tcjs_definitions {
		};
	};
	struct _impl_js_jts_dSignatureHelpItemsOptions : virtual IObject {
		struct _tcjs_definitions {
		};
	};
	struct _impl_js_jts_dSignatureHelpInvokedReason : virtual IObject {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(js_string /*"invoked"*/ v) noexcept;
	};
	struct _impl_js_jts_dSignatureHelpCharacterTypedReason : virtual IObject {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(js_string /*"characterTyped"*/ v) noexcept;
		auto triggerCharacter() noexcept;
		void triggerCharacter(js_string /*"<"*/ v) noexcept;
	};
	struct _impl_js_jts_dSignatureHelpRetriggeredReason : virtual IObject {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(js_string /*"retrigger"*/ v) noexcept;
	};
	struct _impl_js_jts_dApplyCodeActionCommandResult : virtual IObject {
		struct _tcjs_definitions {
		};
		auto successMessage() noexcept;
		void successMessage(js_string v) noexcept;
	};
	struct _impl_js_jts_dClassifications : virtual IObject {
		struct _tcjs_definitions {
		};
		auto spans() noexcept;
		void spans(js::Array<double> v) noexcept;
		auto endOfLineState() noexcept;
		void endOfLineState(_js_jts_dEndOfLineState /*EndOfLineState.None*/ v) noexcept;
	};
	struct _impl_js_jts_dClassifiedSpan : virtual IObject {
		struct _tcjs_definitions {
		};
		auto textSpan() noexcept;
		void textSpan(_js_jts_dTextSpan v) noexcept;
		auto classificationType() noexcept;
		void classificationType(_js_jts_dClassificationTypeNames /*ClassificationTypeNames.comment*/ v) noexcept;
	};
	struct _impl_js_jts_dNavigationBarItem : virtual IObject {
		struct _tcjs_definitions {
		};
		auto text() noexcept;
		void text(js_string v) noexcept;
		auto kind() noexcept;
		void kind(_js_jts_dScriptElementKind /*ScriptElementKind.unknown*/ v) noexcept;
		auto kindModifiers() noexcept;
		void kindModifiers(js_string v) noexcept;
		auto spans() noexcept;
		void spans(js::Array<_js_jts_dTextSpan> v) noexcept;
		auto childItems() noexcept;
		void childItems(js::Array<_js_jts_dNavigationBarItem> v) noexcept;
		auto indent() noexcept;
		void indent(double v) noexcept;
		auto bolded() noexcept;
		void bolded(bool /*false*/ v) noexcept;
		auto grayed() noexcept;
		void grayed(bool /*false*/ v) noexcept;
	};
	struct _impl_js_jts_dNavigationTree : virtual IObject {
		struct _tcjs_definitions {
		};
		auto text() noexcept;
		void text(js_string v) noexcept;
		auto kind() noexcept;
		void kind(_js_jts_dScriptElementKind /*ScriptElementKind.unknown*/ v) noexcept;
		auto kindModifiers() noexcept;
		void kindModifiers(js_string v) noexcept;
		auto spans() noexcept;
		void spans(js::Array<_js_jts_dTextSpan> v) noexcept;
		auto nameSpan() noexcept;
		void nameSpan(js_union<_js_jts_dTextSpan, js_undefined> v) noexcept;
	};
	struct _impl_js_jts_dTodoCommentDescriptor : virtual IObject {
		struct _tcjs_definitions {
		};
		auto text() noexcept;
		void text(js_string v) noexcept;
		auto priority() noexcept;
		void priority(double v) noexcept;
	};
	struct _impl_js_jts_dTodoComment : virtual IObject {
		struct _tcjs_definitions {
		};
		auto descriptor() noexcept;
		void descriptor(_js_jts_dTodoCommentDescriptor v) noexcept;
		auto message() noexcept;
		void message(js_string v) noexcept;
		auto position() noexcept;
		void position(double v) noexcept;
	};
	struct _impl_js_jts_dTextChange : virtual IObject {
		struct _tcjs_definitions {
		};
		auto span() noexcept;
		void span(_js_jts_dTextSpan v) noexcept;
		auto newText() noexcept;
		void newText(js_string v) noexcept;
	};
	struct _impl_js_jts_dFileTextChanges : virtual IObject {
		struct _tcjs_definitions {
		};
		auto fileName() noexcept;
		void fileName(js_string v) noexcept;
		auto textChanges() noexcept;
		void textChanges(js::Array<_js_jts_dTextChange> v) noexcept;
	};
	struct _impl_js_jts_dCodeAction : virtual IObject {
		struct _tcjs_definitions {
		};
		auto description() noexcept;
		void description(js_string v) noexcept;
		auto changes() noexcept;
		void changes(js::Array<_js_jts_dFileTextChanges> v) noexcept;
	};
	struct _impl_js_jts_dCodeFixAction : virtual _impl_js_jts_dCodeAction {
		struct _tcjs_definitions {
		};
		auto fixName() noexcept;
		void fixName(js_string v) noexcept;
	};
	struct _impl_js_jts_dCombinedCodeActions : virtual IObject {
		struct _tcjs_definitions {
		};
		auto changes() noexcept;
		void changes(js::ReadonlyArray<_js_jts_dFileTextChanges> v) noexcept;
	};
	struct _impl_js_jts_dInstallPackageAction : virtual IObject {
		struct _tcjs_definitions {
		};
	};
	struct _impl_js_jts_dApplicableRefactorInfo : virtual IObject {
		struct _tcjs_definitions {
		};
		auto name() noexcept;
		void name(js_string v) noexcept;
		auto description() noexcept;
		void description(js_string v) noexcept;
		auto actions() noexcept;
		void actions(js::Array<_js_jts_dRefactorActionInfo> v) noexcept;
	};
	struct _impl_js_jts_dRefactorActionInfo : virtual IObject {
		struct _tcjs_definitions {
		};
		auto name() noexcept;
		void name(js_string v) noexcept;
		auto description() noexcept;
		void description(js_string v) noexcept;
	};
	struct _impl_js_jts_dRefactorEditInfo : virtual IObject {
		struct _tcjs_definitions {
		};
		auto edits() noexcept;
		void edits(js::Array<_js_jts_dFileTextChanges> v) noexcept;
	};
	struct _impl_js_jts_dTextInsertion : virtual IObject {
		struct _tcjs_definitions {
		};
		auto newText() noexcept;
		void newText(js_string v) noexcept;
		auto caretOffset() noexcept;
		void caretOffset(double v) noexcept;
	};
	struct _impl_js_jts_dDocumentSpan : virtual IObject {
		struct _tcjs_definitions {
		};
		auto textSpan() noexcept;
		void textSpan(_js_jts_dTextSpan v) noexcept;
		auto fileName() noexcept;
		void fileName(js_string v) noexcept;
	};
	struct _impl_js_jts_dRenameLocation : virtual _impl_js_jts_dDocumentSpan {
		struct _tcjs_definitions {
		};
	};
	struct _impl_js_jts_dReferenceEntry : virtual _impl_js_jts_dDocumentSpan {
		struct _tcjs_definitions {
		};
		auto isWriteAccess() noexcept;
		void isWriteAccess(bool /*false*/ v) noexcept;
		auto isDefinition() noexcept;
		void isDefinition(bool /*false*/ v) noexcept;
	};
	struct _impl_js_jts_dImplementationLocation : virtual _impl_js_jts_dDocumentSpan {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dScriptElementKind /*ScriptElementKind.unknown*/ v) noexcept;
		auto displayParts() noexcept;
		void displayParts(js::Array<_js_jts_dSymbolDisplayPart> v) noexcept;
	};
	struct _impl_js_jts_dDocumentHighlights : virtual IObject {
		struct _tcjs_definitions {
		};
		auto fileName() noexcept;
		void fileName(js_string v) noexcept;
		auto highlightSpans() noexcept;
		void highlightSpans(js::Array<_js_jts_dHighlightSpan> v) noexcept;
	};
	struct _impl_js_jts_dHighlightSpan : virtual IObject {
		struct _tcjs_definitions {
		};
		auto textSpan() noexcept;
		void textSpan(_js_jts_dTextSpan v) noexcept;
		auto kind() noexcept;
		void kind(_js_jts_dHighlightSpanKind /*HighlightSpanKind.none*/ v) noexcept;
	};
	struct _impl_js_jts_dNavigateToItem : virtual IObject {
		struct _tcjs_definitions {
		};
		auto name() noexcept;
		void name(js_string v) noexcept;
		auto kind() noexcept;
		void kind(_js_jts_dScriptElementKind /*ScriptElementKind.unknown*/ v) noexcept;
		auto kindModifiers() noexcept;
		void kindModifiers(js_string v) noexcept;
		auto matchKind() noexcept;
		void matchKind(js_string /*"exact"*/ v) noexcept;
		auto isCaseSensitive() noexcept;
		void isCaseSensitive(bool /*false*/ v) noexcept;
		auto fileName() noexcept;
		void fileName(js_string v) noexcept;
		auto textSpan() noexcept;
		void textSpan(_js_jts_dTextSpan v) noexcept;
		auto containerName() noexcept;
		void containerName(js_string v) noexcept;
		auto containerKind() noexcept;
		void containerKind(_js_jts_dScriptElementKind /*ScriptElementKind.unknown*/ v) noexcept;
	};
	struct _impl_js_jts_dEditorOptions : virtual IObject {
		struct _tcjs_definitions {
		};
		auto IndentSize() noexcept;
		void IndentSize(double v) noexcept;
		auto TabSize() noexcept;
		void TabSize(double v) noexcept;
		auto NewLineCharacter() noexcept;
		void NewLineCharacter(js_string v) noexcept;
		auto ConvertTabsToSpaces() noexcept;
		void ConvertTabsToSpaces(bool /*false*/ v) noexcept;
		auto IndentStyle() noexcept;
		void IndentStyle(_js_jts_dIndentStyle /*IndentStyle.None*/ v) noexcept;
	};
	struct _impl_js_jts_dEditorSettings : virtual IObject {
		struct _tcjs_definitions {
		};
	};
	struct _impl_js_jts_dFormatCodeOptions : virtual _impl_js_jts_dEditorOptions {
		struct _tcjs_definitions {
		};
		auto InsertSpaceAfterCommaDelimiter() noexcept;
		void InsertSpaceAfterCommaDelimiter(bool /*false*/ v) noexcept;
		auto InsertSpaceAfterSemicolonInForStatements() noexcept;
		void InsertSpaceAfterSemicolonInForStatements(bool /*false*/ v) noexcept;
		auto InsertSpaceBeforeAndAfterBinaryOperators() noexcept;
		void InsertSpaceBeforeAndAfterBinaryOperators(bool /*false*/ v) noexcept;
		auto InsertSpaceAfterKeywordsInControlFlowStatements() noexcept;
		void InsertSpaceAfterKeywordsInControlFlowStatements(bool /*false*/ v) noexcept;
		auto InsertSpaceAfterFunctionKeywordForAnonymousFunctions() noexcept;
		void InsertSpaceAfterFunctionKeywordForAnonymousFunctions(bool /*false*/ v) noexcept;
		auto InsertSpaceAfterOpeningAndBeforeClosingNonemptyParenthesis() noexcept;
		void InsertSpaceAfterOpeningAndBeforeClosingNonemptyParenthesis(bool /*false*/ v) noexcept;
		auto InsertSpaceAfterOpeningAndBeforeClosingNonemptyBrackets() noexcept;
		void InsertSpaceAfterOpeningAndBeforeClosingNonemptyBrackets(bool /*false*/ v) noexcept;
		auto InsertSpaceAfterOpeningAndBeforeClosingTemplateStringBraces() noexcept;
		void InsertSpaceAfterOpeningAndBeforeClosingTemplateStringBraces(bool /*false*/ v) noexcept;
		auto PlaceOpenBraceOnNewLineForFunctions() noexcept;
		void PlaceOpenBraceOnNewLineForFunctions(bool /*false*/ v) noexcept;
		auto PlaceOpenBraceOnNewLineForControlBlocks() noexcept;
		void PlaceOpenBraceOnNewLineForControlBlocks(bool /*false*/ v) noexcept;
	};
	struct _impl_js_jts_dFormatCodeSettings : virtual _impl_js_jts_dEditorSettings {
		struct _tcjs_definitions {
		};
	};
	struct _impl_js_jts_dDefinitionInfo : virtual _impl_js_jts_dDocumentSpan {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dScriptElementKind /*ScriptElementKind.unknown*/ v) noexcept;
		auto name() noexcept;
		void name(js_string v) noexcept;
		auto containerKind() noexcept;
		void containerKind(_js_jts_dScriptElementKind /*ScriptElementKind.unknown*/ v) noexcept;
		auto containerName() noexcept;
		void containerName(js_string v) noexcept;
	};
	struct _impl_js_jts_dDefinitionInfoAndBoundSpan : virtual IObject {
		struct _tcjs_definitions {
		};
		auto textSpan() noexcept;
		void textSpan(_js_jts_dTextSpan v) noexcept;
	};
	struct _impl_js_jts_dReferencedSymbolDefinitionInfo : virtual _impl_js_jts_dDefinitionInfo {
		struct _tcjs_definitions {
		};
		auto displayParts() noexcept;
		void displayParts(js::Array<_js_jts_dSymbolDisplayPart> v) noexcept;
	};
	struct _impl_js_jts_dReferencedSymbol : virtual IObject {
		struct _tcjs_definitions {
		};
		auto definition() noexcept;
		void definition(_js_jts_dReferencedSymbolDefinitionInfo v) noexcept;
		auto references() noexcept;
		void references(js::Array<_js_jts_dReferenceEntry> v) noexcept;
	};
	struct _impl_js_jts_dSymbolDisplayPart : virtual IObject {
		struct _tcjs_definitions {
		};
		auto text() noexcept;
		void text(js_string v) noexcept;
		auto kind() noexcept;
		void kind(js_string v) noexcept;
	};
	struct _impl_js_jts_dJSDocTagInfo : virtual IObject {
		struct _tcjs_definitions {
		};
		auto name() noexcept;
		void name(js_string v) noexcept;
	};
	struct _impl_js_jts_dQuickInfo : virtual IObject {
		struct _tcjs_definitions {
		};
		auto kind() noexcept;
		void kind(_js_jts_dScriptElementKind /*ScriptElementKind.unknown*/ v) noexcept;
		auto kindModifiers() noexcept;
		void kindModifiers(js_string v) noexcept;
		auto textSpan() noexcept;
		void textSpan(_js_jts_dTextSpan v) noexcept;
	};
	struct _impl_js_jts_dRenameInfoSuccess : virtual IObject {
		struct _tcjs_definitions {
		};
		auto canRename() noexcept;
		void canRename(bool /*true*/ v) noexcept;
		auto displayName() noexcept;
		void displayName(js_string v) noexcept;
		auto fullDisplayName() noexcept;
		void fullDisplayName(js_string v) noexcept;
		auto kind() noexcept;
		void kind(_js_jts_dScriptElementKind /*ScriptElementKind.unknown*/ v) noexcept;
		auto kindModifiers() noexcept;
		void kindModifiers(js_string v) noexcept;
		auto triggerSpan() noexcept;
		void triggerSpan(_js_jts_dTextSpan v) noexcept;
	};
	struct _impl_js_jts_dRenameInfoFailure : virtual IObject {
		struct _tcjs_definitions {
		};
		auto canRename() noexcept;
		void canRename(bool /*false*/ v) noexcept;
		auto localizedErrorMessage() noexcept;
		void localizedErrorMessage(js_string v) noexcept;
	};
	struct _impl_js_jts_dRenameInfoOptions : virtual IObject {
		struct _tcjs_definitions {
		};
	};
	struct _impl_js_jts_dSignatureHelpParameter : virtual IObject {
		struct _tcjs_definitions {
		};
		auto name() noexcept;
		void name(js_string v) noexcept;
		auto documentation() noexcept;
		void documentation(js::Array<_js_jts_dSymbolDisplayPart> v) noexcept;
		auto displayParts() noexcept;
		void displayParts(js::Array<_js_jts_dSymbolDisplayPart> v) noexcept;
		auto isOptional() noexcept;
		void isOptional(bool /*false*/ v) noexcept;
	};
	struct _impl_js_jts_dSelectionRange : virtual IObject {
		struct _tcjs_definitions {
		};
		auto textSpan() noexcept;
		void textSpan(_js_jts_dTextSpan v) noexcept;
	};
	struct _impl_js_jts_dSignatureHelpItem : virtual IObject {
		struct _tcjs_definitions {
		};
		auto isVariadic() noexcept;
		void isVariadic(bool /*false*/ v) noexcept;
		auto prefixDisplayParts() noexcept;
		void prefixDisplayParts(js::Array<_js_jts_dSymbolDisplayPart> v) noexcept;
		auto suffixDisplayParts() noexcept;
		void suffixDisplayParts(js::Array<_js_jts_dSymbolDisplayPart> v) noexcept;
		auto separatorDisplayParts() noexcept;
		void separatorDisplayParts(js::Array<_js_jts_dSymbolDisplayPart> v) noexcept;
		auto parameters() noexcept;
		void parameters(js::Array<_js_jts_dSignatureHelpParameter> v) noexcept;
		auto documentation() noexcept;
		void documentation(js::Array<_js_jts_dSymbolDisplayPart> v) noexcept;
		auto tags() noexcept;
		void tags(js::Array<_js_jts_dJSDocTagInfo> v) noexcept;
	};
	struct _impl_js_jts_dSignatureHelpItems : virtual IObject {
		struct _tcjs_definitions {
		};
		auto items() noexcept;
		void items(js::Array<_js_jts_dSignatureHelpItem> v) noexcept;
		auto applicableSpan() noexcept;
		void applicableSpan(_js_jts_dTextSpan v) noexcept;
		auto selectedItemIndex() noexcept;
		void selectedItemIndex(double v) noexcept;
		auto argumentIndex() noexcept;
		void argumentIndex(double v) noexcept;
		auto argumentCount() noexcept;
		void argumentCount(double v) noexcept;
	};
	struct _impl_js_jts_dCompletionInfo : virtual IObject {
		struct _tcjs_definitions {
		};
		auto isGlobalCompletion() noexcept;
		void isGlobalCompletion(bool /*false*/ v) noexcept;
		auto isMemberCompletion() noexcept;
		void isMemberCompletion(bool /*false*/ v) noexcept;
		auto isNewIdentifierLocation() noexcept;
		void isNewIdentifierLocation(bool /*false*/ v) noexcept;
		auto entries() noexcept;
		void entries(js::Array<_js_jts_dCompletionEntry> v) noexcept;
	};
	struct _impl_js_jts_dCompletionEntry : virtual IObject {
		struct _tcjs_definitions {
		};
		auto name() noexcept;
		void name(js_string v) noexcept;
		auto kind() noexcept;
		void kind(_js_jts_dScriptElementKind /*ScriptElementKind.unknown*/ v) noexcept;
		auto sortText() noexcept;
		void sortText(js_string v) noexcept;
	};
	struct _impl_js_jts_dCompletionEntryDetails : virtual IObject {
		struct _tcjs_definitions {
		};
		auto name() noexcept;
		void name(js_string v) noexcept;
		auto kind() noexcept;
		void kind(_js_jts_dScriptElementKind /*ScriptElementKind.unknown*/ v) noexcept;
		auto kindModifiers() noexcept;
		void kindModifiers(js_string v) noexcept;
		auto displayParts() noexcept;
		void displayParts(js::Array<_js_jts_dSymbolDisplayPart> v) noexcept;
	};
	struct _impl_js_jts_dOutliningSpan : virtual IObject {
		struct _tcjs_definitions {
		};
		auto textSpan() noexcept;
		void textSpan(_js_jts_dTextSpan v) noexcept;
		auto hintSpan() noexcept;
		void hintSpan(_js_jts_dTextSpan v) noexcept;
		auto bannerText() noexcept;
		void bannerText(js_string v) noexcept;
		auto autoCollapse() noexcept;
		void autoCollapse(bool /*false*/ v) noexcept;
		auto kind() noexcept;
		void kind(_js_jts_dOutliningSpanKind /*OutliningSpanKind.Comment*/ v) noexcept;
	};
	struct _impl_js_jts_dClassificationResult : virtual IObject {
		struct _tcjs_definitions {
		};
		auto finalLexState() noexcept;
		void finalLexState(_js_jts_dEndOfLineState /*EndOfLineState.None*/ v) noexcept;
		auto entries() noexcept;
		void entries(js::Array<_js_jts_dClassificationInfo> v) noexcept;
	};
	struct _impl_js_jts_dClassificationInfo : virtual IObject {
		struct _tcjs_definitions {
		};
		auto length() noexcept;
		void length(double v) noexcept;
		auto classification() noexcept;
		void classification(_js_jts_dTokenClass /*TokenClass.Punctuation*/ v) noexcept;
	};
	struct _impl_js_jts_dClassifier : virtual IObject {
		struct _tcjs_definitions {
		};
		auto getClassificationsForLine(js_string text, _js_jts_dEndOfLineState /*EndOfLineState.None*/ lexState, bool /*false*/ syntacticClassifierAbsent) noexcept;
		auto getEncodedLexicalClassifications(js_string text, _js_jts_dEndOfLineState /*EndOfLineState.None*/ endOfLineState, bool /*false*/ syntacticClassifierAbsent) noexcept;
	};
	struct _impl_js_jts_dDocumentRegistry : virtual IObject {
		struct _tcjs_definitions {
		};
		auto acquireDocument(js_string fileName, _js_jts_dCompilerOptions compilationSettings, _js_jts_dIScriptSnapshot scriptSnapshot, js_string version, js_union<_js_jts_dScriptKind /*ScriptKind.TS*/, js_undefined> scriptKind = js_undefined()) noexcept;
		auto acquireDocumentWithKey(js_string fileName, js_unknown /*flags=2097152: Path ()*/ path, _js_jts_dCompilerOptions compilationSettings, js_unknown /*flags=2097152: DocumentRegistryBucketKey ()*/ key, _js_jts_dIScriptSnapshot scriptSnapshot, js_string version, js_union<_js_jts_dScriptKind /*ScriptKind.TS*/, js_undefined> scriptKind = js_undefined()) noexcept;
		auto getKeyForCompilationSettings(_js_jts_dCompilerOptions settings) noexcept;
		auto releaseDocument(js_string fileName, _js_jts_dCompilerOptions compilationSettings) noexcept;
		auto releaseDocumentWithKey(js_unknown /*flags=2097152: Path ()*/ path, js_unknown /*flags=2097152: DocumentRegistryBucketKey ()*/ key) noexcept;
		auto reportStats() noexcept;
		auto updateDocument(js_string fileName, _js_jts_dCompilerOptions compilationSettings, _js_jts_dIScriptSnapshot scriptSnapshot, js_string version, js_union<_js_jts_dScriptKind /*ScriptKind.TS*/, js_undefined> scriptKind = js_undefined()) noexcept;
		auto updateDocumentWithKey(js_string fileName, js_unknown /*flags=2097152: Path ()*/ path, _js_jts_dCompilerOptions compilationSettings, js_unknown /*flags=2097152: DocumentRegistryBucketKey ()*/ key, _js_jts_dIScriptSnapshot scriptSnapshot, js_string version, js_union<_js_jts_dScriptKind /*ScriptKind.TS*/, js_undefined> scriptKind = js_undefined()) noexcept;
	};
	struct _impl_js_jts_dTranspileOptions : virtual IObject {
		struct _tcjs_definitions {
		};
	};
	struct _impl_js_jts_dTranspileOutput : virtual IObject {
		struct _tcjs_definitions {
		};
		auto outputText() noexcept;
		void outputText(js_string v) noexcept;
	};
	inline auto _impl_js_j_qts_q::_tcjs_definitions::addEmitHelper(js_unknown /*flags=262144: T ()*/ node, _js_jts_dEmitHelper helper) noexcept {
		return emscripten::val::global("ts")["addEmitHelper"](node, helper).template as<js_unknown /*flags=262144: T ()*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::addEmitHelpers(js_unknown /*flags=262144: T ()*/ node, js_union<js::Array<_js_jts_dEmitHelper>, js_undefined> helpers) noexcept {
		return emscripten::val::global("ts")["addEmitHelpers"](node, helpers).template as<js_unknown /*flags=262144: T ()*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::addSyntheticLeadingComment(js_unknown /*flags=262144: T ()*/ node, _js_jts_dSyntaxKind /*SyntaxKind.SingleLineCommentTrivia*/ kind, js_string text, js_union<bool /*false*/, js_undefined> hasTrailingNewLine) noexcept {
		return emscripten::val::global("ts")["addSyntheticLeadingComment"](node, kind, text, hasTrailingNewLine).template as<js_unknown /*flags=262144: T ()*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::addSyntheticTrailingComment(js_unknown /*flags=262144: T ()*/ node, _js_jts_dSyntaxKind /*SyntaxKind.SingleLineCommentTrivia*/ kind, js_string text, js_union<bool /*false*/, js_undefined> hasTrailingNewLine) noexcept {
		return emscripten::val::global("ts")["addSyntheticTrailingComment"](node, kind, text, hasTrailingNewLine).template as<js_unknown /*flags=262144: T ()*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::classicNameResolver(js_string moduleName, js_string containingFile, _js_jts_dCompilerOptions compilerOptions, _js_jts_dModuleResolutionHost host, js_union<_js_jts_dNonRelativeModuleNameResolutionCache, js_undefined> cache, js_union<_js_jts_dResolvedProjectReference, js_undefined> redirectedReference) noexcept {
		return emscripten::val::global("ts")["classicNameResolver"](moduleName, containingFile, compilerOptions, host, cache, redirectedReference).template as<_js_jts_dResolvedModuleWithFailedLookupLocations>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::collapseTextChangeRangesAcrossMultipleVersions(js::ReadonlyArray<_js_jts_dTextChangeRange> changes) noexcept {
		return emscripten::val::global("ts")["collapseTextChangeRangesAcrossMultipleVersions"](changes).template as<_js_jts_dTextChangeRange>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::convertCompilerOptionsFromJson(js_unknown jsonOptions, js_string basePath, js_union<js_string, js_undefined> configFileName) noexcept {
		return emscripten::val::global("ts")["convertCompilerOptionsFromJson"](jsonOptions, basePath, configFileName).template as<js_unknown /*flags=524288: { options: CompilerOptions; errors: Diagnostic[]; } (AnonymousTypeWithTypeLiteral(members:[options, errors]))*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::convertToObject(_js_jts_dJsonSourceFile sourceFile, js_unknown /*flags=524288: Push<Diagnostic> (TypeReference=ts.Push)*/ errors) noexcept {
		return emscripten::val::global("ts")["convertToObject"](sourceFile, errors).template as<js_unknown>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::convertTypeAcquisitionFromJson(js_unknown jsonOptions, js_string basePath, js_union<js_string, js_undefined> configFileName) noexcept {
		return emscripten::val::global("ts")["convertTypeAcquisitionFromJson"](jsonOptions, basePath, configFileName).template as<js_unknown /*flags=524288: { options: TypeAcquisition; errors: Diagnostic[]; } (AnonymousTypeWithTypeLiteral(members:[options, errors]))*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::couldStartTrivia(js_string text, double pos) noexcept {
		return emscripten::val::global("ts")["couldStartTrivia"](text, pos).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createAbstractBuilder(_js_jts_dProgram newProgram, _js_jts_dBuilderProgramHost host, js_union<_js_jts_dBuilderProgram, js_undefined> oldProgram, js_union<js::ReadonlyArray<_js_jts_dDiagnostic>, js_undefined> configFileParsingDiagnostics) noexcept {
		return emscripten::val::global("ts")["createAbstractBuilder"](newProgram, host, oldProgram, configFileParsingDiagnostics).template as<_js_jts_dBuilderProgram>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createAbstractBuilder(js_union<js::ReadonlyArray<js_string>, js_undefined> rootNames, js_union<_js_jts_dCompilerOptions, js_undefined> options, js_union<_js_jts_dCompilerHost, js_undefined> host, js_union<_js_jts_dBuilderProgram, js_undefined> oldProgram, js_union<js::ReadonlyArray<_js_jts_dDiagnostic>, js_undefined> configFileParsingDiagnostics, js_union<js::ReadonlyArray<_js_jts_dProjectReference>, js_undefined> projectReferences) noexcept {
		return emscripten::val::global("ts")["createAbstractBuilder"](rootNames, options, host, oldProgram, configFileParsingDiagnostics, projectReferences).template as<_js_jts_dBuilderProgram>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createAdd(_js_jts_dExpression left, _js_jts_dExpression right) noexcept {
		return emscripten::val::global("ts")["createAdd"](left, right).template as<_js_jts_dBinaryExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createArrayBindingPattern(js::ReadonlyArray<js_union<_js_jts_dBindingElement, _js_jts_dOmittedExpression>> elements) noexcept {
		return emscripten::val::global("ts")["createArrayBindingPattern"](elements).template as<_js_jts_dArrayBindingPattern>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createArrayLiteral(js_union<js::ReadonlyArray<_js_jts_dExpression>, js_undefined> elements, js_union<bool /*false*/, js_undefined> multiLine) noexcept {
		return emscripten::val::global("ts")["createArrayLiteral"](elements, multiLine).template as<_js_jts_dArrayLiteralExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createArrayTypeNode(_js_jts_dTypeNode elementType) noexcept {
		return emscripten::val::global("ts")["createArrayTypeNode"](elementType).template as<_js_jts_dArrayTypeNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createArrowFunction(js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, js_union<_js_jts_dTypeNode, js_undefined> type, js_unknown /*flags=1048576: Token<SyntaxKind.EqualsGreaterThanToken> | undefined ()*/ equalsGreaterThanToken, js_union<_js_jts_dBlock, _js_jts_dExpression> body) noexcept {
		return emscripten::val::global("ts")["createArrowFunction"](modifiers, typeParameters, parameters, type, equalsGreaterThanToken, body).template as<_js_jts_dArrowFunction>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createAsExpression(_js_jts_dExpression expression, _js_jts_dTypeNode type) noexcept {
		return emscripten::val::global("ts")["createAsExpression"](expression, type).template as<_js_jts_dAsExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createAssignment(_js_jts_dExpression left, _js_jts_dExpression right) noexcept {
		return emscripten::val::global("ts")["createAssignment"](left, right).template as<_js_jts_dBinaryExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createAssignment(js_union<_js_jts_dArrayLiteralExpression, _js_jts_dObjectLiteralExpression> left, _js_jts_dExpression right) noexcept {
		return emscripten::val::global("ts")["createAssignment"](left, right).template as<js_union<_js_jts_dArrayDestructuringAssignment, _js_jts_dObjectDestructuringAssignment>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createAwait(_js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["createAwait"](expression).template as<_js_jts_dAwaitExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createBigIntLiteral(js_string value) noexcept {
		return emscripten::val::global("ts")["createBigIntLiteral"](value).template as<_js_jts_dBigIntLiteral>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createBinary(_js_jts_dExpression left, js_unknown /*flags=1048576: SyntaxKind.CommaToken | SyntaxKind.LessThanToken | SyntaxKind.GreaterThanToken | SyntaxKind.LessThanEqualsToken | SyntaxKind.GreaterThanEqualsToken | SyntaxKind.EqualsEqualsToken | SyntaxKind.ExclamationEqualsToken | SyntaxKind.EqualsEqualsEqualsToken | SyntaxKind.ExclamationEqualsEqualsToken | SyntaxKind.PlusToken ... ()*/ operator_, _js_jts_dExpression right) noexcept {
		return emscripten::val::global("ts")["createBinary"](left, operator_, right).template as<_js_jts_dBinaryExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createBindingElement(js_unknown /*flags=1048576: Token<SyntaxKind.DotDotDotToken> | undefined ()*/ dotDotDotToken, js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral, js_string, js_undefined> propertyName, js_union<_js_jts_dArrayBindingPattern, _js_jts_dIdentifier, _js_jts_dObjectBindingPattern, js_string> name, js_union<_js_jts_dExpression, js_undefined> initializer) noexcept {
		return emscripten::val::global("ts")["createBindingElement"](dotDotDotToken, propertyName, name, initializer).template as<_js_jts_dBindingElement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createBlock(js::ReadonlyArray<_js_jts_dStatement> statements, js_union<bool /*false*/, js_undefined> multiLine) noexcept {
		return emscripten::val::global("ts")["createBlock"](statements, multiLine).template as<_js_jts_dBlock>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createBreak(js_union<_js_jts_dIdentifier, js_string, js_undefined> label) noexcept {
		return emscripten::val::global("ts")["createBreak"](label).template as<_js_jts_dBreakStatement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createBundle(js::ReadonlyArray<_js_jts_dSourceFile> sourceFiles, js_union<js::ReadonlyArray<js_union<_js_jts_dInputFiles, _js_jts_dUnparsedSource>>, js_undefined> prepends) noexcept {
		return emscripten::val::global("ts")["createBundle"](sourceFiles, prepends).template as<_js_jts_dBundle>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createCall(_js_jts_dExpression expression, js_union<js::ReadonlyArray<_js_jts_dTypeNode>, js_undefined> typeArguments, js_union<js::ReadonlyArray<_js_jts_dExpression>, js_undefined> argumentsArray) noexcept {
		return emscripten::val::global("ts")["createCall"](expression, typeArguments, argumentsArray).template as<_js_jts_dCallExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createCallSignature(js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, js_union<_js_jts_dTypeNode, js_undefined> type) noexcept {
		return emscripten::val::global("ts")["createCallSignature"](typeParameters, parameters, type).template as<_js_jts_dCallSignatureDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createCaseBlock(js::ReadonlyArray<js_union<_js_jts_dCaseClause, _js_jts_dDefaultClause>> clauses) noexcept {
		return emscripten::val::global("ts")["createCaseBlock"](clauses).template as<_js_jts_dCaseBlock>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createCaseClause(_js_jts_dExpression expression, js::ReadonlyArray<_js_jts_dStatement> statements) noexcept {
		return emscripten::val::global("ts")["createCaseClause"](expression, statements).template as<_js_jts_dCaseClause>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createCatchClause(js_union<_js_jts_dVariableDeclaration, js_string, js_undefined> variableDeclaration, _js_jts_dBlock block) noexcept {
		return emscripten::val::global("ts")["createCatchClause"](variableDeclaration, block).template as<_js_jts_dCatchClause>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createClassDeclaration(js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dIdentifier, js_string, js_undefined> name, js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, js_union<js::ReadonlyArray<_js_jts_dHeritageClause>, js_undefined> heritageClauses, js::ReadonlyArray<_js_jts_dClassElement> members) noexcept {
		return emscripten::val::global("ts")["createClassDeclaration"](decorators, modifiers, name, typeParameters, heritageClauses, members).template as<_js_jts_dClassDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createClassExpression(js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dIdentifier, js_string, js_undefined> name, js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, js_union<js::ReadonlyArray<_js_jts_dHeritageClause>, js_undefined> heritageClauses, js::ReadonlyArray<_js_jts_dClassElement> members) noexcept {
		return emscripten::val::global("ts")["createClassExpression"](modifiers, name, typeParameters, heritageClauses, members).template as<_js_jts_dClassExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createClassifier() noexcept {
		return emscripten::val::global("ts")["createClassifier"]().template as<_js_jts_dClassifier>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createComma(_js_jts_dExpression left, _js_jts_dExpression right) noexcept {
		return emscripten::val::global("ts")["createComma"](left, right).template as<_js_jts_dExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createCommaList(js::ReadonlyArray<_js_jts_dExpression> elements) noexcept {
		return emscripten::val::global("ts")["createCommaList"](elements).template as<_js_jts_dCommaListExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createCompilerHost(_js_jts_dCompilerOptions options, js_union<bool /*false*/, js_undefined> setParentNodes) noexcept {
		return emscripten::val::global("ts")["createCompilerHost"](options, setParentNodes).template as<_js_jts_dCompilerHost>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createComputedPropertyName(_js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["createComputedPropertyName"](expression).template as<_js_jts_dComputedPropertyName>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createConditional(_js_jts_dExpression condition, _js_jts_dExpression whenTrue, _js_jts_dExpression whenFalse) noexcept {
		return emscripten::val::global("ts")["createConditional"](condition, whenTrue, whenFalse).template as<_js_jts_dConditionalExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createConditional(_js_jts_dExpression condition, js_unknown /*flags=524288: Token<SyntaxKind.QuestionToken> (TypeReference=ts.Token)*/ questionToken, _js_jts_dExpression whenTrue, js_unknown /*flags=524288: Token<SyntaxKind.ColonToken> (TypeReference=ts.Token)*/ colonToken, _js_jts_dExpression whenFalse) noexcept {
		return emscripten::val::global("ts")["createConditional"](condition, questionToken, whenTrue, colonToken, whenFalse).template as<_js_jts_dConditionalExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createConditionalTypeNode(_js_jts_dTypeNode checkType, _js_jts_dTypeNode extendsType, _js_jts_dTypeNode trueType, _js_jts_dTypeNode falseType) noexcept {
		return emscripten::val::global("ts")["createConditionalTypeNode"](checkType, extendsType, trueType, falseType).template as<_js_jts_dConditionalTypeNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createConstructSignature(js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, js_union<_js_jts_dTypeNode, js_undefined> type) noexcept {
		return emscripten::val::global("ts")["createConstructSignature"](typeParameters, parameters, type).template as<_js_jts_dConstructSignatureDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createConstructor(js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, js_union<_js_jts_dBlock, js_undefined> body) noexcept {
		return emscripten::val::global("ts")["createConstructor"](decorators, modifiers, parameters, body).template as<_js_jts_dConstructorDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createConstructorTypeNode(js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, js_union<_js_jts_dTypeNode, js_undefined> type) noexcept {
		return emscripten::val::global("ts")["createConstructorTypeNode"](typeParameters, parameters, type).template as<_js_jts_dConstructorTypeNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createContinue(js_union<_js_jts_dIdentifier, js_string, js_undefined> label) noexcept {
		return emscripten::val::global("ts")["createContinue"](label).template as<_js_jts_dContinueStatement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createDebuggerStatement() noexcept {
		return emscripten::val::global("ts")["createDebuggerStatement"]().template as<_js_jts_dDebuggerStatement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createDecorator(_js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["createDecorator"](expression).template as<_js_jts_dDecorator>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createDefaultClause(js::ReadonlyArray<_js_jts_dStatement> statements) noexcept {
		return emscripten::val::global("ts")["createDefaultClause"](statements).template as<_js_jts_dDefaultClause>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createDelete(_js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["createDelete"](expression).template as<_js_jts_dDeleteExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createDo(_js_jts_dStatement statement, _js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["createDo"](statement, expression).template as<_js_jts_dDoStatement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createDocumentRegistry(js_union<bool /*false*/, js_undefined> useCaseSensitiveFileNames, js_union<js_string, js_undefined> currentDirectory) noexcept {
		return emscripten::val::global("ts")["createDocumentRegistry"](useCaseSensitiveFileNames, currentDirectory).template as<_js_jts_dDocumentRegistry>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createElementAccess(_js_jts_dExpression expression, js_union<_js_jts_dExpression, double> index) noexcept {
		return emscripten::val::global("ts")["createElementAccess"](expression, index).template as<_js_jts_dElementAccessExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createEmitAndSemanticDiagnosticsBuilderProgram(_js_jts_dProgram newProgram, _js_jts_dBuilderProgramHost host, js_union<_js_jts_dEmitAndSemanticDiagnosticsBuilderProgram, js_undefined> oldProgram, js_union<js::ReadonlyArray<_js_jts_dDiagnostic>, js_undefined> configFileParsingDiagnostics) noexcept {
		return emscripten::val::global("ts")["createEmitAndSemanticDiagnosticsBuilderProgram"](newProgram, host, oldProgram, configFileParsingDiagnostics).template as<_js_jts_dEmitAndSemanticDiagnosticsBuilderProgram>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createEmitAndSemanticDiagnosticsBuilderProgram(js_union<js::ReadonlyArray<js_string>, js_undefined> rootNames, js_union<_js_jts_dCompilerOptions, js_undefined> options, js_union<_js_jts_dCompilerHost, js_undefined> host, js_union<_js_jts_dEmitAndSemanticDiagnosticsBuilderProgram, js_undefined> oldProgram, js_union<js::ReadonlyArray<_js_jts_dDiagnostic>, js_undefined> configFileParsingDiagnostics, js_union<js::ReadonlyArray<_js_jts_dProjectReference>, js_undefined> projectReferences) noexcept {
		return emscripten::val::global("ts")["createEmitAndSemanticDiagnosticsBuilderProgram"](rootNames, options, host, oldProgram, configFileParsingDiagnostics, projectReferences).template as<_js_jts_dEmitAndSemanticDiagnosticsBuilderProgram>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createEmptyStatement() noexcept {
		return emscripten::val::global("ts")["createEmptyStatement"]().template as<_js_jts_dEmptyStatement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createEnumDeclaration(js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dIdentifier, js_string> name, js::ReadonlyArray<_js_jts_dEnumMember> members) noexcept {
		return emscripten::val::global("ts")["createEnumDeclaration"](decorators, modifiers, name, members).template as<_js_jts_dEnumDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createEnumMember(js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral, js_string> name, js_union<_js_jts_dExpression, js_undefined> initializer) noexcept {
		return emscripten::val::global("ts")["createEnumMember"](name, initializer).template as<_js_jts_dEnumMember>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createExportAssignment(js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<bool /*false*/, js_undefined> isExportEquals, _js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["createExportAssignment"](decorators, modifiers, isExportEquals, expression).template as<_js_jts_dExportAssignment>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createExportDeclaration(js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dNamedExports, js_undefined> exportClause, js_union<_js_jts_dExpression, js_undefined> moduleSpecifier) noexcept {
		return emscripten::val::global("ts")["createExportDeclaration"](decorators, modifiers, exportClause, moduleSpecifier).template as<_js_jts_dExportDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createExportDefault(_js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["createExportDefault"](expression).template as<_js_jts_dExportAssignment>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createExportSpecifier(js_union<_js_jts_dIdentifier, js_string, js_undefined> propertyName, js_union<_js_jts_dIdentifier, js_string> name) noexcept {
		return emscripten::val::global("ts")["createExportSpecifier"](propertyName, name).template as<_js_jts_dExportSpecifier>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createExpressionStatement(_js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["createExpressionStatement"](expression).template as<_js_jts_dExpressionStatement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createExpressionWithTypeArguments(js_union<js::ReadonlyArray<_js_jts_dTypeNode>, js_undefined> typeArguments, _js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["createExpressionWithTypeArguments"](typeArguments, expression).template as<_js_jts_dExpressionWithTypeArguments>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createExternalModuleExport(_js_jts_dIdentifier exportName) noexcept {
		return emscripten::val::global("ts")["createExternalModuleExport"](exportName).template as<_js_jts_dExportDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createExternalModuleReference(_js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["createExternalModuleReference"](expression).template as<_js_jts_dExternalModuleReference>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createFalse() noexcept {
		return emscripten::val::global("ts")["createFalse"]().template as<js_unknown /*flags=2097152: BooleanLiteral & Token<SyntaxKind.FalseKeyword> ()*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createFileLevelUniqueName(js_string text) noexcept {
		return emscripten::val::global("ts")["createFileLevelUniqueName"](text).template as<_js_jts_dIdentifier>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createFor(js_union<_js_jts_dExpression, _js_jts_dVariableDeclarationList, js_undefined> initializer, js_union<_js_jts_dExpression, js_undefined> condition, js_union<_js_jts_dExpression, js_undefined> incrementor, _js_jts_dStatement statement) noexcept {
		return emscripten::val::global("ts")["createFor"](initializer, condition, incrementor, statement).template as<_js_jts_dForStatement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createForIn(js_union<_js_jts_dExpression, _js_jts_dVariableDeclarationList> initializer, _js_jts_dExpression expression, _js_jts_dStatement statement) noexcept {
		return emscripten::val::global("ts")["createForIn"](initializer, expression, statement).template as<_js_jts_dForInStatement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createForOf(js_unknown /*flags=1048576: Token<SyntaxKind.AwaitKeyword> | undefined ()*/ awaitModifier, js_union<_js_jts_dExpression, _js_jts_dVariableDeclarationList> initializer, _js_jts_dExpression expression, _js_jts_dStatement statement) noexcept {
		return emscripten::val::global("ts")["createForOf"](awaitModifier, initializer, expression, statement).template as<_js_jts_dForOfStatement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createFunctionDeclaration(js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_unknown /*flags=1048576: Token<SyntaxKind.AsteriskToken> | undefined ()*/ asteriskToken, js_union<_js_jts_dIdentifier, js_string, js_undefined> name, js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, js_union<_js_jts_dTypeNode, js_undefined> type, js_union<_js_jts_dBlock, js_undefined> body) noexcept {
		return emscripten::val::global("ts")["createFunctionDeclaration"](decorators, modifiers, asteriskToken, name, typeParameters, parameters, type, body).template as<_js_jts_dFunctionDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createFunctionExpression(js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_unknown /*flags=1048576: Token<SyntaxKind.AsteriskToken> | undefined ()*/ asteriskToken, js_union<_js_jts_dIdentifier, js_string, js_undefined> name, js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, js_union<js::ReadonlyArray<_js_jts_dParameterDeclaration>, js_undefined> parameters, js_union<_js_jts_dTypeNode, js_undefined> type, _js_jts_dBlock body) noexcept {
		return emscripten::val::global("ts")["createFunctionExpression"](modifiers, asteriskToken, name, typeParameters, parameters, type, body).template as<_js_jts_dFunctionExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createFunctionTypeNode(js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, js_union<_js_jts_dTypeNode, js_undefined> type) noexcept {
		return emscripten::val::global("ts")["createFunctionTypeNode"](typeParameters, parameters, type).template as<_js_jts_dFunctionTypeNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createGetAccessor(js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral, js_string> name, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, js_union<_js_jts_dTypeNode, js_undefined> type, js_union<_js_jts_dBlock, js_undefined> body) noexcept {
		return emscripten::val::global("ts")["createGetAccessor"](decorators, modifiers, name, parameters, type, body).template as<_js_jts_dGetAccessorDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createHeritageClause(_js_jts_dSyntaxKind /*SyntaxKind.ExtendsKeyword*/ token, js::ReadonlyArray<_js_jts_dExpressionWithTypeArguments> types) noexcept {
		return emscripten::val::global("ts")["createHeritageClause"](token, types).template as<_js_jts_dHeritageClause>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createIdentifier(js_string text) noexcept {
		return emscripten::val::global("ts")["createIdentifier"](text).template as<_js_jts_dIdentifier>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createIf(_js_jts_dExpression expression, _js_jts_dStatement thenStatement, js_union<_js_jts_dStatement, js_undefined> elseStatement) noexcept {
		return emscripten::val::global("ts")["createIf"](expression, thenStatement, elseStatement).template as<_js_jts_dIfStatement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createImmediatelyInvokedArrowFunction(js::ReadonlyArray<_js_jts_dStatement> statements) noexcept {
		return emscripten::val::global("ts")["createImmediatelyInvokedArrowFunction"](statements).template as<_js_jts_dCallExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createImmediatelyInvokedArrowFunction(js::ReadonlyArray<_js_jts_dStatement> statements, _js_jts_dParameterDeclaration param, _js_jts_dExpression paramValue) noexcept {
		return emscripten::val::global("ts")["createImmediatelyInvokedArrowFunction"](statements, param, paramValue).template as<_js_jts_dCallExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createImmediatelyInvokedFunctionExpression(js::ReadonlyArray<_js_jts_dStatement> statements) noexcept {
		return emscripten::val::global("ts")["createImmediatelyInvokedFunctionExpression"](statements).template as<_js_jts_dCallExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createImmediatelyInvokedFunctionExpression(js::ReadonlyArray<_js_jts_dStatement> statements, _js_jts_dParameterDeclaration param, _js_jts_dExpression paramValue) noexcept {
		return emscripten::val::global("ts")["createImmediatelyInvokedFunctionExpression"](statements, param, paramValue).template as<_js_jts_dCallExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createImportClause(js_union<_js_jts_dIdentifier, js_undefined> name, js_union<_js_jts_dNamedImports, _js_jts_dNamespaceImport, js_undefined> namedBindings) noexcept {
		return emscripten::val::global("ts")["createImportClause"](name, namedBindings).template as<_js_jts_dImportClause>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createImportDeclaration(js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dImportClause, js_undefined> importClause, _js_jts_dExpression moduleSpecifier) noexcept {
		return emscripten::val::global("ts")["createImportDeclaration"](decorators, modifiers, importClause, moduleSpecifier).template as<_js_jts_dImportDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createImportEqualsDeclaration(js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dIdentifier, js_string> name, js_union<_js_jts_dExternalModuleReference, _js_jts_dIdentifier, _js_jts_dQualifiedName> moduleReference) noexcept {
		return emscripten::val::global("ts")["createImportEqualsDeclaration"](decorators, modifiers, name, moduleReference).template as<_js_jts_dImportEqualsDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createImportSpecifier(js_union<_js_jts_dIdentifier, js_undefined> propertyName, _js_jts_dIdentifier name) noexcept {
		return emscripten::val::global("ts")["createImportSpecifier"](propertyName, name).template as<_js_jts_dImportSpecifier>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createImportTypeNode(_js_jts_dTypeNode argument, js_union<_js_jts_dIdentifier, _js_jts_dQualifiedName, js_undefined> qualifier, js_union<js::ReadonlyArray<_js_jts_dTypeNode>, js_undefined> typeArguments, js_union<bool /*false*/, js_undefined> isTypeOf) noexcept {
		return emscripten::val::global("ts")["createImportTypeNode"](argument, qualifier, typeArguments, isTypeOf).template as<_js_jts_dImportTypeNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createIndexSignature(js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, _js_jts_dTypeNode type) noexcept {
		return emscripten::val::global("ts")["createIndexSignature"](decorators, modifiers, parameters, type).template as<_js_jts_dIndexSignatureDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createIndexedAccessTypeNode(_js_jts_dTypeNode objectType, _js_jts_dTypeNode indexType) noexcept {
		return emscripten::val::global("ts")["createIndexedAccessTypeNode"](objectType, indexType).template as<_js_jts_dIndexedAccessTypeNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createInferTypeNode(_js_jts_dTypeParameterDeclaration typeParameter) noexcept {
		return emscripten::val::global("ts")["createInferTypeNode"](typeParameter).template as<_js_jts_dInferTypeNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createInputFiles(js_function<js_union<js_string, js_undefined>(js_string)> readFileText, js_string javascriptPath, js_union<js_string, js_undefined> javascriptMapPath, js_string declarationPath, js_union<js_string, js_undefined> declarationMapPath, js_union<js_string, js_undefined> buildInfoPath) noexcept {
		return emscripten::val::global("ts")["createInputFiles"](readFileText, javascriptPath, javascriptMapPath, declarationPath, declarationMapPath, buildInfoPath).template as<_js_jts_dInputFiles>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createInputFiles(js_string javascriptText, js_string declarationText) noexcept {
		return emscripten::val::global("ts")["createInputFiles"](javascriptText, declarationText).template as<_js_jts_dInputFiles>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createInputFiles(js_string javascriptText, js_string declarationText, js_union<js_string, js_undefined> javascriptMapPath, js_union<js_string, js_undefined> javascriptMapText, js_union<js_string, js_undefined> declarationMapPath, js_union<js_string, js_undefined> declarationMapText) noexcept {
		return emscripten::val::global("ts")["createInputFiles"](javascriptText, declarationText, javascriptMapPath, javascriptMapText, declarationMapPath, declarationMapText).template as<_js_jts_dInputFiles>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createInterfaceDeclaration(js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dIdentifier, js_string> name, js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, js_union<js::ReadonlyArray<_js_jts_dHeritageClause>, js_undefined> heritageClauses, js::ReadonlyArray<_js_jts_dTypeElement> members) noexcept {
		return emscripten::val::global("ts")["createInterfaceDeclaration"](decorators, modifiers, name, typeParameters, heritageClauses, members).template as<_js_jts_dInterfaceDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createIntersectionTypeNode(js::ReadonlyArray<_js_jts_dTypeNode> types) noexcept {
		return emscripten::val::global("ts")["createIntersectionTypeNode"](types).template as<_js_jts_dIntersectionTypeNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createJsxAttribute(_js_jts_dIdentifier name, js_union<_js_jts_dJsxExpression, _js_jts_dStringLiteral> initializer) noexcept {
		return emscripten::val::global("ts")["createJsxAttribute"](name, initializer).template as<_js_jts_dJsxAttribute>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createJsxAttributes(js::ReadonlyArray<js_union<_js_jts_dJsxAttribute, _js_jts_dJsxSpreadAttribute>> properties) noexcept {
		return emscripten::val::global("ts")["createJsxAttributes"](properties).template as<_js_jts_dJsxAttributes>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createJsxClosingElement(js_union<_js_jts_dIdentifier, _js_jts_dJsxTagNamePropertyAccess, _js_jts_dThisExpression> tagName) noexcept {
		return emscripten::val::global("ts")["createJsxClosingElement"](tagName).template as<_js_jts_dJsxClosingElement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createJsxElement(_js_jts_dJsxOpeningElement openingElement, js::ReadonlyArray<js_union<_js_jts_dJsxElement, _js_jts_dJsxExpression, _js_jts_dJsxFragment, _js_jts_dJsxSelfClosingElement, _js_jts_dJsxText>> children, _js_jts_dJsxClosingElement closingElement) noexcept {
		return emscripten::val::global("ts")["createJsxElement"](openingElement, children, closingElement).template as<_js_jts_dJsxElement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createJsxExpression(js_unknown /*flags=1048576: Token<SyntaxKind.DotDotDotToken> | undefined ()*/ dotDotDotToken, js_union<_js_jts_dExpression, js_undefined> expression) noexcept {
		return emscripten::val::global("ts")["createJsxExpression"](dotDotDotToken, expression).template as<_js_jts_dJsxExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createJsxFragment(_js_jts_dJsxOpeningFragment openingFragment, js::ReadonlyArray<js_union<_js_jts_dJsxElement, _js_jts_dJsxExpression, _js_jts_dJsxFragment, _js_jts_dJsxSelfClosingElement, _js_jts_dJsxText>> children, _js_jts_dJsxClosingFragment closingFragment) noexcept {
		return emscripten::val::global("ts")["createJsxFragment"](openingFragment, children, closingFragment).template as<_js_jts_dJsxFragment>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createJsxJsxClosingFragment() noexcept {
		return emscripten::val::global("ts")["createJsxJsxClosingFragment"]().template as<_js_jts_dJsxClosingFragment>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createJsxOpeningElement(js_union<_js_jts_dIdentifier, _js_jts_dJsxTagNamePropertyAccess, _js_jts_dThisExpression> tagName, js_union<js::ReadonlyArray<_js_jts_dTypeNode>, js_undefined> typeArguments, _js_jts_dJsxAttributes attributes) noexcept {
		return emscripten::val::global("ts")["createJsxOpeningElement"](tagName, typeArguments, attributes).template as<_js_jts_dJsxOpeningElement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createJsxOpeningFragment() noexcept {
		return emscripten::val::global("ts")["createJsxOpeningFragment"]().template as<_js_jts_dJsxOpeningFragment>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createJsxSelfClosingElement(js_union<_js_jts_dIdentifier, _js_jts_dJsxTagNamePropertyAccess, _js_jts_dThisExpression> tagName, js_union<js::ReadonlyArray<_js_jts_dTypeNode>, js_undefined> typeArguments, _js_jts_dJsxAttributes attributes) noexcept {
		return emscripten::val::global("ts")["createJsxSelfClosingElement"](tagName, typeArguments, attributes).template as<_js_jts_dJsxSelfClosingElement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createJsxSpreadAttribute(_js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["createJsxSpreadAttribute"](expression).template as<_js_jts_dJsxSpreadAttribute>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createJsxText(js_string text, js_union<bool /*false*/, js_undefined> containsOnlyTriviaWhiteSpaces) noexcept {
		return emscripten::val::global("ts")["createJsxText"](text, containsOnlyTriviaWhiteSpaces).template as<_js_jts_dJsxText>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createKeywordTypeNode(_js_jts_dSyntaxKind /*SyntaxKind.NullKeyword*/ kind) noexcept {
		return emscripten::val::global("ts")["createKeywordTypeNode"](kind).template as<_js_jts_dKeywordTypeNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createLabel(js_union<_js_jts_dIdentifier, js_string> label, _js_jts_dStatement statement) noexcept {
		return emscripten::val::global("ts")["createLabel"](label, statement).template as<_js_jts_dLabeledStatement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createLanguageService(_js_jts_dLanguageServiceHost host, js_union<_js_jts_dDocumentRegistry, js_undefined> documentRegistry, js_union<bool /*false*/, js_undefined> syntaxOnly) noexcept {
		return emscripten::val::global("ts")["createLanguageService"](host, documentRegistry, syntaxOnly).template as<_js_jts_dLanguageService>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createLanguageServiceSourceFile(js_string fileName, _js_jts_dIScriptSnapshot scriptSnapshot, _js_jts_dScriptTarget /*ScriptTarget.ES3*/ scriptTarget, js_string version, bool /*false*/ setNodeParents, js_union<_js_jts_dScriptKind /*ScriptKind.TS*/, js_undefined> scriptKind) noexcept {
		return emscripten::val::global("ts")["createLanguageServiceSourceFile"](fileName, scriptSnapshot, scriptTarget, version, setNodeParents, scriptKind).template as<_js_jts_dSourceFile>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createLessThan(_js_jts_dExpression left, _js_jts_dExpression right) noexcept {
		return emscripten::val::global("ts")["createLessThan"](left, right).template as<_js_jts_dExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createLiteral(bool /*false*/ value) noexcept {
		return emscripten::val::global("ts")["createLiteral"](value).template as<_js_jts_dBooleanLiteral>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createLiteral(js_union<_js_jts_dIdentifier, _js_jts_dNoSubstitutionTemplateLiteral, _js_jts_dNumericLiteral, _js_jts_dStringLiteral, js_string> value) noexcept {
		return emscripten::val::global("ts")["createLiteral"](value).template as<_js_jts_dStringLiteral>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createLiteral(js_union<_js_jts_dPseudoBigInt, bool /*false*/, double, js_string> value) noexcept {
		return emscripten::val::global("ts")["createLiteral"](value).template as<_js_jts_dPrimaryExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createLiteral(js_union<_js_jts_dPseudoBigInt, double> value) noexcept {
		return emscripten::val::global("ts")["createLiteral"](value).template as<_js_jts_dNumericLiteral>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createLiteralTypeNode(js_union<_js_jts_dBooleanLiteral, _js_jts_dLiteralExpression, _js_jts_dPrefixUnaryExpression> literal) noexcept {
		return emscripten::val::global("ts")["createLiteralTypeNode"](literal).template as<_js_jts_dLiteralTypeNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createLogicalAnd(_js_jts_dExpression left, _js_jts_dExpression right) noexcept {
		return emscripten::val::global("ts")["createLogicalAnd"](left, right).template as<_js_jts_dBinaryExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createLogicalNot(_js_jts_dExpression operand) noexcept {
		return emscripten::val::global("ts")["createLogicalNot"](operand).template as<_js_jts_dPrefixUnaryExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createLogicalOr(_js_jts_dExpression left, _js_jts_dExpression right) noexcept {
		return emscripten::val::global("ts")["createLogicalOr"](left, right).template as<_js_jts_dBinaryExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createLoopVariable() noexcept {
		return emscripten::val::global("ts")["createLoopVariable"]().template as<_js_jts_dIdentifier>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createMappedTypeNode(js_unknown /*flags=1048576: Token<SyntaxKind.ReadonlyKeyword> | Token<SyntaxKind.PlusToken> | Token<SyntaxKind.MinusToken> | undefined ()*/ readonlyToken, _js_jts_dTypeParameterDeclaration typeParameter, js_unknown /*flags=1048576: Token<SyntaxKind.QuestionToken> | Token<SyntaxKind.PlusToken> | Token<SyntaxKind.MinusToken> | undefined ()*/ questionToken, js_union<_js_jts_dTypeNode, js_undefined> type) noexcept {
		return emscripten::val::global("ts")["createMappedTypeNode"](readonlyToken, typeParameter, questionToken, type).template as<_js_jts_dMappedTypeNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createMetaProperty(_js_jts_dSyntaxKind /*SyntaxKind.ImportKeyword*/ keywordToken, _js_jts_dIdentifier name) noexcept {
		return emscripten::val::global("ts")["createMetaProperty"](keywordToken, name).template as<_js_jts_dMetaProperty>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createMethod(js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_unknown /*flags=1048576: Token<SyntaxKind.AsteriskToken> | undefined ()*/ asteriskToken, js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral, js_string> name, js_unknown /*flags=1048576: Token<SyntaxKind.QuestionToken> | undefined ()*/ questionToken, js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, js_union<_js_jts_dTypeNode, js_undefined> type, js_union<_js_jts_dBlock, js_undefined> body) noexcept {
		return emscripten::val::global("ts")["createMethod"](decorators, modifiers, asteriskToken, name, questionToken, typeParameters, parameters, type, body).template as<_js_jts_dMethodDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createMethodSignature(js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, js_union<_js_jts_dTypeNode, js_undefined> type, js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral, js_string> name, js_unknown /*flags=1048576: Token<SyntaxKind.QuestionToken> | undefined ()*/ questionToken) noexcept {
		return emscripten::val::global("ts")["createMethodSignature"](typeParameters, parameters, type, name, questionToken).template as<_js_jts_dMethodSignature>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createModifier(js_unknown /*flags=262144: T ()*/ kind) noexcept {
		return emscripten::val::global("ts")["createModifier"](kind).template as<js_unknown /*flags=524288: Token<T> (TypeReference=ts.Token)*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createModifiersFromModifierFlags(_js_jts_dModifierFlags /*ModifierFlags.None*/ flags) noexcept {
		return emscripten::val::global("ts")["createModifiersFromModifierFlags"](flags).template as<js::Array<js_unknown /*flags=1048576: Modifier ()*/>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createModuleBlock(js::ReadonlyArray<_js_jts_dStatement> statements) noexcept {
		return emscripten::val::global("ts")["createModuleBlock"](statements).template as<_js_jts_dModuleBlock>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createModuleDeclaration(js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dIdentifier, _js_jts_dStringLiteral> name, js_union<_js_jts_dIdentifier, _js_jts_dJSDocNamespaceDeclaration, _js_jts_dModuleBlock, _js_jts_dNamespaceDeclaration, js_undefined> body, js_union<_js_jts_dNodeFlags /*NodeFlags.YieldContext*/, js_undefined> flags) noexcept {
		return emscripten::val::global("ts")["createModuleDeclaration"](decorators, modifiers, name, body, flags).template as<_js_jts_dModuleDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createModuleResolutionCache(js_string currentDirectory, js_function<js_string(js_string)> getCanonicalFileName, js_union<_js_jts_dCompilerOptions, js_undefined> options) noexcept {
		return emscripten::val::global("ts")["createModuleResolutionCache"](currentDirectory, getCanonicalFileName, options).template as<_js_jts_dModuleResolutionCache>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createNamedExports(js::ReadonlyArray<_js_jts_dExportSpecifier> elements) noexcept {
		return emscripten::val::global("ts")["createNamedExports"](elements).template as<_js_jts_dNamedExports>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createNamedImports(js::ReadonlyArray<_js_jts_dImportSpecifier> elements) noexcept {
		return emscripten::val::global("ts")["createNamedImports"](elements).template as<_js_jts_dNamedImports>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createNamespaceExportDeclaration(js_union<_js_jts_dIdentifier, js_string> name) noexcept {
		return emscripten::val::global("ts")["createNamespaceExportDeclaration"](name).template as<_js_jts_dNamespaceExportDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createNamespaceImport(_js_jts_dIdentifier name) noexcept {
		return emscripten::val::global("ts")["createNamespaceImport"](name).template as<_js_jts_dNamespaceImport>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createNew(_js_jts_dExpression expression, js_union<js::ReadonlyArray<_js_jts_dTypeNode>, js_undefined> typeArguments, js_union<js::ReadonlyArray<_js_jts_dExpression>, js_undefined> argumentsArray) noexcept {
		return emscripten::val::global("ts")["createNew"](expression, typeArguments, argumentsArray).template as<_js_jts_dNewExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createNoSubstitutionTemplateLiteral(js_string text) noexcept {
		return emscripten::val::global("ts")["createNoSubstitutionTemplateLiteral"](text).template as<_js_jts_dNoSubstitutionTemplateLiteral>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createNode(_js_jts_dSyntaxKind /*SyntaxKind.Unknown*/ kind, js_union<double, js_undefined> pos, js_union<double, js_undefined> end) noexcept {
		return emscripten::val::global("ts")["createNode"](kind, pos, end).template as<_js_jts_dNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createNodeArray(js_union<js::ReadonlyArray<js_unknown /*flags=262144: T ()*/>, js_undefined> elements, js_union<bool /*false*/, js_undefined> hasTrailingComma) noexcept {
		return emscripten::val::global("ts")["createNodeArray"](elements, hasTrailingComma).template as<js_unknown /*flags=524288: NodeArray<T> (TypeReference=ts.NodeArray)*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createNonNullExpression(_js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["createNonNullExpression"](expression).template as<_js_jts_dNonNullExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createNotEmittedStatement(_js_jts_dNode original) noexcept {
		return emscripten::val::global("ts")["createNotEmittedStatement"](original).template as<_js_jts_dNotEmittedStatement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createNull() noexcept {
		return emscripten::val::global("ts")["createNull"]().template as<js_unknown /*flags=2097152: NullLiteral & Token<SyntaxKind.NullKeyword> ()*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createNumericLiteral(js_string value, js_union<_js_jts_dTokenFlags /*TokenFlags.Octal*/, js_undefined> numericLiteralFlags) noexcept {
		return emscripten::val::global("ts")["createNumericLiteral"](value, numericLiteralFlags).template as<_js_jts_dNumericLiteral>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createObjectBindingPattern(js::ReadonlyArray<_js_jts_dBindingElement> elements) noexcept {
		return emscripten::val::global("ts")["createObjectBindingPattern"](elements).template as<_js_jts_dObjectBindingPattern>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createObjectLiteral(js_union<js::ReadonlyArray<js_union<_js_jts_dGetAccessorDeclaration, _js_jts_dMethodDeclaration, _js_jts_dPropertyAssignment, _js_jts_dSetAccessorDeclaration, _js_jts_dShorthandPropertyAssignment, _js_jts_dSpreadAssignment>>, js_undefined> properties, js_union<bool /*false*/, js_undefined> multiLine) noexcept {
		return emscripten::val::global("ts")["createObjectLiteral"](properties, multiLine).template as<_js_jts_dObjectLiteralExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createOmittedExpression() noexcept {
		return emscripten::val::global("ts")["createOmittedExpression"]().template as<_js_jts_dOmittedExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createOptimisticUniqueName(js_string text) noexcept {
		return emscripten::val::global("ts")["createOptimisticUniqueName"](text).template as<_js_jts_dIdentifier>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createOptionalTypeNode(_js_jts_dTypeNode type) noexcept {
		return emscripten::val::global("ts")["createOptionalTypeNode"](type).template as<_js_jts_dOptionalTypeNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createParameter(js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_unknown /*flags=1048576: Token<SyntaxKind.DotDotDotToken> | undefined ()*/ dotDotDotToken, js_union<_js_jts_dArrayBindingPattern, _js_jts_dIdentifier, _js_jts_dObjectBindingPattern, js_string> name, js_unknown /*flags=1048576: Token<SyntaxKind.QuestionToken> | undefined ()*/ questionToken, js_union<_js_jts_dTypeNode, js_undefined> type, js_union<_js_jts_dExpression, js_undefined> initializer) noexcept {
		return emscripten::val::global("ts")["createParameter"](decorators, modifiers, dotDotDotToken, name, questionToken, type, initializer).template as<_js_jts_dParameterDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createParen(_js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["createParen"](expression).template as<_js_jts_dParenthesizedExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createParenthesizedType(_js_jts_dTypeNode type) noexcept {
		return emscripten::val::global("ts")["createParenthesizedType"](type).template as<_js_jts_dParenthesizedTypeNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createPartiallyEmittedExpression(_js_jts_dExpression expression, js_union<_js_jts_dNode, js_undefined> original) noexcept {
		return emscripten::val::global("ts")["createPartiallyEmittedExpression"](expression, original).template as<_js_jts_dPartiallyEmittedExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createPostfix(_js_jts_dExpression operand, _js_jts_dSyntaxKind /*SyntaxKind.PlusPlusToken*/ operator_) noexcept {
		return emscripten::val::global("ts")["createPostfix"](operand, operator_).template as<_js_jts_dPostfixUnaryExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createPostfixIncrement(_js_jts_dExpression operand) noexcept {
		return emscripten::val::global("ts")["createPostfixIncrement"](operand).template as<_js_jts_dPostfixUnaryExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createPrefix(_js_jts_dSyntaxKind /*SyntaxKind.PlusToken*/ operator_, _js_jts_dExpression operand) noexcept {
		return emscripten::val::global("ts")["createPrefix"](operator_, operand).template as<_js_jts_dPrefixUnaryExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createPrinter(js_union<_js_jts_dPrinterOptions, js_undefined> printerOptions, js_union<_js_jts_dPrintHandlers, js_undefined> handlers) noexcept {
		return emscripten::val::global("ts")["createPrinter"](printerOptions, handlers).template as<_js_jts_dPrinter>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createProgram(_js_jts_dCreateProgramOptions createProgramOptions) noexcept {
		return emscripten::val::global("ts")["createProgram"](createProgramOptions).template as<_js_jts_dProgram>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createProgram(js::ReadonlyArray<js_string> rootNames, _js_jts_dCompilerOptions options, js_union<_js_jts_dCompilerHost, js_undefined> host, js_union<_js_jts_dProgram, js_undefined> oldProgram, js_union<js::ReadonlyArray<_js_jts_dDiagnostic>, js_undefined> configFileParsingDiagnostics) noexcept {
		return emscripten::val::global("ts")["createProgram"](rootNames, options, host, oldProgram, configFileParsingDiagnostics).template as<_js_jts_dProgram>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createProperty(js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral, js_string> name, js_unknown /*flags=1048576: Token<SyntaxKind.QuestionToken> | Token<SyntaxKind.ExclamationToken> | undefined ()*/ questionOrExclamationToken, js_union<_js_jts_dTypeNode, js_undefined> type, js_union<_js_jts_dExpression, js_undefined> initializer) noexcept {
		return emscripten::val::global("ts")["createProperty"](decorators, modifiers, name, questionOrExclamationToken, type, initializer).template as<_js_jts_dPropertyDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createPropertyAccess(_js_jts_dExpression expression, js_union<_js_jts_dIdentifier, js_string> name) noexcept {
		return emscripten::val::global("ts")["createPropertyAccess"](expression, name).template as<_js_jts_dPropertyAccessExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createPropertyAssignment(js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral, js_string> name, _js_jts_dExpression initializer) noexcept {
		return emscripten::val::global("ts")["createPropertyAssignment"](name, initializer).template as<_js_jts_dPropertyAssignment>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createPropertySignature(js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral, js_string> name, js_unknown /*flags=1048576: Token<SyntaxKind.QuestionToken> | undefined ()*/ questionToken, js_union<_js_jts_dTypeNode, js_undefined> type, js_union<_js_jts_dExpression, js_undefined> initializer) noexcept {
		return emscripten::val::global("ts")["createPropertySignature"](modifiers, name, questionToken, type, initializer).template as<_js_jts_dPropertySignature>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createQualifiedName(js_union<_js_jts_dIdentifier, _js_jts_dQualifiedName> left, js_union<_js_jts_dIdentifier, js_string> right) noexcept {
		return emscripten::val::global("ts")["createQualifiedName"](left, right).template as<_js_jts_dQualifiedName>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createRegularExpressionLiteral(js_string text) noexcept {
		return emscripten::val::global("ts")["createRegularExpressionLiteral"](text).template as<_js_jts_dRegularExpressionLiteral>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createRestTypeNode(_js_jts_dTypeNode type) noexcept {
		return emscripten::val::global("ts")["createRestTypeNode"](type).template as<_js_jts_dRestTypeNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createReturn(js_union<_js_jts_dExpression, js_undefined> expression) noexcept {
		return emscripten::val::global("ts")["createReturn"](expression).template as<_js_jts_dReturnStatement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createScanner(_js_jts_dScriptTarget /*ScriptTarget.ES3*/ languageVersion, bool /*false*/ skipTrivia, js_union<_js_jts_dLanguageVariant /*LanguageVariant.Standard*/, js_undefined> languageVariant, js_union<js_string, js_undefined> textInitial, js_union<js_function<void(_js_jts_dDiagnosticMessage, double)>, js_undefined> onError, js_union<double, js_undefined> start, js_union<double, js_undefined> length) noexcept {
		return emscripten::val::global("ts")["createScanner"](languageVersion, skipTrivia, languageVariant, textInitial, onError, start, length).template as<_js_jts_dScanner>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createSemanticDiagnosticsBuilderProgram(_js_jts_dProgram newProgram, _js_jts_dBuilderProgramHost host, js_union<_js_jts_dSemanticDiagnosticsBuilderProgram, js_undefined> oldProgram, js_union<js::ReadonlyArray<_js_jts_dDiagnostic>, js_undefined> configFileParsingDiagnostics) noexcept {
		return emscripten::val::global("ts")["createSemanticDiagnosticsBuilderProgram"](newProgram, host, oldProgram, configFileParsingDiagnostics).template as<_js_jts_dSemanticDiagnosticsBuilderProgram>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createSemanticDiagnosticsBuilderProgram(js_union<js::ReadonlyArray<js_string>, js_undefined> rootNames, js_union<_js_jts_dCompilerOptions, js_undefined> options, js_union<_js_jts_dCompilerHost, js_undefined> host, js_union<_js_jts_dSemanticDiagnosticsBuilderProgram, js_undefined> oldProgram, js_union<js::ReadonlyArray<_js_jts_dDiagnostic>, js_undefined> configFileParsingDiagnostics, js_union<js::ReadonlyArray<_js_jts_dProjectReference>, js_undefined> projectReferences) noexcept {
		return emscripten::val::global("ts")["createSemanticDiagnosticsBuilderProgram"](rootNames, options, host, oldProgram, configFileParsingDiagnostics, projectReferences).template as<_js_jts_dSemanticDiagnosticsBuilderProgram>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createSemicolonClassElement() noexcept {
		return emscripten::val::global("ts")["createSemicolonClassElement"]().template as<_js_jts_dSemicolonClassElement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createSetAccessor(js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral, js_string> name, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, js_union<_js_jts_dBlock, js_undefined> body) noexcept {
		return emscripten::val::global("ts")["createSetAccessor"](decorators, modifiers, name, parameters, body).template as<_js_jts_dSetAccessorDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createShorthandPropertyAssignment(js_union<_js_jts_dIdentifier, js_string> name, js_union<_js_jts_dExpression, js_undefined> objectAssignmentInitializer) noexcept {
		return emscripten::val::global("ts")["createShorthandPropertyAssignment"](name, objectAssignmentInitializer).template as<_js_jts_dShorthandPropertyAssignment>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createSourceFile(js_string fileName, js_string sourceText, _js_jts_dScriptTarget /*ScriptTarget.ES3*/ languageVersion, js_union<bool /*false*/, js_undefined> setParentNodes, js_union<_js_jts_dScriptKind /*ScriptKind.TS*/, js_undefined> scriptKind) noexcept {
		return emscripten::val::global("ts")["createSourceFile"](fileName, sourceText, languageVersion, setParentNodes, scriptKind).template as<_js_jts_dSourceFile>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createSourceMapSource(js_string fileName, js_string text, js_union<js_function<double(double)>, js_undefined> skipTrivia) noexcept {
		return emscripten::val::global("ts")["createSourceMapSource"](fileName, text, skipTrivia).template as<_js_jts_dSourceMapSource>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createSpread(_js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["createSpread"](expression).template as<_js_jts_dSpreadElement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createSpreadAssignment(_js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["createSpreadAssignment"](expression).template as<_js_jts_dSpreadAssignment>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createStrictEquality(_js_jts_dExpression left, _js_jts_dExpression right) noexcept {
		return emscripten::val::global("ts")["createStrictEquality"](left, right).template as<_js_jts_dBinaryExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createStrictInequality(_js_jts_dExpression left, _js_jts_dExpression right) noexcept {
		return emscripten::val::global("ts")["createStrictInequality"](left, right).template as<_js_jts_dBinaryExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createStringLiteral(js_string text) noexcept {
		return emscripten::val::global("ts")["createStringLiteral"](text).template as<_js_jts_dStringLiteral>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createSubtract(_js_jts_dExpression left, _js_jts_dExpression right) noexcept {
		return emscripten::val::global("ts")["createSubtract"](left, right).template as<_js_jts_dBinaryExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createSuper() noexcept {
		return emscripten::val::global("ts")["createSuper"]().template as<_js_jts_dSuperExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createSwitch(_js_jts_dExpression expression, _js_jts_dCaseBlock caseBlock) noexcept {
		return emscripten::val::global("ts")["createSwitch"](expression, caseBlock).template as<_js_jts_dSwitchStatement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createTaggedTemplate(_js_jts_dExpression tag, js_union<_js_jts_dNoSubstitutionTemplateLiteral, _js_jts_dTemplateExpression> template_) noexcept {
		return emscripten::val::global("ts")["createTaggedTemplate"](tag, template_).template as<_js_jts_dTaggedTemplateExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createTaggedTemplate(_js_jts_dExpression tag, js_union<js::ReadonlyArray<_js_jts_dTypeNode>, js_undefined> typeArguments, js_union<_js_jts_dNoSubstitutionTemplateLiteral, _js_jts_dTemplateExpression> template_) noexcept {
		return emscripten::val::global("ts")["createTaggedTemplate"](tag, typeArguments, template_).template as<_js_jts_dTaggedTemplateExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createTempVariable(js_union<js_function<void(_js_jts_dIdentifier)>, js_undefined> recordTempVariable) noexcept {
		return emscripten::val::global("ts")["createTempVariable"](recordTempVariable).template as<_js_jts_dIdentifier>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createTemplateExpression(_js_jts_dTemplateHead head, js::ReadonlyArray<_js_jts_dTemplateSpan> templateSpans) noexcept {
		return emscripten::val::global("ts")["createTemplateExpression"](head, templateSpans).template as<_js_jts_dTemplateExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createTemplateHead(js_string text) noexcept {
		return emscripten::val::global("ts")["createTemplateHead"](text).template as<_js_jts_dTemplateHead>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createTemplateMiddle(js_string text) noexcept {
		return emscripten::val::global("ts")["createTemplateMiddle"](text).template as<_js_jts_dTemplateMiddle>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createTemplateSpan(_js_jts_dExpression expression, js_union<_js_jts_dTemplateMiddle, _js_jts_dTemplateTail> literal) noexcept {
		return emscripten::val::global("ts")["createTemplateSpan"](expression, literal).template as<_js_jts_dTemplateSpan>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createTemplateTail(js_string text) noexcept {
		return emscripten::val::global("ts")["createTemplateTail"](text).template as<_js_jts_dTemplateTail>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createTextChangeRange(_js_jts_dTextSpan span, double newLength) noexcept {
		return emscripten::val::global("ts")["createTextChangeRange"](span, newLength).template as<_js_jts_dTextChangeRange>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createTextSpan(double start, double length) noexcept {
		return emscripten::val::global("ts")["createTextSpan"](start, length).template as<_js_jts_dTextSpan>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createTextSpanFromBounds(double start, double end) noexcept {
		return emscripten::val::global("ts")["createTextSpanFromBounds"](start, end).template as<_js_jts_dTextSpan>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createThis() noexcept {
		return emscripten::val::global("ts")["createThis"]().template as<js_unknown /*flags=2097152: ThisExpression & Token<SyntaxKind.ThisKeyword> ()*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createThisTypeNode() noexcept {
		return emscripten::val::global("ts")["createThisTypeNode"]().template as<_js_jts_dThisTypeNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createThrow(_js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["createThrow"](expression).template as<_js_jts_dThrowStatement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createToken(js_unknown /*flags=262144: TKind ()*/ token) noexcept {
		return emscripten::val::global("ts")["createToken"](token).template as<js_unknown /*flags=524288: Token<TKind> (TypeReference=ts.Token)*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createTrue() noexcept {
		return emscripten::val::global("ts")["createTrue"]().template as<js_unknown /*flags=2097152: BooleanLiteral & Token<SyntaxKind.TrueKeyword> ()*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createTry(_js_jts_dBlock tryBlock, js_union<_js_jts_dCatchClause, js_undefined> catchClause, js_union<_js_jts_dBlock, js_undefined> finallyBlock) noexcept {
		return emscripten::val::global("ts")["createTry"](tryBlock, catchClause, finallyBlock).template as<_js_jts_dTryStatement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createTupleTypeNode(js::ReadonlyArray<_js_jts_dTypeNode> elementTypes) noexcept {
		return emscripten::val::global("ts")["createTupleTypeNode"](elementTypes).template as<_js_jts_dTupleTypeNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createTypeAliasDeclaration(js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dIdentifier, js_string> name, js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, _js_jts_dTypeNode type) noexcept {
		return emscripten::val::global("ts")["createTypeAliasDeclaration"](decorators, modifiers, name, typeParameters, type).template as<_js_jts_dTypeAliasDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createTypeAssertion(_js_jts_dTypeNode type, _js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["createTypeAssertion"](type, expression).template as<_js_jts_dTypeAssertion>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createTypeLiteralNode(js_union<js::ReadonlyArray<_js_jts_dTypeElement>, js_undefined> members) noexcept {
		return emscripten::val::global("ts")["createTypeLiteralNode"](members).template as<_js_jts_dTypeLiteralNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createTypeOf(_js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["createTypeOf"](expression).template as<_js_jts_dTypeOfExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createTypeOperatorNode(_js_jts_dSyntaxKind /*SyntaxKind.KeyOfKeyword*/ operator_, _js_jts_dTypeNode type) noexcept {
		return emscripten::val::global("ts")["createTypeOperatorNode"](operator_, type).template as<_js_jts_dTypeOperatorNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createTypeOperatorNode(_js_jts_dTypeNode type) noexcept {
		return emscripten::val::global("ts")["createTypeOperatorNode"](type).template as<_js_jts_dTypeOperatorNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createTypeParameterDeclaration(js_union<_js_jts_dIdentifier, js_string> name, js_union<_js_jts_dTypeNode, js_undefined> constraint, js_union<_js_jts_dTypeNode, js_undefined> defaultType) noexcept {
		return emscripten::val::global("ts")["createTypeParameterDeclaration"](name, constraint, defaultType).template as<_js_jts_dTypeParameterDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createTypePredicateNode(js_union<_js_jts_dIdentifier, _js_jts_dThisTypeNode, js_string> parameterName, _js_jts_dTypeNode type) noexcept {
		return emscripten::val::global("ts")["createTypePredicateNode"](parameterName, type).template as<_js_jts_dTypePredicateNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createTypeQueryNode(js_union<_js_jts_dIdentifier, _js_jts_dQualifiedName> exprName) noexcept {
		return emscripten::val::global("ts")["createTypeQueryNode"](exprName).template as<_js_jts_dTypeQueryNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createTypeReferenceNode(js_union<_js_jts_dIdentifier, _js_jts_dQualifiedName, js_string> typeName, js_union<js::ReadonlyArray<_js_jts_dTypeNode>, js_undefined> typeArguments) noexcept {
		return emscripten::val::global("ts")["createTypeReferenceNode"](typeName, typeArguments).template as<_js_jts_dTypeReferenceNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createUnionOrIntersectionTypeNode(_js_jts_dSyntaxKind /*SyntaxKind.UnionType*/ kind, js::ReadonlyArray<_js_jts_dTypeNode> types) noexcept {
		return emscripten::val::global("ts")["createUnionOrIntersectionTypeNode"](kind, types).template as<js_union<_js_jts_dIntersectionTypeNode, _js_jts_dUnionTypeNode>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createUnionTypeNode(js::ReadonlyArray<_js_jts_dTypeNode> types) noexcept {
		return emscripten::val::global("ts")["createUnionTypeNode"](types).template as<_js_jts_dUnionTypeNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createUniqueName(js_string text) noexcept {
		return emscripten::val::global("ts")["createUniqueName"](text).template as<_js_jts_dIdentifier>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createUnparsedSourceFile(_js_jts_dInputFiles inputFile, js_string /*"js"*/ type, js_union<bool /*false*/, js_undefined> stripInternal) noexcept {
		return emscripten::val::global("ts")["createUnparsedSourceFile"](inputFile, type, stripInternal).template as<_js_jts_dUnparsedSource>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createUnparsedSourceFile(js_string text) noexcept {
		return emscripten::val::global("ts")["createUnparsedSourceFile"](text).template as<_js_jts_dUnparsedSource>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createUnparsedSourceFile(js_string text, js_union<js_string, js_undefined> mapPath, js_union<js_string, js_undefined> map) noexcept {
		return emscripten::val::global("ts")["createUnparsedSourceFile"](text, mapPath, map).template as<_js_jts_dUnparsedSource>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createVariableDeclaration(js_union<_js_jts_dArrayBindingPattern, _js_jts_dIdentifier, _js_jts_dObjectBindingPattern, js_string> name, js_union<_js_jts_dTypeNode, js_undefined> type, js_union<_js_jts_dExpression, js_undefined> initializer) noexcept {
		return emscripten::val::global("ts")["createVariableDeclaration"](name, type, initializer).template as<_js_jts_dVariableDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createVariableDeclarationList(js::ReadonlyArray<_js_jts_dVariableDeclaration> declarations, js_union<_js_jts_dNodeFlags /*NodeFlags.YieldContext*/, js_undefined> flags) noexcept {
		return emscripten::val::global("ts")["createVariableDeclarationList"](declarations, flags).template as<_js_jts_dVariableDeclarationList>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createVariableStatement(js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dVariableDeclarationList, js::ReadonlyArray<_js_jts_dVariableDeclaration>> declarationList) noexcept {
		return emscripten::val::global("ts")["createVariableStatement"](modifiers, declarationList).template as<_js_jts_dVariableStatement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createVoid(_js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["createVoid"](expression).template as<_js_jts_dVoidExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createVoidZero() noexcept {
		return emscripten::val::global("ts")["createVoidZero"]().template as<_js_jts_dVoidExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createWatchCompilerHost(js::Array<js_string> rootFiles, _js_jts_dCompilerOptions options, _js_jts_dSystem system, js_unknown /*flags=1048576: CreateProgram<T> | undefined ()*/ createProgram, js_union<js_function<void(_js_jts_dDiagnostic)>, js_undefined> reportDiagnostic, js_union<js_function<void(_js_jts_dDiagnostic, js_string, _js_jts_dCompilerOptions)>, js_undefined> reportWatchStatus, js_union<js::ReadonlyArray<_js_jts_dProjectReference>, js_undefined> projectReferences) noexcept {
		return emscripten::val::global("ts")["createWatchCompilerHost"](rootFiles, options, system, createProgram, reportDiagnostic, reportWatchStatus, projectReferences).template as<js_unknown /*flags=524288: WatchCompilerHostOfFilesAndCompilerOptions<T> (TypeReference=ts.WatchCompilerHostOfFilesAndCompilerOptions)*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createWatchCompilerHost(js_string configFileName, js_union<_js_jts_dCompilerOptions, js_undefined> optionsToExtend, _js_jts_dSystem system, js_unknown /*flags=1048576: CreateProgram<T> | undefined ()*/ createProgram, js_union<js_function<void(_js_jts_dDiagnostic)>, js_undefined> reportDiagnostic, js_union<js_function<void(_js_jts_dDiagnostic, js_string, _js_jts_dCompilerOptions)>, js_undefined> reportWatchStatus) noexcept {
		return emscripten::val::global("ts")["createWatchCompilerHost"](configFileName, optionsToExtend, system, createProgram, reportDiagnostic, reportWatchStatus).template as<js_unknown /*flags=524288: WatchCompilerHostOfConfigFile<T> (TypeReference=ts.WatchCompilerHostOfConfigFile)*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createWatchProgram(js_unknown /*flags=524288: WatchCompilerHostOfFilesAndCompilerOptions<T> (TypeReference=ts.WatchCompilerHostOfFilesAndCompilerOptions)*/ host) noexcept {
		return emscripten::val::global("ts")["createWatchProgram"](host).template as<js_unknown /*flags=524288: WatchOfFilesAndCompilerOptions<T> (TypeReference=ts.WatchOfFilesAndCompilerOptions)*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createWhile(_js_jts_dExpression expression, _js_jts_dStatement statement) noexcept {
		return emscripten::val::global("ts")["createWhile"](expression, statement).template as<_js_jts_dWhileStatement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createWith(_js_jts_dExpression expression, _js_jts_dStatement statement) noexcept {
		return emscripten::val::global("ts")["createWith"](expression, statement).template as<_js_jts_dWithStatement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createYield(js_union<_js_jts_dExpression, js_undefined> expression) noexcept {
		return emscripten::val::global("ts")["createYield"](expression).template as<_js_jts_dYieldExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createYield(js_unknown /*flags=1048576: Token<SyntaxKind.AsteriskToken> | undefined ()*/ asteriskToken, _js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["createYield"](asteriskToken, expression).template as<_js_jts_dYieldExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::decodedTextSpanIntersectsWith(double start1, double length1, double start2, double length2) noexcept {
		return emscripten::val::global("ts")["decodedTextSpanIntersectsWith"](start1, length1, start2, length2).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::displayPartsToString(js_union<js::Array<_js_jts_dSymbolDisplayPart>, js_undefined> displayParts) noexcept {
		return emscripten::val::global("ts")["displayPartsToString"](displayParts).template as<js_string>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::disposeEmitNodes(_js_jts_dSourceFile sourceFile) noexcept {
		emscripten::val::global("ts")["disposeEmitNodes"](sourceFile);
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::escapeLeadingUnderscores(js_string identifier) noexcept {
		return emscripten::val::global("ts")["escapeLeadingUnderscores"](identifier).template as<js_unknown /*flags=1048576: __String ()*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::findConfigFile(js_string searchPath, js_function<bool /*false*/(js_string)> fileExists, js_union<js_string, js_undefined> configName) noexcept {
		return emscripten::val::global("ts")["findConfigFile"](searchPath, fileExists, configName).template as<js_union<js_string, js_undefined>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::flattenDiagnosticMessageText(js_union<_js_jts_dDiagnosticMessageChain, js_string, js_undefined> messageText, js_string newLine) noexcept {
		return emscripten::val::global("ts")["flattenDiagnosticMessageText"](messageText, newLine).template as<js_string>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::forEachChild(_js_jts_dNode node, js_function<js_unknown /*flags=1048576: T | undefined ()*/(_js_jts_dNode)> cbNode, js_union<js_function<js_unknown /*flags=1048576: T | undefined ()*/(js_unknown /*flags=524288: NodeArray<Node> (TypeReference=ts.NodeArray)*/)>, js_undefined> cbNodes) noexcept {
		return emscripten::val::global("ts")["forEachChild"](node, cbNode, cbNodes).template as<js_unknown /*flags=1048576: T | undefined ()*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::forEachLeadingCommentRange(js_string text, double pos, js_function<js_unknown /*flags=262144: U ()*/(double, double, _js_jts_dSyntaxKind /*SyntaxKind.SingleLineCommentTrivia*/, bool /*false*/, js_unknown /*flags=262144: T ()*/)> cb, js_unknown /*flags=262144: T ()*/ state) noexcept {
		return emscripten::val::global("ts")["forEachLeadingCommentRange"](text, pos, cb, state).template as<js_unknown /*flags=1048576: U | undefined ()*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::forEachLeadingCommentRange(js_string text, double pos, js_function<js_unknown /*flags=262144: U ()*/(double, double, _js_jts_dSyntaxKind /*SyntaxKind.SingleLineCommentTrivia*/, bool /*false*/)> cb) noexcept {
		return emscripten::val::global("ts")["forEachLeadingCommentRange"](text, pos, cb).template as<js_unknown /*flags=1048576: U | undefined ()*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::forEachTrailingCommentRange(js_string text, double pos, js_function<js_unknown /*flags=262144: U ()*/(double, double, _js_jts_dSyntaxKind /*SyntaxKind.SingleLineCommentTrivia*/, bool /*false*/, js_unknown /*flags=262144: T ()*/)> cb, js_unknown /*flags=262144: T ()*/ state) noexcept {
		return emscripten::val::global("ts")["forEachTrailingCommentRange"](text, pos, cb, state).template as<js_unknown /*flags=1048576: U | undefined ()*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::forEachTrailingCommentRange(js_string text, double pos, js_function<js_unknown /*flags=262144: U ()*/(double, double, _js_jts_dSyntaxKind /*SyntaxKind.SingleLineCommentTrivia*/, bool /*false*/)> cb) noexcept {
		return emscripten::val::global("ts")["forEachTrailingCommentRange"](text, pos, cb).template as<js_unknown /*flags=1048576: U | undefined ()*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::formatDiagnostic(_js_jts_dDiagnostic diagnostic, _js_jts_dFormatDiagnosticsHost host) noexcept {
		return emscripten::val::global("ts")["formatDiagnostic"](diagnostic, host).template as<js_string>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::formatDiagnostics(js::ReadonlyArray<_js_jts_dDiagnostic> diagnostics, _js_jts_dFormatDiagnosticsHost host) noexcept {
		return emscripten::val::global("ts")["formatDiagnostics"](diagnostics, host).template as<js_string>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::formatDiagnosticsWithColorAndContext(js::ReadonlyArray<_js_jts_dDiagnostic> diagnostics, _js_jts_dFormatDiagnosticsHost host) noexcept {
		return emscripten::val::global("ts")["formatDiagnosticsWithColorAndContext"](diagnostics, host).template as<js_string>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getAllJSDocTagsOfKind(_js_jts_dNode node, _js_jts_dSyntaxKind /*SyntaxKind.Unknown*/ kind) noexcept {
		return emscripten::val::global("ts")["getAllJSDocTagsOfKind"](node, kind).template as<js::ReadonlyArray<_js_jts_dJSDocTag>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getAutomaticTypeDirectiveNames(_js_jts_dCompilerOptions options, _js_jts_dModuleResolutionHost host) noexcept {
		return emscripten::val::global("ts")["getAutomaticTypeDirectiveNames"](options, host).template as<js::Array<js_string>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getCombinedModifierFlags(_js_jts_dDeclaration node) noexcept {
		return emscripten::val::global("ts")["getCombinedModifierFlags"](node).template as<_js_jts_dModifierFlags /*ModifierFlags.None*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getCombinedNodeFlags(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["getCombinedNodeFlags"](node).template as<_js_jts_dNodeFlags /*NodeFlags.None*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getCommentRange(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["getCommentRange"](node).template as<_js_jts_dTextRange>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getConfigFileParsingDiagnostics(_js_jts_dParsedCommandLine configFileParseResult) noexcept {
		return emscripten::val::global("ts")["getConfigFileParsingDiagnostics"](configFileParseResult).template as<js::ReadonlyArray<_js_jts_dDiagnostic>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getConstantValue(js_union<_js_jts_dElementAccessExpression, _js_jts_dPropertyAccessExpression> node) noexcept {
		return emscripten::val::global("ts")["getConstantValue"](node).template as<js_union<double, js_string, js_undefined>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getDefaultCompilerOptions() noexcept {
		return emscripten::val::global("ts")["getDefaultCompilerOptions"]().template as<_js_jts_dCompilerOptions>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getDefaultFormatCodeSettings(js_union<js_string, js_undefined> newLineCharacter) noexcept {
		return emscripten::val::global("ts")["getDefaultFormatCodeSettings"](newLineCharacter).template as<_js_jts_dFormatCodeSettings>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getDefaultLibFileName(_js_jts_dCompilerOptions options) noexcept {
		return emscripten::val::global("ts")["getDefaultLibFileName"](options).template as<js_string>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getDefaultLibFilePath(_js_jts_dCompilerOptions options) noexcept {
		return emscripten::val::global("ts")["getDefaultLibFilePath"](options).template as<js_string>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getEffectiveConstraintOfTypeParameter(_js_jts_dTypeParameterDeclaration node) noexcept {
		return emscripten::val::global("ts")["getEffectiveConstraintOfTypeParameter"](node).template as<js_union<_js_jts_dTypeNode, js_undefined>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getEffectiveTypeParameterDeclarations(js_union<_js_jts_dArrowFunction, _js_jts_dCallSignatureDeclaration, _js_jts_dClassDeclaration, _js_jts_dClassExpression, _js_jts_dConstructSignatureDeclaration, _js_jts_dConstructorDeclaration, _js_jts_dConstructorTypeNode, _js_jts_dFunctionDeclaration, _js_jts_dFunctionExpression, _js_jts_dFunctionTypeNode, _js_jts_dGetAccessorDeclaration, _js_jts_dIndexSignatureDeclaration, _js_jts_dInterfaceDeclaration, _js_jts_dJSDocCallbackTag, _js_jts_dJSDocFunctionType, _js_jts_dJSDocSignature, _js_jts_dJSDocTemplateTag, _js_jts_dJSDocTypedefTag, _js_jts_dMethodDeclaration, _js_jts_dMethodSignature, _js_jts_dSetAccessorDeclaration, _js_jts_dTypeAliasDeclaration> node) noexcept {
		return emscripten::val::global("ts")["getEffectiveTypeParameterDeclarations"](node).template as<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getEffectiveTypeRoots(_js_jts_dCompilerOptions options, _js_jts_dGetEffectiveTypeRootsHost host) noexcept {
		return emscripten::val::global("ts")["getEffectiveTypeRoots"](options, host).template as<js_union<js::Array<js_string>, js_undefined>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getEmitHelpers(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["getEmitHelpers"](node).template as<js_union<js::Array<_js_jts_dEmitHelper>, js_undefined>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getGeneratedNameForNode(js_union<_js_jts_dNode, js_undefined> node) noexcept {
		return emscripten::val::global("ts")["getGeneratedNameForNode"](node).template as<_js_jts_dIdentifier>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getJSDocAugmentsTag(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["getJSDocAugmentsTag"](node).template as<js_union<_js_jts_dJSDocAugmentsTag, js_undefined>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getJSDocClassTag(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["getJSDocClassTag"](node).template as<js_union<_js_jts_dJSDocClassTag, js_undefined>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getJSDocEnumTag(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["getJSDocEnumTag"](node).template as<js_union<_js_jts_dJSDocEnumTag, js_undefined>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getJSDocParameterTags(_js_jts_dParameterDeclaration param) noexcept {
		return emscripten::val::global("ts")["getJSDocParameterTags"](param).template as<js::ReadonlyArray<_js_jts_dJSDocParameterTag>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getJSDocReturnTag(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["getJSDocReturnTag"](node).template as<js_union<_js_jts_dJSDocReturnTag, js_undefined>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getJSDocReturnType(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["getJSDocReturnType"](node).template as<js_union<_js_jts_dTypeNode, js_undefined>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getJSDocTags(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["getJSDocTags"](node).template as<js::ReadonlyArray<_js_jts_dJSDocTag>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getJSDocTemplateTag(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["getJSDocTemplateTag"](node).template as<js_union<_js_jts_dJSDocTemplateTag, js_undefined>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getJSDocThisTag(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["getJSDocThisTag"](node).template as<js_union<_js_jts_dJSDocThisTag, js_undefined>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getJSDocType(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["getJSDocType"](node).template as<js_union<_js_jts_dTypeNode, js_undefined>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getJSDocTypeParameterTags(_js_jts_dTypeParameterDeclaration param) noexcept {
		return emscripten::val::global("ts")["getJSDocTypeParameterTags"](param).template as<js::ReadonlyArray<_js_jts_dJSDocTemplateTag>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getJSDocTypeTag(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["getJSDocTypeTag"](node).template as<js_union<_js_jts_dJSDocTypeTag, js_undefined>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getLeadingCommentRanges(js_string text, double pos) noexcept {
		return emscripten::val::global("ts")["getLeadingCommentRanges"](text, pos).template as<js_union<js::Array<_js_jts_dCommentRange>, js_undefined>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getLineAndCharacterOfPosition(_js_jts_dSourceFileLike sourceFile, double position) noexcept {
		return emscripten::val::global("ts")["getLineAndCharacterOfPosition"](sourceFile, position).template as<_js_jts_dLineAndCharacter>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getMutableClone(js_unknown /*flags=262144: T ()*/ node) noexcept {
		return emscripten::val::global("ts")["getMutableClone"](node).template as<js_unknown /*flags=262144: T ()*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getNameOfDeclaration(js_union<_js_jts_dDeclaration, _js_jts_dExpression> declaration) noexcept {
		return emscripten::val::global("ts")["getNameOfDeclaration"](declaration).template as<js_union<_js_jts_dArrayBindingPattern, _js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNoSubstitutionTemplateLiteral, _js_jts_dNumericLiteral, _js_jts_dObjectBindingPattern, _js_jts_dStringLiteral, js_undefined>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getNameOfJSDocTypedef(_js_jts_dJSDocTypedefTag declaration) noexcept {
		return emscripten::val::global("ts")["getNameOfJSDocTypedef"](declaration).template as<js_union<_js_jts_dIdentifier, js_undefined>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getNodeMajorVersion() noexcept {
		return emscripten::val::global("ts")["getNodeMajorVersion"]().template as<js_union<double, js_undefined>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getOriginalNode(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["getOriginalNode"](node).template as<_js_jts_dNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getOriginalNode(_js_jts_dNode node, js_function<bool /*false*/(_js_jts_dNode)> nodeTest) noexcept {
		return emscripten::val::global("ts")["getOriginalNode"](node, nodeTest).template as<js_unknown /*flags=262144: T ()*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getOriginalNode(js_union<_js_jts_dNode, js_undefined> node) noexcept {
		return emscripten::val::global("ts")["getOriginalNode"](node).template as<js_union<_js_jts_dNode, js_undefined>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getOriginalNode(js_union<_js_jts_dNode, js_undefined> node, js_function<bool /*false*/(js_union<_js_jts_dNode, js_undefined>)> nodeTest) noexcept {
		return emscripten::val::global("ts")["getOriginalNode"](node, nodeTest).template as<js_unknown /*flags=1048576: T | undefined ()*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getParseTreeNode(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["getParseTreeNode"](node).template as<_js_jts_dNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getParseTreeNode(js_union<_js_jts_dNode, js_undefined> node, js_union<js_function<bool /*false*/(_js_jts_dNode)>, js_undefined> nodeTest) noexcept {
		return emscripten::val::global("ts")["getParseTreeNode"](node, nodeTest).template as<js_unknown /*flags=1048576: T | undefined ()*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getParsedCommandLineOfConfigFile(js_string configFileName, _js_jts_dCompilerOptions optionsToExtend, _js_jts_dParseConfigFileHost host, js_unknown /*flags=1048576: Map<ExtendedConfigCacheEntry> | undefined ()*/ extendedConfigCache) noexcept {
		return emscripten::val::global("ts")["getParsedCommandLineOfConfigFile"](configFileName, optionsToExtend, host, extendedConfigCache).template as<js_union<_js_jts_dParsedCommandLine, js_undefined>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getPositionOfLineAndCharacter(_js_jts_dSourceFileLike sourceFile, double line, double character) noexcept {
		return emscripten::val::global("ts")["getPositionOfLineAndCharacter"](sourceFile, line, character).template as<double>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getPreEmitDiagnostics(_js_jts_dProgram program, js_union<_js_jts_dSourceFile, js_undefined> sourceFile, js_union<_js_jts_dCancellationToken, js_undefined> cancellationToken) noexcept {
		return emscripten::val::global("ts")["getPreEmitDiagnostics"](program, sourceFile, cancellationToken).template as<js::ReadonlyArray<_js_jts_dDiagnostic>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getShebang(js_string text) noexcept {
		return emscripten::val::global("ts")["getShebang"](text).template as<js_union<js_string, js_undefined>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getSourceMapRange(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["getSourceMapRange"](node).template as<_js_jts_dSourceMapRange>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getSupportedCodeFixes() noexcept {
		return emscripten::val::global("ts")["getSupportedCodeFixes"]().template as<js::Array<js_string>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getSyntheticLeadingComments(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["getSyntheticLeadingComments"](node).template as<js_union<js::Array<_js_jts_dSynthesizedComment>, js_undefined>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getSyntheticTrailingComments(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["getSyntheticTrailingComments"](node).template as<js_union<js::Array<_js_jts_dSynthesizedComment>, js_undefined>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getTokenSourceMapRange(_js_jts_dNode node, _js_jts_dSyntaxKind /*SyntaxKind.Unknown*/ token) noexcept {
		return emscripten::val::global("ts")["getTokenSourceMapRange"](node, token).template as<js_union<_js_jts_dSourceMapRange, js_undefined>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getTrailingCommentRanges(js_string text, double pos) noexcept {
		return emscripten::val::global("ts")["getTrailingCommentRanges"](text, pos).template as<js_union<js::Array<_js_jts_dCommentRange>, js_undefined>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::getTypeParameterOwner(_js_jts_dDeclaration d) noexcept {
		return emscripten::val::global("ts")["getTypeParameterOwner"](d).template as<js_union<_js_jts_dDeclaration, js_undefined>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::hasJSDocParameterTags(js_union<_js_jts_dArrowFunction, _js_jts_dCallSignatureDeclaration, _js_jts_dConstructSignatureDeclaration, _js_jts_dConstructorDeclaration, _js_jts_dConstructorTypeNode, _js_jts_dFunctionDeclaration, _js_jts_dFunctionExpression, _js_jts_dFunctionTypeNode, _js_jts_dGetAccessorDeclaration, _js_jts_dIndexSignatureDeclaration, _js_jts_dJSDocFunctionType, _js_jts_dMethodDeclaration, _js_jts_dMethodSignature, _js_jts_dSetAccessorDeclaration> node) noexcept {
		return emscripten::val::global("ts")["hasJSDocParameterTags"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::idText(_js_jts_dIdentifier identifier) noexcept {
		return emscripten::val::global("ts")["idText"](identifier).template as<js_string>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isAccessor(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isAccessor"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isArrayBindingPattern(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isArrayBindingPattern"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isArrayLiteralExpression(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isArrayLiteralExpression"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isArrayTypeNode(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isArrayTypeNode"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isArrowFunction(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isArrowFunction"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isAsExpression(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isAsExpression"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isAssertionExpression(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isAssertionExpression"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isAwaitExpression(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isAwaitExpression"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isBigIntLiteral(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isBigIntLiteral"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isBinaryExpression(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isBinaryExpression"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isBindingElement(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isBindingElement"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isBindingName(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isBindingName"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isBlock(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isBlock"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isBreakOrContinueStatement(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isBreakOrContinueStatement"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isBreakStatement(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isBreakStatement"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isBundle(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isBundle"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isCallExpression(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isCallExpression"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isCallLikeExpression(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isCallLikeExpression"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isCallOrNewExpression(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isCallOrNewExpression"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isCallSignatureDeclaration(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isCallSignatureDeclaration"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isCaseBlock(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isCaseBlock"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isCaseClause(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isCaseClause"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isCaseOrDefaultClause(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isCaseOrDefaultClause"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isCatchClause(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isCatchClause"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isClassDeclaration(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isClassDeclaration"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isClassElement(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isClassElement"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isClassExpression(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isClassExpression"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isClassLike(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isClassLike"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isClassOrTypeElement(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isClassOrTypeElement"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isComputedPropertyName(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isComputedPropertyName"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isConditionalExpression(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isConditionalExpression"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isConditionalTypeNode(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isConditionalTypeNode"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isConstTypeReference(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isConstTypeReference"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isConstructSignatureDeclaration(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isConstructSignatureDeclaration"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isConstructorDeclaration(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isConstructorDeclaration"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isConstructorTypeNode(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isConstructorTypeNode"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isContinueStatement(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isContinueStatement"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isDebuggerStatement(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isDebuggerStatement"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isDecorator(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isDecorator"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isDefaultClause(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isDefaultClause"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isDeleteExpression(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isDeleteExpression"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isDoStatement(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isDoStatement"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isElementAccessExpression(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isElementAccessExpression"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isEmptyBindingElement(_js_jts_dBindingElement node) noexcept {
		return emscripten::val::global("ts")["isEmptyBindingElement"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isEmptyBindingPattern(js_union<_js_jts_dArrayBindingPattern, _js_jts_dIdentifier, _js_jts_dObjectBindingPattern> node) noexcept {
		return emscripten::val::global("ts")["isEmptyBindingPattern"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isEmptyStatement(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isEmptyStatement"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isEntityName(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isEntityName"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isEnumDeclaration(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isEnumDeclaration"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isEnumMember(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isEnumMember"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isExportAssignment(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isExportAssignment"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isExportDeclaration(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isExportDeclaration"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isExportSpecifier(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isExportSpecifier"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isExpressionStatement(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isExpressionStatement"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isExpressionWithTypeArguments(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isExpressionWithTypeArguments"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isExternalModule(_js_jts_dSourceFile file) noexcept {
		return emscripten::val::global("ts")["isExternalModule"](file).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isExternalModuleNameRelative(js_string moduleName) noexcept {
		return emscripten::val::global("ts")["isExternalModuleNameRelative"](moduleName).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isExternalModuleReference(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isExternalModuleReference"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isForInStatement(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isForInStatement"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isForOfStatement(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isForOfStatement"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isForStatement(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isForStatement"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isFunctionDeclaration(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isFunctionDeclaration"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isFunctionExpression(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isFunctionExpression"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isFunctionLike(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isFunctionLike"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isFunctionOrConstructorTypeNode(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isFunctionOrConstructorTypeNode"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isFunctionTypeNode(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isFunctionTypeNode"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isGetAccessor(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isGetAccessor"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isGetAccessorDeclaration(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isGetAccessorDeclaration"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isHeritageClause(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isHeritageClause"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isIdentifier(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isIdentifier"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isIdentifierPart(double ch, js_union<_js_jts_dScriptTarget /*ScriptTarget.ES2017*/, js_undefined> languageVersion) noexcept {
		return emscripten::val::global("ts")["isIdentifierPart"](ch, languageVersion).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isIdentifierStart(double ch, js_union<_js_jts_dScriptTarget /*ScriptTarget.ES2017*/, js_undefined> languageVersion) noexcept {
		return emscripten::val::global("ts")["isIdentifierStart"](ch, languageVersion).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isIfStatement(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isIfStatement"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isImportClause(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isImportClause"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isImportDeclaration(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isImportDeclaration"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isImportEqualsDeclaration(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isImportEqualsDeclaration"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isImportOrExportSpecifier(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isImportOrExportSpecifier"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isImportSpecifier(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isImportSpecifier"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isImportTypeNode(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isImportTypeNode"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isIndexSignatureDeclaration(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isIndexSignatureDeclaration"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isIndexedAccessTypeNode(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isIndexedAccessTypeNode"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isInferTypeNode(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isInferTypeNode"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isInterfaceDeclaration(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isInterfaceDeclaration"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isIntersectionTypeNode(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isIntersectionTypeNode"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isIterationStatement(_js_jts_dNode node, bool /*false*/ lookInLabeledStatements) noexcept {
		return emscripten::val::global("ts")["isIterationStatement"](node, lookInLabeledStatements).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isJSDoc(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isJSDoc"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isJSDocAllType(_js_jts_dJSDocAllType node) noexcept {
		return emscripten::val::global("ts")["isJSDocAllType"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isJSDocAugmentsTag(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isJSDocAugmentsTag"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isJSDocCallbackTag(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isJSDocCallbackTag"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isJSDocClassTag(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isJSDocClassTag"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isJSDocCommentContainingNode(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isJSDocCommentContainingNode"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isJSDocEnumTag(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isJSDocEnumTag"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isJSDocFunctionType(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isJSDocFunctionType"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isJSDocNonNullableType(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isJSDocNonNullableType"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isJSDocNullableType(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isJSDocNullableType"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isJSDocOptionalType(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isJSDocOptionalType"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isJSDocParameterTag(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isJSDocParameterTag"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isJSDocPropertyLikeTag(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isJSDocPropertyLikeTag"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isJSDocPropertyTag(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isJSDocPropertyTag"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isJSDocReturnTag(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isJSDocReturnTag"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isJSDocSignature(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isJSDocSignature"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isJSDocTemplateTag(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isJSDocTemplateTag"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isJSDocThisTag(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isJSDocThisTag"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isJSDocTypeExpression(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isJSDocTypeExpression"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isJSDocTypeLiteral(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isJSDocTypeLiteral"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isJSDocTypeTag(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isJSDocTypeTag"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isJSDocTypedefTag(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isJSDocTypedefTag"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isJSDocUnknownType(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isJSDocUnknownType"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isJSDocVariadicType(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isJSDocVariadicType"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isJsxAttribute(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isJsxAttribute"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isJsxAttributes(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isJsxAttributes"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isJsxClosingElement(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isJsxClosingElement"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isJsxClosingFragment(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isJsxClosingFragment"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isJsxElement(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isJsxElement"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isJsxExpression(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isJsxExpression"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isJsxFragment(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isJsxFragment"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isJsxOpeningElement(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isJsxOpeningElement"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isJsxOpeningFragment(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isJsxOpeningFragment"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isJsxOpeningLikeElement(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isJsxOpeningLikeElement"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isJsxSelfClosingElement(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isJsxSelfClosingElement"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isJsxSpreadAttribute(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isJsxSpreadAttribute"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isJsxText(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isJsxText"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isLabeledStatement(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isLabeledStatement"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isLineBreak(double ch) noexcept {
		return emscripten::val::global("ts")["isLineBreak"](ch).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isLiteralExpression(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isLiteralExpression"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isLiteralTypeNode(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isLiteralTypeNode"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isMappedTypeNode(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isMappedTypeNode"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isMetaProperty(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isMetaProperty"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isMethodDeclaration(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isMethodDeclaration"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isMethodSignature(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isMethodSignature"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isMissingDeclaration(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isMissingDeclaration"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isModifier(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isModifier"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isModuleBlock(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isModuleBlock"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isModuleDeclaration(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isModuleDeclaration"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isNamedExports(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isNamedExports"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isNamedImports(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isNamedImports"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isNamespaceExportDeclaration(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isNamespaceExportDeclaration"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isNamespaceImport(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isNamespaceImport"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isNewExpression(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isNewExpression"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isNoSubstitutionTemplateLiteral(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isNoSubstitutionTemplateLiteral"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isNonNullExpression(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isNonNullExpression"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isNumericLiteral(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isNumericLiteral"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isObjectBindingPattern(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isObjectBindingPattern"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isObjectLiteralElement(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isObjectLiteralElement"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isObjectLiteralElementLike(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isObjectLiteralElementLike"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isObjectLiteralExpression(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isObjectLiteralExpression"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isOmittedExpression(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isOmittedExpression"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isParameter(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isParameter"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isParameterPropertyDeclaration(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isParameterPropertyDeclaration"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isParenthesizedExpression(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isParenthesizedExpression"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isParenthesizedTypeNode(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isParenthesizedTypeNode"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isParseTreeNode(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isParseTreeNode"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isPostfixUnaryExpression(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isPostfixUnaryExpression"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isPrefixUnaryExpression(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isPrefixUnaryExpression"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isPropertyAccessExpression(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isPropertyAccessExpression"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isPropertyAccessOrQualifiedName(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isPropertyAccessOrQualifiedName"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isPropertyAssignment(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isPropertyAssignment"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isPropertyDeclaration(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isPropertyDeclaration"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isPropertyName(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isPropertyName"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isPropertySignature(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isPropertySignature"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isQualifiedName(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isQualifiedName"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isRegularExpressionLiteral(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isRegularExpressionLiteral"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isReturnStatement(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isReturnStatement"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isSemicolonClassElement(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isSemicolonClassElement"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isSetAccessor(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isSetAccessor"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isSetAccessorDeclaration(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isSetAccessorDeclaration"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isShorthandPropertyAssignment(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isShorthandPropertyAssignment"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isSourceFile(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isSourceFile"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isSpreadAssignment(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isSpreadAssignment"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isSpreadElement(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isSpreadElement"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isStringLiteral(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isStringLiteral"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isStringLiteralLike(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isStringLiteralLike"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isStringTextContainingNode(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isStringTextContainingNode"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isSwitchStatement(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isSwitchStatement"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isTaggedTemplateExpression(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isTaggedTemplateExpression"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isTemplateExpression(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isTemplateExpression"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isTemplateHead(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isTemplateHead"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isTemplateLiteral(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isTemplateLiteral"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isTemplateLiteralToken(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isTemplateLiteralToken"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isTemplateMiddle(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isTemplateMiddle"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isTemplateMiddleOrTemplateTail(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isTemplateMiddleOrTemplateTail"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isTemplateSpan(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isTemplateSpan"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isTemplateTail(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isTemplateTail"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isThisTypeNode(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isThisTypeNode"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isThrowStatement(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isThrowStatement"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isToken(_js_jts_dNode n) noexcept {
		return emscripten::val::global("ts")["isToken"](n).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isTryStatement(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isTryStatement"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isTupleTypeNode(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isTupleTypeNode"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isTypeAliasDeclaration(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isTypeAliasDeclaration"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isTypeAssertion(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isTypeAssertion"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isTypeElement(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isTypeElement"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isTypeLiteralNode(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isTypeLiteralNode"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isTypeNode(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isTypeNode"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isTypeOfExpression(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isTypeOfExpression"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isTypeOperatorNode(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isTypeOperatorNode"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isTypeParameterDeclaration(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isTypeParameterDeclaration"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isTypePredicateNode(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isTypePredicateNode"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isTypeQueryNode(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isTypeQueryNode"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isTypeReferenceNode(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isTypeReferenceNode"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isUnionTypeNode(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isUnionTypeNode"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isUnparsedNode(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isUnparsedNode"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isUnparsedPrepend(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isUnparsedPrepend"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isUnparsedSource(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isUnparsedSource"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isUnparsedTextLike(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isUnparsedTextLike"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isVariableDeclaration(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isVariableDeclaration"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isVariableDeclarationList(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isVariableDeclarationList"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isVariableStatement(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isVariableStatement"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isVoidExpression(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isVoidExpression"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isWhileStatement(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isWhileStatement"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isWhiteSpaceLike(double ch) noexcept {
		return emscripten::val::global("ts")["isWhiteSpaceLike"](ch).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isWhiteSpaceSingleLine(double ch) noexcept {
		return emscripten::val::global("ts")["isWhiteSpaceSingleLine"](ch).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isWithStatement(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isWithStatement"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::isYieldExpression(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["isYieldExpression"](node).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::moveEmitHelpers(_js_jts_dNode source, _js_jts_dNode target, js_function<bool /*false*/(_js_jts_dEmitHelper)> predicate) noexcept {
		emscripten::val::global("ts")["moveEmitHelpers"](source, target, predicate);
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::moveSyntheticComments(js_unknown /*flags=262144: T ()*/ node, _js_jts_dNode original) noexcept {
		return emscripten::val::global("ts")["moveSyntheticComments"](node, original).template as<js_unknown /*flags=262144: T ()*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::nodeModuleNameResolver(js_string moduleName, js_string containingFile, _js_jts_dCompilerOptions compilerOptions, _js_jts_dModuleResolutionHost host, js_union<_js_jts_dModuleResolutionCache, js_undefined> cache, js_union<_js_jts_dResolvedProjectReference, js_undefined> redirectedReference) noexcept {
		return emscripten::val::global("ts")["nodeModuleNameResolver"](moduleName, containingFile, compilerOptions, host, cache, redirectedReference).template as<_js_jts_dResolvedModuleWithFailedLookupLocations>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::parseCommandLine(js::ReadonlyArray<js_string> commandLine, js_union<js_function<js_union<js_string, js_undefined>(js_string)>, js_undefined> readFile) noexcept {
		return emscripten::val::global("ts")["parseCommandLine"](commandLine, readFile).template as<_js_jts_dParsedCommandLine>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::parseConfigFileTextToJson(js_string fileName, js_string jsonText) noexcept {
		return emscripten::val::global("ts")["parseConfigFileTextToJson"](fileName, jsonText).template as<js_unknown /*flags=524288: { config?: any; error?: Diagnostic | undefined; } (AnonymousTypeWithTypeLiteral(members:[config, error]))*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::parseIsolatedEntityName(js_string text, _js_jts_dScriptTarget /*ScriptTarget.ES3*/ languageVersion) noexcept {
		return emscripten::val::global("ts")["parseIsolatedEntityName"](text, languageVersion).template as<js_union<_js_jts_dIdentifier, _js_jts_dQualifiedName, js_undefined>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::parseJsonConfigFileContent(js_unknown json, _js_jts_dParseConfigHost host, js_string basePath, js_union<_js_jts_dCompilerOptions, js_undefined> existingOptions, js_union<js_string, js_undefined> configFileName, js_union<js::Array<js_unknown /*flags=2097152: Path ()*/>, js_undefined> resolutionStack, js_union<js::ReadonlyArray<_js_jts_dFileExtensionInfo>, js_undefined> extraFileExtensions, js_unknown /*flags=1048576: Map<ExtendedConfigCacheEntry> | undefined ()*/ extendedConfigCache) noexcept {
		return emscripten::val::global("ts")["parseJsonConfigFileContent"](json, host, basePath, existingOptions, configFileName, resolutionStack, extraFileExtensions, extendedConfigCache).template as<_js_jts_dParsedCommandLine>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::parseJsonSourceFileConfigFileContent(_js_jts_dTsConfigSourceFile sourceFile, _js_jts_dParseConfigHost host, js_string basePath, js_union<_js_jts_dCompilerOptions, js_undefined> existingOptions, js_union<js_string, js_undefined> configFileName, js_union<js::Array<js_unknown /*flags=2097152: Path ()*/>, js_undefined> resolutionStack, js_union<js::ReadonlyArray<_js_jts_dFileExtensionInfo>, js_undefined> extraFileExtensions, js_unknown /*flags=1048576: Map<ExtendedConfigCacheEntry> | undefined ()*/ extendedConfigCache) noexcept {
		return emscripten::val::global("ts")["parseJsonSourceFileConfigFileContent"](sourceFile, host, basePath, existingOptions, configFileName, resolutionStack, extraFileExtensions, extendedConfigCache).template as<_js_jts_dParsedCommandLine>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::parseJsonText(js_string fileName, js_string sourceText) noexcept {
		return emscripten::val::global("ts")["parseJsonText"](fileName, sourceText).template as<_js_jts_dJsonSourceFile>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::preProcessFile(js_string sourceText, js_union<bool /*false*/, js_undefined> readImportFiles, js_union<bool /*false*/, js_undefined> detectJavaScriptImports) noexcept {
		return emscripten::val::global("ts")["preProcessFile"](sourceText, readImportFiles, detectJavaScriptImports).template as<_js_jts_dPreProcessedFileInfo>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::readConfigFile(js_string fileName, js_function<js_union<js_string, js_undefined>(js_string)> readFile) noexcept {
		return emscripten::val::global("ts")["readConfigFile"](fileName, readFile).template as<js_unknown /*flags=524288: { config?: any; error?: Diagnostic | undefined; } (AnonymousTypeWithTypeLiteral(members:[config, error]))*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::readJsonConfigFile(js_string fileName, js_function<js_union<js_string, js_undefined>(js_string)> readFile) noexcept {
		return emscripten::val::global("ts")["readJsonConfigFile"](fileName, readFile).template as<_js_jts_dTsConfigSourceFile>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::reduceEachLeadingCommentRange(js_string text, double pos, js_function<js_unknown /*flags=262144: U ()*/(double, double, _js_jts_dSyntaxKind /*SyntaxKind.SingleLineCommentTrivia*/, bool /*false*/, js_unknown /*flags=262144: T ()*/, js_unknown /*flags=262144: U ()*/)> cb, js_unknown /*flags=262144: T ()*/ state, js_unknown /*flags=262144: U ()*/ initial) noexcept {
		return emscripten::val::global("ts")["reduceEachLeadingCommentRange"](text, pos, cb, state, initial).template as<js_unknown /*flags=1048576: U | undefined ()*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::reduceEachTrailingCommentRange(js_string text, double pos, js_function<js_unknown /*flags=262144: U ()*/(double, double, _js_jts_dSyntaxKind /*SyntaxKind.SingleLineCommentTrivia*/, bool /*false*/, js_unknown /*flags=262144: T ()*/, js_unknown /*flags=262144: U ()*/)> cb, js_unknown /*flags=262144: T ()*/ state, js_unknown /*flags=262144: U ()*/ initial) noexcept {
		return emscripten::val::global("ts")["reduceEachTrailingCommentRange"](text, pos, cb, state, initial).template as<js_unknown /*flags=1048576: U | undefined ()*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::removeEmitHelper(_js_jts_dNode node, _js_jts_dEmitHelper helper) noexcept {
		return emscripten::val::global("ts")["removeEmitHelper"](node, helper).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::resolveModuleName(js_string moduleName, js_string containingFile, _js_jts_dCompilerOptions compilerOptions, _js_jts_dModuleResolutionHost host, js_union<_js_jts_dModuleResolutionCache, js_undefined> cache, js_union<_js_jts_dResolvedProjectReference, js_undefined> redirectedReference) noexcept {
		return emscripten::val::global("ts")["resolveModuleName"](moduleName, containingFile, compilerOptions, host, cache, redirectedReference).template as<_js_jts_dResolvedModuleWithFailedLookupLocations>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::resolveModuleNameFromCache(js_string moduleName, js_string containingFile, _js_jts_dModuleResolutionCache cache) noexcept {
		return emscripten::val::global("ts")["resolveModuleNameFromCache"](moduleName, containingFile, cache).template as<js_union<_js_jts_dResolvedModuleWithFailedLookupLocations, js_undefined>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::resolveProjectReferencePath(_js_jts_dProjectReference ref) noexcept {
		return emscripten::val::global("ts")["resolveProjectReferencePath"](ref).template as<js_unknown /*flags=2097152: ResolvedConfigFileName ()*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::resolveProjectReferencePath(_js_jts_dResolveProjectReferencePathHost host, _js_jts_dProjectReference ref) noexcept {
		return emscripten::val::global("ts")["resolveProjectReferencePath"](host, ref).template as<js_unknown /*flags=2097152: ResolvedConfigFileName ()*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::resolveTripleslashReference(js_string moduleName, js_string containingFile) noexcept {
		return emscripten::val::global("ts")["resolveTripleslashReference"](moduleName, containingFile).template as<js_string>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::resolveTypeReferenceDirective(js_string typeReferenceDirectiveName, js_union<js_string, js_undefined> containingFile, _js_jts_dCompilerOptions options, _js_jts_dModuleResolutionHost host, js_union<_js_jts_dResolvedProjectReference, js_undefined> redirectedReference) noexcept {
		return emscripten::val::global("ts")["resolveTypeReferenceDirective"](typeReferenceDirectiveName, containingFile, options, host, redirectedReference).template as<_js_jts_dResolvedTypeReferenceDirectiveWithFailedLookupLocations>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::setCommentRange(js_unknown /*flags=262144: T ()*/ node, _js_jts_dTextRange range) noexcept {
		return emscripten::val::global("ts")["setCommentRange"](node, range).template as<js_unknown /*flags=262144: T ()*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::setConstantValue(js_union<_js_jts_dElementAccessExpression, _js_jts_dPropertyAccessExpression> node, js_union<double, js_string> value) noexcept {
		return emscripten::val::global("ts")["setConstantValue"](node, value).template as<js_union<_js_jts_dElementAccessExpression, _js_jts_dPropertyAccessExpression>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::setEmitFlags(js_unknown /*flags=262144: T ()*/ node, _js_jts_dEmitFlags /*EmitFlags.None*/ emitFlags) noexcept {
		return emscripten::val::global("ts")["setEmitFlags"](node, emitFlags).template as<js_unknown /*flags=262144: T ()*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::setOriginalNode(js_unknown /*flags=262144: T ()*/ node, js_union<_js_jts_dNode, js_undefined> original) noexcept {
		return emscripten::val::global("ts")["setOriginalNode"](node, original).template as<js_unknown /*flags=262144: T ()*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::setSourceMapRange(js_unknown /*flags=262144: T ()*/ node, js_union<_js_jts_dSourceMapRange, js_undefined> range) noexcept {
		return emscripten::val::global("ts")["setSourceMapRange"](node, range).template as<js_unknown /*flags=262144: T ()*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::setSyntheticLeadingComments(js_unknown /*flags=262144: T ()*/ node, js_union<js::Array<_js_jts_dSynthesizedComment>, js_undefined> comments) noexcept {
		return emscripten::val::global("ts")["setSyntheticLeadingComments"](node, comments).template as<js_unknown /*flags=262144: T ()*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::setSyntheticTrailingComments(js_unknown /*flags=262144: T ()*/ node, js_union<js::Array<_js_jts_dSynthesizedComment>, js_undefined> comments) noexcept {
		return emscripten::val::global("ts")["setSyntheticTrailingComments"](node, comments).template as<js_unknown /*flags=262144: T ()*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::setTextRange(js_unknown /*flags=262144: T ()*/ range, js_union<_js_jts_dTextRange, js_undefined> location) noexcept {
		return emscripten::val::global("ts")["setTextRange"](range, location).template as<js_unknown /*flags=262144: T ()*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::setTokenSourceMapRange(js_unknown /*flags=262144: T ()*/ node, _js_jts_dSyntaxKind /*SyntaxKind.Unknown*/ token, js_union<_js_jts_dSourceMapRange, js_undefined> range) noexcept {
		return emscripten::val::global("ts")["setTokenSourceMapRange"](node, token, range).template as<js_unknown /*flags=262144: T ()*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::skipPartiallyEmittedExpressions(_js_jts_dExpression node) noexcept {
		return emscripten::val::global("ts")["skipPartiallyEmittedExpressions"](node).template as<_js_jts_dExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::skipPartiallyEmittedExpressions(_js_jts_dNode node) noexcept {
		return emscripten::val::global("ts")["skipPartiallyEmittedExpressions"](node).template as<_js_jts_dNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::sortAndDeduplicateDiagnostics(js::ReadonlyArray<js_unknown /*flags=262144: T ()*/> diagnostics) noexcept {
		return emscripten::val::global("ts")["sortAndDeduplicateDiagnostics"](diagnostics).template as<js_unknown /*flags=524288: SortedReadonlyArray<T> (TypeReference=ts.SortedReadonlyArray)*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::symbolName(_js_jts_dSymbol symbol) noexcept {
		return emscripten::val::global("ts")["symbolName"](symbol).template as<js_string>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::textChangeRangeIsUnchanged(_js_jts_dTextChangeRange range) noexcept {
		return emscripten::val::global("ts")["textChangeRangeIsUnchanged"](range).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::textChangeRangeNewSpan(_js_jts_dTextChangeRange range) noexcept {
		return emscripten::val::global("ts")["textChangeRangeNewSpan"](range).template as<_js_jts_dTextSpan>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::textSpanContainsPosition(_js_jts_dTextSpan span, double position) noexcept {
		return emscripten::val::global("ts")["textSpanContainsPosition"](span, position).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::textSpanContainsTextSpan(_js_jts_dTextSpan span, _js_jts_dTextSpan other) noexcept {
		return emscripten::val::global("ts")["textSpanContainsTextSpan"](span, other).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::textSpanEnd(_js_jts_dTextSpan span) noexcept {
		return emscripten::val::global("ts")["textSpanEnd"](span).template as<double>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::textSpanIntersection(_js_jts_dTextSpan span1, _js_jts_dTextSpan span2) noexcept {
		return emscripten::val::global("ts")["textSpanIntersection"](span1, span2).template as<js_union<_js_jts_dTextSpan, js_undefined>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::textSpanIntersectsWith(_js_jts_dTextSpan span, double start, double length) noexcept {
		return emscripten::val::global("ts")["textSpanIntersectsWith"](span, start, length).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::textSpanIntersectsWithPosition(_js_jts_dTextSpan span, double position) noexcept {
		return emscripten::val::global("ts")["textSpanIntersectsWithPosition"](span, position).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::textSpanIntersectsWithTextSpan(_js_jts_dTextSpan span, _js_jts_dTextSpan other) noexcept {
		return emscripten::val::global("ts")["textSpanIntersectsWithTextSpan"](span, other).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::textSpanIsEmpty(_js_jts_dTextSpan span) noexcept {
		return emscripten::val::global("ts")["textSpanIsEmpty"](span).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::textSpanOverlap(_js_jts_dTextSpan span1, _js_jts_dTextSpan span2) noexcept {
		return emscripten::val::global("ts")["textSpanOverlap"](span1, span2).template as<js_union<_js_jts_dTextSpan, js_undefined>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::textSpanOverlapsWith(_js_jts_dTextSpan span, _js_jts_dTextSpan other) noexcept {
		return emscripten::val::global("ts")["textSpanOverlapsWith"](span, other).template as<bool /*false*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::toEditorSettings(js_union<_js_jts_dEditorOptions, _js_jts_dEditorSettings> options) noexcept {
		return emscripten::val::global("ts")["toEditorSettings"](options).template as<_js_jts_dEditorSettings>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::tokenToString(_js_jts_dSyntaxKind /*SyntaxKind.Unknown*/ t) noexcept {
		return emscripten::val::global("ts")["tokenToString"](t).template as<js_union<js_string, js_undefined>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::transform(js_unknown /*flags=1048576: T | T[] ()*/ source, js::Array<js_unknown /*flags=524288: TransformerFactory<T> ()*/> transformers, js_union<_js_jts_dCompilerOptions, js_undefined> compilerOptions) noexcept {
		return emscripten::val::global("ts")["transform"](source, transformers, compilerOptions).template as<js_unknown /*flags=524288: TransformationResult<T> (TypeReference=ts.TransformationResult)*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::transpile(js_string input, js_union<_js_jts_dCompilerOptions, js_undefined> compilerOptions, js_union<js_string, js_undefined> fileName, js_union<js::Array<_js_jts_dDiagnostic>, js_undefined> diagnostics, js_union<js_string, js_undefined> moduleName) noexcept {
		return emscripten::val::global("ts")["transpile"](input, compilerOptions, fileName, diagnostics, moduleName).template as<js_string>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::transpileModule(js_string input, _js_jts_dTranspileOptions transpileOptions) noexcept {
		return emscripten::val::global("ts")["transpileModule"](input, transpileOptions).template as<_js_jts_dTranspileOutput>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::unescapeLeadingUnderscores(js_unknown /*flags=1048576: __String ()*/ identifier) noexcept {
		return emscripten::val::global("ts")["unescapeLeadingUnderscores"](identifier).template as<js_string>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateArrayBindingPattern(_js_jts_dArrayBindingPattern node, js::ReadonlyArray<js_union<_js_jts_dBindingElement, _js_jts_dOmittedExpression>> elements) noexcept {
		return emscripten::val::global("ts")["updateArrayBindingPattern"](node, elements).template as<_js_jts_dArrayBindingPattern>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateArrayLiteral(_js_jts_dArrayLiteralExpression node, js::ReadonlyArray<_js_jts_dExpression> elements) noexcept {
		return emscripten::val::global("ts")["updateArrayLiteral"](node, elements).template as<_js_jts_dArrayLiteralExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateArrayTypeNode(_js_jts_dArrayTypeNode node, _js_jts_dTypeNode elementType) noexcept {
		return emscripten::val::global("ts")["updateArrayTypeNode"](node, elementType).template as<_js_jts_dArrayTypeNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateArrowFunction(_js_jts_dArrowFunction node, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, js_union<_js_jts_dTypeNode, js_undefined> type, js_unknown /*flags=524288: Token<SyntaxKind.EqualsGreaterThanToken> (TypeReference=ts.Token)*/ equalsGreaterThanToken, js_union<_js_jts_dBlock, _js_jts_dExpression> body) noexcept {
		return emscripten::val::global("ts")["updateArrowFunction"](node, modifiers, typeParameters, parameters, type, equalsGreaterThanToken, body).template as<_js_jts_dArrowFunction>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateAsExpression(_js_jts_dAsExpression node, _js_jts_dExpression expression, _js_jts_dTypeNode type) noexcept {
		return emscripten::val::global("ts")["updateAsExpression"](node, expression, type).template as<_js_jts_dAsExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateAwait(_js_jts_dAwaitExpression node, _js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["updateAwait"](node, expression).template as<_js_jts_dAwaitExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateBinary(_js_jts_dBinaryExpression node, _js_jts_dExpression left, _js_jts_dExpression right, js_unknown /*flags=1048576: SyntaxKind.CommaToken | SyntaxKind.LessThanToken | SyntaxKind.GreaterThanToken | SyntaxKind.LessThanEqualsToken | SyntaxKind.GreaterThanEqualsToken | SyntaxKind.EqualsEqualsToken | SyntaxKind.ExclamationEqualsToken | SyntaxKind.EqualsEqualsEqualsToken | SyntaxKind.ExclamationEqualsEqualsToken | SyntaxKind.PlusToken ... ()*/ operator_) noexcept {
		return emscripten::val::global("ts")["updateBinary"](node, left, right, operator_).template as<_js_jts_dBinaryExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateBindingElement(_js_jts_dBindingElement node, js_unknown /*flags=1048576: Token<SyntaxKind.DotDotDotToken> | undefined ()*/ dotDotDotToken, js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral, js_undefined> propertyName, js_union<_js_jts_dArrayBindingPattern, _js_jts_dIdentifier, _js_jts_dObjectBindingPattern> name, js_union<_js_jts_dExpression, js_undefined> initializer) noexcept {
		return emscripten::val::global("ts")["updateBindingElement"](node, dotDotDotToken, propertyName, name, initializer).template as<_js_jts_dBindingElement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateBlock(_js_jts_dBlock node, js::ReadonlyArray<_js_jts_dStatement> statements) noexcept {
		return emscripten::val::global("ts")["updateBlock"](node, statements).template as<_js_jts_dBlock>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateBreak(_js_jts_dBreakStatement node, js_union<_js_jts_dIdentifier, js_undefined> label) noexcept {
		return emscripten::val::global("ts")["updateBreak"](node, label).template as<_js_jts_dBreakStatement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateBundle(_js_jts_dBundle node, js::ReadonlyArray<_js_jts_dSourceFile> sourceFiles, js_union<js::ReadonlyArray<js_union<_js_jts_dInputFiles, _js_jts_dUnparsedSource>>, js_undefined> prepends) noexcept {
		return emscripten::val::global("ts")["updateBundle"](node, sourceFiles, prepends).template as<_js_jts_dBundle>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateCall(_js_jts_dCallExpression node, _js_jts_dExpression expression, js_union<js::ReadonlyArray<_js_jts_dTypeNode>, js_undefined> typeArguments, js::ReadonlyArray<_js_jts_dExpression> argumentsArray) noexcept {
		return emscripten::val::global("ts")["updateCall"](node, expression, typeArguments, argumentsArray).template as<_js_jts_dCallExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateCallSignature(_js_jts_dCallSignatureDeclaration node, js_unknown /*flags=1048576: NodeArray<TypeParameterDeclaration> | undefined ()*/ typeParameters, js_unknown /*flags=524288: NodeArray<ParameterDeclaration> (TypeReference=ts.NodeArray)*/ parameters, js_union<_js_jts_dTypeNode, js_undefined> type) noexcept {
		return emscripten::val::global("ts")["updateCallSignature"](node, typeParameters, parameters, type).template as<_js_jts_dCallSignatureDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateCaseBlock(_js_jts_dCaseBlock node, js::ReadonlyArray<js_union<_js_jts_dCaseClause, _js_jts_dDefaultClause>> clauses) noexcept {
		return emscripten::val::global("ts")["updateCaseBlock"](node, clauses).template as<_js_jts_dCaseBlock>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateCaseClause(_js_jts_dCaseClause node, _js_jts_dExpression expression, js::ReadonlyArray<_js_jts_dStatement> statements) noexcept {
		return emscripten::val::global("ts")["updateCaseClause"](node, expression, statements).template as<_js_jts_dCaseClause>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateCatchClause(_js_jts_dCatchClause node, js_union<_js_jts_dVariableDeclaration, js_undefined> variableDeclaration, _js_jts_dBlock block) noexcept {
		return emscripten::val::global("ts")["updateCatchClause"](node, variableDeclaration, block).template as<_js_jts_dCatchClause>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateClassDeclaration(_js_jts_dClassDeclaration node, js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dIdentifier, js_undefined> name, js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, js_union<js::ReadonlyArray<_js_jts_dHeritageClause>, js_undefined> heritageClauses, js::ReadonlyArray<_js_jts_dClassElement> members) noexcept {
		return emscripten::val::global("ts")["updateClassDeclaration"](node, decorators, modifiers, name, typeParameters, heritageClauses, members).template as<_js_jts_dClassDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateClassExpression(_js_jts_dClassExpression node, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dIdentifier, js_undefined> name, js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, js_union<js::ReadonlyArray<_js_jts_dHeritageClause>, js_undefined> heritageClauses, js::ReadonlyArray<_js_jts_dClassElement> members) noexcept {
		return emscripten::val::global("ts")["updateClassExpression"](node, modifiers, name, typeParameters, heritageClauses, members).template as<_js_jts_dClassExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateCommaList(_js_jts_dCommaListExpression node, js::ReadonlyArray<_js_jts_dExpression> elements) noexcept {
		return emscripten::val::global("ts")["updateCommaList"](node, elements).template as<_js_jts_dCommaListExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateComputedPropertyName(_js_jts_dComputedPropertyName node, _js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["updateComputedPropertyName"](node, expression).template as<_js_jts_dComputedPropertyName>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateConditional(_js_jts_dConditionalExpression node, _js_jts_dExpression condition, js_unknown /*flags=524288: Token<SyntaxKind.QuestionToken> (TypeReference=ts.Token)*/ questionToken, _js_jts_dExpression whenTrue, js_unknown /*flags=524288: Token<SyntaxKind.ColonToken> (TypeReference=ts.Token)*/ colonToken, _js_jts_dExpression whenFalse) noexcept {
		return emscripten::val::global("ts")["updateConditional"](node, condition, questionToken, whenTrue, colonToken, whenFalse).template as<_js_jts_dConditionalExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateConditionalTypeNode(_js_jts_dConditionalTypeNode node, _js_jts_dTypeNode checkType, _js_jts_dTypeNode extendsType, _js_jts_dTypeNode trueType, _js_jts_dTypeNode falseType) noexcept {
		return emscripten::val::global("ts")["updateConditionalTypeNode"](node, checkType, extendsType, trueType, falseType).template as<_js_jts_dConditionalTypeNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateConstructSignature(_js_jts_dConstructSignatureDeclaration node, js_unknown /*flags=1048576: NodeArray<TypeParameterDeclaration> | undefined ()*/ typeParameters, js_unknown /*flags=524288: NodeArray<ParameterDeclaration> (TypeReference=ts.NodeArray)*/ parameters, js_union<_js_jts_dTypeNode, js_undefined> type) noexcept {
		return emscripten::val::global("ts")["updateConstructSignature"](node, typeParameters, parameters, type).template as<_js_jts_dConstructSignatureDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateConstructor(_js_jts_dConstructorDeclaration node, js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, js_union<_js_jts_dBlock, js_undefined> body) noexcept {
		return emscripten::val::global("ts")["updateConstructor"](node, decorators, modifiers, parameters, body).template as<_js_jts_dConstructorDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateConstructorTypeNode(_js_jts_dConstructorTypeNode node, js_unknown /*flags=1048576: NodeArray<TypeParameterDeclaration> | undefined ()*/ typeParameters, js_unknown /*flags=524288: NodeArray<ParameterDeclaration> (TypeReference=ts.NodeArray)*/ parameters, js_union<_js_jts_dTypeNode, js_undefined> type) noexcept {
		return emscripten::val::global("ts")["updateConstructorTypeNode"](node, typeParameters, parameters, type).template as<_js_jts_dConstructorTypeNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateContinue(_js_jts_dContinueStatement node, js_union<_js_jts_dIdentifier, js_undefined> label) noexcept {
		return emscripten::val::global("ts")["updateContinue"](node, label).template as<_js_jts_dContinueStatement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateDecorator(_js_jts_dDecorator node, _js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["updateDecorator"](node, expression).template as<_js_jts_dDecorator>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateDefaultClause(_js_jts_dDefaultClause node, js::ReadonlyArray<_js_jts_dStatement> statements) noexcept {
		return emscripten::val::global("ts")["updateDefaultClause"](node, statements).template as<_js_jts_dDefaultClause>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateDelete(_js_jts_dDeleteExpression node, _js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["updateDelete"](node, expression).template as<_js_jts_dDeleteExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateDo(_js_jts_dDoStatement node, _js_jts_dStatement statement, _js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["updateDo"](node, statement, expression).template as<_js_jts_dDoStatement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateElementAccess(_js_jts_dElementAccessExpression node, _js_jts_dExpression expression, _js_jts_dExpression argumentExpression) noexcept {
		return emscripten::val::global("ts")["updateElementAccess"](node, expression, argumentExpression).template as<_js_jts_dElementAccessExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateEnumDeclaration(_js_jts_dEnumDeclaration node, js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, _js_jts_dIdentifier name, js::ReadonlyArray<_js_jts_dEnumMember> members) noexcept {
		return emscripten::val::global("ts")["updateEnumDeclaration"](node, decorators, modifiers, name, members).template as<_js_jts_dEnumDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateEnumMember(_js_jts_dEnumMember node, js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral> name, js_union<_js_jts_dExpression, js_undefined> initializer) noexcept {
		return emscripten::val::global("ts")["updateEnumMember"](node, name, initializer).template as<_js_jts_dEnumMember>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateExportAssignment(_js_jts_dExportAssignment node, js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, _js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["updateExportAssignment"](node, decorators, modifiers, expression).template as<_js_jts_dExportAssignment>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateExportDeclaration(_js_jts_dExportDeclaration node, js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dNamedExports, js_undefined> exportClause, js_union<_js_jts_dExpression, js_undefined> moduleSpecifier) noexcept {
		return emscripten::val::global("ts")["updateExportDeclaration"](node, decorators, modifiers, exportClause, moduleSpecifier).template as<_js_jts_dExportDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateExportSpecifier(_js_jts_dExportSpecifier node, js_union<_js_jts_dIdentifier, js_undefined> propertyName, _js_jts_dIdentifier name) noexcept {
		return emscripten::val::global("ts")["updateExportSpecifier"](node, propertyName, name).template as<_js_jts_dExportSpecifier>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateExpressionStatement(_js_jts_dExpressionStatement node, _js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["updateExpressionStatement"](node, expression).template as<_js_jts_dExpressionStatement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateExpressionWithTypeArguments(_js_jts_dExpressionWithTypeArguments node, js_union<js::ReadonlyArray<_js_jts_dTypeNode>, js_undefined> typeArguments, _js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["updateExpressionWithTypeArguments"](node, typeArguments, expression).template as<_js_jts_dExpressionWithTypeArguments>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateExternalModuleReference(_js_jts_dExternalModuleReference node, _js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["updateExternalModuleReference"](node, expression).template as<_js_jts_dExternalModuleReference>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateFor(_js_jts_dForStatement node, js_union<_js_jts_dExpression, _js_jts_dVariableDeclarationList, js_undefined> initializer, js_union<_js_jts_dExpression, js_undefined> condition, js_union<_js_jts_dExpression, js_undefined> incrementor, _js_jts_dStatement statement) noexcept {
		return emscripten::val::global("ts")["updateFor"](node, initializer, condition, incrementor, statement).template as<_js_jts_dForStatement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateForIn(_js_jts_dForInStatement node, js_union<_js_jts_dExpression, _js_jts_dVariableDeclarationList> initializer, _js_jts_dExpression expression, _js_jts_dStatement statement) noexcept {
		return emscripten::val::global("ts")["updateForIn"](node, initializer, expression, statement).template as<_js_jts_dForInStatement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateForOf(_js_jts_dForOfStatement node, js_unknown /*flags=1048576: Token<SyntaxKind.AwaitKeyword> | undefined ()*/ awaitModifier, js_union<_js_jts_dExpression, _js_jts_dVariableDeclarationList> initializer, _js_jts_dExpression expression, _js_jts_dStatement statement) noexcept {
		return emscripten::val::global("ts")["updateForOf"](node, awaitModifier, initializer, expression, statement).template as<_js_jts_dForOfStatement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateFunctionDeclaration(_js_jts_dFunctionDeclaration node, js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_unknown /*flags=1048576: Token<SyntaxKind.AsteriskToken> | undefined ()*/ asteriskToken, js_union<_js_jts_dIdentifier, js_undefined> name, js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, js_union<_js_jts_dTypeNode, js_undefined> type, js_union<_js_jts_dBlock, js_undefined> body) noexcept {
		return emscripten::val::global("ts")["updateFunctionDeclaration"](node, decorators, modifiers, asteriskToken, name, typeParameters, parameters, type, body).template as<_js_jts_dFunctionDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateFunctionExpression(_js_jts_dFunctionExpression node, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_unknown /*flags=1048576: Token<SyntaxKind.AsteriskToken> | undefined ()*/ asteriskToken, js_union<_js_jts_dIdentifier, js_undefined> name, js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, js_union<_js_jts_dTypeNode, js_undefined> type, _js_jts_dBlock body) noexcept {
		return emscripten::val::global("ts")["updateFunctionExpression"](node, modifiers, asteriskToken, name, typeParameters, parameters, type, body).template as<_js_jts_dFunctionExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateFunctionTypeNode(_js_jts_dFunctionTypeNode node, js_unknown /*flags=1048576: NodeArray<TypeParameterDeclaration> | undefined ()*/ typeParameters, js_unknown /*flags=524288: NodeArray<ParameterDeclaration> (TypeReference=ts.NodeArray)*/ parameters, js_union<_js_jts_dTypeNode, js_undefined> type) noexcept {
		return emscripten::val::global("ts")["updateFunctionTypeNode"](node, typeParameters, parameters, type).template as<_js_jts_dFunctionTypeNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateGetAccessor(_js_jts_dGetAccessorDeclaration node, js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral> name, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, js_union<_js_jts_dTypeNode, js_undefined> type, js_union<_js_jts_dBlock, js_undefined> body) noexcept {
		return emscripten::val::global("ts")["updateGetAccessor"](node, decorators, modifiers, name, parameters, type, body).template as<_js_jts_dGetAccessorDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateHeritageClause(_js_jts_dHeritageClause node, js::ReadonlyArray<_js_jts_dExpressionWithTypeArguments> types) noexcept {
		return emscripten::val::global("ts")["updateHeritageClause"](node, types).template as<_js_jts_dHeritageClause>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateIdentifier(_js_jts_dIdentifier node) noexcept {
		return emscripten::val::global("ts")["updateIdentifier"](node).template as<_js_jts_dIdentifier>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateIf(_js_jts_dIfStatement node, _js_jts_dExpression expression, _js_jts_dStatement thenStatement, js_union<_js_jts_dStatement, js_undefined> elseStatement) noexcept {
		return emscripten::val::global("ts")["updateIf"](node, expression, thenStatement, elseStatement).template as<_js_jts_dIfStatement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateImportClause(_js_jts_dImportClause node, js_union<_js_jts_dIdentifier, js_undefined> name, js_union<_js_jts_dNamedImports, _js_jts_dNamespaceImport, js_undefined> namedBindings) noexcept {
		return emscripten::val::global("ts")["updateImportClause"](node, name, namedBindings).template as<_js_jts_dImportClause>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateImportDeclaration(_js_jts_dImportDeclaration node, js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dImportClause, js_undefined> importClause, _js_jts_dExpression moduleSpecifier) noexcept {
		return emscripten::val::global("ts")["updateImportDeclaration"](node, decorators, modifiers, importClause, moduleSpecifier).template as<_js_jts_dImportDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateImportEqualsDeclaration(_js_jts_dImportEqualsDeclaration node, js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, _js_jts_dIdentifier name, js_union<_js_jts_dExternalModuleReference, _js_jts_dIdentifier, _js_jts_dQualifiedName> moduleReference) noexcept {
		return emscripten::val::global("ts")["updateImportEqualsDeclaration"](node, decorators, modifiers, name, moduleReference).template as<_js_jts_dImportEqualsDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateImportSpecifier(_js_jts_dImportSpecifier node, js_union<_js_jts_dIdentifier, js_undefined> propertyName, _js_jts_dIdentifier name) noexcept {
		return emscripten::val::global("ts")["updateImportSpecifier"](node, propertyName, name).template as<_js_jts_dImportSpecifier>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateImportTypeNode(_js_jts_dImportTypeNode node, _js_jts_dTypeNode argument, js_union<_js_jts_dIdentifier, _js_jts_dQualifiedName, js_undefined> qualifier, js_union<js::ReadonlyArray<_js_jts_dTypeNode>, js_undefined> typeArguments, js_union<bool /*false*/, js_undefined> isTypeOf) noexcept {
		return emscripten::val::global("ts")["updateImportTypeNode"](node, argument, qualifier, typeArguments, isTypeOf).template as<_js_jts_dImportTypeNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateIndexSignature(_js_jts_dIndexSignatureDeclaration node, js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, _js_jts_dTypeNode type) noexcept {
		return emscripten::val::global("ts")["updateIndexSignature"](node, decorators, modifiers, parameters, type).template as<_js_jts_dIndexSignatureDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateIndexedAccessTypeNode(_js_jts_dIndexedAccessTypeNode node, _js_jts_dTypeNode objectType, _js_jts_dTypeNode indexType) noexcept {
		return emscripten::val::global("ts")["updateIndexedAccessTypeNode"](node, objectType, indexType).template as<_js_jts_dIndexedAccessTypeNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateInferTypeNode(_js_jts_dInferTypeNode node, _js_jts_dTypeParameterDeclaration typeParameter) noexcept {
		return emscripten::val::global("ts")["updateInferTypeNode"](node, typeParameter).template as<_js_jts_dInferTypeNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateInterfaceDeclaration(_js_jts_dInterfaceDeclaration node, js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, _js_jts_dIdentifier name, js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, js_union<js::ReadonlyArray<_js_jts_dHeritageClause>, js_undefined> heritageClauses, js::ReadonlyArray<_js_jts_dTypeElement> members) noexcept {
		return emscripten::val::global("ts")["updateInterfaceDeclaration"](node, decorators, modifiers, name, typeParameters, heritageClauses, members).template as<_js_jts_dInterfaceDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateIntersectionTypeNode(_js_jts_dIntersectionTypeNode node, js_unknown /*flags=524288: NodeArray<TypeNode> (TypeReference=ts.NodeArray)*/ types) noexcept {
		return emscripten::val::global("ts")["updateIntersectionTypeNode"](node, types).template as<_js_jts_dIntersectionTypeNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateJsxAttribute(_js_jts_dJsxAttribute node, _js_jts_dIdentifier name, js_union<_js_jts_dJsxExpression, _js_jts_dStringLiteral> initializer) noexcept {
		return emscripten::val::global("ts")["updateJsxAttribute"](node, name, initializer).template as<_js_jts_dJsxAttribute>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateJsxAttributes(_js_jts_dJsxAttributes node, js::ReadonlyArray<js_union<_js_jts_dJsxAttribute, _js_jts_dJsxSpreadAttribute>> properties) noexcept {
		return emscripten::val::global("ts")["updateJsxAttributes"](node, properties).template as<_js_jts_dJsxAttributes>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateJsxClosingElement(_js_jts_dJsxClosingElement node, js_union<_js_jts_dIdentifier, _js_jts_dJsxTagNamePropertyAccess, _js_jts_dThisExpression> tagName) noexcept {
		return emscripten::val::global("ts")["updateJsxClosingElement"](node, tagName).template as<_js_jts_dJsxClosingElement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateJsxElement(_js_jts_dJsxElement node, _js_jts_dJsxOpeningElement openingElement, js::ReadonlyArray<js_union<_js_jts_dJsxElement, _js_jts_dJsxExpression, _js_jts_dJsxFragment, _js_jts_dJsxSelfClosingElement, _js_jts_dJsxText>> children, _js_jts_dJsxClosingElement closingElement) noexcept {
		return emscripten::val::global("ts")["updateJsxElement"](node, openingElement, children, closingElement).template as<_js_jts_dJsxElement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateJsxExpression(_js_jts_dJsxExpression node, js_union<_js_jts_dExpression, js_undefined> expression) noexcept {
		return emscripten::val::global("ts")["updateJsxExpression"](node, expression).template as<_js_jts_dJsxExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateJsxFragment(_js_jts_dJsxFragment node, _js_jts_dJsxOpeningFragment openingFragment, js::ReadonlyArray<js_union<_js_jts_dJsxElement, _js_jts_dJsxExpression, _js_jts_dJsxFragment, _js_jts_dJsxSelfClosingElement, _js_jts_dJsxText>> children, _js_jts_dJsxClosingFragment closingFragment) noexcept {
		return emscripten::val::global("ts")["updateJsxFragment"](node, openingFragment, children, closingFragment).template as<_js_jts_dJsxFragment>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateJsxOpeningElement(_js_jts_dJsxOpeningElement node, js_union<_js_jts_dIdentifier, _js_jts_dJsxTagNamePropertyAccess, _js_jts_dThisExpression> tagName, js_union<js::ReadonlyArray<_js_jts_dTypeNode>, js_undefined> typeArguments, _js_jts_dJsxAttributes attributes) noexcept {
		return emscripten::val::global("ts")["updateJsxOpeningElement"](node, tagName, typeArguments, attributes).template as<_js_jts_dJsxOpeningElement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateJsxSelfClosingElement(_js_jts_dJsxSelfClosingElement node, js_union<_js_jts_dIdentifier, _js_jts_dJsxTagNamePropertyAccess, _js_jts_dThisExpression> tagName, js_union<js::ReadonlyArray<_js_jts_dTypeNode>, js_undefined> typeArguments, _js_jts_dJsxAttributes attributes) noexcept {
		return emscripten::val::global("ts")["updateJsxSelfClosingElement"](node, tagName, typeArguments, attributes).template as<_js_jts_dJsxSelfClosingElement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateJsxSpreadAttribute(_js_jts_dJsxSpreadAttribute node, _js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["updateJsxSpreadAttribute"](node, expression).template as<_js_jts_dJsxSpreadAttribute>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateJsxText(_js_jts_dJsxText node, js_string text, js_union<bool /*false*/, js_undefined> containsOnlyTriviaWhiteSpaces) noexcept {
		return emscripten::val::global("ts")["updateJsxText"](node, text, containsOnlyTriviaWhiteSpaces).template as<_js_jts_dJsxText>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateLabel(_js_jts_dLabeledStatement node, _js_jts_dIdentifier label, _js_jts_dStatement statement) noexcept {
		return emscripten::val::global("ts")["updateLabel"](node, label, statement).template as<_js_jts_dLabeledStatement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateLanguageServiceSourceFile(_js_jts_dSourceFile sourceFile, _js_jts_dIScriptSnapshot scriptSnapshot, js_string version, js_union<_js_jts_dTextChangeRange, js_undefined> textChangeRange, js_union<bool /*false*/, js_undefined> aggressiveChecks) noexcept {
		return emscripten::val::global("ts")["updateLanguageServiceSourceFile"](sourceFile, scriptSnapshot, version, textChangeRange, aggressiveChecks).template as<_js_jts_dSourceFile>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateLiteralTypeNode(_js_jts_dLiteralTypeNode node, js_union<_js_jts_dBooleanLiteral, _js_jts_dLiteralExpression, _js_jts_dPrefixUnaryExpression> literal) noexcept {
		return emscripten::val::global("ts")["updateLiteralTypeNode"](node, literal).template as<_js_jts_dLiteralTypeNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateMappedTypeNode(_js_jts_dMappedTypeNode node, js_unknown /*flags=1048576: Token<SyntaxKind.ReadonlyKeyword> | Token<SyntaxKind.PlusToken> | Token<SyntaxKind.MinusToken> | undefined ()*/ readonlyToken, _js_jts_dTypeParameterDeclaration typeParameter, js_unknown /*flags=1048576: Token<SyntaxKind.QuestionToken> | Token<SyntaxKind.PlusToken> | Token<SyntaxKind.MinusToken> | undefined ()*/ questionToken, js_union<_js_jts_dTypeNode, js_undefined> type) noexcept {
		return emscripten::val::global("ts")["updateMappedTypeNode"](node, readonlyToken, typeParameter, questionToken, type).template as<_js_jts_dMappedTypeNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateMetaProperty(_js_jts_dMetaProperty node, _js_jts_dIdentifier name) noexcept {
		return emscripten::val::global("ts")["updateMetaProperty"](node, name).template as<_js_jts_dMetaProperty>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateMethod(_js_jts_dMethodDeclaration node, js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_unknown /*flags=1048576: Token<SyntaxKind.AsteriskToken> | undefined ()*/ asteriskToken, js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral> name, js_unknown /*flags=1048576: Token<SyntaxKind.QuestionToken> | undefined ()*/ questionToken, js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, js_union<_js_jts_dTypeNode, js_undefined> type, js_union<_js_jts_dBlock, js_undefined> body) noexcept {
		return emscripten::val::global("ts")["updateMethod"](node, decorators, modifiers, asteriskToken, name, questionToken, typeParameters, parameters, type, body).template as<_js_jts_dMethodDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateMethodSignature(_js_jts_dMethodSignature node, js_unknown /*flags=1048576: NodeArray<TypeParameterDeclaration> | undefined ()*/ typeParameters, js_unknown /*flags=524288: NodeArray<ParameterDeclaration> (TypeReference=ts.NodeArray)*/ parameters, js_union<_js_jts_dTypeNode, js_undefined> type, js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral> name, js_unknown /*flags=1048576: Token<SyntaxKind.QuestionToken> | undefined ()*/ questionToken) noexcept {
		return emscripten::val::global("ts")["updateMethodSignature"](node, typeParameters, parameters, type, name, questionToken).template as<_js_jts_dMethodSignature>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateModuleBlock(_js_jts_dModuleBlock node, js::ReadonlyArray<_js_jts_dStatement> statements) noexcept {
		return emscripten::val::global("ts")["updateModuleBlock"](node, statements).template as<_js_jts_dModuleBlock>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateModuleDeclaration(_js_jts_dModuleDeclaration node, js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dIdentifier, _js_jts_dStringLiteral> name, js_union<_js_jts_dIdentifier, _js_jts_dJSDocNamespaceDeclaration, _js_jts_dModuleBlock, _js_jts_dNamespaceDeclaration, js_undefined> body) noexcept {
		return emscripten::val::global("ts")["updateModuleDeclaration"](node, decorators, modifiers, name, body).template as<_js_jts_dModuleDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateNamedExports(_js_jts_dNamedExports node, js::ReadonlyArray<_js_jts_dExportSpecifier> elements) noexcept {
		return emscripten::val::global("ts")["updateNamedExports"](node, elements).template as<_js_jts_dNamedExports>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateNamedImports(_js_jts_dNamedImports node, js::ReadonlyArray<_js_jts_dImportSpecifier> elements) noexcept {
		return emscripten::val::global("ts")["updateNamedImports"](node, elements).template as<_js_jts_dNamedImports>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateNamespaceExportDeclaration(_js_jts_dNamespaceExportDeclaration node, _js_jts_dIdentifier name) noexcept {
		return emscripten::val::global("ts")["updateNamespaceExportDeclaration"](node, name).template as<_js_jts_dNamespaceExportDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateNamespaceImport(_js_jts_dNamespaceImport node, _js_jts_dIdentifier name) noexcept {
		return emscripten::val::global("ts")["updateNamespaceImport"](node, name).template as<_js_jts_dNamespaceImport>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateNew(_js_jts_dNewExpression node, _js_jts_dExpression expression, js_union<js::ReadonlyArray<_js_jts_dTypeNode>, js_undefined> typeArguments, js_union<js::ReadonlyArray<_js_jts_dExpression>, js_undefined> argumentsArray) noexcept {
		return emscripten::val::global("ts")["updateNew"](node, expression, typeArguments, argumentsArray).template as<_js_jts_dNewExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateNonNullExpression(_js_jts_dNonNullExpression node, _js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["updateNonNullExpression"](node, expression).template as<_js_jts_dNonNullExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateObjectBindingPattern(_js_jts_dObjectBindingPattern node, js::ReadonlyArray<_js_jts_dBindingElement> elements) noexcept {
		return emscripten::val::global("ts")["updateObjectBindingPattern"](node, elements).template as<_js_jts_dObjectBindingPattern>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateObjectLiteral(_js_jts_dObjectLiteralExpression node, js::ReadonlyArray<js_union<_js_jts_dGetAccessorDeclaration, _js_jts_dMethodDeclaration, _js_jts_dPropertyAssignment, _js_jts_dSetAccessorDeclaration, _js_jts_dShorthandPropertyAssignment, _js_jts_dSpreadAssignment>> properties) noexcept {
		return emscripten::val::global("ts")["updateObjectLiteral"](node, properties).template as<_js_jts_dObjectLiteralExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateOptionalTypeNode(_js_jts_dOptionalTypeNode node, _js_jts_dTypeNode type) noexcept {
		return emscripten::val::global("ts")["updateOptionalTypeNode"](node, type).template as<_js_jts_dOptionalTypeNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateParameter(_js_jts_dParameterDeclaration node, js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_unknown /*flags=1048576: Token<SyntaxKind.DotDotDotToken> | undefined ()*/ dotDotDotToken, js_union<_js_jts_dArrayBindingPattern, _js_jts_dIdentifier, _js_jts_dObjectBindingPattern, js_string> name, js_unknown /*flags=1048576: Token<SyntaxKind.QuestionToken> | undefined ()*/ questionToken, js_union<_js_jts_dTypeNode, js_undefined> type, js_union<_js_jts_dExpression, js_undefined> initializer) noexcept {
		return emscripten::val::global("ts")["updateParameter"](node, decorators, modifiers, dotDotDotToken, name, questionToken, type, initializer).template as<_js_jts_dParameterDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateParen(_js_jts_dParenthesizedExpression node, _js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["updateParen"](node, expression).template as<_js_jts_dParenthesizedExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateParenthesizedType(_js_jts_dParenthesizedTypeNode node, _js_jts_dTypeNode type) noexcept {
		return emscripten::val::global("ts")["updateParenthesizedType"](node, type).template as<_js_jts_dParenthesizedTypeNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updatePartiallyEmittedExpression(_js_jts_dPartiallyEmittedExpression node, _js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["updatePartiallyEmittedExpression"](node, expression).template as<_js_jts_dPartiallyEmittedExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updatePostfix(_js_jts_dPostfixUnaryExpression node, _js_jts_dExpression operand) noexcept {
		return emscripten::val::global("ts")["updatePostfix"](node, operand).template as<_js_jts_dPostfixUnaryExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updatePrefix(_js_jts_dPrefixUnaryExpression node, _js_jts_dExpression operand) noexcept {
		return emscripten::val::global("ts")["updatePrefix"](node, operand).template as<_js_jts_dPrefixUnaryExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateProperty(_js_jts_dPropertyDeclaration node, js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral, js_string> name, js_unknown /*flags=1048576: Token<SyntaxKind.QuestionToken> | Token<SyntaxKind.ExclamationToken> | undefined ()*/ questionOrExclamationToken, js_union<_js_jts_dTypeNode, js_undefined> type, js_union<_js_jts_dExpression, js_undefined> initializer) noexcept {
		return emscripten::val::global("ts")["updateProperty"](node, decorators, modifiers, name, questionOrExclamationToken, type, initializer).template as<_js_jts_dPropertyDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updatePropertyAccess(_js_jts_dPropertyAccessExpression node, _js_jts_dExpression expression, _js_jts_dIdentifier name) noexcept {
		return emscripten::val::global("ts")["updatePropertyAccess"](node, expression, name).template as<_js_jts_dPropertyAccessExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updatePropertyAssignment(_js_jts_dPropertyAssignment node, js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral> name, _js_jts_dExpression initializer) noexcept {
		return emscripten::val::global("ts")["updatePropertyAssignment"](node, name, initializer).template as<_js_jts_dPropertyAssignment>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updatePropertySignature(_js_jts_dPropertySignature node, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral> name, js_unknown /*flags=1048576: Token<SyntaxKind.QuestionToken> | undefined ()*/ questionToken, js_union<_js_jts_dTypeNode, js_undefined> type, js_union<_js_jts_dExpression, js_undefined> initializer) noexcept {
		return emscripten::val::global("ts")["updatePropertySignature"](node, modifiers, name, questionToken, type, initializer).template as<_js_jts_dPropertySignature>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateQualifiedName(_js_jts_dQualifiedName node, js_union<_js_jts_dIdentifier, _js_jts_dQualifiedName> left, _js_jts_dIdentifier right) noexcept {
		return emscripten::val::global("ts")["updateQualifiedName"](node, left, right).template as<_js_jts_dQualifiedName>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateRestTypeNode(_js_jts_dRestTypeNode node, _js_jts_dTypeNode type) noexcept {
		return emscripten::val::global("ts")["updateRestTypeNode"](node, type).template as<_js_jts_dRestTypeNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateReturn(_js_jts_dReturnStatement node, js_union<_js_jts_dExpression, js_undefined> expression) noexcept {
		return emscripten::val::global("ts")["updateReturn"](node, expression).template as<_js_jts_dReturnStatement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateSetAccessor(_js_jts_dSetAccessorDeclaration node, js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral> name, js::ReadonlyArray<_js_jts_dParameterDeclaration> parameters, js_union<_js_jts_dBlock, js_undefined> body) noexcept {
		return emscripten::val::global("ts")["updateSetAccessor"](node, decorators, modifiers, name, parameters, body).template as<_js_jts_dSetAccessorDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateShorthandPropertyAssignment(_js_jts_dShorthandPropertyAssignment node, _js_jts_dIdentifier name, js_union<_js_jts_dExpression, js_undefined> objectAssignmentInitializer) noexcept {
		return emscripten::val::global("ts")["updateShorthandPropertyAssignment"](node, name, objectAssignmentInitializer).template as<_js_jts_dShorthandPropertyAssignment>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateSourceFile(_js_jts_dSourceFile sourceFile, js_string newText, _js_jts_dTextChangeRange textChangeRange, js_union<bool /*false*/, js_undefined> aggressiveChecks) noexcept {
		return emscripten::val::global("ts")["updateSourceFile"](sourceFile, newText, textChangeRange, aggressiveChecks).template as<_js_jts_dSourceFile>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateSourceFileNode(_js_jts_dSourceFile node, js::ReadonlyArray<_js_jts_dStatement> statements, js_union<bool /*false*/, js_undefined> isDeclarationFile, js_union<js::ReadonlyArray<_js_jts_dFileReference>, js_undefined> referencedFiles, js_union<js::ReadonlyArray<_js_jts_dFileReference>, js_undefined> typeReferences, js_union<bool /*false*/, js_undefined> hasNoDefaultLib, js_union<js::ReadonlyArray<_js_jts_dFileReference>, js_undefined> libReferences) noexcept {
		return emscripten::val::global("ts")["updateSourceFileNode"](node, statements, isDeclarationFile, referencedFiles, typeReferences, hasNoDefaultLib, libReferences).template as<_js_jts_dSourceFile>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateSpread(_js_jts_dSpreadElement node, _js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["updateSpread"](node, expression).template as<_js_jts_dSpreadElement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateSpreadAssignment(_js_jts_dSpreadAssignment node, _js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["updateSpreadAssignment"](node, expression).template as<_js_jts_dSpreadAssignment>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateSwitch(_js_jts_dSwitchStatement node, _js_jts_dExpression expression, _js_jts_dCaseBlock caseBlock) noexcept {
		return emscripten::val::global("ts")["updateSwitch"](node, expression, caseBlock).template as<_js_jts_dSwitchStatement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateTaggedTemplate(_js_jts_dTaggedTemplateExpression node, _js_jts_dExpression tag, js_union<_js_jts_dNoSubstitutionTemplateLiteral, _js_jts_dTemplateExpression> template_) noexcept {
		return emscripten::val::global("ts")["updateTaggedTemplate"](node, tag, template_).template as<_js_jts_dTaggedTemplateExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateTaggedTemplate(_js_jts_dTaggedTemplateExpression node, _js_jts_dExpression tag, js_union<js::ReadonlyArray<_js_jts_dTypeNode>, js_undefined> typeArguments, js_union<_js_jts_dNoSubstitutionTemplateLiteral, _js_jts_dTemplateExpression> template_) noexcept {
		return emscripten::val::global("ts")["updateTaggedTemplate"](node, tag, typeArguments, template_).template as<_js_jts_dTaggedTemplateExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateTemplateExpression(_js_jts_dTemplateExpression node, _js_jts_dTemplateHead head, js::ReadonlyArray<_js_jts_dTemplateSpan> templateSpans) noexcept {
		return emscripten::val::global("ts")["updateTemplateExpression"](node, head, templateSpans).template as<_js_jts_dTemplateExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateTemplateSpan(_js_jts_dTemplateSpan node, _js_jts_dExpression expression, js_union<_js_jts_dTemplateMiddle, _js_jts_dTemplateTail> literal) noexcept {
		return emscripten::val::global("ts")["updateTemplateSpan"](node, expression, literal).template as<_js_jts_dTemplateSpan>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateThrow(_js_jts_dThrowStatement node, _js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["updateThrow"](node, expression).template as<_js_jts_dThrowStatement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateTry(_js_jts_dTryStatement node, _js_jts_dBlock tryBlock, js_union<_js_jts_dCatchClause, js_undefined> catchClause, js_union<_js_jts_dBlock, js_undefined> finallyBlock) noexcept {
		return emscripten::val::global("ts")["updateTry"](node, tryBlock, catchClause, finallyBlock).template as<_js_jts_dTryStatement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateTupleTypeNode(_js_jts_dTupleTypeNode node, js::ReadonlyArray<_js_jts_dTypeNode> elementTypes) noexcept {
		return emscripten::val::global("ts")["updateTupleTypeNode"](node, elementTypes).template as<_js_jts_dTupleTypeNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateTypeAliasDeclaration(_js_jts_dTypeAliasDeclaration node, js_union<js::ReadonlyArray<_js_jts_dDecorator>, js_undefined> decorators, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, _js_jts_dIdentifier name, js_union<js::ReadonlyArray<_js_jts_dTypeParameterDeclaration>, js_undefined> typeParameters, _js_jts_dTypeNode type) noexcept {
		return emscripten::val::global("ts")["updateTypeAliasDeclaration"](node, decorators, modifiers, name, typeParameters, type).template as<_js_jts_dTypeAliasDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateTypeAssertion(_js_jts_dTypeAssertion node, _js_jts_dTypeNode type, _js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["updateTypeAssertion"](node, type, expression).template as<_js_jts_dTypeAssertion>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateTypeLiteralNode(_js_jts_dTypeLiteralNode node, js_unknown /*flags=524288: NodeArray<TypeElement> (TypeReference=ts.NodeArray)*/ members) noexcept {
		return emscripten::val::global("ts")["updateTypeLiteralNode"](node, members).template as<_js_jts_dTypeLiteralNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateTypeOf(_js_jts_dTypeOfExpression node, _js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["updateTypeOf"](node, expression).template as<_js_jts_dTypeOfExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateTypeOperatorNode(_js_jts_dTypeOperatorNode node, _js_jts_dTypeNode type) noexcept {
		return emscripten::val::global("ts")["updateTypeOperatorNode"](node, type).template as<_js_jts_dTypeOperatorNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateTypeParameterDeclaration(_js_jts_dTypeParameterDeclaration node, _js_jts_dIdentifier name, js_union<_js_jts_dTypeNode, js_undefined> constraint, js_union<_js_jts_dTypeNode, js_undefined> defaultType) noexcept {
		return emscripten::val::global("ts")["updateTypeParameterDeclaration"](node, name, constraint, defaultType).template as<_js_jts_dTypeParameterDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateTypePredicateNode(_js_jts_dTypePredicateNode node, js_union<_js_jts_dIdentifier, _js_jts_dThisTypeNode> parameterName, _js_jts_dTypeNode type) noexcept {
		return emscripten::val::global("ts")["updateTypePredicateNode"](node, parameterName, type).template as<_js_jts_dTypePredicateNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateTypeQueryNode(_js_jts_dTypeQueryNode node, js_union<_js_jts_dIdentifier, _js_jts_dQualifiedName> exprName) noexcept {
		return emscripten::val::global("ts")["updateTypeQueryNode"](node, exprName).template as<_js_jts_dTypeQueryNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateTypeReferenceNode(_js_jts_dTypeReferenceNode node, js_union<_js_jts_dIdentifier, _js_jts_dQualifiedName> typeName, js_unknown /*flags=1048576: NodeArray<TypeNode> | undefined ()*/ typeArguments) noexcept {
		return emscripten::val::global("ts")["updateTypeReferenceNode"](node, typeName, typeArguments).template as<_js_jts_dTypeReferenceNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateUnionTypeNode(_js_jts_dUnionTypeNode node, js_unknown /*flags=524288: NodeArray<TypeNode> (TypeReference=ts.NodeArray)*/ types) noexcept {
		return emscripten::val::global("ts")["updateUnionTypeNode"](node, types).template as<_js_jts_dUnionTypeNode>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateVariableDeclaration(_js_jts_dVariableDeclaration node, js_union<_js_jts_dArrayBindingPattern, _js_jts_dIdentifier, _js_jts_dObjectBindingPattern> name, js_union<_js_jts_dTypeNode, js_undefined> type, js_union<_js_jts_dExpression, js_undefined> initializer) noexcept {
		return emscripten::val::global("ts")["updateVariableDeclaration"](node, name, type, initializer).template as<_js_jts_dVariableDeclaration>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateVariableDeclarationList(_js_jts_dVariableDeclarationList node, js::ReadonlyArray<_js_jts_dVariableDeclaration> declarations) noexcept {
		return emscripten::val::global("ts")["updateVariableDeclarationList"](node, declarations).template as<_js_jts_dVariableDeclarationList>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateVariableStatement(_js_jts_dVariableStatement node, js_union<js::ReadonlyArray<js_unknown /*flags=1048576: Modifier ()*/>, js_undefined> modifiers, _js_jts_dVariableDeclarationList declarationList) noexcept {
		return emscripten::val::global("ts")["updateVariableStatement"](node, modifiers, declarationList).template as<_js_jts_dVariableStatement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateVoid(_js_jts_dVoidExpression node, _js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["updateVoid"](node, expression).template as<_js_jts_dVoidExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateWhile(_js_jts_dWhileStatement node, _js_jts_dExpression expression, _js_jts_dStatement statement) noexcept {
		return emscripten::val::global("ts")["updateWhile"](node, expression, statement).template as<_js_jts_dWhileStatement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateWith(_js_jts_dWithStatement node, _js_jts_dExpression expression, _js_jts_dStatement statement) noexcept {
		return emscripten::val::global("ts")["updateWith"](node, expression, statement).template as<_js_jts_dWithStatement>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateYield(_js_jts_dYieldExpression node, js_unknown /*flags=1048576: Token<SyntaxKind.AsteriskToken> | undefined ()*/ asteriskToken, _js_jts_dExpression expression) noexcept {
		return emscripten::val::global("ts")["updateYield"](node, asteriskToken, expression).template as<_js_jts_dYieldExpression>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::validateLocaleAndSetLanguage(js_string locale, js_unknown /*flags=524288: { getExecutingFilePath(): string; resolvePath(path: string): string; fileExists(fileName: string): boolean; readFile(fileName: string): string | undefined; } (AnonymousTypeWithTypeLiteral(members:[getExecutingFilePath, resolvePath, fileExists, readFile]))*/ sys, js_unknown /*flags=1048576: Push<Diagnostic> | undefined ()*/ errors) noexcept {
		emscripten::val::global("ts")["validateLocaleAndSetLanguage"](locale, sys, errors);
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::visitEachChild(js_unknown /*flags=262144: T ()*/ node, js_function<js_union<_js_jts_dNode, js::Array<_js_jts_dNode>, js_undefined>(_js_jts_dNode)> visitor, _js_jts_dTransformationContext context) noexcept {
		return emscripten::val::global("ts")["visitEachChild"](node, visitor, context).template as<js_unknown /*flags=262144: T ()*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::visitEachChild(js_unknown /*flags=1048576: T | undefined ()*/ node, js_function<js_union<_js_jts_dNode, js::Array<_js_jts_dNode>, js_undefined>(_js_jts_dNode)> visitor, _js_jts_dTransformationContext context, js_unknown /*flags=1048576: { <T extends Node>(nodes: NodeArray<T> | undefined, visitor: Visitor, test?: ((node: Node) => boolean) | undefined, start?: number | undefined, count?: number | undefined): NodeArray<T>; <T extends Node>(nodes: NodeArray<...> | undefined, visitor: Visitor, test?: ((node: Node) => boolean) | undefined, start?: number... ()*/ nodesVisitor, js_union<js_function<js_union<_js_jts_dNode, js::Array<_js_jts_dNode>, js_undefined>(_js_jts_dNode)>, js_undefined> tokenVisitor) noexcept {
		return emscripten::val::global("ts")["visitEachChild"](node, visitor, context, nodesVisitor, tokenVisitor).template as<js_unknown /*flags=1048576: T | undefined ()*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::visitFunctionBody(_js_jts_dBlock node, js_function<js_union<_js_jts_dNode, js::Array<_js_jts_dNode>, js_undefined>(_js_jts_dNode)> visitor, _js_jts_dTransformationContext context) noexcept {
		return emscripten::val::global("ts")["visitFunctionBody"](node, visitor, context).template as<_js_jts_dBlock>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::visitFunctionBody(js_union<_js_jts_dBlock, _js_jts_dExpression> node, js_function<js_union<_js_jts_dNode, js::Array<_js_jts_dNode>, js_undefined>(_js_jts_dNode)> visitor, _js_jts_dTransformationContext context) noexcept {
		return emscripten::val::global("ts")["visitFunctionBody"](node, visitor, context).template as<js_union<_js_jts_dBlock, _js_jts_dExpression>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::visitFunctionBody(js_union<_js_jts_dBlock, js_undefined> node, js_function<js_union<_js_jts_dNode, js::Array<_js_jts_dNode>, js_undefined>(_js_jts_dNode)> visitor, _js_jts_dTransformationContext context) noexcept {
		return emscripten::val::global("ts")["visitFunctionBody"](node, visitor, context).template as<js_union<_js_jts_dBlock, js_undefined>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::visitLexicalEnvironment(js_unknown /*flags=524288: NodeArray<Statement> (TypeReference=ts.NodeArray)*/ statements, js_function<js_union<_js_jts_dNode, js::Array<_js_jts_dNode>, js_undefined>(_js_jts_dNode)> visitor, _js_jts_dTransformationContext context, js_union<double, js_undefined> start, js_union<bool /*false*/, js_undefined> ensureUseStrict) noexcept {
		return emscripten::val::global("ts")["visitLexicalEnvironment"](statements, visitor, context, start, ensureUseStrict).template as<js_unknown /*flags=524288: NodeArray<Statement> (TypeReference=ts.NodeArray)*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::visitNode(js_unknown /*flags=1048576: T | undefined ()*/ node, js_union<js_function<js_union<_js_jts_dNode, js::Array<_js_jts_dNode>, js_undefined>(_js_jts_dNode)>, js_undefined> visitor, js_union<js_function<bool /*false*/(_js_jts_dNode)>, js_undefined> test, js_union<js_function<js_unknown /*flags=262144: T ()*/(js_unknown /*flags=524288: NodeArray<Node> (TypeReference=ts.NodeArray)*/)>, js_undefined> lift) noexcept {
		return emscripten::val::global("ts")["visitNode"](node, visitor, test, lift).template as<js_unknown /*flags=1048576: T | undefined ()*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::visitNodes(js_unknown /*flags=1048576: NodeArray<T> | undefined ()*/ nodes, js_function<js_union<_js_jts_dNode, js::Array<_js_jts_dNode>, js_undefined>(_js_jts_dNode)> visitor, js_union<js_function<bool /*false*/(_js_jts_dNode)>, js_undefined> test, js_union<double, js_undefined> start, js_union<double, js_undefined> count) noexcept {
		return emscripten::val::global("ts")["visitNodes"](nodes, visitor, test, start, count).template as<js_unknown /*flags=524288: NodeArray<T> (TypeReference=ts.NodeArray)*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::visitParameterList(js_unknown /*flags=1048576: NodeArray<ParameterDeclaration> | undefined ()*/ nodes, js_function<js_union<_js_jts_dNode, js::Array<_js_jts_dNode>, js_undefined>(_js_jts_dNode)> visitor, _js_jts_dTransformationContext context, js_unknown /*flags=1048576: { <T extends Node>(nodes: NodeArray<T> | undefined, visitor: Visitor, test?: ((node: Node) => boolean) | undefined, start?: number | undefined, count?: number | undefined): NodeArray<T>; <T extends Node>(nodes: NodeArray<...> | undefined, visitor: Visitor, test?: ((node: Node) => boolean) | undefined, start?: number... ()*/ nodesVisitor) noexcept {
		return emscripten::val::global("ts")["visitParameterList"](nodes, visitor, context, nodesVisitor).template as<js_unknown /*flags=524288: NodeArray<ParameterDeclaration> (TypeReference=ts.NodeArray)*/>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::walkUpBindingElementsAndPatterns(_js_jts_dBindingElement binding) noexcept {
		return emscripten::val::global("ts")["walkUpBindingElementsAndPatterns"](binding).template as<js_union<_js_jts_dParameterDeclaration, _js_jts_dVariableDeclaration>>();
	}
	inline auto _impl_js_j_qts_q::_tcjs_definitions::createStatement() noexcept { return emscripten::val::global("ts")["createStatement"].template as<js_unknown /*flags=524288: (expression: Expression) => ExpressionStatement ()*/>(); }
	inline void _impl_js_j_qts_q::_tcjs_definitions::createStatement(js_unknown /*flags=524288: (expression: Expression) => ExpressionStatement ()*/ v) noexcept { emscripten::val::global("ts").set("createStatement", v); }
	inline auto _impl_js_j_qts_q::_tcjs_definitions::disableIncrementalParsing() noexcept { return emscripten::val::global("ts")["disableIncrementalParsing"].template as<bool /*false*/>(); }
	inline void _impl_js_j_qts_q::_tcjs_definitions::disableIncrementalParsing(bool /*false*/ v) noexcept { emscripten::val::global("ts").set("disableIncrementalParsing", v); }
	inline auto _impl_js_j_qts_q::_tcjs_definitions::servicesVersion() noexcept { return emscripten::val::global("ts")["servicesVersion"].template as<js_string /*"0.8"*/>(); }
	inline void _impl_js_j_qts_q::_tcjs_definitions::servicesVersion(js_string /*"0.8"*/ v) noexcept { emscripten::val::global("ts").set("servicesVersion", v); }
	inline auto _impl_js_j_qts_q::_tcjs_definitions::sys() noexcept { return emscripten::val::global("ts")["sys"].template as<_js_jts_dSystem>(); }
	inline void _impl_js_j_qts_q::_tcjs_definitions::sys(_js_jts_dSystem v) noexcept { emscripten::val::global("ts").set("sys", v); }
	inline auto _impl_js_j_qts_q::_tcjs_definitions::unchangedTextChangeRange() noexcept { return emscripten::val::global("ts")["unchangedTextChangeRange"].template as<_js_jts_dTextChangeRange>(); }
	inline void _impl_js_j_qts_q::_tcjs_definitions::unchangedTextChangeRange(_js_jts_dTextChangeRange v) noexcept { emscripten::val::global("ts").set("unchangedTextChangeRange", v); }
	inline auto _impl_js_j_qts_q::_tcjs_definitions::updateStatement() noexcept { return emscripten::val::global("ts")["updateStatement"].template as<js_unknown /*flags=524288: (node: ExpressionStatement, expression: Expression) => ExpressionStatement ()*/>(); }
	inline void _impl_js_j_qts_q::_tcjs_definitions::updateStatement(js_unknown /*flags=524288: (node: ExpressionStatement, expression: Expression) => ExpressionStatement ()*/ v) noexcept { emscripten::val::global("ts").set("updateStatement", v); }
	inline auto _impl_js_j_qts_q::_tcjs_definitions::version() noexcept { return emscripten::val::global("ts")["version"].template as<js_string>(); }
	inline void _impl_js_j_qts_q::_tcjs_definitions::version(js_string v) noexcept { emscripten::val::global("ts").set("version", v); }
	inline auto _impl_js_j_qts_q::_tcjs_definitions::versionMajorMinor() noexcept { return emscripten::val::global("ts")["versionMajorMinor"].template as<js_string /*"3.5"*/>(); }
	inline void _impl_js_j_qts_q::_tcjs_definitions::versionMajorMinor(js_string /*"3.5"*/ v) noexcept { emscripten::val::global("ts").set("versionMajorMinor", v); }
	inline auto _impl_js_jts_dSortedReadonlyArray::_u_uu_usortedArrayBrand() noexcept { return _getProperty<js_unknown>(" __sortedArrayBrand"); }
	inline void _impl_js_jts_dSortedReadonlyArray::_u_uu_usortedArrayBrand(js_unknown v) noexcept { _setProperty(" __sortedArrayBrand", v); }
	inline auto _impl_js_jts_dSortedArray::_u_uu_usortedArrayBrand() noexcept { return _getProperty<js_unknown>(" __sortedArrayBrand"); }
	inline void _impl_js_jts_dSortedArray::_u_uu_usortedArrayBrand(js_unknown v) noexcept { _setProperty(" __sortedArrayBrand", v); }
	inline auto _impl_js_jts_dReadonlyMap::size() noexcept { return _getProperty<double>("size"); }
	inline auto _impl_js_jts_dReadonlyMap::entries() noexcept {
		return _call<js_unknown /*flags=524288: Iterator<[string, T]> (TypeReference=ts.Iterator)*/>("entries");
	}
	inline auto _impl_js_jts_dReadonlyMap::forEach(js_function<void(js_unknown /*flags=262144: T ()*/, js_string)> action) noexcept {
		return _call<void>("forEach", action);
	}
	inline auto _impl_js_jts_dReadonlyMap::get(js_string key) noexcept {
		return _call<js_unknown /*flags=1048576: T | undefined ()*/>("get", key);
	}
	inline auto _impl_js_jts_dReadonlyMap::has(js_string key) noexcept {
		return _call<bool /*false*/>("has", key);
	}
	inline auto _impl_js_jts_dReadonlyMap::keys() noexcept {
		return _call<js_unknown /*flags=524288: Iterator<string> (TypeReference=ts.Iterator)*/>("keys");
	}
	inline auto _impl_js_jts_dReadonlyMap::values() noexcept {
		return _call<js_unknown /*flags=524288: Iterator<T> (TypeReference=ts.Iterator)*/>("values");
	}
	inline auto _impl_js_jts_dMap::clear() noexcept {
		return _call<void>("clear");
	}
	inline auto _impl_js_jts_dMap::delete_(js_string key) noexcept {
		return _call<bool /*false*/>("delete", key);
	}
	inline auto _impl_js_jts_dMap::set(js_string key, js_unknown /*flags=262144: T ()*/ value) noexcept {
		return _call<js_unknown /*flags=262144: this ()*/>("set", key, value);
	}
	inline auto _impl_js_jts_dIterator::next() noexcept {
		return _call<js_unknown /*flags=1048576: { value: T; done: false; } | { value: never; done: true; } ()*/>("next");
	}
	inline auto _impl_js_jts_dPush::push(js::Array<js_unknown /*flags=262144: T ()*/> values) noexcept {
		return _call<void>("push", values);
	}
	inline auto _impl_js_jts_dTextRange::pos() noexcept { return _getProperty<double>("pos"); }
	inline void _impl_js_jts_dTextRange::pos(double v) noexcept { _setProperty("pos", v); }
	inline auto _impl_js_jts_dTextRange::end() noexcept { return _getProperty<double>("end"); }
	inline void _impl_js_jts_dTextRange::end(double v) noexcept { _setProperty("end", v); }
	inline auto _impl_js_jts_dNode::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.Unknown*/>("kind"); }
	inline void _impl_js_jts_dNode::kind(_js_jts_dSyntaxKind /*SyntaxKind.Unknown*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dNode::flags() noexcept { return _getProperty<_js_jts_dNodeFlags /*NodeFlags.None*/>("flags"); }
	inline void _impl_js_jts_dNode::flags(_js_jts_dNodeFlags /*NodeFlags.None*/ v) noexcept { _setProperty("flags", v); }
	inline auto _impl_js_jts_dNode::parent() noexcept { return _getProperty<_js_jts_dNode>("parent"); }
	inline void _impl_js_jts_dNode::parent(_js_jts_dNode v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dNode::forEachChild(js_function<js_unknown /*flags=1048576: T | undefined ()*/(_js_jts_dNode)> cbNode, js_union<js_function<js_unknown /*flags=1048576: T | undefined ()*/(js_unknown /*flags=524288: NodeArray<Node> (TypeReference=ts.NodeArray)*/)>, js_undefined> cbNodeArray) noexcept {
		return _call<js_unknown /*flags=1048576: T | undefined ()*/>("forEachChild", cbNode, cbNodeArray);
	}
	inline auto _impl_js_jts_dNode::getChildAt(double index, js_union<_js_jts_dSourceFile, js_undefined> sourceFile) noexcept {
		return _call<_js_jts_dNode>("getChildAt", index, sourceFile);
	}
	inline auto _impl_js_jts_dNode::getChildCount(js_union<_js_jts_dSourceFile, js_undefined> sourceFile) noexcept {
		return _call<double>("getChildCount", sourceFile);
	}
	inline auto _impl_js_jts_dNode::getChildren(js_union<_js_jts_dSourceFile, js_undefined> sourceFile) noexcept {
		return _call<js::Array<_js_jts_dNode>>("getChildren", sourceFile);
	}
	inline auto _impl_js_jts_dNode::getEnd() noexcept {
		return _call<double>("getEnd");
	}
	inline auto _impl_js_jts_dNode::getFirstToken(js_union<_js_jts_dSourceFile, js_undefined> sourceFile) noexcept {
		return _call<js_union<_js_jts_dNode, js_undefined>>("getFirstToken", sourceFile);
	}
	inline auto _impl_js_jts_dNode::getFullStart() noexcept {
		return _call<double>("getFullStart");
	}
	inline auto _impl_js_jts_dNode::getFullText(js_union<_js_jts_dSourceFile, js_undefined> sourceFile) noexcept {
		return _call<js_string>("getFullText", sourceFile);
	}
	inline auto _impl_js_jts_dNode::getFullWidth() noexcept {
		return _call<double>("getFullWidth");
	}
	inline auto _impl_js_jts_dNode::getLastToken(js_union<_js_jts_dSourceFile, js_undefined> sourceFile) noexcept {
		return _call<js_union<_js_jts_dNode, js_undefined>>("getLastToken", sourceFile);
	}
	inline auto _impl_js_jts_dNode::getLeadingTriviaWidth(js_union<_js_jts_dSourceFile, js_undefined> sourceFile) noexcept {
		return _call<double>("getLeadingTriviaWidth", sourceFile);
	}
	inline auto _impl_js_jts_dNode::getSourceFile() noexcept {
		return _call<_js_jts_dSourceFile>("getSourceFile");
	}
	inline auto _impl_js_jts_dNode::getStart(js_union<_js_jts_dSourceFile, js_undefined> sourceFile, js_union<bool /*false*/, js_undefined> includeJsDocComment) noexcept {
		return _call<double>("getStart", sourceFile, includeJsDocComment);
	}
	inline auto _impl_js_jts_dNode::getText(js_union<_js_jts_dSourceFile, js_undefined> sourceFile) noexcept {
		return _call<js_string>("getText", sourceFile);
	}
	inline auto _impl_js_jts_dNode::getWidth(js_union<_js_jts_dSourceFileLike, js_undefined> sourceFile) noexcept {
		return _call<double>("getWidth", sourceFile);
	}
	inline auto _impl_js_jts_dToken::kind() noexcept { return _getProperty<js_unknown /*flags=262144: TKind ()*/>("kind"); }
	inline void _impl_js_jts_dToken::kind(js_unknown /*flags=262144: TKind ()*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dExpression::_expressionBrand() noexcept { return _getProperty<js_unknown>("_expressionBrand"); }
	inline void _impl_js_jts_dExpression::_expressionBrand(js_unknown v) noexcept { _setProperty("_expressionBrand", v); }
	inline auto _impl_js_jts_dUnaryExpression::_unaryExpressionBrand() noexcept { return _getProperty<js_unknown>("_unaryExpressionBrand"); }
	inline void _impl_js_jts_dUnaryExpression::_unaryExpressionBrand(js_unknown v) noexcept { _setProperty("_unaryExpressionBrand", v); }
	inline auto _impl_js_jts_dUpdateExpression::_updateExpressionBrand() noexcept { return _getProperty<js_unknown>("_updateExpressionBrand"); }
	inline void _impl_js_jts_dUpdateExpression::_updateExpressionBrand(js_unknown v) noexcept { _setProperty("_updateExpressionBrand", v); }
	inline auto _impl_js_jts_dLeftHandSideExpression::_leftHandSideExpressionBrand() noexcept { return _getProperty<js_unknown>("_leftHandSideExpressionBrand"); }
	inline void _impl_js_jts_dLeftHandSideExpression::_leftHandSideExpressionBrand(js_unknown v) noexcept { _setProperty("_leftHandSideExpressionBrand", v); }
	inline auto _impl_js_jts_dMemberExpression::_memberExpressionBrand() noexcept { return _getProperty<js_unknown>("_memberExpressionBrand"); }
	inline void _impl_js_jts_dMemberExpression::_memberExpressionBrand(js_unknown v) noexcept { _setProperty("_memberExpressionBrand", v); }
	inline auto _impl_js_jts_dPrimaryExpression::_primaryExpressionBrand() noexcept { return _getProperty<js_unknown>("_primaryExpressionBrand"); }
	inline void _impl_js_jts_dPrimaryExpression::_primaryExpressionBrand(js_unknown v) noexcept { _setProperty("_primaryExpressionBrand", v); }
	inline auto _impl_js_jts_dDeclaration::_declarationBrand() noexcept { return _getProperty<js_unknown>("_declarationBrand"); }
	inline void _impl_js_jts_dDeclaration::_declarationBrand(js_unknown v) noexcept { _setProperty("_declarationBrand", v); }
	inline auto _impl_js_jts_dIdentifier::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.Identifier*/>("kind"); }
	inline void _impl_js_jts_dIdentifier::kind(_js_jts_dSyntaxKind /*SyntaxKind.Identifier*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dIdentifier::escapedText() noexcept { return _getProperty<js_unknown /*flags=1048576: __String ()*/>("escapedText"); }
	inline void _impl_js_jts_dIdentifier::escapedText(js_unknown /*flags=1048576: __String ()*/ v) noexcept { _setProperty("escapedText", v); }
	inline auto _impl_js_jts_dIdentifier::text() noexcept { return _getProperty<js_string>("text"); }
	inline auto _impl_js_jts_dTransientIdentifier::resolvedSymbol() noexcept { return _getProperty<_js_jts_dSymbol>("resolvedSymbol"); }
	inline void _impl_js_jts_dTransientIdentifier::resolvedSymbol(_js_jts_dSymbol v) noexcept { _setProperty("resolvedSymbol", v); }
	inline auto _impl_js_jts_dQualifiedName::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.QualifiedName*/>("kind"); }
	inline void _impl_js_jts_dQualifiedName::kind(_js_jts_dSyntaxKind /*SyntaxKind.QualifiedName*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dQualifiedName::left() noexcept { return _getProperty<js_union<_js_jts_dIdentifier, _js_jts_dQualifiedName>>("left"); }
	inline void _impl_js_jts_dQualifiedName::left(js_union<_js_jts_dIdentifier, _js_jts_dQualifiedName> v) noexcept { _setProperty("left", v); }
	inline auto _impl_js_jts_dQualifiedName::right() noexcept { return _getProperty<_js_jts_dIdentifier>("right"); }
	inline void _impl_js_jts_dQualifiedName::right(_js_jts_dIdentifier v) noexcept { _setProperty("right", v); }
	inline auto _impl_js_jts_dStatement::_statementBrand() noexcept { return _getProperty<js_unknown>("_statementBrand"); }
	inline void _impl_js_jts_dStatement::_statementBrand(js_unknown v) noexcept { _setProperty("_statementBrand", v); }
	inline auto _impl_js_jts_dComputedPropertyName::parent() noexcept { return _getProperty<_js_jts_dDeclaration>("parent"); }
	inline void _impl_js_jts_dComputedPropertyName::parent(_js_jts_dDeclaration v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dComputedPropertyName::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ComputedPropertyName*/>("kind"); }
	inline void _impl_js_jts_dComputedPropertyName::kind(_js_jts_dSyntaxKind /*SyntaxKind.ComputedPropertyName*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dComputedPropertyName::expression() noexcept { return _getProperty<_js_jts_dExpression>("expression"); }
	inline void _impl_js_jts_dComputedPropertyName::expression(_js_jts_dExpression v) noexcept { _setProperty("expression", v); }
	inline auto _impl_js_jts_dDecorator::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.Decorator*/>("kind"); }
	inline void _impl_js_jts_dDecorator::kind(_js_jts_dSyntaxKind /*SyntaxKind.Decorator*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dDecorator::parent() noexcept { return _getProperty<_js_jts_dNamedDeclaration>("parent"); }
	inline void _impl_js_jts_dDecorator::parent(_js_jts_dNamedDeclaration v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dDecorator::expression() noexcept { return _getProperty<_js_jts_dLeftHandSideExpression>("expression"); }
	inline void _impl_js_jts_dDecorator::expression(_js_jts_dLeftHandSideExpression v) noexcept { _setProperty("expression", v); }
	inline auto _impl_js_jts_dTypeParameterDeclaration::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.TypeParameter*/>("kind"); }
	inline void _impl_js_jts_dTypeParameterDeclaration::kind(_js_jts_dSyntaxKind /*SyntaxKind.TypeParameter*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dTypeParameterDeclaration::parent() noexcept { return _getProperty<js_union<_js_jts_dArrowFunction, _js_jts_dCallSignatureDeclaration, _js_jts_dClassDeclaration, _js_jts_dClassExpression, _js_jts_dConstructSignatureDeclaration, _js_jts_dConstructorDeclaration, _js_jts_dConstructorTypeNode, _js_jts_dFunctionDeclaration, _js_jts_dFunctionExpression, _js_jts_dFunctionTypeNode, _js_jts_dGetAccessorDeclaration, _js_jts_dIndexSignatureDeclaration, _js_jts_dInferTypeNode, _js_jts_dInterfaceDeclaration, _js_jts_dJSDocFunctionType, _js_jts_dJSDocTemplateTag, _js_jts_dMethodDeclaration, _js_jts_dMethodSignature, _js_jts_dSetAccessorDeclaration, _js_jts_dTypeAliasDeclaration>>("parent"); }
	inline void _impl_js_jts_dTypeParameterDeclaration::parent(js_union<_js_jts_dArrowFunction, _js_jts_dCallSignatureDeclaration, _js_jts_dClassDeclaration, _js_jts_dClassExpression, _js_jts_dConstructSignatureDeclaration, _js_jts_dConstructorDeclaration, _js_jts_dConstructorTypeNode, _js_jts_dFunctionDeclaration, _js_jts_dFunctionExpression, _js_jts_dFunctionTypeNode, _js_jts_dGetAccessorDeclaration, _js_jts_dIndexSignatureDeclaration, _js_jts_dInferTypeNode, _js_jts_dInterfaceDeclaration, _js_jts_dJSDocFunctionType, _js_jts_dJSDocTemplateTag, _js_jts_dMethodDeclaration, _js_jts_dMethodSignature, _js_jts_dSetAccessorDeclaration, _js_jts_dTypeAliasDeclaration> v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dTypeParameterDeclaration::name() noexcept { return _getProperty<_js_jts_dIdentifier>("name"); }
	inline void _impl_js_jts_dTypeParameterDeclaration::name(_js_jts_dIdentifier v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dSignatureDeclarationBase::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.MethodSignature*/>("kind"); }
	inline void _impl_js_jts_dSignatureDeclarationBase::kind(_js_jts_dSyntaxKind /*SyntaxKind.MethodSignature*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dSignatureDeclarationBase::parameters() noexcept { return _getProperty<js_unknown /*flags=524288: NodeArray<ParameterDeclaration> (TypeReference=ts.NodeArray)*/>("parameters"); }
	inline void _impl_js_jts_dSignatureDeclarationBase::parameters(js_unknown /*flags=524288: NodeArray<ParameterDeclaration> (TypeReference=ts.NodeArray)*/ v) noexcept { _setProperty("parameters", v); }
	inline auto _impl_js_jts_dTypeElement::_typeElementBrand() noexcept { return _getProperty<js_unknown>("_typeElementBrand"); }
	inline void _impl_js_jts_dTypeElement::_typeElementBrand(js_unknown v) noexcept { _setProperty("_typeElementBrand", v); }
	inline auto _impl_js_jts_dCallSignatureDeclaration::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.CallSignature*/>("kind"); }
	inline void _impl_js_jts_dCallSignatureDeclaration::kind(_js_jts_dSyntaxKind /*SyntaxKind.CallSignature*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dConstructSignatureDeclaration::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ConstructSignature*/>("kind"); }
	inline void _impl_js_jts_dConstructSignatureDeclaration::kind(_js_jts_dSyntaxKind /*SyntaxKind.ConstructSignature*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dVariableDeclaration::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.VariableDeclaration*/>("kind"); }
	inline void _impl_js_jts_dVariableDeclaration::kind(_js_jts_dSyntaxKind /*SyntaxKind.VariableDeclaration*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dVariableDeclaration::parent() noexcept { return _getProperty<js_union<_js_jts_dCatchClause, _js_jts_dVariableDeclarationList>>("parent"); }
	inline void _impl_js_jts_dVariableDeclaration::parent(js_union<_js_jts_dCatchClause, _js_jts_dVariableDeclarationList> v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dVariableDeclaration::name() noexcept { return _getProperty<js_union<_js_jts_dArrayBindingPattern, _js_jts_dIdentifier, _js_jts_dObjectBindingPattern>>("name"); }
	inline void _impl_js_jts_dVariableDeclaration::name(js_union<_js_jts_dArrayBindingPattern, _js_jts_dIdentifier, _js_jts_dObjectBindingPattern> v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dVariableDeclarationList::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.VariableDeclarationList*/>("kind"); }
	inline void _impl_js_jts_dVariableDeclarationList::kind(_js_jts_dSyntaxKind /*SyntaxKind.VariableDeclarationList*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dVariableDeclarationList::parent() noexcept { return _getProperty<js_union<_js_jts_dForInStatement, _js_jts_dForOfStatement, _js_jts_dForStatement, _js_jts_dVariableStatement>>("parent"); }
	inline void _impl_js_jts_dVariableDeclarationList::parent(js_union<_js_jts_dForInStatement, _js_jts_dForOfStatement, _js_jts_dForStatement, _js_jts_dVariableStatement> v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dVariableDeclarationList::declarations() noexcept { return _getProperty<js_unknown /*flags=524288: NodeArray<VariableDeclaration> (TypeReference=ts.NodeArray)*/>("declarations"); }
	inline void _impl_js_jts_dVariableDeclarationList::declarations(js_unknown /*flags=524288: NodeArray<VariableDeclaration> (TypeReference=ts.NodeArray)*/ v) noexcept { _setProperty("declarations", v); }
	inline auto _impl_js_jts_dParameterDeclaration::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.Parameter*/>("kind"); }
	inline void _impl_js_jts_dParameterDeclaration::kind(_js_jts_dSyntaxKind /*SyntaxKind.Parameter*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dParameterDeclaration::parent() noexcept { return _getProperty<js_union<_js_jts_dArrowFunction, _js_jts_dCallSignatureDeclaration, _js_jts_dConstructSignatureDeclaration, _js_jts_dConstructorDeclaration, _js_jts_dConstructorTypeNode, _js_jts_dFunctionDeclaration, _js_jts_dFunctionExpression, _js_jts_dFunctionTypeNode, _js_jts_dGetAccessorDeclaration, _js_jts_dIndexSignatureDeclaration, _js_jts_dJSDocFunctionType, _js_jts_dMethodDeclaration, _js_jts_dMethodSignature, _js_jts_dSetAccessorDeclaration>>("parent"); }
	inline void _impl_js_jts_dParameterDeclaration::parent(js_union<_js_jts_dArrowFunction, _js_jts_dCallSignatureDeclaration, _js_jts_dConstructSignatureDeclaration, _js_jts_dConstructorDeclaration, _js_jts_dConstructorTypeNode, _js_jts_dFunctionDeclaration, _js_jts_dFunctionExpression, _js_jts_dFunctionTypeNode, _js_jts_dGetAccessorDeclaration, _js_jts_dIndexSignatureDeclaration, _js_jts_dJSDocFunctionType, _js_jts_dMethodDeclaration, _js_jts_dMethodSignature, _js_jts_dSetAccessorDeclaration> v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dParameterDeclaration::name() noexcept { return _getProperty<js_union<_js_jts_dArrayBindingPattern, _js_jts_dIdentifier, _js_jts_dObjectBindingPattern>>("name"); }
	inline void _impl_js_jts_dParameterDeclaration::name(js_union<_js_jts_dArrayBindingPattern, _js_jts_dIdentifier, _js_jts_dObjectBindingPattern> v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dBindingElement::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.BindingElement*/>("kind"); }
	inline void _impl_js_jts_dBindingElement::kind(_js_jts_dSyntaxKind /*SyntaxKind.BindingElement*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dBindingElement::parent() noexcept { return _getProperty<js_union<_js_jts_dArrayBindingPattern, _js_jts_dObjectBindingPattern>>("parent"); }
	inline void _impl_js_jts_dBindingElement::parent(js_union<_js_jts_dArrayBindingPattern, _js_jts_dObjectBindingPattern> v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dBindingElement::name() noexcept { return _getProperty<js_union<_js_jts_dArrayBindingPattern, _js_jts_dIdentifier, _js_jts_dObjectBindingPattern>>("name"); }
	inline void _impl_js_jts_dBindingElement::name(js_union<_js_jts_dArrayBindingPattern, _js_jts_dIdentifier, _js_jts_dObjectBindingPattern> v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dPropertySignature::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.PropertySignature*/>("kind"); }
	inline void _impl_js_jts_dPropertySignature::kind(_js_jts_dSyntaxKind /*SyntaxKind.PropertySignature*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dPropertySignature::name() noexcept { return _getProperty<js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral>>("name"); }
	inline void _impl_js_jts_dPropertySignature::name(js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral> v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dClassElement::_classElementBrand() noexcept { return _getProperty<js_unknown>("_classElementBrand"); }
	inline void _impl_js_jts_dClassElement::_classElementBrand(js_unknown v) noexcept { _setProperty("_classElementBrand", v); }
	inline auto _impl_js_jts_dPropertyDeclaration::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.PropertyDeclaration*/>("kind"); }
	inline void _impl_js_jts_dPropertyDeclaration::kind(_js_jts_dSyntaxKind /*SyntaxKind.PropertyDeclaration*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dPropertyDeclaration::parent() noexcept { return _getProperty<js_union<_js_jts_dClassDeclaration, _js_jts_dClassExpression>>("parent"); }
	inline void _impl_js_jts_dPropertyDeclaration::parent(js_union<_js_jts_dClassDeclaration, _js_jts_dClassExpression> v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dPropertyDeclaration::name() noexcept { return _getProperty<js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral>>("name"); }
	inline void _impl_js_jts_dPropertyDeclaration::name(js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral> v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dObjectLiteralElement::_objectLiteralBrand() noexcept { return _getProperty<js_unknown>("_objectLiteralBrand"); }
	inline void _impl_js_jts_dObjectLiteralElement::_objectLiteralBrand(js_unknown v) noexcept { _setProperty("_objectLiteralBrand", v); }
	inline auto _impl_js_jts_dPropertyAssignment::parent() noexcept { return _getProperty<_js_jts_dObjectLiteralExpression>("parent"); }
	inline void _impl_js_jts_dPropertyAssignment::parent(_js_jts_dObjectLiteralExpression v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dPropertyAssignment::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.PropertyAssignment*/>("kind"); }
	inline void _impl_js_jts_dPropertyAssignment::kind(_js_jts_dSyntaxKind /*SyntaxKind.PropertyAssignment*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dPropertyAssignment::name() noexcept { return _getProperty<js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral>>("name"); }
	inline void _impl_js_jts_dPropertyAssignment::name(js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral> v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dPropertyAssignment::initializer() noexcept { return _getProperty<_js_jts_dExpression>("initializer"); }
	inline void _impl_js_jts_dPropertyAssignment::initializer(_js_jts_dExpression v) noexcept { _setProperty("initializer", v); }
	inline auto _impl_js_jts_dShorthandPropertyAssignment::parent() noexcept { return _getProperty<_js_jts_dObjectLiteralExpression>("parent"); }
	inline void _impl_js_jts_dShorthandPropertyAssignment::parent(_js_jts_dObjectLiteralExpression v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dShorthandPropertyAssignment::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ShorthandPropertyAssignment*/>("kind"); }
	inline void _impl_js_jts_dShorthandPropertyAssignment::kind(_js_jts_dSyntaxKind /*SyntaxKind.ShorthandPropertyAssignment*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dShorthandPropertyAssignment::name() noexcept { return _getProperty<_js_jts_dIdentifier>("name"); }
	inline void _impl_js_jts_dShorthandPropertyAssignment::name(_js_jts_dIdentifier v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dSpreadAssignment::parent() noexcept { return _getProperty<_js_jts_dObjectLiteralExpression>("parent"); }
	inline void _impl_js_jts_dSpreadAssignment::parent(_js_jts_dObjectLiteralExpression v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dSpreadAssignment::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.SpreadAssignment*/>("kind"); }
	inline void _impl_js_jts_dSpreadAssignment::kind(_js_jts_dSyntaxKind /*SyntaxKind.SpreadAssignment*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dSpreadAssignment::expression() noexcept { return _getProperty<_js_jts_dExpression>("expression"); }
	inline void _impl_js_jts_dSpreadAssignment::expression(_js_jts_dExpression v) noexcept { _setProperty("expression", v); }
	inline auto _impl_js_jts_dPropertyLikeDeclaration::name() noexcept { return _getProperty<js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral>>("name"); }
	inline void _impl_js_jts_dPropertyLikeDeclaration::name(js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral> v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dObjectBindingPattern::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ObjectBindingPattern*/>("kind"); }
	inline void _impl_js_jts_dObjectBindingPattern::kind(_js_jts_dSyntaxKind /*SyntaxKind.ObjectBindingPattern*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dObjectBindingPattern::parent() noexcept { return _getProperty<js_union<_js_jts_dBindingElement, _js_jts_dParameterDeclaration, _js_jts_dVariableDeclaration>>("parent"); }
	inline void _impl_js_jts_dObjectBindingPattern::parent(js_union<_js_jts_dBindingElement, _js_jts_dParameterDeclaration, _js_jts_dVariableDeclaration> v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dObjectBindingPattern::elements() noexcept { return _getProperty<js_unknown /*flags=524288: NodeArray<BindingElement> (TypeReference=ts.NodeArray)*/>("elements"); }
	inline void _impl_js_jts_dObjectBindingPattern::elements(js_unknown /*flags=524288: NodeArray<BindingElement> (TypeReference=ts.NodeArray)*/ v) noexcept { _setProperty("elements", v); }
	inline auto _impl_js_jts_dArrayBindingPattern::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ArrayBindingPattern*/>("kind"); }
	inline void _impl_js_jts_dArrayBindingPattern::kind(_js_jts_dSyntaxKind /*SyntaxKind.ArrayBindingPattern*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dArrayBindingPattern::parent() noexcept { return _getProperty<js_union<_js_jts_dBindingElement, _js_jts_dParameterDeclaration, _js_jts_dVariableDeclaration>>("parent"); }
	inline void _impl_js_jts_dArrayBindingPattern::parent(js_union<_js_jts_dBindingElement, _js_jts_dParameterDeclaration, _js_jts_dVariableDeclaration> v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dArrayBindingPattern::elements() noexcept { return _getProperty<js_unknown /*flags=524288: NodeArray<ArrayBindingElement> (TypeReference=ts.NodeArray)*/>("elements"); }
	inline void _impl_js_jts_dArrayBindingPattern::elements(js_unknown /*flags=524288: NodeArray<ArrayBindingElement> (TypeReference=ts.NodeArray)*/ v) noexcept { _setProperty("elements", v); }
	inline auto _impl_js_jts_dFunctionLikeDeclarationBase::_functionLikeDeclarationBrand() noexcept { return _getProperty<js_unknown>("_functionLikeDeclarationBrand"); }
	inline void _impl_js_jts_dFunctionLikeDeclarationBase::_functionLikeDeclarationBrand(js_unknown v) noexcept { _setProperty("_functionLikeDeclarationBrand", v); }
	inline auto _impl_js_jts_dFunctionDeclaration::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.FunctionDeclaration*/>("kind"); }
	inline void _impl_js_jts_dFunctionDeclaration::kind(_js_jts_dSyntaxKind /*SyntaxKind.FunctionDeclaration*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dMethodSignature::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.MethodSignature*/>("kind"); }
	inline void _impl_js_jts_dMethodSignature::kind(_js_jts_dSyntaxKind /*SyntaxKind.MethodSignature*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dMethodSignature::parent() noexcept { return _getProperty<js_union<_js_jts_dClassDeclaration, _js_jts_dClassExpression, _js_jts_dInterfaceDeclaration, _js_jts_dTypeLiteralNode>>("parent"); }
	inline void _impl_js_jts_dMethodSignature::parent(js_union<_js_jts_dClassDeclaration, _js_jts_dClassExpression, _js_jts_dInterfaceDeclaration, _js_jts_dTypeLiteralNode> v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dMethodSignature::name() noexcept { return _getProperty<js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral>>("name"); }
	inline void _impl_js_jts_dMethodSignature::name(js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral> v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dMethodDeclaration::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.MethodDeclaration*/>("kind"); }
	inline void _impl_js_jts_dMethodDeclaration::kind(_js_jts_dSyntaxKind /*SyntaxKind.MethodDeclaration*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dMethodDeclaration::parent() noexcept { return _getProperty<js_union<_js_jts_dClassDeclaration, _js_jts_dClassExpression, _js_jts_dObjectLiteralExpression>>("parent"); }
	inline void _impl_js_jts_dMethodDeclaration::parent(js_union<_js_jts_dClassDeclaration, _js_jts_dClassExpression, _js_jts_dObjectLiteralExpression> v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dMethodDeclaration::name() noexcept { return _getProperty<js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral>>("name"); }
	inline void _impl_js_jts_dMethodDeclaration::name(js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral> v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dConstructorDeclaration::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.Constructor*/>("kind"); }
	inline void _impl_js_jts_dConstructorDeclaration::kind(_js_jts_dSyntaxKind /*SyntaxKind.Constructor*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dConstructorDeclaration::parent() noexcept { return _getProperty<js_union<_js_jts_dClassDeclaration, _js_jts_dClassExpression>>("parent"); }
	inline void _impl_js_jts_dConstructorDeclaration::parent(js_union<_js_jts_dClassDeclaration, _js_jts_dClassExpression> v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dSemicolonClassElement::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.SemicolonClassElement*/>("kind"); }
	inline void _impl_js_jts_dSemicolonClassElement::kind(_js_jts_dSyntaxKind /*SyntaxKind.SemicolonClassElement*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dSemicolonClassElement::parent() noexcept { return _getProperty<js_union<_js_jts_dClassDeclaration, _js_jts_dClassExpression>>("parent"); }
	inline void _impl_js_jts_dSemicolonClassElement::parent(js_union<_js_jts_dClassDeclaration, _js_jts_dClassExpression> v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dGetAccessorDeclaration::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.GetAccessor*/>("kind"); }
	inline void _impl_js_jts_dGetAccessorDeclaration::kind(_js_jts_dSyntaxKind /*SyntaxKind.GetAccessor*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dGetAccessorDeclaration::parent() noexcept { return _getProperty<js_union<_js_jts_dClassDeclaration, _js_jts_dClassExpression, _js_jts_dObjectLiteralExpression>>("parent"); }
	inline void _impl_js_jts_dGetAccessorDeclaration::parent(js_union<_js_jts_dClassDeclaration, _js_jts_dClassExpression, _js_jts_dObjectLiteralExpression> v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dGetAccessorDeclaration::name() noexcept { return _getProperty<js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral>>("name"); }
	inline void _impl_js_jts_dGetAccessorDeclaration::name(js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral> v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dSetAccessorDeclaration::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.SetAccessor*/>("kind"); }
	inline void _impl_js_jts_dSetAccessorDeclaration::kind(_js_jts_dSyntaxKind /*SyntaxKind.SetAccessor*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dSetAccessorDeclaration::parent() noexcept { return _getProperty<js_union<_js_jts_dClassDeclaration, _js_jts_dClassExpression, _js_jts_dObjectLiteralExpression>>("parent"); }
	inline void _impl_js_jts_dSetAccessorDeclaration::parent(js_union<_js_jts_dClassDeclaration, _js_jts_dClassExpression, _js_jts_dObjectLiteralExpression> v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dSetAccessorDeclaration::name() noexcept { return _getProperty<js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral>>("name"); }
	inline void _impl_js_jts_dSetAccessorDeclaration::name(js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral> v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dIndexSignatureDeclaration::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.IndexSignature*/>("kind"); }
	inline void _impl_js_jts_dIndexSignatureDeclaration::kind(_js_jts_dSyntaxKind /*SyntaxKind.IndexSignature*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dIndexSignatureDeclaration::parent() noexcept { return _getProperty<js_union<_js_jts_dClassDeclaration, _js_jts_dClassExpression, _js_jts_dInterfaceDeclaration, _js_jts_dTypeLiteralNode>>("parent"); }
	inline void _impl_js_jts_dIndexSignatureDeclaration::parent(js_union<_js_jts_dClassDeclaration, _js_jts_dClassExpression, _js_jts_dInterfaceDeclaration, _js_jts_dTypeLiteralNode> v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dTypeNode::_typeNodeBrand() noexcept { return _getProperty<js_unknown>("_typeNodeBrand"); }
	inline void _impl_js_jts_dTypeNode::_typeNodeBrand(js_unknown v) noexcept { _setProperty("_typeNodeBrand", v); }
	inline auto _impl_js_jts_dKeywordTypeNode::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.NullKeyword*/>("kind"); }
	inline void _impl_js_jts_dKeywordTypeNode::kind(_js_jts_dSyntaxKind /*SyntaxKind.NullKeyword*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dImportTypeNode::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ImportType*/>("kind"); }
	inline void _impl_js_jts_dImportTypeNode::kind(_js_jts_dSyntaxKind /*SyntaxKind.ImportType*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dImportTypeNode::argument() noexcept { return _getProperty<_js_jts_dTypeNode>("argument"); }
	inline void _impl_js_jts_dImportTypeNode::argument(_js_jts_dTypeNode v) noexcept { _setProperty("argument", v); }
	inline auto _impl_js_jts_dThisTypeNode::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ThisType*/>("kind"); }
	inline void _impl_js_jts_dThisTypeNode::kind(_js_jts_dSyntaxKind /*SyntaxKind.ThisType*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dFunctionOrConstructorTypeNodeBase::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.FunctionType*/>("kind"); }
	inline void _impl_js_jts_dFunctionOrConstructorTypeNodeBase::kind(_js_jts_dSyntaxKind /*SyntaxKind.FunctionType*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dFunctionOrConstructorTypeNodeBase::type() noexcept { return _getProperty<_js_jts_dTypeNode>("type"); }
	inline void _impl_js_jts_dFunctionOrConstructorTypeNodeBase::type(_js_jts_dTypeNode v) noexcept { _setProperty("type", v); }
	inline auto _impl_js_jts_dFunctionTypeNode::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.FunctionType*/>("kind"); }
	inline void _impl_js_jts_dFunctionTypeNode::kind(_js_jts_dSyntaxKind /*SyntaxKind.FunctionType*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dConstructorTypeNode::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ConstructorType*/>("kind"); }
	inline void _impl_js_jts_dConstructorTypeNode::kind(_js_jts_dSyntaxKind /*SyntaxKind.ConstructorType*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dTypeReferenceNode::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.TypeReference*/>("kind"); }
	inline void _impl_js_jts_dTypeReferenceNode::kind(_js_jts_dSyntaxKind /*SyntaxKind.TypeReference*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dTypeReferenceNode::typeName() noexcept { return _getProperty<js_union<_js_jts_dIdentifier, _js_jts_dQualifiedName>>("typeName"); }
	inline void _impl_js_jts_dTypeReferenceNode::typeName(js_union<_js_jts_dIdentifier, _js_jts_dQualifiedName> v) noexcept { _setProperty("typeName", v); }
	inline auto _impl_js_jts_dTypePredicateNode::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.TypePredicate*/>("kind"); }
	inline void _impl_js_jts_dTypePredicateNode::kind(_js_jts_dSyntaxKind /*SyntaxKind.TypePredicate*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dTypePredicateNode::parent() noexcept { return _getProperty<js_union<_js_jts_dArrowFunction, _js_jts_dCallSignatureDeclaration, _js_jts_dConstructSignatureDeclaration, _js_jts_dConstructorDeclaration, _js_jts_dConstructorTypeNode, _js_jts_dFunctionDeclaration, _js_jts_dFunctionExpression, _js_jts_dFunctionTypeNode, _js_jts_dGetAccessorDeclaration, _js_jts_dIndexSignatureDeclaration, _js_jts_dJSDocFunctionType, _js_jts_dJSDocTypeExpression, _js_jts_dMethodDeclaration, _js_jts_dMethodSignature, _js_jts_dSetAccessorDeclaration>>("parent"); }
	inline void _impl_js_jts_dTypePredicateNode::parent(js_union<_js_jts_dArrowFunction, _js_jts_dCallSignatureDeclaration, _js_jts_dConstructSignatureDeclaration, _js_jts_dConstructorDeclaration, _js_jts_dConstructorTypeNode, _js_jts_dFunctionDeclaration, _js_jts_dFunctionExpression, _js_jts_dFunctionTypeNode, _js_jts_dGetAccessorDeclaration, _js_jts_dIndexSignatureDeclaration, _js_jts_dJSDocFunctionType, _js_jts_dJSDocTypeExpression, _js_jts_dMethodDeclaration, _js_jts_dMethodSignature, _js_jts_dSetAccessorDeclaration> v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dTypePredicateNode::parameterName() noexcept { return _getProperty<js_union<_js_jts_dIdentifier, _js_jts_dThisTypeNode>>("parameterName"); }
	inline void _impl_js_jts_dTypePredicateNode::parameterName(js_union<_js_jts_dIdentifier, _js_jts_dThisTypeNode> v) noexcept { _setProperty("parameterName", v); }
	inline auto _impl_js_jts_dTypePredicateNode::type() noexcept { return _getProperty<_js_jts_dTypeNode>("type"); }
	inline void _impl_js_jts_dTypePredicateNode::type(_js_jts_dTypeNode v) noexcept { _setProperty("type", v); }
	inline auto _impl_js_jts_dTypeQueryNode::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.TypeQuery*/>("kind"); }
	inline void _impl_js_jts_dTypeQueryNode::kind(_js_jts_dSyntaxKind /*SyntaxKind.TypeQuery*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dTypeQueryNode::exprName() noexcept { return _getProperty<js_union<_js_jts_dIdentifier, _js_jts_dQualifiedName>>("exprName"); }
	inline void _impl_js_jts_dTypeQueryNode::exprName(js_union<_js_jts_dIdentifier, _js_jts_dQualifiedName> v) noexcept { _setProperty("exprName", v); }
	inline auto _impl_js_jts_dTypeLiteralNode::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.TypeLiteral*/>("kind"); }
	inline void _impl_js_jts_dTypeLiteralNode::kind(_js_jts_dSyntaxKind /*SyntaxKind.TypeLiteral*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dTypeLiteralNode::members() noexcept { return _getProperty<js_unknown /*flags=524288: NodeArray<TypeElement> (TypeReference=ts.NodeArray)*/>("members"); }
	inline void _impl_js_jts_dTypeLiteralNode::members(js_unknown /*flags=524288: NodeArray<TypeElement> (TypeReference=ts.NodeArray)*/ v) noexcept { _setProperty("members", v); }
	inline auto _impl_js_jts_dArrayTypeNode::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ArrayType*/>("kind"); }
	inline void _impl_js_jts_dArrayTypeNode::kind(_js_jts_dSyntaxKind /*SyntaxKind.ArrayType*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dArrayTypeNode::elementType() noexcept { return _getProperty<_js_jts_dTypeNode>("elementType"); }
	inline void _impl_js_jts_dArrayTypeNode::elementType(_js_jts_dTypeNode v) noexcept { _setProperty("elementType", v); }
	inline auto _impl_js_jts_dTupleTypeNode::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.TupleType*/>("kind"); }
	inline void _impl_js_jts_dTupleTypeNode::kind(_js_jts_dSyntaxKind /*SyntaxKind.TupleType*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dTupleTypeNode::elementTypes() noexcept { return _getProperty<js_unknown /*flags=524288: NodeArray<TypeNode> (TypeReference=ts.NodeArray)*/>("elementTypes"); }
	inline void _impl_js_jts_dTupleTypeNode::elementTypes(js_unknown /*flags=524288: NodeArray<TypeNode> (TypeReference=ts.NodeArray)*/ v) noexcept { _setProperty("elementTypes", v); }
	inline auto _impl_js_jts_dOptionalTypeNode::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.OptionalType*/>("kind"); }
	inline void _impl_js_jts_dOptionalTypeNode::kind(_js_jts_dSyntaxKind /*SyntaxKind.OptionalType*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dOptionalTypeNode::type() noexcept { return _getProperty<_js_jts_dTypeNode>("type"); }
	inline void _impl_js_jts_dOptionalTypeNode::type(_js_jts_dTypeNode v) noexcept { _setProperty("type", v); }
	inline auto _impl_js_jts_dRestTypeNode::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.RestType*/>("kind"); }
	inline void _impl_js_jts_dRestTypeNode::kind(_js_jts_dSyntaxKind /*SyntaxKind.RestType*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dRestTypeNode::type() noexcept { return _getProperty<_js_jts_dTypeNode>("type"); }
	inline void _impl_js_jts_dRestTypeNode::type(_js_jts_dTypeNode v) noexcept { _setProperty("type", v); }
	inline auto _impl_js_jts_dUnionTypeNode::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.UnionType*/>("kind"); }
	inline void _impl_js_jts_dUnionTypeNode::kind(_js_jts_dSyntaxKind /*SyntaxKind.UnionType*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dUnionTypeNode::types() noexcept { return _getProperty<js_unknown /*flags=524288: NodeArray<TypeNode> (TypeReference=ts.NodeArray)*/>("types"); }
	inline void _impl_js_jts_dUnionTypeNode::types(js_unknown /*flags=524288: NodeArray<TypeNode> (TypeReference=ts.NodeArray)*/ v) noexcept { _setProperty("types", v); }
	inline auto _impl_js_jts_dIntersectionTypeNode::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.IntersectionType*/>("kind"); }
	inline void _impl_js_jts_dIntersectionTypeNode::kind(_js_jts_dSyntaxKind /*SyntaxKind.IntersectionType*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dIntersectionTypeNode::types() noexcept { return _getProperty<js_unknown /*flags=524288: NodeArray<TypeNode> (TypeReference=ts.NodeArray)*/>("types"); }
	inline void _impl_js_jts_dIntersectionTypeNode::types(js_unknown /*flags=524288: NodeArray<TypeNode> (TypeReference=ts.NodeArray)*/ v) noexcept { _setProperty("types", v); }
	inline auto _impl_js_jts_dConditionalTypeNode::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ConditionalType*/>("kind"); }
	inline void _impl_js_jts_dConditionalTypeNode::kind(_js_jts_dSyntaxKind /*SyntaxKind.ConditionalType*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dConditionalTypeNode::checkType() noexcept { return _getProperty<_js_jts_dTypeNode>("checkType"); }
	inline void _impl_js_jts_dConditionalTypeNode::checkType(_js_jts_dTypeNode v) noexcept { _setProperty("checkType", v); }
	inline auto _impl_js_jts_dConditionalTypeNode::extendsType() noexcept { return _getProperty<_js_jts_dTypeNode>("extendsType"); }
	inline void _impl_js_jts_dConditionalTypeNode::extendsType(_js_jts_dTypeNode v) noexcept { _setProperty("extendsType", v); }
	inline auto _impl_js_jts_dConditionalTypeNode::trueType() noexcept { return _getProperty<_js_jts_dTypeNode>("trueType"); }
	inline void _impl_js_jts_dConditionalTypeNode::trueType(_js_jts_dTypeNode v) noexcept { _setProperty("trueType", v); }
	inline auto _impl_js_jts_dConditionalTypeNode::falseType() noexcept { return _getProperty<_js_jts_dTypeNode>("falseType"); }
	inline void _impl_js_jts_dConditionalTypeNode::falseType(_js_jts_dTypeNode v) noexcept { _setProperty("falseType", v); }
	inline auto _impl_js_jts_dInferTypeNode::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.InferType*/>("kind"); }
	inline void _impl_js_jts_dInferTypeNode::kind(_js_jts_dSyntaxKind /*SyntaxKind.InferType*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dInferTypeNode::typeParameter() noexcept { return _getProperty<_js_jts_dTypeParameterDeclaration>("typeParameter"); }
	inline void _impl_js_jts_dInferTypeNode::typeParameter(_js_jts_dTypeParameterDeclaration v) noexcept { _setProperty("typeParameter", v); }
	inline auto _impl_js_jts_dParenthesizedTypeNode::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ParenthesizedType*/>("kind"); }
	inline void _impl_js_jts_dParenthesizedTypeNode::kind(_js_jts_dSyntaxKind /*SyntaxKind.ParenthesizedType*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dParenthesizedTypeNode::type() noexcept { return _getProperty<_js_jts_dTypeNode>("type"); }
	inline void _impl_js_jts_dParenthesizedTypeNode::type(_js_jts_dTypeNode v) noexcept { _setProperty("type", v); }
	inline auto _impl_js_jts_dTypeOperatorNode::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.TypeOperator*/>("kind"); }
	inline void _impl_js_jts_dTypeOperatorNode::kind(_js_jts_dSyntaxKind /*SyntaxKind.TypeOperator*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dTypeOperatorNode::operator_() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.KeyOfKeyword*/>("operator"); }
	inline void _impl_js_jts_dTypeOperatorNode::operator_(_js_jts_dSyntaxKind /*SyntaxKind.KeyOfKeyword*/ v) noexcept { _setProperty("operator", v); }
	inline auto _impl_js_jts_dTypeOperatorNode::type() noexcept { return _getProperty<_js_jts_dTypeNode>("type"); }
	inline void _impl_js_jts_dTypeOperatorNode::type(_js_jts_dTypeNode v) noexcept { _setProperty("type", v); }
	inline auto _impl_js_jts_dIndexedAccessTypeNode::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.IndexedAccessType*/>("kind"); }
	inline void _impl_js_jts_dIndexedAccessTypeNode::kind(_js_jts_dSyntaxKind /*SyntaxKind.IndexedAccessType*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dIndexedAccessTypeNode::objectType() noexcept { return _getProperty<_js_jts_dTypeNode>("objectType"); }
	inline void _impl_js_jts_dIndexedAccessTypeNode::objectType(_js_jts_dTypeNode v) noexcept { _setProperty("objectType", v); }
	inline auto _impl_js_jts_dIndexedAccessTypeNode::indexType() noexcept { return _getProperty<_js_jts_dTypeNode>("indexType"); }
	inline void _impl_js_jts_dIndexedAccessTypeNode::indexType(_js_jts_dTypeNode v) noexcept { _setProperty("indexType", v); }
	inline auto _impl_js_jts_dMappedTypeNode::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.MappedType*/>("kind"); }
	inline void _impl_js_jts_dMappedTypeNode::kind(_js_jts_dSyntaxKind /*SyntaxKind.MappedType*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dMappedTypeNode::typeParameter() noexcept { return _getProperty<_js_jts_dTypeParameterDeclaration>("typeParameter"); }
	inline void _impl_js_jts_dMappedTypeNode::typeParameter(_js_jts_dTypeParameterDeclaration v) noexcept { _setProperty("typeParameter", v); }
	inline auto _impl_js_jts_dLiteralTypeNode::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.LiteralType*/>("kind"); }
	inline void _impl_js_jts_dLiteralTypeNode::kind(_js_jts_dSyntaxKind /*SyntaxKind.LiteralType*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dLiteralTypeNode::literal() noexcept { return _getProperty<js_union<_js_jts_dBooleanLiteral, _js_jts_dLiteralExpression, _js_jts_dPrefixUnaryExpression>>("literal"); }
	inline void _impl_js_jts_dLiteralTypeNode::literal(js_union<_js_jts_dBooleanLiteral, _js_jts_dLiteralExpression, _js_jts_dPrefixUnaryExpression> v) noexcept { _setProperty("literal", v); }
	inline auto _impl_js_jts_dLiteralLikeNode::text() noexcept { return _getProperty<js_string>("text"); }
	inline void _impl_js_jts_dLiteralLikeNode::text(js_string v) noexcept { _setProperty("text", v); }
	inline auto _impl_js_jts_dLiteralExpression::_literalExpressionBrand() noexcept { return _getProperty<js_unknown>("_literalExpressionBrand"); }
	inline void _impl_js_jts_dLiteralExpression::_literalExpressionBrand(js_unknown v) noexcept { _setProperty("_literalExpressionBrand", v); }
	inline auto _impl_js_jts_dStringLiteral::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.StringLiteral*/>("kind"); }
	inline void _impl_js_jts_dStringLiteral::kind(_js_jts_dSyntaxKind /*SyntaxKind.StringLiteral*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dOmittedExpression::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.OmittedExpression*/>("kind"); }
	inline void _impl_js_jts_dOmittedExpression::kind(_js_jts_dSyntaxKind /*SyntaxKind.OmittedExpression*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dPartiallyEmittedExpression::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.PartiallyEmittedExpression*/>("kind"); }
	inline void _impl_js_jts_dPartiallyEmittedExpression::kind(_js_jts_dSyntaxKind /*SyntaxKind.PartiallyEmittedExpression*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dPartiallyEmittedExpression::expression() noexcept { return _getProperty<_js_jts_dExpression>("expression"); }
	inline void _impl_js_jts_dPartiallyEmittedExpression::expression(_js_jts_dExpression v) noexcept { _setProperty("expression", v); }
	inline auto _impl_js_jts_dPrefixUnaryExpression::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.PrefixUnaryExpression*/>("kind"); }
	inline void _impl_js_jts_dPrefixUnaryExpression::kind(_js_jts_dSyntaxKind /*SyntaxKind.PrefixUnaryExpression*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dPrefixUnaryExpression::operator_() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.PlusToken*/>("operator"); }
	inline void _impl_js_jts_dPrefixUnaryExpression::operator_(_js_jts_dSyntaxKind /*SyntaxKind.PlusToken*/ v) noexcept { _setProperty("operator", v); }
	inline auto _impl_js_jts_dPrefixUnaryExpression::operand() noexcept { return _getProperty<_js_jts_dUnaryExpression>("operand"); }
	inline void _impl_js_jts_dPrefixUnaryExpression::operand(_js_jts_dUnaryExpression v) noexcept { _setProperty("operand", v); }
	inline auto _impl_js_jts_dPostfixUnaryExpression::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.PostfixUnaryExpression*/>("kind"); }
	inline void _impl_js_jts_dPostfixUnaryExpression::kind(_js_jts_dSyntaxKind /*SyntaxKind.PostfixUnaryExpression*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dPostfixUnaryExpression::operand() noexcept { return _getProperty<_js_jts_dLeftHandSideExpression>("operand"); }
	inline void _impl_js_jts_dPostfixUnaryExpression::operand(_js_jts_dLeftHandSideExpression v) noexcept { _setProperty("operand", v); }
	inline auto _impl_js_jts_dPostfixUnaryExpression::operator_() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.PlusPlusToken*/>("operator"); }
	inline void _impl_js_jts_dPostfixUnaryExpression::operator_(_js_jts_dSyntaxKind /*SyntaxKind.PlusPlusToken*/ v) noexcept { _setProperty("operator", v); }
	inline auto _impl_js_jts_dNullLiteral::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.NullKeyword*/>("kind"); }
	inline void _impl_js_jts_dNullLiteral::kind(_js_jts_dSyntaxKind /*SyntaxKind.NullKeyword*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dBooleanLiteral::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.FalseKeyword*/>("kind"); }
	inline void _impl_js_jts_dBooleanLiteral::kind(_js_jts_dSyntaxKind /*SyntaxKind.FalseKeyword*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dThisExpression::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ThisKeyword*/>("kind"); }
	inline void _impl_js_jts_dThisExpression::kind(_js_jts_dSyntaxKind /*SyntaxKind.ThisKeyword*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dSuperExpression::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.SuperKeyword*/>("kind"); }
	inline void _impl_js_jts_dSuperExpression::kind(_js_jts_dSyntaxKind /*SyntaxKind.SuperKeyword*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dImportExpression::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ImportKeyword*/>("kind"); }
	inline void _impl_js_jts_dImportExpression::kind(_js_jts_dSyntaxKind /*SyntaxKind.ImportKeyword*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dDeleteExpression::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.DeleteExpression*/>("kind"); }
	inline void _impl_js_jts_dDeleteExpression::kind(_js_jts_dSyntaxKind /*SyntaxKind.DeleteExpression*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dDeleteExpression::expression() noexcept { return _getProperty<_js_jts_dUnaryExpression>("expression"); }
	inline void _impl_js_jts_dDeleteExpression::expression(_js_jts_dUnaryExpression v) noexcept { _setProperty("expression", v); }
	inline auto _impl_js_jts_dTypeOfExpression::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.TypeOfExpression*/>("kind"); }
	inline void _impl_js_jts_dTypeOfExpression::kind(_js_jts_dSyntaxKind /*SyntaxKind.TypeOfExpression*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dTypeOfExpression::expression() noexcept { return _getProperty<_js_jts_dUnaryExpression>("expression"); }
	inline void _impl_js_jts_dTypeOfExpression::expression(_js_jts_dUnaryExpression v) noexcept { _setProperty("expression", v); }
	inline auto _impl_js_jts_dVoidExpression::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.VoidExpression*/>("kind"); }
	inline void _impl_js_jts_dVoidExpression::kind(_js_jts_dSyntaxKind /*SyntaxKind.VoidExpression*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dVoidExpression::expression() noexcept { return _getProperty<_js_jts_dUnaryExpression>("expression"); }
	inline void _impl_js_jts_dVoidExpression::expression(_js_jts_dUnaryExpression v) noexcept { _setProperty("expression", v); }
	inline auto _impl_js_jts_dAwaitExpression::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.AwaitExpression*/>("kind"); }
	inline void _impl_js_jts_dAwaitExpression::kind(_js_jts_dSyntaxKind /*SyntaxKind.AwaitExpression*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dAwaitExpression::expression() noexcept { return _getProperty<_js_jts_dUnaryExpression>("expression"); }
	inline void _impl_js_jts_dAwaitExpression::expression(_js_jts_dUnaryExpression v) noexcept { _setProperty("expression", v); }
	inline auto _impl_js_jts_dYieldExpression::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.YieldExpression*/>("kind"); }
	inline void _impl_js_jts_dYieldExpression::kind(_js_jts_dSyntaxKind /*SyntaxKind.YieldExpression*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dSyntheticExpression::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.SyntheticExpression*/>("kind"); }
	inline void _impl_js_jts_dSyntheticExpression::kind(_js_jts_dSyntaxKind /*SyntaxKind.SyntheticExpression*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dSyntheticExpression::isSpread() noexcept { return _getProperty<bool /*false*/>("isSpread"); }
	inline void _impl_js_jts_dSyntheticExpression::isSpread(bool /*false*/ v) noexcept { _setProperty("isSpread", v); }
	inline auto _impl_js_jts_dSyntheticExpression::type() noexcept { return _getProperty<_js_jts_dType>("type"); }
	inline void _impl_js_jts_dSyntheticExpression::type(_js_jts_dType v) noexcept { _setProperty("type", v); }
	inline auto _impl_js_jts_dBinaryExpression::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.BinaryExpression*/>("kind"); }
	inline void _impl_js_jts_dBinaryExpression::kind(_js_jts_dSyntaxKind /*SyntaxKind.BinaryExpression*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dBinaryExpression::left() noexcept { return _getProperty<_js_jts_dExpression>("left"); }
	inline void _impl_js_jts_dBinaryExpression::left(_js_jts_dExpression v) noexcept { _setProperty("left", v); }
	inline auto _impl_js_jts_dBinaryExpression::operatorToken() noexcept { return _getProperty<js_unknown /*flags=524288: Token<BinaryOperator> (TypeReference=ts.Token)*/>("operatorToken"); }
	inline void _impl_js_jts_dBinaryExpression::operatorToken(js_unknown /*flags=524288: Token<BinaryOperator> (TypeReference=ts.Token)*/ v) noexcept { _setProperty("operatorToken", v); }
	inline auto _impl_js_jts_dBinaryExpression::right() noexcept { return _getProperty<_js_jts_dExpression>("right"); }
	inline void _impl_js_jts_dBinaryExpression::right(_js_jts_dExpression v) noexcept { _setProperty("right", v); }
	inline auto _impl_js_jts_dAssignmentExpression::left() noexcept { return _getProperty<_js_jts_dLeftHandSideExpression>("left"); }
	inline void _impl_js_jts_dAssignmentExpression::left(_js_jts_dLeftHandSideExpression v) noexcept { _setProperty("left", v); }
	inline auto _impl_js_jts_dAssignmentExpression::operatorToken() noexcept { return _getProperty<js_unknown /*flags=262144: TOperator ()*/>("operatorToken"); }
	inline void _impl_js_jts_dAssignmentExpression::operatorToken(js_unknown /*flags=262144: TOperator ()*/ v) noexcept { _setProperty("operatorToken", v); }
	inline auto _impl_js_jts_dObjectDestructuringAssignment::left() noexcept { return _getProperty<_js_jts_dObjectLiteralExpression>("left"); }
	inline void _impl_js_jts_dObjectDestructuringAssignment::left(_js_jts_dObjectLiteralExpression v) noexcept { _setProperty("left", v); }
	inline auto _impl_js_jts_dArrayDestructuringAssignment::left() noexcept { return _getProperty<_js_jts_dArrayLiteralExpression>("left"); }
	inline void _impl_js_jts_dArrayDestructuringAssignment::left(_js_jts_dArrayLiteralExpression v) noexcept { _setProperty("left", v); }
	inline auto _impl_js_jts_dConditionalExpression::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ConditionalExpression*/>("kind"); }
	inline void _impl_js_jts_dConditionalExpression::kind(_js_jts_dSyntaxKind /*SyntaxKind.ConditionalExpression*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dConditionalExpression::condition() noexcept { return _getProperty<_js_jts_dExpression>("condition"); }
	inline void _impl_js_jts_dConditionalExpression::condition(_js_jts_dExpression v) noexcept { _setProperty("condition", v); }
	inline auto _impl_js_jts_dConditionalExpression::questionToken() noexcept { return _getProperty<js_unknown /*flags=524288: Token<SyntaxKind.QuestionToken> (TypeReference=ts.Token)*/>("questionToken"); }
	inline void _impl_js_jts_dConditionalExpression::questionToken(js_unknown /*flags=524288: Token<SyntaxKind.QuestionToken> (TypeReference=ts.Token)*/ v) noexcept { _setProperty("questionToken", v); }
	inline auto _impl_js_jts_dConditionalExpression::whenTrue() noexcept { return _getProperty<_js_jts_dExpression>("whenTrue"); }
	inline void _impl_js_jts_dConditionalExpression::whenTrue(_js_jts_dExpression v) noexcept { _setProperty("whenTrue", v); }
	inline auto _impl_js_jts_dConditionalExpression::colonToken() noexcept { return _getProperty<js_unknown /*flags=524288: Token<SyntaxKind.ColonToken> (TypeReference=ts.Token)*/>("colonToken"); }
	inline void _impl_js_jts_dConditionalExpression::colonToken(js_unknown /*flags=524288: Token<SyntaxKind.ColonToken> (TypeReference=ts.Token)*/ v) noexcept { _setProperty("colonToken", v); }
	inline auto _impl_js_jts_dConditionalExpression::whenFalse() noexcept { return _getProperty<_js_jts_dExpression>("whenFalse"); }
	inline void _impl_js_jts_dConditionalExpression::whenFalse(_js_jts_dExpression v) noexcept { _setProperty("whenFalse", v); }
	inline auto _impl_js_jts_dFunctionExpression::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.FunctionExpression*/>("kind"); }
	inline void _impl_js_jts_dFunctionExpression::kind(_js_jts_dSyntaxKind /*SyntaxKind.FunctionExpression*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dFunctionExpression::body() noexcept { return _getProperty<_js_jts_dBlock>("body"); }
	inline void _impl_js_jts_dFunctionExpression::body(_js_jts_dBlock v) noexcept { _setProperty("body", v); }
	inline auto _impl_js_jts_dArrowFunction::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ArrowFunction*/>("kind"); }
	inline void _impl_js_jts_dArrowFunction::kind(_js_jts_dSyntaxKind /*SyntaxKind.ArrowFunction*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dArrowFunction::equalsGreaterThanToken() noexcept { return _getProperty<js_unknown /*flags=524288: Token<SyntaxKind.EqualsGreaterThanToken> (TypeReference=ts.Token)*/>("equalsGreaterThanToken"); }
	inline void _impl_js_jts_dArrowFunction::equalsGreaterThanToken(js_unknown /*flags=524288: Token<SyntaxKind.EqualsGreaterThanToken> (TypeReference=ts.Token)*/ v) noexcept { _setProperty("equalsGreaterThanToken", v); }
	inline auto _impl_js_jts_dArrowFunction::body() noexcept { return _getProperty<js_union<_js_jts_dBlock, _js_jts_dExpression>>("body"); }
	inline void _impl_js_jts_dArrowFunction::body(js_union<_js_jts_dBlock, _js_jts_dExpression> v) noexcept { _setProperty("body", v); }
	inline auto _impl_js_jts_dArrowFunction::name() noexcept { return _getProperty<js_unknown /*flags=131072: never ()*/>("name"); }
	inline void _impl_js_jts_dArrowFunction::name(js_unknown /*flags=131072: never ()*/ v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dRegularExpressionLiteral::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.RegularExpressionLiteral*/>("kind"); }
	inline void _impl_js_jts_dRegularExpressionLiteral::kind(_js_jts_dSyntaxKind /*SyntaxKind.RegularExpressionLiteral*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dNoSubstitutionTemplateLiteral::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.NoSubstitutionTemplateLiteral*/>("kind"); }
	inline void _impl_js_jts_dNoSubstitutionTemplateLiteral::kind(_js_jts_dSyntaxKind /*SyntaxKind.NoSubstitutionTemplateLiteral*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dNumericLiteral::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.NumericLiteral*/>("kind"); }
	inline void _impl_js_jts_dNumericLiteral::kind(_js_jts_dSyntaxKind /*SyntaxKind.NumericLiteral*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dBigIntLiteral::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.BigIntLiteral*/>("kind"); }
	inline void _impl_js_jts_dBigIntLiteral::kind(_js_jts_dSyntaxKind /*SyntaxKind.BigIntLiteral*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dTemplateHead::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.TemplateHead*/>("kind"); }
	inline void _impl_js_jts_dTemplateHead::kind(_js_jts_dSyntaxKind /*SyntaxKind.TemplateHead*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dTemplateHead::parent() noexcept { return _getProperty<_js_jts_dTemplateExpression>("parent"); }
	inline void _impl_js_jts_dTemplateHead::parent(_js_jts_dTemplateExpression v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dTemplateMiddle::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.TemplateMiddle*/>("kind"); }
	inline void _impl_js_jts_dTemplateMiddle::kind(_js_jts_dSyntaxKind /*SyntaxKind.TemplateMiddle*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dTemplateMiddle::parent() noexcept { return _getProperty<_js_jts_dTemplateSpan>("parent"); }
	inline void _impl_js_jts_dTemplateMiddle::parent(_js_jts_dTemplateSpan v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dTemplateTail::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.TemplateTail*/>("kind"); }
	inline void _impl_js_jts_dTemplateTail::kind(_js_jts_dSyntaxKind /*SyntaxKind.TemplateTail*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dTemplateTail::parent() noexcept { return _getProperty<_js_jts_dTemplateSpan>("parent"); }
	inline void _impl_js_jts_dTemplateTail::parent(_js_jts_dTemplateSpan v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dTemplateExpression::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.TemplateExpression*/>("kind"); }
	inline void _impl_js_jts_dTemplateExpression::kind(_js_jts_dSyntaxKind /*SyntaxKind.TemplateExpression*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dTemplateExpression::head() noexcept { return _getProperty<_js_jts_dTemplateHead>("head"); }
	inline void _impl_js_jts_dTemplateExpression::head(_js_jts_dTemplateHead v) noexcept { _setProperty("head", v); }
	inline auto _impl_js_jts_dTemplateExpression::templateSpans() noexcept { return _getProperty<js_unknown /*flags=524288: NodeArray<TemplateSpan> (TypeReference=ts.NodeArray)*/>("templateSpans"); }
	inline void _impl_js_jts_dTemplateExpression::templateSpans(js_unknown /*flags=524288: NodeArray<TemplateSpan> (TypeReference=ts.NodeArray)*/ v) noexcept { _setProperty("templateSpans", v); }
	inline auto _impl_js_jts_dTemplateSpan::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.TemplateSpan*/>("kind"); }
	inline void _impl_js_jts_dTemplateSpan::kind(_js_jts_dSyntaxKind /*SyntaxKind.TemplateSpan*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dTemplateSpan::parent() noexcept { return _getProperty<_js_jts_dTemplateExpression>("parent"); }
	inline void _impl_js_jts_dTemplateSpan::parent(_js_jts_dTemplateExpression v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dTemplateSpan::expression() noexcept { return _getProperty<_js_jts_dExpression>("expression"); }
	inline void _impl_js_jts_dTemplateSpan::expression(_js_jts_dExpression v) noexcept { _setProperty("expression", v); }
	inline auto _impl_js_jts_dTemplateSpan::literal() noexcept { return _getProperty<js_union<_js_jts_dTemplateMiddle, _js_jts_dTemplateTail>>("literal"); }
	inline void _impl_js_jts_dTemplateSpan::literal(js_union<_js_jts_dTemplateMiddle, _js_jts_dTemplateTail> v) noexcept { _setProperty("literal", v); }
	inline auto _impl_js_jts_dParenthesizedExpression::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ParenthesizedExpression*/>("kind"); }
	inline void _impl_js_jts_dParenthesizedExpression::kind(_js_jts_dSyntaxKind /*SyntaxKind.ParenthesizedExpression*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dParenthesizedExpression::expression() noexcept { return _getProperty<_js_jts_dExpression>("expression"); }
	inline void _impl_js_jts_dParenthesizedExpression::expression(_js_jts_dExpression v) noexcept { _setProperty("expression", v); }
	inline auto _impl_js_jts_dArrayLiteralExpression::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ArrayLiteralExpression*/>("kind"); }
	inline void _impl_js_jts_dArrayLiteralExpression::kind(_js_jts_dSyntaxKind /*SyntaxKind.ArrayLiteralExpression*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dArrayLiteralExpression::elements() noexcept { return _getProperty<js_unknown /*flags=524288: NodeArray<Expression> (TypeReference=ts.NodeArray)*/>("elements"); }
	inline void _impl_js_jts_dArrayLiteralExpression::elements(js_unknown /*flags=524288: NodeArray<Expression> (TypeReference=ts.NodeArray)*/ v) noexcept { _setProperty("elements", v); }
	inline auto _impl_js_jts_dSpreadElement::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.SpreadElement*/>("kind"); }
	inline void _impl_js_jts_dSpreadElement::kind(_js_jts_dSyntaxKind /*SyntaxKind.SpreadElement*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dSpreadElement::parent() noexcept { return _getProperty<js_union<_js_jts_dArrayLiteralExpression, _js_jts_dCallExpression, _js_jts_dNewExpression>>("parent"); }
	inline void _impl_js_jts_dSpreadElement::parent(js_union<_js_jts_dArrayLiteralExpression, _js_jts_dCallExpression, _js_jts_dNewExpression> v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dSpreadElement::expression() noexcept { return _getProperty<_js_jts_dExpression>("expression"); }
	inline void _impl_js_jts_dSpreadElement::expression(_js_jts_dExpression v) noexcept { _setProperty("expression", v); }
	inline auto _impl_js_jts_dObjectLiteralExpressionBase::properties() noexcept { return _getProperty<js_unknown /*flags=524288: NodeArray<T> (TypeReference=ts.NodeArray)*/>("properties"); }
	inline void _impl_js_jts_dObjectLiteralExpressionBase::properties(js_unknown /*flags=524288: NodeArray<T> (TypeReference=ts.NodeArray)*/ v) noexcept { _setProperty("properties", v); }
	inline auto _impl_js_jts_dObjectLiteralExpression::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ObjectLiteralExpression*/>("kind"); }
	inline void _impl_js_jts_dObjectLiteralExpression::kind(_js_jts_dSyntaxKind /*SyntaxKind.ObjectLiteralExpression*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dPropertyAccessExpression::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.PropertyAccessExpression*/>("kind"); }
	inline void _impl_js_jts_dPropertyAccessExpression::kind(_js_jts_dSyntaxKind /*SyntaxKind.PropertyAccessExpression*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dPropertyAccessExpression::expression() noexcept { return _getProperty<_js_jts_dLeftHandSideExpression>("expression"); }
	inline void _impl_js_jts_dPropertyAccessExpression::expression(_js_jts_dLeftHandSideExpression v) noexcept { _setProperty("expression", v); }
	inline auto _impl_js_jts_dPropertyAccessExpression::name() noexcept { return _getProperty<_js_jts_dIdentifier>("name"); }
	inline void _impl_js_jts_dPropertyAccessExpression::name(_js_jts_dIdentifier v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dSuperPropertyAccessExpression::expression() noexcept { return _getProperty<_js_jts_dSuperExpression>("expression"); }
	inline void _impl_js_jts_dSuperPropertyAccessExpression::expression(_js_jts_dSuperExpression v) noexcept { _setProperty("expression", v); }
	inline auto _impl_js_jts_dPropertyAccessEntityNameExpression::expression() noexcept { return _getProperty<js_union<_js_jts_dIdentifier, _js_jts_dPropertyAccessEntityNameExpression>>("expression"); }
	inline void _impl_js_jts_dPropertyAccessEntityNameExpression::expression(js_union<_js_jts_dIdentifier, _js_jts_dPropertyAccessEntityNameExpression> v) noexcept { _setProperty("expression", v); }
	inline auto _impl_js_jts_dElementAccessExpression::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ElementAccessExpression*/>("kind"); }
	inline void _impl_js_jts_dElementAccessExpression::kind(_js_jts_dSyntaxKind /*SyntaxKind.ElementAccessExpression*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dElementAccessExpression::expression() noexcept { return _getProperty<_js_jts_dLeftHandSideExpression>("expression"); }
	inline void _impl_js_jts_dElementAccessExpression::expression(_js_jts_dLeftHandSideExpression v) noexcept { _setProperty("expression", v); }
	inline auto _impl_js_jts_dElementAccessExpression::argumentExpression() noexcept { return _getProperty<_js_jts_dExpression>("argumentExpression"); }
	inline void _impl_js_jts_dElementAccessExpression::argumentExpression(_js_jts_dExpression v) noexcept { _setProperty("argumentExpression", v); }
	inline auto _impl_js_jts_dSuperElementAccessExpression::expression() noexcept { return _getProperty<_js_jts_dSuperExpression>("expression"); }
	inline void _impl_js_jts_dSuperElementAccessExpression::expression(_js_jts_dSuperExpression v) noexcept { _setProperty("expression", v); }
	inline auto _impl_js_jts_dCallExpression::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.CallExpression*/>("kind"); }
	inline void _impl_js_jts_dCallExpression::kind(_js_jts_dSyntaxKind /*SyntaxKind.CallExpression*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dCallExpression::expression() noexcept { return _getProperty<_js_jts_dLeftHandSideExpression>("expression"); }
	inline void _impl_js_jts_dCallExpression::expression(_js_jts_dLeftHandSideExpression v) noexcept { _setProperty("expression", v); }
	inline auto _impl_js_jts_dCallExpression::arguments() noexcept { return _getProperty<js_unknown /*flags=524288: NodeArray<Expression> (TypeReference=ts.NodeArray)*/>("arguments"); }
	inline void _impl_js_jts_dCallExpression::arguments(js_unknown /*flags=524288: NodeArray<Expression> (TypeReference=ts.NodeArray)*/ v) noexcept { _setProperty("arguments", v); }
	inline auto _impl_js_jts_dSuperCall::expression() noexcept { return _getProperty<_js_jts_dSuperExpression>("expression"); }
	inline void _impl_js_jts_dSuperCall::expression(_js_jts_dSuperExpression v) noexcept { _setProperty("expression", v); }
	inline auto _impl_js_jts_dImportCall::expression() noexcept { return _getProperty<_js_jts_dImportExpression>("expression"); }
	inline void _impl_js_jts_dImportCall::expression(_js_jts_dImportExpression v) noexcept { _setProperty("expression", v); }
	inline auto _impl_js_jts_dExpressionWithTypeArguments::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ExpressionWithTypeArguments*/>("kind"); }
	inline void _impl_js_jts_dExpressionWithTypeArguments::kind(_js_jts_dSyntaxKind /*SyntaxKind.ExpressionWithTypeArguments*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dExpressionWithTypeArguments::parent() noexcept { return _getProperty<js_union<_js_jts_dHeritageClause, _js_jts_dJSDocAugmentsTag>>("parent"); }
	inline void _impl_js_jts_dExpressionWithTypeArguments::parent(js_union<_js_jts_dHeritageClause, _js_jts_dJSDocAugmentsTag> v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dExpressionWithTypeArguments::expression() noexcept { return _getProperty<_js_jts_dLeftHandSideExpression>("expression"); }
	inline void _impl_js_jts_dExpressionWithTypeArguments::expression(_js_jts_dLeftHandSideExpression v) noexcept { _setProperty("expression", v); }
	inline auto _impl_js_jts_dNewExpression::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.NewExpression*/>("kind"); }
	inline void _impl_js_jts_dNewExpression::kind(_js_jts_dSyntaxKind /*SyntaxKind.NewExpression*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dNewExpression::expression() noexcept { return _getProperty<_js_jts_dLeftHandSideExpression>("expression"); }
	inline void _impl_js_jts_dNewExpression::expression(_js_jts_dLeftHandSideExpression v) noexcept { _setProperty("expression", v); }
	inline auto _impl_js_jts_dTaggedTemplateExpression::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.TaggedTemplateExpression*/>("kind"); }
	inline void _impl_js_jts_dTaggedTemplateExpression::kind(_js_jts_dSyntaxKind /*SyntaxKind.TaggedTemplateExpression*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dTaggedTemplateExpression::tag() noexcept { return _getProperty<_js_jts_dLeftHandSideExpression>("tag"); }
	inline void _impl_js_jts_dTaggedTemplateExpression::tag(_js_jts_dLeftHandSideExpression v) noexcept { _setProperty("tag", v); }
	inline auto _impl_js_jts_dTaggedTemplateExpression::template_() noexcept { return _getProperty<js_union<_js_jts_dNoSubstitutionTemplateLiteral, _js_jts_dTemplateExpression>>("template"); }
	inline void _impl_js_jts_dTaggedTemplateExpression::template_(js_union<_js_jts_dNoSubstitutionTemplateLiteral, _js_jts_dTemplateExpression> v) noexcept { _setProperty("template", v); }
	inline auto _impl_js_jts_dAsExpression::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.AsExpression*/>("kind"); }
	inline void _impl_js_jts_dAsExpression::kind(_js_jts_dSyntaxKind /*SyntaxKind.AsExpression*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dAsExpression::expression() noexcept { return _getProperty<_js_jts_dExpression>("expression"); }
	inline void _impl_js_jts_dAsExpression::expression(_js_jts_dExpression v) noexcept { _setProperty("expression", v); }
	inline auto _impl_js_jts_dAsExpression::type() noexcept { return _getProperty<_js_jts_dTypeNode>("type"); }
	inline void _impl_js_jts_dAsExpression::type(_js_jts_dTypeNode v) noexcept { _setProperty("type", v); }
	inline auto _impl_js_jts_dTypeAssertion::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.TypeAssertionExpression*/>("kind"); }
	inline void _impl_js_jts_dTypeAssertion::kind(_js_jts_dSyntaxKind /*SyntaxKind.TypeAssertionExpression*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dTypeAssertion::type() noexcept { return _getProperty<_js_jts_dTypeNode>("type"); }
	inline void _impl_js_jts_dTypeAssertion::type(_js_jts_dTypeNode v) noexcept { _setProperty("type", v); }
	inline auto _impl_js_jts_dTypeAssertion::expression() noexcept { return _getProperty<_js_jts_dUnaryExpression>("expression"); }
	inline void _impl_js_jts_dTypeAssertion::expression(_js_jts_dUnaryExpression v) noexcept { _setProperty("expression", v); }
	inline auto _impl_js_jts_dNonNullExpression::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.NonNullExpression*/>("kind"); }
	inline void _impl_js_jts_dNonNullExpression::kind(_js_jts_dSyntaxKind /*SyntaxKind.NonNullExpression*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dNonNullExpression::expression() noexcept { return _getProperty<_js_jts_dExpression>("expression"); }
	inline void _impl_js_jts_dNonNullExpression::expression(_js_jts_dExpression v) noexcept { _setProperty("expression", v); }
	inline auto _impl_js_jts_dMetaProperty::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.MetaProperty*/>("kind"); }
	inline void _impl_js_jts_dMetaProperty::kind(_js_jts_dSyntaxKind /*SyntaxKind.MetaProperty*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dMetaProperty::keywordToken() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ImportKeyword*/>("keywordToken"); }
	inline void _impl_js_jts_dMetaProperty::keywordToken(_js_jts_dSyntaxKind /*SyntaxKind.ImportKeyword*/ v) noexcept { _setProperty("keywordToken", v); }
	inline auto _impl_js_jts_dMetaProperty::name() noexcept { return _getProperty<_js_jts_dIdentifier>("name"); }
	inline void _impl_js_jts_dMetaProperty::name(_js_jts_dIdentifier v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dJsxElement::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.JsxElement*/>("kind"); }
	inline void _impl_js_jts_dJsxElement::kind(_js_jts_dSyntaxKind /*SyntaxKind.JsxElement*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dJsxElement::openingElement() noexcept { return _getProperty<_js_jts_dJsxOpeningElement>("openingElement"); }
	inline void _impl_js_jts_dJsxElement::openingElement(_js_jts_dJsxOpeningElement v) noexcept { _setProperty("openingElement", v); }
	inline auto _impl_js_jts_dJsxElement::children() noexcept { return _getProperty<js_unknown /*flags=524288: NodeArray<JsxChild> (TypeReference=ts.NodeArray)*/>("children"); }
	inline void _impl_js_jts_dJsxElement::children(js_unknown /*flags=524288: NodeArray<JsxChild> (TypeReference=ts.NodeArray)*/ v) noexcept { _setProperty("children", v); }
	inline auto _impl_js_jts_dJsxElement::closingElement() noexcept { return _getProperty<_js_jts_dJsxClosingElement>("closingElement"); }
	inline void _impl_js_jts_dJsxElement::closingElement(_js_jts_dJsxClosingElement v) noexcept { _setProperty("closingElement", v); }
	inline auto _impl_js_jts_dJsxTagNamePropertyAccess::expression() noexcept { return _getProperty<js_union<_js_jts_dIdentifier, _js_jts_dJsxTagNamePropertyAccess, _js_jts_dThisExpression>>("expression"); }
	inline void _impl_js_jts_dJsxTagNamePropertyAccess::expression(js_union<_js_jts_dIdentifier, _js_jts_dJsxTagNamePropertyAccess, _js_jts_dThisExpression> v) noexcept { _setProperty("expression", v); }
	inline auto _impl_js_jts_dJsxAttributes::parent() noexcept { return _getProperty<js_union<_js_jts_dJsxOpeningElement, _js_jts_dJsxSelfClosingElement>>("parent"); }
	inline void _impl_js_jts_dJsxAttributes::parent(js_union<_js_jts_dJsxOpeningElement, _js_jts_dJsxSelfClosingElement> v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dJsxOpeningElement::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.JsxOpeningElement*/>("kind"); }
	inline void _impl_js_jts_dJsxOpeningElement::kind(_js_jts_dSyntaxKind /*SyntaxKind.JsxOpeningElement*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dJsxOpeningElement::parent() noexcept { return _getProperty<_js_jts_dJsxElement>("parent"); }
	inline void _impl_js_jts_dJsxOpeningElement::parent(_js_jts_dJsxElement v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dJsxOpeningElement::tagName() noexcept { return _getProperty<js_union<_js_jts_dIdentifier, _js_jts_dJsxTagNamePropertyAccess, _js_jts_dThisExpression>>("tagName"); }
	inline void _impl_js_jts_dJsxOpeningElement::tagName(js_union<_js_jts_dIdentifier, _js_jts_dJsxTagNamePropertyAccess, _js_jts_dThisExpression> v) noexcept { _setProperty("tagName", v); }
	inline auto _impl_js_jts_dJsxOpeningElement::attributes() noexcept { return _getProperty<_js_jts_dJsxAttributes>("attributes"); }
	inline void _impl_js_jts_dJsxOpeningElement::attributes(_js_jts_dJsxAttributes v) noexcept { _setProperty("attributes", v); }
	inline auto _impl_js_jts_dJsxSelfClosingElement::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.JsxSelfClosingElement*/>("kind"); }
	inline void _impl_js_jts_dJsxSelfClosingElement::kind(_js_jts_dSyntaxKind /*SyntaxKind.JsxSelfClosingElement*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dJsxSelfClosingElement::tagName() noexcept { return _getProperty<js_union<_js_jts_dIdentifier, _js_jts_dJsxTagNamePropertyAccess, _js_jts_dThisExpression>>("tagName"); }
	inline void _impl_js_jts_dJsxSelfClosingElement::tagName(js_union<_js_jts_dIdentifier, _js_jts_dJsxTagNamePropertyAccess, _js_jts_dThisExpression> v) noexcept { _setProperty("tagName", v); }
	inline auto _impl_js_jts_dJsxSelfClosingElement::attributes() noexcept { return _getProperty<_js_jts_dJsxAttributes>("attributes"); }
	inline void _impl_js_jts_dJsxSelfClosingElement::attributes(_js_jts_dJsxAttributes v) noexcept { _setProperty("attributes", v); }
	inline auto _impl_js_jts_dJsxFragment::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.JsxFragment*/>("kind"); }
	inline void _impl_js_jts_dJsxFragment::kind(_js_jts_dSyntaxKind /*SyntaxKind.JsxFragment*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dJsxFragment::openingFragment() noexcept { return _getProperty<_js_jts_dJsxOpeningFragment>("openingFragment"); }
	inline void _impl_js_jts_dJsxFragment::openingFragment(_js_jts_dJsxOpeningFragment v) noexcept { _setProperty("openingFragment", v); }
	inline auto _impl_js_jts_dJsxFragment::children() noexcept { return _getProperty<js_unknown /*flags=524288: NodeArray<JsxChild> (TypeReference=ts.NodeArray)*/>("children"); }
	inline void _impl_js_jts_dJsxFragment::children(js_unknown /*flags=524288: NodeArray<JsxChild> (TypeReference=ts.NodeArray)*/ v) noexcept { _setProperty("children", v); }
	inline auto _impl_js_jts_dJsxFragment::closingFragment() noexcept { return _getProperty<_js_jts_dJsxClosingFragment>("closingFragment"); }
	inline void _impl_js_jts_dJsxFragment::closingFragment(_js_jts_dJsxClosingFragment v) noexcept { _setProperty("closingFragment", v); }
	inline auto _impl_js_jts_dJsxOpeningFragment::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.JsxOpeningFragment*/>("kind"); }
	inline void _impl_js_jts_dJsxOpeningFragment::kind(_js_jts_dSyntaxKind /*SyntaxKind.JsxOpeningFragment*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dJsxOpeningFragment::parent() noexcept { return _getProperty<_js_jts_dJsxFragment>("parent"); }
	inline void _impl_js_jts_dJsxOpeningFragment::parent(_js_jts_dJsxFragment v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dJsxClosingFragment::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.JsxClosingFragment*/>("kind"); }
	inline void _impl_js_jts_dJsxClosingFragment::kind(_js_jts_dSyntaxKind /*SyntaxKind.JsxClosingFragment*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dJsxClosingFragment::parent() noexcept { return _getProperty<_js_jts_dJsxFragment>("parent"); }
	inline void _impl_js_jts_dJsxClosingFragment::parent(_js_jts_dJsxFragment v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dJsxAttribute::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.JsxAttribute*/>("kind"); }
	inline void _impl_js_jts_dJsxAttribute::kind(_js_jts_dSyntaxKind /*SyntaxKind.JsxAttribute*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dJsxAttribute::parent() noexcept { return _getProperty<_js_jts_dJsxAttributes>("parent"); }
	inline void _impl_js_jts_dJsxAttribute::parent(_js_jts_dJsxAttributes v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dJsxAttribute::name() noexcept { return _getProperty<_js_jts_dIdentifier>("name"); }
	inline void _impl_js_jts_dJsxAttribute::name(_js_jts_dIdentifier v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dJsxSpreadAttribute::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.JsxSpreadAttribute*/>("kind"); }
	inline void _impl_js_jts_dJsxSpreadAttribute::kind(_js_jts_dSyntaxKind /*SyntaxKind.JsxSpreadAttribute*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dJsxSpreadAttribute::parent() noexcept { return _getProperty<_js_jts_dJsxAttributes>("parent"); }
	inline void _impl_js_jts_dJsxSpreadAttribute::parent(_js_jts_dJsxAttributes v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dJsxSpreadAttribute::expression() noexcept { return _getProperty<_js_jts_dExpression>("expression"); }
	inline void _impl_js_jts_dJsxSpreadAttribute::expression(_js_jts_dExpression v) noexcept { _setProperty("expression", v); }
	inline auto _impl_js_jts_dJsxClosingElement::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.JsxClosingElement*/>("kind"); }
	inline void _impl_js_jts_dJsxClosingElement::kind(_js_jts_dSyntaxKind /*SyntaxKind.JsxClosingElement*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dJsxClosingElement::parent() noexcept { return _getProperty<_js_jts_dJsxElement>("parent"); }
	inline void _impl_js_jts_dJsxClosingElement::parent(_js_jts_dJsxElement v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dJsxClosingElement::tagName() noexcept { return _getProperty<js_union<_js_jts_dIdentifier, _js_jts_dJsxTagNamePropertyAccess, _js_jts_dThisExpression>>("tagName"); }
	inline void _impl_js_jts_dJsxClosingElement::tagName(js_union<_js_jts_dIdentifier, _js_jts_dJsxTagNamePropertyAccess, _js_jts_dThisExpression> v) noexcept { _setProperty("tagName", v); }
	inline auto _impl_js_jts_dJsxExpression::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.JsxExpression*/>("kind"); }
	inline void _impl_js_jts_dJsxExpression::kind(_js_jts_dSyntaxKind /*SyntaxKind.JsxExpression*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dJsxExpression::parent() noexcept { return _getProperty<js_union<_js_jts_dJsxAttribute, _js_jts_dJsxElement, _js_jts_dJsxSpreadAttribute>>("parent"); }
	inline void _impl_js_jts_dJsxExpression::parent(js_union<_js_jts_dJsxAttribute, _js_jts_dJsxElement, _js_jts_dJsxSpreadAttribute> v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dJsxText::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.JsxText*/>("kind"); }
	inline void _impl_js_jts_dJsxText::kind(_js_jts_dSyntaxKind /*SyntaxKind.JsxText*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dJsxText::containsOnlyTriviaWhiteSpaces() noexcept { return _getProperty<bool /*false*/>("containsOnlyTriviaWhiteSpaces"); }
	inline void _impl_js_jts_dJsxText::containsOnlyTriviaWhiteSpaces(bool /*false*/ v) noexcept { _setProperty("containsOnlyTriviaWhiteSpaces", v); }
	inline auto _impl_js_jts_dJsxText::parent() noexcept { return _getProperty<_js_jts_dJsxElement>("parent"); }
	inline void _impl_js_jts_dJsxText::parent(_js_jts_dJsxElement v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dNotEmittedStatement::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.NotEmittedStatement*/>("kind"); }
	inline void _impl_js_jts_dNotEmittedStatement::kind(_js_jts_dSyntaxKind /*SyntaxKind.NotEmittedStatement*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dCommaListExpression::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.CommaListExpression*/>("kind"); }
	inline void _impl_js_jts_dCommaListExpression::kind(_js_jts_dSyntaxKind /*SyntaxKind.CommaListExpression*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dCommaListExpression::elements() noexcept { return _getProperty<js_unknown /*flags=524288: NodeArray<Expression> (TypeReference=ts.NodeArray)*/>("elements"); }
	inline void _impl_js_jts_dCommaListExpression::elements(js_unknown /*flags=524288: NodeArray<Expression> (TypeReference=ts.NodeArray)*/ v) noexcept { _setProperty("elements", v); }
	inline auto _impl_js_jts_dEmptyStatement::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.EmptyStatement*/>("kind"); }
	inline void _impl_js_jts_dEmptyStatement::kind(_js_jts_dSyntaxKind /*SyntaxKind.EmptyStatement*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dDebuggerStatement::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.DebuggerStatement*/>("kind"); }
	inline void _impl_js_jts_dDebuggerStatement::kind(_js_jts_dSyntaxKind /*SyntaxKind.DebuggerStatement*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dMissingDeclaration::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.MissingDeclaration*/>("kind"); }
	inline void _impl_js_jts_dMissingDeclaration::kind(_js_jts_dSyntaxKind /*SyntaxKind.MissingDeclaration*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dBlock::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.Block*/>("kind"); }
	inline void _impl_js_jts_dBlock::kind(_js_jts_dSyntaxKind /*SyntaxKind.Block*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dBlock::statements() noexcept { return _getProperty<js_unknown /*flags=524288: NodeArray<Statement> (TypeReference=ts.NodeArray)*/>("statements"); }
	inline void _impl_js_jts_dBlock::statements(js_unknown /*flags=524288: NodeArray<Statement> (TypeReference=ts.NodeArray)*/ v) noexcept { _setProperty("statements", v); }
	inline auto _impl_js_jts_dVariableStatement::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.VariableStatement*/>("kind"); }
	inline void _impl_js_jts_dVariableStatement::kind(_js_jts_dSyntaxKind /*SyntaxKind.VariableStatement*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dVariableStatement::declarationList() noexcept { return _getProperty<_js_jts_dVariableDeclarationList>("declarationList"); }
	inline void _impl_js_jts_dVariableStatement::declarationList(_js_jts_dVariableDeclarationList v) noexcept { _setProperty("declarationList", v); }
	inline auto _impl_js_jts_dExpressionStatement::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ExpressionStatement*/>("kind"); }
	inline void _impl_js_jts_dExpressionStatement::kind(_js_jts_dSyntaxKind /*SyntaxKind.ExpressionStatement*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dExpressionStatement::expression() noexcept { return _getProperty<_js_jts_dExpression>("expression"); }
	inline void _impl_js_jts_dExpressionStatement::expression(_js_jts_dExpression v) noexcept { _setProperty("expression", v); }
	inline auto _impl_js_jts_dIfStatement::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.IfStatement*/>("kind"); }
	inline void _impl_js_jts_dIfStatement::kind(_js_jts_dSyntaxKind /*SyntaxKind.IfStatement*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dIfStatement::expression() noexcept { return _getProperty<_js_jts_dExpression>("expression"); }
	inline void _impl_js_jts_dIfStatement::expression(_js_jts_dExpression v) noexcept { _setProperty("expression", v); }
	inline auto _impl_js_jts_dIfStatement::thenStatement() noexcept { return _getProperty<_js_jts_dStatement>("thenStatement"); }
	inline void _impl_js_jts_dIfStatement::thenStatement(_js_jts_dStatement v) noexcept { _setProperty("thenStatement", v); }
	inline auto _impl_js_jts_dIterationStatement::statement() noexcept { return _getProperty<_js_jts_dStatement>("statement"); }
	inline void _impl_js_jts_dIterationStatement::statement(_js_jts_dStatement v) noexcept { _setProperty("statement", v); }
	inline auto _impl_js_jts_dDoStatement::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.DoStatement*/>("kind"); }
	inline void _impl_js_jts_dDoStatement::kind(_js_jts_dSyntaxKind /*SyntaxKind.DoStatement*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dDoStatement::expression() noexcept { return _getProperty<_js_jts_dExpression>("expression"); }
	inline void _impl_js_jts_dDoStatement::expression(_js_jts_dExpression v) noexcept { _setProperty("expression", v); }
	inline auto _impl_js_jts_dWhileStatement::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.WhileStatement*/>("kind"); }
	inline void _impl_js_jts_dWhileStatement::kind(_js_jts_dSyntaxKind /*SyntaxKind.WhileStatement*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dWhileStatement::expression() noexcept { return _getProperty<_js_jts_dExpression>("expression"); }
	inline void _impl_js_jts_dWhileStatement::expression(_js_jts_dExpression v) noexcept { _setProperty("expression", v); }
	inline auto _impl_js_jts_dForStatement::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ForStatement*/>("kind"); }
	inline void _impl_js_jts_dForStatement::kind(_js_jts_dSyntaxKind /*SyntaxKind.ForStatement*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dForInStatement::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ForInStatement*/>("kind"); }
	inline void _impl_js_jts_dForInStatement::kind(_js_jts_dSyntaxKind /*SyntaxKind.ForInStatement*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dForInStatement::initializer() noexcept { return _getProperty<js_union<_js_jts_dExpression, _js_jts_dVariableDeclarationList>>("initializer"); }
	inline void _impl_js_jts_dForInStatement::initializer(js_union<_js_jts_dExpression, _js_jts_dVariableDeclarationList> v) noexcept { _setProperty("initializer", v); }
	inline auto _impl_js_jts_dForInStatement::expression() noexcept { return _getProperty<_js_jts_dExpression>("expression"); }
	inline void _impl_js_jts_dForInStatement::expression(_js_jts_dExpression v) noexcept { _setProperty("expression", v); }
	inline auto _impl_js_jts_dForOfStatement::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ForOfStatement*/>("kind"); }
	inline void _impl_js_jts_dForOfStatement::kind(_js_jts_dSyntaxKind /*SyntaxKind.ForOfStatement*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dForOfStatement::initializer() noexcept { return _getProperty<js_union<_js_jts_dExpression, _js_jts_dVariableDeclarationList>>("initializer"); }
	inline void _impl_js_jts_dForOfStatement::initializer(js_union<_js_jts_dExpression, _js_jts_dVariableDeclarationList> v) noexcept { _setProperty("initializer", v); }
	inline auto _impl_js_jts_dForOfStatement::expression() noexcept { return _getProperty<_js_jts_dExpression>("expression"); }
	inline void _impl_js_jts_dForOfStatement::expression(_js_jts_dExpression v) noexcept { _setProperty("expression", v); }
	inline auto _impl_js_jts_dBreakStatement::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.BreakStatement*/>("kind"); }
	inline void _impl_js_jts_dBreakStatement::kind(_js_jts_dSyntaxKind /*SyntaxKind.BreakStatement*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dContinueStatement::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ContinueStatement*/>("kind"); }
	inline void _impl_js_jts_dContinueStatement::kind(_js_jts_dSyntaxKind /*SyntaxKind.ContinueStatement*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dReturnStatement::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ReturnStatement*/>("kind"); }
	inline void _impl_js_jts_dReturnStatement::kind(_js_jts_dSyntaxKind /*SyntaxKind.ReturnStatement*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dWithStatement::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.WithStatement*/>("kind"); }
	inline void _impl_js_jts_dWithStatement::kind(_js_jts_dSyntaxKind /*SyntaxKind.WithStatement*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dWithStatement::expression() noexcept { return _getProperty<_js_jts_dExpression>("expression"); }
	inline void _impl_js_jts_dWithStatement::expression(_js_jts_dExpression v) noexcept { _setProperty("expression", v); }
	inline auto _impl_js_jts_dWithStatement::statement() noexcept { return _getProperty<_js_jts_dStatement>("statement"); }
	inline void _impl_js_jts_dWithStatement::statement(_js_jts_dStatement v) noexcept { _setProperty("statement", v); }
	inline auto _impl_js_jts_dSwitchStatement::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.SwitchStatement*/>("kind"); }
	inline void _impl_js_jts_dSwitchStatement::kind(_js_jts_dSyntaxKind /*SyntaxKind.SwitchStatement*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dSwitchStatement::expression() noexcept { return _getProperty<_js_jts_dExpression>("expression"); }
	inline void _impl_js_jts_dSwitchStatement::expression(_js_jts_dExpression v) noexcept { _setProperty("expression", v); }
	inline auto _impl_js_jts_dSwitchStatement::caseBlock() noexcept { return _getProperty<_js_jts_dCaseBlock>("caseBlock"); }
	inline void _impl_js_jts_dSwitchStatement::caseBlock(_js_jts_dCaseBlock v) noexcept { _setProperty("caseBlock", v); }
	inline auto _impl_js_jts_dCaseBlock::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.CaseBlock*/>("kind"); }
	inline void _impl_js_jts_dCaseBlock::kind(_js_jts_dSyntaxKind /*SyntaxKind.CaseBlock*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dCaseBlock::parent() noexcept { return _getProperty<_js_jts_dSwitchStatement>("parent"); }
	inline void _impl_js_jts_dCaseBlock::parent(_js_jts_dSwitchStatement v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dCaseBlock::clauses() noexcept { return _getProperty<js_unknown /*flags=524288: NodeArray<CaseOrDefaultClause> (TypeReference=ts.NodeArray)*/>("clauses"); }
	inline void _impl_js_jts_dCaseBlock::clauses(js_unknown /*flags=524288: NodeArray<CaseOrDefaultClause> (TypeReference=ts.NodeArray)*/ v) noexcept { _setProperty("clauses", v); }
	inline auto _impl_js_jts_dCaseClause::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.CaseClause*/>("kind"); }
	inline void _impl_js_jts_dCaseClause::kind(_js_jts_dSyntaxKind /*SyntaxKind.CaseClause*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dCaseClause::parent() noexcept { return _getProperty<_js_jts_dCaseBlock>("parent"); }
	inline void _impl_js_jts_dCaseClause::parent(_js_jts_dCaseBlock v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dCaseClause::expression() noexcept { return _getProperty<_js_jts_dExpression>("expression"); }
	inline void _impl_js_jts_dCaseClause::expression(_js_jts_dExpression v) noexcept { _setProperty("expression", v); }
	inline auto _impl_js_jts_dCaseClause::statements() noexcept { return _getProperty<js_unknown /*flags=524288: NodeArray<Statement> (TypeReference=ts.NodeArray)*/>("statements"); }
	inline void _impl_js_jts_dCaseClause::statements(js_unknown /*flags=524288: NodeArray<Statement> (TypeReference=ts.NodeArray)*/ v) noexcept { _setProperty("statements", v); }
	inline auto _impl_js_jts_dDefaultClause::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.DefaultClause*/>("kind"); }
	inline void _impl_js_jts_dDefaultClause::kind(_js_jts_dSyntaxKind /*SyntaxKind.DefaultClause*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dDefaultClause::parent() noexcept { return _getProperty<_js_jts_dCaseBlock>("parent"); }
	inline void _impl_js_jts_dDefaultClause::parent(_js_jts_dCaseBlock v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dDefaultClause::statements() noexcept { return _getProperty<js_unknown /*flags=524288: NodeArray<Statement> (TypeReference=ts.NodeArray)*/>("statements"); }
	inline void _impl_js_jts_dDefaultClause::statements(js_unknown /*flags=524288: NodeArray<Statement> (TypeReference=ts.NodeArray)*/ v) noexcept { _setProperty("statements", v); }
	inline auto _impl_js_jts_dLabeledStatement::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.LabeledStatement*/>("kind"); }
	inline void _impl_js_jts_dLabeledStatement::kind(_js_jts_dSyntaxKind /*SyntaxKind.LabeledStatement*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dLabeledStatement::label() noexcept { return _getProperty<_js_jts_dIdentifier>("label"); }
	inline void _impl_js_jts_dLabeledStatement::label(_js_jts_dIdentifier v) noexcept { _setProperty("label", v); }
	inline auto _impl_js_jts_dLabeledStatement::statement() noexcept { return _getProperty<_js_jts_dStatement>("statement"); }
	inline void _impl_js_jts_dLabeledStatement::statement(_js_jts_dStatement v) noexcept { _setProperty("statement", v); }
	inline auto _impl_js_jts_dThrowStatement::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ThrowStatement*/>("kind"); }
	inline void _impl_js_jts_dThrowStatement::kind(_js_jts_dSyntaxKind /*SyntaxKind.ThrowStatement*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dTryStatement::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.TryStatement*/>("kind"); }
	inline void _impl_js_jts_dTryStatement::kind(_js_jts_dSyntaxKind /*SyntaxKind.TryStatement*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dTryStatement::tryBlock() noexcept { return _getProperty<_js_jts_dBlock>("tryBlock"); }
	inline void _impl_js_jts_dTryStatement::tryBlock(_js_jts_dBlock v) noexcept { _setProperty("tryBlock", v); }
	inline auto _impl_js_jts_dCatchClause::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.CatchClause*/>("kind"); }
	inline void _impl_js_jts_dCatchClause::kind(_js_jts_dSyntaxKind /*SyntaxKind.CatchClause*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dCatchClause::parent() noexcept { return _getProperty<_js_jts_dTryStatement>("parent"); }
	inline void _impl_js_jts_dCatchClause::parent(_js_jts_dTryStatement v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dCatchClause::block() noexcept { return _getProperty<_js_jts_dBlock>("block"); }
	inline void _impl_js_jts_dCatchClause::block(_js_jts_dBlock v) noexcept { _setProperty("block", v); }
	inline auto _impl_js_jts_dClassLikeDeclarationBase::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ClassExpression*/>("kind"); }
	inline void _impl_js_jts_dClassLikeDeclarationBase::kind(_js_jts_dSyntaxKind /*SyntaxKind.ClassExpression*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dClassLikeDeclarationBase::members() noexcept { return _getProperty<js_unknown /*flags=524288: NodeArray<ClassElement> (TypeReference=ts.NodeArray)*/>("members"); }
	inline void _impl_js_jts_dClassLikeDeclarationBase::members(js_unknown /*flags=524288: NodeArray<ClassElement> (TypeReference=ts.NodeArray)*/ v) noexcept { _setProperty("members", v); }
	inline auto _impl_js_jts_dClassDeclaration::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ClassDeclaration*/>("kind"); }
	inline void _impl_js_jts_dClassDeclaration::kind(_js_jts_dSyntaxKind /*SyntaxKind.ClassDeclaration*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dClassExpression::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ClassExpression*/>("kind"); }
	inline void _impl_js_jts_dClassExpression::kind(_js_jts_dSyntaxKind /*SyntaxKind.ClassExpression*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dInterfaceDeclaration::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.InterfaceDeclaration*/>("kind"); }
	inline void _impl_js_jts_dInterfaceDeclaration::kind(_js_jts_dSyntaxKind /*SyntaxKind.InterfaceDeclaration*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dInterfaceDeclaration::name() noexcept { return _getProperty<_js_jts_dIdentifier>("name"); }
	inline void _impl_js_jts_dInterfaceDeclaration::name(_js_jts_dIdentifier v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dInterfaceDeclaration::members() noexcept { return _getProperty<js_unknown /*flags=524288: NodeArray<TypeElement> (TypeReference=ts.NodeArray)*/>("members"); }
	inline void _impl_js_jts_dInterfaceDeclaration::members(js_unknown /*flags=524288: NodeArray<TypeElement> (TypeReference=ts.NodeArray)*/ v) noexcept { _setProperty("members", v); }
	inline auto _impl_js_jts_dHeritageClause::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.HeritageClause*/>("kind"); }
	inline void _impl_js_jts_dHeritageClause::kind(_js_jts_dSyntaxKind /*SyntaxKind.HeritageClause*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dHeritageClause::parent() noexcept { return _getProperty<js_union<_js_jts_dClassDeclaration, _js_jts_dClassExpression, _js_jts_dInterfaceDeclaration>>("parent"); }
	inline void _impl_js_jts_dHeritageClause::parent(js_union<_js_jts_dClassDeclaration, _js_jts_dClassExpression, _js_jts_dInterfaceDeclaration> v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dHeritageClause::token() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ExtendsKeyword*/>("token"); }
	inline void _impl_js_jts_dHeritageClause::token(_js_jts_dSyntaxKind /*SyntaxKind.ExtendsKeyword*/ v) noexcept { _setProperty("token", v); }
	inline auto _impl_js_jts_dHeritageClause::types() noexcept { return _getProperty<js_unknown /*flags=524288: NodeArray<ExpressionWithTypeArguments> (TypeReference=ts.NodeArray)*/>("types"); }
	inline void _impl_js_jts_dHeritageClause::types(js_unknown /*flags=524288: NodeArray<ExpressionWithTypeArguments> (TypeReference=ts.NodeArray)*/ v) noexcept { _setProperty("types", v); }
	inline auto _impl_js_jts_dTypeAliasDeclaration::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.TypeAliasDeclaration*/>("kind"); }
	inline void _impl_js_jts_dTypeAliasDeclaration::kind(_js_jts_dSyntaxKind /*SyntaxKind.TypeAliasDeclaration*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dTypeAliasDeclaration::name() noexcept { return _getProperty<_js_jts_dIdentifier>("name"); }
	inline void _impl_js_jts_dTypeAliasDeclaration::name(_js_jts_dIdentifier v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dTypeAliasDeclaration::type() noexcept { return _getProperty<_js_jts_dTypeNode>("type"); }
	inline void _impl_js_jts_dTypeAliasDeclaration::type(_js_jts_dTypeNode v) noexcept { _setProperty("type", v); }
	inline auto _impl_js_jts_dEnumMember::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.EnumMember*/>("kind"); }
	inline void _impl_js_jts_dEnumMember::kind(_js_jts_dSyntaxKind /*SyntaxKind.EnumMember*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dEnumMember::parent() noexcept { return _getProperty<_js_jts_dEnumDeclaration>("parent"); }
	inline void _impl_js_jts_dEnumMember::parent(_js_jts_dEnumDeclaration v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dEnumMember::name() noexcept { return _getProperty<js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral>>("name"); }
	inline void _impl_js_jts_dEnumMember::name(js_union<_js_jts_dComputedPropertyName, _js_jts_dIdentifier, _js_jts_dNumericLiteral, _js_jts_dStringLiteral> v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dEnumDeclaration::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.EnumDeclaration*/>("kind"); }
	inline void _impl_js_jts_dEnumDeclaration::kind(_js_jts_dSyntaxKind /*SyntaxKind.EnumDeclaration*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dEnumDeclaration::name() noexcept { return _getProperty<_js_jts_dIdentifier>("name"); }
	inline void _impl_js_jts_dEnumDeclaration::name(_js_jts_dIdentifier v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dEnumDeclaration::members() noexcept { return _getProperty<js_unknown /*flags=524288: NodeArray<EnumMember> (TypeReference=ts.NodeArray)*/>("members"); }
	inline void _impl_js_jts_dEnumDeclaration::members(js_unknown /*flags=524288: NodeArray<EnumMember> (TypeReference=ts.NodeArray)*/ v) noexcept { _setProperty("members", v); }
	inline auto _impl_js_jts_dModuleDeclaration::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ModuleDeclaration*/>("kind"); }
	inline void _impl_js_jts_dModuleDeclaration::kind(_js_jts_dSyntaxKind /*SyntaxKind.ModuleDeclaration*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dModuleDeclaration::parent() noexcept { return _getProperty<js_union<_js_jts_dIdentifier, _js_jts_dJSDocNamespaceDeclaration, _js_jts_dModuleBlock, _js_jts_dNamespaceDeclaration, _js_jts_dSourceFile>>("parent"); }
	inline void _impl_js_jts_dModuleDeclaration::parent(js_union<_js_jts_dIdentifier, _js_jts_dJSDocNamespaceDeclaration, _js_jts_dModuleBlock, _js_jts_dNamespaceDeclaration, _js_jts_dSourceFile> v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dModuleDeclaration::name() noexcept { return _getProperty<js_union<_js_jts_dIdentifier, _js_jts_dStringLiteral>>("name"); }
	inline void _impl_js_jts_dModuleDeclaration::name(js_union<_js_jts_dIdentifier, _js_jts_dStringLiteral> v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dNamespaceDeclaration::name() noexcept { return _getProperty<_js_jts_dIdentifier>("name"); }
	inline void _impl_js_jts_dNamespaceDeclaration::name(_js_jts_dIdentifier v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dNamespaceDeclaration::body() noexcept { return _getProperty<js_union<_js_jts_dModuleBlock, _js_jts_dNamespaceDeclaration>>("body"); }
	inline void _impl_js_jts_dNamespaceDeclaration::body(js_union<_js_jts_dModuleBlock, _js_jts_dNamespaceDeclaration> v) noexcept { _setProperty("body", v); }
	inline auto _impl_js_jts_dJSDocNamespaceDeclaration::name() noexcept { return _getProperty<_js_jts_dIdentifier>("name"); }
	inline void _impl_js_jts_dJSDocNamespaceDeclaration::name(_js_jts_dIdentifier v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dModuleBlock::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ModuleBlock*/>("kind"); }
	inline void _impl_js_jts_dModuleBlock::kind(_js_jts_dSyntaxKind /*SyntaxKind.ModuleBlock*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dModuleBlock::parent() noexcept { return _getProperty<_js_jts_dModuleDeclaration>("parent"); }
	inline void _impl_js_jts_dModuleBlock::parent(_js_jts_dModuleDeclaration v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dModuleBlock::statements() noexcept { return _getProperty<js_unknown /*flags=524288: NodeArray<Statement> (TypeReference=ts.NodeArray)*/>("statements"); }
	inline void _impl_js_jts_dModuleBlock::statements(js_unknown /*flags=524288: NodeArray<Statement> (TypeReference=ts.NodeArray)*/ v) noexcept { _setProperty("statements", v); }
	inline auto _impl_js_jts_dImportEqualsDeclaration::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ImportEqualsDeclaration*/>("kind"); }
	inline void _impl_js_jts_dImportEqualsDeclaration::kind(_js_jts_dSyntaxKind /*SyntaxKind.ImportEqualsDeclaration*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dImportEqualsDeclaration::parent() noexcept { return _getProperty<js_union<_js_jts_dModuleBlock, _js_jts_dSourceFile>>("parent"); }
	inline void _impl_js_jts_dImportEqualsDeclaration::parent(js_union<_js_jts_dModuleBlock, _js_jts_dSourceFile> v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dImportEqualsDeclaration::name() noexcept { return _getProperty<_js_jts_dIdentifier>("name"); }
	inline void _impl_js_jts_dImportEqualsDeclaration::name(_js_jts_dIdentifier v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dImportEqualsDeclaration::moduleReference() noexcept { return _getProperty<js_union<_js_jts_dExternalModuleReference, _js_jts_dIdentifier, _js_jts_dQualifiedName>>("moduleReference"); }
	inline void _impl_js_jts_dImportEqualsDeclaration::moduleReference(js_union<_js_jts_dExternalModuleReference, _js_jts_dIdentifier, _js_jts_dQualifiedName> v) noexcept { _setProperty("moduleReference", v); }
	inline auto _impl_js_jts_dExternalModuleReference::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ExternalModuleReference*/>("kind"); }
	inline void _impl_js_jts_dExternalModuleReference::kind(_js_jts_dSyntaxKind /*SyntaxKind.ExternalModuleReference*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dExternalModuleReference::parent() noexcept { return _getProperty<_js_jts_dImportEqualsDeclaration>("parent"); }
	inline void _impl_js_jts_dExternalModuleReference::parent(_js_jts_dImportEqualsDeclaration v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dExternalModuleReference::expression() noexcept { return _getProperty<_js_jts_dExpression>("expression"); }
	inline void _impl_js_jts_dExternalModuleReference::expression(_js_jts_dExpression v) noexcept { _setProperty("expression", v); }
	inline auto _impl_js_jts_dImportDeclaration::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ImportDeclaration*/>("kind"); }
	inline void _impl_js_jts_dImportDeclaration::kind(_js_jts_dSyntaxKind /*SyntaxKind.ImportDeclaration*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dImportDeclaration::parent() noexcept { return _getProperty<js_union<_js_jts_dModuleBlock, _js_jts_dSourceFile>>("parent"); }
	inline void _impl_js_jts_dImportDeclaration::parent(js_union<_js_jts_dModuleBlock, _js_jts_dSourceFile> v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dImportDeclaration::moduleSpecifier() noexcept { return _getProperty<_js_jts_dExpression>("moduleSpecifier"); }
	inline void _impl_js_jts_dImportDeclaration::moduleSpecifier(_js_jts_dExpression v) noexcept { _setProperty("moduleSpecifier", v); }
	inline auto _impl_js_jts_dImportClause::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ImportClause*/>("kind"); }
	inline void _impl_js_jts_dImportClause::kind(_js_jts_dSyntaxKind /*SyntaxKind.ImportClause*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dImportClause::parent() noexcept { return _getProperty<_js_jts_dImportDeclaration>("parent"); }
	inline void _impl_js_jts_dImportClause::parent(_js_jts_dImportDeclaration v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dNamespaceImport::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.NamespaceImport*/>("kind"); }
	inline void _impl_js_jts_dNamespaceImport::kind(_js_jts_dSyntaxKind /*SyntaxKind.NamespaceImport*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dNamespaceImport::parent() noexcept { return _getProperty<_js_jts_dImportClause>("parent"); }
	inline void _impl_js_jts_dNamespaceImport::parent(_js_jts_dImportClause v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dNamespaceImport::name() noexcept { return _getProperty<_js_jts_dIdentifier>("name"); }
	inline void _impl_js_jts_dNamespaceImport::name(_js_jts_dIdentifier v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dNamespaceExportDeclaration::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.NamespaceExportDeclaration*/>("kind"); }
	inline void _impl_js_jts_dNamespaceExportDeclaration::kind(_js_jts_dSyntaxKind /*SyntaxKind.NamespaceExportDeclaration*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dNamespaceExportDeclaration::name() noexcept { return _getProperty<_js_jts_dIdentifier>("name"); }
	inline void _impl_js_jts_dNamespaceExportDeclaration::name(_js_jts_dIdentifier v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dExportDeclaration::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ExportDeclaration*/>("kind"); }
	inline void _impl_js_jts_dExportDeclaration::kind(_js_jts_dSyntaxKind /*SyntaxKind.ExportDeclaration*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dExportDeclaration::parent() noexcept { return _getProperty<js_union<_js_jts_dModuleBlock, _js_jts_dSourceFile>>("parent"); }
	inline void _impl_js_jts_dExportDeclaration::parent(js_union<_js_jts_dModuleBlock, _js_jts_dSourceFile> v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dNamedImports::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.NamedImports*/>("kind"); }
	inline void _impl_js_jts_dNamedImports::kind(_js_jts_dSyntaxKind /*SyntaxKind.NamedImports*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dNamedImports::parent() noexcept { return _getProperty<_js_jts_dImportClause>("parent"); }
	inline void _impl_js_jts_dNamedImports::parent(_js_jts_dImportClause v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dNamedImports::elements() noexcept { return _getProperty<js_unknown /*flags=524288: NodeArray<ImportSpecifier> (TypeReference=ts.NodeArray)*/>("elements"); }
	inline void _impl_js_jts_dNamedImports::elements(js_unknown /*flags=524288: NodeArray<ImportSpecifier> (TypeReference=ts.NodeArray)*/ v) noexcept { _setProperty("elements", v); }
	inline auto _impl_js_jts_dNamedExports::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.NamedExports*/>("kind"); }
	inline void _impl_js_jts_dNamedExports::kind(_js_jts_dSyntaxKind /*SyntaxKind.NamedExports*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dNamedExports::parent() noexcept { return _getProperty<_js_jts_dExportDeclaration>("parent"); }
	inline void _impl_js_jts_dNamedExports::parent(_js_jts_dExportDeclaration v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dNamedExports::elements() noexcept { return _getProperty<js_unknown /*flags=524288: NodeArray<ExportSpecifier> (TypeReference=ts.NodeArray)*/>("elements"); }
	inline void _impl_js_jts_dNamedExports::elements(js_unknown /*flags=524288: NodeArray<ExportSpecifier> (TypeReference=ts.NodeArray)*/ v) noexcept { _setProperty("elements", v); }
	inline auto _impl_js_jts_dImportSpecifier::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ImportSpecifier*/>("kind"); }
	inline void _impl_js_jts_dImportSpecifier::kind(_js_jts_dSyntaxKind /*SyntaxKind.ImportSpecifier*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dImportSpecifier::parent() noexcept { return _getProperty<_js_jts_dNamedImports>("parent"); }
	inline void _impl_js_jts_dImportSpecifier::parent(_js_jts_dNamedImports v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dImportSpecifier::name() noexcept { return _getProperty<_js_jts_dIdentifier>("name"); }
	inline void _impl_js_jts_dImportSpecifier::name(_js_jts_dIdentifier v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dExportSpecifier::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ExportSpecifier*/>("kind"); }
	inline void _impl_js_jts_dExportSpecifier::kind(_js_jts_dSyntaxKind /*SyntaxKind.ExportSpecifier*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dExportSpecifier::parent() noexcept { return _getProperty<_js_jts_dNamedExports>("parent"); }
	inline void _impl_js_jts_dExportSpecifier::parent(_js_jts_dNamedExports v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dExportSpecifier::name() noexcept { return _getProperty<_js_jts_dIdentifier>("name"); }
	inline void _impl_js_jts_dExportSpecifier::name(_js_jts_dIdentifier v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dExportAssignment::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.ExportAssignment*/>("kind"); }
	inline void _impl_js_jts_dExportAssignment::kind(_js_jts_dSyntaxKind /*SyntaxKind.ExportAssignment*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dExportAssignment::parent() noexcept { return _getProperty<_js_jts_dSourceFile>("parent"); }
	inline void _impl_js_jts_dExportAssignment::parent(_js_jts_dSourceFile v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dExportAssignment::expression() noexcept { return _getProperty<_js_jts_dExpression>("expression"); }
	inline void _impl_js_jts_dExportAssignment::expression(_js_jts_dExpression v) noexcept { _setProperty("expression", v); }
	inline auto _impl_js_jts_dFileReference::fileName() noexcept { return _getProperty<js_string>("fileName"); }
	inline void _impl_js_jts_dFileReference::fileName(js_string v) noexcept { _setProperty("fileName", v); }
	inline auto _impl_js_jts_dCheckJsDirective::enabled() noexcept { return _getProperty<bool /*false*/>("enabled"); }
	inline void _impl_js_jts_dCheckJsDirective::enabled(bool /*false*/ v) noexcept { _setProperty("enabled", v); }
	inline auto _impl_js_jts_dCommentRange::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.SingleLineCommentTrivia*/>("kind"); }
	inline void _impl_js_jts_dCommentRange::kind(_js_jts_dSyntaxKind /*SyntaxKind.SingleLineCommentTrivia*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dSynthesizedComment::text() noexcept { return _getProperty<js_string>("text"); }
	inline void _impl_js_jts_dSynthesizedComment::text(js_string v) noexcept { _setProperty("text", v); }
	inline auto _impl_js_jts_dSynthesizedComment::pos() noexcept { return _getProperty<double /*-1*/>("pos"); }
	inline void _impl_js_jts_dSynthesizedComment::pos(double /*-1*/ v) noexcept { _setProperty("pos", v); }
	inline auto _impl_js_jts_dSynthesizedComment::end() noexcept { return _getProperty<double /*-1*/>("end"); }
	inline void _impl_js_jts_dSynthesizedComment::end(double /*-1*/ v) noexcept { _setProperty("end", v); }
	inline auto _impl_js_jts_dJSDocTypeExpression::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.JSDocTypeExpression*/>("kind"); }
	inline void _impl_js_jts_dJSDocTypeExpression::kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocTypeExpression*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dJSDocTypeExpression::type() noexcept { return _getProperty<_js_jts_dTypeNode>("type"); }
	inline void _impl_js_jts_dJSDocTypeExpression::type(_js_jts_dTypeNode v) noexcept { _setProperty("type", v); }
	inline auto _impl_js_jts_dJSDocType::_jsDocTypeBrand() noexcept { return _getProperty<js_unknown>("_jsDocTypeBrand"); }
	inline void _impl_js_jts_dJSDocType::_jsDocTypeBrand(js_unknown v) noexcept { _setProperty("_jsDocTypeBrand", v); }
	inline auto _impl_js_jts_dJSDocAllType::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.JSDocAllType*/>("kind"); }
	inline void _impl_js_jts_dJSDocAllType::kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocAllType*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dJSDocUnknownType::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.JSDocUnknownType*/>("kind"); }
	inline void _impl_js_jts_dJSDocUnknownType::kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocUnknownType*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dJSDocNonNullableType::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.JSDocNonNullableType*/>("kind"); }
	inline void _impl_js_jts_dJSDocNonNullableType::kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocNonNullableType*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dJSDocNonNullableType::type() noexcept { return _getProperty<_js_jts_dTypeNode>("type"); }
	inline void _impl_js_jts_dJSDocNonNullableType::type(_js_jts_dTypeNode v) noexcept { _setProperty("type", v); }
	inline auto _impl_js_jts_dJSDocNullableType::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.JSDocNullableType*/>("kind"); }
	inline void _impl_js_jts_dJSDocNullableType::kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocNullableType*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dJSDocNullableType::type() noexcept { return _getProperty<_js_jts_dTypeNode>("type"); }
	inline void _impl_js_jts_dJSDocNullableType::type(_js_jts_dTypeNode v) noexcept { _setProperty("type", v); }
	inline auto _impl_js_jts_dJSDocOptionalType::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.JSDocOptionalType*/>("kind"); }
	inline void _impl_js_jts_dJSDocOptionalType::kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocOptionalType*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dJSDocOptionalType::type() noexcept { return _getProperty<_js_jts_dTypeNode>("type"); }
	inline void _impl_js_jts_dJSDocOptionalType::type(_js_jts_dTypeNode v) noexcept { _setProperty("type", v); }
	inline auto _impl_js_jts_dJSDocFunctionType::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.JSDocFunctionType*/>("kind"); }
	inline void _impl_js_jts_dJSDocFunctionType::kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocFunctionType*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dJSDocVariadicType::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.JSDocVariadicType*/>("kind"); }
	inline void _impl_js_jts_dJSDocVariadicType::kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocVariadicType*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dJSDocVariadicType::type() noexcept { return _getProperty<_js_jts_dTypeNode>("type"); }
	inline void _impl_js_jts_dJSDocVariadicType::type(_js_jts_dTypeNode v) noexcept { _setProperty("type", v); }
	inline auto _impl_js_jts_dJSDoc::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.JSDocComment*/>("kind"); }
	inline void _impl_js_jts_dJSDoc::kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocComment*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dJSDoc::parent() noexcept { return _getProperty<js_unknown /*flags=1048576: HasJSDoc ()*/>("parent"); }
	inline void _impl_js_jts_dJSDoc::parent(js_unknown /*flags=1048576: HasJSDoc ()*/ v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dJSDocTag::parent() noexcept { return _getProperty<js_union<_js_jts_dJSDoc, _js_jts_dJSDocTypeLiteral>>("parent"); }
	inline void _impl_js_jts_dJSDocTag::parent(js_union<_js_jts_dJSDoc, _js_jts_dJSDocTypeLiteral> v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dJSDocTag::tagName() noexcept { return _getProperty<_js_jts_dIdentifier>("tagName"); }
	inline void _impl_js_jts_dJSDocTag::tagName(_js_jts_dIdentifier v) noexcept { _setProperty("tagName", v); }
	inline auto _impl_js_jts_dJSDocUnknownTag::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.JSDocTag*/>("kind"); }
	inline void _impl_js_jts_dJSDocUnknownTag::kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocTag*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dJSDocAugmentsTag::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.JSDocAugmentsTag*/>("kind"); }
	inline void _impl_js_jts_dJSDocAugmentsTag::kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocAugmentsTag*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dJSDocAugmentsTag::class_() noexcept { return _getProperty<js_unknown /*flags=2097152: ExpressionWithTypeArguments & { expression: EntityNameExpression; } ()*/>("class"); }
	inline void _impl_js_jts_dJSDocAugmentsTag::class_(js_unknown /*flags=2097152: ExpressionWithTypeArguments & { expression: EntityNameExpression; } ()*/ v) noexcept { _setProperty("class", v); }
	inline auto _impl_js_jts_dJSDocClassTag::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.JSDocClassTag*/>("kind"); }
	inline void _impl_js_jts_dJSDocClassTag::kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocClassTag*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dJSDocEnumTag::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.JSDocEnumTag*/>("kind"); }
	inline void _impl_js_jts_dJSDocEnumTag::kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocEnumTag*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dJSDocThisTag::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.JSDocThisTag*/>("kind"); }
	inline void _impl_js_jts_dJSDocThisTag::kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocThisTag*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dJSDocTemplateTag::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.JSDocTemplateTag*/>("kind"); }
	inline void _impl_js_jts_dJSDocTemplateTag::kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocTemplateTag*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dJSDocTemplateTag::constraint() noexcept { return _getProperty<js_union<_js_jts_dJSDocTypeExpression, js_undefined>>("constraint"); }
	inline void _impl_js_jts_dJSDocTemplateTag::constraint(js_union<_js_jts_dJSDocTypeExpression, js_undefined> v) noexcept { _setProperty("constraint", v); }
	inline auto _impl_js_jts_dJSDocTemplateTag::typeParameters() noexcept { return _getProperty<js_unknown /*flags=524288: NodeArray<TypeParameterDeclaration> (TypeReference=ts.NodeArray)*/>("typeParameters"); }
	inline void _impl_js_jts_dJSDocTemplateTag::typeParameters(js_unknown /*flags=524288: NodeArray<TypeParameterDeclaration> (TypeReference=ts.NodeArray)*/ v) noexcept { _setProperty("typeParameters", v); }
	inline auto _impl_js_jts_dJSDocReturnTag::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.JSDocReturnTag*/>("kind"); }
	inline void _impl_js_jts_dJSDocReturnTag::kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocReturnTag*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dJSDocTypeTag::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.JSDocTypeTag*/>("kind"); }
	inline void _impl_js_jts_dJSDocTypeTag::kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocTypeTag*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dJSDocTypeTag::typeExpression() noexcept { return _getProperty<_js_jts_dJSDocTypeExpression>("typeExpression"); }
	inline void _impl_js_jts_dJSDocTypeTag::typeExpression(_js_jts_dJSDocTypeExpression v) noexcept { _setProperty("typeExpression", v); }
	inline auto _impl_js_jts_dJSDocTypedefTag::parent() noexcept { return _getProperty<_js_jts_dJSDoc>("parent"); }
	inline void _impl_js_jts_dJSDocTypedefTag::parent(_js_jts_dJSDoc v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dJSDocTypedefTag::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.JSDocTypedefTag*/>("kind"); }
	inline void _impl_js_jts_dJSDocTypedefTag::kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocTypedefTag*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dJSDocCallbackTag::parent() noexcept { return _getProperty<_js_jts_dJSDoc>("parent"); }
	inline void _impl_js_jts_dJSDocCallbackTag::parent(_js_jts_dJSDoc v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dJSDocCallbackTag::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.JSDocCallbackTag*/>("kind"); }
	inline void _impl_js_jts_dJSDocCallbackTag::kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocCallbackTag*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dJSDocCallbackTag::typeExpression() noexcept { return _getProperty<_js_jts_dJSDocSignature>("typeExpression"); }
	inline void _impl_js_jts_dJSDocCallbackTag::typeExpression(_js_jts_dJSDocSignature v) noexcept { _setProperty("typeExpression", v); }
	inline auto _impl_js_jts_dJSDocSignature::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.JSDocSignature*/>("kind"); }
	inline void _impl_js_jts_dJSDocSignature::kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocSignature*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dJSDocSignature::parameters() noexcept { return _getProperty<js::ReadonlyArray<_js_jts_dJSDocParameterTag>>("parameters"); }
	inline void _impl_js_jts_dJSDocSignature::parameters(js::ReadonlyArray<_js_jts_dJSDocParameterTag> v) noexcept { _setProperty("parameters", v); }
	inline auto _impl_js_jts_dJSDocSignature::type() noexcept { return _getProperty<js_union<_js_jts_dJSDocReturnTag, js_undefined>>("type"); }
	inline void _impl_js_jts_dJSDocSignature::type(js_union<_js_jts_dJSDocReturnTag, js_undefined> v) noexcept { _setProperty("type", v); }
	inline auto _impl_js_jts_dJSDocPropertyLikeTag::parent() noexcept { return _getProperty<_js_jts_dJSDoc>("parent"); }
	inline void _impl_js_jts_dJSDocPropertyLikeTag::parent(_js_jts_dJSDoc v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dJSDocPropertyLikeTag::name() noexcept { return _getProperty<js_union<_js_jts_dIdentifier, _js_jts_dQualifiedName>>("name"); }
	inline void _impl_js_jts_dJSDocPropertyLikeTag::name(js_union<_js_jts_dIdentifier, _js_jts_dQualifiedName> v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dJSDocPropertyLikeTag::isNameFirst() noexcept { return _getProperty<bool /*false*/>("isNameFirst"); }
	inline void _impl_js_jts_dJSDocPropertyLikeTag::isNameFirst(bool /*false*/ v) noexcept { _setProperty("isNameFirst", v); }
	inline auto _impl_js_jts_dJSDocPropertyLikeTag::isBracketed() noexcept { return _getProperty<bool /*false*/>("isBracketed"); }
	inline void _impl_js_jts_dJSDocPropertyLikeTag::isBracketed(bool /*false*/ v) noexcept { _setProperty("isBracketed", v); }
	inline auto _impl_js_jts_dJSDocPropertyTag::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.JSDocPropertyTag*/>("kind"); }
	inline void _impl_js_jts_dJSDocPropertyTag::kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocPropertyTag*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dJSDocParameterTag::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.JSDocParameterTag*/>("kind"); }
	inline void _impl_js_jts_dJSDocParameterTag::kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocParameterTag*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dJSDocTypeLiteral::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.JSDocTypeLiteral*/>("kind"); }
	inline void _impl_js_jts_dJSDocTypeLiteral::kind(_js_jts_dSyntaxKind /*SyntaxKind.JSDocTypeLiteral*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dFlowNodeBase::flags() noexcept { return _getProperty<_js_jts_dFlowFlags /*FlowFlags.Unreachable*/>("flags"); }
	inline void _impl_js_jts_dFlowNodeBase::flags(_js_jts_dFlowFlags /*FlowFlags.Unreachable*/ v) noexcept { _setProperty("flags", v); }
	inline auto _impl_js_jts_dAfterFinallyFlow::antecedent() noexcept { return _getProperty<js_union<_js_jts_dAfterFinallyFlow, _js_jts_dFlowArrayMutation, _js_jts_dFlowAssignment, _js_jts_dFlowCondition, _js_jts_dFlowLabel, _js_jts_dFlowStart, _js_jts_dFlowSwitchClause, _js_jts_dPreFinallyFlow>>("antecedent"); }
	inline void _impl_js_jts_dAfterFinallyFlow::antecedent(js_union<_js_jts_dAfterFinallyFlow, _js_jts_dFlowArrayMutation, _js_jts_dFlowAssignment, _js_jts_dFlowCondition, _js_jts_dFlowLabel, _js_jts_dFlowStart, _js_jts_dFlowSwitchClause, _js_jts_dPreFinallyFlow> v) noexcept { _setProperty("antecedent", v); }
	inline auto _impl_js_jts_dPreFinallyFlow::antecedent() noexcept { return _getProperty<js_union<_js_jts_dAfterFinallyFlow, _js_jts_dFlowArrayMutation, _js_jts_dFlowAssignment, _js_jts_dFlowCondition, _js_jts_dFlowLabel, _js_jts_dFlowStart, _js_jts_dFlowSwitchClause, _js_jts_dPreFinallyFlow>>("antecedent"); }
	inline void _impl_js_jts_dPreFinallyFlow::antecedent(js_union<_js_jts_dAfterFinallyFlow, _js_jts_dFlowArrayMutation, _js_jts_dFlowAssignment, _js_jts_dFlowCondition, _js_jts_dFlowLabel, _js_jts_dFlowStart, _js_jts_dFlowSwitchClause, _js_jts_dPreFinallyFlow> v) noexcept { _setProperty("antecedent", v); }
	inline auto _impl_js_jts_dPreFinallyFlow::lock() noexcept { return _getProperty<_js_jts_dFlowLock>("lock"); }
	inline void _impl_js_jts_dPreFinallyFlow::lock(_js_jts_dFlowLock v) noexcept { _setProperty("lock", v); }
	inline auto _impl_js_jts_dFlowLabel::antecedents() noexcept { return _getProperty<js_union<js::Array<js_union<_js_jts_dAfterFinallyFlow, _js_jts_dFlowArrayMutation, _js_jts_dFlowAssignment, _js_jts_dFlowCondition, _js_jts_dFlowLabel, _js_jts_dFlowStart, _js_jts_dFlowSwitchClause, _js_jts_dPreFinallyFlow>>, js_undefined>>("antecedents"); }
	inline void _impl_js_jts_dFlowLabel::antecedents(js_union<js::Array<js_union<_js_jts_dAfterFinallyFlow, _js_jts_dFlowArrayMutation, _js_jts_dFlowAssignment, _js_jts_dFlowCondition, _js_jts_dFlowLabel, _js_jts_dFlowStart, _js_jts_dFlowSwitchClause, _js_jts_dPreFinallyFlow>>, js_undefined> v) noexcept { _setProperty("antecedents", v); }
	inline auto _impl_js_jts_dFlowAssignment::node() noexcept { return _getProperty<js_union<_js_jts_dBindingElement, _js_jts_dExpression, _js_jts_dVariableDeclaration>>("node"); }
	inline void _impl_js_jts_dFlowAssignment::node(js_union<_js_jts_dBindingElement, _js_jts_dExpression, _js_jts_dVariableDeclaration> v) noexcept { _setProperty("node", v); }
	inline auto _impl_js_jts_dFlowAssignment::antecedent() noexcept { return _getProperty<js_union<_js_jts_dAfterFinallyFlow, _js_jts_dFlowArrayMutation, _js_jts_dFlowAssignment, _js_jts_dFlowCondition, _js_jts_dFlowLabel, _js_jts_dFlowStart, _js_jts_dFlowSwitchClause, _js_jts_dPreFinallyFlow>>("antecedent"); }
	inline void _impl_js_jts_dFlowAssignment::antecedent(js_union<_js_jts_dAfterFinallyFlow, _js_jts_dFlowArrayMutation, _js_jts_dFlowAssignment, _js_jts_dFlowCondition, _js_jts_dFlowLabel, _js_jts_dFlowStart, _js_jts_dFlowSwitchClause, _js_jts_dPreFinallyFlow> v) noexcept { _setProperty("antecedent", v); }
	inline auto _impl_js_jts_dFlowCondition::expression() noexcept { return _getProperty<_js_jts_dExpression>("expression"); }
	inline void _impl_js_jts_dFlowCondition::expression(_js_jts_dExpression v) noexcept { _setProperty("expression", v); }
	inline auto _impl_js_jts_dFlowCondition::antecedent() noexcept { return _getProperty<js_union<_js_jts_dAfterFinallyFlow, _js_jts_dFlowArrayMutation, _js_jts_dFlowAssignment, _js_jts_dFlowCondition, _js_jts_dFlowLabel, _js_jts_dFlowStart, _js_jts_dFlowSwitchClause, _js_jts_dPreFinallyFlow>>("antecedent"); }
	inline void _impl_js_jts_dFlowCondition::antecedent(js_union<_js_jts_dAfterFinallyFlow, _js_jts_dFlowArrayMutation, _js_jts_dFlowAssignment, _js_jts_dFlowCondition, _js_jts_dFlowLabel, _js_jts_dFlowStart, _js_jts_dFlowSwitchClause, _js_jts_dPreFinallyFlow> v) noexcept { _setProperty("antecedent", v); }
	inline auto _impl_js_jts_dFlowSwitchClause::switchStatement() noexcept { return _getProperty<_js_jts_dSwitchStatement>("switchStatement"); }
	inline void _impl_js_jts_dFlowSwitchClause::switchStatement(_js_jts_dSwitchStatement v) noexcept { _setProperty("switchStatement", v); }
	inline auto _impl_js_jts_dFlowSwitchClause::clauseStart() noexcept { return _getProperty<double>("clauseStart"); }
	inline void _impl_js_jts_dFlowSwitchClause::clauseStart(double v) noexcept { _setProperty("clauseStart", v); }
	inline auto _impl_js_jts_dFlowSwitchClause::clauseEnd() noexcept { return _getProperty<double>("clauseEnd"); }
	inline void _impl_js_jts_dFlowSwitchClause::clauseEnd(double v) noexcept { _setProperty("clauseEnd", v); }
	inline auto _impl_js_jts_dFlowSwitchClause::antecedent() noexcept { return _getProperty<js_union<_js_jts_dAfterFinallyFlow, _js_jts_dFlowArrayMutation, _js_jts_dFlowAssignment, _js_jts_dFlowCondition, _js_jts_dFlowLabel, _js_jts_dFlowStart, _js_jts_dFlowSwitchClause, _js_jts_dPreFinallyFlow>>("antecedent"); }
	inline void _impl_js_jts_dFlowSwitchClause::antecedent(js_union<_js_jts_dAfterFinallyFlow, _js_jts_dFlowArrayMutation, _js_jts_dFlowAssignment, _js_jts_dFlowCondition, _js_jts_dFlowLabel, _js_jts_dFlowStart, _js_jts_dFlowSwitchClause, _js_jts_dPreFinallyFlow> v) noexcept { _setProperty("antecedent", v); }
	inline auto _impl_js_jts_dFlowArrayMutation::node() noexcept { return _getProperty<js_union<_js_jts_dBinaryExpression, _js_jts_dCallExpression>>("node"); }
	inline void _impl_js_jts_dFlowArrayMutation::node(js_union<_js_jts_dBinaryExpression, _js_jts_dCallExpression> v) noexcept { _setProperty("node", v); }
	inline auto _impl_js_jts_dFlowArrayMutation::antecedent() noexcept { return _getProperty<js_union<_js_jts_dAfterFinallyFlow, _js_jts_dFlowArrayMutation, _js_jts_dFlowAssignment, _js_jts_dFlowCondition, _js_jts_dFlowLabel, _js_jts_dFlowStart, _js_jts_dFlowSwitchClause, _js_jts_dPreFinallyFlow>>("antecedent"); }
	inline void _impl_js_jts_dFlowArrayMutation::antecedent(js_union<_js_jts_dAfterFinallyFlow, _js_jts_dFlowArrayMutation, _js_jts_dFlowAssignment, _js_jts_dFlowCondition, _js_jts_dFlowLabel, _js_jts_dFlowStart, _js_jts_dFlowSwitchClause, _js_jts_dPreFinallyFlow> v) noexcept { _setProperty("antecedent", v); }
	inline auto _impl_js_jts_dIncompleteType::flags() noexcept { return _getProperty<_js_jts_dTypeFlags /*TypeFlags.Any*/>("flags"); }
	inline void _impl_js_jts_dIncompleteType::flags(_js_jts_dTypeFlags /*TypeFlags.Any*/ v) noexcept { _setProperty("flags", v); }
	inline auto _impl_js_jts_dIncompleteType::type() noexcept { return _getProperty<_js_jts_dType>("type"); }
	inline void _impl_js_jts_dIncompleteType::type(_js_jts_dType v) noexcept { _setProperty("type", v); }
	inline auto _impl_js_jts_dAmdDependency::path() noexcept { return _getProperty<js_string>("path"); }
	inline void _impl_js_jts_dAmdDependency::path(js_string v) noexcept { _setProperty("path", v); }
	inline auto _impl_js_jts_dSourceFile::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.SourceFile*/>("kind"); }
	inline void _impl_js_jts_dSourceFile::kind(_js_jts_dSyntaxKind /*SyntaxKind.SourceFile*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dSourceFile::statements() noexcept { return _getProperty<js_unknown /*flags=524288: NodeArray<Statement> (TypeReference=ts.NodeArray)*/>("statements"); }
	inline void _impl_js_jts_dSourceFile::statements(js_unknown /*flags=524288: NodeArray<Statement> (TypeReference=ts.NodeArray)*/ v) noexcept { _setProperty("statements", v); }
	inline auto _impl_js_jts_dSourceFile::endOfFileToken() noexcept { return _getProperty<js_unknown /*flags=524288: Token<SyntaxKind.EndOfFileToken> (TypeReference=ts.Token)*/>("endOfFileToken"); }
	inline void _impl_js_jts_dSourceFile::endOfFileToken(js_unknown /*flags=524288: Token<SyntaxKind.EndOfFileToken> (TypeReference=ts.Token)*/ v) noexcept { _setProperty("endOfFileToken", v); }
	inline auto _impl_js_jts_dSourceFile::fileName() noexcept { return _getProperty<js_string>("fileName"); }
	inline void _impl_js_jts_dSourceFile::fileName(js_string v) noexcept { _setProperty("fileName", v); }
	inline auto _impl_js_jts_dSourceFile::text() noexcept { return _getProperty<js_string>("text"); }
	inline void _impl_js_jts_dSourceFile::text(js_string v) noexcept { _setProperty("text", v); }
	inline auto _impl_js_jts_dSourceFile::amdDependencies() noexcept { return _getProperty<js::ReadonlyArray<_js_jts_dAmdDependency>>("amdDependencies"); }
	inline void _impl_js_jts_dSourceFile::amdDependencies(js::ReadonlyArray<_js_jts_dAmdDependency> v) noexcept { _setProperty("amdDependencies", v); }
	inline auto _impl_js_jts_dSourceFile::referencedFiles() noexcept { return _getProperty<js::ReadonlyArray<_js_jts_dFileReference>>("referencedFiles"); }
	inline void _impl_js_jts_dSourceFile::referencedFiles(js::ReadonlyArray<_js_jts_dFileReference> v) noexcept { _setProperty("referencedFiles", v); }
	inline auto _impl_js_jts_dSourceFile::typeReferenceDirectives() noexcept { return _getProperty<js::ReadonlyArray<_js_jts_dFileReference>>("typeReferenceDirectives"); }
	inline void _impl_js_jts_dSourceFile::typeReferenceDirectives(js::ReadonlyArray<_js_jts_dFileReference> v) noexcept { _setProperty("typeReferenceDirectives", v); }
	inline auto _impl_js_jts_dSourceFile::libReferenceDirectives() noexcept { return _getProperty<js::ReadonlyArray<_js_jts_dFileReference>>("libReferenceDirectives"); }
	inline void _impl_js_jts_dSourceFile::libReferenceDirectives(js::ReadonlyArray<_js_jts_dFileReference> v) noexcept { _setProperty("libReferenceDirectives", v); }
	inline auto _impl_js_jts_dSourceFile::languageVariant() noexcept { return _getProperty<_js_jts_dLanguageVariant /*LanguageVariant.Standard*/>("languageVariant"); }
	inline void _impl_js_jts_dSourceFile::languageVariant(_js_jts_dLanguageVariant /*LanguageVariant.Standard*/ v) noexcept { _setProperty("languageVariant", v); }
	inline auto _impl_js_jts_dSourceFile::isDeclarationFile() noexcept { return _getProperty<bool /*false*/>("isDeclarationFile"); }
	inline void _impl_js_jts_dSourceFile::isDeclarationFile(bool /*false*/ v) noexcept { _setProperty("isDeclarationFile", v); }
	inline auto _impl_js_jts_dSourceFile::hasNoDefaultLib() noexcept { return _getProperty<bool /*false*/>("hasNoDefaultLib"); }
	inline void _impl_js_jts_dSourceFile::hasNoDefaultLib(bool /*false*/ v) noexcept { _setProperty("hasNoDefaultLib", v); }
	inline auto _impl_js_jts_dSourceFile::languageVersion() noexcept { return _getProperty<_js_jts_dScriptTarget /*ScriptTarget.ES3*/>("languageVersion"); }
	inline void _impl_js_jts_dSourceFile::languageVersion(_js_jts_dScriptTarget /*ScriptTarget.ES3*/ v) noexcept { _setProperty("languageVersion", v); }
	inline auto _impl_js_jts_dSourceFile::getLineAndCharacterOfPosition(double pos) noexcept {
		return _call<_js_jts_dLineAndCharacter>("getLineAndCharacterOfPosition", pos);
	}
	inline auto _impl_js_jts_dSourceFile::getLineEndOfPosition(double pos) noexcept {
		return _call<double>("getLineEndOfPosition", pos);
	}
	inline auto _impl_js_jts_dSourceFile::getLineStarts() noexcept {
		return _call<js::ReadonlyArray<double>>("getLineStarts");
	}
	inline auto _impl_js_jts_dSourceFile::getPositionOfLineAndCharacter(double line, double character) noexcept {
		return _call<double>("getPositionOfLineAndCharacter", line, character);
	}
	inline auto _impl_js_jts_dSourceFile::update(js_string newText, _js_jts_dTextChangeRange textChangeRange) noexcept {
		return _call<_js_jts_dSourceFile>("update", newText, textChangeRange);
	}
	inline auto _impl_js_jts_dBundle::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.Bundle*/>("kind"); }
	inline void _impl_js_jts_dBundle::kind(_js_jts_dSyntaxKind /*SyntaxKind.Bundle*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dBundle::prepends() noexcept { return _getProperty<js::ReadonlyArray<js_union<_js_jts_dInputFiles, _js_jts_dUnparsedSource>>>("prepends"); }
	inline void _impl_js_jts_dBundle::prepends(js::ReadonlyArray<js_union<_js_jts_dInputFiles, _js_jts_dUnparsedSource>> v) noexcept { _setProperty("prepends", v); }
	inline auto _impl_js_jts_dBundle::sourceFiles() noexcept { return _getProperty<js::ReadonlyArray<_js_jts_dSourceFile>>("sourceFiles"); }
	inline void _impl_js_jts_dBundle::sourceFiles(js::ReadonlyArray<_js_jts_dSourceFile> v) noexcept { _setProperty("sourceFiles", v); }
	inline auto _impl_js_jts_dInputFiles::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.InputFiles*/>("kind"); }
	inline void _impl_js_jts_dInputFiles::kind(_js_jts_dSyntaxKind /*SyntaxKind.InputFiles*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dInputFiles::javascriptText() noexcept { return _getProperty<js_string>("javascriptText"); }
	inline void _impl_js_jts_dInputFiles::javascriptText(js_string v) noexcept { _setProperty("javascriptText", v); }
	inline auto _impl_js_jts_dInputFiles::declarationText() noexcept { return _getProperty<js_string>("declarationText"); }
	inline void _impl_js_jts_dInputFiles::declarationText(js_string v) noexcept { _setProperty("declarationText", v); }
	inline auto _impl_js_jts_dUnparsedSource::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.UnparsedSource*/>("kind"); }
	inline void _impl_js_jts_dUnparsedSource::kind(_js_jts_dSyntaxKind /*SyntaxKind.UnparsedSource*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dUnparsedSource::fileName() noexcept { return _getProperty<js_string>("fileName"); }
	inline void _impl_js_jts_dUnparsedSource::fileName(js_string v) noexcept { _setProperty("fileName", v); }
	inline auto _impl_js_jts_dUnparsedSource::text() noexcept { return _getProperty<js_string>("text"); }
	inline void _impl_js_jts_dUnparsedSource::text(js_string v) noexcept { _setProperty("text", v); }
	inline auto _impl_js_jts_dUnparsedSource::prologues() noexcept { return _getProperty<js::ReadonlyArray<_js_jts_dUnparsedPrologue>>("prologues"); }
	inline void _impl_js_jts_dUnparsedSource::prologues(js::ReadonlyArray<_js_jts_dUnparsedPrologue> v) noexcept { _setProperty("prologues", v); }
	inline auto _impl_js_jts_dUnparsedSource::helpers() noexcept { return _getProperty<js_union<js::ReadonlyArray<_js_jts_dUnscopedEmitHelper>, js_undefined>>("helpers"); }
	inline void _impl_js_jts_dUnparsedSource::helpers(js_union<js::ReadonlyArray<_js_jts_dUnscopedEmitHelper>, js_undefined> v) noexcept { _setProperty("helpers", v); }
	inline auto _impl_js_jts_dUnparsedSource::referencedFiles() noexcept { return _getProperty<js::ReadonlyArray<_js_jts_dFileReference>>("referencedFiles"); }
	inline void _impl_js_jts_dUnparsedSource::referencedFiles(js::ReadonlyArray<_js_jts_dFileReference> v) noexcept { _setProperty("referencedFiles", v); }
	inline auto _impl_js_jts_dUnparsedSource::typeReferenceDirectives() noexcept { return _getProperty<js_union<js::ReadonlyArray<js_string>, js_undefined>>("typeReferenceDirectives"); }
	inline void _impl_js_jts_dUnparsedSource::typeReferenceDirectives(js_union<js::ReadonlyArray<js_string>, js_undefined> v) noexcept { _setProperty("typeReferenceDirectives", v); }
	inline auto _impl_js_jts_dUnparsedSource::libReferenceDirectives() noexcept { return _getProperty<js::ReadonlyArray<_js_jts_dFileReference>>("libReferenceDirectives"); }
	inline void _impl_js_jts_dUnparsedSource::libReferenceDirectives(js::ReadonlyArray<_js_jts_dFileReference> v) noexcept { _setProperty("libReferenceDirectives", v); }
	inline auto _impl_js_jts_dUnparsedSource::texts() noexcept { return _getProperty<js::ReadonlyArray<js_union<_js_jts_dUnparsedPrepend, _js_jts_dUnparsedTextLike>>>("texts"); }
	inline void _impl_js_jts_dUnparsedSource::texts(js::ReadonlyArray<js_union<_js_jts_dUnparsedPrepend, _js_jts_dUnparsedTextLike>> v) noexcept { _setProperty("texts", v); }
	inline auto _impl_js_jts_dUnparsedSection::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.Unknown*/>("kind"); }
	inline void _impl_js_jts_dUnparsedSection::kind(_js_jts_dSyntaxKind /*SyntaxKind.Unknown*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dUnparsedSection::parent() noexcept { return _getProperty<_js_jts_dUnparsedSource>("parent"); }
	inline void _impl_js_jts_dUnparsedSection::parent(_js_jts_dUnparsedSource v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dUnparsedPrologue::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.UnparsedPrologue*/>("kind"); }
	inline void _impl_js_jts_dUnparsedPrologue::kind(_js_jts_dSyntaxKind /*SyntaxKind.UnparsedPrologue*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dUnparsedPrologue::data() noexcept { return _getProperty<js_string>("data"); }
	inline void _impl_js_jts_dUnparsedPrologue::data(js_string v) noexcept { _setProperty("data", v); }
	inline auto _impl_js_jts_dUnparsedPrologue::parent() noexcept { return _getProperty<_js_jts_dUnparsedSource>("parent"); }
	inline void _impl_js_jts_dUnparsedPrologue::parent(_js_jts_dUnparsedSource v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dUnparsedPrepend::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.UnparsedPrepend*/>("kind"); }
	inline void _impl_js_jts_dUnparsedPrepend::kind(_js_jts_dSyntaxKind /*SyntaxKind.UnparsedPrepend*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dUnparsedPrepend::data() noexcept { return _getProperty<js_string>("data"); }
	inline void _impl_js_jts_dUnparsedPrepend::data(js_string v) noexcept { _setProperty("data", v); }
	inline auto _impl_js_jts_dUnparsedPrepend::parent() noexcept { return _getProperty<_js_jts_dUnparsedSource>("parent"); }
	inline void _impl_js_jts_dUnparsedPrepend::parent(_js_jts_dUnparsedSource v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dUnparsedPrepend::texts() noexcept { return _getProperty<js::ReadonlyArray<_js_jts_dUnparsedTextLike>>("texts"); }
	inline void _impl_js_jts_dUnparsedPrepend::texts(js::ReadonlyArray<_js_jts_dUnparsedTextLike> v) noexcept { _setProperty("texts", v); }
	inline auto _impl_js_jts_dUnparsedTextLike::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.UnparsedText*/>("kind"); }
	inline void _impl_js_jts_dUnparsedTextLike::kind(_js_jts_dSyntaxKind /*SyntaxKind.UnparsedText*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dUnparsedTextLike::parent() noexcept { return _getProperty<_js_jts_dUnparsedSource>("parent"); }
	inline void _impl_js_jts_dUnparsedTextLike::parent(_js_jts_dUnparsedSource v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dUnparsedSyntheticReference::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.UnparsedSyntheticReference*/>("kind"); }
	inline void _impl_js_jts_dUnparsedSyntheticReference::kind(_js_jts_dSyntaxKind /*SyntaxKind.UnparsedSyntheticReference*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dUnparsedSyntheticReference::parent() noexcept { return _getProperty<_js_jts_dUnparsedSource>("parent"); }
	inline void _impl_js_jts_dUnparsedSyntheticReference::parent(_js_jts_dUnparsedSource v) noexcept { _setProperty("parent", v); }
	inline auto _impl_js_jts_dJsonSourceFile::statements() noexcept { return _getProperty<js_unknown /*flags=524288: NodeArray<JsonObjectExpressionStatement> (TypeReference=ts.NodeArray)*/>("statements"); }
	inline void _impl_js_jts_dJsonSourceFile::statements(js_unknown /*flags=524288: NodeArray<JsonObjectExpressionStatement> (TypeReference=ts.NodeArray)*/ v) noexcept { _setProperty("statements", v); }
	inline auto _impl_js_jts_dJsonMinusNumericLiteral::kind() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.PrefixUnaryExpression*/>("kind"); }
	inline void _impl_js_jts_dJsonMinusNumericLiteral::kind(_js_jts_dSyntaxKind /*SyntaxKind.PrefixUnaryExpression*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dJsonMinusNumericLiteral::operator_() noexcept { return _getProperty<_js_jts_dSyntaxKind /*SyntaxKind.MinusToken*/>("operator"); }
	inline void _impl_js_jts_dJsonMinusNumericLiteral::operator_(_js_jts_dSyntaxKind /*SyntaxKind.MinusToken*/ v) noexcept { _setProperty("operator", v); }
	inline auto _impl_js_jts_dJsonMinusNumericLiteral::operand() noexcept { return _getProperty<_js_jts_dNumericLiteral>("operand"); }
	inline void _impl_js_jts_dJsonMinusNumericLiteral::operand(_js_jts_dNumericLiteral v) noexcept { _setProperty("operand", v); }
	inline auto _impl_js_jts_dJsonObjectExpressionStatement::expression() noexcept { return _getProperty<js_union<_js_jts_dArrayLiteralExpression, _js_jts_dBooleanLiteral, _js_jts_dJsonMinusNumericLiteral, _js_jts_dNullLiteral, _js_jts_dNumericLiteral, _js_jts_dObjectLiteralExpression, _js_jts_dStringLiteral>>("expression"); }
	inline void _impl_js_jts_dJsonObjectExpressionStatement::expression(js_union<_js_jts_dArrayLiteralExpression, _js_jts_dBooleanLiteral, _js_jts_dJsonMinusNumericLiteral, _js_jts_dNullLiteral, _js_jts_dNumericLiteral, _js_jts_dObjectLiteralExpression, _js_jts_dStringLiteral> v) noexcept { _setProperty("expression", v); }
	inline auto _impl_js_jts_dScriptReferenceHost::getCompilerOptions() noexcept {
		return _call<_js_jts_dCompilerOptions>("getCompilerOptions");
	}
	inline auto _impl_js_jts_dScriptReferenceHost::getCurrentDirectory() noexcept {
		return _call<js_string>("getCurrentDirectory");
	}
	inline auto _impl_js_jts_dScriptReferenceHost::getSourceFile(js_string fileName) noexcept {
		return _call<js_union<_js_jts_dSourceFile, js_undefined>>("getSourceFile", fileName);
	}
	inline auto _impl_js_jts_dScriptReferenceHost::getSourceFileByPath(js_unknown /*flags=2097152: Path ()*/ path) noexcept {
		return _call<js_union<_js_jts_dSourceFile, js_undefined>>("getSourceFileByPath", path);
	}
	inline auto _impl_js_jts_dParseConfigHost::useCaseSensitiveFileNames() noexcept { return _getProperty<bool /*false*/>("useCaseSensitiveFileNames"); }
	inline void _impl_js_jts_dParseConfigHost::useCaseSensitiveFileNames(bool /*false*/ v) noexcept { _setProperty("useCaseSensitiveFileNames", v); }
	inline auto _impl_js_jts_dParseConfigHost::fileExists(js_string path) noexcept {
		return _call<bool /*false*/>("fileExists", path);
	}
	inline auto _impl_js_jts_dParseConfigHost::readDirectory(js_string rootDir, js::ReadonlyArray<js_string> extensions, js_union<js::ReadonlyArray<js_string>, js_undefined> excludes, js::ReadonlyArray<js_string> includes, js_union<double, js_undefined> depth) noexcept {
		return _call<js::ReadonlyArray<js_string>>("readDirectory", rootDir, extensions, excludes, includes, depth);
	}
	inline auto _impl_js_jts_dParseConfigHost::readFile(js_string path) noexcept {
		return _call<js_union<js_string, js_undefined>>("readFile", path);
	}
	inline auto _impl_js_jts_dOperationCanceledException::_tcjs_construct() noexcept {
		return _js_jts_dOperationCanceledException(emscripten::val::global("ts")["OperationCanceledException"].new_());
	}
	inline auto _impl_js_jts_dCancellationToken::isCancellationRequested() noexcept {
		return _call<bool /*false*/>("isCancellationRequested");
	}
	inline auto _impl_js_jts_dCancellationToken::throwIfCancellationRequested() noexcept {
		return _call<void>("throwIfCancellationRequested");
	}
	inline auto _impl_js_jts_dProgram::emit(js_union<_js_jts_dSourceFile, js_undefined> targetSourceFile, js_union<js_function<void(js_string, js_string, bool /*false*/, js_union<js_function<void(js_string)>, js_undefined>, js_union<js::ReadonlyArray<_js_jts_dSourceFile>, js_undefined>)>, js_undefined> writeFile, js_union<_js_jts_dCancellationToken, js_undefined> cancellationToken, js_union<bool /*false*/, js_undefined> emitOnlyDtsFiles, js_union<_js_jts_dCustomTransformers, js_undefined> customTransformers) noexcept {
		return _call<_js_jts_dEmitResult>("emit", targetSourceFile, writeFile, cancellationToken, emitOnlyDtsFiles, customTransformers);
	}
	inline auto _impl_js_jts_dProgram::getConfigFileParsingDiagnostics() noexcept {
		return _call<js::ReadonlyArray<_js_jts_dDiagnostic>>("getConfigFileParsingDiagnostics");
	}
	inline auto _impl_js_jts_dProgram::getDeclarationDiagnostics(js_union<_js_jts_dSourceFile, js_undefined> sourceFile, js_union<_js_jts_dCancellationToken, js_undefined> cancellationToken) noexcept {
		return _call<js::ReadonlyArray<_js_jts_dDiagnosticWithLocation>>("getDeclarationDiagnostics", sourceFile, cancellationToken);
	}
	inline auto _impl_js_jts_dProgram::getGlobalDiagnostics(js_union<_js_jts_dCancellationToken, js_undefined> cancellationToken) noexcept {
		return _call<js::ReadonlyArray<_js_jts_dDiagnostic>>("getGlobalDiagnostics", cancellationToken);
	}
	inline auto _impl_js_jts_dProgram::getOptionsDiagnostics(js_union<_js_jts_dCancellationToken, js_undefined> cancellationToken) noexcept {
		return _call<js::ReadonlyArray<_js_jts_dDiagnostic>>("getOptionsDiagnostics", cancellationToken);
	}
	inline auto _impl_js_jts_dProgram::getProjectReferences() noexcept {
		return _call<js_union<js::ReadonlyArray<_js_jts_dProjectReference>, js_undefined>>("getProjectReferences");
	}
	inline auto _impl_js_jts_dProgram::getResolvedProjectReferences() noexcept {
		return _call<js_union<js::ReadonlyArray<js_union<_js_jts_dResolvedProjectReference, js_undefined>>, js_undefined>>("getResolvedProjectReferences");
	}
	inline auto _impl_js_jts_dProgram::getRootFileNames() noexcept {
		return _call<js::ReadonlyArray<js_string>>("getRootFileNames");
	}
	inline auto _impl_js_jts_dProgram::getSemanticDiagnostics(js_union<_js_jts_dSourceFile, js_undefined> sourceFile, js_union<_js_jts_dCancellationToken, js_undefined> cancellationToken) noexcept {
		return _call<js::ReadonlyArray<_js_jts_dDiagnostic>>("getSemanticDiagnostics", sourceFile, cancellationToken);
	}
	inline auto _impl_js_jts_dProgram::getSourceFiles() noexcept {
		return _call<js::ReadonlyArray<_js_jts_dSourceFile>>("getSourceFiles");
	}
	inline auto _impl_js_jts_dProgram::getSyntacticDiagnostics(js_union<_js_jts_dSourceFile, js_undefined> sourceFile, js_union<_js_jts_dCancellationToken, js_undefined> cancellationToken) noexcept {
		return _call<js::ReadonlyArray<_js_jts_dDiagnosticWithLocation>>("getSyntacticDiagnostics", sourceFile, cancellationToken);
	}
	inline auto _impl_js_jts_dProgram::getTypeChecker() noexcept {
		return _call<_js_jts_dTypeChecker>("getTypeChecker");
	}
	inline auto _impl_js_jts_dProgram::isSourceFileDefaultLibrary(_js_jts_dSourceFile file) noexcept {
		return _call<bool /*false*/>("isSourceFileDefaultLibrary", file);
	}
	inline auto _impl_js_jts_dProgram::isSourceFileFromExternalLibrary(_js_jts_dSourceFile file) noexcept {
		return _call<bool /*false*/>("isSourceFileFromExternalLibrary", file);
	}
	inline auto _impl_js_jts_dResolvedProjectReference::commandLine() noexcept { return _getProperty<_js_jts_dParsedCommandLine>("commandLine"); }
	inline void _impl_js_jts_dResolvedProjectReference::commandLine(_js_jts_dParsedCommandLine v) noexcept { _setProperty("commandLine", v); }
	inline auto _impl_js_jts_dResolvedProjectReference::sourceFile() noexcept { return _getProperty<_js_jts_dSourceFile>("sourceFile"); }
	inline void _impl_js_jts_dResolvedProjectReference::sourceFile(_js_jts_dSourceFile v) noexcept { _setProperty("sourceFile", v); }
	inline auto _impl_js_jts_dCustomTransformer::transformBundle(_js_jts_dBundle node) noexcept {
		return _call<_js_jts_dBundle>("transformBundle", node);
	}
	inline auto _impl_js_jts_dCustomTransformer::transformSourceFile(_js_jts_dSourceFile node) noexcept {
		return _call<_js_jts_dSourceFile>("transformSourceFile", node);
	}
	inline auto _impl_js_jts_dSourceMapSpan::emittedLine() noexcept { return _getProperty<double>("emittedLine"); }
	inline void _impl_js_jts_dSourceMapSpan::emittedLine(double v) noexcept { _setProperty("emittedLine", v); }
	inline auto _impl_js_jts_dSourceMapSpan::emittedColumn() noexcept { return _getProperty<double>("emittedColumn"); }
	inline void _impl_js_jts_dSourceMapSpan::emittedColumn(double v) noexcept { _setProperty("emittedColumn", v); }
	inline auto _impl_js_jts_dSourceMapSpan::sourceLine() noexcept { return _getProperty<double>("sourceLine"); }
	inline void _impl_js_jts_dSourceMapSpan::sourceLine(double v) noexcept { _setProperty("sourceLine", v); }
	inline auto _impl_js_jts_dSourceMapSpan::sourceColumn() noexcept { return _getProperty<double>("sourceColumn"); }
	inline void _impl_js_jts_dSourceMapSpan::sourceColumn(double v) noexcept { _setProperty("sourceColumn", v); }
	inline auto _impl_js_jts_dSourceMapSpan::sourceIndex() noexcept { return _getProperty<double>("sourceIndex"); }
	inline void _impl_js_jts_dSourceMapSpan::sourceIndex(double v) noexcept { _setProperty("sourceIndex", v); }
	inline auto _impl_js_jts_dEmitResult::emitSkipped() noexcept { return _getProperty<bool /*false*/>("emitSkipped"); }
	inline void _impl_js_jts_dEmitResult::emitSkipped(bool /*false*/ v) noexcept { _setProperty("emitSkipped", v); }
	inline auto _impl_js_jts_dEmitResult::diagnostics() noexcept { return _getProperty<js::ReadonlyArray<_js_jts_dDiagnostic>>("diagnostics"); }
	inline void _impl_js_jts_dEmitResult::diagnostics(js::ReadonlyArray<_js_jts_dDiagnostic> v) noexcept { _setProperty("diagnostics", v); }
	inline auto _impl_js_jts_dTypeChecker::getAliasedSymbol(_js_jts_dSymbol symbol) noexcept {
		return _call<_js_jts_dSymbol>("getAliasedSymbol", symbol);
	}
	inline auto _impl_js_jts_dTypeChecker::getAmbientModules() noexcept {
		return _call<js::Array<_js_jts_dSymbol>>("getAmbientModules");
	}
	inline auto _impl_js_jts_dTypeChecker::getApparentType(_js_jts_dType type) noexcept {
		return _call<_js_jts_dType>("getApparentType", type);
	}
	inline auto _impl_js_jts_dTypeChecker::getAugmentedPropertiesOfType(_js_jts_dType type) noexcept {
		return _call<js::Array<_js_jts_dSymbol>>("getAugmentedPropertiesOfType", type);
	}
	inline auto _impl_js_jts_dTypeChecker::getBaseConstraintOfType(_js_jts_dType type) noexcept {
		return _call<js_union<_js_jts_dType, js_undefined>>("getBaseConstraintOfType", type);
	}
	inline auto _impl_js_jts_dTypeChecker::getBaseTypeOfLiteralType(_js_jts_dType type) noexcept {
		return _call<_js_jts_dType>("getBaseTypeOfLiteralType", type);
	}
	inline auto _impl_js_jts_dTypeChecker::getBaseTypes(_js_jts_dInterfaceType type) noexcept {
		return _call<js::Array<js_union<_js_jts_dIntersectionType, _js_jts_dObjectType>>>("getBaseTypes", type);
	}
	inline auto _impl_js_jts_dTypeChecker::getConstantValue(js_union<_js_jts_dElementAccessExpression, _js_jts_dEnumMember, _js_jts_dPropertyAccessExpression> node) noexcept {
		return _call<js_union<double, js_string, js_undefined>>("getConstantValue", node);
	}
	inline auto _impl_js_jts_dTypeChecker::getContextualType(_js_jts_dExpression node) noexcept {
		return _call<js_union<_js_jts_dType, js_undefined>>("getContextualType", node);
	}
	inline auto _impl_js_jts_dTypeChecker::getDeclaredTypeOfSymbol(_js_jts_dSymbol symbol) noexcept {
		return _call<_js_jts_dType>("getDeclaredTypeOfSymbol", symbol);
	}
	inline auto _impl_js_jts_dTypeChecker::getDefaultFromTypeParameter(_js_jts_dType type) noexcept {
		return _call<js_union<_js_jts_dType, js_undefined>>("getDefaultFromTypeParameter", type);
	}
	inline auto _impl_js_jts_dTypeChecker::getExportSpecifierLocalTargetSymbol(_js_jts_dExportSpecifier location) noexcept {
		return _call<js_union<_js_jts_dSymbol, js_undefined>>("getExportSpecifierLocalTargetSymbol", location);
	}
	inline auto _impl_js_jts_dTypeChecker::getExportSymbolOfSymbol(_js_jts_dSymbol symbol) noexcept {
		return _call<_js_jts_dSymbol>("getExportSymbolOfSymbol", symbol);
	}
	inline auto _impl_js_jts_dTypeChecker::getExportsOfModule(_js_jts_dSymbol moduleSymbol) noexcept {
		return _call<js::Array<_js_jts_dSymbol>>("getExportsOfModule", moduleSymbol);
	}
	inline auto _impl_js_jts_dTypeChecker::getFullyQualifiedName(_js_jts_dSymbol symbol) noexcept {
		return _call<js_string>("getFullyQualifiedName", symbol);
	}
	inline auto _impl_js_jts_dTypeChecker::getIndexInfoOfType(_js_jts_dType type, _js_jts_dIndexKind /*IndexKind.String*/ kind) noexcept {
		return _call<js_union<_js_jts_dIndexInfo, js_undefined>>("getIndexInfoOfType", type, kind);
	}
	inline auto _impl_js_jts_dTypeChecker::getIndexTypeOfType(_js_jts_dType type, _js_jts_dIndexKind /*IndexKind.String*/ kind) noexcept {
		return _call<js_union<_js_jts_dType, js_undefined>>("getIndexTypeOfType", type, kind);
	}
	inline auto _impl_js_jts_dTypeChecker::getJsxIntrinsicTagNamesAt(_js_jts_dNode location) noexcept {
		return _call<js::Array<_js_jts_dSymbol>>("getJsxIntrinsicTagNamesAt", location);
	}
	inline auto _impl_js_jts_dTypeChecker::getNonNullableType(_js_jts_dType type) noexcept {
		return _call<_js_jts_dType>("getNonNullableType", type);
	}
	inline auto _impl_js_jts_dTypeChecker::getNullableType(_js_jts_dType type, _js_jts_dTypeFlags /*TypeFlags.Any*/ flags) noexcept {
		return _call<_js_jts_dType>("getNullableType", type, flags);
	}
	inline auto _impl_js_jts_dTypeChecker::getPropertiesOfType(_js_jts_dType type) noexcept {
		return _call<js::Array<_js_jts_dSymbol>>("getPropertiesOfType", type);
	}
	inline auto _impl_js_jts_dTypeChecker::getPropertyOfType(_js_jts_dType type, js_string propertyName) noexcept {
		return _call<js_union<_js_jts_dSymbol, js_undefined>>("getPropertyOfType", type, propertyName);
	}
	inline auto _impl_js_jts_dTypeChecker::getPropertySymbolOfDestructuringAssignment(_js_jts_dIdentifier location) noexcept {
		return _call<js_union<_js_jts_dSymbol, js_undefined>>("getPropertySymbolOfDestructuringAssignment", location);
	}
	inline auto _impl_js_jts_dTypeChecker::getResolvedSignature(js_union<_js_jts_dCallExpression, _js_jts_dDecorator, _js_jts_dJsxOpeningElement, _js_jts_dJsxSelfClosingElement, _js_jts_dNewExpression, _js_jts_dTaggedTemplateExpression> node, js_union<js::Array<_js_jts_dSignature>, js_undefined> candidatesOutArray, js_union<double, js_undefined> argumentCount) noexcept {
		return _call<js_union<_js_jts_dSignature, js_undefined>>("getResolvedSignature", node, candidatesOutArray, argumentCount);
	}
	inline auto _impl_js_jts_dTypeChecker::getReturnTypeOfSignature(_js_jts_dSignature signature) noexcept {
		return _call<_js_jts_dType>("getReturnTypeOfSignature", signature);
	}
	inline auto _impl_js_jts_dTypeChecker::getRootSymbols(_js_jts_dSymbol symbol) noexcept {
		return _call<js::ReadonlyArray<_js_jts_dSymbol>>("getRootSymbols", symbol);
	}
	inline auto _impl_js_jts_dTypeChecker::getShorthandAssignmentValueSymbol(_js_jts_dNode location) noexcept {
		return _call<js_union<_js_jts_dSymbol, js_undefined>>("getShorthandAssignmentValueSymbol", location);
	}
	inline auto _impl_js_jts_dTypeChecker::getSignatureFromDeclaration(js_union<_js_jts_dArrowFunction, _js_jts_dCallSignatureDeclaration, _js_jts_dConstructSignatureDeclaration, _js_jts_dConstructorDeclaration, _js_jts_dConstructorTypeNode, _js_jts_dFunctionDeclaration, _js_jts_dFunctionExpression, _js_jts_dFunctionTypeNode, _js_jts_dGetAccessorDeclaration, _js_jts_dIndexSignatureDeclaration, _js_jts_dJSDocFunctionType, _js_jts_dMethodDeclaration, _js_jts_dMethodSignature, _js_jts_dSetAccessorDeclaration> declaration) noexcept {
		return _call<js_union<_js_jts_dSignature, js_undefined>>("getSignatureFromDeclaration", declaration);
	}
	inline auto _impl_js_jts_dTypeChecker::getSignaturesOfType(_js_jts_dType type, _js_jts_dSignatureKind /*SignatureKind.Call*/ kind) noexcept {
		return _call<js::ReadonlyArray<_js_jts_dSignature>>("getSignaturesOfType", type, kind);
	}
	inline auto _impl_js_jts_dTypeChecker::getSymbolAtLocation(_js_jts_dNode node) noexcept {
		return _call<js_union<_js_jts_dSymbol, js_undefined>>("getSymbolAtLocation", node);
	}
	inline auto _impl_js_jts_dTypeChecker::getSymbolsInScope(_js_jts_dNode location, _js_jts_dSymbolFlags /*SymbolFlags.None*/ meaning) noexcept {
		return _call<js::Array<_js_jts_dSymbol>>("getSymbolsInScope", location, meaning);
	}
	inline auto _impl_js_jts_dTypeChecker::getSymbolsOfParameterPropertyDeclaration(_js_jts_dParameterDeclaration parameter, js_string parameterName) noexcept {
		return _call<js::Array<_js_jts_dSymbol>>("getSymbolsOfParameterPropertyDeclaration", parameter, parameterName);
	}
	inline auto _impl_js_jts_dTypeChecker::getTypeAtLocation(_js_jts_dNode node) noexcept {
		return _call<_js_jts_dType>("getTypeAtLocation", node);
	}
	inline auto _impl_js_jts_dTypeChecker::getTypeFromTypeNode(_js_jts_dTypeNode node) noexcept {
		return _call<_js_jts_dType>("getTypeFromTypeNode", node);
	}
	inline auto _impl_js_jts_dTypeChecker::getTypeOfAssignmentPattern(js_union<_js_jts_dArrayLiteralExpression, _js_jts_dObjectLiteralExpression> pattern) noexcept {
		return _call<_js_jts_dType>("getTypeOfAssignmentPattern", pattern);
	}
	inline auto _impl_js_jts_dTypeChecker::getTypeOfSymbolAtLocation(_js_jts_dSymbol symbol, _js_jts_dNode node) noexcept {
		return _call<_js_jts_dType>("getTypeOfSymbolAtLocation", symbol, node);
	}
	inline auto _impl_js_jts_dTypeChecker::getWidenedType(_js_jts_dType type) noexcept {
		return _call<_js_jts_dType>("getWidenedType", type);
	}
	inline auto _impl_js_jts_dTypeChecker::indexInfoToIndexSignatureDeclaration(_js_jts_dIndexInfo indexInfo, _js_jts_dIndexKind /*IndexKind.String*/ kind, js_union<_js_jts_dNode, js_undefined> enclosingDeclaration, js_union<_js_jts_dNodeBuilderFlags /*NodeBuilderFlags.OmitParameterModifiers*/, js_undefined> flags) noexcept {
		return _call<js_union<_js_jts_dIndexSignatureDeclaration, js_undefined>>("indexInfoToIndexSignatureDeclaration", indexInfo, kind, enclosingDeclaration, flags);
	}
	inline auto _impl_js_jts_dTypeChecker::isArgumentsSymbol(_js_jts_dSymbol symbol) noexcept {
		return _call<bool /*false*/>("isArgumentsSymbol", symbol);
	}
	inline auto _impl_js_jts_dTypeChecker::isImplementationOfOverload(js_union<_js_jts_dArrowFunction, _js_jts_dCallSignatureDeclaration, _js_jts_dConstructSignatureDeclaration, _js_jts_dConstructorDeclaration, _js_jts_dConstructorTypeNode, _js_jts_dFunctionDeclaration, _js_jts_dFunctionExpression, _js_jts_dFunctionTypeNode, _js_jts_dGetAccessorDeclaration, _js_jts_dIndexSignatureDeclaration, _js_jts_dJSDocFunctionType, _js_jts_dMethodDeclaration, _js_jts_dMethodSignature, _js_jts_dSetAccessorDeclaration> node) noexcept {
		return _call<js_union<bool /*false*/, js_undefined>>("isImplementationOfOverload", node);
	}
	inline auto _impl_js_jts_dTypeChecker::isOptionalParameter(_js_jts_dParameterDeclaration node) noexcept {
		return _call<bool /*false*/>("isOptionalParameter", node);
	}
	inline auto _impl_js_jts_dTypeChecker::isUndefinedSymbol(_js_jts_dSymbol symbol) noexcept {
		return _call<bool /*false*/>("isUndefinedSymbol", symbol);
	}
	inline auto _impl_js_jts_dTypeChecker::isUnknownSymbol(_js_jts_dSymbol symbol) noexcept {
		return _call<bool /*false*/>("isUnknownSymbol", symbol);
	}
	inline auto _impl_js_jts_dTypeChecker::isValidPropertyAccess(js_union<_js_jts_dImportTypeNode, _js_jts_dPropertyAccessExpression, _js_jts_dQualifiedName> node, js_string propertyName) noexcept {
		return _call<bool /*false*/>("isValidPropertyAccess", node, propertyName);
	}
	inline auto _impl_js_jts_dTypeChecker::runWithCancellationToken(_js_jts_dCancellationToken token, js_function<js_unknown /*flags=262144: T ()*/(_js_jts_dTypeChecker)> cb) noexcept {
		return _call<js_unknown /*flags=262144: T ()*/>("runWithCancellationToken", token, cb);
	}
	inline auto _impl_js_jts_dTypeChecker::signatureToSignatureDeclaration(_js_jts_dSignature signature, _js_jts_dSyntaxKind /*SyntaxKind.Unknown*/ kind, js_union<_js_jts_dNode, js_undefined> enclosingDeclaration, js_union<_js_jts_dNodeBuilderFlags /*NodeBuilderFlags.OmitParameterModifiers*/, js_undefined> flags) noexcept {
		return _call<js_unknown /*flags=1048576: (CallSignatureDeclaration & { typeArguments?: NodeArray<TypeNode> | undefined; }) | (ConstructSignatureDeclaration & { typeArguments?: NodeArray<TypeNode> | undefined; }) | ... 12 more ... | undefined ()*/>("signatureToSignatureDeclaration", signature, kind, enclosingDeclaration, flags);
	}
	inline auto _impl_js_jts_dTypeChecker::signatureToString(_js_jts_dSignature signature, js_union<_js_jts_dNode, js_undefined> enclosingDeclaration, js_union<_js_jts_dTypeFormatFlags /*TypeFormatFlags.UseTypeOfFunction*/, js_undefined> flags, js_union<_js_jts_dSignatureKind /*SignatureKind.Call*/, js_undefined> kind) noexcept {
		return _call<js_string>("signatureToString", signature, enclosingDeclaration, flags, kind);
	}
	inline auto _impl_js_jts_dTypeChecker::symbolToEntityName(_js_jts_dSymbol symbol, _js_jts_dSymbolFlags /*SymbolFlags.None*/ meaning, js_union<_js_jts_dNode, js_undefined> enclosingDeclaration, js_union<_js_jts_dNodeBuilderFlags /*NodeBuilderFlags.OmitParameterModifiers*/, js_undefined> flags) noexcept {
		return _call<js_union<_js_jts_dIdentifier, _js_jts_dQualifiedName, js_undefined>>("symbolToEntityName", symbol, meaning, enclosingDeclaration, flags);
	}
	inline auto _impl_js_jts_dTypeChecker::symbolToExpression(_js_jts_dSymbol symbol, _js_jts_dSymbolFlags /*SymbolFlags.None*/ meaning, js_union<_js_jts_dNode, js_undefined> enclosingDeclaration, js_union<_js_jts_dNodeBuilderFlags /*NodeBuilderFlags.OmitParameterModifiers*/, js_undefined> flags) noexcept {
		return _call<js_union<_js_jts_dExpression, js_undefined>>("symbolToExpression", symbol, meaning, enclosingDeclaration, flags);
	}
	inline auto _impl_js_jts_dTypeChecker::symbolToParameterDeclaration(_js_jts_dSymbol symbol, js_union<_js_jts_dNode, js_undefined> enclosingDeclaration, js_union<_js_jts_dNodeBuilderFlags /*NodeBuilderFlags.OmitParameterModifiers*/, js_undefined> flags) noexcept {
		return _call<js_union<_js_jts_dParameterDeclaration, js_undefined>>("symbolToParameterDeclaration", symbol, enclosingDeclaration, flags);
	}
	inline auto _impl_js_jts_dTypeChecker::symbolToString(_js_jts_dSymbol symbol, js_union<_js_jts_dNode, js_undefined> enclosingDeclaration, js_union<_js_jts_dSymbolFlags /*SymbolFlags.Transient*/, js_undefined> meaning, js_union<_js_jts_dSymbolFormatFlags /*SymbolFormatFlags.None*/, js_undefined> flags) noexcept {
		return _call<js_string>("symbolToString", symbol, enclosingDeclaration, meaning, flags);
	}
	inline auto _impl_js_jts_dTypeChecker::symbolToTypeParameterDeclarations(_js_jts_dSymbol symbol, js_union<_js_jts_dNode, js_undefined> enclosingDeclaration, js_union<_js_jts_dNodeBuilderFlags /*NodeBuilderFlags.OmitParameterModifiers*/, js_undefined> flags) noexcept {
		return _call<js_unknown /*flags=1048576: NodeArray<TypeParameterDeclaration> | undefined ()*/>("symbolToTypeParameterDeclarations", symbol, enclosingDeclaration, flags);
	}
	inline auto _impl_js_jts_dTypeChecker::tryGetMemberInModuleExports(js_string memberName, _js_jts_dSymbol moduleSymbol) noexcept {
		return _call<js_union<_js_jts_dSymbol, js_undefined>>("tryGetMemberInModuleExports", memberName, moduleSymbol);
	}
	inline auto _impl_js_jts_dTypeChecker::typeParameterToDeclaration(_js_jts_dTypeParameter parameter, js_union<_js_jts_dNode, js_undefined> enclosingDeclaration, js_union<_js_jts_dNodeBuilderFlags /*NodeBuilderFlags.OmitParameterModifiers*/, js_undefined> flags) noexcept {
		return _call<js_union<_js_jts_dTypeParameterDeclaration, js_undefined>>("typeParameterToDeclaration", parameter, enclosingDeclaration, flags);
	}
	inline auto _impl_js_jts_dTypeChecker::typePredicateToString(js_union<_js_jts_dIdentifierTypePredicate, _js_jts_dThisTypePredicate> predicate, js_union<_js_jts_dNode, js_undefined> enclosingDeclaration, js_union<_js_jts_dTypeFormatFlags /*TypeFormatFlags.UseTypeOfFunction*/, js_undefined> flags) noexcept {
		return _call<js_string>("typePredicateToString", predicate, enclosingDeclaration, flags);
	}
	inline auto _impl_js_jts_dTypeChecker::typeToString(_js_jts_dType type, js_union<_js_jts_dNode, js_undefined> enclosingDeclaration, js_union<_js_jts_dTypeFormatFlags /*TypeFormatFlags.UseTypeOfFunction*/, js_undefined> flags) noexcept {
		return _call<js_string>("typeToString", type, enclosingDeclaration, flags);
	}
	inline auto _impl_js_jts_dTypeChecker::typeToTypeNode(_js_jts_dType type, js_union<_js_jts_dNode, js_undefined> enclosingDeclaration, js_union<_js_jts_dNodeBuilderFlags /*NodeBuilderFlags.OmitParameterModifiers*/, js_undefined> flags) noexcept {
		return _call<js_union<_js_jts_dTypeNode, js_undefined>>("typeToTypeNode", type, enclosingDeclaration, flags);
	}
	inline auto _impl_js_jts_dTypePredicateBase::kind() noexcept { return _getProperty<_js_jts_dTypePredicateKind /*TypePredicateKind.This*/>("kind"); }
	inline void _impl_js_jts_dTypePredicateBase::kind(_js_jts_dTypePredicateKind /*TypePredicateKind.This*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dTypePredicateBase::type() noexcept { return _getProperty<_js_jts_dType>("type"); }
	inline void _impl_js_jts_dTypePredicateBase::type(_js_jts_dType v) noexcept { _setProperty("type", v); }
	inline auto _impl_js_jts_dThisTypePredicate::kind() noexcept { return _getProperty<_js_jts_dTypePredicateKind /*TypePredicateKind.This*/>("kind"); }
	inline void _impl_js_jts_dThisTypePredicate::kind(_js_jts_dTypePredicateKind /*TypePredicateKind.This*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dIdentifierTypePredicate::kind() noexcept { return _getProperty<_js_jts_dTypePredicateKind /*TypePredicateKind.Identifier*/>("kind"); }
	inline void _impl_js_jts_dIdentifierTypePredicate::kind(_js_jts_dTypePredicateKind /*TypePredicateKind.Identifier*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dIdentifierTypePredicate::parameterName() noexcept { return _getProperty<js_string>("parameterName"); }
	inline void _impl_js_jts_dIdentifierTypePredicate::parameterName(js_string v) noexcept { _setProperty("parameterName", v); }
	inline auto _impl_js_jts_dIdentifierTypePredicate::parameterIndex() noexcept { return _getProperty<double>("parameterIndex"); }
	inline void _impl_js_jts_dIdentifierTypePredicate::parameterIndex(double v) noexcept { _setProperty("parameterIndex", v); }
	inline auto _impl_js_jts_dSymbol::flags() noexcept { return _getProperty<_js_jts_dSymbolFlags /*SymbolFlags.None*/>("flags"); }
	inline void _impl_js_jts_dSymbol::flags(_js_jts_dSymbolFlags /*SymbolFlags.None*/ v) noexcept { _setProperty("flags", v); }
	inline auto _impl_js_jts_dSymbol::escapedName() noexcept { return _getProperty<js_unknown /*flags=1048576: __String ()*/>("escapedName"); }
	inline void _impl_js_jts_dSymbol::escapedName(js_unknown /*flags=1048576: __String ()*/ v) noexcept { _setProperty("escapedName", v); }
	inline auto _impl_js_jts_dSymbol::declarations() noexcept { return _getProperty<js::Array<_js_jts_dDeclaration>>("declarations"); }
	inline void _impl_js_jts_dSymbol::declarations(js::Array<_js_jts_dDeclaration> v) noexcept { _setProperty("declarations", v); }
	inline auto _impl_js_jts_dSymbol::valueDeclaration() noexcept { return _getProperty<_js_jts_dDeclaration>("valueDeclaration"); }
	inline void _impl_js_jts_dSymbol::valueDeclaration(_js_jts_dDeclaration v) noexcept { _setProperty("valueDeclaration", v); }
	inline auto _impl_js_jts_dSymbol::name() noexcept { return _getProperty<js_string>("name"); }
	inline auto _impl_js_jts_dSymbol::getDeclarations() noexcept {
		return _call<js_union<js::Array<_js_jts_dDeclaration>, js_undefined>>("getDeclarations");
	}
	inline auto _impl_js_jts_dSymbol::getDocumentationComment(js_union<_js_jts_dTypeChecker, js_undefined> typeChecker) noexcept {
		return _call<js::Array<_js_jts_dSymbolDisplayPart>>("getDocumentationComment", typeChecker);
	}
	inline auto _impl_js_jts_dSymbol::getEscapedName() noexcept {
		return _call<js_unknown /*flags=1048576: __String ()*/>("getEscapedName");
	}
	inline auto _impl_js_jts_dSymbol::getFlags() noexcept {
		return _call<_js_jts_dSymbolFlags /*SymbolFlags.None*/>("getFlags");
	}
	inline auto _impl_js_jts_dSymbol::getJsDocTags() noexcept {
		return _call<js::Array<_js_jts_dJSDocTagInfo>>("getJsDocTags");
	}
	inline auto _impl_js_jts_dSymbol::getName() noexcept {
		return _call<js_string>("getName");
	}
	inline auto _impl_js_jts_dReadonlyUnderscoreEscapedMap::size() noexcept { return _getProperty<double>("size"); }
	inline auto _impl_js_jts_dReadonlyUnderscoreEscapedMap::entries() noexcept {
		return _call<js_unknown /*flags=524288: Iterator<[__String, T]> (TypeReference=ts.Iterator)*/>("entries");
	}
	inline auto _impl_js_jts_dReadonlyUnderscoreEscapedMap::forEach(js_function<void(js_unknown /*flags=262144: T ()*/, js_unknown /*flags=1048576: __String ()*/)> action) noexcept {
		return _call<void>("forEach", action);
	}
	inline auto _impl_js_jts_dReadonlyUnderscoreEscapedMap::get(js_unknown /*flags=1048576: __String ()*/ key) noexcept {
		return _call<js_unknown /*flags=1048576: T | undefined ()*/>("get", key);
	}
	inline auto _impl_js_jts_dReadonlyUnderscoreEscapedMap::has(js_unknown /*flags=1048576: __String ()*/ key) noexcept {
		return _call<bool /*false*/>("has", key);
	}
	inline auto _impl_js_jts_dReadonlyUnderscoreEscapedMap::keys() noexcept {
		return _call<js_unknown /*flags=524288: Iterator<__String> (TypeReference=ts.Iterator)*/>("keys");
	}
	inline auto _impl_js_jts_dReadonlyUnderscoreEscapedMap::values() noexcept {
		return _call<js_unknown /*flags=524288: Iterator<T> (TypeReference=ts.Iterator)*/>("values");
	}
	inline auto _impl_js_jts_dUnderscoreEscapedMap::clear() noexcept {
		return _call<void>("clear");
	}
	inline auto _impl_js_jts_dUnderscoreEscapedMap::delete_(js_unknown /*flags=1048576: __String ()*/ key) noexcept {
		return _call<bool /*false*/>("delete", key);
	}
	inline auto _impl_js_jts_dUnderscoreEscapedMap::set(js_unknown /*flags=1048576: __String ()*/ key, js_unknown /*flags=262144: T ()*/ value) noexcept {
		return _call<js_unknown /*flags=262144: this ()*/>("set", key, value);
	}
	inline auto _impl_js_jts_dType::flags() noexcept { return _getProperty<_js_jts_dTypeFlags /*TypeFlags.Any*/>("flags"); }
	inline void _impl_js_jts_dType::flags(_js_jts_dTypeFlags /*TypeFlags.Any*/ v) noexcept { _setProperty("flags", v); }
	inline auto _impl_js_jts_dType::symbol() noexcept { return _getProperty<_js_jts_dSymbol>("symbol"); }
	inline void _impl_js_jts_dType::symbol(_js_jts_dSymbol v) noexcept { _setProperty("symbol", v); }
	inline auto _impl_js_jts_dType::getApparentProperties() noexcept {
		return _call<js::Array<_js_jts_dSymbol>>("getApparentProperties");
	}
	inline auto _impl_js_jts_dType::getBaseTypes() noexcept {
		return _call<js_union<js::Array<js_union<_js_jts_dIntersectionType, _js_jts_dObjectType>>, js_undefined>>("getBaseTypes");
	}
	inline auto _impl_js_jts_dType::getCallSignatures() noexcept {
		return _call<js::ReadonlyArray<_js_jts_dSignature>>("getCallSignatures");
	}
	inline auto _impl_js_jts_dType::getConstraint() noexcept {
		return _call<js_union<_js_jts_dType, js_undefined>>("getConstraint");
	}
	inline auto _impl_js_jts_dType::getConstructSignatures() noexcept {
		return _call<js::ReadonlyArray<_js_jts_dSignature>>("getConstructSignatures");
	}
	inline auto _impl_js_jts_dType::getDefault() noexcept {
		return _call<js_union<_js_jts_dType, js_undefined>>("getDefault");
	}
	inline auto _impl_js_jts_dType::getFlags() noexcept {
		return _call<_js_jts_dTypeFlags /*TypeFlags.Any*/>("getFlags");
	}
	inline auto _impl_js_jts_dType::getNonNullableType() noexcept {
		return _call<_js_jts_dType>("getNonNullableType");
	}
	inline auto _impl_js_jts_dType::getNumberIndexType() noexcept {
		return _call<js_union<_js_jts_dType, js_undefined>>("getNumberIndexType");
	}
	inline auto _impl_js_jts_dType::getProperties() noexcept {
		return _call<js::Array<_js_jts_dSymbol>>("getProperties");
	}
	inline auto _impl_js_jts_dType::getProperty(js_string propertyName) noexcept {
		return _call<js_union<_js_jts_dSymbol, js_undefined>>("getProperty", propertyName);
	}
	inline auto _impl_js_jts_dType::getStringIndexType() noexcept {
		return _call<js_union<_js_jts_dType, js_undefined>>("getStringIndexType");
	}
	inline auto _impl_js_jts_dType::getSymbol() noexcept {
		return _call<js_union<_js_jts_dSymbol, js_undefined>>("getSymbol");
	}
	inline auto _impl_js_jts_dType::isClass() noexcept {
		return _call<bool /*false*/>("isClass");
	}
	inline auto _impl_js_jts_dType::isClassOrInterface() noexcept {
		return _call<bool /*false*/>("isClassOrInterface");
	}
	inline auto _impl_js_jts_dType::isIntersection() noexcept {
		return _call<bool /*false*/>("isIntersection");
	}
	inline auto _impl_js_jts_dType::isLiteral() noexcept {
		return _call<bool /*false*/>("isLiteral");
	}
	inline auto _impl_js_jts_dType::isNumberLiteral() noexcept {
		return _call<bool /*false*/>("isNumberLiteral");
	}
	inline auto _impl_js_jts_dType::isStringLiteral() noexcept {
		return _call<bool /*false*/>("isStringLiteral");
	}
	inline auto _impl_js_jts_dType::isTypeParameter() noexcept {
		return _call<bool /*false*/>("isTypeParameter");
	}
	inline auto _impl_js_jts_dType::isUnion() noexcept {
		return _call<bool /*false*/>("isUnion");
	}
	inline auto _impl_js_jts_dType::isUnionOrIntersection() noexcept {
		return _call<bool /*false*/>("isUnionOrIntersection");
	}
	inline auto _impl_js_jts_dLiteralType::value() noexcept { return _getProperty<js_union<_js_jts_dPseudoBigInt, double, js_string>>("value"); }
	inline void _impl_js_jts_dLiteralType::value(js_union<_js_jts_dPseudoBigInt, double, js_string> v) noexcept { _setProperty("value", v); }
	inline auto _impl_js_jts_dLiteralType::freshType() noexcept { return _getProperty<_js_jts_dLiteralType>("freshType"); }
	inline void _impl_js_jts_dLiteralType::freshType(_js_jts_dLiteralType v) noexcept { _setProperty("freshType", v); }
	inline auto _impl_js_jts_dLiteralType::regularType() noexcept { return _getProperty<_js_jts_dLiteralType>("regularType"); }
	inline void _impl_js_jts_dLiteralType::regularType(_js_jts_dLiteralType v) noexcept { _setProperty("regularType", v); }
	inline auto _impl_js_jts_dUniqueESSymbolType::symbol() noexcept { return _getProperty<_js_jts_dSymbol>("symbol"); }
	inline void _impl_js_jts_dUniqueESSymbolType::symbol(_js_jts_dSymbol v) noexcept { _setProperty("symbol", v); }
	inline auto _impl_js_jts_dUniqueESSymbolType::escapedName() noexcept { return _getProperty<js_unknown /*flags=1048576: __String ()*/>("escapedName"); }
	inline void _impl_js_jts_dUniqueESSymbolType::escapedName(js_unknown /*flags=1048576: __String ()*/ v) noexcept { _setProperty("escapedName", v); }
	inline auto _impl_js_jts_dStringLiteralType::value() noexcept { return _getProperty<js_string>("value"); }
	inline void _impl_js_jts_dStringLiteralType::value(js_string v) noexcept { _setProperty("value", v); }
	inline auto _impl_js_jts_dNumberLiteralType::value() noexcept { return _getProperty<double>("value"); }
	inline void _impl_js_jts_dNumberLiteralType::value(double v) noexcept { _setProperty("value", v); }
	inline auto _impl_js_jts_dBigIntLiteralType::value() noexcept { return _getProperty<_js_jts_dPseudoBigInt>("value"); }
	inline void _impl_js_jts_dBigIntLiteralType::value(_js_jts_dPseudoBigInt v) noexcept { _setProperty("value", v); }
	inline auto _impl_js_jts_dObjectType::objectFlags() noexcept { return _getProperty<_js_jts_dObjectFlags /*ObjectFlags.Class*/>("objectFlags"); }
	inline void _impl_js_jts_dObjectType::objectFlags(_js_jts_dObjectFlags /*ObjectFlags.Class*/ v) noexcept { _setProperty("objectFlags", v); }
	inline auto _impl_js_jts_dInterfaceType::typeParameters() noexcept { return _getProperty<js_union<js::Array<_js_jts_dTypeParameter>, js_undefined>>("typeParameters"); }
	inline void _impl_js_jts_dInterfaceType::typeParameters(js_union<js::Array<_js_jts_dTypeParameter>, js_undefined> v) noexcept { _setProperty("typeParameters", v); }
	inline auto _impl_js_jts_dInterfaceType::outerTypeParameters() noexcept { return _getProperty<js_union<js::Array<_js_jts_dTypeParameter>, js_undefined>>("outerTypeParameters"); }
	inline void _impl_js_jts_dInterfaceType::outerTypeParameters(js_union<js::Array<_js_jts_dTypeParameter>, js_undefined> v) noexcept { _setProperty("outerTypeParameters", v); }
	inline auto _impl_js_jts_dInterfaceType::localTypeParameters() noexcept { return _getProperty<js_union<js::Array<_js_jts_dTypeParameter>, js_undefined>>("localTypeParameters"); }
	inline void _impl_js_jts_dInterfaceType::localTypeParameters(js_union<js::Array<_js_jts_dTypeParameter>, js_undefined> v) noexcept { _setProperty("localTypeParameters", v); }
	inline auto _impl_js_jts_dInterfaceType::thisType() noexcept { return _getProperty<js_union<_js_jts_dTypeParameter, js_undefined>>("thisType"); }
	inline void _impl_js_jts_dInterfaceType::thisType(js_union<_js_jts_dTypeParameter, js_undefined> v) noexcept { _setProperty("thisType", v); }
	inline auto _impl_js_jts_dInterfaceTypeWithDeclaredMembers::declaredProperties() noexcept { return _getProperty<js::Array<_js_jts_dSymbol>>("declaredProperties"); }
	inline void _impl_js_jts_dInterfaceTypeWithDeclaredMembers::declaredProperties(js::Array<_js_jts_dSymbol> v) noexcept { _setProperty("declaredProperties", v); }
	inline auto _impl_js_jts_dInterfaceTypeWithDeclaredMembers::declaredCallSignatures() noexcept { return _getProperty<js::Array<_js_jts_dSignature>>("declaredCallSignatures"); }
	inline void _impl_js_jts_dInterfaceTypeWithDeclaredMembers::declaredCallSignatures(js::Array<_js_jts_dSignature> v) noexcept { _setProperty("declaredCallSignatures", v); }
	inline auto _impl_js_jts_dInterfaceTypeWithDeclaredMembers::declaredConstructSignatures() noexcept { return _getProperty<js::Array<_js_jts_dSignature>>("declaredConstructSignatures"); }
	inline void _impl_js_jts_dInterfaceTypeWithDeclaredMembers::declaredConstructSignatures(js::Array<_js_jts_dSignature> v) noexcept { _setProperty("declaredConstructSignatures", v); }
	inline auto _impl_js_jts_dTypeReference::target() noexcept { return _getProperty<_js_jts_dGenericType>("target"); }
	inline void _impl_js_jts_dTypeReference::target(_js_jts_dGenericType v) noexcept { _setProperty("target", v); }
	inline auto _impl_js_jts_dTupleType::minLength() noexcept { return _getProperty<double>("minLength"); }
	inline void _impl_js_jts_dTupleType::minLength(double v) noexcept { _setProperty("minLength", v); }
	inline auto _impl_js_jts_dTupleType::hasRestElement() noexcept { return _getProperty<bool /*false*/>("hasRestElement"); }
	inline void _impl_js_jts_dTupleType::hasRestElement(bool /*false*/ v) noexcept { _setProperty("hasRestElement", v); }
	inline auto _impl_js_jts_dTupleType::readonly() noexcept { return _getProperty<bool /*false*/>("readonly"); }
	inline void _impl_js_jts_dTupleType::readonly(bool /*false*/ v) noexcept { _setProperty("readonly", v); }
	inline auto _impl_js_jts_dTupleTypeReference::target() noexcept { return _getProperty<_js_jts_dTupleType>("target"); }
	inline void _impl_js_jts_dTupleTypeReference::target(_js_jts_dTupleType v) noexcept { _setProperty("target", v); }
	inline auto _impl_js_jts_dUnionOrIntersectionType::types() noexcept { return _getProperty<js::Array<_js_jts_dType>>("types"); }
	inline void _impl_js_jts_dUnionOrIntersectionType::types(js::Array<_js_jts_dType> v) noexcept { _setProperty("types", v); }
	inline auto _impl_js_jts_dEvolvingArrayType::elementType() noexcept { return _getProperty<_js_jts_dType>("elementType"); }
	inline void _impl_js_jts_dEvolvingArrayType::elementType(_js_jts_dType v) noexcept { _setProperty("elementType", v); }
	inline auto _impl_js_jts_dIndexedAccessType::objectType() noexcept { return _getProperty<_js_jts_dType>("objectType"); }
	inline void _impl_js_jts_dIndexedAccessType::objectType(_js_jts_dType v) noexcept { _setProperty("objectType", v); }
	inline auto _impl_js_jts_dIndexedAccessType::indexType() noexcept { return _getProperty<_js_jts_dType>("indexType"); }
	inline void _impl_js_jts_dIndexedAccessType::indexType(_js_jts_dType v) noexcept { _setProperty("indexType", v); }
	inline auto _impl_js_jts_dIndexType::type() noexcept { return _getProperty<js_union<_js_jts_dInstantiableType, _js_jts_dUnionOrIntersectionType>>("type"); }
	inline void _impl_js_jts_dIndexType::type(js_union<_js_jts_dInstantiableType, _js_jts_dUnionOrIntersectionType> v) noexcept { _setProperty("type", v); }
	inline auto _impl_js_jts_dConditionalRoot::node() noexcept { return _getProperty<_js_jts_dConditionalTypeNode>("node"); }
	inline void _impl_js_jts_dConditionalRoot::node(_js_jts_dConditionalTypeNode v) noexcept { _setProperty("node", v); }
	inline auto _impl_js_jts_dConditionalRoot::checkType() noexcept { return _getProperty<_js_jts_dType>("checkType"); }
	inline void _impl_js_jts_dConditionalRoot::checkType(_js_jts_dType v) noexcept { _setProperty("checkType", v); }
	inline auto _impl_js_jts_dConditionalRoot::extendsType() noexcept { return _getProperty<_js_jts_dType>("extendsType"); }
	inline void _impl_js_jts_dConditionalRoot::extendsType(_js_jts_dType v) noexcept { _setProperty("extendsType", v); }
	inline auto _impl_js_jts_dConditionalRoot::trueType() noexcept { return _getProperty<_js_jts_dType>("trueType"); }
	inline void _impl_js_jts_dConditionalRoot::trueType(_js_jts_dType v) noexcept { _setProperty("trueType", v); }
	inline auto _impl_js_jts_dConditionalRoot::falseType() noexcept { return _getProperty<_js_jts_dType>("falseType"); }
	inline void _impl_js_jts_dConditionalRoot::falseType(_js_jts_dType v) noexcept { _setProperty("falseType", v); }
	inline auto _impl_js_jts_dConditionalRoot::isDistributive() noexcept { return _getProperty<bool /*false*/>("isDistributive"); }
	inline void _impl_js_jts_dConditionalRoot::isDistributive(bool /*false*/ v) noexcept { _setProperty("isDistributive", v); }
	inline auto _impl_js_jts_dConditionalType::root() noexcept { return _getProperty<_js_jts_dConditionalRoot>("root"); }
	inline void _impl_js_jts_dConditionalType::root(_js_jts_dConditionalRoot v) noexcept { _setProperty("root", v); }
	inline auto _impl_js_jts_dConditionalType::checkType() noexcept { return _getProperty<_js_jts_dType>("checkType"); }
	inline void _impl_js_jts_dConditionalType::checkType(_js_jts_dType v) noexcept { _setProperty("checkType", v); }
	inline auto _impl_js_jts_dConditionalType::extendsType() noexcept { return _getProperty<_js_jts_dType>("extendsType"); }
	inline void _impl_js_jts_dConditionalType::extendsType(_js_jts_dType v) noexcept { _setProperty("extendsType", v); }
	inline auto _impl_js_jts_dConditionalType::resolvedTrueType() noexcept { return _getProperty<_js_jts_dType>("resolvedTrueType"); }
	inline void _impl_js_jts_dConditionalType::resolvedTrueType(_js_jts_dType v) noexcept { _setProperty("resolvedTrueType", v); }
	inline auto _impl_js_jts_dConditionalType::resolvedFalseType() noexcept { return _getProperty<_js_jts_dType>("resolvedFalseType"); }
	inline void _impl_js_jts_dConditionalType::resolvedFalseType(_js_jts_dType v) noexcept { _setProperty("resolvedFalseType", v); }
	inline auto _impl_js_jts_dSubstitutionType::typeVariable() noexcept { return _getProperty<js_union<_js_jts_dIndexedAccessType, _js_jts_dTypeParameter>>("typeVariable"); }
	inline void _impl_js_jts_dSubstitutionType::typeVariable(js_union<_js_jts_dIndexedAccessType, _js_jts_dTypeParameter> v) noexcept { _setProperty("typeVariable", v); }
	inline auto _impl_js_jts_dSubstitutionType::substitute() noexcept { return _getProperty<_js_jts_dType>("substitute"); }
	inline void _impl_js_jts_dSubstitutionType::substitute(_js_jts_dType v) noexcept { _setProperty("substitute", v); }
	inline auto _impl_js_jts_dSignature::parameters() noexcept { return _getProperty<js::ReadonlyArray<_js_jts_dSymbol>>("parameters"); }
	inline void _impl_js_jts_dSignature::parameters(js::ReadonlyArray<_js_jts_dSymbol> v) noexcept { _setProperty("parameters", v); }
	inline auto _impl_js_jts_dSignature::getDeclaration() noexcept {
		return _call<js_union<_js_jts_dArrowFunction, _js_jts_dCallSignatureDeclaration, _js_jts_dConstructSignatureDeclaration, _js_jts_dConstructorDeclaration, _js_jts_dConstructorTypeNode, _js_jts_dFunctionDeclaration, _js_jts_dFunctionExpression, _js_jts_dFunctionTypeNode, _js_jts_dGetAccessorDeclaration, _js_jts_dIndexSignatureDeclaration, _js_jts_dJSDocFunctionType, _js_jts_dMethodDeclaration, _js_jts_dMethodSignature, _js_jts_dSetAccessorDeclaration>>("getDeclaration");
	}
	inline auto _impl_js_jts_dSignature::getDocumentationComment(js_union<_js_jts_dTypeChecker, js_undefined> typeChecker) noexcept {
		return _call<js::Array<_js_jts_dSymbolDisplayPart>>("getDocumentationComment", typeChecker);
	}
	inline auto _impl_js_jts_dSignature::getJsDocTags() noexcept {
		return _call<js::Array<_js_jts_dJSDocTagInfo>>("getJsDocTags");
	}
	inline auto _impl_js_jts_dSignature::getParameters() noexcept {
		return _call<js::Array<_js_jts_dSymbol>>("getParameters");
	}
	inline auto _impl_js_jts_dSignature::getReturnType() noexcept {
		return _call<_js_jts_dType>("getReturnType");
	}
	inline auto _impl_js_jts_dSignature::getTypeParameters() noexcept {
		return _call<js_union<js::Array<_js_jts_dTypeParameter>, js_undefined>>("getTypeParameters");
	}
	inline auto _impl_js_jts_dIndexInfo::type() noexcept { return _getProperty<_js_jts_dType>("type"); }
	inline void _impl_js_jts_dIndexInfo::type(_js_jts_dType v) noexcept { _setProperty("type", v); }
	inline auto _impl_js_jts_dIndexInfo::isReadonly() noexcept { return _getProperty<bool /*false*/>("isReadonly"); }
	inline void _impl_js_jts_dIndexInfo::isReadonly(bool /*false*/ v) noexcept { _setProperty("isReadonly", v); }
	inline auto _impl_js_jts_dFileExtensionInfo::extension() noexcept { return _getProperty<js_string>("extension"); }
	inline void _impl_js_jts_dFileExtensionInfo::extension(js_string v) noexcept { _setProperty("extension", v); }
	inline auto _impl_js_jts_dFileExtensionInfo::isMixedContent() noexcept { return _getProperty<bool /*false*/>("isMixedContent"); }
	inline void _impl_js_jts_dFileExtensionInfo::isMixedContent(bool /*false*/ v) noexcept { _setProperty("isMixedContent", v); }
	inline auto _impl_js_jts_dDiagnosticMessage::key() noexcept { return _getProperty<js_string>("key"); }
	inline void _impl_js_jts_dDiagnosticMessage::key(js_string v) noexcept { _setProperty("key", v); }
	inline auto _impl_js_jts_dDiagnosticMessage::category() noexcept { return _getProperty<_js_jts_dDiagnosticCategory /*DiagnosticCategory.Warning*/>("category"); }
	inline void _impl_js_jts_dDiagnosticMessage::category(_js_jts_dDiagnosticCategory /*DiagnosticCategory.Warning*/ v) noexcept { _setProperty("category", v); }
	inline auto _impl_js_jts_dDiagnosticMessage::code() noexcept { return _getProperty<double>("code"); }
	inline void _impl_js_jts_dDiagnosticMessage::code(double v) noexcept { _setProperty("code", v); }
	inline auto _impl_js_jts_dDiagnosticMessage::message() noexcept { return _getProperty<js_string>("message"); }
	inline void _impl_js_jts_dDiagnosticMessage::message(js_string v) noexcept { _setProperty("message", v); }
	inline auto _impl_js_jts_dDiagnosticMessageChain::messageText() noexcept { return _getProperty<js_string>("messageText"); }
	inline void _impl_js_jts_dDiagnosticMessageChain::messageText(js_string v) noexcept { _setProperty("messageText", v); }
	inline auto _impl_js_jts_dDiagnosticMessageChain::category() noexcept { return _getProperty<_js_jts_dDiagnosticCategory /*DiagnosticCategory.Warning*/>("category"); }
	inline void _impl_js_jts_dDiagnosticMessageChain::category(_js_jts_dDiagnosticCategory /*DiagnosticCategory.Warning*/ v) noexcept { _setProperty("category", v); }
	inline auto _impl_js_jts_dDiagnosticMessageChain::code() noexcept { return _getProperty<double>("code"); }
	inline void _impl_js_jts_dDiagnosticMessageChain::code(double v) noexcept { _setProperty("code", v); }
	inline auto _impl_js_jts_dDiagnosticRelatedInformation::category() noexcept { return _getProperty<_js_jts_dDiagnosticCategory /*DiagnosticCategory.Warning*/>("category"); }
	inline void _impl_js_jts_dDiagnosticRelatedInformation::category(_js_jts_dDiagnosticCategory /*DiagnosticCategory.Warning*/ v) noexcept { _setProperty("category", v); }
	inline auto _impl_js_jts_dDiagnosticRelatedInformation::code() noexcept { return _getProperty<double>("code"); }
	inline void _impl_js_jts_dDiagnosticRelatedInformation::code(double v) noexcept { _setProperty("code", v); }
	inline auto _impl_js_jts_dDiagnosticRelatedInformation::file() noexcept { return _getProperty<js_union<_js_jts_dSourceFile, js_undefined>>("file"); }
	inline void _impl_js_jts_dDiagnosticRelatedInformation::file(js_union<_js_jts_dSourceFile, js_undefined> v) noexcept { _setProperty("file", v); }
	inline auto _impl_js_jts_dDiagnosticRelatedInformation::start() noexcept { return _getProperty<js_union<double, js_undefined>>("start"); }
	inline void _impl_js_jts_dDiagnosticRelatedInformation::start(js_union<double, js_undefined> v) noexcept { _setProperty("start", v); }
	inline auto _impl_js_jts_dDiagnosticRelatedInformation::length() noexcept { return _getProperty<js_union<double, js_undefined>>("length"); }
	inline void _impl_js_jts_dDiagnosticRelatedInformation::length(js_union<double, js_undefined> v) noexcept { _setProperty("length", v); }
	inline auto _impl_js_jts_dDiagnosticRelatedInformation::messageText() noexcept { return _getProperty<js_union<_js_jts_dDiagnosticMessageChain, js_string>>("messageText"); }
	inline void _impl_js_jts_dDiagnosticRelatedInformation::messageText(js_union<_js_jts_dDiagnosticMessageChain, js_string> v) noexcept { _setProperty("messageText", v); }
	inline auto _impl_js_jts_dDiagnosticWithLocation::file() noexcept { return _getProperty<_js_jts_dSourceFile>("file"); }
	inline void _impl_js_jts_dDiagnosticWithLocation::file(_js_jts_dSourceFile v) noexcept { _setProperty("file", v); }
	inline auto _impl_js_jts_dDiagnosticWithLocation::start() noexcept { return _getProperty<double>("start"); }
	inline void _impl_js_jts_dDiagnosticWithLocation::start(double v) noexcept { _setProperty("start", v); }
	inline auto _impl_js_jts_dDiagnosticWithLocation::length() noexcept { return _getProperty<double>("length"); }
	inline void _impl_js_jts_dDiagnosticWithLocation::length(double v) noexcept { _setProperty("length", v); }
	inline auto _impl_js_jts_dPluginImport::name() noexcept { return _getProperty<js_string>("name"); }
	inline void _impl_js_jts_dPluginImport::name(js_string v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dProjectReference::path() noexcept { return _getProperty<js_string>("path"); }
	inline void _impl_js_jts_dProjectReference::path(js_string v) noexcept { _setProperty("path", v); }
	inline auto _impl_js_jts_dLineAndCharacter::line() noexcept { return _getProperty<double>("line"); }
	inline void _impl_js_jts_dLineAndCharacter::line(double v) noexcept { _setProperty("line", v); }
	inline auto _impl_js_jts_dLineAndCharacter::character() noexcept { return _getProperty<double>("character"); }
	inline void _impl_js_jts_dLineAndCharacter::character(double v) noexcept { _setProperty("character", v); }
	inline auto _impl_js_jts_dParsedCommandLine::options() noexcept { return _getProperty<_js_jts_dCompilerOptions>("options"); }
	inline void _impl_js_jts_dParsedCommandLine::options(_js_jts_dCompilerOptions v) noexcept { _setProperty("options", v); }
	inline auto _impl_js_jts_dParsedCommandLine::fileNames() noexcept { return _getProperty<js::Array<js_string>>("fileNames"); }
	inline void _impl_js_jts_dParsedCommandLine::fileNames(js::Array<js_string> v) noexcept { _setProperty("fileNames", v); }
	inline auto _impl_js_jts_dParsedCommandLine::errors() noexcept { return _getProperty<js::Array<_js_jts_dDiagnostic>>("errors"); }
	inline void _impl_js_jts_dParsedCommandLine::errors(js::Array<_js_jts_dDiagnostic> v) noexcept { _setProperty("errors", v); }
	inline auto _impl_js_jts_dExpandResult::fileNames() noexcept { return _getProperty<js::Array<js_string>>("fileNames"); }
	inline void _impl_js_jts_dExpandResult::fileNames(js::Array<js_string> v) noexcept { _setProperty("fileNames", v); }
	inline auto _impl_js_jts_dExpandResult::wildcardDirectories() noexcept { return _getProperty<js_unknown /*flags=524288: MapLike<WatchDirectoryFlags> (TypeReference=ts.MapLike)*/>("wildcardDirectories"); }
	inline void _impl_js_jts_dExpandResult::wildcardDirectories(js_unknown /*flags=524288: MapLike<WatchDirectoryFlags> (TypeReference=ts.MapLike)*/ v) noexcept { _setProperty("wildcardDirectories", v); }
	inline auto _impl_js_jts_dCreateProgramOptions::rootNames() noexcept { return _getProperty<js::ReadonlyArray<js_string>>("rootNames"); }
	inline void _impl_js_jts_dCreateProgramOptions::rootNames(js::ReadonlyArray<js_string> v) noexcept { _setProperty("rootNames", v); }
	inline auto _impl_js_jts_dCreateProgramOptions::options() noexcept { return _getProperty<_js_jts_dCompilerOptions>("options"); }
	inline void _impl_js_jts_dCreateProgramOptions::options(_js_jts_dCompilerOptions v) noexcept { _setProperty("options", v); }
	inline auto _impl_js_jts_dModuleResolutionHost::fileExists(js_string fileName) noexcept {
		return _call<bool /*false*/>("fileExists", fileName);
	}
	inline auto _impl_js_jts_dModuleResolutionHost::readFile(js_string fileName) noexcept {
		return _call<js_union<js_string, js_undefined>>("readFile", fileName);
	}
	inline auto _impl_js_jts_dResolvedModule::resolvedFileName() noexcept { return _getProperty<js_string>("resolvedFileName"); }
	inline void _impl_js_jts_dResolvedModule::resolvedFileName(js_string v) noexcept { _setProperty("resolvedFileName", v); }
	inline auto _impl_js_jts_dResolvedModuleFull::extension() noexcept { return _getProperty<_js_jts_dExtension /*Extension.Ts*/>("extension"); }
	inline void _impl_js_jts_dResolvedModuleFull::extension(_js_jts_dExtension /*Extension.Ts*/ v) noexcept { _setProperty("extension", v); }
	inline auto _impl_js_jts_dPackageId::name() noexcept { return _getProperty<js_string>("name"); }
	inline void _impl_js_jts_dPackageId::name(js_string v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dPackageId::subModuleName() noexcept { return _getProperty<js_string>("subModuleName"); }
	inline void _impl_js_jts_dPackageId::subModuleName(js_string v) noexcept { _setProperty("subModuleName", v); }
	inline auto _impl_js_jts_dPackageId::version() noexcept { return _getProperty<js_string>("version"); }
	inline void _impl_js_jts_dPackageId::version(js_string v) noexcept { _setProperty("version", v); }
	inline auto _impl_js_jts_dResolvedModuleWithFailedLookupLocations::resolvedModule() noexcept { return _getProperty<js_union<_js_jts_dResolvedModuleFull, js_undefined>>("resolvedModule"); }
	inline auto _impl_js_jts_dResolvedTypeReferenceDirective::primary() noexcept { return _getProperty<bool /*false*/>("primary"); }
	inline void _impl_js_jts_dResolvedTypeReferenceDirective::primary(bool /*false*/ v) noexcept { _setProperty("primary", v); }
	inline auto _impl_js_jts_dResolvedTypeReferenceDirective::resolvedFileName() noexcept { return _getProperty<js_union<js_string, js_undefined>>("resolvedFileName"); }
	inline void _impl_js_jts_dResolvedTypeReferenceDirective::resolvedFileName(js_union<js_string, js_undefined> v) noexcept { _setProperty("resolvedFileName", v); }
	inline auto _impl_js_jts_dResolvedTypeReferenceDirectiveWithFailedLookupLocations::resolvedTypeReferenceDirective() noexcept { return _getProperty<js_union<_js_jts_dResolvedTypeReferenceDirective, js_undefined>>("resolvedTypeReferenceDirective"); }
	inline auto _impl_js_jts_dResolvedTypeReferenceDirectiveWithFailedLookupLocations::failedLookupLocations() noexcept { return _getProperty<js::ReadonlyArray<js_string>>("failedLookupLocations"); }
	inline auto _impl_js_jts_dCompilerHost::writeFile() noexcept { return _getProperty<js_function<void(js_string, js_string, bool /*false*/, js_union<js_function<void(js_string)>, js_undefined>, js_union<js::ReadonlyArray<_js_jts_dSourceFile>, js_undefined>)>>("writeFile"); }
	inline void _impl_js_jts_dCompilerHost::writeFile(js_function<void(js_string, js_string, bool /*false*/, js_union<js_function<void(js_string)>, js_undefined>, js_union<js::ReadonlyArray<_js_jts_dSourceFile>, js_undefined>)> v) noexcept { _setProperty("writeFile", v); }
	inline auto _impl_js_jts_dCompilerHost::getCanonicalFileName(js_string fileName) noexcept {
		return _call<js_string>("getCanonicalFileName", fileName);
	}
	inline auto _impl_js_jts_dCompilerHost::getCurrentDirectory() noexcept {
		return _call<js_string>("getCurrentDirectory");
	}
	inline auto _impl_js_jts_dCompilerHost::getDefaultLibFileName(_js_jts_dCompilerOptions options) noexcept {
		return _call<js_string>("getDefaultLibFileName", options);
	}
	inline auto _impl_js_jts_dCompilerHost::getNewLine() noexcept {
		return _call<js_string>("getNewLine");
	}
	inline auto _impl_js_jts_dCompilerHost::getSourceFile(js_string fileName, _js_jts_dScriptTarget /*ScriptTarget.ES3*/ languageVersion, js_union<js_function<void(js_string)>, js_undefined> onError, js_union<bool /*false*/, js_undefined> shouldCreateNewSourceFile) noexcept {
		return _call<js_union<_js_jts_dSourceFile, js_undefined>>("getSourceFile", fileName, languageVersion, onError, shouldCreateNewSourceFile);
	}
	inline auto _impl_js_jts_dCompilerHost::useCaseSensitiveFileNames() noexcept {
		return _call<bool /*false*/>("useCaseSensitiveFileNames");
	}
	inline auto _impl_js_jts_dSourceMapSource::fileName() noexcept { return _getProperty<js_string>("fileName"); }
	inline void _impl_js_jts_dSourceMapSource::fileName(js_string v) noexcept { _setProperty("fileName", v); }
	inline auto _impl_js_jts_dSourceMapSource::text() noexcept { return _getProperty<js_string>("text"); }
	inline void _impl_js_jts_dSourceMapSource::text(js_string v) noexcept { _setProperty("text", v); }
	inline auto _impl_js_jts_dSourceMapSource::getLineAndCharacterOfPosition(double pos) noexcept {
		return _call<_js_jts_dLineAndCharacter>("getLineAndCharacterOfPosition", pos);
	}
	inline auto _impl_js_jts_dEmitHelper::name() noexcept { return _getProperty<js_string>("name"); }
	inline auto _impl_js_jts_dEmitHelper::scoped() noexcept { return _getProperty<bool /*false*/>("scoped"); }
	inline auto _impl_js_jts_dEmitHelper::text() noexcept { return _getProperty<js_union<js_function<js_string(js_function<js_string(js_string)>)>, js_string>>("text"); }
	inline auto _impl_js_jts_dUnscopedEmitHelper::scoped() noexcept { return _getProperty<bool /*false*/>("scoped"); }
	inline auto _impl_js_jts_dUnscopedEmitHelper::text() noexcept { return _getProperty<js_string>("text"); }
	inline auto _impl_js_jts_dTransformationContext::onSubstituteNode() noexcept { return _getProperty<js_function<_js_jts_dNode(_js_jts_dEmitHint /*EmitHint.SourceFile*/, _js_jts_dNode)>>("onSubstituteNode"); }
	inline void _impl_js_jts_dTransformationContext::onSubstituteNode(js_function<_js_jts_dNode(_js_jts_dEmitHint /*EmitHint.SourceFile*/, _js_jts_dNode)> v) noexcept { _setProperty("onSubstituteNode", v); }
	inline auto _impl_js_jts_dTransformationContext::onEmitNode() noexcept { return _getProperty<js_function<void(_js_jts_dEmitHint /*EmitHint.SourceFile*/, _js_jts_dNode, js_function<void(_js_jts_dEmitHint /*EmitHint.SourceFile*/, _js_jts_dNode)>)>>("onEmitNode"); }
	inline void _impl_js_jts_dTransformationContext::onEmitNode(js_function<void(_js_jts_dEmitHint /*EmitHint.SourceFile*/, _js_jts_dNode, js_function<void(_js_jts_dEmitHint /*EmitHint.SourceFile*/, _js_jts_dNode)>)> v) noexcept { _setProperty("onEmitNode", v); }
	inline auto _impl_js_jts_dTransformationContext::enableEmitNotification(_js_jts_dSyntaxKind /*SyntaxKind.Unknown*/ kind) noexcept {
		return _call<void>("enableEmitNotification", kind);
	}
	inline auto _impl_js_jts_dTransformationContext::enableSubstitution(_js_jts_dSyntaxKind /*SyntaxKind.Unknown*/ kind) noexcept {
		return _call<void>("enableSubstitution", kind);
	}
	inline auto _impl_js_jts_dTransformationContext::endLexicalEnvironment() noexcept {
		return _call<js_union<js::Array<_js_jts_dStatement>, js_undefined>>("endLexicalEnvironment");
	}
	inline auto _impl_js_jts_dTransformationContext::getCompilerOptions() noexcept {
		return _call<_js_jts_dCompilerOptions>("getCompilerOptions");
	}
	inline auto _impl_js_jts_dTransformationContext::hoistFunctionDeclaration(_js_jts_dFunctionDeclaration node) noexcept {
		return _call<void>("hoistFunctionDeclaration", node);
	}
	inline auto _impl_js_jts_dTransformationContext::hoistVariableDeclaration(_js_jts_dIdentifier node) noexcept {
		return _call<void>("hoistVariableDeclaration", node);
	}
	inline auto _impl_js_jts_dTransformationContext::isEmitNotificationEnabled(_js_jts_dNode node) noexcept {
		return _call<bool /*false*/>("isEmitNotificationEnabled", node);
	}
	inline auto _impl_js_jts_dTransformationContext::isSubstitutionEnabled(_js_jts_dNode node) noexcept {
		return _call<bool /*false*/>("isSubstitutionEnabled", node);
	}
	inline auto _impl_js_jts_dTransformationContext::readEmitHelpers() noexcept {
		return _call<js_union<js::Array<_js_jts_dEmitHelper>, js_undefined>>("readEmitHelpers");
	}
	inline auto _impl_js_jts_dTransformationContext::requestEmitHelper(_js_jts_dEmitHelper helper) noexcept {
		return _call<void>("requestEmitHelper", helper);
	}
	inline auto _impl_js_jts_dTransformationContext::resumeLexicalEnvironment() noexcept {
		return _call<void>("resumeLexicalEnvironment");
	}
	inline auto _impl_js_jts_dTransformationContext::startLexicalEnvironment() noexcept {
		return _call<void>("startLexicalEnvironment");
	}
	inline auto _impl_js_jts_dTransformationContext::suspendLexicalEnvironment() noexcept {
		return _call<void>("suspendLexicalEnvironment");
	}
	inline auto _impl_js_jts_dTransformationResult::transformed() noexcept { return _getProperty<js::Array<js_unknown /*flags=262144: T ()*/>>("transformed"); }
	inline void _impl_js_jts_dTransformationResult::transformed(js::Array<js_unknown /*flags=262144: T ()*/> v) noexcept { _setProperty("transformed", v); }
	inline auto _impl_js_jts_dTransformationResult::dispose() noexcept {
		return _call<void>("dispose");
	}
	inline auto _impl_js_jts_dTransformationResult::emitNodeWithNotification(_js_jts_dEmitHint /*EmitHint.SourceFile*/ hint, _js_jts_dNode node, js_function<void(_js_jts_dEmitHint /*EmitHint.SourceFile*/, _js_jts_dNode)> emitCallback) noexcept {
		return _call<void>("emitNodeWithNotification", hint, node, emitCallback);
	}
	inline auto _impl_js_jts_dTransformationResult::substituteNode(_js_jts_dEmitHint /*EmitHint.SourceFile*/ hint, _js_jts_dNode node) noexcept {
		return _call<_js_jts_dNode>("substituteNode", hint, node);
	}
	inline auto _impl_js_jts_dPrinter::printBundle(_js_jts_dBundle bundle) noexcept {
		return _call<js_string>("printBundle", bundle);
	}
	inline auto _impl_js_jts_dPrinter::printFile(_js_jts_dSourceFile sourceFile) noexcept {
		return _call<js_string>("printFile", sourceFile);
	}
	inline auto _impl_js_jts_dPrinter::printList(_js_jts_dListFormat /*ListFormat.None*/ format, js_unknown /*flags=524288: NodeArray<T> (TypeReference=ts.NodeArray)*/ list, _js_jts_dSourceFile sourceFile) noexcept {
		return _call<js_string>("printList", format, list, sourceFile);
	}
	inline auto _impl_js_jts_dPrinter::printNode(_js_jts_dEmitHint /*EmitHint.SourceFile*/ hint, _js_jts_dNode node, _js_jts_dSourceFile sourceFile) noexcept {
		return _call<js_string>("printNode", hint, node, sourceFile);
	}
	inline auto _impl_js_jts_dTextSpan::start() noexcept { return _getProperty<double>("start"); }
	inline void _impl_js_jts_dTextSpan::start(double v) noexcept { _setProperty("start", v); }
	inline auto _impl_js_jts_dTextSpan::length() noexcept { return _getProperty<double>("length"); }
	inline void _impl_js_jts_dTextSpan::length(double v) noexcept { _setProperty("length", v); }
	inline auto _impl_js_jts_dTextChangeRange::span() noexcept { return _getProperty<_js_jts_dTextSpan>("span"); }
	inline void _impl_js_jts_dTextChangeRange::span(_js_jts_dTextSpan v) noexcept { _setProperty("span", v); }
	inline auto _impl_js_jts_dTextChangeRange::newLength() noexcept { return _getProperty<double>("newLength"); }
	inline void _impl_js_jts_dTextChangeRange::newLength(double v) noexcept { _setProperty("newLength", v); }
	inline auto _impl_js_jts_dSyntaxList::_children() noexcept { return _getProperty<js::Array<_js_jts_dNode>>("_children"); }
	inline void _impl_js_jts_dSyntaxList::_children(js::Array<_js_jts_dNode> v) noexcept { _setProperty("_children", v); }
	inline auto _impl_js_jts_dPseudoBigInt::negative() noexcept { return _getProperty<bool /*false*/>("negative"); }
	inline void _impl_js_jts_dPseudoBigInt::negative(bool /*false*/ v) noexcept { _setProperty("negative", v); }
	inline auto _impl_js_jts_dPseudoBigInt::base10Value() noexcept { return _getProperty<js_string>("base10Value"); }
	inline void _impl_js_jts_dPseudoBigInt::base10Value(js_string v) noexcept { _setProperty("base10Value", v); }
	inline auto _impl_js_jts_dSystem::args() noexcept { return _getProperty<js::Array<js_string>>("args"); }
	inline void _impl_js_jts_dSystem::args(js::Array<js_string> v) noexcept { _setProperty("args", v); }
	inline auto _impl_js_jts_dSystem::newLine() noexcept { return _getProperty<js_string>("newLine"); }
	inline void _impl_js_jts_dSystem::newLine(js_string v) noexcept { _setProperty("newLine", v); }
	inline auto _impl_js_jts_dSystem::useCaseSensitiveFileNames() noexcept { return _getProperty<bool /*false*/>("useCaseSensitiveFileNames"); }
	inline void _impl_js_jts_dSystem::useCaseSensitiveFileNames(bool /*false*/ v) noexcept { _setProperty("useCaseSensitiveFileNames", v); }
	inline auto _impl_js_jts_dSystem::createDirectory(js_string path) noexcept {
		return _call<void>("createDirectory", path);
	}
	inline auto _impl_js_jts_dSystem::directoryExists(js_string path) noexcept {
		return _call<bool /*false*/>("directoryExists", path);
	}
	inline auto _impl_js_jts_dSystem::exit(js_union<double, js_undefined> exitCode) noexcept {
		return _call<void>("exit", exitCode);
	}
	inline auto _impl_js_jts_dSystem::fileExists(js_string path) noexcept {
		return _call<bool /*false*/>("fileExists", path);
	}
	inline auto _impl_js_jts_dSystem::getCurrentDirectory() noexcept {
		return _call<js_string>("getCurrentDirectory");
	}
	inline auto _impl_js_jts_dSystem::getDirectories(js_string path) noexcept {
		return _call<js::Array<js_string>>("getDirectories", path);
	}
	inline auto _impl_js_jts_dSystem::getExecutingFilePath() noexcept {
		return _call<js_string>("getExecutingFilePath");
	}
	inline auto _impl_js_jts_dSystem::readDirectory(js_string path, js_union<js::ReadonlyArray<js_string>, js_undefined> extensions, js_union<js::ReadonlyArray<js_string>, js_undefined> exclude, js_union<js::ReadonlyArray<js_string>, js_undefined> include, js_union<double, js_undefined> depth) noexcept {
		return _call<js::Array<js_string>>("readDirectory", path, extensions, exclude, include, depth);
	}
	inline auto _impl_js_jts_dSystem::readFile(js_string path, js_union<js_string, js_undefined> encoding) noexcept {
		return _call<js_union<js_string, js_undefined>>("readFile", path, encoding);
	}
	inline auto _impl_js_jts_dSystem::resolvePath(js_string path) noexcept {
		return _call<js_string>("resolvePath", path);
	}
	inline auto _impl_js_jts_dSystem::write(js_string s) noexcept {
		return _call<void>("write", s);
	}
	inline auto _impl_js_jts_dSystem::writeFile(js_string path, js_string data, js_union<bool /*false*/, js_undefined> writeByteOrderMark) noexcept {
		return _call<void>("writeFile", path, data, writeByteOrderMark);
	}
	inline auto _impl_js_jts_dFileWatcher::close() noexcept {
		return _call<void>("close");
	}
	inline auto _impl_js_jts_dScanner::getStartPos() noexcept {
		return _call<double>("getStartPos");
	}
	inline auto _impl_js_jts_dScanner::getText() noexcept {
		return _call<js_string>("getText");
	}
	inline auto _impl_js_jts_dScanner::getTextPos() noexcept {
		return _call<double>("getTextPos");
	}
	inline auto _impl_js_jts_dScanner::getToken() noexcept {
		return _call<_js_jts_dSyntaxKind /*SyntaxKind.Unknown*/>("getToken");
	}
	inline auto _impl_js_jts_dScanner::getTokenPos() noexcept {
		return _call<double>("getTokenPos");
	}
	inline auto _impl_js_jts_dScanner::getTokenText() noexcept {
		return _call<js_string>("getTokenText");
	}
	inline auto _impl_js_jts_dScanner::getTokenValue() noexcept {
		return _call<js_string>("getTokenValue");
	}
	inline auto _impl_js_jts_dScanner::hasExtendedUnicodeEscape() noexcept {
		return _call<bool /*false*/>("hasExtendedUnicodeEscape");
	}
	inline auto _impl_js_jts_dScanner::hasPrecedingLineBreak() noexcept {
		return _call<bool /*false*/>("hasPrecedingLineBreak");
	}
	inline auto _impl_js_jts_dScanner::isIdentifier() noexcept {
		return _call<bool /*false*/>("isIdentifier");
	}
	inline auto _impl_js_jts_dScanner::isReservedWord() noexcept {
		return _call<bool /*false*/>("isReservedWord");
	}
	inline auto _impl_js_jts_dScanner::isUnterminated() noexcept {
		return _call<bool /*false*/>("isUnterminated");
	}
	inline auto _impl_js_jts_dScanner::lookAhead(js_function<js_unknown /*flags=262144: T ()*/()> callback) noexcept {
		return _call<js_unknown /*flags=262144: T ()*/>("lookAhead", callback);
	}
	inline auto _impl_js_jts_dScanner::reScanGreaterToken() noexcept {
		return _call<_js_jts_dSyntaxKind /*SyntaxKind.Unknown*/>("reScanGreaterToken");
	}
	inline auto _impl_js_jts_dScanner::reScanJsxToken() noexcept {
		return _call<_js_jts_dSyntaxKind /*SyntaxKind.EndOfFileToken*/>("reScanJsxToken");
	}
	inline auto _impl_js_jts_dScanner::reScanLessThanToken() noexcept {
		return _call<_js_jts_dSyntaxKind /*SyntaxKind.Unknown*/>("reScanLessThanToken");
	}
	inline auto _impl_js_jts_dScanner::reScanSlashToken() noexcept {
		return _call<_js_jts_dSyntaxKind /*SyntaxKind.Unknown*/>("reScanSlashToken");
	}
	inline auto _impl_js_jts_dScanner::reScanTemplateToken() noexcept {
		return _call<_js_jts_dSyntaxKind /*SyntaxKind.Unknown*/>("reScanTemplateToken");
	}
	inline auto _impl_js_jts_dScanner::scan() noexcept {
		return _call<_js_jts_dSyntaxKind /*SyntaxKind.Unknown*/>("scan");
	}
	inline auto _impl_js_jts_dScanner::scanJsDocToken() noexcept {
		return _call<_js_jts_dSyntaxKind /*SyntaxKind.Unknown*/>("scanJsDocToken");
	}
	inline auto _impl_js_jts_dScanner::scanJsxAttributeValue() noexcept {
		return _call<_js_jts_dSyntaxKind /*SyntaxKind.Unknown*/>("scanJsxAttributeValue");
	}
	inline auto _impl_js_jts_dScanner::scanJsxIdentifier() noexcept {
		return _call<_js_jts_dSyntaxKind /*SyntaxKind.Unknown*/>("scanJsxIdentifier");
	}
	inline auto _impl_js_jts_dScanner::scanJsxToken() noexcept {
		return _call<_js_jts_dSyntaxKind /*SyntaxKind.EndOfFileToken*/>("scanJsxToken");
	}
	inline auto _impl_js_jts_dScanner::scanRange(double start, double length, js_function<js_unknown /*flags=262144: T ()*/()> callback) noexcept {
		return _call<js_unknown /*flags=262144: T ()*/>("scanRange", start, length, callback);
	}
	inline auto _impl_js_jts_dScanner::setLanguageVariant(_js_jts_dLanguageVariant /*LanguageVariant.Standard*/ variant) noexcept {
		return _call<void>("setLanguageVariant", variant);
	}
	inline auto _impl_js_jts_dScanner::setOnError(js_union<js_function<void(_js_jts_dDiagnosticMessage, double)>, js_undefined> onError) noexcept {
		return _call<void>("setOnError", onError);
	}
	inline auto _impl_js_jts_dScanner::setScriptTarget(_js_jts_dScriptTarget /*ScriptTarget.ES3*/ scriptTarget) noexcept {
		return _call<void>("setScriptTarget", scriptTarget);
	}
	inline auto _impl_js_jts_dScanner::setText(js_union<js_string, js_undefined> text, js_union<double, js_undefined> start, js_union<double, js_undefined> length) noexcept {
		return _call<void>("setText", text, start, length);
	}
	inline auto _impl_js_jts_dScanner::setTextPos(double textPos) noexcept {
		return _call<void>("setTextPos", textPos);
	}
	inline auto _impl_js_jts_dScanner::tryScan(js_function<js_unknown /*flags=262144: T ()*/()> callback) noexcept {
		return _call<js_unknown /*flags=262144: T ()*/>("tryScan", callback);
	}
	inline auto _impl_js_jts_dConfigFileDiagnosticsReporter::onUnRecoverableConfigFileDiagnostic() noexcept { return _getProperty<js_function<void(_js_jts_dDiagnostic)>>("onUnRecoverableConfigFileDiagnostic"); }
	inline void _impl_js_jts_dConfigFileDiagnosticsReporter::onUnRecoverableConfigFileDiagnostic(js_function<void(_js_jts_dDiagnostic)> v) noexcept { _setProperty("onUnRecoverableConfigFileDiagnostic", v); }
	inline auto _impl_js_jts_dParseConfigFileHost::getCurrentDirectory() noexcept {
		return _call<js_string>("getCurrentDirectory");
	}
	inline auto _impl_js_jts_dParsedTsconfig::raw() noexcept { return _getProperty<js_unknown>("raw"); }
	inline void _impl_js_jts_dParsedTsconfig::raw(js_unknown v) noexcept { _setProperty("raw", v); }
	inline auto _impl_js_jts_dExtendedConfigCacheEntry::extendedResult() noexcept { return _getProperty<_js_jts_dTsConfigSourceFile>("extendedResult"); }
	inline void _impl_js_jts_dExtendedConfigCacheEntry::extendedResult(_js_jts_dTsConfigSourceFile v) noexcept { _setProperty("extendedResult", v); }
	inline auto _impl_js_jts_dExtendedConfigCacheEntry::extendedConfig() noexcept { return _getProperty<js_union<_js_jts_dParsedTsconfig, js_undefined>>("extendedConfig"); }
	inline void _impl_js_jts_dExtendedConfigCacheEntry::extendedConfig(js_union<_js_jts_dParsedTsconfig, js_undefined> v) noexcept { _setProperty("extendedConfig", v); }
	inline auto _impl_js_jts_dNonRelativeModuleNameResolutionCache::getOrCreateCacheForModuleName(js_string nonRelativeModuleName, js_union<_js_jts_dResolvedProjectReference, js_undefined> redirectedReference) noexcept {
		return _call<_js_jts_dPerModuleNameCache>("getOrCreateCacheForModuleName", nonRelativeModuleName, redirectedReference);
	}
	inline auto _impl_js_jts_dModuleResolutionCache::getOrCreateCacheForDirectory(js_string directoryName, js_union<_js_jts_dResolvedProjectReference, js_undefined> redirectedReference) noexcept {
		return _call<js_unknown /*flags=524288: Map<ResolvedModuleWithFailedLookupLocations> (TypeReference=ts.Map)*/>("getOrCreateCacheForDirectory", directoryName, redirectedReference);
	}
	inline auto _impl_js_jts_dPerModuleNameCache::get(js_string directory) noexcept {
		return _call<js_union<_js_jts_dResolvedModuleWithFailedLookupLocations, js_undefined>>("get", directory);
	}
	inline auto _impl_js_jts_dPerModuleNameCache::set(js_string directory, _js_jts_dResolvedModuleWithFailedLookupLocations result) noexcept {
		return _call<void>("set", directory, result);
	}
	inline auto _impl_js_jts_dFormatDiagnosticsHost::getCanonicalFileName(js_string fileName) noexcept {
		return _call<js_string>("getCanonicalFileName", fileName);
	}
	inline auto _impl_js_jts_dFormatDiagnosticsHost::getCurrentDirectory() noexcept {
		return _call<js_string>("getCurrentDirectory");
	}
	inline auto _impl_js_jts_dFormatDiagnosticsHost::getNewLine() noexcept {
		return _call<js_string>("getNewLine");
	}
	inline auto _impl_js_jts_dResolveProjectReferencePathHost::fileExists(js_string fileName) noexcept {
		return _call<bool /*false*/>("fileExists", fileName);
	}
	inline auto _impl_js_jts_dEmitOutput::outputFiles() noexcept { return _getProperty<js::Array<_js_jts_dOutputFile>>("outputFiles"); }
	inline void _impl_js_jts_dEmitOutput::outputFiles(js::Array<_js_jts_dOutputFile> v) noexcept { _setProperty("outputFiles", v); }
	inline auto _impl_js_jts_dEmitOutput::emitSkipped() noexcept { return _getProperty<bool /*false*/>("emitSkipped"); }
	inline void _impl_js_jts_dEmitOutput::emitSkipped(bool /*false*/ v) noexcept { _setProperty("emitSkipped", v); }
	inline auto _impl_js_jts_dOutputFile::name() noexcept { return _getProperty<js_string>("name"); }
	inline void _impl_js_jts_dOutputFile::name(js_string v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dOutputFile::writeByteOrderMark() noexcept { return _getProperty<bool /*false*/>("writeByteOrderMark"); }
	inline void _impl_js_jts_dOutputFile::writeByteOrderMark(bool /*false*/ v) noexcept { _setProperty("writeByteOrderMark", v); }
	inline auto _impl_js_jts_dOutputFile::text() noexcept { return _getProperty<js_string>("text"); }
	inline void _impl_js_jts_dOutputFile::text(js_string v) noexcept { _setProperty("text", v); }
	inline auto _impl_js_jts_dBuilderProgramHost::useCaseSensitiveFileNames() noexcept {
		return _call<bool /*false*/>("useCaseSensitiveFileNames");
	}
	inline auto _impl_js_jts_dBuilderProgram::emit(js_union<_js_jts_dSourceFile, js_undefined> targetSourceFile, js_union<js_function<void(js_string, js_string, bool /*false*/, js_union<js_function<void(js_string)>, js_undefined>, js_union<js::ReadonlyArray<_js_jts_dSourceFile>, js_undefined>)>, js_undefined> writeFile, js_union<_js_jts_dCancellationToken, js_undefined> cancellationToken, js_union<bool /*false*/, js_undefined> emitOnlyDtsFiles, js_union<_js_jts_dCustomTransformers, js_undefined> customTransformers) noexcept {
		return _call<_js_jts_dEmitResult>("emit", targetSourceFile, writeFile, cancellationToken, emitOnlyDtsFiles, customTransformers);
	}
	inline auto _impl_js_jts_dBuilderProgram::getAllDependencies(_js_jts_dSourceFile sourceFile) noexcept {
		return _call<js::ReadonlyArray<js_string>>("getAllDependencies", sourceFile);
	}
	inline auto _impl_js_jts_dBuilderProgram::getCompilerOptions() noexcept {
		return _call<_js_jts_dCompilerOptions>("getCompilerOptions");
	}
	inline auto _impl_js_jts_dBuilderProgram::getConfigFileParsingDiagnostics() noexcept {
		return _call<js::ReadonlyArray<_js_jts_dDiagnostic>>("getConfigFileParsingDiagnostics");
	}
	inline auto _impl_js_jts_dBuilderProgram::getCurrentDirectory() noexcept {
		return _call<js_string>("getCurrentDirectory");
	}
	inline auto _impl_js_jts_dBuilderProgram::getDeclarationDiagnostics(js_union<_js_jts_dSourceFile, js_undefined> sourceFile, js_union<_js_jts_dCancellationToken, js_undefined> cancellationToken) noexcept {
		return _call<js::ReadonlyArray<_js_jts_dDiagnosticWithLocation>>("getDeclarationDiagnostics", sourceFile, cancellationToken);
	}
	inline auto _impl_js_jts_dBuilderProgram::getGlobalDiagnostics(js_union<_js_jts_dCancellationToken, js_undefined> cancellationToken) noexcept {
		return _call<js::ReadonlyArray<_js_jts_dDiagnostic>>("getGlobalDiagnostics", cancellationToken);
	}
	inline auto _impl_js_jts_dBuilderProgram::getOptionsDiagnostics(js_union<_js_jts_dCancellationToken, js_undefined> cancellationToken) noexcept {
		return _call<js::ReadonlyArray<_js_jts_dDiagnostic>>("getOptionsDiagnostics", cancellationToken);
	}
	inline auto _impl_js_jts_dBuilderProgram::getProgram() noexcept {
		return _call<_js_jts_dProgram>("getProgram");
	}
	inline auto _impl_js_jts_dBuilderProgram::getSemanticDiagnostics(js_union<_js_jts_dSourceFile, js_undefined> sourceFile, js_union<_js_jts_dCancellationToken, js_undefined> cancellationToken) noexcept {
		return _call<js::ReadonlyArray<_js_jts_dDiagnostic>>("getSemanticDiagnostics", sourceFile, cancellationToken);
	}
	inline auto _impl_js_jts_dBuilderProgram::getSourceFile(js_string fileName) noexcept {
		return _call<js_union<_js_jts_dSourceFile, js_undefined>>("getSourceFile", fileName);
	}
	inline auto _impl_js_jts_dBuilderProgram::getSourceFiles() noexcept {
		return _call<js::ReadonlyArray<_js_jts_dSourceFile>>("getSourceFiles");
	}
	inline auto _impl_js_jts_dBuilderProgram::getSyntacticDiagnostics(js_union<_js_jts_dSourceFile, js_undefined> sourceFile, js_union<_js_jts_dCancellationToken, js_undefined> cancellationToken) noexcept {
		return _call<js::ReadonlyArray<_js_jts_dDiagnostic>>("getSyntacticDiagnostics", sourceFile, cancellationToken);
	}
	inline auto _impl_js_jts_dSemanticDiagnosticsBuilderProgram::getSemanticDiagnosticsOfNextAffectedFile(js_union<_js_jts_dCancellationToken, js_undefined> cancellationToken, js_union<js_function<bool /*false*/(_js_jts_dSourceFile)>, js_undefined> ignoreSourceFile) noexcept {
		return _call<js_unknown /*flags=1048576: AffectedFileResult<readonly Diagnostic[]> ()*/>("getSemanticDiagnosticsOfNextAffectedFile", cancellationToken, ignoreSourceFile);
	}
	inline auto _impl_js_jts_dEmitAndSemanticDiagnosticsBuilderProgram::emitNextAffectedFile(js_union<js_function<void(js_string, js_string, bool /*false*/, js_union<js_function<void(js_string)>, js_undefined>, js_union<js::ReadonlyArray<_js_jts_dSourceFile>, js_undefined>)>, js_undefined> writeFile, js_union<_js_jts_dCancellationToken, js_undefined> cancellationToken, js_union<bool /*false*/, js_undefined> emitOnlyDtsFiles, js_union<_js_jts_dCustomTransformers, js_undefined> customTransformers) noexcept {
		return _call<js_unknown /*flags=1048576: AffectedFileResult<EmitResult> ()*/>("emitNextAffectedFile", writeFile, cancellationToken, emitOnlyDtsFiles, customTransformers);
	}
	inline auto _impl_js_jts_dWatchHost::watchDirectory(js_string path, js_function<void(js_string)> callback, js_union<bool /*false*/, js_undefined> recursive) noexcept {
		return _call<_js_jts_dFileWatcher>("watchDirectory", path, callback, recursive);
	}
	inline auto _impl_js_jts_dWatchHost::watchFile(js_string path, js_function<void(js_string, _js_jts_dFileWatcherEventKind /*FileWatcherEventKind.Created*/)> callback, js_union<double, js_undefined> pollingInterval) noexcept {
		return _call<_js_jts_dFileWatcher>("watchFile", path, callback, pollingInterval);
	}
	inline auto _impl_js_jts_dProgramHost::createProgram() noexcept { return _getProperty<js_unknown /*flags=524288: CreateProgram<T> ()*/>("createProgram"); }
	inline void _impl_js_jts_dProgramHost::createProgram(js_unknown /*flags=524288: CreateProgram<T> ()*/ v) noexcept { _setProperty("createProgram", v); }
	inline auto _impl_js_jts_dProgramHost::fileExists(js_string path) noexcept {
		return _call<bool /*false*/>("fileExists", path);
	}
	inline auto _impl_js_jts_dProgramHost::getCurrentDirectory() noexcept {
		return _call<js_string>("getCurrentDirectory");
	}
	inline auto _impl_js_jts_dProgramHost::getDefaultLibFileName(_js_jts_dCompilerOptions options) noexcept {
		return _call<js_string>("getDefaultLibFileName", options);
	}
	inline auto _impl_js_jts_dProgramHost::getNewLine() noexcept {
		return _call<js_string>("getNewLine");
	}
	inline auto _impl_js_jts_dProgramHost::readFile(js_string path, js_union<js_string, js_undefined> encoding) noexcept {
		return _call<js_union<js_string, js_undefined>>("readFile", path, encoding);
	}
	inline auto _impl_js_jts_dProgramHost::useCaseSensitiveFileNames() noexcept {
		return _call<bool /*false*/>("useCaseSensitiveFileNames");
	}
	inline auto _impl_js_jts_dWatchCompilerHostOfFilesAndCompilerOptions::rootFiles() noexcept { return _getProperty<js::Array<js_string>>("rootFiles"); }
	inline void _impl_js_jts_dWatchCompilerHostOfFilesAndCompilerOptions::rootFiles(js::Array<js_string> v) noexcept { _setProperty("rootFiles", v); }
	inline auto _impl_js_jts_dWatchCompilerHostOfFilesAndCompilerOptions::options() noexcept { return _getProperty<_js_jts_dCompilerOptions>("options"); }
	inline void _impl_js_jts_dWatchCompilerHostOfFilesAndCompilerOptions::options(_js_jts_dCompilerOptions v) noexcept { _setProperty("options", v); }
	inline auto _impl_js_jts_dWatchCompilerHostOfConfigFile::configFileName() noexcept { return _getProperty<js_string>("configFileName"); }
	inline void _impl_js_jts_dWatchCompilerHostOfConfigFile::configFileName(js_string v) noexcept { _setProperty("configFileName", v); }
	inline auto _impl_js_jts_dWatchCompilerHostOfConfigFile::readDirectory(js_string path, js_union<js::ReadonlyArray<js_string>, js_undefined> extensions, js_union<js::ReadonlyArray<js_string>, js_undefined> exclude, js_union<js::ReadonlyArray<js_string>, js_undefined> include, js_union<double, js_undefined> depth) noexcept {
		return _call<js::Array<js_string>>("readDirectory", path, extensions, exclude, include, depth);
	}
	inline auto _impl_js_jts_dWatch::getProgram() noexcept {
		return _call<js_unknown /*flags=262144: T ()*/>("getProgram");
	}
	inline auto _impl_js_jts_dWatchOfFilesAndCompilerOptions::updateRootFileNames(js::Array<js_string> fileNames) noexcept {
		return _call<void>("updateRootFileNames", fileNames);
	}
	inline auto _impl_js_jts_dserver_dTypingInstallerResponse::kind() noexcept { return _getProperty<js_string /*"action::set"*/>("kind"); }
	inline auto _impl_js_jts_dserver_dTypingInstallerRequestWithProjectName::projectName() noexcept { return _getProperty<js_string>("projectName"); }
	inline auto _impl_js_jts_dserver_dDiscoverTypings::fileNames() noexcept { return _getProperty<js::Array<js_string>>("fileNames"); }
	inline auto _impl_js_jts_dserver_dDiscoverTypings::projectRootPath() noexcept { return _getProperty<js_unknown /*flags=2097152: Path ()*/>("projectRootPath"); }
	inline auto _impl_js_jts_dserver_dDiscoverTypings::compilerOptions() noexcept { return _getProperty<_js_jts_dCompilerOptions>("compilerOptions"); }
	inline auto _impl_js_jts_dserver_dDiscoverTypings::typeAcquisition() noexcept { return _getProperty<_js_jts_dTypeAcquisition>("typeAcquisition"); }
	inline auto _impl_js_jts_dserver_dDiscoverTypings::unresolvedImports() noexcept { return _getProperty<js_unknown /*flags=524288: SortedReadonlyArray<string> (TypeReference=ts.SortedReadonlyArray)*/>("unresolvedImports"); }
	inline auto _impl_js_jts_dserver_dDiscoverTypings::kind() noexcept { return _getProperty<js_string /*"discover"*/>("kind"); }
	inline auto _impl_js_jts_dserver_dCloseProject::kind() noexcept { return _getProperty<js_string /*"closeProject"*/>("kind"); }
	inline auto _impl_js_jts_dserver_dTypesRegistryRequest::kind() noexcept { return _getProperty<js_string /*"typesRegistry"*/>("kind"); }
	inline auto _impl_js_jts_dserver_dInstallPackageRequest::kind() noexcept { return _getProperty<js_string /*"installPackage"*/>("kind"); }
	inline auto _impl_js_jts_dserver_dInstallPackageRequest::fileName() noexcept { return _getProperty<js_unknown /*flags=2097152: Path ()*/>("fileName"); }
	inline auto _impl_js_jts_dserver_dInstallPackageRequest::packageName() noexcept { return _getProperty<js_string>("packageName"); }
	inline auto _impl_js_jts_dserver_dInstallPackageRequest::projectRootPath() noexcept { return _getProperty<js_unknown /*flags=2097152: Path ()*/>("projectRootPath"); }
	inline auto _impl_js_jts_dserver_dProjectResponse::projectName() noexcept { return _getProperty<js_string>("projectName"); }
	inline auto _impl_js_jts_dserver_dPackageInstalledResponse::kind() noexcept { return _getProperty<js_string /*"action::packageInstalled"*/>("kind"); }
	inline auto _impl_js_jts_dserver_dPackageInstalledResponse::success() noexcept { return _getProperty<bool /*false*/>("success"); }
	inline auto _impl_js_jts_dserver_dPackageInstalledResponse::message() noexcept { return _getProperty<js_string>("message"); }
	inline auto _impl_js_jts_dserver_dInitializationFailedResponse::kind() noexcept { return _getProperty<js_string /*"event::initializationFailed"*/>("kind"); }
	inline auto _impl_js_jts_dserver_dInitializationFailedResponse::message() noexcept { return _getProperty<js_string>("message"); }
	inline auto _impl_js_jts_dserver_dInvalidateCachedTypings::kind() noexcept { return _getProperty<js_string /*"action::invalidate"*/>("kind"); }
	inline auto _impl_js_jts_dserver_dInstallTypes::kind() noexcept { return _getProperty<js_string /*"event::beginInstallTypes"*/>("kind"); }
	inline auto _impl_js_jts_dserver_dInstallTypes::eventId() noexcept { return _getProperty<double>("eventId"); }
	inline auto _impl_js_jts_dserver_dInstallTypes::typingsInstallerVersion() noexcept { return _getProperty<js_string>("typingsInstallerVersion"); }
	inline auto _impl_js_jts_dserver_dInstallTypes::packagesToInstall() noexcept { return _getProperty<js::ReadonlyArray<js_string>>("packagesToInstall"); }
	inline auto _impl_js_jts_dserver_dBeginInstallTypes::kind() noexcept { return _getProperty<js_string /*"event::beginInstallTypes"*/>("kind"); }
	inline auto _impl_js_jts_dserver_dEndInstallTypes::kind() noexcept { return _getProperty<js_string /*"event::endInstallTypes"*/>("kind"); }
	inline auto _impl_js_jts_dserver_dEndInstallTypes::installSuccess() noexcept { return _getProperty<bool /*false*/>("installSuccess"); }
	inline auto _impl_js_jts_dserver_dSetTypings::typeAcquisition() noexcept { return _getProperty<_js_jts_dTypeAcquisition>("typeAcquisition"); }
	inline auto _impl_js_jts_dserver_dSetTypings::compilerOptions() noexcept { return _getProperty<_js_jts_dCompilerOptions>("compilerOptions"); }
	inline auto _impl_js_jts_dserver_dSetTypings::typings() noexcept { return _getProperty<js::Array<js_string>>("typings"); }
	inline auto _impl_js_jts_dserver_dSetTypings::unresolvedImports() noexcept { return _getProperty<js_unknown /*flags=524288: SortedReadonlyArray<string> (TypeReference=ts.SortedReadonlyArray)*/>("unresolvedImports"); }
	inline auto _impl_js_jts_dserver_dSetTypings::kind() noexcept { return _getProperty<js_string /*"action::set"*/>("kind"); }
	inline auto _impl_js_jts_dSourceFileLike::getLineAndCharacterOfPosition(double pos) noexcept {
		return _call<_js_jts_dLineAndCharacter>("getLineAndCharacterOfPosition", pos);
	}
	inline auto _impl_js_jts_dIScriptSnapshot::getChangeRange(_js_jts_dIScriptSnapshot oldSnapshot) noexcept {
		return _call<js_union<_js_jts_dTextChangeRange, js_undefined>>("getChangeRange", oldSnapshot);
	}
	inline auto _impl_js_jts_dIScriptSnapshot::getLength() noexcept {
		return _call<double>("getLength");
	}
	inline auto _impl_js_jts_dIScriptSnapshot::getText(double start, double end) noexcept {
		return _call<js_string>("getText", start, end);
	}
	inline auto _impl_js_jts_dScriptSnapshot::_tcjs_definitions::fromString(js_string text) noexcept {
		return emscripten::val::global("ts")["ScriptSnapshot"]["fromString"](text).template as<_js_jts_dIScriptSnapshot>();
	}
	inline auto _impl_js_jts_dPreProcessedFileInfo::referencedFiles() noexcept { return _getProperty<js::Array<_js_jts_dFileReference>>("referencedFiles"); }
	inline void _impl_js_jts_dPreProcessedFileInfo::referencedFiles(js::Array<_js_jts_dFileReference> v) noexcept { _setProperty("referencedFiles", v); }
	inline auto _impl_js_jts_dPreProcessedFileInfo::typeReferenceDirectives() noexcept { return _getProperty<js::Array<_js_jts_dFileReference>>("typeReferenceDirectives"); }
	inline void _impl_js_jts_dPreProcessedFileInfo::typeReferenceDirectives(js::Array<_js_jts_dFileReference> v) noexcept { _setProperty("typeReferenceDirectives", v); }
	inline auto _impl_js_jts_dPreProcessedFileInfo::libReferenceDirectives() noexcept { return _getProperty<js::Array<_js_jts_dFileReference>>("libReferenceDirectives"); }
	inline void _impl_js_jts_dPreProcessedFileInfo::libReferenceDirectives(js::Array<_js_jts_dFileReference> v) noexcept { _setProperty("libReferenceDirectives", v); }
	inline auto _impl_js_jts_dPreProcessedFileInfo::importedFiles() noexcept { return _getProperty<js::Array<_js_jts_dFileReference>>("importedFiles"); }
	inline void _impl_js_jts_dPreProcessedFileInfo::importedFiles(js::Array<_js_jts_dFileReference> v) noexcept { _setProperty("importedFiles", v); }
	inline auto _impl_js_jts_dPreProcessedFileInfo::isLibFile() noexcept { return _getProperty<bool /*false*/>("isLibFile"); }
	inline void _impl_js_jts_dPreProcessedFileInfo::isLibFile(bool /*false*/ v) noexcept { _setProperty("isLibFile", v); }
	inline auto _impl_js_jts_dHostCancellationToken::isCancellationRequested() noexcept {
		return _call<bool /*false*/>("isCancellationRequested");
	}
	inline auto _impl_js_jts_dInstallPackageOptions::fileName() noexcept { return _getProperty<js_unknown /*flags=2097152: Path ()*/>("fileName"); }
	inline void _impl_js_jts_dInstallPackageOptions::fileName(js_unknown /*flags=2097152: Path ()*/ v) noexcept { _setProperty("fileName", v); }
	inline auto _impl_js_jts_dInstallPackageOptions::packageName() noexcept { return _getProperty<js_string>("packageName"); }
	inline void _impl_js_jts_dInstallPackageOptions::packageName(js_string v) noexcept { _setProperty("packageName", v); }
	inline auto _impl_js_jts_dLanguageServiceHost::getCompilationSettings() noexcept {
		return _call<_js_jts_dCompilerOptions>("getCompilationSettings");
	}
	inline auto _impl_js_jts_dLanguageServiceHost::getCurrentDirectory() noexcept {
		return _call<js_string>("getCurrentDirectory");
	}
	inline auto _impl_js_jts_dLanguageServiceHost::getDefaultLibFileName(_js_jts_dCompilerOptions options) noexcept {
		return _call<js_string>("getDefaultLibFileName", options);
	}
	inline auto _impl_js_jts_dLanguageServiceHost::getScriptFileNames() noexcept {
		return _call<js::Array<js_string>>("getScriptFileNames");
	}
	inline auto _impl_js_jts_dLanguageServiceHost::getScriptSnapshot(js_string fileName) noexcept {
		return _call<js_union<_js_jts_dIScriptSnapshot, js_undefined>>("getScriptSnapshot", fileName);
	}
	inline auto _impl_js_jts_dLanguageServiceHost::getScriptVersion(js_string fileName) noexcept {
		return _call<js_string>("getScriptVersion", fileName);
	}
	inline auto _impl_js_jts_dLanguageService::applyCodeActionCommand(_js_jts_dInstallPackageAction action, js_union<_js_jts_dFormatCodeSettings, js_undefined> formatSettings) noexcept {
		return _call<js::Promise<_js_jts_dApplyCodeActionCommandResult>>("applyCodeActionCommand", action, formatSettings);
	}
	inline auto _impl_js_jts_dLanguageService::applyCodeActionCommand(js::Array<_js_jts_dInstallPackageAction> action, js_union<_js_jts_dFormatCodeSettings, js_undefined> formatSettings) noexcept {
		return _call<js::Promise<js::Array<_js_jts_dApplyCodeActionCommandResult>>>("applyCodeActionCommand", action, formatSettings);
	}
	inline auto _impl_js_jts_dLanguageService::applyCodeActionCommand(js_string fileName, _js_jts_dInstallPackageAction action) noexcept {
		return _call<js::Promise<_js_jts_dApplyCodeActionCommandResult>>("applyCodeActionCommand", fileName, action);
	}
	inline auto _impl_js_jts_dLanguageService::applyCodeActionCommand(js_string fileName, js::Array<_js_jts_dInstallPackageAction> action) noexcept {
		return _call<js::Promise<js::Array<_js_jts_dApplyCodeActionCommandResult>>>("applyCodeActionCommand", fileName, action);
	}
	inline auto _impl_js_jts_dLanguageService::applyCodeActionCommand(js_string fileName, js_union<_js_jts_dInstallPackageAction, js::Array<_js_jts_dInstallPackageAction>> action) noexcept {
		return _call<js::Promise<js_union<_js_jts_dApplyCodeActionCommandResult, js::Array<_js_jts_dApplyCodeActionCommandResult>>>>("applyCodeActionCommand", fileName, action);
	}
	inline auto _impl_js_jts_dLanguageService::applyCodeActionCommand(js_union<_js_jts_dInstallPackageAction, js::Array<_js_jts_dInstallPackageAction>> action, js_union<_js_jts_dFormatCodeSettings, js_undefined> formatSettings) noexcept {
		return _call<js::Promise<js_union<_js_jts_dApplyCodeActionCommandResult, js::Array<_js_jts_dApplyCodeActionCommandResult>>>>("applyCodeActionCommand", action, formatSettings);
	}
	inline auto _impl_js_jts_dLanguageService::cleanupSemanticCache() noexcept {
		return _call<void>("cleanupSemanticCache");
	}
	inline auto _impl_js_jts_dLanguageService::dispose() noexcept {
		return _call<void>("dispose");
	}
	inline auto _impl_js_jts_dLanguageService::findReferences(js_string fileName, double position) noexcept {
		return _call<js_union<js::Array<_js_jts_dReferencedSymbol>, js_undefined>>("findReferences", fileName, position);
	}
	inline auto _impl_js_jts_dLanguageService::findRenameLocations(js_string fileName, double position, bool /*false*/ findInStrings, bool /*false*/ findInComments, js_union<bool /*false*/, js_undefined> providePrefixAndSuffixTextForRename) noexcept {
		return _call<js_union<js::ReadonlyArray<_js_jts_dRenameLocation>, js_undefined>>("findRenameLocations", fileName, position, findInStrings, findInComments, providePrefixAndSuffixTextForRename);
	}
	inline auto _impl_js_jts_dLanguageService::getApplicableRefactors(js_string fileName, js_union<_js_jts_dTextRange, double> positionOrRange, js_union<_js_jts_dUserPreferences, js_undefined> preferences) noexcept {
		return _call<js::Array<_js_jts_dApplicableRefactorInfo>>("getApplicableRefactors", fileName, positionOrRange, preferences);
	}
	inline auto _impl_js_jts_dLanguageService::getBraceMatchingAtPosition(js_string fileName, double position) noexcept {
		return _call<js::Array<_js_jts_dTextSpan>>("getBraceMatchingAtPosition", fileName, position);
	}
	inline auto _impl_js_jts_dLanguageService::getBreakpointStatementAtPosition(js_string fileName, double position) noexcept {
		return _call<js_union<_js_jts_dTextSpan, js_undefined>>("getBreakpointStatementAtPosition", fileName, position);
	}
	inline auto _impl_js_jts_dLanguageService::getCodeFixesAtPosition(js_string fileName, double start, double end, js::ReadonlyArray<double> errorCodes, _js_jts_dFormatCodeSettings formatOptions, _js_jts_dUserPreferences preferences) noexcept {
		return _call<js::ReadonlyArray<_js_jts_dCodeFixAction>>("getCodeFixesAtPosition", fileName, start, end, errorCodes, formatOptions, preferences);
	}
	inline auto _impl_js_jts_dLanguageService::getCombinedCodeFix(_js_jts_dCombinedCodeFixScope scope, js_unknown /*flags=524288: {} ()*/ fixId, _js_jts_dFormatCodeSettings formatOptions, _js_jts_dUserPreferences preferences) noexcept {
		return _call<_js_jts_dCombinedCodeActions>("getCombinedCodeFix", scope, fixId, formatOptions, preferences);
	}
	inline auto _impl_js_jts_dLanguageService::getCompilerOptionsDiagnostics() noexcept {
		return _call<js::Array<_js_jts_dDiagnostic>>("getCompilerOptionsDiagnostics");
	}
	inline auto _impl_js_jts_dLanguageService::getCompletionEntryDetails(js_string fileName, double position, js_string name, js_union<_js_jts_dFormatCodeOptions, _js_jts_dFormatCodeSettings, js_undefined> formatOptions, js_union<js_string, js_undefined> source, js_union<_js_jts_dUserPreferences, js_undefined> preferences) noexcept {
		return _call<js_union<_js_jts_dCompletionEntryDetails, js_undefined>>("getCompletionEntryDetails", fileName, position, name, formatOptions, source, preferences);
	}
	inline auto _impl_js_jts_dLanguageService::getCompletionEntrySymbol(js_string fileName, double position, js_string name, js_union<js_string, js_undefined> source) noexcept {
		return _call<js_union<_js_jts_dSymbol, js_undefined>>("getCompletionEntrySymbol", fileName, position, name, source);
	}
	inline auto _impl_js_jts_dLanguageService::getCompletionsAtPosition(js_string fileName, double position, js_union<_js_jts_dGetCompletionsAtPositionOptions, js_undefined> options) noexcept {
		return _call<js_unknown /*flags=1048576: WithMetadata<CompletionInfo> | undefined ()*/>("getCompletionsAtPosition", fileName, position, options);
	}
	inline auto _impl_js_jts_dLanguageService::getDefinitionAndBoundSpan(js_string fileName, double position) noexcept {
		return _call<js_union<_js_jts_dDefinitionInfoAndBoundSpan, js_undefined>>("getDefinitionAndBoundSpan", fileName, position);
	}
	inline auto _impl_js_jts_dLanguageService::getDefinitionAtPosition(js_string fileName, double position) noexcept {
		return _call<js_union<js::ReadonlyArray<_js_jts_dDefinitionInfo>, js_undefined>>("getDefinitionAtPosition", fileName, position);
	}
	inline auto _impl_js_jts_dLanguageService::getDocCommentTemplateAtPosition(js_string fileName, double position) noexcept {
		return _call<js_union<_js_jts_dTextInsertion, js_undefined>>("getDocCommentTemplateAtPosition", fileName, position);
	}
	inline auto _impl_js_jts_dLanguageService::getDocumentHighlights(js_string fileName, double position, js::Array<js_string> filesToSearch) noexcept {
		return _call<js_union<js::Array<_js_jts_dDocumentHighlights>, js_undefined>>("getDocumentHighlights", fileName, position, filesToSearch);
	}
	inline auto _impl_js_jts_dLanguageService::getEditsForFileRename(js_string oldFilePath, js_string newFilePath, _js_jts_dFormatCodeSettings formatOptions, js_union<_js_jts_dUserPreferences, js_undefined> preferences) noexcept {
		return _call<js::ReadonlyArray<_js_jts_dFileTextChanges>>("getEditsForFileRename", oldFilePath, newFilePath, formatOptions, preferences);
	}
	inline auto _impl_js_jts_dLanguageService::getEditsForRefactor(js_string fileName, _js_jts_dFormatCodeSettings formatOptions, js_union<_js_jts_dTextRange, double> positionOrRange, js_string refactorName, js_string actionName, js_union<_js_jts_dUserPreferences, js_undefined> preferences) noexcept {
		return _call<js_union<_js_jts_dRefactorEditInfo, js_undefined>>("getEditsForRefactor", fileName, formatOptions, positionOrRange, refactorName, actionName, preferences);
	}
	inline auto _impl_js_jts_dLanguageService::getEmitOutput(js_string fileName, js_union<bool /*false*/, js_undefined> emitOnlyDtsFiles) noexcept {
		return _call<_js_jts_dEmitOutput>("getEmitOutput", fileName, emitOnlyDtsFiles);
	}
	inline auto _impl_js_jts_dLanguageService::getEncodedSemanticClassifications(js_string fileName, _js_jts_dTextSpan span) noexcept {
		return _call<_js_jts_dClassifications>("getEncodedSemanticClassifications", fileName, span);
	}
	inline auto _impl_js_jts_dLanguageService::getEncodedSyntacticClassifications(js_string fileName, _js_jts_dTextSpan span) noexcept {
		return _call<_js_jts_dClassifications>("getEncodedSyntacticClassifications", fileName, span);
	}
	inline auto _impl_js_jts_dLanguageService::getFormattingEditsAfterKeystroke(js_string fileName, double position, js_string key, js_union<_js_jts_dFormatCodeOptions, _js_jts_dFormatCodeSettings> options) noexcept {
		return _call<js::Array<_js_jts_dTextChange>>("getFormattingEditsAfterKeystroke", fileName, position, key, options);
	}
	inline auto _impl_js_jts_dLanguageService::getFormattingEditsForDocument(js_string fileName, js_union<_js_jts_dFormatCodeOptions, _js_jts_dFormatCodeSettings> options) noexcept {
		return _call<js::Array<_js_jts_dTextChange>>("getFormattingEditsForDocument", fileName, options);
	}
	inline auto _impl_js_jts_dLanguageService::getFormattingEditsForRange(js_string fileName, double start, double end, js_union<_js_jts_dFormatCodeOptions, _js_jts_dFormatCodeSettings> options) noexcept {
		return _call<js::Array<_js_jts_dTextChange>>("getFormattingEditsForRange", fileName, start, end, options);
	}
	inline auto _impl_js_jts_dLanguageService::getImplementationAtPosition(js_string fileName, double position) noexcept {
		return _call<js_union<js::ReadonlyArray<_js_jts_dImplementationLocation>, js_undefined>>("getImplementationAtPosition", fileName, position);
	}
	inline auto _impl_js_jts_dLanguageService::getIndentationAtPosition(js_string fileName, double position, js_union<_js_jts_dEditorOptions, _js_jts_dEditorSettings> options) noexcept {
		return _call<double>("getIndentationAtPosition", fileName, position, options);
	}
	inline auto _impl_js_jts_dLanguageService::getJsxClosingTagAtPosition(js_string fileName, double position) noexcept {
		return _call<js_union<_js_jts_dJsxClosingTagInfo, js_undefined>>("getJsxClosingTagAtPosition", fileName, position);
	}
	inline auto _impl_js_jts_dLanguageService::getNameOrDottedNameSpan(js_string fileName, double startPos, double endPos) noexcept {
		return _call<js_union<_js_jts_dTextSpan, js_undefined>>("getNameOrDottedNameSpan", fileName, startPos, endPos);
	}
	inline auto _impl_js_jts_dLanguageService::getNavigateToItems(js_string searchValue, js_union<double, js_undefined> maxResultCount, js_union<js_string, js_undefined> fileName, js_union<bool /*false*/, js_undefined> excludeDtsFiles) noexcept {
		return _call<js::Array<_js_jts_dNavigateToItem>>("getNavigateToItems", searchValue, maxResultCount, fileName, excludeDtsFiles);
	}
	inline auto _impl_js_jts_dLanguageService::getNavigationBarItems(js_string fileName) noexcept {
		return _call<js::Array<_js_jts_dNavigationBarItem>>("getNavigationBarItems", fileName);
	}
	inline auto _impl_js_jts_dLanguageService::getNavigationTree(js_string fileName) noexcept {
		return _call<_js_jts_dNavigationTree>("getNavigationTree", fileName);
	}
	inline auto _impl_js_jts_dLanguageService::getOccurrencesAtPosition(js_string fileName, double position) noexcept {
		return _call<js_union<js::ReadonlyArray<_js_jts_dReferenceEntry>, js_undefined>>("getOccurrencesAtPosition", fileName, position);
	}
	inline auto _impl_js_jts_dLanguageService::getOutliningSpans(js_string fileName) noexcept {
		return _call<js::Array<_js_jts_dOutliningSpan>>("getOutliningSpans", fileName);
	}
	inline auto _impl_js_jts_dLanguageService::getProgram() noexcept {
		return _call<js_union<_js_jts_dProgram, js_undefined>>("getProgram");
	}
	inline auto _impl_js_jts_dLanguageService::getQuickInfoAtPosition(js_string fileName, double position) noexcept {
		return _call<js_union<_js_jts_dQuickInfo, js_undefined>>("getQuickInfoAtPosition", fileName, position);
	}
	inline auto _impl_js_jts_dLanguageService::getReferencesAtPosition(js_string fileName, double position) noexcept {
		return _call<js_union<js::Array<_js_jts_dReferenceEntry>, js_undefined>>("getReferencesAtPosition", fileName, position);
	}
	inline auto _impl_js_jts_dLanguageService::getRenameInfo(js_string fileName, double position, js_union<_js_jts_dRenameInfoOptions, js_undefined> options) noexcept {
		return _call<js_union<_js_jts_dRenameInfoFailure, _js_jts_dRenameInfoSuccess>>("getRenameInfo", fileName, position, options);
	}
	inline auto _impl_js_jts_dLanguageService::getSemanticClassifications(js_string fileName, _js_jts_dTextSpan span) noexcept {
		return _call<js::Array<_js_jts_dClassifiedSpan>>("getSemanticClassifications", fileName, span);
	}
	inline auto _impl_js_jts_dLanguageService::getSemanticDiagnostics(js_string fileName) noexcept {
		return _call<js::Array<_js_jts_dDiagnostic>>("getSemanticDiagnostics", fileName);
	}
	inline auto _impl_js_jts_dLanguageService::getSignatureHelpItems(js_string fileName, double position, js_union<_js_jts_dSignatureHelpItemsOptions, js_undefined> options) noexcept {
		return _call<js_union<_js_jts_dSignatureHelpItems, js_undefined>>("getSignatureHelpItems", fileName, position, options);
	}
	inline auto _impl_js_jts_dLanguageService::getSmartSelectionRange(js_string fileName, double position) noexcept {
		return _call<_js_jts_dSelectionRange>("getSmartSelectionRange", fileName, position);
	}
	inline auto _impl_js_jts_dLanguageService::getSpanOfEnclosingComment(js_string fileName, double position, bool /*false*/ onlyMultiLine) noexcept {
		return _call<js_union<_js_jts_dTextSpan, js_undefined>>("getSpanOfEnclosingComment", fileName, position, onlyMultiLine);
	}
	inline auto _impl_js_jts_dLanguageService::getSuggestionDiagnostics(js_string fileName) noexcept {
		return _call<js::Array<_js_jts_dDiagnosticWithLocation>>("getSuggestionDiagnostics", fileName);
	}
	inline auto _impl_js_jts_dLanguageService::getSyntacticClassifications(js_string fileName, _js_jts_dTextSpan span) noexcept {
		return _call<js::Array<_js_jts_dClassifiedSpan>>("getSyntacticClassifications", fileName, span);
	}
	inline auto _impl_js_jts_dLanguageService::getSyntacticDiagnostics(js_string fileName) noexcept {
		return _call<js::Array<_js_jts_dDiagnosticWithLocation>>("getSyntacticDiagnostics", fileName);
	}
	inline auto _impl_js_jts_dLanguageService::getTodoComments(js_string fileName, js::Array<_js_jts_dTodoCommentDescriptor> descriptors) noexcept {
		return _call<js::Array<_js_jts_dTodoComment>>("getTodoComments", fileName, descriptors);
	}
	inline auto _impl_js_jts_dLanguageService::getTypeDefinitionAtPosition(js_string fileName, double position) noexcept {
		return _call<js_union<js::ReadonlyArray<_js_jts_dDefinitionInfo>, js_undefined>>("getTypeDefinitionAtPosition", fileName, position);
	}
	inline auto _impl_js_jts_dLanguageService::isValidBraceCompletionAtPosition(js_string fileName, double position, double openingBrace) noexcept {
		return _call<bool /*false*/>("isValidBraceCompletionAtPosition", fileName, position, openingBrace);
	}
	inline auto _impl_js_jts_dLanguageService::organizeImports(_js_jts_dCombinedCodeFixScope scope, _js_jts_dFormatCodeSettings formatOptions, js_union<_js_jts_dUserPreferences, js_undefined> preferences) noexcept {
		return _call<js::ReadonlyArray<_js_jts_dFileTextChanges>>("organizeImports", scope, formatOptions, preferences);
	}
	inline auto _impl_js_jts_dJsxClosingTagInfo::newText() noexcept { return _getProperty<js_string>("newText"); }
	inline auto _impl_js_jts_dCombinedCodeFixScope::type() noexcept { return _getProperty<js_string /*"file"*/>("type"); }
	inline void _impl_js_jts_dCombinedCodeFixScope::type(js_string /*"file"*/ v) noexcept { _setProperty("type", v); }
	inline auto _impl_js_jts_dCombinedCodeFixScope::fileName() noexcept { return _getProperty<js_string>("fileName"); }
	inline void _impl_js_jts_dCombinedCodeFixScope::fileName(js_string v) noexcept { _setProperty("fileName", v); }
	inline auto _impl_js_jts_dSignatureHelpInvokedReason::kind() noexcept { return _getProperty<js_string /*"invoked"*/>("kind"); }
	inline void _impl_js_jts_dSignatureHelpInvokedReason::kind(js_string /*"invoked"*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dSignatureHelpCharacterTypedReason::kind() noexcept { return _getProperty<js_string /*"characterTyped"*/>("kind"); }
	inline void _impl_js_jts_dSignatureHelpCharacterTypedReason::kind(js_string /*"characterTyped"*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dSignatureHelpCharacterTypedReason::triggerCharacter() noexcept { return _getProperty<js_string /*"<"*/>("triggerCharacter"); }
	inline void _impl_js_jts_dSignatureHelpCharacterTypedReason::triggerCharacter(js_string /*"<"*/ v) noexcept { _setProperty("triggerCharacter", v); }
	inline auto _impl_js_jts_dSignatureHelpRetriggeredReason::kind() noexcept { return _getProperty<js_string /*"retrigger"*/>("kind"); }
	inline void _impl_js_jts_dSignatureHelpRetriggeredReason::kind(js_string /*"retrigger"*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dApplyCodeActionCommandResult::successMessage() noexcept { return _getProperty<js_string>("successMessage"); }
	inline void _impl_js_jts_dApplyCodeActionCommandResult::successMessage(js_string v) noexcept { _setProperty("successMessage", v); }
	inline auto _impl_js_jts_dClassifications::spans() noexcept { return _getProperty<js::Array<double>>("spans"); }
	inline void _impl_js_jts_dClassifications::spans(js::Array<double> v) noexcept { _setProperty("spans", v); }
	inline auto _impl_js_jts_dClassifications::endOfLineState() noexcept { return _getProperty<_js_jts_dEndOfLineState /*EndOfLineState.None*/>("endOfLineState"); }
	inline void _impl_js_jts_dClassifications::endOfLineState(_js_jts_dEndOfLineState /*EndOfLineState.None*/ v) noexcept { _setProperty("endOfLineState", v); }
	inline auto _impl_js_jts_dClassifiedSpan::textSpan() noexcept { return _getProperty<_js_jts_dTextSpan>("textSpan"); }
	inline void _impl_js_jts_dClassifiedSpan::textSpan(_js_jts_dTextSpan v) noexcept { _setProperty("textSpan", v); }
	inline auto _impl_js_jts_dClassifiedSpan::classificationType() noexcept { return _getProperty<_js_jts_dClassificationTypeNames /*ClassificationTypeNames.comment*/>("classificationType"); }
	inline void _impl_js_jts_dClassifiedSpan::classificationType(_js_jts_dClassificationTypeNames /*ClassificationTypeNames.comment*/ v) noexcept { _setProperty("classificationType", v); }
	inline auto _impl_js_jts_dNavigationBarItem::text() noexcept { return _getProperty<js_string>("text"); }
	inline void _impl_js_jts_dNavigationBarItem::text(js_string v) noexcept { _setProperty("text", v); }
	inline auto _impl_js_jts_dNavigationBarItem::kind() noexcept { return _getProperty<_js_jts_dScriptElementKind /*ScriptElementKind.unknown*/>("kind"); }
	inline void _impl_js_jts_dNavigationBarItem::kind(_js_jts_dScriptElementKind /*ScriptElementKind.unknown*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dNavigationBarItem::kindModifiers() noexcept { return _getProperty<js_string>("kindModifiers"); }
	inline void _impl_js_jts_dNavigationBarItem::kindModifiers(js_string v) noexcept { _setProperty("kindModifiers", v); }
	inline auto _impl_js_jts_dNavigationBarItem::spans() noexcept { return _getProperty<js::Array<_js_jts_dTextSpan>>("spans"); }
	inline void _impl_js_jts_dNavigationBarItem::spans(js::Array<_js_jts_dTextSpan> v) noexcept { _setProperty("spans", v); }
	inline auto _impl_js_jts_dNavigationBarItem::childItems() noexcept { return _getProperty<js::Array<_js_jts_dNavigationBarItem>>("childItems"); }
	inline void _impl_js_jts_dNavigationBarItem::childItems(js::Array<_js_jts_dNavigationBarItem> v) noexcept { _setProperty("childItems", v); }
	inline auto _impl_js_jts_dNavigationBarItem::indent() noexcept { return _getProperty<double>("indent"); }
	inline void _impl_js_jts_dNavigationBarItem::indent(double v) noexcept { _setProperty("indent", v); }
	inline auto _impl_js_jts_dNavigationBarItem::bolded() noexcept { return _getProperty<bool /*false*/>("bolded"); }
	inline void _impl_js_jts_dNavigationBarItem::bolded(bool /*false*/ v) noexcept { _setProperty("bolded", v); }
	inline auto _impl_js_jts_dNavigationBarItem::grayed() noexcept { return _getProperty<bool /*false*/>("grayed"); }
	inline void _impl_js_jts_dNavigationBarItem::grayed(bool /*false*/ v) noexcept { _setProperty("grayed", v); }
	inline auto _impl_js_jts_dNavigationTree::text() noexcept { return _getProperty<js_string>("text"); }
	inline void _impl_js_jts_dNavigationTree::text(js_string v) noexcept { _setProperty("text", v); }
	inline auto _impl_js_jts_dNavigationTree::kind() noexcept { return _getProperty<_js_jts_dScriptElementKind /*ScriptElementKind.unknown*/>("kind"); }
	inline void _impl_js_jts_dNavigationTree::kind(_js_jts_dScriptElementKind /*ScriptElementKind.unknown*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dNavigationTree::kindModifiers() noexcept { return _getProperty<js_string>("kindModifiers"); }
	inline void _impl_js_jts_dNavigationTree::kindModifiers(js_string v) noexcept { _setProperty("kindModifiers", v); }
	inline auto _impl_js_jts_dNavigationTree::spans() noexcept { return _getProperty<js::Array<_js_jts_dTextSpan>>("spans"); }
	inline void _impl_js_jts_dNavigationTree::spans(js::Array<_js_jts_dTextSpan> v) noexcept { _setProperty("spans", v); }
	inline auto _impl_js_jts_dNavigationTree::nameSpan() noexcept { return _getProperty<js_union<_js_jts_dTextSpan, js_undefined>>("nameSpan"); }
	inline void _impl_js_jts_dNavigationTree::nameSpan(js_union<_js_jts_dTextSpan, js_undefined> v) noexcept { _setProperty("nameSpan", v); }
	inline auto _impl_js_jts_dTodoCommentDescriptor::text() noexcept { return _getProperty<js_string>("text"); }
	inline void _impl_js_jts_dTodoCommentDescriptor::text(js_string v) noexcept { _setProperty("text", v); }
	inline auto _impl_js_jts_dTodoCommentDescriptor::priority() noexcept { return _getProperty<double>("priority"); }
	inline void _impl_js_jts_dTodoCommentDescriptor::priority(double v) noexcept { _setProperty("priority", v); }
	inline auto _impl_js_jts_dTodoComment::descriptor() noexcept { return _getProperty<_js_jts_dTodoCommentDescriptor>("descriptor"); }
	inline void _impl_js_jts_dTodoComment::descriptor(_js_jts_dTodoCommentDescriptor v) noexcept { _setProperty("descriptor", v); }
	inline auto _impl_js_jts_dTodoComment::message() noexcept { return _getProperty<js_string>("message"); }
	inline void _impl_js_jts_dTodoComment::message(js_string v) noexcept { _setProperty("message", v); }
	inline auto _impl_js_jts_dTodoComment::position() noexcept { return _getProperty<double>("position"); }
	inline void _impl_js_jts_dTodoComment::position(double v) noexcept { _setProperty("position", v); }
	inline auto _impl_js_jts_dTextChange::span() noexcept { return _getProperty<_js_jts_dTextSpan>("span"); }
	inline void _impl_js_jts_dTextChange::span(_js_jts_dTextSpan v) noexcept { _setProperty("span", v); }
	inline auto _impl_js_jts_dTextChange::newText() noexcept { return _getProperty<js_string>("newText"); }
	inline void _impl_js_jts_dTextChange::newText(js_string v) noexcept { _setProperty("newText", v); }
	inline auto _impl_js_jts_dFileTextChanges::fileName() noexcept { return _getProperty<js_string>("fileName"); }
	inline void _impl_js_jts_dFileTextChanges::fileName(js_string v) noexcept { _setProperty("fileName", v); }
	inline auto _impl_js_jts_dFileTextChanges::textChanges() noexcept { return _getProperty<js::Array<_js_jts_dTextChange>>("textChanges"); }
	inline void _impl_js_jts_dFileTextChanges::textChanges(js::Array<_js_jts_dTextChange> v) noexcept { _setProperty("textChanges", v); }
	inline auto _impl_js_jts_dCodeAction::description() noexcept { return _getProperty<js_string>("description"); }
	inline void _impl_js_jts_dCodeAction::description(js_string v) noexcept { _setProperty("description", v); }
	inline auto _impl_js_jts_dCodeAction::changes() noexcept { return _getProperty<js::Array<_js_jts_dFileTextChanges>>("changes"); }
	inline void _impl_js_jts_dCodeAction::changes(js::Array<_js_jts_dFileTextChanges> v) noexcept { _setProperty("changes", v); }
	inline auto _impl_js_jts_dCodeFixAction::fixName() noexcept { return _getProperty<js_string>("fixName"); }
	inline void _impl_js_jts_dCodeFixAction::fixName(js_string v) noexcept { _setProperty("fixName", v); }
	inline auto _impl_js_jts_dCombinedCodeActions::changes() noexcept { return _getProperty<js::ReadonlyArray<_js_jts_dFileTextChanges>>("changes"); }
	inline void _impl_js_jts_dCombinedCodeActions::changes(js::ReadonlyArray<_js_jts_dFileTextChanges> v) noexcept { _setProperty("changes", v); }
	inline auto _impl_js_jts_dApplicableRefactorInfo::name() noexcept { return _getProperty<js_string>("name"); }
	inline void _impl_js_jts_dApplicableRefactorInfo::name(js_string v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dApplicableRefactorInfo::description() noexcept { return _getProperty<js_string>("description"); }
	inline void _impl_js_jts_dApplicableRefactorInfo::description(js_string v) noexcept { _setProperty("description", v); }
	inline auto _impl_js_jts_dApplicableRefactorInfo::actions() noexcept { return _getProperty<js::Array<_js_jts_dRefactorActionInfo>>("actions"); }
	inline void _impl_js_jts_dApplicableRefactorInfo::actions(js::Array<_js_jts_dRefactorActionInfo> v) noexcept { _setProperty("actions", v); }
	inline auto _impl_js_jts_dRefactorActionInfo::name() noexcept { return _getProperty<js_string>("name"); }
	inline void _impl_js_jts_dRefactorActionInfo::name(js_string v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dRefactorActionInfo::description() noexcept { return _getProperty<js_string>("description"); }
	inline void _impl_js_jts_dRefactorActionInfo::description(js_string v) noexcept { _setProperty("description", v); }
	inline auto _impl_js_jts_dRefactorEditInfo::edits() noexcept { return _getProperty<js::Array<_js_jts_dFileTextChanges>>("edits"); }
	inline void _impl_js_jts_dRefactorEditInfo::edits(js::Array<_js_jts_dFileTextChanges> v) noexcept { _setProperty("edits", v); }
	inline auto _impl_js_jts_dTextInsertion::newText() noexcept { return _getProperty<js_string>("newText"); }
	inline void _impl_js_jts_dTextInsertion::newText(js_string v) noexcept { _setProperty("newText", v); }
	inline auto _impl_js_jts_dTextInsertion::caretOffset() noexcept { return _getProperty<double>("caretOffset"); }
	inline void _impl_js_jts_dTextInsertion::caretOffset(double v) noexcept { _setProperty("caretOffset", v); }
	inline auto _impl_js_jts_dDocumentSpan::textSpan() noexcept { return _getProperty<_js_jts_dTextSpan>("textSpan"); }
	inline void _impl_js_jts_dDocumentSpan::textSpan(_js_jts_dTextSpan v) noexcept { _setProperty("textSpan", v); }
	inline auto _impl_js_jts_dDocumentSpan::fileName() noexcept { return _getProperty<js_string>("fileName"); }
	inline void _impl_js_jts_dDocumentSpan::fileName(js_string v) noexcept { _setProperty("fileName", v); }
	inline auto _impl_js_jts_dReferenceEntry::isWriteAccess() noexcept { return _getProperty<bool /*false*/>("isWriteAccess"); }
	inline void _impl_js_jts_dReferenceEntry::isWriteAccess(bool /*false*/ v) noexcept { _setProperty("isWriteAccess", v); }
	inline auto _impl_js_jts_dReferenceEntry::isDefinition() noexcept { return _getProperty<bool /*false*/>("isDefinition"); }
	inline void _impl_js_jts_dReferenceEntry::isDefinition(bool /*false*/ v) noexcept { _setProperty("isDefinition", v); }
	inline auto _impl_js_jts_dImplementationLocation::kind() noexcept { return _getProperty<_js_jts_dScriptElementKind /*ScriptElementKind.unknown*/>("kind"); }
	inline void _impl_js_jts_dImplementationLocation::kind(_js_jts_dScriptElementKind /*ScriptElementKind.unknown*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dImplementationLocation::displayParts() noexcept { return _getProperty<js::Array<_js_jts_dSymbolDisplayPart>>("displayParts"); }
	inline void _impl_js_jts_dImplementationLocation::displayParts(js::Array<_js_jts_dSymbolDisplayPart> v) noexcept { _setProperty("displayParts", v); }
	inline auto _impl_js_jts_dDocumentHighlights::fileName() noexcept { return _getProperty<js_string>("fileName"); }
	inline void _impl_js_jts_dDocumentHighlights::fileName(js_string v) noexcept { _setProperty("fileName", v); }
	inline auto _impl_js_jts_dDocumentHighlights::highlightSpans() noexcept { return _getProperty<js::Array<_js_jts_dHighlightSpan>>("highlightSpans"); }
	inline void _impl_js_jts_dDocumentHighlights::highlightSpans(js::Array<_js_jts_dHighlightSpan> v) noexcept { _setProperty("highlightSpans", v); }
	inline auto _impl_js_jts_dHighlightSpan::textSpan() noexcept { return _getProperty<_js_jts_dTextSpan>("textSpan"); }
	inline void _impl_js_jts_dHighlightSpan::textSpan(_js_jts_dTextSpan v) noexcept { _setProperty("textSpan", v); }
	inline auto _impl_js_jts_dHighlightSpan::kind() noexcept { return _getProperty<_js_jts_dHighlightSpanKind /*HighlightSpanKind.none*/>("kind"); }
	inline void _impl_js_jts_dHighlightSpan::kind(_js_jts_dHighlightSpanKind /*HighlightSpanKind.none*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dNavigateToItem::name() noexcept { return _getProperty<js_string>("name"); }
	inline void _impl_js_jts_dNavigateToItem::name(js_string v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dNavigateToItem::kind() noexcept { return _getProperty<_js_jts_dScriptElementKind /*ScriptElementKind.unknown*/>("kind"); }
	inline void _impl_js_jts_dNavigateToItem::kind(_js_jts_dScriptElementKind /*ScriptElementKind.unknown*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dNavigateToItem::kindModifiers() noexcept { return _getProperty<js_string>("kindModifiers"); }
	inline void _impl_js_jts_dNavigateToItem::kindModifiers(js_string v) noexcept { _setProperty("kindModifiers", v); }
	inline auto _impl_js_jts_dNavigateToItem::matchKind() noexcept { return _getProperty<js_string /*"exact"*/>("matchKind"); }
	inline void _impl_js_jts_dNavigateToItem::matchKind(js_string /*"exact"*/ v) noexcept { _setProperty("matchKind", v); }
	inline auto _impl_js_jts_dNavigateToItem::isCaseSensitive() noexcept { return _getProperty<bool /*false*/>("isCaseSensitive"); }
	inline void _impl_js_jts_dNavigateToItem::isCaseSensitive(bool /*false*/ v) noexcept { _setProperty("isCaseSensitive", v); }
	inline auto _impl_js_jts_dNavigateToItem::fileName() noexcept { return _getProperty<js_string>("fileName"); }
	inline void _impl_js_jts_dNavigateToItem::fileName(js_string v) noexcept { _setProperty("fileName", v); }
	inline auto _impl_js_jts_dNavigateToItem::textSpan() noexcept { return _getProperty<_js_jts_dTextSpan>("textSpan"); }
	inline void _impl_js_jts_dNavigateToItem::textSpan(_js_jts_dTextSpan v) noexcept { _setProperty("textSpan", v); }
	inline auto _impl_js_jts_dNavigateToItem::containerName() noexcept { return _getProperty<js_string>("containerName"); }
	inline void _impl_js_jts_dNavigateToItem::containerName(js_string v) noexcept { _setProperty("containerName", v); }
	inline auto _impl_js_jts_dNavigateToItem::containerKind() noexcept { return _getProperty<_js_jts_dScriptElementKind /*ScriptElementKind.unknown*/>("containerKind"); }
	inline void _impl_js_jts_dNavigateToItem::containerKind(_js_jts_dScriptElementKind /*ScriptElementKind.unknown*/ v) noexcept { _setProperty("containerKind", v); }
	inline auto _impl_js_jts_dEditorOptions::IndentSize() noexcept { return _getProperty<double>("IndentSize"); }
	inline void _impl_js_jts_dEditorOptions::IndentSize(double v) noexcept { _setProperty("IndentSize", v); }
	inline auto _impl_js_jts_dEditorOptions::TabSize() noexcept { return _getProperty<double>("TabSize"); }
	inline void _impl_js_jts_dEditorOptions::TabSize(double v) noexcept { _setProperty("TabSize", v); }
	inline auto _impl_js_jts_dEditorOptions::NewLineCharacter() noexcept { return _getProperty<js_string>("NewLineCharacter"); }
	inline void _impl_js_jts_dEditorOptions::NewLineCharacter(js_string v) noexcept { _setProperty("NewLineCharacter", v); }
	inline auto _impl_js_jts_dEditorOptions::ConvertTabsToSpaces() noexcept { return _getProperty<bool /*false*/>("ConvertTabsToSpaces"); }
	inline void _impl_js_jts_dEditorOptions::ConvertTabsToSpaces(bool /*false*/ v) noexcept { _setProperty("ConvertTabsToSpaces", v); }
	inline auto _impl_js_jts_dEditorOptions::IndentStyle() noexcept { return _getProperty<_js_jts_dIndentStyle /*IndentStyle.None*/>("IndentStyle"); }
	inline void _impl_js_jts_dEditorOptions::IndentStyle(_js_jts_dIndentStyle /*IndentStyle.None*/ v) noexcept { _setProperty("IndentStyle", v); }
	inline auto _impl_js_jts_dFormatCodeOptions::InsertSpaceAfterCommaDelimiter() noexcept { return _getProperty<bool /*false*/>("InsertSpaceAfterCommaDelimiter"); }
	inline void _impl_js_jts_dFormatCodeOptions::InsertSpaceAfterCommaDelimiter(bool /*false*/ v) noexcept { _setProperty("InsertSpaceAfterCommaDelimiter", v); }
	inline auto _impl_js_jts_dFormatCodeOptions::InsertSpaceAfterSemicolonInForStatements() noexcept { return _getProperty<bool /*false*/>("InsertSpaceAfterSemicolonInForStatements"); }
	inline void _impl_js_jts_dFormatCodeOptions::InsertSpaceAfterSemicolonInForStatements(bool /*false*/ v) noexcept { _setProperty("InsertSpaceAfterSemicolonInForStatements", v); }
	inline auto _impl_js_jts_dFormatCodeOptions::InsertSpaceBeforeAndAfterBinaryOperators() noexcept { return _getProperty<bool /*false*/>("InsertSpaceBeforeAndAfterBinaryOperators"); }
	inline void _impl_js_jts_dFormatCodeOptions::InsertSpaceBeforeAndAfterBinaryOperators(bool /*false*/ v) noexcept { _setProperty("InsertSpaceBeforeAndAfterBinaryOperators", v); }
	inline auto _impl_js_jts_dFormatCodeOptions::InsertSpaceAfterKeywordsInControlFlowStatements() noexcept { return _getProperty<bool /*false*/>("InsertSpaceAfterKeywordsInControlFlowStatements"); }
	inline void _impl_js_jts_dFormatCodeOptions::InsertSpaceAfterKeywordsInControlFlowStatements(bool /*false*/ v) noexcept { _setProperty("InsertSpaceAfterKeywordsInControlFlowStatements", v); }
	inline auto _impl_js_jts_dFormatCodeOptions::InsertSpaceAfterFunctionKeywordForAnonymousFunctions() noexcept { return _getProperty<bool /*false*/>("InsertSpaceAfterFunctionKeywordForAnonymousFunctions"); }
	inline void _impl_js_jts_dFormatCodeOptions::InsertSpaceAfterFunctionKeywordForAnonymousFunctions(bool /*false*/ v) noexcept { _setProperty("InsertSpaceAfterFunctionKeywordForAnonymousFunctions", v); }
	inline auto _impl_js_jts_dFormatCodeOptions::InsertSpaceAfterOpeningAndBeforeClosingNonemptyParenthesis() noexcept { return _getProperty<bool /*false*/>("InsertSpaceAfterOpeningAndBeforeClosingNonemptyParenthesis"); }
	inline void _impl_js_jts_dFormatCodeOptions::InsertSpaceAfterOpeningAndBeforeClosingNonemptyParenthesis(bool /*false*/ v) noexcept { _setProperty("InsertSpaceAfterOpeningAndBeforeClosingNonemptyParenthesis", v); }
	inline auto _impl_js_jts_dFormatCodeOptions::InsertSpaceAfterOpeningAndBeforeClosingNonemptyBrackets() noexcept { return _getProperty<bool /*false*/>("InsertSpaceAfterOpeningAndBeforeClosingNonemptyBrackets"); }
	inline void _impl_js_jts_dFormatCodeOptions::InsertSpaceAfterOpeningAndBeforeClosingNonemptyBrackets(bool /*false*/ v) noexcept { _setProperty("InsertSpaceAfterOpeningAndBeforeClosingNonemptyBrackets", v); }
	inline auto _impl_js_jts_dFormatCodeOptions::InsertSpaceAfterOpeningAndBeforeClosingTemplateStringBraces() noexcept { return _getProperty<bool /*false*/>("InsertSpaceAfterOpeningAndBeforeClosingTemplateStringBraces"); }
	inline void _impl_js_jts_dFormatCodeOptions::InsertSpaceAfterOpeningAndBeforeClosingTemplateStringBraces(bool /*false*/ v) noexcept { _setProperty("InsertSpaceAfterOpeningAndBeforeClosingTemplateStringBraces", v); }
	inline auto _impl_js_jts_dFormatCodeOptions::PlaceOpenBraceOnNewLineForFunctions() noexcept { return _getProperty<bool /*false*/>("PlaceOpenBraceOnNewLineForFunctions"); }
	inline void _impl_js_jts_dFormatCodeOptions::PlaceOpenBraceOnNewLineForFunctions(bool /*false*/ v) noexcept { _setProperty("PlaceOpenBraceOnNewLineForFunctions", v); }
	inline auto _impl_js_jts_dFormatCodeOptions::PlaceOpenBraceOnNewLineForControlBlocks() noexcept { return _getProperty<bool /*false*/>("PlaceOpenBraceOnNewLineForControlBlocks"); }
	inline void _impl_js_jts_dFormatCodeOptions::PlaceOpenBraceOnNewLineForControlBlocks(bool /*false*/ v) noexcept { _setProperty("PlaceOpenBraceOnNewLineForControlBlocks", v); }
	inline auto _impl_js_jts_dDefinitionInfo::kind() noexcept { return _getProperty<_js_jts_dScriptElementKind /*ScriptElementKind.unknown*/>("kind"); }
	inline void _impl_js_jts_dDefinitionInfo::kind(_js_jts_dScriptElementKind /*ScriptElementKind.unknown*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dDefinitionInfo::name() noexcept { return _getProperty<js_string>("name"); }
	inline void _impl_js_jts_dDefinitionInfo::name(js_string v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dDefinitionInfo::containerKind() noexcept { return _getProperty<_js_jts_dScriptElementKind /*ScriptElementKind.unknown*/>("containerKind"); }
	inline void _impl_js_jts_dDefinitionInfo::containerKind(_js_jts_dScriptElementKind /*ScriptElementKind.unknown*/ v) noexcept { _setProperty("containerKind", v); }
	inline auto _impl_js_jts_dDefinitionInfo::containerName() noexcept { return _getProperty<js_string>("containerName"); }
	inline void _impl_js_jts_dDefinitionInfo::containerName(js_string v) noexcept { _setProperty("containerName", v); }
	inline auto _impl_js_jts_dDefinitionInfoAndBoundSpan::textSpan() noexcept { return _getProperty<_js_jts_dTextSpan>("textSpan"); }
	inline void _impl_js_jts_dDefinitionInfoAndBoundSpan::textSpan(_js_jts_dTextSpan v) noexcept { _setProperty("textSpan", v); }
	inline auto _impl_js_jts_dReferencedSymbolDefinitionInfo::displayParts() noexcept { return _getProperty<js::Array<_js_jts_dSymbolDisplayPart>>("displayParts"); }
	inline void _impl_js_jts_dReferencedSymbolDefinitionInfo::displayParts(js::Array<_js_jts_dSymbolDisplayPart> v) noexcept { _setProperty("displayParts", v); }
	inline auto _impl_js_jts_dReferencedSymbol::definition() noexcept { return _getProperty<_js_jts_dReferencedSymbolDefinitionInfo>("definition"); }
	inline void _impl_js_jts_dReferencedSymbol::definition(_js_jts_dReferencedSymbolDefinitionInfo v) noexcept { _setProperty("definition", v); }
	inline auto _impl_js_jts_dReferencedSymbol::references() noexcept { return _getProperty<js::Array<_js_jts_dReferenceEntry>>("references"); }
	inline void _impl_js_jts_dReferencedSymbol::references(js::Array<_js_jts_dReferenceEntry> v) noexcept { _setProperty("references", v); }
	inline auto _impl_js_jts_dSymbolDisplayPart::text() noexcept { return _getProperty<js_string>("text"); }
	inline void _impl_js_jts_dSymbolDisplayPart::text(js_string v) noexcept { _setProperty("text", v); }
	inline auto _impl_js_jts_dSymbolDisplayPart::kind() noexcept { return _getProperty<js_string>("kind"); }
	inline void _impl_js_jts_dSymbolDisplayPart::kind(js_string v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dJSDocTagInfo::name() noexcept { return _getProperty<js_string>("name"); }
	inline void _impl_js_jts_dJSDocTagInfo::name(js_string v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dQuickInfo::kind() noexcept { return _getProperty<_js_jts_dScriptElementKind /*ScriptElementKind.unknown*/>("kind"); }
	inline void _impl_js_jts_dQuickInfo::kind(_js_jts_dScriptElementKind /*ScriptElementKind.unknown*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dQuickInfo::kindModifiers() noexcept { return _getProperty<js_string>("kindModifiers"); }
	inline void _impl_js_jts_dQuickInfo::kindModifiers(js_string v) noexcept { _setProperty("kindModifiers", v); }
	inline auto _impl_js_jts_dQuickInfo::textSpan() noexcept { return _getProperty<_js_jts_dTextSpan>("textSpan"); }
	inline void _impl_js_jts_dQuickInfo::textSpan(_js_jts_dTextSpan v) noexcept { _setProperty("textSpan", v); }
	inline auto _impl_js_jts_dRenameInfoSuccess::canRename() noexcept { return _getProperty<bool /*true*/>("canRename"); }
	inline void _impl_js_jts_dRenameInfoSuccess::canRename(bool /*true*/ v) noexcept { _setProperty("canRename", v); }
	inline auto _impl_js_jts_dRenameInfoSuccess::displayName() noexcept { return _getProperty<js_string>("displayName"); }
	inline void _impl_js_jts_dRenameInfoSuccess::displayName(js_string v) noexcept { _setProperty("displayName", v); }
	inline auto _impl_js_jts_dRenameInfoSuccess::fullDisplayName() noexcept { return _getProperty<js_string>("fullDisplayName"); }
	inline void _impl_js_jts_dRenameInfoSuccess::fullDisplayName(js_string v) noexcept { _setProperty("fullDisplayName", v); }
	inline auto _impl_js_jts_dRenameInfoSuccess::kind() noexcept { return _getProperty<_js_jts_dScriptElementKind /*ScriptElementKind.unknown*/>("kind"); }
	inline void _impl_js_jts_dRenameInfoSuccess::kind(_js_jts_dScriptElementKind /*ScriptElementKind.unknown*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dRenameInfoSuccess::kindModifiers() noexcept { return _getProperty<js_string>("kindModifiers"); }
	inline void _impl_js_jts_dRenameInfoSuccess::kindModifiers(js_string v) noexcept { _setProperty("kindModifiers", v); }
	inline auto _impl_js_jts_dRenameInfoSuccess::triggerSpan() noexcept { return _getProperty<_js_jts_dTextSpan>("triggerSpan"); }
	inline void _impl_js_jts_dRenameInfoSuccess::triggerSpan(_js_jts_dTextSpan v) noexcept { _setProperty("triggerSpan", v); }
	inline auto _impl_js_jts_dRenameInfoFailure::canRename() noexcept { return _getProperty<bool /*false*/>("canRename"); }
	inline void _impl_js_jts_dRenameInfoFailure::canRename(bool /*false*/ v) noexcept { _setProperty("canRename", v); }
	inline auto _impl_js_jts_dRenameInfoFailure::localizedErrorMessage() noexcept { return _getProperty<js_string>("localizedErrorMessage"); }
	inline void _impl_js_jts_dRenameInfoFailure::localizedErrorMessage(js_string v) noexcept { _setProperty("localizedErrorMessage", v); }
	inline auto _impl_js_jts_dSignatureHelpParameter::name() noexcept { return _getProperty<js_string>("name"); }
	inline void _impl_js_jts_dSignatureHelpParameter::name(js_string v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dSignatureHelpParameter::documentation() noexcept { return _getProperty<js::Array<_js_jts_dSymbolDisplayPart>>("documentation"); }
	inline void _impl_js_jts_dSignatureHelpParameter::documentation(js::Array<_js_jts_dSymbolDisplayPart> v) noexcept { _setProperty("documentation", v); }
	inline auto _impl_js_jts_dSignatureHelpParameter::displayParts() noexcept { return _getProperty<js::Array<_js_jts_dSymbolDisplayPart>>("displayParts"); }
	inline void _impl_js_jts_dSignatureHelpParameter::displayParts(js::Array<_js_jts_dSymbolDisplayPart> v) noexcept { _setProperty("displayParts", v); }
	inline auto _impl_js_jts_dSignatureHelpParameter::isOptional() noexcept { return _getProperty<bool /*false*/>("isOptional"); }
	inline void _impl_js_jts_dSignatureHelpParameter::isOptional(bool /*false*/ v) noexcept { _setProperty("isOptional", v); }
	inline auto _impl_js_jts_dSelectionRange::textSpan() noexcept { return _getProperty<_js_jts_dTextSpan>("textSpan"); }
	inline void _impl_js_jts_dSelectionRange::textSpan(_js_jts_dTextSpan v) noexcept { _setProperty("textSpan", v); }
	inline auto _impl_js_jts_dSignatureHelpItem::isVariadic() noexcept { return _getProperty<bool /*false*/>("isVariadic"); }
	inline void _impl_js_jts_dSignatureHelpItem::isVariadic(bool /*false*/ v) noexcept { _setProperty("isVariadic", v); }
	inline auto _impl_js_jts_dSignatureHelpItem::prefixDisplayParts() noexcept { return _getProperty<js::Array<_js_jts_dSymbolDisplayPart>>("prefixDisplayParts"); }
	inline void _impl_js_jts_dSignatureHelpItem::prefixDisplayParts(js::Array<_js_jts_dSymbolDisplayPart> v) noexcept { _setProperty("prefixDisplayParts", v); }
	inline auto _impl_js_jts_dSignatureHelpItem::suffixDisplayParts() noexcept { return _getProperty<js::Array<_js_jts_dSymbolDisplayPart>>("suffixDisplayParts"); }
	inline void _impl_js_jts_dSignatureHelpItem::suffixDisplayParts(js::Array<_js_jts_dSymbolDisplayPart> v) noexcept { _setProperty("suffixDisplayParts", v); }
	inline auto _impl_js_jts_dSignatureHelpItem::separatorDisplayParts() noexcept { return _getProperty<js::Array<_js_jts_dSymbolDisplayPart>>("separatorDisplayParts"); }
	inline void _impl_js_jts_dSignatureHelpItem::separatorDisplayParts(js::Array<_js_jts_dSymbolDisplayPart> v) noexcept { _setProperty("separatorDisplayParts", v); }
	inline auto _impl_js_jts_dSignatureHelpItem::parameters() noexcept { return _getProperty<js::Array<_js_jts_dSignatureHelpParameter>>("parameters"); }
	inline void _impl_js_jts_dSignatureHelpItem::parameters(js::Array<_js_jts_dSignatureHelpParameter> v) noexcept { _setProperty("parameters", v); }
	inline auto _impl_js_jts_dSignatureHelpItem::documentation() noexcept { return _getProperty<js::Array<_js_jts_dSymbolDisplayPart>>("documentation"); }
	inline void _impl_js_jts_dSignatureHelpItem::documentation(js::Array<_js_jts_dSymbolDisplayPart> v) noexcept { _setProperty("documentation", v); }
	inline auto _impl_js_jts_dSignatureHelpItem::tags() noexcept { return _getProperty<js::Array<_js_jts_dJSDocTagInfo>>("tags"); }
	inline void _impl_js_jts_dSignatureHelpItem::tags(js::Array<_js_jts_dJSDocTagInfo> v) noexcept { _setProperty("tags", v); }
	inline auto _impl_js_jts_dSignatureHelpItems::items() noexcept { return _getProperty<js::Array<_js_jts_dSignatureHelpItem>>("items"); }
	inline void _impl_js_jts_dSignatureHelpItems::items(js::Array<_js_jts_dSignatureHelpItem> v) noexcept { _setProperty("items", v); }
	inline auto _impl_js_jts_dSignatureHelpItems::applicableSpan() noexcept { return _getProperty<_js_jts_dTextSpan>("applicableSpan"); }
	inline void _impl_js_jts_dSignatureHelpItems::applicableSpan(_js_jts_dTextSpan v) noexcept { _setProperty("applicableSpan", v); }
	inline auto _impl_js_jts_dSignatureHelpItems::selectedItemIndex() noexcept { return _getProperty<double>("selectedItemIndex"); }
	inline void _impl_js_jts_dSignatureHelpItems::selectedItemIndex(double v) noexcept { _setProperty("selectedItemIndex", v); }
	inline auto _impl_js_jts_dSignatureHelpItems::argumentIndex() noexcept { return _getProperty<double>("argumentIndex"); }
	inline void _impl_js_jts_dSignatureHelpItems::argumentIndex(double v) noexcept { _setProperty("argumentIndex", v); }
	inline auto _impl_js_jts_dSignatureHelpItems::argumentCount() noexcept { return _getProperty<double>("argumentCount"); }
	inline void _impl_js_jts_dSignatureHelpItems::argumentCount(double v) noexcept { _setProperty("argumentCount", v); }
	inline auto _impl_js_jts_dCompletionInfo::isGlobalCompletion() noexcept { return _getProperty<bool /*false*/>("isGlobalCompletion"); }
	inline void _impl_js_jts_dCompletionInfo::isGlobalCompletion(bool /*false*/ v) noexcept { _setProperty("isGlobalCompletion", v); }
	inline auto _impl_js_jts_dCompletionInfo::isMemberCompletion() noexcept { return _getProperty<bool /*false*/>("isMemberCompletion"); }
	inline void _impl_js_jts_dCompletionInfo::isMemberCompletion(bool /*false*/ v) noexcept { _setProperty("isMemberCompletion", v); }
	inline auto _impl_js_jts_dCompletionInfo::isNewIdentifierLocation() noexcept { return _getProperty<bool /*false*/>("isNewIdentifierLocation"); }
	inline void _impl_js_jts_dCompletionInfo::isNewIdentifierLocation(bool /*false*/ v) noexcept { _setProperty("isNewIdentifierLocation", v); }
	inline auto _impl_js_jts_dCompletionInfo::entries() noexcept { return _getProperty<js::Array<_js_jts_dCompletionEntry>>("entries"); }
	inline void _impl_js_jts_dCompletionInfo::entries(js::Array<_js_jts_dCompletionEntry> v) noexcept { _setProperty("entries", v); }
	inline auto _impl_js_jts_dCompletionEntry::name() noexcept { return _getProperty<js_string>("name"); }
	inline void _impl_js_jts_dCompletionEntry::name(js_string v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dCompletionEntry::kind() noexcept { return _getProperty<_js_jts_dScriptElementKind /*ScriptElementKind.unknown*/>("kind"); }
	inline void _impl_js_jts_dCompletionEntry::kind(_js_jts_dScriptElementKind /*ScriptElementKind.unknown*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dCompletionEntry::sortText() noexcept { return _getProperty<js_string>("sortText"); }
	inline void _impl_js_jts_dCompletionEntry::sortText(js_string v) noexcept { _setProperty("sortText", v); }
	inline auto _impl_js_jts_dCompletionEntryDetails::name() noexcept { return _getProperty<js_string>("name"); }
	inline void _impl_js_jts_dCompletionEntryDetails::name(js_string v) noexcept { _setProperty("name", v); }
	inline auto _impl_js_jts_dCompletionEntryDetails::kind() noexcept { return _getProperty<_js_jts_dScriptElementKind /*ScriptElementKind.unknown*/>("kind"); }
	inline void _impl_js_jts_dCompletionEntryDetails::kind(_js_jts_dScriptElementKind /*ScriptElementKind.unknown*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dCompletionEntryDetails::kindModifiers() noexcept { return _getProperty<js_string>("kindModifiers"); }
	inline void _impl_js_jts_dCompletionEntryDetails::kindModifiers(js_string v) noexcept { _setProperty("kindModifiers", v); }
	inline auto _impl_js_jts_dCompletionEntryDetails::displayParts() noexcept { return _getProperty<js::Array<_js_jts_dSymbolDisplayPart>>("displayParts"); }
	inline void _impl_js_jts_dCompletionEntryDetails::displayParts(js::Array<_js_jts_dSymbolDisplayPart> v) noexcept { _setProperty("displayParts", v); }
	inline auto _impl_js_jts_dOutliningSpan::textSpan() noexcept { return _getProperty<_js_jts_dTextSpan>("textSpan"); }
	inline void _impl_js_jts_dOutliningSpan::textSpan(_js_jts_dTextSpan v) noexcept { _setProperty("textSpan", v); }
	inline auto _impl_js_jts_dOutliningSpan::hintSpan() noexcept { return _getProperty<_js_jts_dTextSpan>("hintSpan"); }
	inline void _impl_js_jts_dOutliningSpan::hintSpan(_js_jts_dTextSpan v) noexcept { _setProperty("hintSpan", v); }
	inline auto _impl_js_jts_dOutliningSpan::bannerText() noexcept { return _getProperty<js_string>("bannerText"); }
	inline void _impl_js_jts_dOutliningSpan::bannerText(js_string v) noexcept { _setProperty("bannerText", v); }
	inline auto _impl_js_jts_dOutliningSpan::autoCollapse() noexcept { return _getProperty<bool /*false*/>("autoCollapse"); }
	inline void _impl_js_jts_dOutliningSpan::autoCollapse(bool /*false*/ v) noexcept { _setProperty("autoCollapse", v); }
	inline auto _impl_js_jts_dOutliningSpan::kind() noexcept { return _getProperty<_js_jts_dOutliningSpanKind /*OutliningSpanKind.Comment*/>("kind"); }
	inline void _impl_js_jts_dOutliningSpan::kind(_js_jts_dOutliningSpanKind /*OutliningSpanKind.Comment*/ v) noexcept { _setProperty("kind", v); }
	inline auto _impl_js_jts_dClassificationResult::finalLexState() noexcept { return _getProperty<_js_jts_dEndOfLineState /*EndOfLineState.None*/>("finalLexState"); }
	inline void _impl_js_jts_dClassificationResult::finalLexState(_js_jts_dEndOfLineState /*EndOfLineState.None*/ v) noexcept { _setProperty("finalLexState", v); }
	inline auto _impl_js_jts_dClassificationResult::entries() noexcept { return _getProperty<js::Array<_js_jts_dClassificationInfo>>("entries"); }
	inline void _impl_js_jts_dClassificationResult::entries(js::Array<_js_jts_dClassificationInfo> v) noexcept { _setProperty("entries", v); }
	inline auto _impl_js_jts_dClassificationInfo::length() noexcept { return _getProperty<double>("length"); }
	inline void _impl_js_jts_dClassificationInfo::length(double v) noexcept { _setProperty("length", v); }
	inline auto _impl_js_jts_dClassificationInfo::classification() noexcept { return _getProperty<_js_jts_dTokenClass /*TokenClass.Punctuation*/>("classification"); }
	inline void _impl_js_jts_dClassificationInfo::classification(_js_jts_dTokenClass /*TokenClass.Punctuation*/ v) noexcept { _setProperty("classification", v); }
	inline auto _impl_js_jts_dClassifier::getClassificationsForLine(js_string text, _js_jts_dEndOfLineState /*EndOfLineState.None*/ lexState, bool /*false*/ syntacticClassifierAbsent) noexcept {
		return _call<_js_jts_dClassificationResult>("getClassificationsForLine", text, lexState, syntacticClassifierAbsent);
	}
	inline auto _impl_js_jts_dClassifier::getEncodedLexicalClassifications(js_string text, _js_jts_dEndOfLineState /*EndOfLineState.None*/ endOfLineState, bool /*false*/ syntacticClassifierAbsent) noexcept {
		return _call<_js_jts_dClassifications>("getEncodedLexicalClassifications", text, endOfLineState, syntacticClassifierAbsent);
	}
	inline auto _impl_js_jts_dDocumentRegistry::acquireDocument(js_string fileName, _js_jts_dCompilerOptions compilationSettings, _js_jts_dIScriptSnapshot scriptSnapshot, js_string version, js_union<_js_jts_dScriptKind /*ScriptKind.TS*/, js_undefined> scriptKind) noexcept {
		return _call<_js_jts_dSourceFile>("acquireDocument", fileName, compilationSettings, scriptSnapshot, version, scriptKind);
	}
	inline auto _impl_js_jts_dDocumentRegistry::acquireDocumentWithKey(js_string fileName, js_unknown /*flags=2097152: Path ()*/ path, _js_jts_dCompilerOptions compilationSettings, js_unknown /*flags=2097152: DocumentRegistryBucketKey ()*/ key, _js_jts_dIScriptSnapshot scriptSnapshot, js_string version, js_union<_js_jts_dScriptKind /*ScriptKind.TS*/, js_undefined> scriptKind) noexcept {
		return _call<_js_jts_dSourceFile>("acquireDocumentWithKey", fileName, path, compilationSettings, key, scriptSnapshot, version, scriptKind);
	}
	inline auto _impl_js_jts_dDocumentRegistry::getKeyForCompilationSettings(_js_jts_dCompilerOptions settings) noexcept {
		return _call<js_unknown /*flags=2097152: DocumentRegistryBucketKey ()*/>("getKeyForCompilationSettings", settings);
	}
	inline auto _impl_js_jts_dDocumentRegistry::releaseDocument(js_string fileName, _js_jts_dCompilerOptions compilationSettings) noexcept {
		return _call<void>("releaseDocument", fileName, compilationSettings);
	}
	inline auto _impl_js_jts_dDocumentRegistry::releaseDocumentWithKey(js_unknown /*flags=2097152: Path ()*/ path, js_unknown /*flags=2097152: DocumentRegistryBucketKey ()*/ key) noexcept {
		return _call<void>("releaseDocumentWithKey", path, key);
	}
	inline auto _impl_js_jts_dDocumentRegistry::reportStats() noexcept {
		return _call<js_string>("reportStats");
	}
	inline auto _impl_js_jts_dDocumentRegistry::updateDocument(js_string fileName, _js_jts_dCompilerOptions compilationSettings, _js_jts_dIScriptSnapshot scriptSnapshot, js_string version, js_union<_js_jts_dScriptKind /*ScriptKind.TS*/, js_undefined> scriptKind) noexcept {
		return _call<_js_jts_dSourceFile>("updateDocument", fileName, compilationSettings, scriptSnapshot, version, scriptKind);
	}
	inline auto _impl_js_jts_dDocumentRegistry::updateDocumentWithKey(js_string fileName, js_unknown /*flags=2097152: Path ()*/ path, _js_jts_dCompilerOptions compilationSettings, js_unknown /*flags=2097152: DocumentRegistryBucketKey ()*/ key, _js_jts_dIScriptSnapshot scriptSnapshot, js_string version, js_union<_js_jts_dScriptKind /*ScriptKind.TS*/, js_undefined> scriptKind) noexcept {
		return _call<_js_jts_dSourceFile>("updateDocumentWithKey", fileName, path, compilationSettings, key, scriptSnapshot, version, scriptKind);
	}
	inline auto _impl_js_jts_dTranspileOutput::outputText() noexcept { return _getProperty<js_string>("outputText"); }
	inline void _impl_js_jts_dTranspileOutput::outputText(js_string v) noexcept { _setProperty("outputText", v); }
}; // namespace tc::js_defs
namespace tc::js {
using ts = js_defs::_js_j_qts_q;
} // namespace tc::js

// Manual fixes
namespace tc::js::ts_ext {
	using SignatureDeclaration = tc::jst::js_union<tc::js::ts::MethodSignature, tc::js::ts::MethodDeclaration, tc::js::ts::ConstructorDeclaration, tc::js::ts::CallSignatureDeclaration, tc::js::ts::FunctionDeclaration>;
	using BaseType = tc::jst::js_union<tc::js::ts::ObjectType, tc::js::ts::IntersectionType>;

	// TODO: Unclear why this is ok, this is not defined on TypeParameter

	struct _js_TypeParameter : virtual tc::js_defs::_impl_js_jts_dTypeParameter {
		auto constraint() noexcept { return _getProperty<tc::jst::js_union<tc::jst::js_undefined, tc::js::ts::Type>>("constraint"); }
	};
	using TypeParameter = tc::jst::js_ref<_js_TypeParameter>;

	// TODO: Generics 
	struct _js_SymbolTable : virtual tc::jst::IObject {
		struct _tcjs_definitions {
			using value_type = tc::js::ts::Symbol;
		};

		template<typename Fn>
		auto operator()(Fn fn) noexcept {
			return _call<void>("forEach", tc::jst::js_lambda_wrap([&](tc::js::ts::Symbol value, tc::jst::js_unknown, tc::jst::js_unknown) noexcept {
				fn(tc_move(value));
			}));
		}
	};
	using SymbolTable = tc::jst::js_ref<_js_SymbolTable>;

	template<typename T>
	ReadonlyArray<T> MakeReadOnlyArray(tc::jst::js_unknown unk) noexcept {
		return ReadonlyArray<T>(unk);
	}

	struct _js_HeritageClause : virtual tc::js_defs::_impl_js_jts_dHeritageClause {
		auto types() noexcept { return _getProperty<ReadonlyArray<tc::js::ts::Node>>("types"); }
	};
	using HeritageClause = tc::jst::js_ref<_js_HeritageClause>;

	// TODO: Optional member
	struct _js_Symbol : virtual tc::js_defs::_impl_js_jts_dSymbol {
		inline auto parent() noexcept { return _getProperty<tc::jst::js_optional<tc::js::ts::Symbol>>("parent"); }
		inline auto members() noexcept { return _getProperty<tc::jst::js_optional<tc::js::ts_ext::SymbolTable>>("members"); }
		inline auto exports() noexcept { return _getProperty<tc::jst::js_optional<tc::js::ts_ext::SymbolTable>>("exports"); }
		inline auto globalExports() noexcept { return _getProperty<tc::jst::js_optional<tc::js::ts_ext::SymbolTable>>("globalExports"); }
	};
	using Symbol = tc::jst::js_ref<_js_Symbol>;

	struct _js_ClassLikeDeclaration : virtual tc::js_defs::_impl_js_jts_dClassDeclaration {
		auto heritageClauses() noexcept { return _getProperty<tc::jst::js_optional<ReadonlyArray<tc::js::ts::HeritageClause>>>("heritageClauses"); }
	};
	using ClassLikeDeclaration = tc::jst::js_ref<_js_ClassLikeDeclaration>;

	struct _js_NamedDeclaration : virtual tc::js_defs::_impl_js_jts_dNamedDeclaration {
		auto name() noexcept { return _getProperty<tc::jst::js_optional<tc::js::ts::Node>>("name"); }
	};
	using NamedDeclaration = tc::jst::js_ref<_js_NamedDeclaration>;

	inline auto name(tc::js::ts::NamedDeclaration decl) noexcept {
		return NamedDeclaration(decl)->name();
	}

	struct _js_CompilerOptions : virtual tc::js_defs::_impl_js_jts_dCompilerOptions {
		auto noEmitOnError() noexcept { return _getProperty<tc::jst::js_optional<bool>>("noEmitOnError"); }
		void noEmitOnError(tc::jst::js_optional<bool> v) noexcept { _setProperty("noEmitOnError", v); }

		auto module() noexcept { return _getProperty<tc::jst::js_optional<bool>>("module"); }
		void module(tc::jst::js_optional<tc::js::ts::ModuleKind> v) noexcept { _setProperty("module", v); }

		auto strict() noexcept { return _getProperty<tc::jst::js_optional<bool>>("strict"); }
		void strict(tc::jst::js_optional<bool> v) noexcept { _setProperty("strict", v); }

		auto target() noexcept { return _getProperty<tc::jst::js_optional<tc::js::ts::ScriptTarget>>("target"); }
		void target(tc::jst::js_optional<tc::js::ts::ScriptTarget> v) noexcept { _setProperty("target", v); }

		static auto _tcjs_construct() noexcept { return emscripten::val::object(); }
	};
	using CompilerOptions = tc::jst::js_ref<_js_CompilerOptions>;

	struct _js_TypeReference : virtual tc::js_defs::_impl_js_jts_dTypeReference {
		auto typeArguments() noexcept { return _getProperty<ReadonlyArray<tc::js::ts::Type>>("typeArguments"); }
	};
	using TypeReference = tc::jst::js_ref<_js_TypeReference>;


	// Type guards

	inline auto isMethodSignature(tc::js::ts::Node node) noexcept {
		std::optional<tc::js::ts::MethodSignature> result;
		if (tc::js::ts::isMethodSignature(node))
			result.emplace(node);
		return result;
	}

	inline auto isMethodDeclaration(tc::js::ts::Node node) noexcept {
		std::optional<tc::js::ts::MethodDeclaration> result;
		if (tc::js::ts::isMethodDeclaration(node))
			result.emplace(node);
		return result;
	}

	inline auto isConstructorDeclaration(tc::js::ts::Node node) noexcept {
		std::optional<tc::js::ts::ConstructorDeclaration> result;
		if (tc::js::ts::isConstructorDeclaration(node))
			result.emplace(node);
		return result;
	}

	inline auto isFunctionDeclaration(tc::js::ts::Node node) noexcept {
		std::optional<tc::js::ts::ConstructorDeclaration> result;
		if (tc::js::ts::isFunctionDeclaration(node))
			result.emplace(node);
		return result;
	}
	
	inline auto isClassDeclaration(tc::js::ts::Node node) noexcept {
		std::optional<tc::js::ts::ClassDeclaration> result;
		if (tc::js::ts::isClassDeclaration(node))
			result.emplace(node);
		return result;
	}
	
	inline auto isInterfaceDeclaration(tc::js::ts::Node node) noexcept {
		std::optional<tc::js::ts::InterfaceDeclaration> result;
		if (tc::js::ts::isInterfaceDeclaration(node))
			result.emplace(node);
		return result;
	}
	
	inline auto isEnumDeclaration(tc::js::ts::Node node) noexcept {
		std::optional<tc::js::ts::EnumDeclaration> result;
		if (tc::js::ts::isEnumDeclaration(node))
			result.emplace(node);
		return result;
	}

	inline auto isModuleDeclaration(tc::js::ts::Node node) noexcept {
		std::optional<tc::js::ts::ModuleDeclaration> result;
		if (tc::js::ts::isModuleDeclaration(node))
			result.emplace(node);
		return result;
	}
	
	inline auto isVariableStatement(tc::js::ts::Node node) noexcept {
		std::optional<tc::js::ts::VariableStatement> result;
		if (tc::js::ts::isVariableStatement(node))
			result.emplace(node);
		return result;
	}

	inline auto isClassOrInterface(tc::js::ts::Type type) noexcept {
		std::optional<tc::js::ts::InterfaceType> result;
		if (type->isClassOrInterface())
			result.emplace(type);
		return result;
	}

	inline auto isUnion(tc::js::ts::Type type) noexcept {
		std::optional<tc::js::ts::UnionType> result;
		if (type->isUnion())
			result.emplace(type);
		return result;
	}


}


namespace tc::js_defs {
	// Manually implemented instead of DEFINE_CONTIGUOUS_ENUM + enumset to avoid manually checking that all enums are indeed contiguous.
	inline tc::js::ts::SymbolFlags operator|(tc::js::ts::SymbolFlags a, tc::js::ts::SymbolFlags b) { return static_cast<tc::js::ts::SymbolFlags>(static_cast<int>(a) | static_cast<int>(b)); }
	inline bool operator&(tc::js::ts::SymbolFlags a, tc::js::ts::SymbolFlags b) { return static_cast<int>(a) & static_cast<int>(b); }

	inline tc::js::ts::TypeFlags operator|(tc::js::ts::TypeFlags a, tc::js::ts::TypeFlags b) { return static_cast<tc::js::ts::TypeFlags>(static_cast<int>(a) | static_cast<int>(b)); }
	inline bool operator&(tc::js::ts::TypeFlags a, tc::js::ts::TypeFlags b) { return static_cast<int>(a) & static_cast<int>(b); }

	inline tc::js::ts::ObjectFlags operator|(tc::js::ts::ObjectFlags a, tc::js::ts::ObjectFlags b) { return static_cast<tc::js::ts::ObjectFlags>(static_cast<int>(a) | static_cast<int>(b)); }
	inline bool operator&(tc::js::ts::ObjectFlags a, tc::js::ts::ObjectFlags b) { return static_cast<int>(a) & static_cast<int>(b); }

	inline tc::js::ts::ModifierFlags operator|(tc::js::ts::ModifierFlags a, tc::js::ts::ModifierFlags b) { return static_cast<tc::js::ts::ModifierFlags>(static_cast<int>(a) | static_cast<int>(b)); }
	inline bool operator&(tc::js::ts::ModifierFlags a, tc::js::ts::ModifierFlags b) { return static_cast<int>(a) & static_cast<int>(b); }
} // namespace tc::js_defs